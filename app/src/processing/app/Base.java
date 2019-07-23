/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-10 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 2
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package processing.app;

import cc.arduino.Compiler;
import cc.arduino.Constants;
import cc.arduino.UpdatableBoardsLibsFakeURLsHandler;
import cc.arduino.UploaderUtils;
import cc.arduino.contributions.*;
import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.LibrariesIndexer;
import cc.arduino.contributions.libraries.LibraryInstaller;
import cc.arduino.contributions.libraries.LibraryOfSameTypeComparator;
import cc.arduino.contributions.libraries.ui.LibraryManagerUI;
import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.packages.ContributionInstaller;
import cc.arduino.contributions.packages.ContributionsIndexer;
import cc.arduino.contributions.packages.ui.ContributionManagerUI;
import cc.arduino.files.DeleteFilesOnShutdown;
import cc.arduino.packages.DiscoveryManager;
import cc.arduino.packages.Uploader;
import cc.arduino.view.Event;
import cc.arduino.view.JMenuUtils;
import cc.arduino.view.SplashScreenHelper;
import com.github.zafarkhaja.semver.Version;
import org.apache.commons.compress.utils.IOUtils;
import org.apache.commons.lang3.StringUtils;
import processing.app.debug.TargetBoard;
import processing.app.debug.TargetPackage;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.*;
import processing.app.helpers.filefilters.OnlyDirs;
import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.javax.swing.filechooser.FileNameExtensionFilter;
import processing.app.legacy.PApplet;
import processing.app.macosx.ThinkDifferent;
import processing.app.packages.LibraryList;
import processing.app.packages.UserLibrary;
import processing.app.packages.UserLibraryFolder.Location;
import processing.app.syntax.PdeKeywords;
import processing.app.syntax.SketchTextAreaDefaultInputMap;
import processing.app.tools.MenuScroller;
import processing.app.tools.ZipDeflater;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.List;
import java.util.Timer;
import java.util.*;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;


/**
 * The base class for the main processing application.
 * Primary role of this class is for platform identification and
 * general interaction with the system (launching URLs, loading
 * files and images, etc) that comes from that.
 */
public class Base {

  private static final int RECENT_SKETCHES_MAX_SIZE = 10;

  private static boolean commandLine;
  public static volatile Base INSTANCE;

  public static Map<String, Object> FIND_DIALOG_STATE = new HashMap<>();
  private final ContributionInstaller contributionInstaller;
  private final LibraryInstaller libraryInstaller;
  private ContributionsSelfCheck contributionsSelfCheck;

  // set to true after the first time the menu is built.
  // so that the errors while building don't show up again.
  boolean builtOnce;

  // classpath for all known libraries for p5
  // (both those in the p5/libs folder and those with lib subfolders
  // found in the sketchbook)
  static public String librariesClassPath;

  // Location for untitled items
  static File untitledFolder;

  // p5 icon for the window
//  static Image icon;

  //  int editorCount;
  List<Editor> editors = Collections.synchronizedList(new ArrayList<Editor>());
  Editor activeEditor;

  // these menus are shared so that the board and serial port selections
  // are the same for all windows (since the board and serial port that are
  // actually used are determined by the preferences, which are shared)
  private List<JMenu> boardsCustomMenus;
  private List<JMenuItem> programmerMenus;

  private PdeKeywords pdeKeywords;
  private final List<JMenuItem> recentSketchesMenuItems = new LinkedList<>();

  static public void main(String args[]) throws Exception {
    if (!OSUtils.isWindows()) {
      // Those properties helps enabling anti-aliasing on Linux
      // (but not on Windows where they made things worse actually
      // and the font rendering becomes ugly).

      // Those properties must be set before initializing any
      // graphic object, otherwise they don't have any effect.
      System.setProperty("awt.useSystemAAFontSettings", "on");
      System.setProperty("swing.aatext", "true");
    }
    System.setProperty("java.net.useSystemProxies", "true");

    if (OSUtils.isMacOS()) {
      System.setProperty("apple.laf.useScreenMenuBar",
        String.valueOf(!System.getProperty("os.version").startsWith("10.13")
          || com.apple.eawt.Application.getApplication().isAboutMenuItemPresent()));

      ThinkDifferent.init();
    }

    try {
      INSTANCE = new Base(args);
    } catch (Throwable e) {
      e.printStackTrace(System.err);
      System.exit(255);
    }
  }

  static public void initLogger() {
    Handler consoleHandler = new ConsoleLogger();
    consoleHandler.setLevel(Level.ALL);
    consoleHandler.setFormatter(new LogFormatter("%1$tl:%1$tM:%1$tS [%4$7s] %2$s: %5$s%n"));

    Logger globalLogger = Logger.getLogger(Logger.GLOBAL_LOGGER_NAME);
    globalLogger.setLevel(consoleHandler.getLevel());

    // Remove default
    Handler[] handlers = globalLogger.getHandlers();
    for(Handler handler : handlers) {
        globalLogger.removeHandler(handler);
    }
    Logger root = Logger.getLogger("");
    handlers = root.getHandlers();
    for(Handler handler : handlers) {
      root.removeHandler(handler);
    }

    globalLogger.addHandler(consoleHandler);

    Logger.getLogger("cc.arduino.packages.autocomplete").setParent(globalLogger);
    Logger.getLogger("br.com.criativasoft.cpluslibparser").setParent(globalLogger);
    Logger.getLogger(Base.class.getPackage().getName()).setParent(globalLogger);

  }

  static protected boolean isCommandLine() {
    return commandLine;
  }

  // Returns a File object for the given pathname. If the pathname
  // is not absolute, it is interpreted relative to the current
  // directory when starting the IDE (which is not the same as the
  // current working directory!).
  static public File absoluteFile(String path) {
    return BaseNoGui.absoluteFile(path);
  }

