package processing.app;

import java.io.File;

import javax.swing.Action;
import javax.swing.SwingUtilities;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.Document;
import javax.swing.undo.UndoManager;

import org.fife.ui.rtextarea.RTextArea;

public class SketchCodeDocument implements SketchDocumentProvider, DocumentListener{

  private SketchCode code;
  private Document document;

  // Undo Manager for this tab, each tab keeps track of their own Editor.undo
  // will be set to this object when this code is the tab that's currently the
  // front.
  private UndoManager undo;

  // saved positions from last time this tab was used
  private int selectionStart;
  private int selectionStop;
  private int scrollPosition;

  public SketchCodeDocument(SketchCode code) {
    this.code = code;
    this.code.setMetadata(this);
  }

  public SketchCodeDocument(BaseSketch sketch, File file) {
    this.code = new SketchCode(sketch, file, this);
  }

  public UndoManager getUndo() {
    return undo;
  }

  public void setUndo(UndoManager undo) {
    this.undo = undo;
  }

  public int getSelectionStart() {
    return selectionStart;
  }

  public void setSelectionStart(int selectionStart) {
    this.selectionStart = selectionStart;
  }

  public int getSelectionStop() {
    return selectionStop;
  }

  public void setSelectionStop(int selectionStop) {
    this.selectionStop = selectionStop;
  }

  public int getScrollPosition() {
    return scrollPosition;
  }

  public void setScrollPosition(int scrollPosition) {
    this.scrollPosition = scrollPosition;
  }

  public SketchCode getCode() {
    return code;
  }

  public void setCode(SketchCode code) {
    this.code = code;
  }

  public Document getDocument() {
    return document;
  }

  public void setDocument(Document document) {
    this.document = document;
    document.addDocumentListener(this);
  }
  
  /**
   * Check for changes in text.
   * This use UndoManager actions to track if has modifications. 
   */
  private void checkModifiedState(){
    if(undo != null){
      
      SwingUtilities.invokeLater(new Runnable() {
        
        @Override
        public void run() {
          // HACK: get menu state from RSyntaxTextArea
          Action a = RTextArea.getAction(RTextArea.UNDO_ACTION);
          if(a.isEnabled()){
            code.setModified(true);
          }else{
            // TODO: need re-check libraries changes ??
            code.setModified(false);
          }
        }
      });
    }else{
      code.setModified(true);
    }
  }

  @Override
  public void insertUpdate(DocumentEvent e) {
    checkModifiedState();
  }


  @Override
  public void removeUpdate(DocumentEvent e) {
    checkModifiedState();
  }


  @Override
  public void changedUpdate(DocumentEvent e) {
     // Callback for when styles in the current document change.
     // This method is never called.
  }
  
}
