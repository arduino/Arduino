/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */

package cc.arduino;

import cc.arduino.i18n.I18NAwareMessageConsumer;
import cc.arduino.packages.BoardPort;
import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.DefaultExecutor;
import org.apache.commons.exec.PumpStreamHandler;
import org.apache.commons.lang3.StringUtils;
import processing.app.*;
import processing.app.debug.*;
import processing.app.helpers.PreferencesMap;
import processing.app.helpers.PreferencesMapException;
import processing.app.helpers.ProcessUtils;
import processing.app.helpers.StringReplacer;
import processing.app.legacy.PApplet;
import processing.app.tools.DoubleQuotedArgumentsOnWindowsCommandLine;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static processing.app.I18n.tr;

public class Compiler implements MessageConsumer {

  //used by transifex integration
  static {
    tr("'arch' folder is no longer supported! See http://goo.gl/gfFJzU for more information");
    tr("Archiving built core (caching) in: {0}");
    tr("Board {0} (platform {1}, package {2}) is unknown");
    tr("Bootloader file specified but missing: {0}");
    tr("Build options changed, rebuilding all");
    tr("Unable to find {0} in {1}");
    tr("Invalid quoting: no closing [{0}] char found.");
    tr("(legacy)");
    tr("Multiple libraries were found for \"{0}\"");
    tr(" Not used: {0}");
    tr(" Used: {0}");
    tr("Library can't use both 'src' and 'utility' folders. Double check {0}");
    tr("WARNING: library {0} claims to run on {1} architecture(s) and may be incompatible with your current board which runs on {2} architecture(s).");
    tr("Looking for recipes like {0}*{1}");
    tr("Board {0}:{1}:{2} doesn''t define a ''build.board'' preference. Auto-set to: {3}");
    tr("Selected board depends on '{0}' core (not installed).");
    tr("{0} must be a folder");
    tr("{0}: Unknown package");
    tr("{0} pattern is missing");
    tr("Platform {0} (package {1}) is unknown");
    tr("Progress {0}");
    tr("Missing '{0}' from library in {1}");
    tr("Running: {0}");
    tr("Running recipe: {0}");
    tr("Setting build path to {0}");
    tr("Unhandled type {0} in context key {1}");
    tr("Unknown sketch file extension: {0}");
    tr("Using library {0} at version {1} in folder: {2} {3}");
    tr("Using library {0} in folder: {1} {2}");
    tr("Using previously compiled file: {0}");
    tr("WARNING: Category '{0}' in library {1} is not valid. Setting to '{2}'");
    tr("Warning: platform.txt from core '{0}' misses property '{1}', using default value '{2}'. Consider upgrading this core.");
    tr("Warning: platform.txt from core '{0}' contains deprecated {1}, automatically converted to {2}. Consider upgrading this core.");
    tr("WARNING: Spurious {0} folder in '{1}' library");
    tr("Sketch uses {0} bytes ({2}%%) of program storage space. Maximum is {1} bytes.");
    tr("Couldn't determine program size: {0}");
    tr("Global variables use {0} bytes ({2}%%) of dynamic memory, leaving {3} bytes for local variables. Maximum is {1} bytes.");
    tr("Global variables use {0} bytes of dynamic memory.");
    tr("Sketch too big; see https://support.arduino.cc/hc/en-us/articles/360013825179 for tips on reducing it.");
    tr("Not enough memory; see https://support.arduino.cc/hc/en-us/articles/360013825179 for tips on reducing your footprint.");
    tr("Low memory available, stability problems may occur.");
    tr("An error occurred while verifying the sketch");
    tr("An error occurred while verifying/uploading the sketch");
    tr("Can't find the sketch in the specified path");
    tr("Done compiling");
    tr("Done uploading");
    tr("Error while uploading");
    tr("Error while verifying");
    tr("Error while verifying/uploading");
    tr("Mode not supported");
    tr("Multiple files not supported");
    tr("No command line parameters found");
    tr("No parameters");
    tr("No sketch");
    tr("No sketchbook");
    tr("Only --verify, --upload or --get-pref are supported");
    tr("Sketchbook path not defined");
    tr("The --upload option supports only one file at a time");
    tr("Verifying and uploading...");
  }

