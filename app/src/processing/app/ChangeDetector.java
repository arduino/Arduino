package processing.app;

import java.awt.EventQueue;
import java.awt.Frame;
import java.awt.event.WindowEvent;
import java.awt.event.WindowFocusListener;
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;

import javax.swing.JOptionPane;

public class ChangeDetector implements WindowFocusListener {
  private Sketch sketch;
  private Editor editor;

  // Windows and others seem to have a few hundred ms difference in reported
  // times, so we're arbitrarily setting a gap in time here.
  // Mac OS X has an (exactly) one second difference. Not sure if it's a Java
  // bug or something else about how OS X is writing files.
  private final int MODIFIED_TIME_BUFFER = 1000;

  // Set true if the user selected 'no'. TODO this can't just skip once,
  // because subsequent returns to the window w/o saving will keep firing.
  private boolean skip = false;


  public ChangeDetector(Editor editor) {    
    this.sketch = editor.sketch;
    this.editor = editor;
  }


  @Override
  public void windowGainedFocus(WindowEvent e) {
    // Keep the listener instantiated and check this to avoid a maze of
    // adding and removing and re-adding with Preferences changes.
    //TODO add preference
    if (true || Preferences.getBoolean("editor.watcher")) {
      // if they selected no, skip the next focus event
      if (skip) {
        skip = false;

      } else {
        new Thread(new Runnable() {
          @Override
          public void run() {
            checkFileChange();
          }
        }).start();
      }
    }
  }

  @Override
  public void windowLostFocus(WindowEvent e) {
    // Shouldn't need to do anything here, and not storing anything here b/c we
    // don't want to assume a loss of focus is required before change detection
  }


  private void checkFileChange() {
    
    //check that the content of each of the files in sketch matches what is in memory
    if (sketch == null) {
      return;
    }

    // check file count first
    File sketchFolder = sketch.getFolder();
    File[] sketchFiles = sketchFolder.listFiles(new FilenameFilter() {
      
      @Override
      public boolean accept(File dir, String name) {
        for (String s : SketchData.EXTENSIONS) {
          if (name.toLowerCase().endsWith(s.toLowerCase())) {
            return true;
          }
        }
        return false;
      }
    });
    int fileCount = sketchFiles.length;

    if (fileCount != sketch.getCodeCount()) {
      // if they chose to reload and there aren't any files left
      if (reloadSketch(null) && fileCount < 1) {
        try {
          //make a blank file
          sketch.getCode(0).getFile().createNewFile();
        } catch (Exception e1) {
          //if that didn't work, tell them it's un-recoverable
          showErrorEDT("Reload failed", "The sketch contains no code files.", e1);
          //don't try to reload again after the double fail
          //this editor is probably trashed by this point, but a save-as might be possible
          skip = true;
          return;
        }
        //it's okay to do this without confirmation, because they already confirmed to deleting the unsaved changes above
        try{
          sketch.load(true);
        }catch(IOException e){
          showWarningEDT("Reload Failed", "The reload has failed!\nSketch will not be reloaded and may work incorrectly!");
          return;
        }
        showWarningEDT("Modified Reload",
                         "You cannot delete the last code file in a sketch.\n" +
                         "A new blank sketch file has been generated for you.");

      }
      return;
    }


    SketchCode[] codes = sketch.getCodes();
    for (SketchCode sc : codes) {
      File sketchFile = sc.getFile();
      if (sketchFile.exists()) {
        long diff = sketchFile.lastModified() - sc.lastModified();
        if (diff > MODIFIED_TIME_BUFFER) {
          //System.out.println(sketchFile.getName() + " " + diff);
          reloadSketch(sc);
          //return;
        }
      } else {
        // If a file in the sketch was not found, then it must have been
        // deleted externally, so reload the sketch.
        reloadSketch(sc);
        //return;
      }
    }
  }


  private void setSketchCodeModified(SketchCode sc) {
    sc.setModified(true);
    sketch.setModified(true);
  }


  /**
   * @param changed The file that was known to be modified
   * @return true if the files in the sketch have been reloaded
   */
  private boolean reloadSketch(SketchCode changed) {
    int response = blockingYesNoPrompt(editor,
                                       "File Modified",
                                       "Your sketch has been modified externally.\n" +
                                       "Would you like to reload the sketch?",
                                       "If you reload the sketch, any unsaved changes will be lost.");
    if (response == 0) {
      try{
        sketch.load(true);
      }catch(IOException e){
        showWarningEDT("Reload Failed", "The reload has failed!\nSketch will not be reloaded (has it been deleted externally?) and may work incorrectly!");
        return false;
      }
      rebuildHeaderEDT();
      return true;
    }

    // they said no (or canceled), make it possible to stop the msgs by saving
    if (changed != null) {
      //set it to be modified so that it will actually save to disk when the user saves from inside processing
      setSketchCodeModified(changed);

    } else {
      // Because the number of files changed, they may be working with a file
      // that doesn't exist any more. So find the files that are missing,
      // and mark them as modified so that the next "Save" will write them.
      for (SketchCode sc : sketch.getCodes()) {
        if (!sc.getFile().exists()) {
          setSketchCodeModified(sc);
        }
      }
      // If files were simply added, then nothing needs done
    }
    rebuildHeaderEDT();
    skip = true;
    return false;
  }


  private void showErrorEDT(final String title, final String message,
                              final Exception e) {
    EventQueue.invokeLater(new Runnable() {
      @Override
      public void run() {
        Base.showError(title, message, e);
      }
    });
  }


  private void showWarningEDT(final String title, final String message) {
    EventQueue.invokeLater(new Runnable() {
      @Override
      public void run() {
        Base.showWarning(title, message,null);
      }
    });
  }


  private int blockingYesNoPrompt(final Frame editor, final String title,
                                  final String message1,
                                  final String message2) {
    final int[] result = { -1 };  // yuck
    final Object[] options = { "Yes", "No" };
    try {
      //have to wait for a response on this one
      EventQueue.invokeAndWait(new Runnable() {
        @Override
        public void run() {
          result[0] = JOptionPane
              .showOptionDialog(editor, message1 + "\n" + message2, title,
                                JOptionPane.YES_NO_OPTION,
                                JOptionPane.QUESTION_MESSAGE, null, options,
                                options[0]);
        }
      });
    } catch (InvocationTargetException e) {
      //occurs if Base.showYesNoQuestion throws an error, so, shouldn't happen
      e.getTargetException().printStackTrace();
    } catch (InterruptedException e) {
      //occurs if the EDT is interrupted, so, shouldn't happen
      e.printStackTrace();
    }
    return result[0];
  }


  private void rebuildHeaderEDT() {
    EventQueue.invokeLater(new Runnable() {
      @Override
      public void run() {
        editor.header.rebuild();
      }
    });
  }
}
