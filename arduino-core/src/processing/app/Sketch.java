package processing.app;

import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import processing.app.helpers.FileUtils;

import static processing.app.I18n.tr;

/**
 * This represents a single sketch, consisting of one or more files.
 */
public class Sketch {

  public static final String DEFAULT_SKETCH_EXTENSION = "ino";
  public static final List<String> SKETCH_EXTENSIONS = Arrays.asList(DEFAULT_SKETCH_EXTENSION, "pde");
  public static final List<String> OTHER_ALLOWED_EXTENSIONS = Arrays.asList("c", "cpp", "h", "hh", "hpp", "s");
  public static final List<String> EXTENSIONS = Stream.concat(SKETCH_EXTENSIONS.stream(), OTHER_ALLOWED_EXTENSIONS.stream()).collect(Collectors.toList());

  /**
   * folder that contains this sketch
   */
  private File folder;

  /**
   * Name of sketch, which is the name of main file (without .pde or .java
   * extension)
   */
  private String name;

  private List<SketchFile> files = new ArrayList<SketchFile>();

  private static final Comparator<SketchFile> CODE_DOCS_COMPARATOR = new Comparator<SketchFile>() {
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
   *          The primary file for this sketch.
   */
  Sketch(File file) throws IOException {
    // get the name of the sketch by chopping .pde or .java
    // off of the main file name
    String mainFilename = primaryFile.getName();
    int suffixLength = getDefaultExtension().length() + 1;
    name = mainFilename.substring(0, mainFilename.length() - suffixLength);

    folder = new File(file.getParent());
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
      if (BaseNoGui.isSanitaryName(file.getName())) {
        FileUtils.SplitFile split = FileUtils.splitFilename(file);
        boolean isPrimary = split.basename.equals(folder.getName()) && SKETCH_EXTENSIONS.contains(split.extension);
        result.add(new SketchFile(file, isPrimary));
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

  public void addFile(SketchFile file) {
    files.add(file);
    Collections.sort(files, CODE_DOCS_COMPARATOR);
  }

  protected void replaceFile(SketchFile newCode) {
    for (SketchFile file : files) {
      if (file.getFileName().equals(newCode.getFileName())) {
        files.set(files.indexOf(file), newCode);
        return;
      }
    }
  }

  public SketchFile getFile(int i) {
    return files.get(i);
  }

  protected void removeFile(SketchFile which) {
    if (!files.remove(which))
      System.err.println("removeCode: internal error.. could not find code");
  }

  public String getName() {
    return name;
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
}