  public Base(String[] args) throws Exception {
    Thread deleteFilesOnShutdownThread = new Thread(DeleteFilesOnShutdown.INSTANCE);
    deleteFilesOnShutdownThread.setName("DeleteFilesOnShutdown");
    Runtime.getRuntime().addShutdownHook(deleteFilesOnShutdownThread);

    BaseNoGui.initLogger();

    initLogger();

    BaseNoGui.initPlatform();

    BaseNoGui.getPlatform().init();

    BaseNoGui.initPortableFolder();
    // This configure the logs root folder
    System.out.println("Set log4j store directory " + BaseNoGui.getSettingsFolder().getAbsolutePath());
    System.setProperty("log4j.dir", BaseNoGui.getSettingsFolder().getAbsolutePath());

    // Look for a possible "--preferences-file" parameter and load preferences
    BaseNoGui.initParameters(args);

    CommandlineParser parser = new CommandlineParser(args);
    parser.parseArgumentsPhase1();
    commandLine = !parser.isGuiMode();

    BaseNoGui.checkInstallationFolder();

    // If no path is set, get the default sketchbook folder for this platform
    if (BaseNoGui.getSketchbookPath() == null) {
      File defaultFolder = getDefaultSketchbookFolderOrPromptForIt();
      if (BaseNoGui.getPortableFolder() != null)
        PreferencesData.set("sketchbook.path", BaseNoGui.getPortableSketchbookFolder());
      else
        PreferencesData.set("sketchbook.path", defaultFolder.getAbsolutePath());
      if (!defaultFolder.exists()) {
        defaultFolder.mkdirs();
      }
    }

    SplashScreenHelper splash;
    if (parser.isGuiMode()) {
      // Setup all notification widgets
      splash = new SplashScreenHelper(SplashScreen.getSplashScreen());
      BaseNoGui.notifier = new GUIUserNotifier(this);

      // Setup the theme coloring fun
      Theme.init();
      System.setProperty("swing.aatext", PreferencesData.get("editor.antialias", "true"));

      // Set the look and feel before opening the window
      try {
        BaseNoGui.getPlatform().setLookAndFeel();
      } catch (Exception e) {
        // ignore
      }

      // Use native popups so they don't look so crappy on osx
      JPopupMenu.setDefaultLightWeightPopupEnabled(false);
    } else {
      splash = new SplashScreenHelper(null);
    }

    splash.splashText(tr("Loading configuration..."));

    BaseNoGui.initVersion();

    // Don't put anything above this line that might make GUI,
    // because the platform has to be inited properly first.

    // Create a location for untitled sketches
    untitledFolder = FileUtils.createTempFolder("untitled" + new Random().nextInt(Integer.MAX_VALUE), ".tmp");
    DeleteFilesOnShutdown.add(untitledFolder);

    splash.splashText(tr("Initializing packages..."));
    BaseNoGui.initPackages();

    parser.getUploadPort().ifPresent(BaseNoGui::selectSerialPort);

    splash.splashText(tr("Preparing boards..."));

    if (!isCommandLine()) {
      rebuildBoardsMenu();
      rebuildProgrammerMenu();
    } else {
      TargetBoard lastSelectedBoard = BaseNoGui.getTargetBoard();
      if (lastSelectedBoard != null)
        BaseNoGui.selectBoard(lastSelectedBoard);
    }

    // Setup board-dependent variables.
    onBoardOrPortChange();

    pdeKeywords = new PdeKeywords();
    pdeKeywords.reload();

    final GPGDetachedSignatureVerifier gpgDetachedSignatureVerifier = new GPGDetachedSignatureVerifier();
    contributionInstaller = new ContributionInstaller(BaseNoGui.getPlatform(), gpgDetachedSignatureVerifier);
    libraryInstaller = new LibraryInstaller(BaseNoGui.getPlatform(), gpgDetachedSignatureVerifier);

    parser.parseArgumentsPhase2();

    // Save the preferences. For GUI mode, this happens in the quit
    // handler, but for other modes we should also make sure to save
    // them.
    if (parser.isForceSavePrefs()) {
      PreferencesData.save();
    }

    if (parser.isInstallBoard()) {
      ContributionsIndexer indexer = new ContributionsIndexer(
          BaseNoGui.getSettingsFolder(), BaseNoGui.getHardwareFolder(),
          BaseNoGui.getPlatform(), gpgDetachedSignatureVerifier);
      ProgressListener progressListener = new ConsoleProgressListener();

      List<String> downloadedPackageIndexFiles = contributionInstaller.updateIndex(progressListener);
      contributionInstaller.deleteUnknownFiles(downloadedPackageIndexFiles);
      indexer.parseIndex();
      indexer.syncWithFilesystem();

      String[] boardToInstallParts = parser.getBoardToInstall().split(":");

      ContributedPlatform selected = null;
      if (boardToInstallParts.length == 3) {
        Optional<Version> version = VersionHelper.valueOf(boardToInstallParts[2]);
        if (!version.isPresent()) {
          System.out.println(format(tr("Invalid version {0}"), boardToInstallParts[2]));
          System.exit(1);
        }
        selected = indexer.getIndex().findPlatform(boardToInstallParts[0], boardToInstallParts[1], version.get().toString());
      } else if (boardToInstallParts.length == 2) {
        List<ContributedPlatform> platformsByName = indexer.getIndex().findPlatforms(boardToInstallParts[0], boardToInstallParts[1]);
        Collections.sort(platformsByName, new DownloadableContributionVersionComparator());
        if (!platformsByName.isEmpty()) {
          selected = platformsByName.get(platformsByName.size() - 1);
        }
      }
      if (selected == null) {
        System.out.println(tr("Selected board is not available"));
        System.exit(1);
      }

      ContributedPlatform installed = indexer.getInstalled(boardToInstallParts[0], boardToInstallParts[1]);

      if (!selected.isBuiltIn()) {
        contributionInstaller.install(selected, progressListener);
      }

      if (installed != null && !installed.isBuiltIn()) {
        contributionInstaller.remove(installed);
      }

      System.exit(0);

    } else if (parser.isInstallLibrary()) {
      BaseNoGui.onBoardOrPortChange();

      ProgressListener progressListener = new ConsoleProgressListener();
      libraryInstaller.updateIndex(progressListener);

      LibrariesIndexer indexer = new LibrariesIndexer(BaseNoGui.getSettingsFolder());
      indexer.parseIndex();
      indexer.setLibrariesFolders(BaseNoGui.getLibrariesFolders());
      indexer.rescanLibraries();

      for (String library : parser.getLibraryToInstall().split(",")) {
        String[] libraryToInstallParts = library.split(":");

        ContributedLibrary selected = null;
        if (libraryToInstallParts.length == 2) {
          Optional<Version> version = VersionHelper.valueOf(libraryToInstallParts[1]);
          if (!version.isPresent()) {
            System.out.println(format(tr("Invalid version {0}"), libraryToInstallParts[1]));
            System.exit(1);
          }
          selected = indexer.getIndex().find(libraryToInstallParts[0], version.get().toString());
        } else if (libraryToInstallParts.length == 1) {
          List<ContributedLibrary> librariesByName = indexer.getIndex().find(libraryToInstallParts[0]);
          Collections.sort(librariesByName, new DownloadableContributionVersionComparator());
          if (!librariesByName.isEmpty()) {
            selected = librariesByName.get(librariesByName.size() - 1);
          }
        }
        if (selected == null) {
          System.out.println(tr("Selected library is not available"));
          System.exit(1);
        }

        Optional<ContributedLibrary> mayInstalled = indexer.getIndex().getInstalled(libraryToInstallParts[0]);
        if (mayInstalled.isPresent() && selected.isIDEBuiltIn()) {
          System.out.println(tr(I18n
              .format("Library {0} is available as built-in in the IDE.\nRemoving the other version {1} installed in the sketchbook...",
                      library, mayInstalled.get().getParsedVersion())));
          libraryInstaller.remove(mayInstalled.get(), progressListener);
        } else {
          libraryInstaller.install(selected, progressListener);
        }
      }

      System.exit(0);

    } else if (parser.isVerifyOrUploadMode()) {
      // Set verbosity for command line build
      PreferencesData.setBoolean("build.verbose", parser.isDoVerboseBuild());
      PreferencesData.setBoolean("upload.verbose", parser.isDoVerboseUpload());

      // Set preserve-temp flag
      PreferencesData.setBoolean("runtime.preserve.temp.files", parser.isPreserveTempFiles());

      // Make sure these verbosity preferences are only for the current session
      PreferencesData.setDoSave(false);

      Sketch sketch = null;
      String outputFile = null;

      try {
        // Build
        splash.splashText(tr("Verifying..."));

        File sketchFile = BaseNoGui.absoluteFile(parser.getFilenames().get(0));
        sketch = new Sketch(sketchFile);

        outputFile = new Compiler(sketch).build(progress -> {}, false);
      } catch (Exception e) {
        // Error during build
        e.printStackTrace();
        System.exit(1);
      }

      if (parser.isUploadMode()) {
        // Upload
        splash.splashText(tr("Uploading..."));

        try {
          List<String> warnings = new ArrayList<>();
          UploaderUtils uploader = new UploaderUtils();
          boolean res = uploader.upload(sketch, null, outputFile,
                                        parser.isDoUseProgrammer(),
                                        parser.isNoUploadPort(), warnings);
          for (String warning : warnings) {
            System.out.println(tr("Warning") + ": " + warning);
          }
          if (!res) {
            throw new Exception();
          }
        } catch (Exception e) {
          // Error during upload
          System.out.flush();
          System.err.flush();
          System.err
              .println(tr("An error occurred while uploading the sketch"));
          System.exit(1);
        }
      }

      // No errors exit gracefully
      System.exit(0);
    } else if (parser.isGuiMode()) {
      splash.splashText(tr("Starting..."));

      for (String path : parser.getFilenames()) {
        // Correctly resolve relative paths
        File file = absoluteFile(path);

        // Fix a problem with systems that use a non-ASCII languages. Paths are
        // being passed in with 8.3 syntax, which makes the sketch loader code
        // unhappy, since the sketch folder naming doesn't match up correctly.
        // http://dev.processing.org/bugs/show_bug.cgi?id=1089
        if (OSUtils.isWindows()) {
          try {
            file = file.getCanonicalFile();
          } catch (IOException e) {
            e.printStackTrace();
          }
        }

        if (!parser.isForceSavePrefs())
          PreferencesData.setDoSave(true);
        if (handleOpen(file, retrieveSketchLocation(".default"), false) == null) {
          String mess = format(tr("Failed to open sketch: \"{0}\""), path);
          // Open failure is fatal in upload/verify mode
          if (parser.isVerifyOrUploadMode())
            showError(null, mess, 2);
          else
            showWarning(null, mess, null);
        }
      }

      installKeyboardInputMap();

      // Check if there were previously opened sketches to be restored
      restoreSketches();

      // Create a new empty window (will be replaced with any files to be opened)
      if (editors.isEmpty()) {
        handleNew();
      }

      new Thread(new BuiltInCoreIsNewerCheck(this)).start();

      // Check for boards which need an additional core
      new Thread(new NewBoardListener(this)).start();

      // Check for updates
      if (PreferencesData.getBoolean("update.check")) {
        new UpdateCheck(this);

        contributionsSelfCheck = new ContributionsSelfCheck(this, new UpdatableBoardsLibsFakeURLsHandler(this), contributionInstaller, libraryInstaller);
        new Timer(false).schedule(contributionsSelfCheck, Constants.BOARDS_LIBS_UPDATABLE_CHECK_START_PERIOD);
      }

    } else if (parser.isNoOpMode()) {
      // Do nothing (intended for only changing preferences)
      System.exit(0);
    } else if (parser.isGetPrefMode()) {
      BaseNoGui.dumpPrefs(parser);
    } else if (parser.isVersionMode()) {
      System.out.println("Arduino: " + BaseNoGui.VERSION_NAME_LONG);
      System.exit(0);
    }
  }

  private void installKeyboardInputMap() {
    UIManager.put("RSyntaxTextAreaUI.inputMap", new SketchTextAreaDefaultInputMap());
  }

  /**
   * Post-constructor setup for the editor area. Loads the last
   * sketch that was used (if any), and restores other Editor settings.
   * The complement to "storePreferences", this is called when the
   * application is first launched.
   *
   * @throws Exception
   */
  protected boolean restoreSketches() throws Exception {
    // Iterate through all sketches that were open last time p5 was running.
    // If !windowPositionValid, then ignore the coordinates found for each.

    // Save the sketch path and window placement for each open sketch
    int count = PreferencesData.getInteger("last.sketch.count");
    int opened = 0;
    for (int i = count - 1; i >= 0; i--) {
      String path = PreferencesData.get("last.sketch" + i + ".path");
      if (path == null) {
        continue;
      }
      if (BaseNoGui.getPortableFolder() != null && !new File(path).isAbsolute()) {
        File absolute = new File(BaseNoGui.getPortableFolder(), path);
        try {
          path = absolute.getCanonicalPath();
        } catch (IOException e) {
          // path unchanged.
        }
      }
      int[] location = retrieveSketchLocation("" + i);
      // If file did not exist, null will be returned for the Editor
      if (handleOpen(new File(path), location, nextEditorLocation(), false, false) != null) {
        opened++;
      }
    }
    return (opened > 0);
  }

  /**
   * Store screen dimensions on last close
   */
  protected void storeScreenDimensions() {
    // Save the width and height of the screen
    Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
    PreferencesData.setInteger("last.screen.width", screen.width);
    PreferencesData.setInteger("last.screen.height", screen.height);
  }

  /**
   * Store list of sketches that are currently open.
   * Called when the application is quitting and documents are still open.
   */
  protected void storeSketches() {

    // If there is only one sketch opened save his position as default
    if (editors.size() == 1) {
      storeSketchLocation(editors.get(0), ".default");
    }

    // Save the sketch path and window placement for each open sketch
    String untitledPath = untitledFolder.getAbsolutePath();
    List<Editor> reversedEditors = new LinkedList<>(editors);
    Collections.reverse(reversedEditors);
    int index = 0;
    for (Editor editor : reversedEditors) {
      Sketch sketch = editor.getSketch();
      String path = sketch.getMainFilePath();
      // Skip untitled sketches if they do not contains changes.
      if (path.startsWith(untitledPath) && !sketch.isModified()) {
        continue;
      }
      storeSketchLocation(editor, "" + index);
      index++;
    }
    PreferencesData.setInteger("last.sketch.count", index);
  }

