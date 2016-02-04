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
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static processing.app.I18n.tr;


/**
 * Stores information about files in the current sketch
 */
public class Sketch {
  private final Editor editor;

  /** true if any of the files have been modified. */
  private boolean modified;

  private SketchCodeDocument current;
  private int currentIndex;

  private final SketchData data;

  /**
   * path is location of the main .pde file, because this is also
   * simplest to use when opening the file from the finder/explorer.
   */
  public Sketch(Editor _editor, File file) throws IOException {
    editor = _editor;
    data = new SketchData(file);
    load();
  }


  /**
   * Build the list of files.
   * <P>
   * Generally this is only done once, rather than
   * each time a change is made, because otherwise it gets to be
   * a nightmare to keep track of what files went where, because
   * not all the data will be saved to disk.
   * <P>
   * This also gets called when the main sketch file is renamed,
   * because the sketch has to be reloaded from a different folder.
   * <P>
   * Another exception is when an external editor is in use,
   * in which case the load happens each time "run" is hit.
   */
  private void load() throws IOException {
    load(false);
  }

  protected void load(boolean forceUpdate) throws IOException {
    data.load();

    for (SketchCode code : data.getCodes()) {
      if (code.getMetadata() == null)
        code.setMetadata(new SketchCodeDocument(this, code));
    }

    // set the main file to be the current tab
    if (editor != null) {
      setCurrentCode(currentIndex, forceUpdate);
    }
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
    editor.status.clearState();
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    if (currentIndex == 0 && editor.untitled) {
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
    String prompt = (currentIndex == 0) ?
      "New name for sketch:" : "New name for file:";
    String oldName = (current.getCode().isExtension("ino")) ?
      current.getCode().getPrettyName() : current.getCode().getFileName();
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

    // Add the extension here, this simplifies some of the logic below.
    if (newName.indexOf('.') == -1) {
      newName += "." + getDefaultExtension();
    }

    // if renaming to the same thing as before, just ignore.
    // also ignoring case here, because i don't want to write
    // a bunch of special stuff for each platform
    // (osx is case insensitive but preserving, windows insensitive,
    // *nix is sensitive and preserving.. argh)
    if (renamingCode) {
      if (newName.equalsIgnoreCase(current.getCode().getFileName()) && OSUtils.isWindows()) {
        // exit quietly for the 'rename' case.
        // if it's a 'new' then an error will occur down below
        return;
      }
    }

    newName = newName.trim();
    if (newName.equals("")) return;

    int dot = newName.indexOf('.');
    if (dot == 0) {
      Base.showWarning(tr("Problem with rename"),
                       tr("The name cannot start with a period."), null);
      return;
    }

    String newExtension = newName.substring(dot+1).toLowerCase();
    if (!validExtension(newExtension)) {
      Base.showWarning(tr("Problem with rename"),
                       I18n.format(
			 tr("\".{0}\" is not a valid extension."), newExtension
		       ), null);
      return;
    }

    // Don't let the user create the main tab as a .java file instead of .pde
    if (!isDefaultExtension(newExtension)) {
      if (renamingCode) {  // If creating a new tab, don't show this error
        if (current.getCode() == data.getCode(0)) {  // If this is the main tab, disallow
          Base.showWarning(tr("Problem with rename"),
                           tr("The main file can't use an extension.\n" +
                             "(It may be time for your to graduate to a\n" +
                             "\"real\" programming environment)"), null);
          return;
        }
      }
    }

    // dots are allowed for the .pde and .java, but not in the name
    // make sure the user didn't name things poo.time.pde
    // or something like that (nothing against poo time)
    String shortName = newName.substring(0, dot);
    String sanitaryName = BaseNoGui.sanitizeName(shortName);
    if (!shortName.equals(sanitaryName)) {
      newName = sanitaryName + "." + newExtension;
    }

    // In Arduino, we want to allow files with the same name but different
    // extensions, so compare the full names (including extensions).  This
    // might cause problems: http://dev.processing.org/bugs/show_bug.cgi?id=543
    for (SketchCode c : data.getCodes()) {
      if (newName.equalsIgnoreCase(c.getFileName()) && OSUtils.isWindows()) {
        Base.showMessage(tr("Error"),
                         I18n.format(
			   tr("A file named \"{0}\" already exists in \"{1}\""),
			   c.getFileName(),
			   data.getFolder().getAbsolutePath()
			 ));
        return;
      }
    }

    // In Arduino, don't allow a .cpp file with the same name as the sketch,
    // because the sketch is concatenated into a file with that name as part
    // of the build process.  
    if (newName.equals(getName() + ".cpp")) {
      Base.showMessage(tr("Error"),
                       tr("You can't have a .cpp file with the same name as the sketch."));
      return;
    }

    if (renamingCode && currentIndex == 0) {
      for (SketchCode code : data.getCodes()) {
        if (sanitaryName.equalsIgnoreCase(code.getPrettyName()) &&
          code.isExtension("cpp")) {
          Base.showMessage(tr("Error"),
                           I18n.format(tr("You can't rename the sketch to \"{0}\"\n"
                                           + "because the sketch already has a .cpp file with that name."),
                                       sanitaryName));
          return;
        }
      }
    }


    File newFile = new File(data.getFolder(), newName);
//    if (newFile.exists()) {  // yay! users will try anything
//      Base.showMessage("Error",
//                       "A file named \"" + newFile + "\" already exists\n" +
//                       "in \"" + folder.getAbsolutePath() + "\"");
//      return;
//    }

//    File newFileHidden = new File(folder, newName + ".x");
//    if (newFileHidden.exists()) {
//      // don't let them get away with it if they try to create something
//      // with the same name as something hidden
//      Base.showMessage("No Way",
//                       "A hidden tab with the same name already exists.\n" +
//                       "Use \"Unhide\" to bring it back.");
//      return;
//    }

    if (renamingCode) {
      if (currentIndex == 0) {
        // get the new folder name/location
        String folderName = newName.substring(0, newName.indexOf('.'));
        File newFolder = new File(data.getFolder().getParentFile(), folderName);
        if (newFolder.exists()) {
          Base.showWarning(tr("Cannot Rename"),
                           I18n.format(
			     tr("Sorry, a sketch (or folder) named " +
                               "\"{0}\" already exists."),
			     newName
			   ), null);
          return;
        }

        // unfortunately this can't be a "save as" because that
        // only copies the sketch files and the data folder
        // however this *will* first save the sketch, then rename

        // first get the contents of the editor text area
        if (current.getCode().isModified()) {
          current.getCode().setProgram(editor.getText());
          try {
            // save this new SketchCode
            current.getCode().save();
          } catch (Exception e) {
            Base.showWarning(tr("Error"), tr("Could not rename the sketch. (0)"), e);
            return;
          }
        }

        if (!current.getCode().renameTo(newFile)) {
          Base.showWarning(tr("Error"),
                           I18n.format(
			     tr("Could not rename \"{0}\" to \"{1}\""),
			     current.getCode().getFileName(),
			     newFile.getName()
			   ), null);
          return;
        }

        // save each of the other tabs because this is gonna be re-opened
        try {
          for (SketchCode code : data.getCodes()) {
            code.save();
          }
        } catch (Exception e) {
          Base.showWarning(tr("Error"), tr("Could not rename the sketch. (1)"), e);
          return;
        }

        // now rename the sketch folder and re-open
        boolean success = data.getFolder().renameTo(newFolder);
        if (!success) {
          Base.showWarning(tr("Error"), tr("Could not rename the sketch. (2)"), null);
          return;
        }
        // if successful, set base properties for the sketch

        File newMainFile = new File(newFolder, newName + ".ino");

        // having saved everything and renamed the folder and the main .pde,
        // use the editor to re-open the sketch to re-init state
        // (unfortunately this will kill positions for carets etc)
        editor.handleOpenUnchecked(newMainFile,
                                   currentIndex,
                                   editor.getSelectionStart(),
                                   editor.getSelectionStop(),
                                   editor.getScrollPosition());

        // get the changes into the sketchbook menu
        // (re-enabled in 0115 to fix bug #332)
        editor.base.rebuildSketchbookMenus();

      } else {  // else if something besides code[0]
        if (!current.getCode().renameTo(newFile)) {
          Base.showWarning(tr("Error"),
                           I18n.format(
			     tr("Could not rename \"{0}\" to \"{1}\""),
			     current.getCode().getFileName(),
			     newFile.getName()
			   ), null);
          return;
        }
      }

    } else {  // creating a new file
      try {
        if (!newFile.createNewFile()) {
          // Already checking for IOException, so make our own.
          throw new IOException(tr("createNewFile() returned false"));
        }
      } catch (IOException e) {
        Base.showWarning(tr("Error"),
			 I18n.format(
                           "Could not create the file \"{0}\" in \"{1}\"",
			   newFile,
			   data.getFolder().getAbsolutePath()
			 ), e);
        return;
      }
      ensureExistence();
      data.addCode((new SketchCodeDocument(this, newFile)).getCode());
    }

    // sort the entries
    data.sortCode();

    // set the new guy as current
    setCurrentCode(newName);

    // update the tabs
    editor.header.rebuild();
  }


  /**
   * Remove a piece of code from the sketch and from the disk.
   */
  public void handleDeleteCode() throws IOException {
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
    String prompt = (currentIndex == 0) ?
      tr("Are you sure you want to delete this sketch?") :
      I18n.format(tr("Are you sure you want to delete \"{0}\"?"), current.getCode().getFileNameWithExtensionIfNotIno());
    int result = JOptionPane.showOptionDialog(editor,
                                              prompt,
                                              tr("Delete"),
                                              JOptionPane.YES_NO_OPTION,
                                              JOptionPane.QUESTION_MESSAGE,
                                              null,
                                              options,
                                              options[0]);
    if (result == JOptionPane.YES_OPTION) {
      if (currentIndex == 0) {
        // need to unset all the modified flags, otherwise tries
        // to do a save on the handleNew()

        // delete the entire sketch
        Base.removeDir(data.getFolder());

        // get the changes into the sketchbook menu
        //sketchbook.rebuildMenus();

        // make a new sketch, and i think this will rebuild the sketch menu
        //editor.handleNewUnchecked();
        //editor.handleClose2();
        editor.base.handleClose(editor);

      } else {
        // delete the file
        if (!current.getCode().deleteFile(BaseNoGui.getBuildFolder(data).toPath())) {
          Base.showMessage(tr("Couldn't do it"),
                           I18n.format(tr("Could not delete \"{0}\"."), current.getCode().getFileName()));
          return;
        }

        // remove code from the list
        data.removeCode(current.getCode());

        // just set current tab to the main tab
        setCurrentCode(0);

        // update the tabs
        editor.header.repaint();
      }
    }
  }


  /**
   * Move to the previous tab.
   */
  public void handlePrevCode() {
    int prev = currentIndex - 1;
    if (prev < 0) prev = data.getCodeCount()-1;
    setCurrentCode(prev);
  }


  /**
   * Move to the next tab.
   */
  public void handleNextCode() {
    setCurrentCode((currentIndex + 1) % data.getCodeCount());
  }


  /**
   * Sets the modified value for the code in the frontmost tab.
   */
  public void setModified(boolean state) {
    //System.out.println("setting modified to " + state);
    //new Exception().printStackTrace();
    current.getCode().setModified(state);
    calcModified();
  }


  private void calcModified() {
    modified = false;
    for (SketchCode code : data.getCodes()) {
      if (code.isModified()) {
        modified = true;
        break;
      }
    }
    editor.header.repaint();

    if (OSUtils.isMacOS()) {
      // http://developer.apple.com/qa/qa2001/qa1146.html
      Object modifiedParam = modified ? Boolean.TRUE : Boolean.FALSE;
      editor.getRootPane().putClientProperty("windowModified", modifiedParam);
      editor.getRootPane().putClientProperty("Window.documentModified", modifiedParam);
    }
  }


  public boolean isModified() {
    return modified;
  }


  /**
   * Save all code in the current sketch.
   */
  public boolean save() throws IOException {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    // first get the contents of the editor text area
    if (current.getCode().isModified()) {
      current.getCode().setProgram(editor.getText());
    }

    // don't do anything if not actually modified
    //if (!modified) return false;

    if (isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath())) {
      Base.showMessage(tr("Sketch is read-only"),
        tr("Some files are marked \"read-only\", so you'll\n" +
          "need to re-save this sketch to another location."));
      return saveAs();
    }

    // rename .pde files to .ino
    File mainFile = new File(getMainFilePath());
    File mainFolder = mainFile.getParentFile();
    File[] pdeFiles = mainFolder.listFiles((dir, name) -> {
      return name.toLowerCase().endsWith(".pde");
    });

    if (pdeFiles != null && pdeFiles.length > 0) {
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
        for (File pdeFile : pdeFiles)
          renameCodeToInoExtension(pdeFile);
      }
    }

