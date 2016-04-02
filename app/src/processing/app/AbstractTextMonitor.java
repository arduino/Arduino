package processing.app;

import static processing.app.I18n.tr;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.AffineTransform;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ChangeListener;
import javax.swing.text.DefaultCaret;

import cc.arduino.packages.BoardPort;

@SuppressWarnings("serial")
public abstract class AbstractTextMonitor extends AbstractMonitor {

  protected JLabel noLineEndingAlert;
  protected TextAreaFIFO textArea;
  protected JScrollPane scrollPane;
  protected JTextField textField;
  protected JButton sendButton;
  protected JCheckBox autoscrollBox;
  protected JComboBox lineEndings;
  protected JComboBox serialRates;
  
  protected byte[][] lineEndingSelection;

  protected JComboBox<Charset> txCharsets;
  protected JComboBox<Charset> rxCharsets;
  
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
    sendButton = new JButton(tr("Send"));

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
    noLineEndingAlert.setMinimumSize(new Dimension(0, noLineEndingAlert.getPreferredSize().height));

    lineEndings = new JComboBox(new String[]{tr("No line ending"), tr("Newline"), tr("Carriage return"), tr("Both NL & CR")});
    lineEndingSelection = new byte[][] { {}, {'\n'}, {'\r'}, {'\r', '\n'}};
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
    
    java.util.List<Charset> list = new java.util.ArrayList<Charset>();
        
    // All JVMs are required to support these standard charsets. I will add them to the top
    // the list 
    
    list.add(Charset.forName("US-ASCII"));
    list.add(Charset.forName("ISO-8859-1"));
    list.add(Charset.forName("UTF-8"));
    list.add(Charset.forName("UTF-16"));
    list.add(Charset.forName("UTF-16BE"));
    list.add(Charset.forName("UTF-16LE"));
    
    list.addAll(Charset.availableCharsets().values());
    
    rxCharsets = new JComboBox<Charset>(list.toArray(new Charset[list.size()]));
    for(java.util.Iterator<Charset> i = list.iterator(); i.hasNext();) {
	  if(!i.next().canEncode()) {
		i.remove();
	  }
    }
    txCharsets = new JComboBox<Charset>(list.toArray(new Charset[list.size()]));

    txCharsets.setSelectedItem(Charset.forName("US-ASCII")); // US-ASCII is always available
    rxCharsets.setSelectedItem(Charset.defaultCharset()); // assume that the arduino is being tested against the current platform

    // some of these encoding names are a little long, so I'll knock some size off the fonts
    Font compressed = txCharsets.getFont().deriveFont(new AffineTransform(.8, 0, 0, 1, 0, 0));
    txCharsets.setFont(compressed);
    rxCharsets.setFont(compressed);
    txCharsets.setMaximumSize(txCharsets.getMinimumSize());
    rxCharsets.setMaximumSize(rxCharsets.getMinimumSize());
    
    pane.add(autoscrollBox);
    pane.add(Box.createHorizontalGlue());
    pane.add(noLineEndingAlert);
    pane.add(new JLabel("Tx"));
    pane.add(Box.createRigidArea(new Dimension(2, 0)));
    pane.add(txCharsets);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(new JLabel("Rx"));
    pane.add(Box.createRigidArea(new Dimension(2, 0)));
    pane.add(rxCharsets);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(lineEndings);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(serialRates);

    mainPane.add(pane, BorderLayout.SOUTH);
  }

  protected void onEnableWindow(boolean enable)
  {
    textArea.setEnabled(enable);
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

  public void onSerialRateChange(ActionListener listener) {
    serialRates.addActionListener(listener);
  }
  
  public void onTxCharsetChange(ActionListener listener) {
	txCharsets.addActionListener(listener);
  }
		  
  public void onRxCharsetChange(ActionListener listener) {
    rxCharsets.addActionListener(listener);
  }
		  
  public void message(final byte[] msg) {
	String s;
	
	try {
		s = new String(msg, ((Charset)rxCharsets.getSelectedItem()).name());
	} catch (UnsupportedEncodingException e) {
		s = new String(msg);
	}
	
	final String final_s = s;
	
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        textArea.append(final_s);
        if (autoscrollBox.isSelected()) {
          textArea.setCaretPosition(textArea.getDocument().getLength());
        }
      }
    });
  }
}
