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

import static processing.app.I18n._;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

import processing.app.debug.RunnerException;
import processing.app.helpers.PreferencesMapException;
import processing.app.packages.Library;
import processing.app.packages.LibraryList;
import processing.app.packages.SketchListener;
import br.com.criativasoft.cpluslibparser.LibraryCache;
import br.com.criativasoft.cpluslibparser.metadata.TLibrary;


/**
 * Stores information about files in the current sketch
 */
public abstract class BaseSketch {
  
  public static final String SKETCH_LIB_PREFIX = "private:sketch:"; // for autocomplete metadata

  /** true if any of the files have been modified. */
  protected boolean modified;

  protected int currentIndex;

  protected SketchData data;
  
  /** Class name for the PApplet, as determined by the preprocessor. */
  protected String appletClassName;

  private Set<SketchListener> listeners = new LinkedHashSet<SketchListener>();
   

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
  protected abstract void load() throws IOException;

  /**
   * Handler for the New Code menu option.
   */
  public abstract void handleNewCode();

  /**
   * Handler for the Rename Code menu option.
   */
  public abstract void handleRenameCode();


  /**
   * This is called upon return from entering a new file name.
   * (that is, from either newCode or renameCode after the prompt)
   * This code is almost identical for both the newCode and renameCode
   * cases, so they're kept merged except for right in the middle
   * where they diverge.
   */
  protected abstract void nameCode(String newName);


  /**
   * Remove a piece of code from the sketch and from the disk.
   */
  public abstract void handleDeleteCode();


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
  public abstract  void setModified(boolean state);


  protected abstract void calcModified();


  public boolean isModified() {
    return modified;
  }


  /**
   * Save all code in the current sketch.
   */
  public abstract boolean save() throws IOException;


