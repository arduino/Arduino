package processing.app;

import cc.arduino.Constants;
import cc.arduino.contributions.GPGDetachedSignatureVerifier;
import cc.arduino.contributions.VersionComparator;
import cc.arduino.contributions.libraries.LibrariesIndexer;
import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.packages.ContributedTool;
import cc.arduino.contributions.packages.ContributionsIndexer;
import cc.arduino.packages.DiscoveryManager;
import com.fasterxml.jackson.core.JsonProcessingException;
import org.apache.commons.compress.utils.IOUtils;
import org.apache.commons.logging.impl.LogFactoryImpl;
import org.apache.commons.logging.impl.NoOpLog;
import processing.app.debug.*;
import processing.app.helpers.*;
import processing.app.helpers.filefilters.OnlyDirs;
import processing.app.helpers.filefilters.OnlyFilesWithExtension;
import processing.app.legacy.PApplet;
import processing.app.packages.LibraryList;
import processing.app.packages.UserLibrary;
import processing.app.packages.UserLibraryFolder;
import processing.app.packages.UserLibraryFolder.Location;
import cc.arduino.files.DeleteFilesOnShutdown;
import processing.app.helpers.FileUtils;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

import cc.arduino.packages.BoardPort;

import static processing.app.I18n.tr;
import static processing.app.helpers.filefilters.OnlyDirs.ONLY_DIRS;

public class BaseNoGui {

  /** Version string to be used for build */
  public static final int REVISION = 10811;
  /** Extended version string displayed on GUI */
  public static final String VERSION_NAME = "1.8.11";
  public static final String VERSION_NAME_LONG;

  // Current directory to use for relative paths specified on the
  // commandline
  static String currentDirectory = System.getProperty("user.dir");

  static {
    String versionNameLong = VERSION_NAME;
    File hourlyBuildTxt = new File(getContentFile("lib"), "hourlyBuild.txt");
    if (hourlyBuildTxt.exists() && hourlyBuildTxt.canRead()) {
      versionNameLong += " Hourly Build";
      try {
        versionNameLong += " " + FileUtils.readFileToString(hourlyBuildTxt).trim();
      } catch (IOException e) {
        //noop
      }
    }

    File windowsStoreConfig = new File(getContentFile("lib"), "windowsStore.txt");
    if (windowsStoreConfig.exists()) {
      try {
        PreferencesMap conf = new PreferencesMap(windowsStoreConfig);
        PreferencesData.setBoolean("runtime.is-windows-store-app", true);
        PreferencesData.set("runtime.windows-store-app.id", conf.get("appid"));
        versionNameLong += " (Windows Store " + conf.get("version") + ")";
      } catch (IOException e1) {
        e1.printStackTrace();
      }
    }

    VERSION_NAME_LONG = versionNameLong;
  }

  private static DiscoveryManager discoveryManager;

  // these are static because they're used by Sketch
  static private File examplesFolder;
  static private File toolsFolder;

  // maps #included files to their library folder
  public static Map<String, LibraryList> importToLibraryTable;

  // XXX: Remove this field
  static private List<UserLibraryFolder> librariesFolders;

  static UserNotifier notifier = new BasicUserNotifier();

  static public Map<String, TargetPackage> packages;

  static Platform platform;

  static File portableFolder = null;
  static final String portableSketchbookFolder = "sketchbook";

  public static ContributionsIndexer indexer;
  public static LibrariesIndexer librariesIndexer;

  private static String boardManagerLink = "";

  private static File buildCache;

  // Returns a File object for the given pathname. If the pathname
  // is not absolute, it is interpreted relative to the current
  // directory when starting the IDE (which is not the same as the
  // current working directory!).
  static public File absoluteFile(String path) {
    if (path == null) return null;

    File file = new File(path);
    if (!file.isAbsolute()) {
      file = new File(currentDirectory, path);
    }
    return file;
  }

  /**
   * Get the number of lines in a file by counting the number of newline
   * characters inside a String (and adding 1).
   */
  static public int countLines(String what) {
    int count = 1;
    for (char c : what.toCharArray()) {
      if (c == '\n') count++;
    }
    return count;
  }

