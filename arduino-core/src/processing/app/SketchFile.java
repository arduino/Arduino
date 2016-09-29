/*
  SketchFile - data class for a single file inside a sketch
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

package processing.app;

import processing.app.helpers.FileUtils;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static processing.app.I18n.tr;

/**
 * Represents a file within a sketch.
 */
public class SketchFile {

  /**
   * File object for where this code is located
   */
  private File file;

  /**
   * The sketch this file belongs to.
   */
  private Sketch sketch;

  /**
   * Is this the primary file in the sketch?
   */
  private boolean primary;

  /**
   * Interface for an in-memory storage of text file contents. This is
   * intended to allow a GUI to keep modified text in memory, and allow
   * SketchFile to check for changes when needed.
   */
  public static interface TextStorage {
    /** Get the current text */
    public String getText();

    /**
     * Is the text modified externally, after the last call to
     * clearModified() or setText()?
     */
    public boolean isModified();

    /** Clear the isModified() result value */
    public void clearModified();
  }

  /**
   * A storage for this file's text. This can be set by a GUI, so we can
   * have access to any modified version of the file. This can be null,
   * in which case the file is never modified, and saving is a no-op.
   */
  private TextStorage storage;

  /**
   * Create a new SketchFile
   *
   * @param sketch
   *          The sketch this file belongs to
   * @param file
   *          The file this SketchFile represents
   * @param primary
   *          Whether this file is the primary file of the sketch
   */
  public SketchFile(Sketch sketch, File file) {
    this.sketch = sketch;
    this.file = file;
    FileUtils.SplitFile split = FileUtils.splitFilename(file);
    this.primary = split.basename.equals(sketch.getFolder().getName())
        && Sketch.SKETCH_EXTENSIONS.contains(split.extension);
  }

  /**
   * Set an in-memory storage for this file's text, that will be queried
   * on compile, save, and whenever the text is needed. null can be
   * passed to detach any attached storage.
   */
  public void setStorage(TextStorage text) {
    this.storage = text;
  }


  public File getFile() {
    return file;
  }

  /**
   * Is this the primary file in the sketch?
   */
  public boolean isPrimary() {
    return primary;
  }

  protected boolean fileExists() {
    return file.exists();
  }


  protected boolean fileReadOnly() {
    return !file.canWrite();
  }


  protected boolean delete(Path tempBuildFolder) throws IOException {
    if (!file.delete()) {
      return false;
    }

    List<Path> tempBuildFolders = Stream.of(tempBuildFolder, tempBuildFolder.resolve("sketch"))
        .filter(path -> Files.exists(path)).collect(Collectors.toList());

    for (Path folder : tempBuildFolders) {
      if (!deleteCompiledFilesFrom(folder)) {
        return false;
      }
    }

    sketch.removeFile(this);

    return true;
  }

  private boolean deleteCompiledFilesFrom(Path tempBuildFolder) throws IOException {
    List<Path> compiledFiles = Files.list(tempBuildFolder)
      .filter(pathname -> pathname.getFileName().toString().startsWith(getFileName()))
      .collect(Collectors.toList());

    for (Path compiledFile : compiledFiles) {
      try {
        Files.delete(compiledFile);
      } catch (IOException e) {
        return false;
      }
    }
    return true;
  }

  /**
   * Rename the given file to get the given name.
   *
   * @param newName
   *          The new name, including extension, excluding directory
   *          name.
   * @throws IOException
   *           When a problem occurs, or is expected to occur. The error
   *           message should be already translated.
   */
  public void renameTo(String newName) throws IOException {
    File newFile = new File(file.getParentFile(), newName);
    sketch.checkNewFilename(newFile);
    if (file.renameTo(newFile)) {
      renamedTo(newFile);
    } else {
      String msg = I18n.format(tr("Failed to rename \"{0}\" to \"{1}\""), file.getName(), newName);
      throw new IOException(msg);
    }
  }

  /**
   * Should be called when this file was renamed and renameTo could not
   * be used (e.g. when renaming the entire sketch directory).
   */
  protected void renamedTo(File what) {
    file = what;
  }

  /*
   * Returns the filename include extension.
   */
  public String getFileName() {
    return file.getName();
  }

  /**
   * Returns the filename without extension for normal sketch files
   * (Sketch.SKETCH_EXTENSIONS) and the filename with extension for all
   * others.
   */
  public String getPrettyName() {
    if (isExtension(Sketch.SKETCH_EXTENSIONS))
      return getBaseName();
    else
      return getFileName();
  }

  /**
   * Returns the filename without extension
   */
  public String getBaseName() {
    return FileUtils.splitFilename(file).basename;
  }

  public boolean isExtension(String... extensions) {
    return isExtension(Arrays.asList(extensions));
  }

  public boolean isExtension(List<String> extensions) {
    return FileUtils.hasExtension(file, extensions);
  }


  public String getProgram() {
    if (storage != null)
      return storage.getText();

    return null;
  }


  public boolean isModified() {
    if (storage != null)
      return storage.isModified();
    return false;
  }

  @Override
  public boolean equals(Object o) {
    return (o instanceof SketchFile) && file.equals(((SketchFile) o).file);
  }

  /**
   * Load this piece of code from a file and return the contents. This
   * completely ignores any changes in the linked storage, if any, and
   * just directly reads the file.
   */
  public String load() throws IOException {
    String text = BaseNoGui.loadFile(file);

    if (text == null) {
      throw new IOException();
    }

    if (text.indexOf('\uFFFD') != -1) {
      System.err.println(
        I18n.format(
          tr("\"{0}\" contains unrecognized characters. " +
            "If this code was created with an older version of Arduino, " +
            "you may need to use Tools -> Fix Encoding & Reload to update " +
            "the sketch to use UTF-8 encoding. If not, you may need to " +
            "delete the bad characters to get rid of this warning."),
          file.getName()
        )
      );
      System.err.println();
    }
    return text;
  }


  /**
   * Save this piece of code, regardless of whether the modified
   * flag is set or not.
   */
  public void save() throws IOException {
    if (storage == null)
      return; /* Nothing to do */

    BaseNoGui.saveFile(storage.getText(), file);
    storage.clearModified();
  }


  /**
   * Save this file to another location, used by Sketch.saveAs()
   */
  public void saveAs(File newFile) throws IOException {
    if (storage == null)
      return; /* Nothing to do */

    BaseNoGui.saveFile(storage.getText(), newFile);
    renamedTo(newFile);
  }
}
