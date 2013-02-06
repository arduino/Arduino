/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package processing.app;

import processing.app.debug.MessageConsumer;
import processing.core.*;
import static processing.app.I18n._;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.event.*;
import javax.swing.text.*;

public class SerialMonitor extends JFrame implements MessageConsumer {
  private Serial serial;
  private String port;
  private JTextArea textArea;
  private JScrollPane scrollPane;
  private JTextField textField;
  private JButton sendButton;
  private JCheckBox autoscrollBox;
  private JCheckBox sendAsBytesBox;
  private JComboBox lineEndings;
  private JComboBox serialRates;
  private int serialRate;

  public SerialMonitor(String port) {
    super(port);
  
    this.port = port;
  
    addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent e) {
          closeSerialPort();
        }
      });  
      
    // obvious, no?
    KeyStroke wc = Editor.WINDOW_CLOSE_KEYSTROKE;
    getRootPane().getInputMap(JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT).put(wc, "close");
    getRootPane().getActionMap().put("close", new AbstractAction() {
      public void actionPerformed(ActionEvent e) {
        closeSerialPort();
        setVisible(false);
      }});
  
    getContentPane().setLayout(new BorderLayout());
    
    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = Preferences.getFont("editor.font");
    Font font = new Font(consoleFont.getName(), consoleFont.getStyle(), editorFont.getSize());

    textArea = new JTextArea(16, 40);
    textArea.setEditable(false);    
    textArea.setFont(font);
    
    // don't automatically update the caret.  that way we can manually decide
    // whether or not to do so based on the autoscroll checkbox.
    ((DefaultCaret)textArea.getCaret()).setUpdatePolicy(DefaultCaret.NEVER_UPDATE);
    
    scrollPane = new JScrollPane(textArea);
    
    getContentPane().add(scrollPane, BorderLayout.CENTER);
    
    JPanel pane = new JPanel();
    pane.setLayout(new BoxLayout(pane, BoxLayout.X_AXIS));
    pane.setBorder(new EmptyBorder(4, 4, 4, 4));

    textField = new JTextField(40);
    textField.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        send(textField.getText());
        textField.setText("");
      }});

    sendButton = new JButton(_("Send"));
    sendButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        send(textField.getText());
        textField.setText("");
      }});
    
    pane.add(textField);
    pane.add(Box.createRigidArea(new Dimension(4, 0)));
    pane.add(sendButton);
    
    getContentPane().add(pane, BorderLayout.NORTH);
    
    pane = new JPanel();
    pane.setLayout(new BoxLayout(pane, BoxLayout.X_AXIS));
    pane.setBorder(new EmptyBorder(4, 4, 4, 4));
    
    autoscrollBox = new JCheckBox(_("Autoscroll"), true);

    sendAsBytesBox = new JCheckBox(_("Send as bytes"), false);
    sendAsBytesBox.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        lineEndings.setVisible(!sendAsBytesBox.isSelected());
      }
    });
    
    lineEndings = new JComboBox(new String[] { _("No line ending"), _("Newline"), _("Carriage return"), _("Both NL & CR") });
    lineEndings.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
      	Preferences.setInteger("serial.line_ending", lineEndings.getSelectedIndex());
      }
    });
    if (Preferences.get("serial.line_ending") != null) {
      lineEndings.setSelectedIndex(Preferences.getInteger("serial.line_ending"));
    }
    lineEndings.setMaximumSize(lineEndings.getMinimumSize());
      
    String[] serialRateStrings = {
      "300","1200","2400","4800","9600","14400",
      "19200","28800","38400","57600","115200"
    };
    
    serialRates = new JComboBox();
    for (int i = 0; i < serialRateStrings.length; i++)
      serialRates.addItem(serialRateStrings[i] + " " + _("baud"));

    serialRate = Preferences.getInteger("serial.debug_rate");
    serialRates.setSelectedItem(serialRate + " " + _("baud"));
    serialRates.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        String wholeString = (String) serialRates.getSelectedItem();
        String rateString = wholeString.substring(0, wholeString.indexOf(' '));
        serialRate = Integer.parseInt(rateString);
        Preferences.set("serial.debug_rate", rateString);
        closeSerialPort();
        try {
          openSerialPort();
        } catch (SerialException e) {
          System.err.println(e);
        }
      }});
      
    serialRates.setMaximumSize(serialRates.getMinimumSize());

    pane.add(autoscrollBox);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(sendAsBytesBox);
    pane.add(Box.createHorizontalGlue());
    pane.add(lineEndings);
    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(serialRates);
    
    getContentPane().add(pane, BorderLayout.SOUTH);

    pack();
    
    Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
    if (Preferences.get("last.screen.height") != null) {
      // if screen size has changed, the window coordinates no longer
      // make sense, so don't use them unless they're identical
      int screenW = Preferences.getInteger("last.screen.width");
      int screenH = Preferences.getInteger("last.screen.height");
      if ((screen.width == screenW) && (screen.height == screenH)) {
        String locationStr = Preferences.get("last.serial.location");
        if (locationStr != null) {
          int[] location = PApplet.parseInt(PApplet.split(locationStr, ','));
          setPlacement(location);
        }
      }
    }
  }
  
  protected void setPlacement(int[] location) {
    setBounds(location[0], location[1], location[2], location[3]);
  }

  protected int[] getPlacement() {
    int[] location = new int[4];

    // Get the dimensions of the Frame
    Rectangle bounds = getBounds();
    location[0] = bounds.x;
    location[1] = bounds.y;
    location[2] = bounds.width;
    location[3] = bounds.height;

    return location;
  }

  private void sendAsBytes(String s) {
    // Cut the string on every comma and trim the spaces
    String[] strArr = s.split(" ?, ?");
    int length = strArr.length;
    // Array for holding each byte of the stringarray
    byte[] byteArr = new byte[length];
    try {
      for (int i = 0; i < length; i++) {
        byteArr[i] = stringToByte(strArr[i]);
      }
    } catch (ByteStringException e) {
      // One of the numbers was not following the right format so end the send
      // and display a dialog
      String flawedStr = e.getMessage() != null ? e.getMessage() : "";
      String message = I18n
          .format(_("<html> "
                    + "<head> <style type=\"text/css\">"
//                    + "b '{' font: 13pt \"Lucida Grande\" '}'"
//                    + "p '{' font: 11pt \"Lucida Grande\"; margin-top: 8px '}'"
                    + "pre '{' font: 11pt \"Lucida Sans Typewriter\"'}'"
                    + "</style> </head>"
                    + "<b>{0}</b>"
                    + "<p>You should have enter a comma seperated array of bytes.</p>"
                    + "<p>The bytes must be formed as:</p>"
                    + "<PRE>Hex      0xff<BR>Octal    0377<BR>Decimal  255<BR>Binary   11111111</PRE>"
                    + "<p>(examples with their respective maximum values)</p></html>"),
                  flawedStr);
      JOptionPane.showMessageDialog(this, message, _("Malfomated String"),
                                    JOptionPane.ERROR_MESSAGE);
      return;
    }
    serial.write(byteArr);
  }

  private static byte stringToByte(String s) throws ByteStringException {
    final String regexHex = "0x([\\dabcdef]){2}";
    final String regexOct = "0[0-3]([0-7]){2}";
    final String regexDec = "(25[0-5]|2[0-4][0-9]|1\\d{2}|[1-9]\\d?)";
    final String regexBin = "[01]{8}";

    if (s.matches(regexHex)) {
      // cut off the 0x and convert to int
      return (byte) Integer.parseInt(s.substring(2), 16);
    }
    else if (s.matches(regexOct)) {
      // cut off the 0 and convert to int
      return (byte) Integer.parseInt(s.substring(1), 8);
    }
    else if (s.matches(regexDec)) {
      // convert to int
      return (byte) Integer.parseInt(s);
    }
    else if (s.matches(regexBin)) {
      // convert to int
      return (byte) Integer.parseInt(s,2);
    }
    // the imput is not the right format so throw exception
    throw new ByteStringException(
        I18n.format("''{0}'' is not a well formed string!", s));
  }

  private void send(String s) {
    if (serial != null) {
      // See if we want to send it as bytes
      if (sendAsBytesBox.isSelected()) {
        sendAsBytes(s);
      } else {
        switch (lineEndings.getSelectedIndex()) {
        case 1:
          s += "\n";
          break;
        case 2:
          s += "\r";
          break;
        case 3:
          s += "\r\n";
          break;
        }
        serial.write(s);
      }
    }
  }

  public void openSerialPort() throws SerialException {
    if (serial != null) return;
  
    serial = new Serial(port, serialRate);
    serial.addListener(this);
  }
  
  public void closeSerialPort() {
    if (serial != null) {
      int[] location = getPlacement();
      String locationStr = PApplet.join(PApplet.str(location), ",");
      Preferences.set("last.serial.location", locationStr);
      textArea.setText("");
      serial.dispose();
      serial = null;
    }
  }
  
  public void message(final String s) {
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        textArea.append(s);
        if (autoscrollBox.isSelected()) {
        	textArea.setCaretPosition(textArea.getDocument().getLength());
        }
      }});
  }
}
