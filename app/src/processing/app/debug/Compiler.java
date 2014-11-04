/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-08 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package processing.app.debug;

import processing.app.Base;
import processing.app.Preferences;
import processing.app.Sketch;
import processing.app.SketchCode;
import processing.core.*;
import processing.app.I18n;
import static processing.app.I18n._;

import java.io.*;
import java.util.*;
import java.util.zip.*;


public class Compiler implements MessageConsumer {
  static final String BUGS_URL =
    _("https://github.com/energia/Energia/issues");
  static final String SUPER_BADNESS =
    I18n.format(_("Compiler error, please submit this code to {0}"), BUGS_URL);

  Sketch sketch;
  String buildPath;
  String primaryClassName;
  boolean verbose;
  boolean sketchIsCompiled;

  RunnerException exception;

  public Compiler() { }

  /**
   * Compile with avr-gcc.
   *
   * @param sketch Sketch object to be compiled.
   * @param buildPath Where the temporary files live and will be built from.
   * @param primaryClassName the name of the combined sketch file w/ extension
   * @return true if successful.
   * @throws RunnerException Only if there's a problem. Only then.
   */
  public boolean compile(Sketch sketch,
                         String buildPath,
                         String primaryClassName,
                         boolean verbose) throws RunnerException {
    this.sketch = sketch;
    this.buildPath = buildPath;
    this.primaryClassName = primaryClassName;
    this.verbose = verbose;
    this.sketchIsCompiled = false;

    // the pms object isn't used for anything but storage
    MessageStream pms = new MessageStream(this);


    String basePath = Base.getBasePath();
    Map<String, String> boardPreferences = Base.getBoardPreferences();
    String core = boardPreferences.get("build.core");
    String arch = Base.getArch();
    if (core == null) {
    	RunnerException re = new RunnerException(_("No board selected; please choose a board from the Tools > Board menu."));
      re.hideStackTrace();
      throw re;
    }
    String corePath;
    
    if (core.indexOf(':') == -1) {
      Target t = Base.getTarget();
      File coreFolder = new File(new File(t.getFolder(), "cores"), core);
      corePath = coreFolder.getAbsolutePath();
    } else {
      Target t = Base.targetsTable.get(core.substring(0, core.indexOf(':')));
      File coreFolder = new File(t.getFolder(), "cores");
      coreFolder = new File(coreFolder, core.substring(core.indexOf(':') + 1));
      corePath = coreFolder.getAbsolutePath();
    }

    String variant = boardPreferences.get("build.variant");
    String variantPath = null;
    
    if (variant != null) {
      if (variant.indexOf(':') == -1) {
	Target t = Base.getTarget();
	File variantFolder = new File(new File(t.getFolder(), "variants"), variant);
	variantPath = variantFolder.getAbsolutePath();
      } else {
	Target t = Base.targetsTable.get(variant.substring(0, variant.indexOf(':')));
	File variantFolder = new File(t.getFolder(), "variants");
	variantFolder = new File(variantFolder, variant.substring(variant.indexOf(':') + 1));
	variantPath = variantFolder.getAbsolutePath();
      }
    }

    String rtsIncPath = null;
    String rtsLibPath = null;
    
    if (arch == "c2000") {
    	Target t = Base.getTarget();
     	File rtsIncFolder;
     	File rtsLibFolder;

     	rtsIncFolder = new File(new File(new File(t.getFolder(), "..//tools"), "c2000"), "include");
     	rtsLibFolder = new File(new File(new File(t.getFolder(), "..//tools"), "c2000"), "lib");
    	rtsIncPath = rtsIncFolder.getAbsolutePath();
    	rtsLibPath = rtsLibFolder.getAbsolutePath();
    }

    List<File> objectFiles = new ArrayList<File>();

   // 0. include paths for core + all libraries

   sketch.setCompilingProgress(20);
   List includePaths = new ArrayList();
   includePaths.add(corePath);
   if (variantPath != null) includePaths.add(variantPath);
   if (rtsIncPath != null) includePaths.add(rtsIncPath);
   for (File file : sketch.getImportedLibraries()) {
     includePaths.add(file.getPath());
   }

   // 1. compile the sketch (already in the buildPath)

   sketch.setCompilingProgress(30);
   objectFiles.addAll(
     compileFiles(basePath, buildPath, includePaths,
               findFilesInPath(buildPath, "S", false),
               findFilesInPath(buildPath, "c", false),
               findFilesInPath(buildPath, "cpp", false),
               boardPreferences));
   sketchIsCompiled = true;

   // 2. compile the libraries, outputting .o files to: <buildPath>/<library>/

   sketch.setCompilingProgress(40);
   for (File libraryFolder : sketch.getImportedLibraries()) {
     File outputFolder = new File(buildPath, libraryFolder.getName());
     File utilityFolder = new File(libraryFolder, "utility");
     createFolder(outputFolder);
     // this library can use includes in its utility/ folder
     includePaths.add(utilityFolder.getAbsolutePath());
     objectFiles.addAll(
       compileFiles(basePath, outputFolder.getAbsolutePath(), includePaths,
               findFilesInFolder(libraryFolder, "S", false),
               findFilesInFolder(libraryFolder, "c", false),
               findFilesInFolder(libraryFolder, "cpp", false),
               boardPreferences));
     outputFolder = new File(outputFolder, "utility");
     createFolder(outputFolder);
     objectFiles.addAll(
       compileFiles(basePath, outputFolder.getAbsolutePath(), includePaths,
               findFilesInFolder(utilityFolder, "S", false),
               findFilesInFolder(utilityFolder, "c", false),
               findFilesInFolder(utilityFolder, "cpp", false),
               boardPreferences));
     // other libraries should not see this library's utility/ folder
     includePaths.remove(includePaths.size() - 1);
   }

   // 3. compile the core, outputting .o files to <buildPath> and then
   // collecting them into the core.a library file.
   List<File> coreObjectFiles;
   //For c2000 cores, includes only the necessary files for the specific core
   if(arch == "c2000")
   {
	  sketch.setCompilingProgress(50);
	  includePaths.clear();
	  includePaths.add(corePath);  // include path for core only
	  if (rtsIncPath != null) includePaths.add(rtsIncPath);
	  if (variantPath != null) includePaths.add(variantPath);
	  //add specific header folders to paths
	  String core_headersPath = corePath;
	  String core_commonPath = corePath; 
	  if( boardPreferences.get("build.mcu").equals("TMS320F28027"))
      {
		  core_commonPath += "/f2802x_common";
		  core_headersPath += "/f2802x_headers";
      }
      else if( boardPreferences.get("build.mcu").equals("TMS320F28069"))
      {


			  core_commonPath += "/F2806x_common";
			  core_headersPath += "/F2806x_headers";
      

      }
	  ArrayList<File> corePathfiles_S = findFilesInPath(corePath, "S", false);
	  corePathfiles_S.addAll(findFilesInPath(core_commonPath, "S", true));
	  corePathfiles_S.addAll(findFilesInPath(core_headersPath, "S", true));
	  ArrayList<File> corePathfiles_c = findFilesInPath(corePath, "c", false);
	  corePathfiles_c.addAll(findFilesInPath(core_commonPath, "c", true));
	  corePathfiles_c.addAll(findFilesInPath(core_headersPath, "c", true));
	  ArrayList<File> corePathfiles_cpp = findFilesInPath(corePath, "cpp", false);
	  corePathfiles_cpp.addAll(findFilesInPath(core_commonPath, "cpp", true));
	  corePathfiles_cpp.addAll(findFilesInPath(core_headersPath, "cpp", true));
	  coreObjectFiles =
	    compileFiles(basePath, buildPath, includePaths,
	    			corePathfiles_S,
	    			corePathfiles_c,
	    			corePathfiles_cpp,
	              boardPreferences);
   }
   //other cores do not have to worry about not including all the files in the core path
   else
   {
   sketch.setCompilingProgress(50);
  includePaths.clear();
  includePaths.add(corePath);  // include path for core only
  if (rtsIncPath != null) includePaths.add(rtsIncPath);
  if (variantPath != null) includePaths.add(variantPath);
	  coreObjectFiles =
    compileFiles(basePath, buildPath, includePaths,
              findFilesInPath(corePath, "S", true),
              findFilesInPath(corePath, "c", true),
              findFilesInPath(corePath, "cpp", true),
              boardPreferences);

   }
  String runtimeLibraryName = buildPath + File.separator + "core.a";
  List baseCommandAR;
  if(arch == "msp430")  {
    baseCommandAR = new ArrayList(Arrays.asList(new String[] {
      basePath + "msp430-ar",
      "rcs",
      runtimeLibraryName
    }));
    } else if(arch == "lm4f" || arch == "cc3200") {
      baseCommandAR = new ArrayList(Arrays.asList(new String[] { 
        basePath + "arm-none-eabi-ar",
        "rcs",
        runtimeLibraryName
    }));  	
    } else  if(arch == "c2000"){
      baseCommandAR = new ArrayList(Arrays.asList(new String[] {
	    basePath + "ar2000",
	    "r",
	    runtimeLibraryName
    }));
    }else {
      baseCommandAR = new ArrayList(Arrays.asList(new String[] {
        basePath + "avr-ar",
        "rcs",
        runtimeLibraryName
    }));
  }

//  if(arch != "c2000"){
    if(arch == "c2000")
    {
  	  for(File file : coreObjectFiles) {
 	     List commandAR = new ArrayList(baseCommandAR);
 	     commandAR.add(file.getAbsolutePath());
 	     execAsynchronouslyShell(commandAR);
 	   }
    }
    else
    {
	  for(File file : coreObjectFiles) {
	     List commandAR = new ArrayList(baseCommandAR);
	     commandAR.add(file.getAbsolutePath());
	     execAsynchronously(commandAR);
	   }
    }
//  }

    // 4. link it all together into the .elf file
    // For atmega2560, need --relax linker option to link larger
    // programs correctly.
    String optRelax = "";
    String atmega2560 = new String ("atmega2560");
    if ( atmega2560.equals(boardPreferences.get("build.mcu")) ) {
        optRelax = new String(",--relax");
    }
    sketch.setCompilingProgress(60);
    List baseCommandLinker;
    if (arch == "msp430") { 
        baseCommandLinker = new ArrayList(Arrays.asList(new String[] {
        basePath + "msp430-gcc",
        "-Os",
        // msp430 linker has an issue with main residing in an archive, cora.a in this case.
        // -u,main works around this by forcing the linker to find a definition for main.
        "-Wl,-gc-sections,-u,main", 
        "-mmcu=" + boardPreferences.get("build.mcu"),
        "-o",
        buildPath + File.separator + primaryClassName + ".elf"
      }));
    }else if (arch == "lm4f" || arch == "cc3200") { 
        baseCommandLinker = new ArrayList(Arrays.asList(new String[] {
        basePath + "arm-none-eabi-g++",
        "-Os",
        "-nostartfiles","-nostdlib",
        "-Wl,--gc-sections",
        "-T", corePath + File.separator + boardPreferences.get("ldscript"),
        "-Wl,--entry=ResetISR",
        "-mthumb", "-mcpu=cortex-m4",
        }));

	if(arch == "lm4f") {
		baseCommandLinker.add("-mfloat-abi=hard");
		baseCommandLinker.add("-mfpu=fpv4-sp-d16");
		baseCommandLinker.add("-fsingle-precision-constant");
	}

        baseCommandLinker.add("-o");
        baseCommandLinker.add(buildPath + File.separator + primaryClassName + ".elf");
    } else if (arch == "c2000") { 
        List objects = new ArrayList(baseCommandAR);
        
        includePaths.clear();
        includePaths.add(corePath);  // include path for core only
        if (rtsIncPath != null) includePaths.add(rtsIncPath);
        if (variantPath != null) includePaths.add(variantPath);
        if (rtsIncPath != null) includePaths.add(rtsLibPath);
       
        
        //TODO: Test linker arugments
        baseCommandLinker = new ArrayList(Arrays.asList(new String[] {
        basePath + "cl2000"}));
        baseCommandLinker.add("-v28");//compile for unified memory model
        baseCommandLinker.add("-ml");//compile for unified memory model
        baseCommandLinker.add("-mt");//compile for unified memory model
        baseCommandLinker.add("-g");//compile for unified memory model
        baseCommandLinker.add("--gcc");//compile for unified memory model
        baseCommandLinker.add("--define=ENERGIA=" + Base.EREVISION);
        baseCommandLinker.add("--define=F_CPU=" + boardPreferences.get("build.f_cpu"));
        baseCommandLinker.add("--define=" + boardPreferences.get("build.mcu"));
        baseCommandLinker.add("--define=ARDUINO=" + Base.REVISION);
        baseCommandLinker.add("--diag_warning=225");//compile for unified memory model
        baseCommandLinker.add("--display_error_number");//compile for unified memory model
        baseCommandLinker.add("--diag_wrap=off");//compile for unified memory model
        baseCommandLinker.add("-z");//compile for unified memory model
        baseCommandLinker.add("--stack_size=0x300");//compile for unified memory model
        baseCommandLinker.add("-m\"Energia_C2000_Test.map\"");//compile for unified memory model
        baseCommandLinker.add("--warn_sections");//compile for unified memory model
        for (int i = 0; i < includePaths.size(); i++) {
        	baseCommandLinker.add("-i" + '\"' + (String) includePaths.get(i)+ '\"' );
        } 
        baseCommandLinker.add("--reread_libs");//compile for unified memory model
        baseCommandLinker.add("--display_error_number");//compile for unified memory model
        baseCommandLinker.add("--diag_wrap=off");//compile for unified memory model
        baseCommandLinker.add("--entry_point=code_start");//compile for unified memory model
        baseCommandLinker.add("--rom_model");//compile for unified memory model
        baseCommandLinker.add("-o" + buildPath + File.separator + primaryClassName + ".out");
//        "-o",
//        buildPath + File.separator + primaryClassName + ".elf"
        
        




    } else {
      baseCommandLinker = new ArrayList(Arrays.asList(new String[] {
        basePath + "avr-gcc",
        "-Os",
        "-Wl,--gc-sections"+optRelax,
        "-mmcu=" + boardPreferences.get("build.mcu"),
        "-o",
        buildPath + File.separator + primaryClassName + ".elf"
        }));
    }

    for (File file : objectFiles) {
      baseCommandLinker.add(file.getAbsolutePath());
    }

    baseCommandLinker.add(runtimeLibraryName);
    if(arch == "lm4f" || arch == "cc3200"){
      baseCommandLinker.add("-L" + buildPath);
      if(!Preferences.getBoolean("build.drvlib")) {
    	  String driverlib = corePath + File.separator + "driverlib" + File.separator + "libdriverlib.a";
    		  baseCommandLinker.add(driverlib);
      }
      baseCommandLinker.add("-lm");
      baseCommandLinker.add("-lc");
      baseCommandLinker.add("-lgcc");
    } 
    //Obtain the correct linker files for the specific chip
    if(arch == "c2000"){
        baseCommandLinker.add("-l" + boardPreferences.get("build.rts"));
        if( boardPreferences.get("build.mcu").equals("TMS320F28027"))
        {

        	baseCommandLinker.add(corePath + "//f2802x_common//cmd//F28027.cmd");
            baseCommandLinker.add(corePath + "//f2802x_headers//cmd//F2802x_Headers_nonBIOS.cmd");

        }
        else if( boardPreferences.get("build.mcu").equals("TMS320F28069"))
        {
        	if(Base.isLinux())
        	{
        		baseCommandLinker.add(corePath + "/F2806x_common/cmd/F28069.cmd");
	        	baseCommandLinker.add(corePath + "/F2806x_headers/cmd/F2806x_Headers_nonBIOS.cmd");
        	}
        	else
        	{
	        	baseCommandLinker.add(corePath + "\\F2806x_common\\cmd\\F28069.cmd");
	        	baseCommandLinker.add(corePath + "\\F2806x_headers\\cmd\\F2806x_Headers_nonBIOS.cmd");
        	}
        }
        else
        {
        	if(Base.isLinux())
        	{
        		baseCommandLinker.add(corePath + "/f2802x_common/cmd/F28027.cmd");
            	baseCommandLinker.add(corePath + "/f2802x_headers/cmd/F2802x_Headers_nonBIOS.cmd");
        	}
        	else
        	{
        baseCommandLinker.add(corePath + "\\f2802x_common\\cmd\\F28027.cmd");
        baseCommandLinker.add(corePath + "\\f2802x_headers\\cmd\\F2802x_Headers_nonBIOS.cmd");
        	}    
        }
    }else {
      baseCommandLinker.add("-L" + buildPath);
      baseCommandLinker.add("-lm");
    }
    if(arch == "c2000")
    {
    	execAsynchronouslyShell(baseCommandLinker);
    }
    else
    {
    execAsynchronously(baseCommandLinker);
    }
    List baseCommandObjcopy;
    if (arch == "msp430") {
    baseCommandObjcopy = new ArrayList(Arrays.asList(new String[] {
      basePath + "msp430-objcopy",
      "-O",
      "-R",
    }));
    } else if (arch == "lm4f" || arch == "cc3200") {
      baseCommandObjcopy = new ArrayList(Arrays.asList(new String[] {
        basePath + "arm-none-eabi-objcopy",
        "-O",
      }));
    }else if (arch == "c2000") { 
	//TODO: Figure out object copy
    baseCommandObjcopy = new ArrayList(Arrays.asList(new String[] {basePath + "hex2000"}));
    baseCommandObjcopy.add("-boot");
    baseCommandObjcopy.add("-sci8");
    baseCommandObjcopy.add("-a");
    } else {
      baseCommandObjcopy = new ArrayList(Arrays.asList(new String[] {
        basePath + "avr-objcopy",
        "-O",
        "-R",
      }));

    }
    List commandObjcopy;
    if ((arch == "msp430") || (arch == "lm4f") || (arch == "c2000") || (arch == "cc3200")) {
      //nothing 
    } else {
        // 5. extract EEPROM data (from EEMEM directive) to .eep file.
      sketch.setCompilingProgress(70);
      commandObjcopy = new ArrayList(baseCommandObjcopy);
      commandObjcopy.add(2, "ihex");
      commandObjcopy.set(3, "-j");
      commandObjcopy.add(".eeprom");
      commandObjcopy.add("--set-section-flags=.eeprom=alloc,load");
      commandObjcopy.add("--no-change-warnings");
      commandObjcopy.add("--change-section-lma");
      commandObjcopy.add(".eeprom=0");
      commandObjcopy.add(buildPath + File.separator + primaryClassName + ".elf");
      commandObjcopy.add(buildPath + File.separator + primaryClassName + ".eep");
      execAsynchronously(commandObjcopy);
    }
    // 6. build the .hex or .bin file
    sketch.setCompilingProgress(80);
    commandObjcopy = new ArrayList(baseCommandObjcopy);
    if (arch == "lm4f" || arch == "cc3200"){
	  	commandObjcopy.add(2, "binary");
    	commandObjcopy.add(buildPath + File.separator + primaryClassName + ".elf");
    	commandObjcopy.add(buildPath + File.separator + primaryClassName + ".bin");
    }else if (arch == "c2000"){
    	commandObjcopy.add(buildPath + File.separator + primaryClassName + ".out");
    	commandObjcopy.add("-o");
    	commandObjcopy.add(buildPath + File.separator + primaryClassName + ".txt");
    }else {
	    commandObjcopy.add(2, "ihex");
	    commandObjcopy.add(".eeprom"); // remove eeprom data
	  	commandObjcopy.add(buildPath + File.separator + primaryClassName + ".elf");
	    commandObjcopy.add(buildPath + File.separator + primaryClassName + ".hex");
    }
    if(arch == "c2000")
    {
    	execAsynchronouslyShell(commandObjcopy);
    }
    else
    {
	execAsynchronously(commandObjcopy);
    }
    sketch.setCompilingProgress(90);
   
    return true;
  }