  enum BuilderAction {
    COMPILE("-compile"), DUMP_PREFS("-dump-prefs");

    final String value;

    BuilderAction(String value) {
      this.value = value;
    }
  }

  private static final Pattern ERROR_FORMAT = Pattern.compile("(.+\\.\\w+):(\\d+)(:\\d+)*:\\s*((fatal)?\\s*error:\\s*)(.*)\\s*", Pattern.MULTILINE | Pattern.DOTALL);

  private final File pathToSketch;
  private final Sketch sketch;
  private String buildPath;
  private File buildCache;
  private final boolean verbose;
  private RunnerException exception;

  public Compiler(Sketch data) {
    this(data.getPrimaryFile().getFile(), data);
  }

  public Compiler(File pathToSketch, Sketch sketch) {
    this.pathToSketch = pathToSketch;
    this.sketch = sketch;
    this.verbose = PreferencesData.getBoolean("build.verbose");
  }

  public String build(CompilerProgressListener progListener, boolean exportHex) throws RunnerException, PreferencesMapException, IOException {
    List<CompilerProgressListener> listeners = new ArrayList<>();
    listeners.add(progListener);
    return this.build(listeners, exportHex);
  }

  public String build(List<CompilerProgressListener> progListeners, boolean exportHex) throws RunnerException, PreferencesMapException, IOException {
    this.buildPath = sketch.getBuildPath().getAbsolutePath();
    this.buildCache = BaseNoGui.getCachePath();

    TargetBoard board = BaseNoGui.getTargetBoard();
    if (board == null) {
      throw new RunnerException("Board is not selected");
    }

    TargetPlatform platform = board.getContainerPlatform();
    TargetPackage aPackage = platform.getContainerPackage();
    String vidpid = VIDPID();

    PreferencesMap prefs = loadPreferences(board, platform, aPackage, vidpid);

    MessageConsumerOutputStream out = new MessageConsumerOutputStream(new ProgressAwareMessageConsumer(new I18NAwareMessageConsumer(System.out, System.err), progListeners), "\n");
    MessageConsumerOutputStream err = new MessageConsumerOutputStream(new I18NAwareMessageConsumer(System.err, Compiler.this), "\n");

    callArduinoBuilder(board, platform, aPackage, vidpid, BuilderAction.COMPILE, out, err);

    out.flush();
    err.flush();

    if (exportHex) {
      runActions("hooks.savehex.presavehex", prefs);

      saveHex(prefs);

      runActions("hooks.savehex.postsavehex", prefs);
    }

    return sketch.getPrimaryFile().getFileName();
  }

  private String VIDPID() {
    BoardPort boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
    if (boardPort == null) {
      return "";
    }

    String vid = boardPort.getPrefs().get("vid");
    String pid = boardPort.getPrefs().get("pid");
    if (StringUtils.isEmpty(vid) || StringUtils.isEmpty(pid)) {
      return "";
    }

    return vid.toUpperCase() + "_" + pid.toUpperCase();
  }

  private PreferencesMap loadPreferences(TargetBoard board, TargetPlatform platform, TargetPackage aPackage, String vidpid) throws RunnerException, IOException {
    ByteArrayOutputStream stdout = new ByteArrayOutputStream();
    ByteArrayOutputStream stderr = new ByteArrayOutputStream();
    MessageConsumerOutputStream err = new MessageConsumerOutputStream(new I18NAwareMessageConsumer(new PrintStream(stderr), Compiler.this), "\n");
    try {
      callArduinoBuilder(board, platform, aPackage, vidpid, BuilderAction.DUMP_PREFS, stdout, err);
    } catch (RunnerException e) {
      System.err.println(new String(stderr.toByteArray()));
      throw e;
    }
    PreferencesMap prefs = new PreferencesMap();
    prefs.load(new ByteArrayInputStream(stdout.toByteArray()));
    return prefs;
  }