    data.save();
    calcModified();
    return true;
  }


  private boolean renameCodeToInoExtension(File pdeFile) {
    for (SketchCode c : data.getCodes()) {
      if (!c.getFile().equals(pdeFile))
        continue;

      String pdeName = pdeFile.getPath();
      pdeName = pdeName.substring(0, pdeName.length() - 4) + ".ino";
      return c.renameTo(new File(pdeName));
    }
    return false;
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

      fd.setDirectory(data.getFolder().getParentFile().getAbsolutePath());
    }
    String oldName = data.getName();
    fd.setFile(oldName);

    fd.setVisible(true);
    String newParentDir = fd.getDirectory();
    String newName = fd.getFile();

    // user canceled selection
    if (newName == null) return false;
    newName = Sketch.checkName(newName);

    File newFolder = new File(newParentDir, newName);

    // make sure there doesn't exist a .cpp file with that name already
    // but ignore this situation for the first tab, since it's probably being
    // resaved (with the same name) to another location/folder.
    for (int i = 1; i < data.getCodeCount(); i++) {
      SketchCode code = data.getCode(i);
      if (newName.equalsIgnoreCase(code.getPrettyName())) {
        Base.showMessage(tr("Error"),
          I18n.format(tr("You can't save the sketch as \"{0}\"\n" +
            "because the sketch already has a file with that name."), newName
          ));
        return false;
      }
    }

    // check if the paths are identical
    if (newFolder.equals(data.getFolder())) {
      // just use "save" here instead, because the user will have received a
      // message (from the operating system) about "do you want to replace?"
      return save();
    }

    // check to see if the user is trying to save this sketch inside itself
    try {
      String newPath = newFolder.getCanonicalPath() + File.separator;
      String oldPath = data.getFolder().getCanonicalPath() + File.separator;

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
      Base.removeDir(newFolder);
    }
    // in fact, you can't do this on windows because the file dialog
    // will instead put you inside the folder, but it happens on osx a lot.

    // now make a fresh copy of the folder
    newFolder.mkdirs();

    // grab the contents of the current tab before saving
    // first get the contents of the editor text area
    if (current.getCode().isModified()) {
      current.getCode().setProgram(editor.getText());
    }

    // save the other tabs to their new location
    for (SketchCode code : data.getCodes()) {
      if (data.indexOfCode(code) == 0) continue;
      File newFile = new File(newFolder, code.getFileName());
      code.saveAs(newFile);
    }

    // re-copy the data folder (this may take a while.. add progress bar?)
    if (data.getDataFolder().exists()) {
      File newDataFolder = new File(newFolder, "data");
      Base.copyDir(data.getDataFolder(), newDataFolder);
    }

    // re-copy the code folder
    if (data.getCodeFolder().exists()) {
      File newCodeFolder = new File(newFolder, "code");
      Base.copyDir(data.getCodeFolder(), newCodeFolder);
    }

    // copy custom applet.html file if one exists
    // http://dev.processing.org/bugs/show_bug.cgi?id=485
    File customHtml = new File(data.getFolder(), "applet.html");
    if (customHtml.exists()) {
      File newHtml = new File(newFolder, "applet.html");
      Base.copyFile(customHtml, newHtml);
    }

    // save the main tab with its new name
    File newFile = new File(newFolder, newName + ".ino");
    data.getCode(0).saveAs(newFile);

    editor.handleOpenUnchecked(newFile,
            currentIndex,
            editor.getSelectionStart(),
            editor.getSelectionStop(),
            editor.getScrollPosition());

    // Name changed, rebuild the sketch menus
    //editor.sketchbook.rebuildMenusAsync();
    editor.base.rebuildSketchbookMenus();

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
   * <p/>
   * .pde or .java files will be added to the sketch folder. <br/>
   * .jar, .class, .dll, .jnilib, and .so files will all
   * be added to the "code" folder. <br/>
   * All other files will be added to the "data" folder.
   * <p/>
   * If they don't exist already, the "code" or "data" folder
   * will be created.
   * <p/>
   * @return true if successful.
   */
  public boolean addFile(File sourceFile) {
    String filename = sourceFile.getName();
    File destFile = null;
    String codeExtension = null;
    boolean replacement = false;

    // if the file appears to be code related, drop it
    // into the code folder, instead of the data folder
    if (filename.toLowerCase().endsWith(".o") ||
        filename.toLowerCase().endsWith(".a") ||
        filename.toLowerCase().endsWith(".so")) {

      //if (!codeFolder.exists()) codeFolder.mkdirs();
      prepareCodeFolder();
      destFile = new File(data.getCodeFolder(), filename);

    } else {
      for (String extension : SketchData.EXTENSIONS) {
        String lower = filename.toLowerCase();
        if (lower.endsWith("." + extension)) {
          destFile = new File(data.getFolder(), filename);
          codeExtension = extension;
        }
      }
      if (codeExtension == null) {
        prepareDataFolder();
        destFile = new File(data.getDataFolder(), filename);
      }
    }

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
      boolean muchSuccess = destFile.delete();
      if (!muchSuccess) {
        Base.showWarning(tr("Error adding file"),
                         I18n.format(tr("Could not delete the existing ''{0}'' file."), filename),
			 null);
        return false;
      }
    }

    // make sure they aren't the same file
    if ((codeExtension == null) && sourceFile.equals(destFile)) {
      Base.showWarning(tr("You can't fool me"),
                       tr("This file has already been copied to the\n" +
                         "location from which where you're trying to add it.\n" +
                         "I ain't not doin nuthin'."), null);
      return false;
    }

    // in case the user is "adding" the code in an attempt
    // to update the sketch's tabs
    if (!sourceFile.equals(destFile)) {
      try {
        Base.copyFile(sourceFile, destFile);

      } catch (IOException e) {
        Base.showWarning(tr("Error adding file"),
                         I18n.format(tr("Could not add ''{0}'' to the sketch."), filename),
			 e);
        return false;
      }
    }

    if (codeExtension != null) {
      SketchCode newCode = (new SketchCodeDocument(this, destFile)).getCode();

      if (replacement) {
        data.replaceCode(newCode);

      } else {
        ensureExistence();
        data.addCode(newCode);
        data.sortCode();
      }
      setCurrentCode(filename);
      editor.header.repaint();
      if (editor.untitled) {  // TODO probably not necessary? problematic?
        // Mark the new code as modified so that the sketch is saved
        current.getCode().setModified(true);
      }

    } else {
      if (editor.untitled) {  // TODO probably not necessary? problematic?
        // If a file has been added, mark the main code as modified so
        // that the sketch is properly saved.
        data.getCode(0).setModified(true);
      }
    }
    return true;
  }


  public void importLibrary(UserLibrary lib) throws IOException {
    importLibrary(lib.getSrcFolder());
  }

  /**
   * Add import statements to the current tab for all of packages inside
   * the specified jar file.
   */
  private void importLibrary(File jarPath) throws IOException {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    String list[] = Base.headerListFromIncludePath(jarPath);
    if (list == null || list.length == 0) {
      return;
    }

    // import statements into the main sketch file (code[0])
    // if the current code is a .java file, insert into current
    //if (current.flavor == PDE) {
    if (hasDefaultExtension(current.getCode())) {
      setCurrentCode(0);
    }
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
    buffer.append(editor.getText());
    editor.setText(buffer.toString());
    editor.setSelection(0, 0);  // scroll to start
    setModified(true);
  }


  /**
   * Change what file is currently being edited. Changes the current tab index.
   * <OL>
   * <LI> store the String for the text of the current file.
   * <LI> retrieve the String for the text of the new file.
   * <LI> change the text that's visible in the text area
   * </OL>
   */
  public void setCurrentCode(int which) {
    setCurrentCode(which, false);
  }

  private void setCurrentCode(int which, boolean forceUpdate) {
    // if current is null, then this is the first setCurrent(0)
    if (!forceUpdate && (currentIndex == which) && (current != null)) {
      return;
    }

    // get the text currently being edited
    if (current != null) {
      current.getCode().setProgram(editor.getText());
      current.setSelectionStart(editor.getSelectionStart());
      current.setSelectionStop(editor.getSelectionStop());
      current.setScrollPosition(editor.getScrollPosition());
    }

    current = (SketchCodeDocument) data.getCode(which).getMetadata();
    currentIndex = which;

    if (SwingUtilities.isEventDispatchThread()) {
      editor.setCode(current);
    } else {
      try {
        SwingUtilities.invokeAndWait(() -> editor.setCode(current));
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    editor.header.rebuild();
  }


  /**
   * Internal helper function to set the current tab based on a name.
   * @param findName the file name (not pretty name) to be shown
   */
  protected void setCurrentCode(String findName) {
    for (SketchCode code : data.getCodes()) {
      if (findName.equals(code.getFileName()) ||
          findName.equals(code.getPrettyName())) {
        setCurrentCode(data.indexOfCode(code));
        return;
      }
    }
  }


  /**
   * Preprocess, Compile, and Run the current code.
   * <P>
   * There are three main parts to this process:
   * <PRE>
   *   (0. if not java, then use another 'engine'.. i.e. python)
   *
   *    1. do the p5 language preprocessing
   *       this creates a working .java file in a specific location
   *       better yet, just takes a chunk of java code and returns a
   *       new/better string editor can take care of saving this to a
   *       file location
   *
   *    2. compile the code from that location
   *       catching errors along the way
   *       placing it in a ready classpath, or .. ?
   *
   *    3. run the code
   *       needs to communicate location for window
   *       and maybe setup presentation space as well
   *       run externally if a code folder exists,
   *       or if more than one file is in the project
   *
   *    X. afterwards, some of these steps need a cleanup function
   * </PRE>
   */
  //protected String compile() throws RunnerException {

  /**
   * When running from the editor, take care of preparations before running
   * the build.
   */
  public void prepare() throws IOException {
    // make sure the user didn't hide the sketch folder
    ensureExistence();

    current.getCode().setProgram(editor.getText());

    // TODO record history here
    //current.history.record(program, SketchHistory.RUN);

    // if an external editor is being used, need to grab the
    // latest version of the code from the file.
    if (PreferencesData.getBoolean("editor.external")) {
      // history gets screwed by the open..
      //String historySaved = history.lastRecorded;
      //handleOpen(sketch);
      //history.lastRecorded = historySaved;

      // nuke previous files and settings, just get things loaded
      load(true);
    }

//    // handle preprocessing the main file's code
//    return build(tempBuildFolder.getAbsolutePath());
  }

  /**
   * Run the build inside the temporary build folder.
   * @return null if compilation failed, main class name if not
   * @throws RunnerException
   */
  public String build(boolean verbose, boolean save) throws RunnerException, PreferencesMapException, IOException {
    return build(BaseNoGui.getBuildFolder(data).getAbsolutePath(), verbose, save);
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
  private String build(String buildPath, boolean verbose, boolean save) throws RunnerException, PreferencesMapException, IOException {
    // run the preprocessor
    editor.status.progressUpdate(20);

    ensureExistence();

    CompilerProgressListener progressListener = editor.status::progressUpdate;

    boolean deleteTemp = false;
    String pathToSketch = data.getMainFilePath();
    if (isModified()) {
      // If any files are modified, make a copy of the sketch with the changes
      // saved, so arduino-builder will see the modifications.
      pathToSketch = saveSketchInTempFolder();
      deleteTemp = true;
    }

    try {
      return new Compiler(pathToSketch, data, buildPath).build(progressListener,
                                                               save);
    } finally {
      // Make sure we clean up any temporary sketch copy
      if (deleteTemp)
        FileUtils.recursiveDelete(new File(pathToSketch).getParentFile());
    }
  }

  private String saveSketchInTempFolder() throws IOException {
    File tempFolder = FileUtils.createTempFolder("arduino_modified_sketch_");
    FileUtils.copy(getFolder(), tempFolder);

    for (SketchCode sc : Stream.of(data.getCodes()).filter(SketchCode::isModified).collect(Collectors.toList())) {
      Files.write(Paths.get(tempFolder.getAbsolutePath(), sc.getFileName()), sc.getProgram().getBytes());
    }

    return Paths.get(tempFolder.getAbsolutePath(), data.getPrimaryFile().getName()).toString();
  }

  protected boolean exportApplet(boolean usingProgrammer) throws Exception {
    return exportApplet(BaseNoGui.getBuildFolder(data).getAbsolutePath(), usingProgrammer);
  }


  /**
   * Handle export to applet.
   */
  private boolean exportApplet(String appletPath, boolean usingProgrammer)
    throws Exception {

    prepare();

    // build the sketch
    editor.status.progressNotice(tr("Compiling sketch..."));
    String foundName = build(appletPath, false, false);
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
    boolean success = upload(appletPath, foundName, usingProgrammer);
    editor.status.progressUpdate(100);
    return success;
  }

  private boolean upload(String buildPath, String suggestedClassName, boolean usingProgrammer) throws Exception {

    Uploader uploader = new UploaderUtils().getUploaderByPreferences(false);

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
        success = new UploaderUtils().upload(data, uploader, buildPath, suggestedClassName, usingProgrammer, false, warningsAccumulator);
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

    return success;
  }

  /**
   * Make sure the sketch hasn't been moved or deleted by some
   * nefarious user. If they did, try to re-create it and save.
   * Only checks to see if the main folder is still around,
   * but not its contents.
   */
  private void ensureExistence() {
    if (data.getFolder().exists()) return;

    Base.showWarning(tr("Sketch Disappeared"),
                     tr("The sketch folder has disappeared.\n " +
                       "Will attempt to re-save in the same location,\n" +
                       "but anything besides the code will be lost."), null);
    try {
      data.getFolder().mkdirs();
      modified = true;

      for (SketchCode code : data.getCodes()) {
        code.save();  // this will force a save
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
    String apath = data.getFolder().getAbsolutePath();

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
    for (SketchCode code : data.getCodes()) {
      if (code.isModified() && code.fileReadOnly() && code.fileExists()) {
        return true;
      }
    }
    return false;
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  // Breaking out extension types in order to clean up the code, and make it
  // easier for other environments (like Arduino) to incorporate changes.

  /**
   * True if the specified code has the default file extension.
   */
  private boolean hasDefaultExtension(SketchCode code) {
    return code.isExtension(getDefaultExtension());
  }


  /**
   * True if the specified extension is the default file extension.
   */
  private boolean isDefaultExtension(String what) {
    return what.equals(getDefaultExtension());
  }


  /**
   * Check this extension (no dots, please) against the list of valid
   * extensions.
   */
  private boolean validExtension(String what) {
    return SketchData.EXTENSIONS.contains(what);
  }


  /**
   * Returns the default extension for this editor setup.
   */
  public String getDefaultExtension() {
    return data.getDefaultExtension();
  }

  static private final List<String> hiddenExtensions = Arrays.asList("ino", "pde");

  public List<String> getHiddenExtensions() {
    return hiddenExtensions;
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  // Additional accessors added in 0136 because of package work.
  // These will also be helpful for tool developers.


  /**
   * Returns the name of this sketch. (The pretty name of the main tab.)
   */
  public String getName() {
    return data.getName();
  }


  /**
   * Returns path to the main .pde file for this sketch.
   */
  public String getMainFilePath() {
    return data.getMainFilePath();
  }


  /**
   * Returns the sketch folder.
   */
  public File getFolder() {
    return data.getFolder();
  }


  /**
   * Create the data folder if it does not exist already. As a convenience,
   * it also returns the data folder, since it's likely about to be used.
   */
  private File prepareDataFolder() {
    if (!data.getDataFolder().exists()) {
      data.getDataFolder().mkdirs();
    }
    return data.getDataFolder();
  }


  /**
   * Create the code folder if it does not exist already. As a convenience,
   * it also returns the code folder, since it's likely about to be used.
   */
  private File prepareCodeFolder() {
    if (!data.getCodeFolder().exists()) {
      data.getCodeFolder().mkdirs();
    }
    return data.getCodeFolder();
  }


  public SketchCode[] getCodes() {
    return data.getCodes();
  }


  public int getCodeCount() {
    return data.getCodeCount();
  }


  public SketchCode getCode(int index) {
    return data.getCode(index);
  }


  public int getCodeIndex(SketchCode who) {
    return data.indexOfCode(who);
  }


  public SketchCode getCurrentCode() {
    return current.getCode();
  }


  private void setUntitled(boolean u) {
    editor.untitled = u;
  }


  public boolean isUntitled() {
    return editor.untitled;
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
          "of ASCII characters and numbers (but cannot start with a number).\n" +
          "They should also be less than 64 characters long.");
      System.out.println(msg);
    }
    return newName;
  }


}