  private List<File> compileFiles(String basePath,
                                  String buildPath, List<File> includePaths,
                                  List<File> sSources, 
                                  List<File> cSources, List<File> cppSources,
                                  Map<String, String> boardPreferences)
    throws RunnerException {

    List<File> objectPaths = new ArrayList<File>();
	if(Base.getArch() == "c2000")
	{
	
    
    for (File file : sSources) {
      String objectPath = buildPath + File.separator + file.getName() + ".o";
      objectPaths.add(new File(objectPath));
	      execAsynchronouslyShell(getCommandCompilerS(basePath, includePaths,
	                                             file.getAbsolutePath(),
	                                             objectPath,
	                                             boardPreferences));
	    }
	 		
	    for (File file : cSources) {
	        String objectPath = buildPath + File.separator + file.getName() + ".o";
	        String dependPath = buildPath + File.separator + file.getName() + ".d";
	        File objectFile = new File(objectPath);
	        File dependFile = new File(dependPath);
	        objectPaths.add(objectFile);
	        if (is_already_compiled(file, objectFile, dependFile, boardPreferences)) continue;
	        execAsynchronouslyShell(getCommandCompilerC(basePath, includePaths,
	                                               file.getAbsolutePath(),
	                                               objectPath,
	                                               boardPreferences));
	    }
	
	    for (File file : cppSources) {
	        String objectPath = buildPath + File.separator + file.getName() + ".o";
	        String dependPath = buildPath + File.separator + file.getName() + ".d";
	        File objectFile = new File(objectPath);
	        File dependFile = new File(dependPath);
	        objectPaths.add(objectFile);
	        if (is_already_compiled(file, objectFile, dependFile, boardPreferences)) continue;
	        execAsynchronouslyShell(getCommandCompilerCPP(basePath, includePaths,
	                                                 file.getAbsolutePath(),
	                                                 objectPath,
	                                                 boardPreferences));
	    }
	}
	else
	{
	    for (File file : sSources) {
	      String objectPath = buildPath + File.separator + file.getName() + ".o";
	      objectPaths.add(new File(objectPath));
      execAsynchronously(getCommandCompilerS(basePath, includePaths,
                                             file.getAbsolutePath(),
                                             objectPath,
                                             boardPreferences));
    }
 		
    for (File file : cSources) {
        String objectPath = buildPath + File.separator + file.getName() + ".o";
        String dependPath = buildPath + File.separator + file.getName() + ".d";
        File objectFile = new File(objectPath);
        File dependFile = new File(dependPath);
        objectPaths.add(objectFile);
        if (is_already_compiled(file, objectFile, dependFile, boardPreferences)) continue;
        execAsynchronously(getCommandCompilerC(basePath, includePaths,
                                               file.getAbsolutePath(),
                                               objectPath,
                                               boardPreferences));
    }

    for (File file : cppSources) {
        String objectPath = buildPath + File.separator + file.getName() + ".o";
        String dependPath = buildPath + File.separator + file.getName() + ".d";
        File objectFile = new File(objectPath);
        File dependFile = new File(dependPath);
        objectPaths.add(objectFile);
        if (is_already_compiled(file, objectFile, dependFile, boardPreferences)) continue;
        execAsynchronously(getCommandCompilerCPP(basePath, includePaths,
                                                 file.getAbsolutePath(),
                                                 objectPath,
                                                 boardPreferences));
    }
	}
    return objectPaths;
  }

