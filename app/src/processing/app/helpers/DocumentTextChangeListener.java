package processing.app.helpers;

import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

/**
 * Helper class that create a document listener that calls the given
 * TextChangeListener on any change to the document text (but not changes to
 * document attributes).
 * 
 * The TextChangeListener to be passed is intended to be a lambda function, for
 * easy definition of a callback.
 */
public class DocumentTextChangeListener implements DocumentListener {
  public interface TextChangeListener {
    public void textChanged();
  }

  private TextChangeListener onChange;

  public DocumentTextChangeListener(TextChangeListener onChange) {
    this.onChange = onChange;
  }

  @Override
  public void changedUpdate(DocumentEvent arg0) {
    /* Attributes changed, do nothing */
  }

  @Override
  public void insertUpdate(DocumentEvent arg0) {
    onChange.textChanged();
  }

  @Override
  public void removeUpdate(DocumentEvent arg0) {
    onChange.textChanged();
  }
}
