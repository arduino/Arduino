package processing.app;

import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import processing.app.helpers.FileUtils;

import static processing.app.I18n.tr;

public class SketchData {

  public static final List<String> SKETCH_EXTENSIONS = Arrays.asList("ino", "pde");
  public static final List<String> OTHER_ALLOWED_EXTENSIONS = Arrays.asList("c", "cpp", "h", "hh", "hpp", "s");
  public static final List<String> EXTENSIONS = Stream.concat(SKETCH_EXTENSIONS.stream(), OTHER_ALLOWED_EXTENSIONS.stream()).collect(Collectors.toList());

  /**
   * main pde file for this sketch.
   */
  private File primaryFile;

  /**
   * folder that contains this sketch
   */
  private File folder;

  /**
   * data folder location for this sketch (may not exist yet)
   */
  private File dataFolder;

  /**
   * code folder location for this sketch (may not exist yet)
   */
  private File codeFolder;

  /**
   * Name of sketch, which is the name of main file (without .pde or .java
   * extension)
   */
  private String name;

  private List<SketchCode> codes = new ArrayList<SketchCode>();

  private static final Comparator<SketchCode> CODE_DOCS_COMPARATOR = new Comparator<SketchCode>() {
    @Override
    public int compare(SketchCode x, SketchCode y) {
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
  SketchData(File file) throws IOException {
    primaryFile = file;

    // get the name of the sketch by chopping .pde or .java
    // off of the main file name
    String mainFilename = primaryFile.getName();
    int suffixLength = getDefaultExtension().length() + 1;
    name = mainFilename.substring(0, mainFilename.length() - suffixLength);

    folder = new File(file.getParent());
    codeFolder = new File(folder, "code");
    dataFolder = new File(folder, "data");
    codes = listSketchFiles();
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
    List<SketchCode> reloaded = listSketchFiles();
    if (!reloaded.equals(codes)) {
      codes = reloaded;
      return true;
    }
    return false;
  }

  /**
   * Scan this sketch's directory for files that should be loaded as
   * part of this sketch. Doesn't modify this SketchData instance, just
   * returns a filtered and sorted list of File objects ready to be
   * passed to the SketchCode constructor.
   */
  private List<SketchCode> listSketchFiles() throws IOException {
    Set<SketchCode> result = new TreeSet<>(CODE_DOCS_COMPARATOR);
    for (File file : FileUtils.listFiles(folder, false, EXTENSIONS)) {
      if (BaseNoGui.isSanitaryName(file.getName())) {
        result.add(new SketchCode(file, file.equals(primaryFile)));
      } else {
        System.err.println(I18n.format(tr("File name {0} is invalid: ignored"), file.getName()));
      }
    }

    if (result.size() == 0)
      throw new IOException(tr("No valid code files found"));

    return new ArrayList<>(result);
  }

  public void save() throws IOException {
    for (SketchCode code : getCodes()) {
      if (code.isModified())
        code.save();
    }
  }

  public int getCodeCount() {
    return codes.size();
  }

  public SketchCode[] getCodes() {
    return codes.toArray(new SketchCode[0]);
  }

  /**
   * Returns the default extension for this editor setup.
   */
  public String getDefaultExtension() {
    return "ino";
  }

  /**
   * Returns a file object for the primary .pde of this sketch.
   */
  public File getPrimaryFile() {
    return primaryFile;
  }

  /**
   * Returns path to the main .pde file for this sketch.
   */
  public String getMainFilePath() {
    return primaryFile.getAbsolutePath();
    //return code[0].file.getAbsolutePath();
  }

  public void addCode(SketchCode sketchCode) {
    codes.add(sketchCode);
  }

  protected void replaceCode(SketchCode newCode) {
    for (SketchCode code : codes) {
      if (code.getFileName().equals(newCode.getFileName())) {
        codes.set(codes.indexOf(code), newCode);
        return;
      }
    }
  }

  protected void sortCode() {
    Collections.sort(codes, CODE_DOCS_COMPARATOR);
  }

  public SketchCode getCode(int i) {
    return codes.get(i);
  }

  protected void removeCode(SketchCode which) {
    if (!codes.remove(which))
      System.err.println("removeCode: internal error.. could not find code");
  }

  public int indexOfCode(SketchCode who) {
    return codes.indexOf(who);
  }

  public String getName() {
    return name;
  }

  public File getFolder() {
    return folder;
  }

  public File getDataFolder() {
    return dataFolder;
  }

  public File getCodeFolder() {
    return codeFolder;
  }
}