  private boolean is_already_compiled(File src, File obj, File dep, Map<String, String> prefs) {
    boolean ret=true;
    try {
      //System.out.println("\n  is_already_compiled: begin checks: " + obj.getPath());
      if (!obj.exists()) return false;  // object file (.o) does not exist
      if (!dep.exists()) return false;  // dep file (.d) does not exist
      long src_modified = src.lastModified();
      long obj_modified = obj.lastModified();
      if (src_modified >= obj_modified) return false;  // source modified since object compiled
      if (src_modified >= dep.lastModified()) return false;  // src modified since dep compiled
      BufferedReader reader = new BufferedReader(new FileReader(dep.getPath()));
      String line;
      boolean need_obj_parse = true;
      while ((line = reader.readLine()) != null) {
        if (line.endsWith("\\")) {
          line = line.substring(0, line.length() - 1);
        }
        line = line.trim();
        if (line.length() == 0) continue; // ignore blank lines
        if (need_obj_parse) {
          // line is supposed to be the object file - make sure it really is!
          if (line.endsWith(":")) {
            line = line.substring(0, line.length() - 1);
            String objpath = obj.getCanonicalPath();
            File linefile = new File(line);
            String linepath = linefile.getCanonicalPath();
            //System.out.println("  is_already_compiled: obj =  " + objpath);
            //System.out.println("  is_already_compiled: line = " + linepath);
            if (objpath.compareTo(linepath) == 0) {
              need_obj_parse = false;
              continue;
            } else {
              ret = false;  // object named inside .d file is not the correct file!
              break;
            }
          } else {
            ret = false;  // object file supposed to end with ':', but didn't
            break;
          }
        } else {
          // line is a prerequisite file
          File prereq = new File(line);
          if (!prereq.exists()) {
            ret = false;  // prerequisite file did not exist
            break;
          }
          if (prereq.lastModified() >= obj_modified) {
            ret = false;  // prerequisite modified since object was compiled
            break;
          }
          //System.out.println("  is_already_compiled:  prerequisite ok");
        }
      }
      reader.close();
    } catch (Exception e) {
      return false;  // any error reading dep file = recompile it
    }
    if (ret && (verbose || Preferences.getBoolean("build.verbose"))) {
      System.out.println("  Using previously compiled: " + obj.getPath());
    }
    return ret;
  }