  static public PreferencesMap getBoardPreferences() {
    TargetBoard board = getTargetBoard();
    if (board == null)
      return null;
    String boardId = board.getId();

    PreferencesMap prefs = new PreferencesMap(board.getPreferences());

    String extendedName = prefs.get("name");
    for (String menuId : board.getMenuIds()) {
      if (!board.hasMenu(menuId))
        continue;

      // Get "custom_[MENU_ID]" preference (for example "custom_cpu")
      String entry = PreferencesData.get("custom_" + menuId);
      if (entry != null && entry.startsWith(boardId)) {

        String selectionId = entry.substring(boardId.length() + 1);
        prefs.putAll(board.getMenuPreferences(menuId, selectionId));

        // Update the name with the extended configuration
        extendedName += ", " + board.getMenuLabel(menuId, selectionId);
      }
    }
    prefs.put("name", extendedName);

    // Resolve tools needed for this board
    List<ContributedTool> requiredTools = new ArrayList<>();

    // Add all tools dependencies specified in package index
    ContributedPlatform p = indexer.getContributedPlaform(getTargetPlatform());
    if (p != null)
      requiredTools.addAll(p.getResolvedTools());

    // Add all tools dependencies from the (possibily) referenced core
    String core = prefs.get("build.core");
    if (core != null && core.contains(":")) {
      String split[] = core.split(":");
      TargetPlatform referenced = BaseNoGui.getCurrentTargetPlatformFromPackage(split[0]);
      if (referenced != null) {
        ContributedPlatform referencedPlatform = indexer.getContributedPlaform(referenced);
        if (referencedPlatform != null)
          requiredTools.addAll(referencedPlatform.getResolvedTools());
      } else {
        String msg = tr("The current selected board needs the core '{0}' that is not installed.");
        System.out.println(I18n.format(msg, core));
      }
    }

    String prefix = "runtime.tools.";
    for (ContributedTool tool : requiredTools) {
      File folder = tool.getInstalledFolder();
      if (folder == null) {
        continue;
      }
      String toolPath = folder.getAbsolutePath();
      prefs.put(prefix + tool.getName() + ".path", toolPath);
      prefs.put(prefix + tool.getName() + "-" + tool.getVersion() + ".path", toolPath);
      PreferencesData.set(prefix + tool.getName() + ".path", toolPath);
      PreferencesData.set(prefix + tool.getName() + "-" + tool.getVersion() + ".path", toolPath);
    }
    return prefs;
  }

  static public File getContentFile(String name) {
    String appDir = System.getProperty("APP_DIR");
    if (appDir == null || appDir.length() == 0) {
      appDir = currentDirectory;
    }
    File installationFolder = new File(appDir);
    return new File(installationFolder, name);
  }

  static public TargetPlatform getCurrentTargetPlatformFromPackage(String pack) {
    return getTargetPlatform(pack, PreferencesData.get("target_platform"));
  }

  static public  File getDefaultSketchbookFolder() {
    if (getPortableFolder() != null)
      return new File(getPortableFolder(), getPortableSketchbookFolder());

    File sketchbookFolder = null;
    try {
      sketchbookFolder = getPlatform().getDefaultSketchbookFolder();
    } catch (Exception e) { }

    return sketchbookFolder;
  }

  public static DiscoveryManager getDiscoveryManager() {
    if (discoveryManager == null) {
      discoveryManager = new DiscoveryManager(packages);
    }
    return discoveryManager;
  }

  static public File getExamplesFolder() {
    return examplesFolder;
  }

  static public String getExamplesPath() {
    return examplesFolder.getAbsolutePath();
  }

  static public File getHardwareFolder() {
    // calculate on the fly because it's needed by Preferences.init() to find
    // the boards.txt and programmers.txt preferences files (which happens
    // before the other folders / paths get cached).
    return getContentFile("hardware");
  }

  static public String getHardwarePath() {
    return getHardwareFolder().getAbsolutePath();
  }

  static public List<UserLibraryFolder> getLibrariesFolders() {
    return librariesFolders;
  }

  static public Platform getPlatform() {
    return platform;
  }

  static public File getPortableFolder() {
    return portableFolder;
  }