  private void addPathFlagIfPathExists(List<String> cmd, String flag, File folder) {
    if (folder.exists()) {
      cmd.add(flag);
      cmd.add(folder.getAbsolutePath());
    }
  }

  private void callArduinoBuilder(TargetBoard board, TargetPlatform platform, TargetPackage aPackage, String vidpid, BuilderAction action, OutputStream outStream, OutputStream errStream) throws RunnerException {
    List<String> cmd = new ArrayList<>();
    cmd.add(BaseNoGui.getContentFile("arduino-builder").getAbsolutePath());
    cmd.add(action.value);
    cmd.add("-logger=machine");

    File installedPackagesFolder = new File(BaseNoGui.getSettingsFolder(), "packages");

    addPathFlagIfPathExists(cmd, "-hardware", BaseNoGui.getHardwareFolder());
    addPathFlagIfPathExists(cmd, "-hardware", installedPackagesFolder);
    addPathFlagIfPathExists(cmd, "-hardware", BaseNoGui.getSketchbookHardwareFolder());

    addPathFlagIfPathExists(cmd, "-tools", BaseNoGui.getContentFile("tools-builder"));
    addPathFlagIfPathExists(cmd, "-tools", Paths.get(BaseNoGui.getHardwarePath(), "tools", "avr").toFile());
    addPathFlagIfPathExists(cmd, "-tools", installedPackagesFolder);

    if(PreferencesData.getBoolean("build.load_sketch_libraries") == true) {
        addPathFlagIfPathExists(cmd, "-libraries",Paths.get(sketch.getFolder().getAbsolutePath(),"libraries").toFile());
    }

    addPathFlagIfPathExists(cmd, "-built-in-libraries", BaseNoGui.getContentFile("libraries"));

   
    addPathFlagIfPathExists(cmd, "-libraries", BaseNoGui.getSketchbookLibrariesFolder().folder);

    String fqbn = Stream.of(aPackage.getId(), platform.getId(), board.getId(), boardOptions(board)).filter(s -> !s.isEmpty()).collect(Collectors.joining(":"));
    cmd.add("-fqbn=" + fqbn);

    if (!"".equals(vidpid)) {
      cmd.add("-vid-pid=" + vidpid);
    }

    cmd.add("-ide-version=" + BaseNoGui.REVISION);
    cmd.add("-build-path");
    cmd.add(buildPath);
    cmd.add("-warnings=" + PreferencesData.get("compiler.warning_level"));

    if (PreferencesData.getBoolean("compiler.cache_core") == true && buildCache != null) {
      cmd.add("-build-cache");
      cmd.add(buildCache.getAbsolutePath());
    }

    PreferencesData.getMap()
      .subTree("runtime.build_properties_custom")
      .entrySet()
      .stream()
      .forEach(kv -> cmd.add("-prefs=" + kv.getKey() + "=" + kv.getValue()));

    cmd.add("-prefs=build.warn_data_percentage=" + PreferencesData.get("build.warn_data_percentage"));

    for (Map.Entry<String, String> entry : BaseNoGui.getBoardPreferences().entrySet()) {
        if (entry.getKey().startsWith("runtime.tools")) {
          cmd.add("-prefs=" + entry.getKey() + "=" + entry.getValue());
        }
    }

    //commandLine.addArgument("-debug-level=10", false);

    if (verbose) {
      cmd.add("-verbose");
    }

    cmd.add(pathToSketch.getAbsolutePath());

    if (verbose) {
      System.out.println(StringUtils.join(cmd, ' '));
    }

    int result;
    try {
      Process proc = ProcessUtils.exec(cmd.toArray(new String[0]));
      MessageSiphon in = new MessageSiphon(proc.getInputStream(), (msg) -> {
        try {
          outStream.write(msg.getBytes());
        } catch (Exception e) {
          exception = new RunnerException(e);
        }
      });
      MessageSiphon err = new MessageSiphon(proc.getErrorStream(), (msg) -> {
        try {
          errStream.write(msg.getBytes());
        } catch (Exception e) {
          exception = new RunnerException(e);
        }
      });

      in.join();
      err.join();
      result = proc.waitFor();
    } catch (Exception e) {
      throw new RunnerException(e);
    }

    if (exception != null)
      throw exception;

    if (result > 1) {
      System.err.println(I18n.format(tr("{0} returned {1}"), cmd.get(0), result));
    }

    if (result != 0) {
      RunnerException re = new RunnerException(I18n.format(tr("Error compiling for board {0}."), board.getName()));
      re.hideStackTrace();
      throw re;
    }
  }