  boolean firstErrorFound;
  boolean secondErrorFound;

  /**
   * Either succeeds or throws a RunnerException fit for public consumption.
   */
  private void execAsynchronously(List commandList) throws RunnerException {
    String arch = Base.getArch();
    String[] command = new String[commandList.size()];
    commandList.toArray(command);
    int result = 0;
    
    if (verbose || Preferences.getBoolean("build.verbose")) {
      for(int j = 0; j < command.length; j++) {
        System.out.print(command[j] + " ");
      }
      System.out.println();
    }
    System.out.println(Arrays.toString(command));

    firstErrorFound = false;  // haven't found any errors yet
    secondErrorFound = false;
    Process process;
    try {
        	process = Runtime.getRuntime().exec(command);
        	
    } catch (IOException e) {
      RunnerException re = new RunnerException(e.getMessage());
      re.hideStackTrace();
      throw re;
    }

    MessageSiphon in = new MessageSiphon(process.getInputStream(), this);
    MessageSiphon err = new MessageSiphon(process.getErrorStream(), this);

    // wait for the process to finish.  if interrupted
    // before waitFor returns, continue waiting
    boolean compiling = true;
    while (compiling) {
      try {
        if (in.thread != null)
          in.thread.join();
        if (err.thread != null)
          err.thread.join();
        result = process.waitFor();
        //System.out.println("result is " + result);
        compiling = false;
      } catch (InterruptedException ignored) { }
    }

    // an error was queued up by message(), barf this back to compile(),
    // which will barf it back to Editor. if you're having trouble
    // discerning the imagery, consider how cows regurgitate their food
    // to digest it, and the fact that they have five stomaches.
    //
    //System.out.println("throwing up " + exception);
    if (exception != null) { throw exception; }

    if (result > 1) {
      // a failure in the tool (e.g. unable to locate a sub-executable)
      System.err.println(
	  I18n.format(_("{0} returned {1}"), command[0], result));
    }

    if (result != 0) {
      RunnerException re = new RunnerException(_("Error compiling."));
      re.hideStackTrace();
      throw re;
    }
  }

