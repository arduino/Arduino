/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-10 Ben Fry and Casey Reas
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

import cc.arduino.Compiler;
import cc.arduino.CompilerProgressListener;
import cc.arduino.UploaderUtils;
import cc.arduino.packages.Uploader;
import processing.app.debug.RunnerException;
import processing.app.forms.PasswordAuthorizationDialog;
import processing.app.helpers.FileUtils;
import processing.app.helpers.OSUtils;
import processing.app.helpers.PreferencesMapException;
import processing.app.packages.LibraryList;
import processing.app.packages.UserLibrary;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static processing.app.I18n.tr;


/**
 * Handles various tasks related to a sketch, in response to user inter-action.
 */
public class SketchController {
  private final Editor editor;
  private final Sketch sketch;

  public SketchController(Editor _editor, Sketch _sketch) {
    editor = _editor;
    sketch = _sketch;
  }

  private boolean renamingCode;

  /**
   * Handler for the New Code menu option.
   */
  public void handleNewCode() {
    editor.status.clearState();
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    // if read-only, give an error
    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath())) {
      // if the files are read-only, need to first do a "save as".
      Base.showMessage(tr("Sketch is Read-Only"),
                       tr("Some files are marked \"read-only\", so you'll\n" +
                         "need to re-save the sketch in another location,\n" +
                         "and try again."));
      return;
    }

    renamingCode = false;
    editor.status.edit(tr("Name for new file:"), "");
  }


  /**
   * Handler for the Rename Code menu option.
   */
  public void handleRenameCode() {
    SketchFile current = editor.getCurrentTab().getSketchFile();

    editor.status.clearState();
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    if (current.isPrimary() && editor.untitled) {
      Base.showMessage(tr("Sketch is Untitled"),
                       tr("How about saving the sketch first \n" +
                         "before trying to rename it?"));
      return;
    }

    // if read-only, give an error
    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath())) {
      // if the files are read-only, need to first do a "save as".
      Base.showMessage(tr("Sketch is Read-Only"),
                       tr("Some files are marked \"read-only\", so you'll\n" +
                         "need to re-save the sketch in another location,\n" +
                         "and try again."));
      return;
    }

    // ask for new name of file (internal to window)
    // TODO maybe just popup a text area?
    renamingCode = true;
    String prompt = current.isPrimary() ?
      "New name for sketch:" : "New name for file:";
    String oldName = current.getPrettyName();
    editor.status.edit(prompt, oldName);
  }


  /**
   * This is called upon return from entering a new file name.
   * (that is, from either newCode or renameCode after the prompt)
   * This code is almost identical for both the newCode and renameCode
   * cases, so they're kept merged except for right in the middle
   * where they diverge.
   */
  protected void nameCode(String newName) {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    newName = newName.trim();
    if (newName.equals("")) return;

    if (newName.charAt(0) == '.') {
      Base.showWarning(tr("Problem with rename"),
                       tr("The name cannot start with a period."), null);
      return;
    }

    FileUtils.SplitFile split = FileUtils.splitFilename(newName);
    if (split.extension.equals(""))
      split.extension = Sketch.DEFAULT_SKETCH_EXTENSION;

    if (!Sketch.EXTENSIONS.contains(split.extension.toLowerCase())) {
      String msg = I18n.format(tr("\".{0}\" is not a valid extension."),
                               split.extension);
      Base.showWarning(tr("Problem with rename"), msg, null);
      return;
    }

    // Sanitize name
    split.basename = BaseNoGui.sanitizeName(split.basename);
    newName = split.join();

    if (renamingCode) {
      SketchFile current = editor.getCurrentTab().getSketchFile();

      if (current.isPrimary()) {
        if (!split.extension.equals(Sketch.DEFAULT_SKETCH_EXTENSION)) {
          Base.showWarning(tr("Problem with rename"),
                           tr("The main file cannot use an extension"), null);
          return;
        }

        // Primary file, rename the entire sketch
        final File parent = sketch.getFolder().getParentFile();
        File newFolder = new File(parent, split.basename);
        try {
          sketch.renameTo(newFolder);
        } catch (IOException e) {
          // This does not pass on e, to prevent showing a backtrace for
          // "normal" errors.
          Base.showWarning(tr("Error"), e.getMessage(), null);
          return;
        }

        editor.base.rebuildSketchbookMenus();
      } else {
        // Non-primary file, rename just that file
        try {
          current.renameTo(newName);
        } catch (IOException e) {
          // This does not pass on e, to prevent showing a backtrace for
          // "normal" errors.
          Base.showWarning(tr("Error"), e.getMessage(), null);
          return;
        }
      }

    } else {  // creating a new file
      SketchFile file;
      try {
        file = sketch.addFile(newName);
        editor.addTab(file, "");
      } catch (IOException e) {
        // This does not pass on e, to prevent showing a backtrace for
        // "normal" errors.
        Base.showWarning(tr("Error"), e.getMessage(), null);
        return;
      }
      editor.selectTab(editor.findTabIndex(file));
    }

    // update the tabs
    editor.header.rebuild();
  }


  /**
   * Remove a piece of code from the sketch and from the disk.
   */
  public void handleDeleteCode() throws IOException {
    SketchFile current = editor.getCurrentTab().getSketchFile();
    editor.status.clearState();
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    // if read-only, give an error
    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath())) {
      // if the files are read-only, need to first do a "save as".
      Base.showMessage(tr("Sketch is Read-Only"),
                       tr("Some files are marked \"read-only\", so you'll\n" +
                       "need to re-save the sketch in another location,\n" +
                       "and try again."));
      return;
    }

    // confirm deletion with user, yes/no
    Object[] options = { tr("OK"), tr("Cancel") };
    String prompt = current.isPrimary() ?
      tr("Are you sure you want to delete this sketch?") :
      I18n.format(tr("Are you sure you want to delete \"{0}\"?"),
                                                      current.getPrettyName());
    int result = JOptionPane.showOptionDialog(editor,
                                              prompt,
                                              tr("Delete"),
                                              JOptionPane.YES_NO_OPTION,
                                              JOptionPane.QUESTION_MESSAGE,
                                              null,
                                              options,
                                              options[0]);
    if (result == JOptionPane.YES_OPTION) {
      if (current.isPrimary()) {
        sketch.delete();
        editor.base.handleClose(editor);
      } else {
        // delete the file
        if (!current.delete(sketch.getBuildPath().toPath())) {
          Base.showMessage(tr("Couldn't do it"),
                           I18n.format(tr("Could not delete \"{0}\"."), current.getFileName()));
          return;
        }

        editor.removeTab(current);

        // just set current tab to the main tab
        editor.selectTab(0);

        // update the tabs
        editor.header.repaint();
      }
    }
  }

  /**
   * Called whenever the modification status of one of the tabs changes. TODO:
   * Move this code into Editor and improve decoupling from EditorTab
   */
  public void calcModified() {
    editor.header.repaint();

    if (OSUtils.isMacOS()) {
      // http://developer.apple.com/qa/qa2001/qa1146.html
      Object modifiedParam = sketch.isModified() ? Boolean.TRUE : Boolean.FALSE;
      editor.getRootPane().putClientProperty("windowModified", modifiedParam);
      editor.getRootPane().putClientProperty("Window.documentModified", modifiedParam);
    }
  }



  /**
   * Save all code in the current sketch.
   */
  public boolean save() throws IOException {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath())) {
      Base.showMessage(tr("Sketch is read-only"),
        tr("Some files are marked \"read-only\", so you'll\n" +
          "need to re-save this sketch to another location."));
      return saveAs();
    }

    // rename .pde files to .ino
    List<SketchFile> oldFiles = new ArrayList<>();
    for (SketchFile file : sketch.getFiles()) {
      if (file.isExtension(Sketch.OLD_SKETCH_EXTENSIONS))
        oldFiles.add(file);
    }

    if (oldFiles.size() > 0) {
      if (PreferencesData.get("editor.update_extension") == null) {
        Object[] options = {tr("OK"), tr("Cancel")};
        int result = JOptionPane.showOptionDialog(editor,
          tr("In Arduino 1.0, the default file extension has changed\n" +
            "from .pde to .ino.  New sketches (including those created\n" +
            "by \"Save-As\") will use the new extension.  The extension\n" +
            "of existing sketches will be updated on save, but you can\n" +
            "disable this in the Preferences dialog.\n" +
            "\n" +
            "Save sketch and update its extension?"),
          tr(".pde -> .ino"),
          JOptionPane.OK_CANCEL_OPTION,
          JOptionPane.QUESTION_MESSAGE,
          null,
          options,
          options[0]);

        if (result != JOptionPane.OK_OPTION) return false; // save cancelled

        PreferencesData.setBoolean("editor.update_extension", true);
      }

      if (PreferencesData.getBoolean("editor.update_extension")) {
        // Do rename of all .pde files to new .ino extension
        for (SketchFile file : oldFiles) {
          File newName = FileUtils.replaceExtension(file.getFile(), Sketch.DEFAULT_SKETCH_EXTENSION);
          file.renameTo(newName.getName());
        }
      }
    }

    sketch.save();
    return true;
  }

  /**
   * Handles 'Save As' for a sketch.
   * <P>
   * This basically just duplicates the current sketch folder to
   * a new location, and then calls 'Save'. (needs to take the current
   * state of the open files and save them to the new folder..
   * but not save over the old versions for the old sketch..)
   * <P>
   * Also removes the previously-generated .class and .jar files,
   * because they can cause trouble.
   */
  protected boolean saveAs() throws IOException {
    // get new name for folder
    FileDialog fd = new FileDialog(editor, tr("Save sketch folder as..."), FileDialog.SAVE);
    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath()) || isUntitled()) {
      // default to the sketchbook folder
      fd.setDirectory(BaseNoGui.getSketchbookFolder().getAbsolutePath());
    } else {
      // default to the parent folder of where this was
      // on macs a .getParentFile() method is required

      fd.setDirectory(sketch.getFolder().getParentFile().getAbsolutePath());
    }
    String oldName = sketch.getName();
    fd.setFile(oldName);

    fd.setVisible(true);
    String newParentDir = fd.getDirectory();
    String newName = fd.getFile();

    // user canceled selection
    if (newName == null) return false;
    newName = SketchController.checkName(newName);

    File newFolder = new File(newParentDir, newName);

    // check if the paths are identical
    if (newFolder.equals(sketch.getFolder())) {
      // just use "save" here instead, because the user will have received a
      // message (from the operating system) about "do you want to replace?"
      return save();
    }

    // check to see if the user is trying to save this sketch inside itself
    try {
      String newPath = newFolder.getCanonicalPath() + File.separator;
      String oldPath = sketch.getFolder().getCanonicalPath() + File.separator;

      if (newPath.indexOf(oldPath) == 0) {
        Base.showWarning(tr("How very Borges of you"),
                tr("You cannot save the sketch into a folder\n" +
                        "inside itself. This would go on forever."), null);
        return false;
      }
    } catch (IOException e) {
      //ignore
    }

    // if the new folder already exists, then need to remove
    // its contents before copying everything over
    // (user will have already been warned)
    if (newFolder.exists()) {
      FileUtils.recursiveDelete(newFolder);
    }
    // in fact, you can't do this on windows because the file dialog
    // will instead put you inside the folder, but it happens on osx a lot.

    try {
      sketch.saveAs(newFolder);
    } catch (IOException e) {
      // This does not pass on e, to prevent showing a backtrace for "normal"
      // errors.
      Base.showWarning(tr("Error"), e.getMessage(), null);
    }
    // Name changed, rebuild the sketch menus
    //editor.sketchbook.rebuildMenusAsync();
    editor.base.rebuildSketchbookMenus();
    editor.header.rebuild();

    // Make sure that it's not an untitled sketch
    setUntitled(false);

    // let Editor know that the save was successful
    return true;
  }


  /**
   * Prompt the user for a new file to the sketch, then call the
   * other addFile() function to actually add it.
   */
  public void handleAddFile() {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    // if read-only, give an error
    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath())) {
      // if the files are read-only, need to first do a "save as".
      Base.showMessage(tr("Sketch is Read-Only"),
                       tr("Some files are marked \"read-only\", so you'll\n" +
                         "need to re-save the sketch in another location,\n" +
                         "and try again."));
      return;
    }

    // get a dialog, select a file to add to the sketch
    FileDialog fd = new FileDialog(editor, tr("Select an image or other data file to copy to your sketch"), FileDialog.LOAD);
    fd.setVisible(true);

    String directory = fd.getDirectory();
    String filename = fd.getFile();
    if (filename == null) return;

    // copy the file into the folder. if people would rather
    // it move instead of copy, they can do it by hand
    File sourceFile = new File(directory, filename);

    // now do the work of adding the file
    boolean result = addFile(sourceFile);

    if (result) {
      editor.statusNotice(tr("One file added to the sketch."));
      PreferencesData.set("last.folder", sourceFile.getAbsolutePath());
    }
  }


  /**
   * Add a file to the sketch.
   *
   * Supported code files will be copied to the sketch folder. All other files
   * will be copied to the "data" folder (which is created if it does not exist
   * yet).
   * 
   * @return true if successful.
   */
  public boolean addFile(File sourceFile) {
    String filename = sourceFile.getName();
    File destFile = null;
    boolean isData = false;
    boolean replacement = false;

    if (FileUtils.hasExtension(sourceFile, Sketch.EXTENSIONS)) {
      destFile = new File(sketch.getFolder(), filename);
    } else {
      sketch.prepareDataFolder();
      destFile = new File(sketch.getDataFolder(), filename);
      isData = true;
    }

    if (!sourceFile.equals(destFile)) {
      // The typical case here is adding a file from somewhere else.
      // This however fails if the source and destination are equal

      // check whether this file already exists
      if (destFile.exists()) {
        Object[] options = { tr("OK"), tr("Cancel") };
        String prompt = I18n.format(tr("Replace the existing version of {0}?"), filename);
        int result = JOptionPane.showOptionDialog(editor,
                                                  prompt,
                                                  tr("Replace"),
                                                  JOptionPane.YES_NO_OPTION,
                                                  JOptionPane.QUESTION_MESSAGE,
                                                  null,
                                                  options,
                                                  options[0]);
        if (result == JOptionPane.YES_OPTION) {
          replacement = true;
        } else {
          return false;
        }
      }

      // If it's a replacement, delete the old file first,
      // otherwise case changes will not be preserved.
      // http://dev.processing.org/bugs/show_bug.cgi?id=969
      if (replacement) {
        if (!destFile.delete()) {
          Base.showWarning(tr("Error adding file"),
                           I18n.format(tr("Could not delete the existing ''{0}'' file."), filename),
                           null);
          return false;
        }
      }

      // perform the copy
      try {
        Base.copyFile(sourceFile, destFile);

      } catch (IOException e) {
        Base.showWarning(tr("Error adding file"),
                         I18n.format(tr("Could not add ''{0}'' to the sketch."), filename),
                         e);
        return false;
      }
    }
    else {
      // If the source and destination are equal, a code file is handled
      //   - as a replacement, if there is a corresponding tab,
      //    (eg. user wants to update the file after modifying it outside the editor)
      //   - as an addition, otherwise.
      //    (eg. the user copied the file to the sketch folder and wants to edit it)
      // For a data file, this is a no-op.
      if (editor.findTabIndex(destFile) >= 0)
        replacement = true;
    }

    // open/refresh the tab
    if (!isData) {
      int tabIndex;
      if (replacement) {
        tabIndex = editor.findTabIndex(destFile);
        editor.getTabs().get(tabIndex).reload();
      } else {
        SketchFile sketchFile;
        try {
          sketchFile = sketch.addFile(destFile.getName());
          editor.addTab(sketchFile, null);
        } catch (IOException e) {
          // This does not pass on e, to prevent showing a backtrace for
          // "normal" errors.
          Base.showWarning(tr("Error"), e.getMessage(), null);
          return false;
        }
        tabIndex = editor.findTabIndex(sketchFile);
      }
      editor.selectTab(tabIndex);
    }
    return true;
  }


  /**
   * Add import statements to the current tab for the specified library
   */
  public void importLibrary(UserLibrary lib) throws IOException {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    List<String> list = lib.getIncludes();
    if (list == null) {
      File srcFolder = lib.getSrcFolder();
      String[] headers = Base.headerListFromIncludePath(srcFolder);
      list = Arrays.asList(headers);
    }
    if (list.isEmpty()) {
      return;
    }

    // import statements into the main sketch file (code[0])
    // if the current code is a .java file, insert into current
    //if (current.flavor == PDE) {
    SketchFile file = editor.getCurrentTab().getSketchFile();
    if (file.isExtension(Sketch.SKETCH_EXTENSIONS))
      editor.selectTab(0);

    // could also scan the text in the file to see if each import
    // statement is already in there, but if the user has the import
    // commented out, then this will be a problem.
    StringBuilder buffer = new StringBuilder();
    for (String aList : list) {
      buffer.append("#include <");
      buffer.append(aList);
      buffer.append(">\n");
    }
    buffer.append('\n');
    buffer.append(editor.getCurrentTab().getText());
    editor.getCurrentTab().setText(buffer.toString());
    editor.getCurrentTab().setSelection(0, 0);  // scroll to start
  }

  /**
   * Preprocess and compile all the code for this sketch.
   *
   * In an advanced program, the returned class name could be different,
   * which is why the className is set based on the return value.
   * A compilation error will burp up a RunnerException.
   *
   * @return null if compilation failed, main class name if not
   */
  public String build(boolean verbose, boolean save) throws RunnerException, PreferencesMapException, IOException {
    // run the preprocessor
    for (CompilerProgressListener progressListener : editor.status.getCompilerProgressListeners()){
      progressListener.progress(20);
    }

    ensureExistence();
       

    boolean deleteTemp = false;
    File pathToSketch = sketch.getPrimaryFile().getFile();
    if (sketch.isModified()) {
      // If any files are modified, make a copy of the sketch with the changes
      // saved, so arduino-builder will see the modifications.
      pathToSketch = saveSketchInTempFolder();
      deleteTemp = true;
    }

    try {
      return new Compiler(pathToSketch, sketch).build(editor.status.getCompilerProgressListeners(), save);
    } finally {
      // Make sure we clean up any temporary sketch copy
      if (deleteTemp)
        FileUtils.recursiveDelete(pathToSketch.getParentFile());
    }
  }

  private File saveSketchInTempFolder() throws IOException {
    File tempFolder = FileUtils.createTempFolder("arduino_modified_sketch_");
    FileUtils.copy(sketch.getFolder(), tempFolder);

    for (SketchFile file : Stream.of(sketch.getFiles()).filter(SketchFile::isModified).collect(Collectors.toList())) {
      Files.write(Paths.get(tempFolder.getAbsolutePath(), file.getFileName()), file.getProgram().getBytes());
    }

    return Paths.get(tempFolder.getAbsolutePath(), sketch.getPrimaryFile().getFileName()).toFile();
  }

  /**
   * Handle export to applet.
   */
  protected boolean exportApplet(boolean usingProgrammer) throws Exception {
    // build the sketch
    editor.status.progressNotice(tr("Compiling sketch..."));
    String foundName = build(false, false);
    // (already reported) error during export, exit this function
    if (foundName == null) return false;

//    // If name != exportSketchName, then that's weirdness
//    // BUG unfortunately, that can also be a bug in the preproc :(
//    if (!name.equals(foundName)) {
//      Base.showWarning("Error during export",
//                       "Sketch name is " + name + " but the sketch\n" +
//                       "name in the code was " + foundName, null);
//      return false;
//    }

    editor.status.progressNotice(tr("Uploading..."));
    boolean success = upload(foundName, usingProgrammer);
    editor.status.progressUpdate(100);
    return success;
  }

  private boolean upload(String suggestedClassName, boolean usingProgrammer) throws Exception {

    UploaderUtils uploaderInstance = new UploaderUtils();
    Uploader uploader = uploaderInstance.getUploaderByPreferences(false);

    boolean success = false;
    do {
      if (uploader.requiresAuthorization() && !PreferencesData.has(uploader.getAuthorizationKey())) {
        PasswordAuthorizationDialog dialog = new PasswordAuthorizationDialog(editor, tr("Type board password to upload a new sketch"));
        dialog.setLocationRelativeTo(editor);
        dialog.setVisible(true);

        if (dialog.isCancelled()) {
          editor.statusNotice(tr("Upload cancelled"));
          return false;
        }

        PreferencesData.set(uploader.getAuthorizationKey(), dialog.getPassword());
      }

      List<String> warningsAccumulator = new LinkedList<>();
      try {
        success = uploaderInstance.upload(sketch, uploader, suggestedClassName, usingProgrammer, false, warningsAccumulator);
      } finally {
        if (uploader.requiresAuthorization() && !success) {
          PreferencesData.remove(uploader.getAuthorizationKey());
        }
      }

      for (String warning : warningsAccumulator) {
        System.out.print(tr("Warning"));
        System.out.print(": ");
        System.out.println(warning);
      }

    } while (uploader.requiresAuthorization() && !success);

    if (!success) {
      String errorMessage = uploader.getFailureMessage();
      if (errorMessage.equals("")) {
        errorMessage = tr("An error occurred while uploading the sketch");
      }
      editor.statusError(errorMessage);
    }

    return success;
  }

  /**
   * Make sure the sketch hasn't been moved or deleted by some
   * nefarious user. If they did, try to re-create it and save.
   * Only checks to see if the main folder is still around,
   * but not its contents.
   */
  private void ensureExistence() {
    if (sketch.getFolder().exists()) return;

    Base.showWarning(tr("Sketch Disappeared"),
                     tr("The sketch folder has disappeared.\n " +
                       "Will attempt to re-save in the same location,\n" +
                       "but anything besides the code will be lost."), null);
    try {
      sketch.getFolder().mkdirs();

      for (SketchFile file : sketch.getFiles()) {
        file.save();  // this will force a save
      }
      calcModified();

    } catch (Exception e) {
      Base.showWarning(tr("Could not re-save sketch"),
                       tr("Could not properly re-save the sketch. " +
                         "You may be in trouble at this point,\n" +
                         "and it might be time to copy and paste " +
                         "your code to another text editor."), e);
    }
  }


  /**
   * Returns true if this is a read-only sketch. Used for the
   * examples directory, or when sketches are loaded from read-only
   * volumes or folders without appropriate permissions.
   */
  public boolean isReadOnly(LibraryList libraries, String examplesPath) {
    String apath = sketch.getFolder().getAbsolutePath();

    Optional<UserLibrary> libraryThatIncludesSketch = libraries.stream().filter(lib -> apath.startsWith(lib.getInstalledFolder().getAbsolutePath())).findFirst();
    if (libraryThatIncludesSketch.isPresent() && !libraryThatIncludesSketch.get().onGoingDevelopment()) {
      return true;
    }

    return sketchIsSystemExample(apath, examplesPath) || sketchFilesAreReadOnly();
  }

  private boolean sketchIsSystemExample(String apath, String examplesPath) {
    return apath.startsWith(examplesPath);
  }

  private boolean sketchFilesAreReadOnly() {
    for (SketchFile file : sketch.getFiles()) {
      if (file.isModified() && file.fileReadOnly() && file.fileExists()) {
        return true;
      }
    }
    return false;
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .



  private void setUntitled(boolean u) {
    editor.untitled = u;
  }


  public boolean isUntitled() {
    return editor.untitled;
  }

  public Sketch getSketch() {
    return sketch;
  }

  // .................................................................


  /**
   * Convert to sanitized name and alert the user
   * if changes were made.
   */
  private static String checkName(String origName) {
    String newName = BaseNoGui.sanitizeName(origName);

    if (!newName.equals(origName)) {
      String msg =
        tr("The sketch name had to be modified. Sketch names can only consist\n" +
          "of ASCII characters and numbers and be less than 64 characters long.");
      System.out.println(msg);
    }
    return newName;
  }


}
