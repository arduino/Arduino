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
import java.util.StringTokenizer;

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
  protected JCheckBox addTimeStampBox;
  protected JComboBox<String> sendEncoding;
  protected JComboBox<String> receiveEncoding;
  protected JComboBox<String> lineEndings;
  protected JComboBox<String> serialRates;

  public AbstractTextMonitor(Base base, BoardPort boardPort) {
    super(boardPort);

    // Add font size adjustment listeners. This has to be done here due to
    // super(boardPort) invoking onCreateWindow(...) before we can store base.
    base.addEditorFontResizeListeners(textArea);
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
      System.out.println("Finished!");
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