  /**
   * Either succeeds or throws a RunnerException fit for public consumption.
   */
  private void execAsynchronouslyShell(List commandList) throws RunnerException {
    String arch = Base.getArch();
	String[] command = new String[commandList.size()];
    commandList.toArray(command);
    int result = 0;

    if (verbose || Preferences.getBoolean("build.verbose")) {
      for(int j = 0; j < command.length; j++) {
        System.out.print(command[j] + " ");
      }
      System.out.println();
    }
    System.out.println(Arrays.toString(command));   
    firstErrorFound = false;  // haven't found any errors yet
    secondErrorFound = false;
    Process process;
    try {
        if(arch == "c2000")
        {
        	if(Base.isLinux() || Base.isMacOS())
        	{
        	    String command_line = "";
        	    for(String str:command)
        	    {
        	    	command_line += str+" ";
    
        	    }
    	    	process = Runtime.getRuntime().exec(new String[]{"bash","-c",command_line});
    	    	System.out.println(command_line);
        	}
        	else
        	{
        		process = Runtime.getRuntime().exec(command);
        	}
        }
        else
        {
      process = Runtime.getRuntime().exec(command);
        }
    } catch (IOException e) {
      RunnerException re = new RunnerException(e.getMessage());
      re.hideStackTrace();
      throw re;
    }

    MessageSiphon in = new MessageSiphon(process.getInputStream(), this);
    MessageSiphon err = new MessageSiphon(process.getErrorStream(), this);

    // wait for the process to finish.  if interrupted
    // before waitFor returns, continue waiting
    boolean compiling = true;
    while (compiling) {
      try {
        if (in.thread != null)
          in.thread.join();
        if (err.thread != null)
          err.thread.join();
        result = process.waitFor();
        //System.out.println("result is " + result);
        compiling = false;
      } catch (InterruptedException ignored) { }
    }

    // an error was queued up by message(), barf this back to compile(),
    // which will barf it back to Editor. if you're having trouble
    // discerning the imagery, consider how cows regurgitate their food
    // to digest it, and the fact that they have five stomaches.
    //
    //System.out.println("throwing up " + exception);
    if (exception != null) { throw exception; }

    if (result > 1) {
      // a failure in the tool (e.g. unable to locate a sub-executable)
      System.err.println(
	  I18n.format(_("{0} returned {1}"), command[0], result));
    }

    if (result != 0) {
      RunnerException re = new RunnerException(_("Error compiling."));
      re.hideStackTrace();
      throw re;
    }
  }


