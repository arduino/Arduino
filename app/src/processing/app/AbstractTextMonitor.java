package processing.app;

import static processing.app.I18n.tr;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;
import javax.swing.text.DefaultCaret;

import cc.arduino.packages.BoardPort;

@SuppressWarnings("serial")
public abstract class AbstractTextMonitor extends AbstractMonitor {

  protected JLabel noLineEndingAlert;
  protected TextAreaFIFO textArea;
  protected JScrollPane scrollPane;
  protected JTextField textField;
  protected JButton sendButton;
  protected JButton clearButton;
  protected JCheckBox autoscrollBox;
  protected JComboBox lineEndings;
  protected JComboBox serialRates;

  public AbstractTextMonitor(BoardPort boardPort) {
    super(boardPort);
  }
  
  protected void onCreateWindow(Container mainPane) {
    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    Font font = Theme.scale(new Font(consoleFont.getName(), consoleFont.getStyle(), editorFont.getSize()));

    mainPane.setLayout(new BorderLayout());

    textArea = new TextAreaFIFO(8000000);
    textArea.setRows(16);
    textArea.setColumns(40);
    textArea.setEditable(false);
    textArea.setFont(font);

    // don't automatically update the caret.  that way we can manually decide
    // whether or not to do so based on the autoscroll checkbox.
    ((DefaultCaret) textArea.getCaret()).setUpdatePolicy(DefaultCaret.NEVER_UPDATE);

    scrollPane = new JScrollPane(textArea);

    mainPane.add(scrollPane, BorderLayout.CENTER);
  
    JPanel upperPane = new JPanel();
    upperPane.setLayout(new BoxLayout(upperPane, BoxLayout.X_AXIS));
    upperPane.setBorder(new EmptyBorder(4, 4, 4, 4));

    textField = new JTextField(40);
    // textField is selected every time the window is focused
    addWindowFocusListener(new WindowAdapter() {
      public void windowGainedFocus(WindowEvent e) {
        textField.requestFocusInWindow();
      }
    });

    sendButton = new JButton(tr("Send"));
    clearButton = new JButton(tr("Clear output"));

    upperPane.add(textField);
    upperPane.add(Box.createRigidArea(new Dimension(4, 0)));
    upperPane.add(sendButton);

    mainPane.add(upperPane, BorderLayout.NORTH);

    final JPanel pane = new JPanel();
    pane.setLayout(new BoxLayout(pane, BoxLayout.X_AXIS));
    pane.setBorder(new EmptyBorder(4, 4, 4, 4));

    autoscrollBox = new JCheckBox(tr("Autoscroll"), true);

    noLineEndingAlert = new JLabel(I18n.format(tr("You've pressed {0} but nothing was sent. Should you select a line ending?"), tr("Send")));
    noLineEndingAlert.setToolTipText(noLineEndingAlert.getText());
    noLineEndingAlert.setForeground(pane.getBackground());
    Dimension minimumSize = new Dimension(noLineEndingAlert.getMinimumSize());
    minimumSize.setSize(minimumSize.getWidth() / 3, minimumSize.getHeight());
    noLineEndingAlert.setMinimumSize(minimumSize);

    lineEndings = new JComboBox(new String[]{tr("No line ending"), tr("Newline"), tr("Carriage return"), tr("Both NL & CR")});
    lineEndings.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        PreferencesData.setInteger("serial.line_ending", lineEndings.getSelectedIndex());
        noLineEndingAlert.setForeground(pane.getBackground());
      }
    });
    if (PreferencesData.get("serial.line_ending") != null) {
      lineEndings.setSelectedIndex(PreferencesData.getInteger("serial.line_ending"));
    }
    lineEndings.setMaximumSize(lineEndings.getMinimumSize());

    serialRates = new JComboBox();
    for (String rate : serialRateStrings) {
      serialRates.addItem(rate + " " + tr("baud"));
    }

    serialRates.setMaximumSize(serialRates.getMinimumSize());

    pane.add(autoscrollBox);
    pane.add(Box.createHorizontalGlue());
    pane.add(noLineEndingAlert);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(lineEndings);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(serialRates);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(clearButton);

    mainPane.add(pane, BorderLayout.SOUTH);
  }

  protected void onEnableWindow(boolean enable)
  {
    textArea.setEnabled(enable);
    clearButton.setEnabled(enable);
    scrollPane.setEnabled(enable);
    textField.setEnabled(enable);
    sendButton.setEnabled(enable);
    autoscrollBox.setEnabled(enable);
    lineEndings.setEnabled(enable);
    serialRates.setEnabled(enable);
  }

  public void onSendCommand(ActionListener listener) {
    textField.addActionListener(listener);
    sendButton.addActionListener(listener);
  }
  
  public void onClearCommand(ActionListener listener) {
    clearButton.addActionListener(listener);
  }

  public void onSerialRateChange(ActionListener listener) {
    serialRates.addActionListener(listener);
  }
  
  public void message(final String s) {
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        textArea.append(s);
        if (autoscrollBox.isSelected()) {
          textArea.setCaretPosition(textArea.getDocument().getLength());
        }
      }
    });
  }
}