  static public String getPortableSketchbookFolder() {
    return portableSketchbookFolder;
  }

  static public File getCachePath() {
    if (buildCache == null) {
      try {
        buildCache = FileUtils.createTempFolder("arduino_cache_");
        DeleteFilesOnShutdown.add(buildCache);
      } catch (IOException e) {
        return null;
      }
    }
    return buildCache;
  }

  /**
   * Convenience method to get a File object for the specified filename inside
   * the settings folder.
   * For now, only used by Preferences to get the preferences.txt file.
   * @param filename A file inside the settings folder.
   * @return filename wrapped as a File object inside the settings folder
   */
  static public File getSettingsFile(String filename) {
    return new File(getSettingsFolder(), filename);
  }

  static public File getSettingsFolder() {
    if (getPortableFolder() != null)
      return getPortableFolder();

    File settingsFolder = null;

    String preferencesPath = PreferencesData.get("settings.path");
    if (preferencesPath != null) {
      settingsFolder = absoluteFile(preferencesPath);

    } else {
      try {
        settingsFolder = getPlatform().getSettingsFolder();
      } catch (Exception e) {
        showError(tr("Problem getting data folder"),
                  tr("Error getting the Arduino data folder."), e);
      }
    }

    // create the folder if it doesn't exist already
    if (!settingsFolder.exists()) {
      if (!settingsFolder.mkdirs()) {
        showError(tr("Settings issues"),
                tr("Arduino cannot run because it could not\n" +
                        "create a folder to store your settings."), null);
      }
    }
    return settingsFolder;
  }

  static public File getSketchbookFolder() {
    String sketchBookPath = PreferencesData.get("sketchbook.path");
    if (getPortableFolder() != null && !new File(sketchBookPath).isAbsolute()) {
      return new File(getPortableFolder(), sketchBookPath);
    }
    return absoluteFile(sketchBookPath);
  }

  static public File getSketchbookHardwareFolder() {
    return new File(getSketchbookFolder(), "hardware");
  }

  static public UserLibraryFolder getSketchbookLibrariesFolder() {
    File libdir = new File(getSketchbookFolder(), "libraries");
    if (!libdir.exists()) {
      FileWriter freadme = null;
      try {
        libdir.mkdirs();
        freadme = new FileWriter(new File(libdir, "readme.txt"));
        freadme.write(tr("For information on installing libraries, see: " +
                        "http://www.arduino.cc/en/Guide/Libraries\n"));
      } catch (Exception e) {
      } finally {
        IOUtils.closeQuietly(freadme);
      }
    }
    return new UserLibraryFolder(libdir, Location.SKETCHBOOK);
  }

  static public String getSketchbookPath() {
    // Get the sketchbook path, and make sure it's set properly
    String sketchbookPath = PreferencesData.get("sketchbook.path");

    // If a value is at least set, first check to see if the folder exists.
    // If it doesn't, warn the user that the sketchbook folder is being reset.
    if (sketchbookPath != null) {
      File sketchbookFolder;
      if (getPortableFolder() != null && !new File(sketchbookPath).isAbsolute()) {
        sketchbookFolder = new File(getPortableFolder(), sketchbookPath);
      } else {
        sketchbookFolder = absoluteFile(sketchbookPath);
      }
      if (!sketchbookFolder.exists()) {
        showWarning(tr("Sketchbook folder disappeared"),
                    tr("The sketchbook folder no longer exists.\n" +
                      "Arduino will switch to the default sketchbook\n" +
                      "location, and create a new sketchbook folder if\n" +
                      "necessary. Arduino will then stop talking about\n" +
                      "himself in the third person."), null);
        sketchbookPath = null;
      }
    }

    return sketchbookPath;
  }

  public static TargetBoard getTargetBoard() {
    TargetPlatform targetPlatform = getTargetPlatform();
    if (targetPlatform == null)
      return null;
    String boardId = PreferencesData.get("board");
    return targetPlatform.getBoard(boardId);
  }

  /**
   * Returns a specific TargetPackage
   *
   * @param packageName
   * @return
   */
  static public TargetPackage getTargetPackage(String packageName) {
    return packages.get(packageName);
  }