  /**
   * Part of the MessageConsumer interface, this is called
   * whenever a piece (usually a line) of error message is spewed
   * out from the compiler. The errors are parsed for their contents
   * and line number, which is then reported back to Editor.
   */
  public void message(String s) {
    int i;

    // remove the build path so people only see the filename
    // can't use replaceAll() because the path may have characters in it which
    // have meaning in a regular expression.
    if (!verbose) {
      while ((i = s.indexOf(buildPath + File.separator)) != -1) {
        s = s.substring(0, i) + s.substring(i + (buildPath + File.separator).length());
      }
    }
  
    // look for error line, which contains file name, line number,
    // and at least the first line of the error message
    String errorFormat = "([\\w\\d_]+.\\w+):(\\d+):\\s*error:\\s*(.*)\\s*";
    String[] pieces = PApplet.match(s, errorFormat);

//    if (pieces != null && exception == null) {
//      exception = sketch.placeException(pieces[3], pieces[1], PApplet.parseInt(pieces[2]) - 1);
//      if (exception != null) exception.hideStackTrace();
//    }
    
    if (pieces != null) {
      String error = pieces[3], msg = "";
      
      if (pieces[3].trim().equals("SPI.h: No such file or directory")) {
        error = _("Please import the SPI library from the Sketch > Import Library menu.");
        msg = _("\nAs of Arduino 0019, the Ethernet library depends on the SPI library." +
              "\nYou appear to be using it or another library that depends on the SPI library.\n\n");
      }
      
      if (pieces[3].trim().equals("'BYTE' was not declared in this scope")) {
        error = _("The 'BYTE' keyword is no longer supported.");
        msg = _("\nAs of Arduino 1.0, the 'BYTE' keyword is no longer supported." +
              "\nPlease use Serial.write() instead.\n\n");
      }
      
      if (pieces[3].trim().equals("no matching function for call to 'Server::Server(int)'")) {
        error = _("The Server class has been renamed EthernetServer.");
        msg = _("\nAs of Arduino 1.0, the Server class in the Ethernet library " +
              "has been renamed to EthernetServer.\n\n");
      }
      
      if (pieces[3].trim().equals("no matching function for call to 'Client::Client(byte [4], int)'")) {
        error = _("The Client class has been renamed EthernetClient.");
        msg = _("\nAs of Arduino 1.0, the Client class in the Ethernet library " +
              "has been renamed to EthernetClient.\n\n");
      }
      
      if (pieces[3].trim().equals("'Udp' was not declared in this scope")) {
        error = _("The Udp class has been renamed EthernetUdp.");
        msg = _("\nAs of Arduino 1.0, the Udp class in the Ethernet library " +
              "has been renamed to EthernetClient.\n\n");
      }
      
      if (pieces[3].trim().equals("'class TwoWire' has no member named 'send'")) {
        error = _("Wire.send() has been renamed Wire.write().");
        msg = _("\nAs of Arduino 1.0, the Wire.send() function was renamed " +
              "to Wire.write() for consistency with other libraries.\n\n");
      }
      
      if (pieces[3].trim().equals("'class TwoWire' has no member named 'receive'")) {
        error = _("Wire.receive() has been renamed Wire.read().");
        msg = _("\nAs of Arduino 1.0, the Wire.receive() function was renamed " +
              "to Wire.read() for consistency with other libraries.\n\n");
      }

      RunnerException e = null;
      if (!sketchIsCompiled) {
        // Place errors when compiling the sketch, but never while compiling libraries
        // or the core.  The user's sketch might contain the same filename!
        e = sketch.placeException(error, pieces[1], PApplet.parseInt(pieces[2]) - 1);
      }

      // replace full file path with the name of the sketch tab (unless we're
      // in verbose mode, in which case don't modify the compiler output)
      if (e != null && !verbose) {
        SketchCode code = sketch.getCode(e.getCodeIndex());
        String fileName = (code.isExtension("ino") || code.isExtension("pde")) ? code.getPrettyName() : code.getFileName();
        int lineNum = e.getCodeLine() + 1;
        s = fileName + ":" + lineNum + ": error: " + pieces[3] + msg;
      }
            
      if (exception == null && e != null) {
        exception = e;
        exception.hideStackTrace();
      }      
    }
    
    System.err.print(s);
  }

  /////////////////////////////////////////////////////////////////////////////

  static private List getCommandCompilerS(String basePath, List includePaths,
    String sourceName, String objectName, Map<String, String> boardPreferences) {
    String arch = Base.getArch();
    
    List baseCommandCompiler;
    
    if (arch == "msp430") {
    	//as per
    	//http://mspgcc.sourceforge.net/manual/x1522.html
        baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {
          basePath + "msp430-gcc",
          "-c", // compile, don't link
//          "-g", // include debugging info (so errors include line numbers)
          "-assembler-with-cpp",
          "-mmcu=" + boardPreferences.get("build.mcu"),
          "-DF_CPU=" + boardPreferences.get("build.f_cpu"),
          "-DARDUINO=" + Base.REVISION,
          "-DENERGIA=" + Base.EREVISION,
        }));
        
