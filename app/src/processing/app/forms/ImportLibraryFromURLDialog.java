package processing.app.forms;

import org.jdesktop.layout.GroupLayout;
import org.jdesktop.layout.LayoutStyle;

import javax.swing.*;
import java.awt.*;

public class ImportLibraryFromURLDialog extends JDialog {

  protected JButton okButton;
  protected JLabel typeURLLabel;
  protected JLabel downloadingLabel;
  protected JTextField urlTextField;

  public ImportLibraryFromURLDialog(Frame parent, boolean modal) {
    super(parent, modal);
    initComponents();
  }

  @SuppressWarnings("unchecked")
  private void initComponents() {

    typeURLLabel = new JLabel();
    urlTextField = new JTextField();
    okButton = new JButton();
    downloadingLabel = new JLabel();

    setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

    typeURLLabel.setText("typeURLLabel");

    urlTextField.setText("urlTextField");

    okButton.setText("okButton");

    downloadingLabel.setText("downloadingLabel");

    GroupLayout layout = new GroupLayout(getContentPane());
    getContentPane().setLayout(layout);
    layout.setHorizontalGroup(
            layout.createParallelGroup(GroupLayout.LEADING)
                    .add(layout.createSequentialGroup()
                            .addContainerGap()
                            .add(layout.createParallelGroup(GroupLayout.LEADING)
                                    .add(urlTextField)
                                    .add(layout.createSequentialGroup()
                                            .add(layout.createParallelGroup(GroupLayout.LEADING)
                                                    .add(typeURLLabel)
                                                    .add(layout.createSequentialGroup()
                                                            .add(okButton)
                                                            .addPreferredGap(LayoutStyle.RELATED)
                                                            .add(downloadingLabel)))
                                            .add(0, 279, Short.MAX_VALUE)))
                            .addContainerGap())
    );
    layout.setVerticalGroup(
            layout.createParallelGroup(GroupLayout.LEADING)
                    .add(layout.createSequentialGroup()
                            .addContainerGap()
                            .add(typeURLLabel)
                            .addPreferredGap(LayoutStyle.RELATED)
                            .add(urlTextField, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(LayoutStyle.RELATED)
                            .add(layout.createParallelGroup(GroupLayout.BASELINE)
                                    .add(okButton)
                                    .add(downloadingLabel))
                            .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
    );

    pack();
  }
}
