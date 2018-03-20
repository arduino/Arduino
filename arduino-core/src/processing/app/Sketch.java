package processing.app;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import cc.arduino.files.DeleteFilesOnShutdown;
import processing.app.helpers.FileUtils;
import processing.app.EditorTab;

import static processing.app.I18n.tr;

/**
 * This represents a single sketch, consisting of one or more files.
 */
public class Sketch {
  public static final String DEFAULT_SKETCH_EXTENSION = "ino";
  public static final List<String> OLD_SKETCH_EXTENSIONS = Arrays.asList("pde");
  public static final List<String> SKETCH_EXTENSIONS = Stream.concat(Stream.of(DEFAULT_SKETCH_EXTENSION), OLD_SKETCH_EXTENSIONS.stream()).collect(Collectors.toList());
  public static final List<String> OTHER_ALLOWED_EXTENSIONS = Arrays.asList("c", "cpp", "h", "hh", "hpp", "s");
  public static final List<String> EXTENSIONS = Stream.concat(SKETCH_EXTENSIONS.stream(), OTHER_ALLOWED_EXTENSIONS.stream()).collect(Collectors.toList());

  /**
   * folder that contains this sketch
   */
  private File folder;

  private List<SketchFile> files = new ArrayList<>();

  private File buildPath;

  public static final Comparator<SketchFile> CODE_DOCS_COMPARATOR = new Comparator<SketchFile>() {
    @Override
    public int compare(SketchFile x, SketchFile y) {
      if (x.isPrimary() && !y.isPrimary())
        return -1;
      if (y.isPrimary() && !x.isPrimary())
        return 1;
      return x.getFileName().compareTo(y.getFileName());
    }
  };

  /**
   * Create a new SketchData object, and looks at the sketch directory
   * on disk to get populate the list of files in this sketch.
   *
   * @param file
   *          Any file inside the sketch directory.
   */
  Sketch(File file) throws IOException {
    folder = file.getParentFile();
    files = listSketchFiles(true);
  }

  static public File checkSketchFile(File file) {
    // check to make sure that this .pde file is
    // in a folder of the same name
    String fileName = file.getName();
    File parent = file.getParentFile();
    String parentName = parent.getName();
    String pdeName = parentName + ".pde";
    File altPdeFile = new File(parent, pdeName);
    String inoName = parentName + ".ino";
    File altInoFile = new File(parent, inoName);

    if (pdeName.equals(fileName) || inoName.equals(fileName))
      return file;

    if (altPdeFile.exists())
      return altPdeFile;

    if (altInoFile.exists())
      return altInoFile;

    return null;
  }

  /**
   * Reload the list of files. This checks the sketch directory on disk,
   * to see if any files were added or removed. This does *not* check
   * the contents of the files, just their presence.
   *
   * @return true when the list of files was changed, false when it was
   *         not.
   */
  public boolean reload() throws IOException {
    List<SketchFile> reloaded = listSketchFiles(false);
    if (!reloaded.equals(files)) {
      files = reloaded;
      return true;
    }
    return false;
  }

  /**
   * Scan this sketch's directory for files that should be loaded as
   * part of this sketch. Doesn't modify this SketchData instance, just
   * returns a filtered and sorted list of File objects ready to be
   * passed to the SketchFile constructor.
   *
   * @param showWarnings
   *          When true, any invalid filenames will show a warning.
   */
  private List<SketchFile> listSketchFiles(boolean showWarnings) throws IOException {
    Set<SketchFile> result = new TreeSet<>(CODE_DOCS_COMPARATOR);
    for (File file : FileUtils.listFiles(folder, false, EXTENSIONS)) {
      if (BaseNoGui.isSanitaryName(FileUtils.splitFilename(file).basename)) {
        result.add(new SketchFile(this, file));
      } else if (showWarnings) {
        System.err.println(I18n.format(tr("File name {0} is invalid: ignored"), file.getName()));
      }
    }

    if (result.size() == 0)
      throw new IOException(tr("No valid code files found"));

    return new ArrayList<>(result);
  }