  /**
   * Returns the currently selected TargetPlatform.
   *
   * @return
   */
  static public TargetPlatform getTargetPlatform() {
    String packageName = PreferencesData.get("target_package");
    String platformName = PreferencesData.get("target_platform");
    return getTargetPlatform(packageName, platformName);
  }

  /**
   * Returns a specific TargetPlatform searching Package/Platform
   *
   * @param packageName
   * @param platformName
   * @return
   */
  static public TargetPlatform getTargetPlatform(String packageName,
                                                 String platformName) {
    TargetPackage p = packages.get(packageName);
    if (p == null)
      return null;
    return p.get(platformName);
  }

  static public File getToolsFolder() {
    return toolsFolder;
  }

  static public String getToolsPath() {
    return toolsFolder.getAbsolutePath();
  }

  static public String getBoardManagerLink() {
	  return boardManagerLink;
  }

  protected static PropertyChangeSupport propertyChangeSupport = new PropertyChangeSupport(BaseNoGui.class);

  public static void setBoardManagerLink(String temp) {
	  boardManagerLink = temp;
	  propertyChangeSupport.firePropertyChange("boardManagerLink", "", boardManagerLink);
  }

  public static void addPropertyChangeListener(PropertyChangeListener listener) {
	  propertyChangeSupport.addPropertyChangeListener(listener);
  }

  /**
   * Given a folder, return a list of the header files in that folder (but not
   * the header files in its sub-folders, as those should be included from
   * within the header files at the top-level).
   */
  static public String[] headerListFromIncludePath(File path) throws IOException {
    String[] list = path.list(new OnlyFilesWithExtension(".h", ".hh", ".hpp"));
    if (list == null) {
      throw new IOException();
    }
    return list;
  }

  protected static void dumpPrefs(CommandlineParser parser) {
    if (parser.getGetPref() != null) {
      String value = PreferencesData.get(parser.getGetPref(), null);
      if (value != null) {
        System.out.println(value);
        System.exit(0);
      } else {
        System.exit(4);
      }
    } else {
      System.out.println("#PREFDUMP#");
      PreferencesMap prefs = PreferencesData.getMap();
      for (Map.Entry<String, String> entry : prefs.entrySet()) {
        System.out.println(entry.getKey() + "=" + entry.getValue());
      }
      System.exit(0);
    }
  }

  static public void initLogger() {
    System.setProperty(LogFactoryImpl.LOG_PROPERTY, NoOpLog.class.getCanonicalName());
    Logger.getLogger("javax.jmdns").setLevel(Level.OFF);
  }

  static public void initPackages() throws Exception {
    indexer = new ContributionsIndexer(getSettingsFolder(), getHardwareFolder(), getPlatform(),
        new GPGDetachedSignatureVerifier());

    try {
      indexer.parseIndex();
    } catch (JsonProcessingException e) {
      File indexFile = indexer.getIndexFile(Constants.DEFAULT_INDEX_FILE_NAME);
      File indexSignatureFile = indexer.getIndexFile(Constants.DEFAULT_INDEX_FILE_NAME + ".sig");
      indexFile.delete();
      indexSignatureFile.delete();
      throw e;
    }
    indexer.syncWithFilesystem();

    packages = new LinkedHashMap<>();
    loadHardware(getHardwareFolder());
    loadContributedHardware(indexer);
    loadHardware(getSketchbookHardwareFolder());
    createToolPreferences(indexer.getInstalledTools(), true);

    librariesIndexer = new LibrariesIndexer(getSettingsFolder());
    try {
      librariesIndexer.parseIndex();
    } catch (JsonProcessingException e) {
      File librariesIndexFile = librariesIndexer.getIndexFile();
      librariesIndexFile.delete();
    }

    if (discoveryManager == null) {
      discoveryManager = new DiscoveryManager(packages);
    }
  }

  static protected void initPlatform() {
    try {
      Class<?> platformClass = Class.forName("processing.app.Platform");
      if (OSUtils.isMacOS()) {
        platformClass = Class.forName("processing.app.macosx.Platform");
      } else if (OSUtils.isWindows()) {
        platformClass = Class.forName("processing.app.windows.Platform");
      } else if (OSUtils.isLinux()) {
        platformClass = Class.forName("processing.app.linux.Platform");
      }
      platform = (Platform) platformClass.newInstance();
    } catch (Exception e) {
      showError(tr("Problem Setting the Platform"),
                tr("An unknown error occurred while trying to load\n" +
                  "platform-specific code for your machine."), e);
    }
  }

