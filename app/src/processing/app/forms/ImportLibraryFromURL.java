package processing.app.forms;

import processing.app.I18n;

import java.awt.*;
import java.awt.event.ActionListener;

import static processing.app.I18n._;

public class ImportLibraryFromURL extends ImportLibraryFromURLDialog {

  public ImportLibraryFromURL(Frame parent) {
    super(parent, true);

    setTitle(_("Type the URL of the library ZIP file"));
    typeURLLabel.setText(getTitle() + ":");
    downloadingLabel.setText(_("Downloading... please wait..."));
    downloadingLabel.setVisible(false);
    urlTextField.setText("");
    okButton.setText(I18n.PROMPT_OK);

  }

  public void hideDownloadingLabel() {
    downloadingLabel.setVisible(true);
  }

  public void showDownloadingLabel() {
    downloadingLabel.setVisible(false);
  }

  public void addActionListener(ActionListener listener) {
    okButton.addActionListener(listener);
  }

  public String getUrl() {
    return urlTextField.getText();
  }
}