  /**
   * Create the data folder if it does not exist already. As a
   * convenience, it also returns the data folder, since it's likely
   * about to be used.
   */
  public File prepareDataFolder() {
    File dataFolder = getDataFolder();
    if (!dataFolder.exists()) {
      dataFolder.mkdirs();
    }
    return dataFolder;
  }

  public void save() throws IOException {
    for (SketchFile file : getFiles()) {
      if (file.isModified())
        file.save();
    }
  }

  private final String buildToolsHeader = "\n/** Arduino IDE Board Tool details\n";
  private final String buildToolsHeaderEnd = "*/";

  /**
   * Checks the code for a valid build tool header
   * @param program The code to scan for the build tools
   * @return True if the build tool header was found ONE time. Returns false if found MORE than one time, or not found at all.
   */
  private boolean containsBuildSettings(String program){
    return program.contains(buildToolsHeader) && (program.indexOf(buildToolsHeader) == program.lastIndexOf(buildToolsHeader));
  }

  /**
   * This function returns the index of the Nth occurrence of the substring in the specified string (http://programming.guide/java/nth-occurrence-in-string.html)
   * @param str The string to find the Nth occurrence in
   * @param substr The string to find
   * @param n The occurrence number you'd like to find
   * @return
   */
  private static int ordinalIndexOf(String str, String substr, int n) {
    int pos = str.indexOf(substr);
    while (--n > 0 && pos != -1)
      pos = str.indexOf(substr, pos + 1);
    return pos;
  }

  private void removeBuildSettingsHeader(EditorTab tab){
    if(tab.getText().contains(buildToolsHeader)) {
      int headerStartIndex = tab.getText().indexOf(buildToolsHeader);
      int headerStopIndex = tab.getText().indexOf(buildToolsHeaderEnd);
      if (headerStartIndex > headerStopIndex) {
        System.err.println("The build tool header is not the first comment block in your file! Please fix this.");
        for (int i = 0; i < tab.getText().length(); i++) {
          if (headerStartIndex < ordinalIndexOf(tab.getText(), buildToolsHeaderEnd, i)) {
            headerStopIndex = ordinalIndexOf(tab.getText(), buildToolsHeaderEnd, i);
            break;
          }
        }
      }
      String header = tab.getText().substring(headerStartIndex, headerStopIndex + buildToolsHeaderEnd.length());
      tab.setText(tab.getText().replace(header, ""));
      // Run this method again so we are sure that there aren't any headers left
      removeBuildSettingsHeader(tab);
    }
  }

  /**
   * This checks the program code for a valid build tool settings header and returns the LinkedHashMap with the setting name and the value.
   * The build tools header should not be changed or manipulated by the pre-processor as the pre-processors output may depend on the build tools.
   * @param program The program code
   * @return The {@code LinkedHashMap} with the settings and their values of the <b>first</b> header that was found in the program code
   */
  public LinkedHashMap<String, String> getBuildSettingsFromProgram(String program){
    LinkedHashMap<String, String> buildSettings = new LinkedHashMap<>();
    if(containsBuildSettings(program)){
        int headerStartIndex = program.indexOf(buildToolsHeader);
        int headerStopIndex = program.indexOf(buildToolsHeaderEnd);
        if(headerStartIndex > headerStopIndex){
          System.err.println("The build tool header is not the first comment block in your file! Please fix this.");
          for(int i = 0; i < program.length(); i++){
            if(headerStartIndex < ordinalIndexOf(program, buildToolsHeaderEnd, i)){
              headerStopIndex = ordinalIndexOf(program, buildToolsHeaderEnd, i);
              break;
            }
          }
        }
        String header = program.substring(headerStartIndex + buildToolsHeader.length(), headerStopIndex);

        String[] headerLines = header.split("\n");

        for(int line = 0; line < headerLines.length; line++){
          String[] setting = headerLines[line].replace("*","").trim().split(": ");
          if(headerLines[line].indexOf(": ") != (headerLines[line].length() -1)){
            // The value of the setting is not empty
            buildSettings.put(setting[0].trim(), setting[1].trim());
          }else{
            buildSettings.put(setting[0], "");
          }
        }
    }else{
      if(!program.contains(buildToolsHeader)){
        // There are multiple headers, remove them
        // TODO Create a dialog asking the user to add a build header to the file
      }
    }

    return buildSettings;
  }