        if(Preferences.getBoolean("build.debug"))
        	baseCommandCompiler.add("-g");

    } else if (arch == "lm4f" || arch == "cc3200") {
        baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {
          basePath + "arm-none-eabi-gcc",
          "-c",
//          "-g",
//          "-gdwarf-2",
          "-assembler-with-cpp",
          Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
          "-mthumb", "-mcpu=cortex-m4"
        }));

		if(arch == "lm4f") {
			baseCommandCompiler.add("-mfloat-abi=hard");
			baseCommandCompiler.add("-mfpu=fpv4-sp-d16");
			baseCommandCompiler.add("-fsingle-precision-constant");
		}

        baseCommandCompiler.add("-DF_CPU=" + boardPreferences.get("build.f_cpu"));
        baseCommandCompiler.add("-DARDUINO=" + Base.REVISION);
        baseCommandCompiler.add("-DENERGIA=" + Base.EREVISION);

        if(Preferences.getBoolean("build.debug")) {
        	baseCommandCompiler.add("-g");
        	baseCommandCompiler.add("-gdwarf-2");
        }

    } else if (arch == "c2000") {
    	
        String[] filePrefix = new String[2];
        filePrefix = sourceName.split(".s");
      	//TODO: Figure out compiler args...updated needs testing
        baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {basePath + "cl2000"}));
        baseCommandCompiler.add("-v28");//compile for c28x
        baseCommandCompiler.add("--asm_extension=S");//change assembly extension so it picks up S files
        baseCommandCompiler.add("-ml");//compile for unified memory model
        baseCommandCompiler.add("-mt");//compile for large memory model
        baseCommandCompiler.add("-g"); // include debugging info (so errors include line numbers)
        for (int i = 0; i < includePaths.size(); i++) {
        	baseCommandCompiler.add("--include_path=" + '\"' + (String) includePaths.get(i)+ '\"' );
        }      
        baseCommandCompiler.add("--gcc");//enable gcc extensions
        baseCommandCompiler.add("--define=ENERGIA=" + Base.EREVISION);
        baseCommandCompiler.add("--define=F_CPU=" + boardPreferences.get("build.f_cpu"));
        baseCommandCompiler.add("--define=" + boardPreferences.get("build.mcu"));
        baseCommandCompiler.add("--define=ARDUINO=" + Base.REVISION);
        baseCommandCompiler.add("--diag_warning=225");
        baseCommandCompiler.add("--gen_func_subsections=on");
        baseCommandCompiler.add("--display_error_number");
        baseCommandCompiler.add("--diag_wrap=off");
        baseCommandCompiler.add("--preproc_with_compile");
        baseCommandCompiler.add("--preproc_dependency=" + '\"' + filePrefix[0]+".pp" + '\"');
    } else {
        baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {
           basePath + "avr-gcc",
          "-c", // compile, don't link
          "-g", // include debugging info (so errors include line numbers)
          "-assembler-with-cpp",
          "-mmcu=" + boardPreferences.get("build.mcu"),
          "-DF_CPU=" + boardPreferences.get("build.f_cpu"),
          "-DARDUINO=" + Base.REVISION,
        }));
    }
    
    for (int i = 0; i < includePaths.size(); i++) {
    	if(arch == "c2000"){
//    		baseCommandCompilerCPP.add("--include_path=" + '\"' + (String) includePaths.get(i)+ '\"' );
    	}else{
    		baseCommandCompiler.add("-I" + (String) includePaths.get(i));
    	}
    }

    if(arch == "c2000"){
    	baseCommandCompiler.add('\"' + sourceName + '\"');
    	baseCommandCompiler.add("--output_file=" + objectName);
    }else{
    	baseCommandCompiler.add(sourceName);
    	baseCommandCompiler.add("-o");
    	baseCommandCompiler.add(objectName);
    }

    return baseCommandCompiler;
  }

  
  static private List getCommandCompilerC(String basePath, List includePaths,
    String sourceName, String objectName, Map<String, String> boardPreferences) {
	 String arch = Base.getArch();
     List baseCommandCompiler;

      if (arch == "msp430") {
      baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {
        basePath + "msp430-gcc",
        "-c", // compile, don't link
//        "-g", // include debugging info (so errors include line numbers)
        "-Os", // optimize for size
        Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
        "-ffunction-sections", // place each function in its own section
        "-fdata-sections",
        "-mmcu=" + boardPreferences.get("build.mcu"),
        "-DF_CPU=" + boardPreferences.get("build.f_cpu"),
        "-MMD", // output dependancy info
        "-DARDUINO=" + Base.REVISION,
        "-DENERGIA=" + Base.EREVISION,
      }));

      if(Preferences.getBoolean("build.debug"))
      	baseCommandCompiler.add("-g");

      }else if (arch == "lm4f" || arch == "cc3200") {
        baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {
        basePath + "arm-none-eabi-gcc",
        "-c",
//        "-g",
//        "-gdwarf-2",
        "-Os",
        Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
        "-ffunction-sections",
        "-fdata-sections",
        "-mthumb", "-mcpu=cortex-m4",
      }));

	if(arch == "lm4f") {
		baseCommandCompiler.add("-mfloat-abi=hard");
		baseCommandCompiler.add("-mfpu=fpv4-sp-d16");
		baseCommandCompiler.add("-fsingle-precision-constant");
	}

        baseCommandCompiler.add("-DF_CPU=" + boardPreferences.get("build.f_cpu"));
        baseCommandCompiler.add("-MMD"); // output dependancy info
        baseCommandCompiler.add("-DARDUINO=" + Base.REVISION);
        baseCommandCompiler.add("-DENERGIA=" + Base.EREVISION);

        if(Preferences.getBoolean("build.debug")) {
        	baseCommandCompiler.add("-g");
        	baseCommandCompiler.add("-gdwarf-2");
        }

      } else if (arch == "c2000") {
      	
          String[] filePrefix = new String[2];
          filePrefix = sourceName.split(".c");
        	//TODO: Figure out compiler args...updated needs testing
          baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {basePath + "cl2000"}));
          baseCommandCompiler.add("-v28");//compile for c28x
          //baseCommandCompiler.add("-O2");//optimize level 2
          baseCommandCompiler.add("-ml");//compile for unified memory model
          baseCommandCompiler.add("-mt");//compile for large memory model
          baseCommandCompiler.add("-g"); // include debugging info (so errors include line numbers)
          for (int i = 0; i < includePaths.size(); i++) {
        	  baseCommandCompiler.add("--include_path=" + '\"' + (String) includePaths.get(i)+ '\"' );
          }      
          baseCommandCompiler.add("--gcc");//enable gcc extensions
          baseCommandCompiler.add("--define=ENERGIA=" + Base.EREVISION);
          baseCommandCompiler.add("--define=F_CPU=" + boardPreferences.get("build.f_cpu"));
          baseCommandCompiler.add("--define=" + boardPreferences.get("build.mcu"));
          baseCommandCompiler.add("--define=ARDUINO=" + Base.REVISION);
          baseCommandCompiler.add("--diag_warning=225");
          baseCommandCompiler.add("--gen_func_subsections=on");
          baseCommandCompiler.add("--display_error_number");
          baseCommandCompiler.add("--diag_wrap=off");
          baseCommandCompiler.add("--preproc_with_compile");
          baseCommandCompiler.add("--preproc_dependency=" + '\"' + filePrefix[0]+".pp" + '\"');

      }else { // default to avr
        baseCommandCompiler = new ArrayList(Arrays.asList(new String[] {
        basePath + "avr-gcc",
        "-c", // compile, don't link
        "-g", // include debugging info (so errors include line numbers)
        "-Os", // optimize for size
        Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
        "-ffunction-sections", // place each function in its own section
        "-fdata-sections",
        "-mmcu=" + boardPreferences.get("build.mcu"),
        "-DF_CPU=" + boardPreferences.get("build.f_cpu"),
        "-MMD", // output dependancy info
        "-DARDUINO=" + Base.REVISION,
        }));
    }
		
      for (int i = 0; i < includePaths.size(); i++) {
      	if(arch == "c2000"){
//      		baseCommandCompilerCPP.add("--include_path=" + '\"' + (String) includePaths.get(i)+ '\"' );
      	}else{
      		baseCommandCompiler.add("-I" + (String) includePaths.get(i));
      	}
      }

      if(arch == "c2000"){
    	  baseCommandCompiler.add('\"' + sourceName + '\"');
    	  baseCommandCompiler.add("--output_file=" + objectName);
      }else{
    	  baseCommandCompiler.add(sourceName);
    	  baseCommandCompiler.add("-o");
    	  baseCommandCompiler.add(objectName);
      }

    return baseCommandCompiler;
  }
	
	
  static private List getCommandCompilerCPP(String basePath,
    List includePaths, String sourceName, String objectName,
    Map<String, String> boardPreferences) {
    
    String arch = Base.getArch();
    List baseCommandCompilerCPP;
    if (arch == "msp430") {  
      baseCommandCompilerCPP = new ArrayList(Arrays.asList(new String[] {
        basePath + "msp430-g++",
        "-c", // compile, don't link
//        "-g", // include debugging info (so errors include line numbers)
        "-Os", // optimize for size
        Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
        "-ffunction-sections", // place each function in its own section
        "-fdata-sections",
        "-mmcu=" + boardPreferences.get("build.mcu"),
        "-DF_CPU=" + boardPreferences.get("build.f_cpu"),
        "-MMD", // output dependancy info
        "-DARDUINO=" + Base.REVISION,
        "-DENERGIA=" + Base.EREVISION,
      }));
      
      if(Preferences.getBoolean("build.debug"))
      	baseCommandCompilerCPP.add("-g");
    } 
    else if (arch == "lm4f" || arch == "cc3200") {
        baseCommandCompilerCPP = new ArrayList(Arrays.asList(new String[] {
          basePath + "arm-none-eabi-g++",
          "-c",
//          "-g", // include debugging info (so errors include line numbers)
//          "-gdwarf-2",
          "-Os",
          Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
          "-fno-rtti",
          "-fno-exceptions",
          "-ffunction-sections", // place each function in its own section
          "-fdata-sections",
          "-mthumb", "-mcpu=cortex-m4",
        }));

	if(arch == "lm4f") {
		baseCommandCompilerCPP.add("-mfloat-abi=hard");
		baseCommandCompilerCPP.add("-mfpu=fpv4-sp-d16");
		baseCommandCompilerCPP.add("-fsingle-precision-constant");
	}

        baseCommandCompilerCPP.add("-DF_CPU=" + boardPreferences.get("build.f_cpu"));
        baseCommandCompilerCPP.add("-MMD"); // output dependancy info
        baseCommandCompilerCPP.add("-DARDUINO=" + Base.REVISION);
        baseCommandCompilerCPP.add("-DENERGIA=" + Base.EREVISION);

        if(Preferences.getBoolean("build.debug")) {
        	baseCommandCompilerCPP.add("-g");
        	baseCommandCompilerCPP.add("-gdwarf-2");
        }

    }else if (arch == "c2000") {
    	
      String[] filePrefix = new String[2];
      filePrefix = sourceName.split(".cpp");
    	//TODO: Figure out compiler args...updated needs testing
      baseCommandCompilerCPP = new ArrayList(Arrays.asList(new String[] {basePath + "cl2000"}));
      baseCommandCompilerCPP.add("-v28");//compile for c28x
      //baseCommandCompilerCPP.add("-O2");//optimize level 2
      baseCommandCompilerCPP.add("-ml");//compile for unified memory model
      baseCommandCompilerCPP.add("-mt");//compile for large memory model
      baseCommandCompilerCPP.add("-g"); // include debugging info (so errors include line numbers)
      for (int i = 0; i < includePaths.size(); i++) {
      	baseCommandCompilerCPP.add("--include_path=" + '\"' + (String) includePaths.get(i)+ '\"' );
      }      
      baseCommandCompilerCPP.add("--gcc");//enable gcc extensions
      baseCommandCompilerCPP.add("--define=ENERGIA=" + Base.EREVISION);
      baseCommandCompilerCPP.add("--define=F_CPU=" + boardPreferences.get("build.f_cpu"));
      baseCommandCompilerCPP.add("--define=" + boardPreferences.get("build.mcu"));
      baseCommandCompilerCPP.add("--define=ARDUINO=" + Base.REVISION);
      baseCommandCompilerCPP.add("--diag_warning=225");
      baseCommandCompilerCPP.add("--gen_func_subsections=on");
      baseCommandCompilerCPP.add("--display_error_number");
      baseCommandCompilerCPP.add("--diag_wrap=off");
      baseCommandCompilerCPP.add("--preproc_with_compile");
      baseCommandCompilerCPP.add("--preproc_dependency=" + '\"' + filePrefix[0]+".pp" + '\"');
    } else { // default to avr
      baseCommandCompilerCPP = new ArrayList(Arrays.asList(new String[] {
        basePath + "avr-g++",
        "-c", // compile, don't link
        "-g", // include debugging info (so errors include line numbers)
        "-Os", // optimize for size
        Preferences.getBoolean("build.verbose") ? "-Wall" : "-w", // show warnings if verbose
        "-fno-exceptions",
        "-ffunction-sections", // place each function in its own section
        "-fdata-sections",
        "-mmcu=" + boardPreferences.get("build.mcu"),
        "--define=F_CPU=" + boardPreferences.get("build.f_cpu"),
        "-MMD", // output dependancy info
        "-define=ARDUINO=" + Base.REVISION,
      }));
    } 

    for (int i = 0; i < includePaths.size(); i++) {
    	if(arch == "c2000"){
//    		baseCommandCompilerCPP.add("--include_path=" + '\"' + (String) includePaths.get(i)+ '\"' );
    	}else{
    		 baseCommandCompilerCPP.add("-I" + (String) includePaths.get(i));
    	}
    }

    if(arch == "c2000"){
        baseCommandCompilerCPP.add('\"' + sourceName + '\"');
    	baseCommandCompilerCPP.add("--output_file=" + objectName);
    }else{
        baseCommandCompilerCPP.add(sourceName);
    	baseCommandCompilerCPP.add("-o");
    	baseCommandCompilerCPP.add(objectName);
    }

    return baseCommandCompilerCPP;
  }



  /////////////////////////////////////////////////////////////////////////////

  static private void createFolder(File folder) throws RunnerException {
    if (folder.isDirectory()) return;
    if (!folder.mkdir())
      throw new RunnerException("Couldn't create: " + folder);
  }

  /**
   * Given a folder, return a list of the header files in that folder (but
   * not the header files in its sub-folders, as those should be included from
   * within the header files at the top-level).
   */
  static public String[] headerListFromIncludePath(String path) {
    FilenameFilter onlyHFiles = new FilenameFilter() {
      public boolean accept(File dir, String name) {
        return name.endsWith(".h");
      }
    };
    
    return (new File(path)).list(onlyHFiles);
  }
  
  static public ArrayList<File> findFilesInPath(String path, String extension,
                                                boolean recurse) {
    return findFilesInFolder(new File(path), extension, recurse);
  }
  
  static public ArrayList<File> findFilesInFolder(File folder, String extension,
                                                  boolean recurse) {
    ArrayList<File> files = new ArrayList<File>();
    
    if (folder.listFiles() == null) return files;
    
    for (File file : folder.listFiles()) {
    
      if (file.getName().startsWith(".")) continue; // skip hidden files
      
      if (file.getName().endsWith("." + extension))
        files.add(file);
        
      if (recurse && file.isDirectory()) {
        if(!Preferences.getBoolean("build.drvlib") && file.getName().contentEquals("driverlib")) {
        	continue;
        }

        files.addAll(findFilesInFolder(file, extension, true));
      }
    }
    
    return files;
  }
  
}