  static public void initPortableFolder() {
    // Portable folder
    portableFolder = getContentFile("portable");
    if (!portableFolder.exists()) {
      portableFolder = null;
    }
  }

  static public void initVersion() {
    // help 3rd party installers find the correct hardware path
    PreferencesData.set("last.ide." + VERSION_NAME + ".hardwarepath", getHardwarePath());
    PreferencesData.set("last.ide." + VERSION_NAME + ".daterun", "" + (new Date()).getTime() / 1000);
  }

  /**
   * Return true if the name is valid for a Processing sketch.
   */
  static public boolean isSanitaryName(String name) {
    return sanitizeName(name).equals(name);
  }

  static protected void loadHardware(File folder) {
    if (!folder.isDirectory()) {
      return;
    }

    String list[] = folder.list(new OnlyDirs());

    // if a bad folder or something like that, this might come back null
    if (list == null) {
      return;
    }

    // alphabetize list, since it's not always alpha order
    // replaced hella slow bubble sort with this feller for 0093
    Arrays.sort(list, String.CASE_INSENSITIVE_ORDER);

    for (String target : list) {
      // Skip reserved 'tools' folder.
      if (target.equals("tools")) {
        continue;
      }
      File subfolder = new File(folder, target);

      TargetPackage targetPackage;
      if (packages.containsKey(target)) {
        targetPackage = packages.get(target);
      } else {
        targetPackage = new LegacyTargetPackage(target);
        packages.put(target, targetPackage);
      }
      try {
        loadTargetPackage(targetPackage, subfolder);
      } catch (TargetPlatformException e) {
        System.out.println("WARNING: Error loading hardware folder " + new File(folder, target));
        System.out.println("  " + e.getMessage());
      }
    }
  }

  private static void loadTargetPackage(TargetPackage targetPackage, File _folder) throws TargetPlatformException {
    File[] folders = _folder.listFiles(ONLY_DIRS);
    if (folders == null) {
      return;
    }

    for (File subFolder : folders) {
      if (!subFolder.exists() || !subFolder.canRead()) {
        continue;
      }
      String arch = subFolder.getName();
      try {
        TargetPlatform p = new LegacyTargetPlatform(arch, subFolder, targetPackage);
        targetPackage.getPlatforms().put(arch, p);
      } catch (TargetPlatformException e) {
        System.err.println(e.getMessage());
      }
    }

    if (targetPackage.getPlatforms().size() == 0) {
      throw new TargetPlatformException(I18n.format(tr("No valid hardware definitions found in folder {0}."), _folder.getName()));
    }
  }

  /**
   * Grab the contents of a file as a string.
   */
  static public String loadFile(File file) throws IOException {
    String[] contents = PApplet.loadStrings(file);
    if (contents == null) return null;
    return PApplet.join(contents, "\n");
  }

  public static void checkInstallationFolder() {
    if (isIDEInstalledIntoSettingsFolder()) {
      showError(tr("Incorrect IDE installation folder"), tr("Your copy of the IDE is installed in a subfolder of your settings folder.\nPlease move the IDE to another folder."), 10);
    }
    if (isIDEInstalledIntoSketchbookFolder()) {
      showError(tr("Incorrect IDE installation folder"), tr("Your copy of the IDE is installed in a subfolder of your sketchbook.\nPlease move the IDE to another folder."), 10);
    }
  }

  public static boolean isIDEInstalledIntoSketchbookFolder() {
    return PreferencesData.has("sketchbook.path") && FileUtils.isSubDirectory(new File(PreferencesData.get("sketchbook.path")), new File(PreferencesData.get("runtime.ide.path")));
  }

  public static boolean isIDEInstalledIntoSettingsFolder() {
    try {
      return FileUtils.isSubDirectory(BaseNoGui.getPlatform().getSettingsFolder(), new File(PreferencesData.get("runtime.ide.path")));
    } catch (Exception e) {
      return false;
    }
  }

