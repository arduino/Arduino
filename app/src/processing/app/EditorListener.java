package processing.app;

import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.text.BadLocationException;

import org.fife.ui.rsyntaxtextarea.RSyntaxUtilities;
import org.fife.ui.rsyntaxtextarea.Token;

import processing.app.syntax.SketchTextArea;
import cc.arduino.packages.autocomplete.SketchCompletionProvider;

public class EditorListener implements KeyListener {
  
  private Editor editor;
  
  public EditorListener(Editor editor) {
    super();
    this.editor = editor;
  }
  
  /** ctrl-alt on windows and linux, cmd-alt on mac os x */
  static final int CTRL_ALT = ActionEvent.ALT_MASK | Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();

  static final int CTRL_SHIFT = ActionEvent.SHIFT_MASK | Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
  
  static final int CTRL = Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
  

  @Override
  public void keyTyped(KeyEvent e) {
    // TODO Auto-generated method stub
  }

  @Override
  public void keyPressed(KeyEvent event) {
    
    SketchTextArea textarea = editor.getTextArea();
    
    if (!textarea.isEditable()) return;
    
    Sketch sketch = editor.getSketch();

    char c = event.getKeyChar();
    int code = event.getKeyCode();
    
    // Navigation..
    if ((event.getModifiers() & CTRL) == CTRL && code == KeyEvent.VK_TAB) {
      sketch.handleNextCode();
    }
    
    // Navigation..
    // FIXME: not working on LINUX !!!
    if (((event.getModifiers() & CTRL_SHIFT) == CTRL_SHIFT)) {
      if(code == KeyEvent.VK_TAB)
        sketch.handlePrevCode();
    }
    
    // Navigation..
    if ((event.getModifiers() & CTRL_ALT) == CTRL_ALT) {
      if (code == KeyEvent.VK_LEFT) {
        sketch.handlePrevCode();
      } else if (code == KeyEvent.VK_RIGHT) {
        sketch.handleNextCode();
      }
    }
    
    // Generate New Variable
    if (event.isAltDown() && code == KeyEvent.VK_ENTER) {
      
      int line = textarea.getCaretLineNumber();
      
      Token tokenListForLine = textarea.getTokenListForLine(line);
      int start = RSyntaxUtilities.getNextImportantToken(tokenListForLine, textarea, line).getOffset();
      int end = textarea.getLineEndOffsetOfCurrentLine();
      
      try {
        String expression = textarea.getText(start, end - start);
        SketchCompletionProvider provider = textarea.getCompletionProvider();
        provider.generateNewVariableFor(expression, start);
        
        
        
      } catch (BadLocationException e) {}
      
    }
    
//    if (event.isAltDown() && code == KeyEvent.VK_T) {
//      int line = textarea.getCaretLineNumber();
//      textarea.setActiveLineRange(line, line + 3); 
//    }
    
  }

  @Override
  public void keyReleased(KeyEvent e) {
    // TODO Auto-generated method stub
    
  }

}