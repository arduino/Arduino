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

import cc.arduino.packages.BoardPort;
import processing.app.legacy.PApplet;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.nio.charset.Charset;

import static processing.app.I18n.tr;

@SuppressWarnings("serial")
public class SerialMonitor extends AbstractTextMonitor {

  private Serial serial;
  private int serialRate;

  private static final EncodingOption DEFAULT_SEND_ENCODING =
      EncodingOption.UTF_8;
  private static final EncodingOption DEFAULT_RECEIVE_ENCODING =
      EncodingOption.UTF_8;

  public SerialMonitor(Base base, BoardPort port) {
    super(base, port);

    serialRate = PreferencesData.getInteger("serial.debug_rate");
    serialRates.setSelectedItem(serialRate + " " + tr("baud"));
    onSerialRateChange((ActionEvent event) -> {
      String wholeString = (String) serialRates.getSelectedItem();
      String rateString = wholeString.substring(0, wholeString.indexOf(' '));
      serialRate = Integer.parseInt(rateString);
      PreferencesData.set("serial.debug_rate", rateString);
      try {
        close();
        Thread.sleep(100); // Wait for serial port to properly close
        open();
      } catch (InterruptedException e) {
        // noop
      } catch (Exception e) {
        System.err.println(e);
      }
    });

    onReceiveEncodingChange((ActionEvent event) -> {
      String receiveAs = tr("Receive as") + " ";
      String selectedEncodingStr = receiveEncoding.getItemAt(
          receiveEncoding.getSelectedIndex()).substring(receiveAs.length());
      Charset selectedCharset =
          EncodingOption.forName(selectedEncodingStr).getCharset();
      if (serial.getCharset() != selectedCharset) {
        serial.resetDecoding(selectedCharset);
        PreferencesData.set("serial.receive_encoding", selectedEncodingStr);
      }
    });

    onSendCommand((ActionEvent event) -> {
      send(textField.getText());
      textField.setText("");
    });
    
    onClearCommand((ActionEvent event) -> textArea.setText(""));
  }

  private void send(String s) {
    if (serial != null) {
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
        default:
          break;
      }
      if ("".equals(s) && lineEndings.getSelectedIndex() == 0
          && !PreferencesData.has("runtime.line.ending.alert.notified")) {
        noLineEndingAlert.setForeground(Color.RED);
        PreferencesData.set("runtime.line.ending.alert.notified", "true");
      }
      EncodingOption encodingOption =
          EncodingOption.forName(PreferencesData.get("serial.send_encoding"));
      if (encodingOption == null) {
        encodingOption = DEFAULT_SEND_ENCODING;
      }
      Charset charSet = encodingOption.getCharset();
      byte[] bytes;
      if (charSet != null) {
        bytes = s.getBytes(encodingOption.getCharset());
      } else {
        switch (encodingOption) {
          case BYTES:
            String[] split = s.split(",");
            bytes = new byte[split.length];
            for (int i = 0; i < split.length; i++) {
              String valStr = split[i].trim();
              try {
                int val = Integer.parseInt(valStr);
                if (val < 0x00 || val > 0xFF) {
                  this.message("\n[ERROR] Invalid byte value given: "
                      + val + ". Byte values are in range [0-255].\n");
                  return;
                }
                bytes[i] = (byte) val;
              } catch (NumberFormatException e) {
                this.message("\n[ERROR] Invalid byte value given: " + valStr
                    + ". Byte values are numbers in range [0-255].\n");
                return;
              }
            }
            break;
          default:
            throw new Error(
                "Unsupported 'send as' encoding option: " + encodingOption);
        }
      }
      serial.write(bytes);
    }
  }

  @Override
  public void open() throws Exception {
    super.open();

    if (serial != null) return;

    EncodingOption encodingOption =
        EncodingOption.forName(PreferencesData.get("serial.receive_encoding"));
    if (encodingOption == null) {
      encodingOption = DEFAULT_RECEIVE_ENCODING;
    }
    serial = new Serial(
        getBoardPort().getAddress(), serialRate, encodingOption.getCharset()) {
      @Override
      protected void message(char buff[], int n) {
        if (serial.getCharset() == null) {
          if(buff.length != 0) {
            StringBuilder strBuilder = new StringBuilder();
            for (int i = 0; i < n; i++) {
              strBuilder.append(buff[i] & 0xFF).append("\n");
            }
            addToUpdateBuffer(
                strBuilder.toString().toCharArray(), strBuilder.length());
          }
        } else {
          addToUpdateBuffer(buff, n);
        }
      }
    };
  }

  @Override
  public void close() throws Exception {
    super.close();
    if (serial != null) {
      int[] location = getPlacement();
      String locationStr = PApplet.join(PApplet.str(location), ",");
      PreferencesData.set("last.serial.location", locationStr);
      textArea.setText("");
      serial.dispose();
      serial = null;
    }
  }
  
}