  static public void onBoardOrPortChange() {
    examplesFolder = getContentFile("examples");
    toolsFolder = getContentFile("tools");
    librariesFolders = new ArrayList<>();

    // Add IDE libraries folder
    librariesFolders.add(new UserLibraryFolder(getContentFile("libraries"), Location.IDE_BUILTIN));

    TargetPlatform targetPlatform = getTargetPlatform();
    if (targetPlatform != null) {
      String core = getBoardPreferences().get("build.core", "arduino");
      if (core.contains(":")) {
        String referencedCore = core.split(":")[0];
        TargetPlatform referencedPlatform = getTargetPlatform(referencedCore, targetPlatform.getId());
        if (referencedPlatform != null) {
          File referencedPlatformFolder = referencedPlatform.getFolder();
          // Add libraries folder for the referenced platform
          File folder = new File(referencedPlatformFolder, "libraries");
          librariesFolders.add(new UserLibraryFolder(folder, Location.REFERENCED_CORE));
        }
      }
      File platformFolder = targetPlatform.getFolder();
      // Add libraries folder for the selected platform
      File folder = new File(platformFolder, "libraries");
      librariesFolders.add(new UserLibraryFolder(folder, Location.CORE));
    }

    // Add libraries folder for the sketchbook
    librariesFolders.add(getSketchbookLibrariesFolder());

    // Scan for libraries in each library folder.
    // Libraries located in the latest folders on the list can override
    // other libraries with the same name.
    librariesIndexer.setLibrariesFolders(librariesFolders);
    if (getTargetPlatform() != null) {
      librariesIndexer.setArchitecturePriority(getTargetPlatform().getId());
    }
    librariesIndexer.rescanLibraries();

    populateImportToLibraryTable();
  }

  static protected void loadContributedHardware(ContributionsIndexer idx) {
    for (TargetPackage pack : idx.createTargetPackages()) {
      packages.put(pack.getId(), pack);
    }
  }

  public static void createToolPreferences(Collection<ContributedTool> installedTools, boolean removeOldKeys) {
    String prefix = "runtime.tools.";
    if (removeOldKeys) {
      PreferencesData.removeAllKeysWithPrefix(prefix);
    }

    Map<String, String> latestVersions = new HashMap<>();
    for (ContributedTool tool : installedTools) {
      File installedFolder = tool.getInstalledFolder();
      String toolPath;
      if (installedFolder != null) {
        toolPath = installedFolder.getAbsolutePath();
      } else {
        toolPath = Constants.PREF_REMOVE_PLACEHOLDER;
      }
      String toolName = tool.getName();
      String toolVersion = tool.getVersion();
      PreferencesData.set(prefix + toolName + "-" + toolVersion + ".path", toolPath);
      PreferencesData.set(prefix + tool.getPackager() + "-" + toolName + "-" + toolVersion + ".path", toolPath);
      // In the generic tool property put the path of the latest version if more are available
      try {
        if (!latestVersions.containsKey(toolName) || VersionComparator.greaterThan(toolVersion, latestVersions.get(toolName))) {
          latestVersions.put(toolName, toolVersion);
          PreferencesData.set(prefix + toolName + ".path", toolPath);
        }
      } catch (Exception e) {
        // Ignore invalid versions
      }
    }
  }