  protected boolean renameCodeToInoExtension(File pdeFile) {
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
  protected abstract boolean saveAs() throws IOException;


  /**
   * Prompt the user for a new file to the sketch, then call the
   * other addFile() function to actually add it.
   */
  public abstract void handleAddFile();


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
  public abstract boolean addFile(File sourceFile);

  public void importLibrary(Library lib) throws IOException {
    importLibrary(lib.getSrcFolder());
    data.addLibrary(lib);
  }
  
  /**
   * Add import statements to the current tab for all of packages inside
   * the specified jar file.
   */
  public abstract void importLibrary(File jarPath) throws IOException;


  /**
   * Change what file is currently being edited. Changes the current tab index.
   * <OL>
   * <LI> store the String for the text of the current file.
   * <LI> retrieve the String for the text of the new file.
   * <LI> change the text that's visible in the text area
   * </OL>
   */
  public abstract void setCurrentCode(int which);


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
  public abstract void prepare() throws IOException;



  /**
   * Map an error from a set of processed .java files back to its location
   * in the actual sketch.
   * @param message The error message.
   * @param filename The .java file where the exception was found.
   * @param line Line number of the .java file for the exception (1-indexed)
   * @return A RunnerException to be sent to the editor, or null if it wasn't
   *         possible to place the exception to the sketch code.
   */
//  public RunnerException placeExceptionAlt(String message, 
//                                        String filename, int line) {
//    String appletJavaFile = appletClassName + ".java";
//    SketchCode errorCode = null;
//    if (filename.equals(appletJavaFile)) {
//      for (SketchCode code : getCode()) {
//        if (code.isExtension("ino")) {
//          if (line >= code.getPreprocOffset()) {
//            errorCode = code;
//          }
//        }
//      }
//    } else {
//      for (SketchCode code : getCode()) {
//        if (code.isExtension("java")) {
//          if (filename.equals(code.getFileName())) {
//            errorCode = code;
//          }
//        }
//      }
//    }
//    int codeIndex = getCodeIndex(errorCode);
//
//    if (codeIndex != -1) {
//      //System.out.println("got line num " + lineNumber);
//      // in case this was a tab that got embedded into the main .java
//      line -= getCode(codeIndex).getPreprocOffset();
//
//      // lineNumber is 1-indexed, but editor wants zero-indexed
//      line--;
//
//      // getMessage() will be what's shown in the editor
//      RunnerException exception = 
//        new RunnerException(message, codeIndex, line, -1);
//      exception.hideStackTrace();
//      return exception;
//    }
//    return null;
//  }


  /**
   * Run the build inside the temporary build folder.
   * @return null if compilation failed, main class name if not
   * @throws RunnerException
   */
  public abstract String build(boolean verbose) throws RunnerException, PreferencesMapException;

  /**
   * Preprocess and compile all the code for this sketch.
   *
   * In an advanced program, the returned class name could be different,
   * which is why the className is set based on the return value.
   * A compilation error will burp up a RunnerException.
   *
   * @return null if compilation failed, main class name if not
   */
  public abstract String build(String buildPath, boolean verbose) throws RunnerException, PreferencesMapException;

  protected abstract boolean exportApplet(boolean usingProgrammer) throws Exception;


  /**
   * Handle export to applet.
   */
  public abstract boolean exportApplet(String appletPath, boolean usingProgrammer)
    throws Exception;


  protected abstract boolean upload(String buildPath, String suggestedClassName, boolean usingProgrammer) throws Exception;


  public boolean exportApplicationPrompt() throws IOException, RunnerException {
    return false;
  }


  /**
   * Export to application via GUI.
   */
  protected boolean exportApplication() throws IOException, RunnerException {
    return false;
  }


  /**
   * Export to application without GUI.
   */
  public boolean exportApplication(String destPath,
                                   int exportPlatform) throws IOException, RunnerException {
    return false;
  }


  /**
   * Make sure the sketch hasn't been moved or deleted by some
   * nefarious user. If they did, try to re-create it and save.
   * Only checks to see if the main folder is still around,
   * but not its contents.
   */
  protected void ensureExistence() {
    if (data.getFolder().exists()) return;

    BaseNoGui.showWarning(_("Sketch Disappeared"),
                     _("The sketch folder has disappeared.\n " +
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
      BaseNoGui.showWarning(_("Could not re-save sketch"),
                       _("Could not properly re-save the sketch. " +
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
  public boolean isReadOnly() {
    String apath = data.getFolder().getAbsolutePath();
    for (File folder : BaseNoGui.getLibrariesPath()) {
      if (apath.startsWith(folder.getAbsolutePath()))
        return true;
    }
    if (apath.startsWith(BaseNoGui.getExamplesPath()) ||
        apath.startsWith(BaseNoGui.getSketchbookLibrariesFolder().getAbsolutePath())) {
      return true;
    }

    // canWrite() doesn't work on directories
    // } else if (!folder.canWrite()) {

    // check to see if each modified code file can be written to
    for (SketchCode code : data.getCodes()) {
      if (code.isModified() && code.fileReadOnly() && code.fileExists()) {
        // System.err.println("found a read-only file " + code[i].file);
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
  public boolean hasDefaultExtension(SketchCode code) {
    return code.isExtension(getDefaultExtension());
  }


  /**
   * True if the specified extension is the default file extension.
   */
  public boolean isDefaultExtension(String what) {
    return what.equals(getDefaultExtension());
  }


  /**
   * Check this extension (no dots, please) against the list of valid
   * extensions.
   */
  public boolean validExtension(String what) {
    return data.getExtensions().contains(what);
  }


  /**
   * Returns the default extension for this editor setup.
   */
  public String getDefaultExtension() {
    return data.getDefaultExtension();
  }

  static private List<String> hiddenExtensions = Arrays.asList("ino", "pde");

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
  public File prepareDataFolder() {
    if (!data.getDataFolder().exists()) {
      data.getDataFolder().mkdirs();
    }
    return data.getDataFolder();
  }


  /**
   * Create the code folder if it does not exist already. As a convenience,
   * it also returns the code folder, since it's likely about to be used.
   */
  public File prepareCodeFolder() {
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


  public abstract SketchCode getCurrentCode();


  public abstract void setUntitled(boolean u);


  public abstract boolean isUntitled();
  
  public abstract boolean isExternalMode();

  public String getAppletClassName2() {
    return appletClassName;
  }


  // .................................................................


  public boolean addListener(SketchListener listener){
    return listeners.add(listener);
  }

  public boolean removeListener(SketchListener listener){
    return listeners.add(listener);
  }
  
  public void notifyListeners(SketchListener.Event event, BaseSketch sketch, SketchCode code){
    
    for (SketchListener listener : listeners) {
      
      if(event == SketchListener.Event.LOAD){
        listener.onSketchLoad(sketch);
      }
      if(event == SketchListener.Event.INSERTED){
        listener.onSketchInserted(sketch, code);
      }
      if(event == SketchListener.Event.SAVED){
        listener.onSketchSaved(sketch, code);
      }
      
    }
    
  }
  
  /**
   * Convert to sanitized name and alert the user
   * if changes were made.
   */
  static public String checkName(String origName) {
    String newName = BaseNoGui.sanitizeName(origName);

    if (!newName.equals(origName)) {
      String msg =
        _("The sketch name had to be modified. Sketch names can only consist\n" +
          "of ASCII characters and numbers (but cannot start with a number).\n" +
          "They should also be less than 64 characters long.");
      System.out.println(msg);
    }
    return newName;
  }

  public SketchData getData() {
    return data;
  }

  public void setSketchMetadata( TLibrary sketchMetadata ) {
    data.setSketchMetadata(sketchMetadata);
  }

  public TLibrary getSketchMetadata() {
    return data.getSketchMetadata();
  }

  public LibraryCache getLibraryCacheContext() {
    return data.getLibraryCacheContext();
  }

  public LibraryList getImportedLibraries() {
    return data.getImportedLibraries();
  }

}