  private void saveHex(PreferencesMap prefs) throws RunnerException {
    List<String> compiledSketches = new ArrayList<>(prefs.subTree("recipe.output.tmp_file", 1).values());
    List<String> copyOfCompiledSketches = new ArrayList<>(prefs.subTree("recipe.output.save_file", 1).values());

    if (isExportCompiledSketchSupported(compiledSketches, copyOfCompiledSketches, prefs)) {
      System.err.println(tr("Warning: This core does not support exporting sketches. Please consider upgrading it or contacting its author"));
      return;
    }

    PreferencesMap dict = new PreferencesMap(prefs);
    dict.put("ide_version", "" + BaseNoGui.REVISION);
    PreferencesMap withBootloaderDict = new PreferencesMap(dict);
    dict.put("build.project_name", dict.get("build.project_name") + ".with_bootloader");

    if (!compiledSketches.isEmpty()) {
      for (int i = 0; i < compiledSketches.size(); i++) {
        saveHex(compiledSketches.get(i), copyOfCompiledSketches.get(i), dict);
        saveHex(compiledSketches.get(i), copyOfCompiledSketches.get(i), withBootloaderDict);
      }
    } else {
      try {
        saveHex(prefs.getOrExcept("recipe.output.tmp_file"), prefs.getOrExcept("recipe.output.save_file"), dict);
        saveHex(prefs.getOrExcept("recipe.output.tmp_file"), prefs.getOrExcept("recipe.output.save_file"), withBootloaderDict);
      } catch (PreferencesMapException e) {
        throw new RunnerException(e);
      }
    }
  }

  private void saveHex(String compiledSketch, String copyOfCompiledSketch, PreferencesMap prefs) throws RunnerException {
    try {
      compiledSketch = StringReplacer.replaceFromMapping(compiledSketch, prefs);
      copyOfCompiledSketch = StringReplacer.replaceFromMapping(copyOfCompiledSketch, prefs);
      copyOfCompiledSketch = copyOfCompiledSketch.replaceAll(":", "_");

      Path compiledSketchPath;
      Path compiledSketchPathInSubfolder = Paths.get(prefs.get("build.path"), "sketch", compiledSketch);
      Path compiledSketchPathInBuildPath = Paths.get(prefs.get("build.path"), compiledSketch);
      if (Files.exists(compiledSketchPathInSubfolder)) {
        compiledSketchPath = compiledSketchPathInSubfolder;
      } else if (Files.exists(compiledSketchPathInBuildPath)) {
        compiledSketchPath = compiledSketchPathInBuildPath;
      } else {
        return;
      }

      Path copyOfCompiledSketchFilePath = Paths.get(this.sketch.getFolder().getAbsolutePath(), copyOfCompiledSketch);

      Files.copy(compiledSketchPath, copyOfCompiledSketchFilePath, StandardCopyOption.REPLACE_EXISTING);
    } catch (IOException e) {
      throw new RunnerException(e);
    }
  }

  private boolean isExportCompiledSketchSupported(List<String> compiledSketches, List<String> copyOfCompiledSketches, PreferencesMap prefs) {
    return (compiledSketches.isEmpty() || copyOfCompiledSketches.isEmpty() || copyOfCompiledSketches.size() < compiledSketches.size()) && (!prefs.containsKey("recipe.output.tmp_file") || !prefs.containsKey("recipe.output.save_file"));
  }

  private void runActions(String recipeClass, PreferencesMap prefs) throws RunnerException, PreferencesMapException {
    List<String> patterns = prefs.keySet().stream().filter(key -> key.startsWith("recipe." + recipeClass) && key.endsWith(".pattern")).collect(Collectors.toList());
    Collections.sort(patterns);
    for (String recipe : patterns) {
      runRecipe(recipe, prefs);
    }
  }