  static public void populateImportToLibraryTable() {
    // Populate importToLibraryTable. Each header filename maps to
    // a list of libraries. Compiler.java will use only the first
    // library on each list. The others are used only to advise
    // user of ambiguously matched and duplicate libraries.
    importToLibraryTable = new HashMap<>();
    for (UserLibrary lib : librariesIndexer.getInstalledLibraries()) {
      try {
        String headers[] = headerListFromIncludePath(lib.getSrcFolder());
        for (String header : headers) {
          LibraryList list = importToLibraryTable.get(header);
          if (list == null) {
            // This is the first library found with this header
            list = new LibraryList();
            list.addFirst(lib);
            importToLibraryTable.put(header, list);
          } else {
            UserLibrary old = list.peekFirst();
            boolean useThisLib = true;
            // This is the case where 2 libraries have a .h header
            // with the same name.  We must decide which library to
            // use when a sketch has #include "name.h"
            //
            // When all other factors are equal, "libName" is
            // used in preference to "oldName", because getLibraries()
            // gives the library list in order from less specific to
            // more specific locations.
            //
            // But often one library is more clearly the user's
            // intention to use.  Many cases are tested, always first
            // for "libName", then for "oldName".
            //
            String name = header.substring(0, header.length() - 2); // name without ".h"
            String oldName = old.getInstalledFolder().getName();  // just the library folder name
            String libName = lib.getInstalledFolder().getName();  // just the library folder name
            //System.out.println("name conflict: " + name);
            //System.out.println(" old = " + oldName + " -> " + old.getInstalledFolder().getPath());
            //System.out.println(" new = " + libName + " -> " + lib.getInstalledFolder().getPath());
            String name_lc = name.toLowerCase();
            String oldName_lc = oldName.toLowerCase();
            String libName_lc = libName.toLowerCase();
            // always favor a perfect name match
            if (libName.equals(name)) {
            } else if (oldName.equals(name)) {
                useThisLib = false;
            // check for "-master" appended (zip file from github)
            } else if (libName.equals(name+"-master")) {
            } else if (oldName.equals(name+"-master")) {
                useThisLib = false;
            // next, favor a match with other stuff appended
            } else if (libName.startsWith(name)) {
            } else if (oldName.startsWith(name)) {
                useThisLib = false;
            // otherwise, favor a match with stuff prepended
            } else if (libName.endsWith(name)) {
            } else if (oldName.endsWith(name)) {
                useThisLib = false;
            // as a last resort, match if stuff prepended and appended
            } else if (libName.contains(name)) {
            } else if (oldName.contains(name)) {
                useThisLib = false;
            // repeat all the above tests, with case insensitive matching
            } else if (libName_lc.equals(name_lc)) {
            } else if (oldName_lc.equals(name_lc)) {
                useThisLib = false;
            } else if (libName_lc.equals(name_lc+"-master")) {
            } else if (oldName_lc.equals(name_lc+"-master")) {
                useThisLib = false;
            } else if (libName_lc.startsWith(name_lc)) {
            } else if (oldName_lc.startsWith(name_lc)) {
                useThisLib = false;
            } else if (libName_lc.endsWith(name_lc)) {
            } else if (oldName_lc.endsWith(name_lc)) {
                useThisLib = false;
            } else if (libName_lc.contains(name_lc)) {
            } else if (oldName_lc.contains(name_lc)) {
                useThisLib = false;
            } else {
              // none of these tests matched, so just default to "libName".
            }
            if (useThisLib) {
              list.addFirst(lib);
            } else {
              list.addLast(lib);
            }
          }
        }
      } catch (IOException e) {
        showWarning(tr("Error"), I18n
            .format("Unable to list header files in {0}", lib.getSrcFolder()), e);
      }
    }
  }

  static public void initParameters(String args[]) throws Exception {
    String preferencesFile = null;

    // Do a first pass over the commandline arguments, the rest of them
    // will be processed by the Base constructor. Note that this loop
    // does not look at the last element of args, to prevent crashing
    // when no parameter was specified to an option. Later, Base() will
    // then show an error for these.
    for (int i = 0; i < args.length - 1; i++) {
      if (args[i].equals("--preferences-file")) {
        ++i;
        preferencesFile = args[i];
        continue;
      }
    }

    // run static initialization that grabs all the prefs
    PreferencesData.init(absoluteFile(preferencesFile));
  }

