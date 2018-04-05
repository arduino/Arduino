package processing.app.syntax;

import org.fife.ui.rsyntaxtextarea.RSyntaxDocument;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextAreaEditorKit;
import org.fife.ui.rtextarea.RTextArea;
import org.fife.ui.rtextarea.RecordableTextAction;

import javax.swing.*;
import javax.swing.text.*;
import java.awt.event.ActionEvent;

public class SketchTextAreaEditorKit extends RSyntaxTextAreaEditorKit {

  public static final String rtaDeleteNextWordAction = "RTA.DeleteNextWordAction";
  public static final String rtaDeleteLineToCursorAction = "RTA.DeleteLineToCursorAction";
  public static final String rtaIncreaseIndentAction = "RTA.IncreaseIndentAction";

  private static final Action[] defaultActions = {
    new DeleteNextWordAction(),
    new DeleteLineToCursorAction(),
    new IncreaseIndentAction(),
    new SelectWholeLineAction(),
    new ToggleCommentAction()
  };

  @Override
  public Action[] getActions() {
    return TextAction.augmentList(super.getActions(), SketchTextAreaEditorKit.defaultActions);
  }

  public static class DeleteNextWordAction extends RecordableTextAction {

    public DeleteNextWordAction() {
      super(rtaDeleteNextWordAction);
    }

    @Override
    public void actionPerformedImpl(ActionEvent e, RTextArea textArea) {
      if (!textArea.isEditable() || !textArea.isEnabled()) {
        UIManager.getLookAndFeel().provideErrorFeedback(textArea);
        return;
      }
      try {
        int start = textArea.getSelectionStart();
        int end = getNextWordStart(textArea, start);
        if (end > start) {
          textArea.getDocument().remove(start, end - start);
        }
      } catch (BadLocationException ex) {
        UIManager.getLookAndFeel().provideErrorFeedback(textArea);
      }
    }

    @Override
    public String getMacroID() {
      return rtaDeleteNextWordAction;
    }

    /**
     * Returns the starting offset to delete.  Exists so subclasses can
     * override.
     */
    protected int getNextWordStart(RTextArea textArea, int end)
      throws BadLocationException {
      return Utilities.getNextWord(textArea, end);
    }

  }

  public static class DeleteLineToCursorAction extends RecordableTextAction {

    public DeleteLineToCursorAction() {
      super(rtaDeleteLineToCursorAction);
    }

    @Override
    public void actionPerformedImpl(ActionEvent e, RTextArea textArea) {
      if (!textArea.isEditable() || !textArea.isEnabled()) {
        UIManager.getLookAndFeel().provideErrorFeedback(textArea);
        return;
      }
      try {

        // We use the elements instead of calling getLineOfOffset(),
        // etc. to speed things up just a tad (i.e. micro-optimize).
        Document document = textArea.getDocument();
        int caretPosition = textArea.getCaretPosition();
        Element map = document.getDefaultRootElement();
        int currentLineNum = map.getElementIndex(caretPosition);
        Element currentLineElement = map.getElement(currentLineNum);
        int currentLineStart = currentLineElement.getStartOffset();
        if (caretPosition > currentLineStart) {
          document.remove(currentLineStart, caretPosition - currentLineStart);
        }

      } catch (BadLocationException ble) {
        ble.printStackTrace();
      }
    }

    @Override
    public String getMacroID() {
      return rtaDeleteLineToCursorAction;
    }

  }

  /**
   * Increases the indent of the selected or current line(s).
   */
  public static class IncreaseIndentAction extends RSyntaxTextAreaEditorKit.InsertTabAction {

    public IncreaseIndentAction() {
      super(rtaIncreaseIndentAction);
    }

    @Override
    public void actionPerformedImpl(ActionEvent e, RTextArea textArea) {
      int caretPosition = textArea.getCaretPosition();
      boolean noSelec = textArea.getSelectedText() == null;

      // if no selection, focus on first char.
      if (noSelec) {
        try {
          int line = textArea.getCaretLineNumber();
          int startOffset = textArea.getLineStartOffset(line);
          textArea.setCaretPosition(startOffset);
        } catch (BadLocationException ex) {
        }
      }

      // Insert Tab or Spaces..
      super.actionPerformedImpl(e, textArea);

      if (noSelec) {
        textArea.setCaretPosition(caretPosition + (textArea.getTabsEmulated() ? textArea.getTabSize() : 1));
      }
    }
  }