  private void runRecipe(String recipe, PreferencesMap prefs) throws RunnerException, PreferencesMapException {
    PreferencesMap dict = new PreferencesMap(prefs);
    dict.put("ide_version", "" + BaseNoGui.REVISION);
    dict.put("sketch_path", sketch.getFolder().getAbsolutePath());

    String[] cmdArray;
    String cmd = prefs.getOrExcept(recipe);
    try {
      cmdArray = StringReplacer.formatAndSplit(cmd, dict);
    } catch (Exception e) {
      throw new RunnerException(e);
    }
    exec(cmdArray);
  }

  private void exec(String[] command) throws RunnerException {
    // eliminate any empty array entries
    List<String> stringList = new ArrayList<>();
    for (String string : command) {
      string = string.trim();
      if (string.length() != 0)
        stringList.add(string);
    }
    command = stringList.toArray(new String[stringList.size()]);
    if (command.length == 0)
      return;

    if (verbose) {
      for (String c : command)
        System.out.print(c + " ");
      System.out.println();
    }

    DefaultExecutor executor = new DefaultExecutor();
    executor.setStreamHandler(new PumpStreamHandler() {

      @Override
      protected Thread createPump(InputStream is, OutputStream os, boolean closeWhenExhausted) {
        final Thread result = new Thread(new MyStreamPumper(is, Compiler.this));
        result.setName("MyStreamPumper Thread");
        result.setDaemon(true);
        return result;

      }
    });

    CommandLine commandLine = new DoubleQuotedArgumentsOnWindowsCommandLine(command[0]);
    for (int i = 1; i < command.length; i++) {
      commandLine.addArgument(command[i], false);
    }

    int result;
    executor.setExitValues(null);
    try {
      result = executor.execute(commandLine);
    } catch (IOException e) {
      RunnerException re = new RunnerException(e.getMessage());
      re.hideStackTrace();
      throw re;
    }
    executor.setExitValues(new int[0]);

    // an error was queued up by message(), barf this back to compile(),
    // which will barf it back to Editor. if you're having trouble
    // discerning the imagery, consider how cows regurgitate their food
    // to digest it, and the fact that they have five stomaches.
    //
    //System.out.println("throwing up " + exception);
    if (exception != null)
      throw exception;

    if (result > 1) {
      // a failure in the tool (e.g. unable to locate a sub-executable)
      System.err
        .println(I18n.format(tr("{0} returned {1}"), command[0], result));
    }

    if (result != 0) {
      RunnerException re = new RunnerException(tr("Error compiling."));
      re.hideStackTrace();
      throw re;
    }
  }

  private String boardOptions(TargetBoard board) {
    return board.getMenuIds().stream()
      .filter(board::hasMenu)
      .filter(menuId -> {
        String entry = PreferencesData.get("custom_" + menuId);
        return entry != null && entry.startsWith(board.getId());
      })
      .map(menuId -> {
        String entry = PreferencesData.get("custom_" + menuId);
        String selectionId = entry.substring(board.getId().length() + 1);
        return menuId + "=" + selectionId;
      })
      .collect(Collectors.joining(","));
  }

