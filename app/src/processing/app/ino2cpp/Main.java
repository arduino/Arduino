/*
 *  ======== Main ========
 *  Main class for the ino2cpp command line tool
 *
 *  This tool is used to generate a GNU make buildable C/C++ project from an
 *  Energia sketch folder.
 */
package processing.app.ino2cpp;

import processing.app.preproc.PdePreprocessor;
import processing.app.Preferences;

import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.Writer;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.util.ArrayList;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Main
{
    final static String USAGE = "usage: ino2cpp [-o output_directory] [-Dname=value] [-E] [-v] [-T template] sketch_directory target";
    static int verbose = 0;
    
    /*
     *  ======== main ========
     *  Energia command line preprocessing tool
     *
     *  Usage:
     *
     *    java -jar ino2cpp.jar [options ...] <sketch_dir> <target_name>[:<variant_name>]
     *
     *    where,
     *       <sketch_dir>   - path to the folder containing the user's sketch
     *
     *       <target>       - name of the target (cc3200emt, msp432, ...)
     *                        Target names are of the form:
     *                            <device>[emt][:<variant>]
     *                        where
     *                            <device> is one of cc3200, msp432, cc2650
     *
     *                            <variant> is a device-specific board
     *                            identifier.
     *                        For example, the following are supported target
     *                        names:
     *                            cc3200emt:CC3200_LAUNCHXL
     *                            cc3200emt:CC3200STK_WIFI
     *                            cc3200emt:RedBearLab_CC3200
     *                            cc3200emt:RedBearLab_WiFi_Mini
     *                            
     *                            msp432:MSP_EXP432P401R
     *
     *                            cc2600emt:CC2650STK_BLE
     *
     *    Options:
     *       -o <build_dir> - path to where main.cpp, <sketch>.cpp, and any
     *                        template generated files are written.  If
     *                        <build_dir> doesn't exist it will be created.
     *                        If this option is not specified, the <build_dir> 
     *                        will be set to the sketch directory.
     *  
     *       -r <root_dir>  - root directory containing file resources such as
     *                        main.cpp templates.  This option also defines
     *                        the following named values (which can be
     *                        referenced from within templates):
     *                            build.app.root - <root_dir> converted to
     *                                an absolute path
     *
     *                            preproc.main.template - the path to the
     *                                template used to generate main.cpp
     *
     *                        If this option is not specified, root_dir is
     *                        set to the current working directory; i.e.,
     *                        Java's "user.dir".
     *
     *       -Dname=value   - defines a name-value pair that can be referenced
     *                        from within a template.  This option can be
     *                        repeated on the command line.
     *
     *                        Templates reference values by enclosing their
     *                        names in back quotes (`).  For example, if
     *                        '-Dfoo=bar' is specified on the command
     *                        line, strings matching `foo` within a template
     *                        will be replaced with "bar" (without the
     *                        quotes).
     *
     *                        In addition to name-value pairs defined on the
     *                        command line, all standard Java runtime
     *                        properties can be referenced.  For example,
     *                        occurrences of `user.dir` will be replaced with
     *                        the absolute path of the working directory of
     *                        the Java application.
     *
     *       -E               only run the pre-processor; i.e., don't copy
     *                        extra source files from the sketch folder to
     *                        the build folder.  If this option is not
     *                        specified, all *.c, *.cpp, *.S and *.h files in
     *                        the skectch folder are copied to the build
     *                        folder with their last modification date
     *                        preserved (to prevent unneeded re-compilation).
     *                        
     *       -T template    - defines a template file that is expanded and 
     *                        written to a file in the output directory with
     *                        a name that's derived from the template's name.
     *                        This option can be repeated on the command line.
     *
     *                        The name of the generated file is the "base name"
     *                        of the template with any trailing ".template*"
     *                        removed.  For example, if the output directory
     *                        is "./build" and the template name is
     *                        "templates/vars.mk.template", the template
     *                        output is written to "./build/vars.mk".
     *                        
     *                        Templates are always expanded after running the 
     *                        preprocessor and, as a result, they can reference
     *                        the following computed values:
     *
     *                            build.extra.sources - space separated list of
     *                                all .c, .cpp, and .S files found in the
     *                                sketch folder
     *
     *                            build.mainsketch - name of the .cpp file
     *                                 generated from the sketch folder's .ino
     *                                 files.
     *
     *                            build.app.root - identifies the installation
     *                                directory for the application running
     *                                main().  Set to <root>, if
     *                                "-r <root>" is specified on the command
     *                                line; otherwise it's set to the Java
     *                                "user.dir" property.
     *                            
     *                            build.variant - identifies a specific board
     *                                for the build.
     *
     *       -v               verbose progress output
     */
    public static void main(String[] args)
    {
        String output = null;
        String root = null;
        String aSketchName = null;
        int start = 0;
        boolean ppOnly = false;
        
        ArrayList<String> templates = new ArrayList<String>();

        /* parse command line options */
        for (start = 0; start < args.length; start++) {
            if (args[start].charAt(0) != '-') {
                break;
            }

            char opt = args[start].charAt(1);
            switch (opt) {
                case 'r': 
                case 'o': 
                case 'T': {
                    start += 1;
                    if (start >= args.length) {
                        System.err.println("missing argument for '-"
                                           + opt + "' option");
                        System.err.println(USAGE);
                        System.exit(1);
                    }
                    switch (opt) {
                        case 'r': root = args[start];
                            break;
                        case 'o': output = args[start];
                            break;
                        case 'T': templates.add(args[start]);
                            break;
                    }
                    break;
                }
                case 'n': {
                    start += 1;
                    aSketchName = args[start];
                    break;
                }
                case 'E': {
                    ppOnly = true;
                    break;
                }
                case 'v': {
                    verbose++;
                    break;
                }
                case 'D': {
                    String name = args[start].substring(2);
                    int index = name.indexOf('=');
                    if (index <= 0) {
                        System.err.println(USAGE);
                        System.exit(1);
                    }
                    String value = name.substring(index + 1);
                    name = name.substring(0, index);
                    System.setProperty(name, value);
                    break;
                }

                default: {
                    /* fail for unknown options */
                    System.err.println(USAGE);
                    System.exit(1);
                }
            }
        }

        if ((args.length - start) != 2) {
            /* require at least two arguments: sketch folder and target */
            System.err.println(USAGE);
            System.exit(1);
        }

        /* get and parse target specification: target[:variant] */
        String target = args[start + 1];
        String variant = null;
        if (target.indexOf(":") > 0) {
            variant = target.substring(target.indexOf(":") + 1);
            target = target.substring(0, target.indexOf(":"));
        }
        if (variant != null) {
            Preferences.set("build.variant", variant);
        }
        
        /* get sketch folder */
        String sketch = args[start];

        /* if output folder is not provided, write files to sketch folder */
        if (output == null) {
            output = args[start];
        }
        
        /* check sketch folder existence */
        File dir = new File(sketch);
        if (!dir.exists() || !dir.isDirectory()) {
            System.err.println("ino2cpp: error: sketch directory '"
                               + sketch + "' doesn't exist or isn't a directory.");
            System.exit(1);
        }

        /* check output folder existence */
        dir = new File(output);
        if (!dir.exists()) {
            /* create the output directory if it doesn't exist */
            if (!dir.mkdirs()) {
                System.err.println(
                    "ino2cpp: error: can't create output directory '"
                    + output + "'.");
                System.exit(1);
            }
        }
        if (!dir.isDirectory()) {
            System.err.println("ino2cpp: error: specified output folder '"
                               + output + "' is not a directory.");
            System.exit(1);
        }
        
        /* set build.app.root for makefile templates */
        if (root == null) {
            root = System.getProperty("user.dir");
        }
        Preferences.set("build.app.root", (new File(root)).getAbsolutePath());

        /* set main.template to use for preprocessing output */
        String tmp = findMain(root, target);
        if (tmp != null) {
            Preferences.set("preproc.main.template", tmp);
        }

        /* run the preprocessor to generate *.cpp files */
        String name = ino2cpp(output, sketch, aSketchName, target, ppOnly);

        if (verbose > 0) {
            System.out.println("generated: " + name);
        }

        if (name == null) {
            System.exit(1);
        }

        /* expand specified template files too (e.g., Variable.mk) */
        for (String tplt : templates) {
            try {
                generate(tplt, output);
            }
            catch (Exception e) {
                System.err.println(e);
                e.printStackTrace();
                System.exit(1);
            }
        }
    }

    /*
     *  ======== ino2cpp ========
     *  buildPath   - path to the build directory (where main.cpp
     *                and <sketch>.cpp are generated and built)
     *  sketchPath  - path to the directory containing user's sketch files
     *  aSketchName - alternative Sketch name. The final output of the 
                      the PdePreprocessor will be this <aSketchName>.ino.cpp
     *  target      - name of the target (cc3200emt, msp432, ...)
     *
     *  Returns null on a failure; otherwise, the basename of the
     *          generated <sketch>.cpp file
     */
    private static String ino2cpp(String buildPath, String sketchPath, String aSketchName,
                                  String target, boolean ppOnly)
    {
        File dir = new File(sketchPath);
        if (!dir.isDirectory()) {
            System.err.println(sketchPath + " is not a directory");
            return (null);
        }
        
        String sketchName = dir.getName();

        /* must set target; the path to main.template is a fxn of target */
        Preferences.set("target", target);
        
        /* set defaults for properties referenced by the preprocessor */
        Preferences.set("editor.tabs.size", "4");
        Preferences.set("preproc.substitute_unicode", "true");

        /* create a filename filter to find all .ino files in a project */
        final ArrayList<String> extraSrc = new ArrayList<String> ();
        final ArrayList<String> extraHdr = new ArrayList<String> ();
        FilenameFilter fileNameFilter = new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name) {
                int lastIndex = name.lastIndexOf('.');
                if (lastIndex > 0) {
                    String ext = name.substring(lastIndex); // get extension
                    if (name.charAt(0) != '.' && (new File(dir, name)).isFile()) {
                        if (ext.equals(".ino")) {
                            return true;
                        }
                        else if (ext.equals(".cpp") || ext.equals(".c")
                                 || ext.equals(".S")) {
                            extraSrc.add(name);
                        }
                        else if (ext.equals(".h")) {
                            extraHdr.add(name);
                        }
                    }
                }
                return false;
            }
        };

        try {
            /* find all .ino files */
            File [] files = dir.listFiles(fileNameFilter);

            /* handle all other sources */
            if ((extraSrc.size() + extraHdr.size()) > 0) {
                /* define "build.extra.sources" (for template expansion) */
                StringBuffer sb = new StringBuffer();
                for (String s : extraSrc) {
                    sb.append(' ');
                    sb.append(s);
                }
                if (sb.length() > 0) {
                    String str = sb.toString();
                    Preferences.set("build.extra.sources", str.substring(1));
                }
                
                /* (optionally) copy extra sources to the build directory */
                if (!ppOnly) {
                    String src = new File(sketchPath).getCanonicalPath();
                    String dst = new File(buildPath).getCanonicalPath();
                    /* don't copy if sketchPath and buildPath are the same */
                    if (!src.equals(dst)) {
                        for (String name : extraSrc) {
                            copyFile(src, dst, name);
                        }
                        for (String name : extraHdr) {
                            copyFile(src, dst, name);
                        }
                    }
                }
            }
            
            /* if there are any .ino file to handle */
            if (files.length > 0) {
                /* create InoCode object list from  all .ino files */
                ArrayList<PdePreprocessor.InoCode> code =
                    new ArrayList<PdePreprocessor.InoCode>();
                for (int i = 0; i < files.length; i++) {
                    if (verbose > 0) {
                        System.out.println("   scanning "
                            + files[i].getAbsolutePath() + " ...");
                    }
                    code.add(new PdePreprocessor.InoCode(files[i]));
                }
        
                /* scan code files, put results in buildPath folder,
                 * and return generated main sketch file name
                 */
                PdePreprocessor preproc = new PdePreprocessor();
                String main = preproc.generate(buildPath,
                                               code, sketchName, aSketchName, true);
                Preferences.set("build.mainsketch", main);
                return (main);
            }

        }
        catch (Exception e) {
            System.err.println(e);
            e.printStackTrace();
        }
        
        return (null);
    }

    /*
     *  ======== findMain ========
     *  Locate target-dependent main.cpp template
     */
    private static String findMain(String root, String target)
    {
        String tplt = System.getProperty("preproc.main.template");
        if (tplt != null) {
            return (tplt);
        }
        
        final String fs = File.separator;
        String[] paths = {
            /* standalone command line tool's template directory */
            root + fs + "templates" + fs
                      + target      + fs + "main.template",

            /* Energia 16/17 physical design */
            root + fs + "hardware" + fs
                      + target     + fs
                      + "cores"    + fs
                      + target     + fs + "main.template",

            /* future(?) Energia physical design */
            root + fs + "hardware" + fs
                      + target     + fs + "main.template"
        };

        for (String p : paths) {
            if ((new File(p)).exists()) {
                return (p);
            }
        }
        return (null);
    }

    /* regex for embedded "macros" to be expanded in a template */
    static final Pattern propPattern = Pattern.compile("`([0-9a-zA-Z_.]+)`");

    /*
     *  ======== generate ========
     *  Expand template file into the specified output directory
     */
    static void generate(String tplt, String outputDir)
        throws Exception
    {
        /* convert template file name to destination file name */
        int index = tplt.lastIndexOf('/');
        if (index <  tplt.lastIndexOf('\\')) {
            index = tplt.lastIndexOf('\\');
        }

        String base = tplt.substring(index);
        if ((index = base.lastIndexOf(".template")) > 0) {
            base = base.substring(0, index);
        }
        String dst = outputDir + '/' + base;

        /* flimsy check: should really use getCanonicalPath() here */
        if (dst.equals(tplt)) {
            System.err.println("can't use template '" + tplt
                               + "' to overwrite it self");
            return;
        }
        
        FileWriter file = new FileWriter(dst);
        try {
            generate(tplt, file);
        }
        finally {
            file.close();
        }
    }

    /*
     *  ======== generate ========
     *  Expand template file into the specified output stream
     */
    static void generate(String tplt, Writer out)
        throws Exception
    {
        /* expand template line-by-line, writing result to out */
        BufferedReader reader = new BufferedReader(new FileReader(tplt));
        String         line = null;
        String         nl = System.getProperty("line.separator");

        while ((line = reader.readLine()) != null) {
            line = expand(line) + nl;
            out.write(line);
        }
        reader.close();
    }

    /*
     *  ======== expand ========
     *  Return specified input string with any embeddded marcos expanded
     */
    static String expand(String in)
    {
        String result = "";
        
        Matcher propMatcher = propPattern.matcher(in);
        int start = 0;
        while (propMatcher.find()) {
            /* append chracters before the start of the `` expression */
            String prefix = in.substring(start, propMatcher.start());
            result += prefix;

            /* replace the `` expression with its value */
            result += lookup(propMatcher.group(1));

            /* set the next starting point to the end of the `` expression */
            start = propMatcher.end();
        }

        /* append any characters after the last `` expression */
        if (start < in.length()) {
            result += in.substring(start);
        }

        return (result);
    }

    /*
     *  ======== copyFile ========
     *  Copy src/name to dst/name and preserve modification time
     */
    private static void copyFile(String src, String dst, String name)
        throws Exception
    {
        File srcFile = new File(src, name);
        File dstFile = new File(dst, name);

        if (verbose > 0) {
            System.out.println("   copying " + srcFile + " to " + dstFile);
        }

        FileInputStream ins = new FileInputStream(srcFile);
        FileOutputStream outs = new FileOutputStream(dstFile);
        java.nio.channels.FileChannel inc = ins.getChannel();
        java.nio.channels.FileChannel outc = outs.getChannel();

        /* copy srcFile to dstFile */
        inc.transferTo(0, inc.size(), outc);

        inc.close();
        outc.close();
        ins.close();
        outs.close();

        /* preserve modification dates for make */
        dstFile.setLastModified(srcFile.lastModified());
    }
    
    /*
     *  ======== lookup ========
     *  Lookup specified macro name and return its value
     */
    private static String lookup(String expr)
    {
        String value = Preferences.get(expr);
        if (value == null) {
            value = System.getProperty(expr);
        }

        return (value == null ? "" : value);
    }
}
