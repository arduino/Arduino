package processing.app.syntax.im;

import java.awt.*;
import java.awt.font.FontRenderContext;
import java.awt.font.TextAttribute;
import java.awt.font.TextLayout;
import java.text.AttributedCharacterIterator;
import java.text.AttributedString;

import javax.swing.text.BadLocationException;

import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;

/**
 * This class Manage texts from input method 
 * by begin-process-end steps.
 * 
 * First, if a user start inputing via input method, 
 * beginCompositionText is called from InputMethodSupport.
 * Second, the user continues from input method, processCompositionText is called
 * and reflect user inputs to text area.
 * Finally the user try to commit text, endCompositionText is called.
 *  
 * @author Takashi Maekawa (takachin@generative.info)
 */

public class CompositionTextManager {
  private RSyntaxTextArea textArea;
  private String prevComposeString;
  private int prevCommittedCount;
  private boolean isInputProcess;
  private int initialCaretPosition;
  public static final int COMPOSING_UNDERBAR_HEIGHT = 5;
  
  /**
   * Create text manager class with a textarea.
   * @param textArea texarea component for PDE.
   */
  public CompositionTextManager(RSyntaxTextArea textArea) {
    this.textArea = textArea;
    prevComposeString = "";
    isInputProcess = false;
    prevCommittedCount = 0;
  }

  /**
   * Get this text manager is whether in input process or not.
   */
  public boolean getIsInputProcess() {
    return isInputProcess;
  }
  /**
   * Insert full width space
   */
  public void insertFullWidthSpace() {
    initialCaretPosition = textArea.getCaretPosition();
    int layoutCaretPosition = initialCaretPosition;
    try {
      textArea.getDocument().insertString(layoutCaretPosition, "\u3000", null);
    } catch (BadLocationException e) {
      e.printStackTrace();
    }
  }

  /**
   * Called when a user begins input from input method.
   * This method initializes text manager.
   * 
   * @param text Text from InputMethodEvent.
   * @param commited_count Numbers of committed characters in text. 
   */
  public void beginCompositionText(AttributedCharacterIterator text, int committed_count) {
    isInputProcess = true;
    prevComposeString = "";
    initialCaretPosition = textArea.getCaretPosition();
    processCompositionText(text, committed_count);
  }

  /**
   * Called when a user processing input characters and
   * select candidates from input method.
   * 
   * @param text Text from InputMethodEvent.
   * @param commited_count Numbers of committed characters in text. 
   */
  public void processCompositionText(AttributedCharacterIterator text, int committed_count) {
    int layoutCaretPosition = initialCaretPosition + committed_count;
    CompositionTextPainter compositionPainter = textArea.getGraphics().getCompositionTextpainter();
    compositionPainter.setComposedTextLayout(getTextLayout(text, committed_count), layoutCaretPosition);
    int textLength = text.getEndIndex() - text.getBeginIndex() - committed_count;
    StringBuffer unCommitedStringBuf = new StringBuffer(textLength);
    char c;
    for (c = text.setIndex(committed_count); c != AttributedCharacterIterator.DONE
        && textLength > 0; c = text.next(), --textLength) {
      unCommitedStringBuf.append(c);
    }
    String unCommittedString = unCommitedStringBuf.toString();
    try {
      if(canRemovePreviousInput(committed_count)){
        textArea.getDocument().remove(layoutCaretPosition, prevComposeString.length());
      }
      textArea.getDocument().insertString(layoutCaretPosition, unCommittedString, null);
      if(committed_count > 0){
        initialCaretPosition = initialCaretPosition + committed_count;
      }
      prevComposeString = unCommittedString;
      prevCommittedCount = committed_count;
    } catch (BadLocationException e) {
      e.printStackTrace();
    }
  }

  private boolean canRemovePreviousInput(int committed_count){
    return (prevCommittedCount == committed_count || prevCommittedCount > committed_count);
  }

  /**
   * Called when a user fixed text from input method or delete all 
   * composition text. This method resets CompositionTextPainter.
   * 
   * @param text Text from InputMethodEvent.
   * @param commited_count Numbers of committed characters in text. 
   */
  public void endCompositionText(AttributedCharacterIterator text, int committed_count) {
    /*
     * If there are no committed characters, remove it all from textarea.
     * This case will happen if a user delete all composing characters by backspace or delete key. 
     * If it does, these previous characters are needed to be deleted.
     */
    if(committed_count == 0){
      removeNotCommittedText(text);
    }
    CompositionTextPainter compositionPainter = textArea.getPainter().getCompositionTextpainter();
    compositionPainter.invalidateComposedTextLayout(initialCaretPosition + committed_count);
    prevComposeString = "";
    isInputProcess = false;
  }

  private void removeNotCommittedText(AttributedCharacterIterator text){
    if (prevComposeString.length() == 0) {
      return;
    }
    try {
        textArea.getDocument().remove(initialCaretPosition, prevComposeString.length());
    } catch (BadLocationException e) {
      e.printStackTrace();
    }
  }

  private TextLayout getTextLayout(AttributedCharacterIterator text, int committed_count) {
    AttributedString composed = new AttributedString(text, committed_count, text.getEndIndex());
    Font font = textArea.getFont();
    FontRenderContext context = ((Graphics2D) (textArea.getGraphics())).getFontRenderContext();
    composed.addAttribute(TextAttribute.FONT, font);
    TextLayout layout = new TextLayout(composed.getIterator(), context);
    return layout;
  }

  private Point getCaretLocation() {
    Point loc = new Point();
    FontMetrics fm = textArea.getGraphics().getFontMetrics();
    int offsetY = fm.getHeight() - COMPOSING_UNDERBAR_HEIGHT;
    int lineIndex = textArea.getCaretLineNumber();
    loc.y = lineIndex * fm.getHeight() + offsetY;
    int offsetX = textArea.getCaretPosition()
        - textArea.getLineStartOffset(lineIndex);
    loc.x = textArea.offsetToX(lineIndex, offsetX);
    return loc;
  }

  public Rectangle getTextLocation() {
    Point caret = getCaretLocation();
    return getCaretRectangle(caret.x, caret.y);
  }

  private Rectangle getCaretRectangle(int x, int y) {
    Point origin = textArea.getLocationOnScreen();
    int height = textArea.getGraphics().getFontMetrics().getHeight();
    return new Rectangle(origin.x + x, origin.y + y, 0, height);
  }

  public AttributedCharacterIterator getCommittedText(int beginIndex, int endIndex) {
    int length = endIndex - beginIndex;
    String textAreaString = null;
    try {
      textAreaString = textArea.getText(beginIndex, length);
    } catch (BadLocationException e) {
    }
    return new AttributedString(textAreaString).getIterator();
  }

  public int getInsertPositionOffset() {
    return textArea.getCaretPosition() * -1;
  }
}