  /**
   * Part of the MessageConsumer interface, this is called
   * whenever a piece (usually a line) of error message is spewed
   * out from the compiler. The errors are parsed for their contents
   * and line number, which is then reported back to Editor.
   */
  @Override
  public void message(String s) {
    int i;

    if (!verbose) {
      while ((i = s.indexOf(buildPath + File.separator)) != -1) {
        s = s.substring(0, i) + s.substring(i + (buildPath + File.separator).length());
      }
    }

    String[] pieces = PApplet.match(s, ERROR_FORMAT);

    if (pieces != null) {
      String msg = "";
      String filename = pieces[1];
      int line = PApplet.parseInt(pieces[2]);
      int col = -1;
      if (pieces[3] != null) {
        col = PApplet.parseInt(pieces[3].substring(1));
      }
      String errorPrefix = pieces[4];
      String error = pieces[6];

      if (error.trim().equals("SPI.h: No such file or directory")) {
        error = tr("Please import the SPI library from the Sketch > Import Library menu.");
        msg = tr("\nAs of Arduino 0019, the Ethernet library depends on the SPI library." +
          "\nYou appear to be using it or another library that depends on the SPI library.\n\n");
      }

      if (error.trim().equals("'BYTE' was not declared in this scope")) {
        error = tr("The 'BYTE' keyword is no longer supported.");
        msg = tr("\nAs of Arduino 1.0, the 'BYTE' keyword is no longer supported." +
          "\nPlease use Serial.write() instead.\n\n");
      }

      if (error.trim().equals("no matching function for call to 'Server::Server(int)'")) {
        error = tr("The Server class has been renamed EthernetServer.");
        msg = tr("\nAs of Arduino 1.0, the Server class in the Ethernet library " +
          "has been renamed to EthernetServer.\n\n");
      }

      if (error.trim().equals("no matching function for call to 'Client::Client(byte [4], int)'")) {
        error = tr("The Client class has been renamed EthernetClient.");
        msg = tr("\nAs of Arduino 1.0, the Client class in the Ethernet library " +
          "has been renamed to EthernetClient.\n\n");
      }

      if (error.trim().equals("'Udp' was not declared in this scope")) {
        error = tr("The Udp class has been renamed EthernetUdp.");
        msg = tr("\nAs of Arduino 1.0, the Udp class in the Ethernet library " +
          "has been renamed to EthernetUdp.\n\n");
      }

      if (error.trim().equals("'class TwoWire' has no member named 'send'")) {
        error = tr("Wire.send() has been renamed Wire.write().");
        msg = tr("\nAs of Arduino 1.0, the Wire.send() function was renamed " +
          "to Wire.write() for consistency with other libraries.\n\n");
      }

      if (error.trim().equals("'class TwoWire' has no member named 'receive'")) {
        error = tr("Wire.receive() has been renamed Wire.read().");
        msg = tr("\nAs of Arduino 1.0, the Wire.receive() function was renamed " +
          "to Wire.read() for consistency with other libraries.\n\n");
      }

      if (error.trim().equals("'Mouse' was not declared in this scope")) {
        error = tr("'Mouse' not found. Does your sketch include the line '#include <Mouse.h>'?");
        //msg = _("\nThe 'Mouse' class is only supported on the Arduino Leonardo.\n\n");
      }

      if (error.trim().equals("'Keyboard' was not declared in this scope")) {
        error = tr("'Keyboard' not found. Does your sketch include the line '#include <Keyboard.h>'?");
        //msg = _("\nThe 'Keyboard' class is only supported on the Arduino Leonardo.\n\n");
      }

      RunnerException ex = placeException(error, filename, line - 1, col);

      if (ex != null) {
        String fileName = ex.getCodeFile().getPrettyName();
        int lineNum = ex.getCodeLine() + 1;
        int colNum = ex.getCodeColumn();
        String column = (colNum != -1) ? (":" + colNum) : "";
        s = fileName + ":" + lineNum + column + ": " + errorPrefix + error + msg;
      }

      if (ex != null) {
        if (exception == null || exception.getMessage().equals(ex.getMessage())) {
          exception = ex;
          exception.hideStackTrace();
        }
      }
    }

    if (s.contains("undefined reference to `SPIClass::begin()'") &&
      s.contains("libraries/Robot_Control")) {
      String error = tr("Please import the SPI library from the Sketch > Import Library menu.");
      exception = new RunnerException(error);
    }

    if (s.contains("undefined reference to `Wire'") &&
      s.contains("libraries/Robot_Control")) {
      String error = tr("Please import the Wire library from the Sketch > Import Library menu.");
      exception = new RunnerException(error);
    }

    System.err.println(s);
  }

  private RunnerException placeException(String message, String fileName, int line, int col) {
    for (SketchFile file : sketch.getFiles()) {
      if (new File(fileName).getName().equals(file.getFileName())) {
        return new RunnerException(message, file, line, col);
      }
    }
    return null;
  }
}