  private void storeSketchLocation(Editor editor, String index) {
    String path = editor.getSketch().getMainFilePath();
    String loc = StringUtils.join(editor.getPlacement(), ',');
    PreferencesData.set("last.sketch" + index + ".path", path);
    PreferencesData.set("last.sketch" + index + ".location", loc);
  }

  private int[] retrieveSketchLocation(String index) {
    if (PreferencesData.get("last.screen.height") == null)
      return defaultEditorLocation();

    // if screen size has changed, the window coordinates no longer
    // make sense, so don't use them unless they're identical
    Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
    int screenW = PreferencesData.getInteger("last.screen.width");
    int screenH = PreferencesData.getInteger("last.screen.height");

    if ((screen.width != screenW) || (screen.height != screenH))
      return defaultEditorLocation();

    String locationStr = PreferencesData
        .get("last.sketch" + index + ".location");
    if (locationStr == null)
      return defaultEditorLocation();
    return PApplet.parseInt(PApplet.split(locationStr, ','));
  }

  protected void storeRecentSketches(SketchController sketch) {
    if (sketch.isUntitled()) {
      return;
    }

    Set<String> sketches = new LinkedHashSet<>();
    sketches.add(sketch.getSketch().getMainFilePath());
    sketches.addAll(PreferencesData.getCollection("recent.sketches"));

    PreferencesData.setCollection("recent.sketches", sketches);
  }

  protected void removeRecentSketchPath(String path) {
    Collection<String> sketches = new LinkedList<>(PreferencesData.getCollection("recent.sketches"));
    sketches.remove(path);
    PreferencesData.setCollection("recent.sketches", sketches);
  }

  // Because of variations in native windowing systems, no guarantees about
  // changes to the focused and active Windows can be made. Developers must
  // never assume that this Window is the focused or active Window until this
  // Window receives a WINDOW_GAINED_FOCUS or WINDOW_ACTIVATED event.
  protected void handleActivated(Editor whichEditor) {
    activeEditor = whichEditor;
    activeEditor.rebuildRecentSketchesMenu();
    if (PreferencesData.getBoolean("editor.external")) {
      try {
        // If the list of files on disk changed, recreate the tabs for them
        if (activeEditor.getSketch().reload())
          activeEditor.createTabs();
        else // Let the current tab know it was activated, so it can reload
          activeEditor.getCurrentTab().activated();
      } catch (IOException e) {
        System.err.println(e);
      }
    }
  }

  protected int[] defaultEditorLocation() {
    int defaultWidth = PreferencesData.getInteger("editor.window.width.default");
    int defaultHeight = PreferencesData.getInteger("editor.window.height.default");
    Rectangle screen = GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice().getDefaultConfiguration().getBounds();
    return new int[]{
            (screen.width - defaultWidth) / 2,
            (screen.height - defaultHeight) / 2,
            defaultWidth, defaultHeight, 0
    };
  }

  protected int[] nextEditorLocation() {
    if (activeEditor == null) {
      // If no current active editor, use default placement
      return defaultEditorLocation();
    }

    Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();

    // With a currently active editor, open the new window
    // using the same dimensions, but offset slightly.
    synchronized (editors) {
      int[] location = activeEditor.getPlacement();

      // Just in case the bounds for that window are bad
      final int OVER = 50;
      location[0] += OVER;
      location[1] += OVER;

      if (location[0] == OVER || location[2] == OVER
          || location[0] + location[2] > screen.width
          || location[1] + location[3] > screen.height) {
        // Warp the next window to a randomish location on screen.
        int[] l = defaultEditorLocation();
        l[0] *= Math.random() * 2;
        l[1] *= Math.random() * 2;
        return l;
      }

      return location;
    }
  }


  // .................................................................


  boolean breakTime = false;
  String[] months = {
          "jan", "feb", "mar", "apr", "may", "jun",
          "jul", "aug", "sep", "oct", "nov", "dec"
  };

  protected File createNewUntitled() throws IOException {
    File newbieDir = null;
    String newbieName = null;

    // In 0126, untitled sketches will begin in the temp folder,
    // and then moved to a new location because Save will default to Save As.
    File sketchbookDir = BaseNoGui.getSketchbookFolder();
    File newbieParentDir = untitledFolder;

    // Use a generic name like sketch_031008a, the date plus a char
    int index = 0;
    //SimpleDateFormat formatter = new SimpleDateFormat("yyMMdd");
    //SimpleDateFormat formatter = new SimpleDateFormat("MMMdd");
    //String purty = formatter.format(new Date()).toLowerCase();
    Calendar cal = Calendar.getInstance();
    int day = cal.get(Calendar.DAY_OF_MONTH);  // 1..31
    int month = cal.get(Calendar.MONTH);  // 0..11
    String purty = months[month] + PApplet.nf(day, 2);

    do {
      if (index == 26*26) {
        // In 0166, avoid running past zz by sending people outdoors.
        if (!breakTime) {
          showWarning(tr("Time for a Break"),
                  tr("You've reached the limit for auto naming of new sketches\n" +
                          "for the day. How about going for a walk instead?"), null);
          breakTime = true;
        } else {
          showWarning(tr("Sunshine"),
                  tr("No really, time for some fresh air for you."), null);
        }
        return null;
      }

      int multiples = index / 26;

      if(multiples > 0){
        newbieName = ((char) ('a' + (multiples-1))) + "" + ((char) ('a' + (index % 26))) + "";
      }else{
        newbieName = ((char) ('a' + index)) + "";
      }
      newbieName = "sketch_" + purty + newbieName;
      newbieDir = new File(newbieParentDir, newbieName);
      index++;
      // Make sure it's not in the temp folder *and* it's not in the sketchbook
    } while (newbieDir.exists() || new File(sketchbookDir, newbieName).exists());

    // Make the directory for the new sketch
    newbieDir.mkdirs();

    // Make an empty pde file
    File newbieFile = new File(newbieDir, newbieName + ".ino");
    if (!newbieFile.createNewFile()) {
      throw new IOException();
    }

    // Initialize the pde file with the BareMinimum sketch.
    // Apply user-defined tab settings.
    String sketch = FileUtils.readFileToString(
        new File(getContentFile("examples"), "01.Basics" + File.separator
            + "BareMinimum" + File.separator + "BareMinimum.ino"));
    String currentTab = "  ";
    String newTab = (PreferencesData.getBoolean("editor.tabs.expand")
        ? StringUtils.repeat(" ",
            PreferencesData.getInteger("editor.tabs.size"))
        : "\t");
    sketch = sketch.replaceAll(
        "(?<=(^|\n)(" + currentTab + "){0,50})" + currentTab, newTab);
    FileUtils.writeStringToFile(newbieFile, sketch);
    return newbieFile;
  }


  /**
   * Create a new untitled document in a new sketch window.
   *
   * @throws Exception
   */
  public void handleNew() throws Exception {
    try {
      File file = createNewUntitled();
      if (file != null) {
        handleOpen(file, true);
      }

    } catch (IOException e) {
      if (activeEditor != null) {
        activeEditor.statusError(e);
      }
    }
  }


  /**
   * Prompt for a sketch to open, and open it in a new window.
   *
   * @throws Exception
   */
  public void handleOpenPrompt() throws Exception {
    // get the frontmost window frame for placing file dialog
    FileDialog fd = new FileDialog(activeEditor, tr("Open an Arduino sketch..."), FileDialog.LOAD);
    File lastFolder = new File(PreferencesData.get("last.folder", BaseNoGui.getSketchbookFolder().getAbsolutePath()));
    if (lastFolder.exists() && lastFolder.isFile()) {
      lastFolder = lastFolder.getParentFile();
    }
    fd.setDirectory(lastFolder.getAbsolutePath());

    // Only show .pde files as eligible bachelors
    fd.setFilenameFilter(new FilenameFilter() {
      public boolean accept(File dir, String name) {
        return name.toLowerCase().endsWith(".ino")
                || name.toLowerCase().endsWith(".pde");
      }
    });

    fd.setVisible(true);

    String directory = fd.getDirectory();
    String filename = fd.getFile();

    // User canceled selection
    if (filename == null) return;

    File inputFile = new File(directory, filename);

    PreferencesData.set("last.folder", inputFile.getAbsolutePath());
    handleOpen(inputFile);
  }


  /**
   * Open a sketch in a new window.
   *
   * @param file File to open
   * @return the Editor object, so that properties (like 'untitled')
   * can be set by the caller
   * @throws Exception
   */
  public Editor handleOpen(File file) throws Exception {
    return handleOpen(file, false);
  }

  public Editor handleOpen(File file, boolean untitled) throws Exception {
    return handleOpen(file, nextEditorLocation(), untitled);
  }

  protected Editor handleOpen(File file, int[] location, boolean untitled) throws Exception {
    return handleOpen(file, location, location, true, untitled);
  }

  protected Editor handleOpen(File file, int[] storedLocation, int[] defaultLocation, boolean storeOpenedSketches, boolean untitled) throws Exception {
    if (!file.exists()) return null;

    // Cycle through open windows to make sure that it's not already open.
    for (Editor editor : editors) {
      if (editor.getSketch().getPrimaryFile().getFile().equals(file)) {
        editor.toFront();
        return editor;
      }
    }

    Editor editor = new Editor(this, file, storedLocation, defaultLocation, BaseNoGui.getPlatform());

    // Make sure that the sketch actually loaded
    if (editor.getSketchController() == null) {
      return null;  // Just walk away quietly
    }

    editor.untitled = untitled;

    editors.add(editor);

    if (storeOpenedSketches) {
      // Store information on who's open and running
      // (in case there's a crash or something that can't be recovered)
      storeSketches();
      storeRecentSketches(editor.getSketchController());
      rebuildRecentSketchesMenuItems();
      PreferencesData.save();
    }

    // now that we're ready, show the window
    // (don't do earlier, cuz we might move it based on a window being closed)
    SwingUtilities.invokeLater(() -> editor.setVisible(true));

    return editor;
  }