  private boolean isBuildSettingsEqual(LinkedHashMap<String,String> first, LinkedHashMap<String, String> second){
    return first.keySet().containsAll(second.keySet()) && first.values().containsAll(second.values());
  }

  public void setBuildSettings(EditorTab tab, LinkedHashMap<String, String> buildSettings){
    if(tab.getSketch().getSketch() != this){
      return;
    }

    String customBoardSettingsHeader = buildSettings.entrySet().stream().map(entry-> String.format(" * %s: %s\n", entry.getKey(), entry.getValue())).collect(Collectors.joining("", buildToolsHeader, "*/"));
    if(!isBuildSettingsEqual(getBuildSettingsFromProgram(tab.getText()),buildSettings)){
      removeBuildSettingsHeader(tab);
      tab.setText(customBoardSettingsHeader + ((tab.getText().charAt(0) == '\n') ? "" : "\n") + tab.getText());
    }
  }

  public int getCodeCount() {
    return files.size();
  }

  public SketchFile[] getFiles() {
    return files.toArray(new SketchFile[0]);
  }

  /**
   * Returns a file object for the primary .pde of this sketch.
   */
  public SketchFile getPrimaryFile() {
    return files.get(0);
  }

  /**
   * Returns path to the main .pde file for this sketch.
   */
  public String getMainFilePath() {
    return getPrimaryFile().getFile().getAbsolutePath();
  }

  public SketchFile getFile(int i) {
    return files.get(i);
  }

  /**
   * Gets the build path for this sketch. The first time this is called,
   * a build path is generated and created and the same path is returned
   * on all subsequent calls.
   *
   * This takes into account the build.path preference. If it is set,
   * that path is always returned, and the directory is *not* deleted on
   * shutdown. If the preference is not set, a random pathname in a
   * temporary directory is generated, which is automatically deleted on
   * shutdown.
   */
  public File getBuildPath() throws IOException {
    if (buildPath == null) {
      if (PreferencesData.get("build.path") != null) {
        buildPath = BaseNoGui.absoluteFile(PreferencesData.get("build.path"));
        Files.createDirectories(buildPath.toPath());
      } else {
        buildPath = FileUtils.createTempFolder("arduino_build_");
        DeleteFilesOnShutdown.add(buildPath);
      }
    }

    return buildPath;
  }

  protected void removeFile(SketchFile which) {
    if (!files.remove(which))
      System.err.println("removeCode: internal error.. could not find code");
  }

  public String getName() {
    return folder.getName();
  }

  public File getFolder() {
    return folder;
  }

  public File getDataFolder() {
    return new File(folder, "data");
  }

  /**
   * Is any of the files in this sketch modified?
   */
  public boolean isModified() {
    for (SketchFile file : files) {
      if (file.isModified())
        return true;
    }
    return false;
  }

  /**
   * Finds the file with the given filename and returns its index.
   * Returns -1 when the file was not found.
   */
  public int findFileIndex(File filename) {
    int i = 0;
    for (SketchFile file : files) {
      if (file.getFile().equals(filename))
        return i;
      i++;
    }
    return -1;
  }

  /**
   * Check if renaming/saving this sketch to the given folder would
   * cause a problem because: 1. The new folder already exists 2.
   * Renaming the primary file would cause a conflict with an existing
   * file. If so, an IOEXception is thrown. If not, the name of the new
   * primary file is returned.
   */
  protected File checkNewFoldername(File newFolder) throws IOException {
    String newPrimary = FileUtils.addExtension(newFolder.getName(), DEFAULT_SKETCH_EXTENSION);
    // Verify the new folder does not exist yet
    if (newFolder.exists()) {
      String msg = I18n.format(tr("Sorry, the folder \"{0}\" already exists."), newFolder.getAbsoluteFile());
      throw new IOException(msg);
    }

    // If the folder is actually renamed (as opposed to moved somewhere
    // else), check for conflicts using the new filename, but the
    // existing folder name.
    if (!newFolder.getName().equals(folder.getName()))
      checkNewFilename(new File(folder, newPrimary));

    return new File(newFolder, newPrimary);
  }

