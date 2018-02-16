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
import java.text.SimpleDateFormat;
import java.util.Date;

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
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultCaret;
import javax.swing.event.UndoableEditListener;
import javax.swing.text.AbstractDocument;
import javax.swing.text.Document;

import cc.arduino.packages.BoardPort;

@SuppressWarnings("serial")
public abstract class AbstractTextMonitor extends AbstractMonitor {

  protected JLabel noLineEndingAlert;
  protected TextAreaFIFO textArea;
  protected HTMLTextAreaFIFO htmlTextArea;
  protected JScrollPane scrollPane;
  protected JScrollPane htmlScrollPane;
  protected JTextField textField;
  protected JButton sendButton;
  protected JButton clearButton;
  protected JCheckBox autoscrollBox;
  protected JCheckBox addTimeStampBox;
  protected JComboBox lineEndings;
  protected JComboBox serialRates;
  protected Container mainPane;
  private long lastMessage;
  private javax.swing.Timer updateTimer;
  private boolean htmlView = true;

  private SimpleDateFormat logDateFormat;
  
  public AbstractTextMonitor(BoardPort boardPort) {
    super(boardPort);
    logDateFormat = new SimpleDateFormat("HH:mm:ss.SSS");
  }
  
  protected void onCreateWindow(Container mainPane) {
    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    Font font = Theme.scale(new Font(consoleFont.getName(), consoleFont.getStyle(), editorFont.getSize()));

    this.mainPane = mainPane;
    mainPane.setLayout(new BorderLayout());

    textArea = new TextAreaFIFO(8000000);
    textArea.setRows(16);
    textArea.setColumns(40);
    textArea.setEditable(false);
    textArea.setFont(font);

    htmlTextArea = new HTMLTextAreaFIFO(8000000);
    htmlTextArea.setEditable(false);
    htmlTextArea.setFont(font);
    htmlTextArea.setOpaque(false);

    // don't automatically update the caret.  that way we can manually decide
    // whether or not to do so based on the autoscroll checkbox.
    ((DefaultCaret) textArea.getCaret()).setUpdatePolicy(DefaultCaret.NEVER_UPDATE);
    ((DefaultCaret) htmlTextArea.getCaret()).setUpdatePolicy(DefaultCaret.NEVER_UPDATE);

    Document doc = textArea.getDocument();
    if (doc instanceof AbstractDocument)
    {
      UndoableEditListener[] undoListeners =
          ( (AbstractDocument) doc).getUndoableEditListeners();
      if (undoListeners.length > 0)
      {
        for (UndoableEditListener undoListener : undoListeners)
        {
          doc.removeUndoableEditListener(undoListener);
        }
      }
    }

    doc = htmlTextArea.getDocument();
    if (doc instanceof AbstractDocument)
    {
      UndoableEditListener[] undoListeners =
          ( (AbstractDocument) doc).getUndoableEditListeners();
      if (undoListeners.length > 0)
      {
        for (UndoableEditListener undoListener : undoListeners)
        {
          doc.removeUndoableEditListener(undoListener);
        }
      }
    }

    scrollPane = new JScrollPane(textArea);
    scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
    htmlScrollPane = new JScrollPane(htmlTextArea);
    htmlScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

    ActionListener checkIfSteady = new ActionListener() {
      public void actionPerformed(ActionEvent evt) {
        if (System.currentTimeMillis() - lastMessage > 200) {
          if (htmlView == false && textArea.getLength() < 1000) {

            htmlTextArea.setText("");
            boolean res = htmlTextArea.append(textArea.getText());
            if (res) {
              htmlView = true;
              mainPane.remove(scrollPane);
              if (textArea.getCaretPosition() > htmlTextArea.getDocument().getLength()) {
                htmlTextArea.setCaretPosition(htmlTextArea.getDocument().getLength());
              } else {
                htmlTextArea.setCaretPosition(textArea.getCaretPosition());
              }
              mainPane.add(htmlScrollPane, BorderLayout.CENTER);
              scrollPane.setVisible(false);
              mainPane.validate();
              mainPane.repaint();
            }
          }
        } else {
          if (htmlView == true) {
            htmlView = false;
            mainPane.remove(htmlScrollPane);
            mainPane.add(scrollPane, BorderLayout.CENTER);
            scrollPane.setVisible(true);
            mainPane.validate();
            mainPane.repaint();
          }
        }
      }
    };

    updateTimer = new javax.swing.Timer(33, checkIfSteady);

    mainPane.add(scrollPane, BorderLayout.CENTER);

    htmlTextArea.setVisible(true);
    htmlScrollPane.setVisible(true);
  
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
    addTimeStampBox = new JCheckBox(tr("Show timestamp"), false);

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
    if (PreferencesData.get("serial.show_timestamp") != null) {
      addTimeStampBox.setSelected(PreferencesData.getBoolean("serial.show_timestamp"));
    }
    addTimeStampBox.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        PreferencesData.setBoolean("serial.show_timestamp", addTimeStampBox.isSelected());
      }
    });

    lineEndings.setMaximumSize(lineEndings.getMinimumSize());

    serialRates = new JComboBox();
    for (String rate : serialRateStrings) {
      serialRates.addItem(rate + " " + tr("baud"));
    }

    serialRates.setMaximumSize(serialRates.getMinimumSize());

    pane.add(autoscrollBox);
    pane.add(addTimeStampBox);
    pane.add(Box.createHorizontalGlue());
    pane.add(noLineEndingAlert);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(lineEndings);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(serialRates);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(clearButton);

    mainPane.add(pane, BorderLayout.SOUTH);

    updateTimer.start();
  }

  protected void onEnableWindow(boolean enable)
  {
    textArea.setEnabled(enable);
    clearButton.setEnabled(enable);
    htmlTextArea.setEnabled(enable);
    scrollPane.setEnabled(enable);
    htmlScrollPane.setEnabled(enable);
    textField.setEnabled(enable);
    sendButton.setEnabled(enable);
    autoscrollBox.setEnabled(enable);
    addTimeStampBox.setEnabled(enable);
    lineEndings.setEnabled(enable);
    serialRates.setEnabled(enable);
    if (enable == false) {
      htmlTextArea.setText("");
    }
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
    lastMessage = System.currentTimeMillis();
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        if (addTimeStampBox.isSelected()) {
          String[] lines = s.split("(?<=\\n)");
          Document doc = textArea.getDocument();
          for (String currentLine : lines) {
            try {
              if (doc.getLength() == 0 || ((int) doc.getText(doc.getLength() - 1, 1).charAt(0) == 10)) {
                textArea.append(logDateFormat.format(new Date()) + " -> " + currentLine);
              } else {
                textArea.append(currentLine);
              }
            } catch (BadLocationException e) {
              e.printStackTrace();
            }
          }
        } else {
          textArea.append(s);
        }

        if (autoscrollBox.isSelected()) {
          textArea.setCaretPosition(textArea.getDocument().getLength());
        }
      }
    });
  }
}