  protected void rebuildRecentSketchesMenuItems() {
    Set<File> recentSketches = new LinkedHashSet<File>() {

      @Override
      public boolean add(File file) {
        if (size() >= RECENT_SKETCHES_MAX_SIZE) {
          return false;
        }
        return super.add(file);
      }
    };

    for (String path : PreferencesData.getCollection("recent.sketches")) {
      File file = new File(path);
      if (file.exists()) {
        recentSketches.add(file);
      }
    }

    recentSketchesMenuItems.clear();
    for (final File recentSketch : recentSketches) {
      JMenuItem recentSketchMenuItem = new JMenuItem(recentSketch.getParentFile().getName());
      recentSketchMenuItem.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent actionEvent) {
          try {
            handleOpen(recentSketch);
          } catch (Exception e) {
            e.printStackTrace();
          }
        }
      });
      recentSketchesMenuItems.add(recentSketchMenuItem);
    }
  }


  /**
   * Close a sketch as specified by its editor window.
   *
   * @param editor Editor object of the sketch to be closed.
   * @return true if succeeded in closing, false if canceled.
   */
  public boolean handleClose(Editor editor) {

    if (editors.size() == 1) {
      if (!handleQuit()) {
        return false;
      }
      // Everything called after handleQuit will only affect OSX
      editor.setVisible(false);
      editors.remove(editor);
    } else {
      // More than one editor window open,
      // proceed with closing the current window.
      // Check if modified
      if (!editor.checkModified()) {
        return false;
      }
      editor.setVisible(false);
      editor.dispose();
      editors.remove(editor);
    }
    return true;
  }


  /**
   * Handler for File &rarr; Quit.
   *
   * @return false if canceled, true otherwise.
   */
  public boolean handleQuit() {
    // If quit is canceled, this will be replaced anyway
    // by a later handleQuit() that is not canceled.
    storeScreenDimensions();
    storeSketches();
    try {
      Editor.serialMonitor.close();
    } catch (Exception e) {
      // ignore
    }

    // kill uploader (if still alive)
    UploaderUtils uploaderInstance = new UploaderUtils();
    Uploader uploader = uploaderInstance.getUploaderByPreferences(false);
    if (uploader != null && uploader.programmerPid != null && uploader.programmerPid.isAlive()) {
        // kill the stuck programmer
        uploader.programmerPid.destroyForcibly();
    }

    if (handleQuitEach()) {
      // Save out the current prefs state
      PreferencesData.save();

      if (!OSUtils.isMacOS()) {
        // If this was fired from the menu or an AppleEvent (the Finder),
        // then Mac OS X will send the terminate signal itself.
        System.exit(0);
      }
      return true;
    }
    return false;
  }


  /**
   * Attempt to close each open sketch in preparation for quitting.
   *
   * @return false if canceled along the way
   */
  protected boolean handleQuitEach() {
    for (Editor editor : editors) {
      if (!editor.checkModified()) {
        return false;
      }
    }
    return true;
  }


  // .................................................................


  /**
   * Asynchronous version of menu rebuild to be used on save and rename
   * to prevent the interface from locking up until the menus are done.
   */
  public void rebuildSketchbookMenus() {
    //System.out.println("async enter");
    //new Exception().printStackTrace();
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        //System.out.println("starting rebuild");
        rebuildSketchbookMenu(Editor.sketchbookMenu);
        rebuildToolbarMenu(Editor.toolbarMenu);
        //System.out.println("done with rebuild");
      }
    });
    //System.out.println("async exit");
  }


  protected void rebuildToolbarMenu(JMenu menu) {
    JMenuItem item;
    menu.removeAll();

    // Add the single "Open" item
    item = Editor.newJMenuItem(tr("Open..."), 'O');
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        try {
          handleOpenPrompt();
        } catch (Exception e1) {
          e1.printStackTrace();
        }
      }
    });
    menu.add(item);
    menu.addSeparator();

    // Add a list of all sketches and subfolders
    boolean sketches = addSketches(menu, BaseNoGui.getSketchbookFolder());
    if (sketches) menu.addSeparator();

    // Add each of the subfolders of examples directly to the menu
    boolean found = addSketches(menu, BaseNoGui.getExamplesFolder());
    if (found) menu.addSeparator();
  }


  protected void rebuildSketchbookMenu(JMenu menu) {
    menu.removeAll();
    addSketches(menu, BaseNoGui.getSketchbookFolder());

    JMenu librariesMenu = JMenuUtils.findSubMenuWithLabel(menu, "libraries");
    if (librariesMenu != null) {
      menu.remove(librariesMenu);
    }
    JMenu hardwareMenu = JMenuUtils.findSubMenuWithLabel(menu, "hardware");
    if (hardwareMenu != null) {
      menu.remove(hardwareMenu);
    }
  }

  private LibraryList getSortedLibraries() {
    LibraryList installedLibraries = BaseNoGui.librariesIndexer.getInstalledLibraries();
    Collections.sort(installedLibraries, new LibraryOfSameTypeComparator());
    return installedLibraries;
  }

  public void rebuildImportMenu(JMenu importMenu) {
    if (importMenu == null)
      return;
    importMenu.removeAll();

    JMenuItem menu = new JMenuItem(tr("Manage Libraries..."));
    // Ctrl+Shift+I on Windows and Linux, Command+Shift+I on macOS
    menu.setAccelerator(KeyStroke.getKeyStroke('I',
        Toolkit.getDefaultToolkit().getMenuShortcutKeyMask() |
        ActionEvent.SHIFT_MASK));
    menu.addActionListener(e -> openLibraryManager("", ""));
    importMenu.add(menu);
    importMenu.addSeparator();

    JMenuItem addLibraryMenuItem = new JMenuItem(tr("Add .ZIP Library..."));
    addLibraryMenuItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.this.handleAddLibrary();
        BaseNoGui.librariesIndexer.rescanLibraries();
        Base.this.onBoardOrPortChange();
        Base.this.rebuildImportMenu(Editor.importMenu);
        Base.this.rebuildExamplesMenu(Editor.examplesMenu);
      }
    });
    importMenu.add(addLibraryMenuItem);
    importMenu.addSeparator();

    // Split between user supplied libraries and IDE libraries
    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform();

    if (targetPlatform != null) {
      LibraryList libs = getSortedLibraries();
      String lastLibType = null;
      for (UserLibrary lib : libs) {
        String libType = lib.getTypes().get(0);
        if (!libType.equals(lastLibType)) {
          if (lastLibType != null) {
            importMenu.addSeparator();
          }
          lastLibType = libType;
          JMenuItem platformItem = new JMenuItem(format(tr("{0} libraries"), tr(lastLibType)));
          platformItem.setEnabled(false);
          importMenu.add(platformItem);
        }

        AbstractAction action = new AbstractAction(lib.getName()) {
          public void actionPerformed(ActionEvent event) {
            UserLibrary l = (UserLibrary) getValue("library");
            try {
              activeEditor.getSketchController().importLibrary(l);
            } catch (IOException e) {
              showWarning(tr("Error"), format("Unable to list header files in {0}", l.getSrcFolder()), e);
            }
          }
        };
        action.putValue("library", lib);

        // Add new element at the bottom
        JMenuItem item = new JMenuItem(action);
        item.putClientProperty("library", lib);
        importMenu.add(item);
      }
    }
  }

  public void rebuildExamplesMenu(JMenu menu) {
    if (menu == null) {
      return;
    }

    menu.removeAll();

    // Add examples from distribution "example" folder
    JMenuItem label = new JMenuItem(tr("Built-in Examples"));
    label.setEnabled(false);
    menu.add(label);
    boolean found = addSketches(menu, BaseNoGui.getExamplesFolder());
    if (found) {
      menu.addSeparator();
    }

    // Libraries can come from 4 locations: collect info about all four
    String boardId = null;
    String referencedPlatformName = null;
    String myArch = null;
    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform();
    if (targetPlatform != null) {
      myArch = targetPlatform.getId();
      boardId = BaseNoGui.getTargetBoard().getName();
      String core = BaseNoGui.getBoardPreferences().get("build.core", "arduino");
      if (core.contains(":")) {
        String refcore = core.split(":")[0];
        TargetPlatform referencedPlatform = BaseNoGui.getTargetPlatform(refcore, myArch);
        if (referencedPlatform != null) {
          referencedPlatformName = referencedPlatform.getPreferences().get("name");
        }
      }
    }

    // Divide the libraries into 7 lists, corresponding to the 4 locations
    // with the retired IDE libs further divided into their own list, and
    // any incompatible sketchbook libs further divided into their own list.
    // The 7th list of "other" libraries should always be empty, but serves
    // as a safety feature to prevent any library from vanishing.
    LibraryList allLibraries = BaseNoGui.librariesIndexer.getInstalledLibraries();
    LibraryList ideLibs = new LibraryList();
    LibraryList retiredIdeLibs = new LibraryList();
    LibraryList platformLibs = new LibraryList();
    LibraryList referencedPlatformLibs = new LibraryList();
    LibraryList sketchbookLibs = new LibraryList();
    LibraryList sketchbookIncompatibleLibs = new LibraryList();
    LibraryList otherLibs = new LibraryList();
    for (UserLibrary lib : allLibraries) {
      // Get the library's location - used for sorting into categories
      Location location = lib.getLocation();
      // Is this library compatible?
      List<String> arch = lib.getArchitectures();
      boolean compatible;
      if (myArch == null || arch == null || arch.contains("*")) {
        compatible = true;
      } else {
        compatible = arch.contains(myArch);
      }
      // IDE Libaries (including retired)
      if (location == Location.IDE_BUILTIN) {
        if (compatible) {
          // only compatible IDE libs are shown
          if (lib.getTypes().contains("Retired")) {
            retiredIdeLibs.add(lib);
          } else {
            ideLibs.add(lib);
          }
        }
      // Platform Libraries
      } else if (location == Location.CORE) {
        // all platform libs are assumed to be compatible
        platformLibs.add(lib);
      // Referenced Platform Libraries
      } else if (location == Location.REFERENCED_CORE) {
        // all referenced platform libs are assumed to be compatible
        referencedPlatformLibs.add(lib);
      // Sketchbook Libraries (including incompatible)
      } else if (location == Location.SKETCHBOOK) {
        if (compatible) {
          // libraries promoted from sketchbook (behave as builtin)
          if (!lib.getTypes().isEmpty() && lib.getTypes().contains("Arduino")
              && lib.getArchitectures().contains("*")) {
            ideLibs.add(lib);
          } else {
            sketchbookLibs.add(lib);
          }
        } else {
          sketchbookIncompatibleLibs.add(lib);
        }
      // Other libraries of unknown type (should never occur)
      } else {
        otherLibs.add(lib);
      }
    }

    // Add examples from libraries
    if (!ideLibs.isEmpty()) {
      ideLibs.sort();
      label = new JMenuItem(tr("Examples for any board"));
      label.setEnabled(false);
      menu.add(label);
    }
    for (UserLibrary lib : ideLibs) {
      addSketchesSubmenu(menu, lib);
    }

    if (!retiredIdeLibs.isEmpty()) {
      retiredIdeLibs.sort();
      JMenu retired = new JMenu(tr("RETIRED"));
      menu.add(retired);
      for (UserLibrary lib : retiredIdeLibs) {
        addSketchesSubmenu(retired, lib);
      }
    }

    if (!platformLibs.isEmpty()) {
      menu.addSeparator();
      platformLibs.sort();
      label = new JMenuItem(format(tr("Examples for {0}"), boardId));
      label.setEnabled(false);
      menu.add(label);
      for (UserLibrary lib : platformLibs) {
        addSketchesSubmenu(menu, lib);
      }
    }

    if (!referencedPlatformLibs.isEmpty()) {
      menu.addSeparator();
      referencedPlatformLibs.sort();
      label = new JMenuItem(format(tr("Examples for {0}"), referencedPlatformName));
      label.setEnabled(false);
      menu.add(label);
      for (UserLibrary lib : referencedPlatformLibs) {
        addSketchesSubmenu(menu, lib);
      }
    }

    if (!sketchbookLibs.isEmpty()) {
      menu.addSeparator();
      sketchbookLibs.sort();
      label = new JMenuItem(tr("Examples from Custom Libraries"));
      label.setEnabled(false);
      menu.add(label);
      for (UserLibrary lib : sketchbookLibs) {
        addSketchesSubmenu(menu, lib);
      }
    }

    if (!sketchbookIncompatibleLibs.isEmpty()) {
      sketchbookIncompatibleLibs.sort();
      JMenu incompatible = new JMenu(tr("INCOMPATIBLE"));
      MenuScroller.setScrollerFor(incompatible);
      menu.add(incompatible);
      for (UserLibrary lib : sketchbookIncompatibleLibs) {
        addSketchesSubmenu(incompatible, lib);
      }
    }

    if (!otherLibs.isEmpty()) {
      menu.addSeparator();
      otherLibs.sort();
      label = new JMenuItem(tr("Examples from Other Libraries"));
      label.setEnabled(false);
      menu.add(label);
      for (UserLibrary lib : otherLibs) {
        addSketchesSubmenu(menu, lib);
      }
    }
  }

  private static String priorPlatformFolder;
  private static boolean newLibraryImported;

  public void onBoardOrPortChange() {
    BaseNoGui.onBoardOrPortChange();

    // reload keywords when package/platform changes
    TargetPlatform tp = BaseNoGui.getTargetPlatform();
    if (tp != null) {
      String platformFolder = tp.getFolder().getAbsolutePath();
      if (priorPlatformFolder == null || !priorPlatformFolder.equals(platformFolder) || newLibraryImported) {
        pdeKeywords = new PdeKeywords();
        pdeKeywords.reload();
        priorPlatformFolder = platformFolder;
        newLibraryImported = false;
        for (Editor editor : editors) {
          editor.updateKeywords(pdeKeywords);
        }
      }
    }

    // Update editors status bar
    for (Editor editor : editors) {
      editor.onBoardOrPortChange();
    }
  }

  public void openLibraryManager(final String filterText, String dropdownItem) {
    if (contributionsSelfCheck != null) {
      contributionsSelfCheck.cancel();
    }
    @SuppressWarnings("serial")
    LibraryManagerUI managerUI = new LibraryManagerUI(activeEditor, libraryInstaller) {
      @Override
      protected void onIndexesUpdated() throws Exception {
        BaseNoGui.initPackages();
        rebuildBoardsMenu();
        rebuildProgrammerMenu();
        onBoardOrPortChange();
        updateUI();
        if (StringUtils.isNotEmpty(dropdownItem)) {
          selectDropdownItemByClassName(dropdownItem);
        }
        if (StringUtils.isNotEmpty(filterText)) {
          setFilterText(filterText);
        }
      }
    };
    managerUI.setLocationRelativeTo(activeEditor);
    managerUI.updateUI();
    managerUI.setVisible(true);
    // Manager dialog is modal, waits here until closed

    //handleAddLibrary();
    newLibraryImported = true;
    onBoardOrPortChange();
    rebuildImportMenu(Editor.importMenu);
    rebuildExamplesMenu(Editor.examplesMenu);
  }

  public void openBoardsManager(final String filterText, String dropdownItem) throws Exception {
    if (contributionsSelfCheck != null) {
      contributionsSelfCheck.cancel();
    }
    @SuppressWarnings("serial")
    ContributionManagerUI managerUI = new ContributionManagerUI(activeEditor, contributionInstaller) {
      @Override
      protected void onIndexesUpdated() throws Exception {
        BaseNoGui.initPackages();
        rebuildBoardsMenu();
        rebuildProgrammerMenu();
        updateUI();
        if (StringUtils.isNotEmpty(dropdownItem)) {
          selectDropdownItemByClassName(dropdownItem);
        }
        if (StringUtils.isNotEmpty(filterText)) {
          setFilterText(filterText);
        }
      }
    };
    managerUI.setLocationRelativeTo(activeEditor);
    managerUI.updateUI();
    managerUI.setVisible(true);
    // Installer dialog is modal, waits here until closed

    // Reload all boards (that may have been installed/updated/removed)
    BaseNoGui.initPackages();
    rebuildBoardsMenu();
    rebuildProgrammerMenu();
    onBoardOrPortChange();
  }

  public void rebuildBoardsMenu() throws Exception {
    boardsCustomMenus = new LinkedList<>();

    // The first custom menu is the "Board" selection submenu
    JMenu boardMenu = new JMenu(tr("Board"));
    boardMenu.putClientProperty("removeOnWindowDeactivation", true);
    MenuScroller.setScrollerFor(boardMenu).setTopFixedCount(1);

    boardMenu.add(new JMenuItem(new AbstractAction(tr("Boards Manager...")) {
      public void actionPerformed(ActionEvent actionevent) {
        String filterText = "";
        String dropdownItem = "";
        if (actionevent instanceof Event) {
          filterText = ((Event) actionevent).getPayload().get("filterText").toString();
          dropdownItem = ((Event) actionevent).getPayload().get("dropdownItem").toString();
        }
        try {
          openBoardsManager(filterText, dropdownItem);
        } catch (Exception e) {
          //TODO show error
          e.printStackTrace();
        }
      }
    }));
    boardsCustomMenus.add(boardMenu);

    // If there are no platforms installed we are done
    if (BaseNoGui.packages.size() == 0)
      return;

    // Separate "Install boards..." command from installed boards
    boardMenu.add(new JSeparator());

    // Generate custom menus for all platforms
    for (TargetPackage targetPackage : BaseNoGui.packages.values()) {
      for (TargetPlatform targetPlatform : targetPackage.platforms()) {
        for (String customMenuTitle : targetPlatform.getCustomMenus().values()) {
          JMenu customMenu = new JMenu(tr(customMenuTitle));
          customMenu.putClientProperty("platform", getPlatformUniqueId(targetPlatform));
          customMenu.putClientProperty("removeOnWindowDeactivation", true);
          boardsCustomMenus.add(customMenu);
        }
      }
    }

    List<JMenuItem> menuItemsToClickAfterStartup = new LinkedList<>();

    ButtonGroup boardsButtonGroup = new ButtonGroup();
    Map<String, ButtonGroup> buttonGroupsMap = new HashMap<>();

    // Cycle through all packages
    boolean first = true;
    for (TargetPackage targetPackage : BaseNoGui.packages.values()) {
      // For every package cycle through all platform
      for (TargetPlatform targetPlatform : targetPackage.platforms()) {

        // Add a separator from the previous platform
        if (!first)
          boardMenu.add(new JSeparator());
        first = false;

        // Add a title for each platform
        String platformLabel = targetPlatform.getPreferences().get("name");
        if (platformLabel != null && !targetPlatform.getBoards().isEmpty()) {
          JMenuItem menuLabel = new JMenuItem(tr(platformLabel));
          menuLabel.setEnabled(false);
          boardMenu.add(menuLabel);
        }

        // Cycle through all boards of this platform
        for (TargetBoard board : targetPlatform.getBoards().values()) {
          if (board.getPreferences().get("hide") != null)
            continue;
          JMenuItem item = createBoardMenusAndCustomMenus(boardsCustomMenus, menuItemsToClickAfterStartup,
                  buttonGroupsMap,
                  board, targetPlatform, targetPackage);
          boardMenu.add(item);
          boardsButtonGroup.add(item);
        }
      }
    }

    if (menuItemsToClickAfterStartup.isEmpty()) {
      menuItemsToClickAfterStartup.add(selectFirstEnabledMenuItem(boardMenu));
    }

    for (JMenuItem menuItemToClick : menuItemsToClickAfterStartup) {
      menuItemToClick.setSelected(true);
      menuItemToClick.getAction().actionPerformed(new ActionEvent(this, -1, ""));
    }
  }

  private String getPlatformUniqueId(TargetPlatform platform) {
    return platform.getId() + "_" + platform.getFolder();
  }

  private JRadioButtonMenuItem createBoardMenusAndCustomMenus(
          final List<JMenu> boardsCustomMenus, List<JMenuItem> menuItemsToClickAfterStartup,
          Map<String, ButtonGroup> buttonGroupsMap,
          TargetBoard board, TargetPlatform targetPlatform, TargetPackage targetPackage)
          throws Exception {
    String selPackage = PreferencesData.get("target_package");
    String selPlatform = PreferencesData.get("target_platform");
    String selBoard = PreferencesData.get("board");

    String boardId = board.getId();
    String packageName = targetPackage.getId();
    String platformName = targetPlatform.getId();

    // Setup a menu item for the current board
    @SuppressWarnings("serial")
    Action action = new AbstractAction(board.getName()) {
      public void actionPerformed(ActionEvent actionevent) {
        BaseNoGui.selectBoard((TargetBoard) getValue("b"));
        filterVisibilityOfSubsequentBoardMenus(boardsCustomMenus, (TargetBoard) getValue("b"), 1);

        onBoardOrPortChange();
        rebuildImportMenu(Editor.importMenu);
        rebuildExamplesMenu(Editor.examplesMenu);
      }
    };
    action.putValue("b", board);

    JRadioButtonMenuItem item = new JRadioButtonMenuItem(action);

    if (selBoard.equals(boardId) && selPackage.equals(packageName)
            && selPlatform.equals(platformName)) {
      menuItemsToClickAfterStartup.add(item);
    }

    PreferencesMap customMenus = targetPlatform.getCustomMenus();
    for (final String menuId : customMenus.keySet()) {
      String title = customMenus.get(menuId);
      JMenu menu = getBoardCustomMenu(tr(title), getPlatformUniqueId(targetPlatform));

      if (board.hasMenu(menuId)) {
        PreferencesMap boardCustomMenu = board.getMenuLabels(menuId);
        for (String customMenuOption : boardCustomMenu.keySet()) {
          @SuppressWarnings("serial")
          Action subAction = new AbstractAction(tr(boardCustomMenu.get(customMenuOption))) {
            public void actionPerformed(ActionEvent e) {
              PreferencesData.set("custom_" + menuId, ((List<TargetBoard>) getValue("board")).get(0).getId() + "_" + getValue("custom_menu_option"));
              onBoardOrPortChange();
            }
          };
          List<TargetBoard> boards = (List<TargetBoard>) subAction.getValue("board");
          if (boards == null) {
            boards = new ArrayList<TargetBoard>();
          }
          boards.add(board);
          subAction.putValue("board", boards);
          subAction.putValue("custom_menu_option", customMenuOption);

          if (!buttonGroupsMap.containsKey(menuId)) {
            buttonGroupsMap.put(menuId, new ButtonGroup());
          }

          JRadioButtonMenuItem subItem = new JRadioButtonMenuItem(subAction);
          menu.add(subItem);
          buttonGroupsMap.get(menuId).add(subItem);

          String selectedCustomMenuEntry = PreferencesData.get("custom_" + menuId);
          if (selBoard.equals(boardId) && (boardId + "_" + customMenuOption).equals(selectedCustomMenuEntry)) {
            menuItemsToClickAfterStartup.add(subItem);
          }
        }
      }
    }

    return item;
  }

  private void filterVisibilityOfSubsequentBoardMenus(List<JMenu> boardsCustomMenus, TargetBoard board,
                                                      int fromIndex) {
    for (int i = fromIndex; i < boardsCustomMenus.size(); i++) {
      JMenu menu = boardsCustomMenus.get(i);
      for (int m = 0; m < menu.getItemCount(); m++) {
        JMenuItem menuItem = menu.getItem(m);
        for (TargetBoard t_board : (List<TargetBoard>)menuItem.getAction().getValue("board")) {
          menuItem.setVisible(t_board.equals(board));
        }
      }
      menu.setVisible(ifThereAreVisibleItemsOn(menu));

      if (menu.isVisible()) {
        JMenuItem visibleSelectedOrFirstMenuItem = selectVisibleSelectedOrFirstMenuItem(menu);
        if (!visibleSelectedOrFirstMenuItem.isSelected()) {
          visibleSelectedOrFirstMenuItem.setSelected(true);
          visibleSelectedOrFirstMenuItem.getAction().actionPerformed(null);
        }
      }
    }
  }

  private static boolean ifThereAreVisibleItemsOn(JMenu menu) {
    for (int i = 0; i < menu.getItemCount(); i++) {
      if (menu.getItem(i).isVisible()) {
        return true;
      }
    }
    return false;
  }

  private JMenu getBoardCustomMenu(String label, String platformUniqueId) throws Exception {
    for (JMenu menu : boardsCustomMenus) {
      if (label.equals(menu.getText()) && menu.getClientProperty("platform").equals(platformUniqueId)) {
        return menu;
      }
    }
    throw new Exception("Custom menu not found!");
  }

  public List<JMenuItem> getProgrammerMenus() {
    return programmerMenus;
  }

  private static JMenuItem selectVisibleSelectedOrFirstMenuItem(JMenu menu) {
    JMenuItem firstVisible = null;
    for (int i = 0; i < menu.getItemCount(); i++) {
      JMenuItem item = menu.getItem(i);
      if (item != null && item.isVisible()) {
        if (item.isSelected()) {
          return item;
        }
        if (firstVisible == null) {
          firstVisible = item;
        }
      }
    }

    if (firstVisible != null) {
      return firstVisible;
    }

    throw new IllegalStateException("Menu has no enabled items");
  }

  private static JMenuItem selectFirstEnabledMenuItem(JMenu menu) {
    for (int i = 1; i < menu.getItemCount(); i++) {
      JMenuItem item = menu.getItem(i);
      if (item != null && item.isEnabled()) {
        return item;
      }
    }
    throw new IllegalStateException("Menu has no enabled items");
  }

  public void rebuildProgrammerMenu() {
    programmerMenus = new LinkedList<>();

    ButtonGroup group = new ButtonGroup();
    for (TargetPackage targetPackage : BaseNoGui.packages.values()) {
      for (TargetPlatform targetPlatform : targetPackage.platforms()) {
        for (String programmer : targetPlatform.getProgrammers().keySet()) {
          String id = targetPackage.getId() + ":" + programmer;

          @SuppressWarnings("serial")
          AbstractAction action = new AbstractAction(targetPlatform.getProgrammer(programmer).get("name")) {
            public void actionPerformed(ActionEvent actionevent) {
              PreferencesData.set("programmer", "" + getValue("id"));
            }
          };
          action.putValue("id", id);
          JMenuItem item = new JRadioButtonMenuItem(action);
          if (PreferencesData.get("programmer").equals(id)) {
            item.setSelected(true);
          }
          group.add(item);
          programmerMenus.add(item);
        }
      }
    }
  }

  /**
   * Scan a folder recursively, and add any sketches found to the menu
   * specified. Set the openReplaces parameter to true when opening the sketch
   * should replace the sketch in the current window, or false when the
   * sketch should open in a new window.
   */
  protected boolean addSketches(JMenu menu, File folder) {
    if (folder == null)
      return false;

    if (!folder.isDirectory()) return false;

    File[] files = folder.listFiles();
    // If a bad folder or unreadable or whatever, this will come back null
    if (files == null) return false;

    // Alphabetize files, since it's not always alpha order
    Arrays.sort(files, new Comparator<File>() {
      @Override
      public int compare(File file, File file2) {
        return file.getName().compareToIgnoreCase(file2.getName());
      }
    });

    boolean ifound = false;
    for (File subfolder : files) {
      if (!FileUtils.isSCCSOrHiddenFile(subfolder) && subfolder.isDirectory()
          && addSketchesSubmenu(menu, subfolder.getName(), subfolder)) {
        ifound = true;
      }
    }
    return ifound;
  }

  private boolean addSketchesSubmenu(JMenu menu, UserLibrary lib) {
    return addSketchesSubmenu(menu, lib.getName(), lib.getInstalledFolder());
  }

  private boolean addSketchesSubmenu(JMenu menu, String name, File folder) {

    ActionListener listener = new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        String path = e.getActionCommand();
        File file = new File(path);
        if (file.exists()) {
          try {
            handleOpen(file);
          } catch (Exception e1) {
            e1.printStackTrace();
          }
        } else {
          showWarning(tr("Sketch Does Not Exist"),
                  tr("The selected sketch no longer exists.\n"
                          + "You may need to restart Arduino to update\n"
                          + "the sketchbook menu."), null);
        }
      }
    };

    File entry = new File(folder, name + ".ino");
    if (!entry.exists() && (new File(folder, name + ".pde")).exists())
      entry = new File(folder, name + ".pde");

    // if a .pde file of the same prefix as the folder exists..
    if (entry.exists()) {

      if (!BaseNoGui.isSanitaryName(name)) {
        if (!builtOnce) {
          String complaining = I18n
                  .format(
                          tr("The sketch \"{0}\" cannot be used.\n"
                                  + "Sketch names must contain only basic letters and numbers\n"
                                  + "(ASCII-only with no spaces, "
                                  + "and it cannot start with a number).\n"
                                  + "To get rid of this message, remove the sketch from\n"
                                  + "{1}"), name, entry.getAbsolutePath());
          showMessage(tr("Ignoring sketch with bad name"), complaining);
        }
        return false;
      }

      JMenuItem item = new JMenuItem(name);
      item.addActionListener(listener);
      item.setActionCommand(entry.getAbsolutePath());
      menu.add(item);
      return true;
    }

    // don't create an extra menu level for a folder named "examples"
    if (folder.getName().equals("examples"))
      return addSketches(menu, folder);

    // not a sketch folder, but maybe a subfolder containing sketches
    JMenu submenu = new JMenu(name);
    boolean found = addSketches(submenu, folder);
    if (found) {
      menu.add(submenu);
      MenuScroller.setScrollerFor(submenu);
    }
    return found;
  }

  protected void addLibraries(JMenu menu, LibraryList libs) throws IOException {

    LibraryList list = new LibraryList(libs);
    list.sort();

    for (UserLibrary lib : list) {
      @SuppressWarnings("serial")
      AbstractAction action = new AbstractAction(lib.getName()) {
        public void actionPerformed(ActionEvent event) {
          UserLibrary l = (UserLibrary) getValue("library");
          try {
            activeEditor.getSketchController().importLibrary(l);
          } catch (IOException e) {
            showWarning(tr("Error"), format("Unable to list header files in {0}", l.getSrcFolder()), e);
          }
        }
      };
      action.putValue("library", lib);

      // Add new element at the bottom
      JMenuItem item = new JMenuItem(action);
      item.putClientProperty("library", lib);
      menu.add(item);

      // XXX: DAM: should recurse here so that library folders can be nested
    }
  }

  /**
   * Given a folder, return a list of the header files in that folder (but not
   * the header files in its sub-folders, as those should be included from
   * within the header files at the top-level).
   */
  static public String[] headerListFromIncludePath(File path) throws IOException {
    String[] list = path.list(new OnlyFilesWithExtension(".h"));
    if (list == null) {
      throw new IOException();
    }
    return list;
  }

  /**
   * Show the About box.
   */
  @SuppressWarnings("serial")
  public void handleAbout() {
    final Image image = Theme.getLibImage("about", activeEditor,
                                          Theme.scale(475), Theme.scale(300));
    final Window window = new Window(activeEditor) {
      public void paint(Graphics graphics) {
        Graphics2D g = Theme.setupGraphics2D(graphics);
        g.drawImage(image, 0, 0, null);

        Font f = new Font("SansSerif", Font.PLAIN, Theme.scale(11));
        g.setFont(f);
        g.setColor(new Color(0,151,156));
        g.drawString(BaseNoGui.VERSION_NAME_LONG, Theme.scale(33), Theme.scale(20));
      }
    };
    window.addMouseListener(new MouseAdapter() {
      public void mousePressed(MouseEvent e) {
        window.dispose();
      }
    });
    int w = image.getWidth(activeEditor);
    int h = image.getHeight(activeEditor);
    Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
    window.setBounds((screen.width - w) / 2, (screen.height - h) / 2, w, h);
    window.setLocationRelativeTo(activeEditor);
    window.setVisible(true);
  }


  /**
   * Show the Preferences window.
   */
  public void handlePrefs() {
    cc.arduino.view.preferences.Preferences dialog = new cc.arduino.view.preferences.Preferences(activeEditor, this);
    if (activeEditor != null) {
      dialog.setLocationRelativeTo(activeEditor);
    }
    dialog.setVisible(true);
  }

  /**
   * Adjust font size
   */
  public void handleFontSizeChange(int change) {
    String pieces[] = PreferencesData.get("editor.font").split(",");
    try {
      int newSize = Integer.parseInt(pieces[2]) + change;
      if (newSize < 4)
        newSize = 4;
      pieces[2] = String.valueOf(newSize);
    } catch (NumberFormatException e) {
      // ignore
      return;
    }
    PreferencesData.set("editor.font", StringUtils.join(pieces, ','));
    getEditors().forEach(Editor::applyPreferences);
  }

  /**
   * Adds a {@link MouseWheelListener} and {@link KeyListener} to the given
   * component that will make "CTRL scroll" and "CTRL +/-"
   * (with optional SHIFT for +) increase/decrease the editor text size.
   * This method is equivalent to calling
   * {@link #addEditorFontResizeMouseWheelListener(Component)} and
   * {@link #addEditorFontResizeKeyListener(Component)} on the given component.
   * Note that this also affects components that use the editor font settings.
   * @param comp - The component to add the listener to.
   */
  public void addEditorFontResizeListeners(Component comp) {
    addEditorFontResizeMouseWheelListener(comp);
    addEditorFontResizeKeyListener(comp);
  }

  /**
   * Adds a {@link MouseWheelListener} to the given component that will
   * make "CTRL scroll" increase/decrease the editor text size.
   * When CTRL is not pressed while scrolling, mouse wheel events are passed
   * on to the parent of the given component.
   * Note that this also affects components that use the editor font settings.
   * @param comp - The component to add the listener to.
   */
  public void addEditorFontResizeMouseWheelListener(Component comp) {
    comp.addMouseWheelListener(e -> {
      if (e.isControlDown()) {
        if (e.getWheelRotation() < 0) {
          this.handleFontSizeChange(1);
        } else {
          this.handleFontSizeChange(-1);
        }
      } else {
        if (e.getComponent() != null && e.getComponent().getParent() != null) {
          e.getComponent().getParent().dispatchEvent(e);
        }
      }
    });
  }

  /**
   * Adds a {@link KeyListener} to the given component that will make "CTRL +/-"
   * (with optional SHIFT for +) increase/decrease the editor text size.
   * Note that this also affects components that use the editor font settings.
   * @param comp - The component to add the listener to.
   */
  public void addEditorFontResizeKeyListener(Component comp) {
    comp.addKeyListener(new KeyAdapter() {
      @Override
      public void keyPressed(KeyEvent e) {
        if (e.getModifiersEx() == KeyEvent.CTRL_DOWN_MASK
            || e.getModifiersEx() == (KeyEvent.CTRL_DOWN_MASK
                                      | KeyEvent.SHIFT_DOWN_MASK)) {
          switch (e.getKeyCode()) {
          case KeyEvent.VK_PLUS:
          case KeyEvent.VK_EQUALS:
            Base.this.handleFontSizeChange(1);
            break;
          case KeyEvent.VK_MINUS:
            if (!e.isShiftDown()) {
              Base.this.handleFontSizeChange(-1);
            }
            break;
          }
        }
      }
    });
  }

  public List<JMenu> getBoardsCustomMenus() {
    return boardsCustomMenus;
  }

  public File getDefaultSketchbookFolderOrPromptForIt() {
    File sketchbookFolder = BaseNoGui.getDefaultSketchbookFolder();

    if (sketchbookFolder == null && !isCommandLine()) {
      sketchbookFolder = promptSketchbookLocation();
    }

    // create the folder if it doesn't exist already
    boolean result = true;
    if (!sketchbookFolder.exists()) {
      result = sketchbookFolder.mkdirs();
    }

    if (!result) {
      showError(tr("You forgot your sketchbook"),
              tr("Arduino cannot run because it could not\n" +
                      "create a folder to store your sketchbook."), null);
    }

    return sketchbookFolder;
  }


  /**
   * Check for a new sketchbook location.
   */
  static protected File promptSketchbookLocation() {
    File folder = null;

    folder = new File(System.getProperty("user.home"), "sketchbook");
    if (!folder.exists()) {
      folder.mkdirs();
      return folder;
    }

    String prompt = tr("Select (or create new) folder for sketches...");
    folder = selectFolder(prompt, null, null);
    if (folder == null) {
      System.exit(0);
    }
    return folder;
  }


  // .................................................................


  /**
   * Implements the cross-platform headache of opening URLs
   * TODO This code should be replaced by PApplet.link(),
   * however that's not a static method (because it requires
   * an AppletContext when used as an applet), so it's mildly
   * trickier than just removing this method.
   */
  static public void openURL(String url) {
    try {
      BaseNoGui.getPlatform().openURL(url);
    } catch (Exception e) {
      showWarning(tr("Problem Opening URL"),
                  format(tr("Could not open the URL\n{0}"), url), e);
    }
  }


  /**
   * Used to determine whether to disable the "Show Sketch Folder" option.
   *
   * @return true If a means of opening a folder is known to be available.
   */
  static protected boolean openFolderAvailable() {
    return BaseNoGui.getPlatform().openFolderAvailable();
  }


  /**
   * Implements the other cross-platform headache of opening
   * a folder in the machine's native file browser.
   */
  static public void openFolder(File file) {
    try {
      BaseNoGui.getPlatform().openFolder(file);
    } catch (Exception e) {
      showWarning(tr("Problem Opening Folder"),
                  format(tr("Could not open the folder\n{0}"), file.getAbsolutePath()), e);
    }
  }


  // .................................................................


  static public File selectFolder(String prompt, File folder, Component parent) {
    JFileChooser fc = new JFileChooser();
    fc.setDialogTitle(prompt);
    if (folder != null) {
      fc.setSelectedFile(folder);
    }
    fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);

    int returned = fc.showOpenDialog(parent);
    if (returned == JFileChooser.APPROVE_OPTION) {
      return fc.getSelectedFile();
    }
    return null;
  }


  // .................................................................


  /**
   * Give this Frame an icon.
   */
  static public void setIcon(Frame frame) {
    if (OSUtils.isMacOS()) {
      return;
    }

    List<Image> icons = Stream
      .of("16", "24", "32", "48", "64", "72", "96", "128", "256")
      .map(res -> "/lib/icons/" + res + "x" + res + "/apps/arduino.png")
      .map(path -> BaseNoGui.getContentFile(path).getAbsolutePath())
      .map(absPath -> Toolkit.getDefaultToolkit().createImage(absPath))
      .collect(Collectors.toList());
    frame.setIconImages(icons);
  }


  /**
   * Registers key events for a Ctrl-W and ESC with an ActionListener
   * that will take care of disposing the window.
   */
  static public void registerWindowCloseKeys(JRootPane root,
                                             ActionListener disposer) {
    KeyStroke stroke = KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0);
    root.registerKeyboardAction(disposer, stroke,
            JComponent.WHEN_IN_FOCUSED_WINDOW);

    int modifiers = Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
    stroke = KeyStroke.getKeyStroke('W', modifiers);
    root.registerKeyboardAction(disposer, stroke,
            JComponent.WHEN_IN_FOCUSED_WINDOW);
  }


  // .................................................................


  static public void showReference(String filename) {
    showReference("reference/www.arduino.cc/en", filename);
  }

  static public void showReference(String prefix, String filename) {
    File referenceFolder = getContentFile(prefix);
    File referenceFile = new File(referenceFolder, filename);
    if (!referenceFile.exists())
      referenceFile = new File(referenceFolder, filename + ".html");

    if(referenceFile.exists()){
      openURL(referenceFile.getAbsolutePath());
    }else{
      showWarning(tr("Problem Opening URL"), format(tr("Could not open the URL\n{0}"), referenceFile), null);
    }
  }

  public static void showEdisonGettingStarted() {
    showReference("reference/Edison_help_files", "ArduinoIDE_guide_edison");
  }

  static public void showArduinoGettingStarted() {
    if (OSUtils.isMacOS()) {
      showReference("Guide/MacOSX");
    } else if (OSUtils.isWindows()) {
      showReference("Guide/Windows");
    } else {
      openURL("http://www.arduino.cc/playground/Learning/Linux");
    }
  }

  static public void showReference() {
    showReference("Reference/HomePage");
  }


  static public void showEnvironment() {
    showReference("Guide/Environment");
  }


  static public void showTroubleshooting() {
    showReference("Guide/Troubleshooting");
  }


  static public void showFAQ() {
    showReference("Main/FAQ");
  }


  // .................................................................


  /**
   * "No cookie for you" type messages. Nothing fatal or all that
   * much of a bummer, but something to notify the user about.
   */
  static public void showMessage(String title, String message) {
    BaseNoGui.showMessage(title, message);
  }


  /**
   * Non-fatal error message with optional stack trace side dish.
   */
  static public void showWarning(String title, String message, Exception e) {
    BaseNoGui.showWarning(title, message, e);
  }


  static public void showError(String title, String message, Throwable e) {
    showError(title, message, e, 1);
  }

  static public void showError(String title, String message, int exit_code) {
    showError(title, message, null, exit_code);
  }

  /**
   * Show an error message that's actually fatal to the program.
   * This is an error that can't be recovered. Use showWarning()
   * for errors that allow P5 to continue running.
   */
  static public void showError(String title, String message, Throwable e, int exit_code) {
    BaseNoGui.showError(title, message, e, exit_code);
  }


  static public File getContentFile(String name) {
    return BaseNoGui.getContentFile(name);
  }


  // ...................................................................


  /**
   * Get the number of lines in a file by counting the number of newline
   * characters inside a String (and adding 1).
   */
  static public int countLines(String what) {
    return BaseNoGui.countLines(what);
  }


  /**
   * Same as PApplet.loadBytes(), however never does gzip decoding.
   */
  static public byte[] loadBytesRaw(File file) throws IOException {
    int size = (int) file.length();
    FileInputStream input = null;
    try {
      input = new FileInputStream(file);
      byte buffer[] = new byte[size];
      int offset = 0;
      int bytesRead;
      while ((bytesRead = input.read(buffer, offset, size - offset)) != -1) {
        offset += bytesRead;
        if (bytesRead == 0) break;
      }
      return buffer;
    } finally {
      IOUtils.closeQuietly(input);
    }
  }


  /**
   * Read from a file with a bunch of attribute/value pairs
   * that are separated by = and ignore comments with #.
   */
  static public HashMap<String, String> readSettings(File inputFile) {
    HashMap<String, String> outgoing = new HashMap<>();
    if (!inputFile.exists()) return outgoing;  // return empty hash

    String lines[] = PApplet.loadStrings(inputFile);
    for (int i = 0; i < lines.length; i++) {
      int hash = lines[i].indexOf('#');
      String line = (hash == -1) ?
              lines[i].trim() : lines[i].substring(0, hash).trim();
      if (line.length() == 0) continue;

      int equals = line.indexOf('=');
      if (equals == -1) {
        System.err.println("ignoring illegal line in " + inputFile);
        System.err.println("  " + line);
        continue;
      }
      String attr = line.substring(0, equals).trim();
      String valu = line.substring(equals + 1).trim();
      outgoing.put(attr, valu);
    }
    return outgoing;
  }


  static public void copyFile(File sourceFile,
                              File targetFile) throws IOException {
    InputStream from = null;
    OutputStream to = null;
    try {
      from = new BufferedInputStream(new FileInputStream(sourceFile));
      to = new BufferedOutputStream(new FileOutputStream(targetFile));
      byte[] buffer = new byte[16 * 1024];
      int bytesRead;
      while ((bytesRead = from.read(buffer)) != -1) {
        to.write(buffer, 0, bytesRead);
      }
      to.flush();
    } finally {
      IOUtils.closeQuietly(from);
      IOUtils.closeQuietly(to);
    }

    targetFile.setLastModified(sourceFile.lastModified());
  }


  /**
   * Grab the contents of a file as a string.
   */
  static public String loadFile(File file) throws IOException {
    return BaseNoGui.loadFile(file);
  }


  /**
   * Spew the contents of a String object out to a file.
   */
  static public void saveFile(String str, File file) throws IOException {
    BaseNoGui.saveFile(str, file);
  }


  /**
   * Calculate the size of the contents of a folder.
   * Used to determine whether sketches are empty or not.
   * Note that the function calls itself recursively.
   */
  static public int calcFolderSize(File folder) {
    int size = 0;

    String files[] = folder.list();
    // null if folder doesn't exist, happens when deleting sketch
    if (files == null) return -1;

    for (int i = 0; i < files.length; i++) {
      if (files[i].equals(".") || (files[i].equals("..")) ||
              files[i].equals(".DS_Store")) continue;
      File fella = new File(folder, files[i]);
      if (fella.isDirectory()) {
        size += calcFolderSize(fella);
      } else {
        size += (int) fella.length();
      }
    }
    return size;
  }

  public void handleAddLibrary() {
    JFileChooser fileChooser = new JFileChooser(System.getProperty("user.home"));
    fileChooser.setDialogTitle(tr("Select a zip file or a folder containing the library you'd like to add"));
    fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
    fileChooser.setFileFilter(new FileNameExtensionFilter(tr("ZIP files or folders"), "zip"));

    Dimension preferredSize = fileChooser.getPreferredSize();
    fileChooser.setPreferredSize(new Dimension(preferredSize.width + 200, preferredSize.height + 200));

    int returnVal = fileChooser.showOpenDialog(activeEditor);

    if (returnVal != JFileChooser.APPROVE_OPTION) {
      return;
    }

    File sourceFile = fileChooser.getSelectedFile();
    File tmpFolder = null;

    try {
      // unpack ZIP
      if (!sourceFile.isDirectory()) {
        try {
          tmpFolder = FileUtils.createTempFolder();
          ZipDeflater zipDeflater = new ZipDeflater(sourceFile, tmpFolder);
          zipDeflater.deflate();
          File[] foldersInTmpFolder = tmpFolder.listFiles(new OnlyDirs());
          if (foldersInTmpFolder.length != 1) {
            throw new IOException(tr("Zip doesn't contain a library"));
          }
          sourceFile = foldersInTmpFolder[0];
        } catch (IOException e) {
          activeEditor.statusError(e);
          return;
        }
      }

      File libFolder = sourceFile;
      if (FileUtils.isSubDirectory(new File(PreferencesData.get("sketchbook.path")), libFolder)) {
        activeEditor.statusError(tr("A subfolder of your sketchbook is not a valid library"));
        return;
      }

      if (FileUtils.isSubDirectory(libFolder, new File(PreferencesData.get("sketchbook.path")))) {
        activeEditor.statusError(tr("You can't import a folder that contains your sketchbook"));
        return;
      }

      String libName = libFolder.getName();
      if (!BaseNoGui.isSanitaryName(libName)) {
        String mess = format(tr("The library \"{0}\" cannot be used.\n"
                        + "Library names must contain only basic letters and numbers.\n"
                        + "(ASCII only and no spaces, and it cannot start with a number)"),
                libName);
        activeEditor.statusError(mess);
        return;
      }

      String[] headers;
      File libProp = new File(libFolder, "library.properties");
      File srcFolder = new File(libFolder, "src");
      if (libProp.exists() && srcFolder.isDirectory()) {
        headers = BaseNoGui.headerListFromIncludePath(srcFolder);
      } else {
        headers = BaseNoGui.headerListFromIncludePath(libFolder);
      }
      if (headers.length == 0) {
        activeEditor.statusError(tr("Specified folder/zip file does not contain a valid library"));
        return;
      }

      // copy folder
      File destinationFolder = new File(BaseNoGui.getSketchbookLibrariesFolder().folder, sourceFile.getName());
      if (!destinationFolder.mkdir()) {
        activeEditor.statusError(format(tr("A library named {0} already exists"), sourceFile.getName()));
        return;
      }
      try {
        FileUtils.copy(sourceFile, destinationFolder);
      } catch (IOException e) {
        activeEditor.statusError(e);
        return;
      }
      activeEditor.statusNotice(tr("Library added to your libraries. Check \"Include library\" menu"));
    } catch (IOException e) {
      // FIXME error when importing. ignoring :(
    } finally {
      // delete zip created temp folder, if exists
      newLibraryImported = true;
      FileUtils.recursiveDelete(tmpFolder);
    }
  }

  public static DiscoveryManager getDiscoveryManager() {
    return BaseNoGui.getDiscoveryManager();
  }

  public Editor getActiveEditor() {
    return activeEditor;
  }

  public boolean hasActiveEditor() {
    return activeEditor != null;
  }

  public List<Editor> getEditors() {
    return new LinkedList<>(editors);
  }

  public PdeKeywords getPdeKeywords() {
    return pdeKeywords;
  }

  public List<JMenuItem> getRecentSketchesMenuItems() {
    return recentSketchesMenuItems;
  }

}