  /**
   * Check if renaming or adding a file would cause a problem because
   * the file already exists in this sketch. If so, an IOEXception is
   * thrown.
   *
   * @param newFile
   *          The filename of the new file, or the new name for an
   *          existing file.
   */
  protected void checkNewFilename(File newFile) throws IOException {
    // Verify that the sketch doesn't have a filem with the new name
    // already, other than the current primary (index 0)
    if (findFileIndex(newFile) >= 0) {
      String msg = I18n.format(tr("The sketch already contains a file named \"{0}\""), newFile.getName());
      throw new IOException(msg);
    }

  }

  /**
   * Rename this sketch' folder to the given name. Unlike saveAs(), this
   * moves the sketch directory, not leaving anything in the old place.
   * This operation does not *save* the sketch, so the files on disk are
   * moved, but not modified.
   *
   * @param newFolder
   *          The new folder name for this sketch. The new primary
   *          file's name will be derived from this.
   *
   * @throws IOException
   *           When a problem occurs. The error message should be
   *           already translated.
   */
  public void renameTo(File newFolder) throws IOException {
    // Check intended rename (throws if there is a problem)
    File newPrimary = checkNewFoldername(newFolder);

    // Rename the sketch folder
    if (!getFolder().renameTo(newFolder))
      throw new IOException(tr("Failed to rename sketch folder"));

    folder = newFolder;

    // Tell each file about its new name
    for (SketchFile file : files)
      file.renamedTo(new File(newFolder, file.getFileName()));

    // And finally, rename the primary file
    getPrimaryFile().renameTo(newPrimary.getName());
  }


  public SketchFile addFile(String newName) throws IOException {
    // Check the name will not cause any conflicts
    File newFile = new File(folder, newName);
    checkNewFilename(newFile);

    // Add a new sketchFile
    SketchFile sketchFile = new SketchFile(this, newFile);
    files.add(sketchFile);
    Collections.sort(files, CODE_DOCS_COMPARATOR);

    return sketchFile;
  }

  /**
   * Save this sketch under the new name given. Unlike renameTo(), this
   * leaves the existing sketch in place.
   *
   * @param newFolder
   *          The new folder name for this sketch. The new primary
   *          file's name will be derived from this.
   *
   * @throws IOException
   *           When a problem occurs. The error message should be
   *           already translated.
   */
  public void saveAs(File newFolder) throws IOException {
    // Check intented rename (throws if there is a problem)
    File newPrimary = checkNewFoldername(newFolder);

    // Create the folder
    if (!newFolder.mkdirs()) {
      String msg = I18n.format(tr("Could not create directory \"{0}\""), newFolder.getAbsolutePath());
      throw new IOException(msg);
    }

    // Save the files to their new location
    for (SketchFile file : files) {
      if (file.isPrimary())
        file.saveAs(newPrimary);
      else
        file.saveAs(new File(newFolder, file.getFileName()));
    }


    // Copy the data folder (this may take a while.. add progress bar?)
    if (getDataFolder().exists()) {
      File newDataFolder = new File(newFolder, "data");
      // Check if data folder exits, if not try to create the data folder
      if (!newDataFolder.exists() && !newDataFolder.mkdirs()) {
        String msg = I18n.format(tr("Could not create directory \"{0}\""), newFolder.getAbsolutePath());
        throw new IOException(msg);
      }
      // Copy the data files into the new folder
      FileUtils.copy(getDataFolder(), newDataFolder);
    }
    
    // Change folder to the new folder
    folder = newFolder;
    
  }

  /**
   * Deletes this entire sketch from disk.
   */
  void delete() {
    FileUtils.recursiveDelete(folder);
  }
}