  /**
   * Selects the line around the caret.
   */
  public static class SelectWholeLineAction extends RecordableTextAction {

    public SelectWholeLineAction() {
      super(selectLineAction);
    }

    @Override
    public void actionPerformedImpl(ActionEvent e, RTextArea textArea) {
      Document document = textArea.getDocument();
      Element map = document.getDefaultRootElement();
      int currentLineNum = map.getElementIndex(textArea.getCaretPosition());
      Element currentLineElement = map.getElement(currentLineNum);
      textArea.select(currentLineElement.getStartOffset(), currentLineElement.getEndOffset());
    }

    @Override
    public final String getMacroID() {
      return DefaultEditorKit.selectLineAction;
    }

  }

  public static class ToggleCommentAction extends RecordableTextAction {

    public ToggleCommentAction() {
      super(rstaToggleCommentAction);
    }

    @Override
    public void actionPerformedImpl(ActionEvent e, RTextArea textArea) {

      if (!textArea.isEditable() || !textArea.isEnabled()) {
        UIManager.getLookAndFeel().provideErrorFeedback(textArea);
        return;
      }

      RSyntaxDocument doc = (RSyntaxDocument) textArea.getDocument();
      Element map = doc.getDefaultRootElement();
      Caret c = textArea.getCaret();
      int dot = c.getDot();
      int mark = c.getMark();
      int line1 = map.getElementIndex(dot);
      int line2 = map.getElementIndex(mark);
      int start = Math.min(line1, line2);
      int end = Math.max(line1, line2);

      org.fife.ui.rsyntaxtextarea.Token t = doc.getTokenListForLine(start);
      int languageIndex = t != null ? t.getLanguageIndex() : 0;
      String[] startEnd = doc.getLineCommentStartAndEnd(languageIndex);

      if (startEnd == null) {
        UIManager.getLookAndFeel().provideErrorFeedback(textArea);
        return;
      }

      // Don't toggle comment on last line if there is no
      // text selected on it.
      if (start != end) {
        Element elem = map.getElement(end);
        if (Math.max(dot, mark) == elem.getStartOffset()) {
          end--;
        }
      }

      textArea.beginAtomicEdit();
      try {
        boolean add = getDoAdd(doc, map, start, end, startEnd);
        for (line1 = start; line1 <= end; line1++) {
          Element elem = map.getElement(line1);
          handleToggleComment(elem, doc, startEnd, add);
        }
      } catch (BadLocationException ble) {
        ble.printStackTrace();
        UIManager.getLookAndFeel().provideErrorFeedback(textArea);
      } finally {
        textArea.endAtomicEdit();
      }

    }

    private boolean getDoAdd(Document doc, Element map, int startLine, int endLine, String[] startEnd) throws BadLocationException {
      boolean doAdd = false;
      for (int i = startLine; i <= endLine; i++) {
        Element elem = map.getElement(i);
        int start = elem.getStartOffset();
        String t = doc.getText(start, elem.getEndOffset() - start - 1).trim();
        if (!t.startsWith(startEnd[0]) ||
          (startEnd[1] != null && !t.endsWith(startEnd[1]))) {
          doAdd = true;
          break;
        }
      }
      return doAdd;
    }

    private void handleToggleComment(Element elem, Document doc, String[] startEnd, boolean add) throws BadLocationException {
      int start = elem.getStartOffset();
      int end = elem.getEndOffset() - 1;
      if (add) {
        doc.insertString(start, startEnd[0], null);
        if (startEnd[1] != null) {
          doc.insertString(end + startEnd[0].length(), startEnd[1], null);
        }
      } else {
        String text = doc.getText(start, elem.getEndOffset() - start - 1);
        start += text.indexOf(startEnd[0]);
        doc.remove(start, startEnd[0].length());
        if (startEnd[1] != null) {
          int temp = startEnd[1].length();
          doc.remove(end - startEnd[0].length() - temp, temp);
        }
      }
    }

    @Override
    public final String getMacroID() {
      return rstaToggleCommentAction;
    }

  }

}