  /**
   * Produce a sanitized name that fits our standards for likely to work.
   * <p/>
   * Java classes have a wider range of names that are technically allowed
   * (supposedly any Unicode name) than what we support. The reason for
   * going more narrow is to avoid situations with text encodings and
   * converting during the process of moving files between operating
   * systems, i.e. uploading from a Windows machine to a Linux server,
   * or reading a FAT32 partition in OS X and using a thumb drive.
   * <p/>
   * This helper function replaces everything but A-Z, a-z, and 0-9 with
   * underscores. Also disallows starting the sketch name with a digit.
   */
  static public String sanitizeName(String origName) {
    char c[] = origName.toCharArray();
    StringBuffer buffer = new StringBuffer();

    for (int i = 0; i < c.length; i++) {
      if (((c[i] >= '0') && (c[i] <= '9')) ||
          ((c[i] >= 'a') && (c[i] <= 'z')) ||
          ((c[i] >= 'A') && (c[i] <= 'Z')) ||
          ((i > 0) && (c[i] == '-')) ||
          ((i > 0) && (c[i] == '.'))) {
        buffer.append(c[i]);
      } else {
        buffer.append('_');
      }
    }
    // let's not be ridiculous about the length of filenames.
    // in fact, Mac OS 9 can handle 255 chars, though it can't really
    // deal with filenames longer than 31 chars in the Finder.
    // but limiting to that for sketches would mean setting the
    // upper-bound on the character limit here to 25 characters
    // (to handle the base name + ".class")
    if (buffer.length() > 63) {
      buffer.setLength(63);
    }
    return buffer.toString();
  }

  /**
   * Save the content of a String into a file
   * - Save the content into a temp file
   * - Find the canonical path of the file (if it's a symlink, follow it)
   * - Remove the original file
   * - Move temp file to original path
   * This ensures that the file is not getting truncated if the disk is full
   */
  static public void saveFile(String str, File file) throws IOException {
    File temp = File.createTempFile(file.getName(), null, file.getParentFile());
    // Split the file content using minimum common separator \n
    // then trim any other character (\r) so saveStrings can print it in the correct
    // format for every OS
    String strArray[] = str.split("\n");
    for (String item : strArray) {
      item.trim();
    }
    PApplet.saveStrings(temp, strArray);

    try {
      file = file.toPath().toRealPath().toFile().getCanonicalFile();
    } catch (IOException e) {
    }

    if (file.exists()) {
      boolean result = file.delete();
      if (!result) {
        throw new IOException(
      I18n.format(
        tr("Could not remove old version of {0}"),
        file.getAbsolutePath()));
      }
    }
    boolean result = temp.renameTo(file);
    if (!result) {
      throw new IOException(
    I18n.format(
      tr("Could not replace {0}"),
      file.getAbsolutePath()));
    }
  }

  static public void selectBoard(TargetBoard targetBoard) {
    TargetPlatform targetPlatform = targetBoard.getContainerPlatform();
    TargetPackage targetPackage = targetPlatform.getContainerPackage();

    PreferencesData.set("target_package", targetPackage.getId());
    PreferencesData.set("target_platform", targetPlatform.getId());
    PreferencesData.set("board", targetBoard.getId());

    File platformFolder = targetPlatform.getFolder();
    PreferencesData.set("runtime.platform.path", platformFolder.getAbsolutePath());
    PreferencesData.set("runtime.hardware.path", platformFolder.getParentFile().getAbsolutePath());
  }

  public static void selectSerialPort(String port) {
    PreferencesData.set("serial.port", port);
    BoardPort boardPort = getDiscoveryManager().find(port, true);
    if (boardPort != null) {
      PreferencesData.set("serial.port.iserial", boardPort.getPrefs().get("iserial"));
    }
    String portFile = port;
    if (port.startsWith("/dev/")) {
      portFile = portFile.substring(5);
    }
    PreferencesData.set("serial.port.file", portFile);
  }

  static public void showError(String title, String message, int exit_code) {
    showError(title, message, null, exit_code);
  }

  static public void showError(String title, String message, Throwable e) {
    notifier.showError(title, message, e, 1);
  }

  /**
   * Show an error message that's actually fatal to the program.
   * This is an error that can't be recovered. Use showWarning()
   * for errors that allow P5 to continue running.
   */
  static public void showError(String title, String message, Throwable e, int exit_code) {
    notifier.showError(title, message, e, exit_code);
  }

  /**
   * "No cookie for you" type messages. Nothing fatal or all that
   * much of a bummer, but something to notify the user about.
   */
  static public void showMessage(String title, String message) {
    notifier.showMessage(title, message);
  }

  /**
   * Non-fatal error message with optional stack trace side dish.
   */
  static public void showWarning(String title, String message, Exception e) {
    notifier.showWarning(title, message, e);
  }

}
