package processing.app;

import static processing.app.I18n.tr;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyListener;
import java.awt.event.MouseWheelListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.StringTokenizer;

import javax.swing.Action;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;
import javax.swing.text.DefaultCaret;
import javax.swing.text.DefaultEditorKit;

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
  protected JCheckBox addTimeStampBox;
  protected JComboBox<String> lineEndings;
  protected JComboBox<String> serialRates;

  public AbstractTextMonitor(BoardPort boardPort) {
    super(boardPort);
  }

  @Override
  public synchronized void addMouseWheelListener(MouseWheelListener l) {
    super.addMouseWheelListener(l);
    textArea.addMouseWheelListener(l);
  }

  @Override
  public synchronized void addKeyListener(KeyListener l) {
    super.addKeyListener(l);
    textArea.addKeyListener(l);
    textField.addKeyListener(l);
  }

  @Override
  protected void onCreateWindow(Container mainPane) {

    mainPane.setLayout(new BorderLayout());

    textArea = new TextAreaFIFO(8_000_000);
    textArea.setRows(16);
    textArea.setColumns(40);
    textArea.setEditable(false);

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
      @Override
      public void windowGainedFocus(WindowEvent e) {
        textField.requestFocusInWindow();
      }
    });

    // Add cut/copy/paste contextual menu to the text input field.
    JPopupMenu menu = new JPopupMenu();

    Action cut = new DefaultEditorKit.CutAction();
    cut.putValue(Action.NAME, tr("Cut"));
    menu.add(cut);

    Action copy = new DefaultEditorKit.CopyAction();
    copy.putValue(Action.NAME, tr("Copy"));
    menu.add(copy);

    Action paste = new DefaultEditorKit.PasteAction();
    paste.putValue(Action.NAME, tr("Paste"));
    menu.add(paste);

    textField.setComponentPopupMenu(menu);

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

    lineEndings = new JComboBox<>(new String[]{tr("No line ending"), tr("Newline"), tr("Carriage return"), tr("Both NL & CR")});
    lineEndings.addActionListener((ActionEvent event) -> {
      PreferencesData.setInteger("serial.line_ending", lineEndings.getSelectedIndex());
      noLineEndingAlert.setForeground(pane.getBackground());
    });
    addTimeStampBox.addActionListener((ActionEvent event) ->
        PreferencesData.setBoolean("serial.show_timestamp", addTimeStampBox.isSelected()));

    lineEndings.setMaximumSize(lineEndings.getMinimumSize());

    serialRates = new JComboBox<>();
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

    applyPreferences();

    mainPane.add(pane, BorderLayout.SOUTH);
  }

  @Override
  protected void onEnableWindow(boolean enable)
  {
    textArea.setEnabled(enable);
    clearButton.setEnabled(enable);
    scrollPane.setEnabled(enable);
    textField.setEnabled(enable);
    sendButton.setEnabled(enable);
    autoscrollBox.setEnabled(enable);
    addTimeStampBox.setEnabled(enable);
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

  @Override
  public void message(String msg) {
    SwingUtilities.invokeLater(() -> updateTextArea(msg));
  }

  private static final String LINE_SEPARATOR = "\n";
  private boolean isStartingLine = true;

  protected void updateTextArea(String msg) {
    if (addTimeStampBox.isSelected()) {
      textArea.append(addTimestamps(msg));
    } else {
      textArea.append(msg);
    }
    if (autoscrollBox.isSelected()) {
      textArea.setCaretPosition(textArea.getDocument().getLength());
    }
  }

  @Override
  public void applyPreferences() {

    // Apply font.
    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    textArea.setFont(Theme.scale(new Font(
        consoleFont.getName(), consoleFont.getStyle(), editorFont.getSize())));

    // Apply line endings.
    if (PreferencesData.get("serial.line_ending") != null) {
      lineEndings.setSelectedIndex(PreferencesData.getInteger("serial.line_ending"));
    }

    // Apply timestamp visibility.
    if (PreferencesData.get("serial.show_timestamp") != null) {
      addTimeStampBox.setSelected(PreferencesData.getBoolean("serial.show_timestamp"));
    }
  }

  private String addTimestamps(String text) {
    String now = new SimpleDateFormat("HH:mm:ss.SSS -> ").format(new Date());
    final StringBuilder sb = new StringBuilder(text.length() + now.length());
    StringTokenizer tokenizer = new StringTokenizer(text, LINE_SEPARATOR, true);
    while (tokenizer.hasMoreTokens()) {
      if (isStartingLine) {
        sb.append(now);
      }
      String token = tokenizer.nextToken();
      sb.append(token);
      // tokenizer returns "\n" as a single token
      isStartingLine = token.equals(LINE_SEPARATOR);
    }
    return sb.toString();
  }
}
