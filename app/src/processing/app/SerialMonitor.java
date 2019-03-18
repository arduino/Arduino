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
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import static processing.app.I18n.tr;

@SuppressWarnings("serial")
public class SerialMonitor extends AbstractTextMonitor {

  private Serial serial;
  private int serialRate;

  private static final int COMMAND_HISTORY_SIZE = 100;
  private final CommandHistory commandHistory =
      new CommandHistory(COMMAND_HISTORY_SIZE);

  public SerialMonitor(BoardPort port) {
    super(port);

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

    onSendCommand((ActionEvent event) -> {
      String command = textField.getText();
      send(command);
      commandHistory.addCommand(command);
      textField.setText("");
    });

    onClearCommand((ActionEvent event) -> textArea.setText(""));

    // Add key listener to UP, DOWN, ESC keys for command history traversal.
    textField.addKeyListener(new KeyAdapter() {
      @Override
      public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {

          // Select previous command.
          case KeyEvent.VK_UP:
            if (commandHistory.hasPreviousCommand()) {
              textField.setText(
                  commandHistory.getPreviousCommand(textField.getText()));
            }
            break;

          // Select next command.
          case KeyEvent.VK_DOWN:
            if (commandHistory.hasNextCommand()) {
              textField.setText(commandHistory.getNextCommand());
            }
            break;

          // Reset history location, restoring the last unexecuted command.
          case KeyEvent.VK_ESCAPE:
            textField.setText(commandHistory.resetHistoryLocation());
            break;
        }
      }
    });
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
      if ("".equals(s) && lineEndings.getSelectedIndex() == 0 && !PreferencesData.has("runtime.line.ending.alert.notified")) {
        noLineEndingAlert.setForeground(Color.RED);
        PreferencesData.set("runtime.line.ending.alert.notified", "true");
      }
      serial.write(s);
    }
  }

  @Override
  public void open() throws Exception {
    super.open();

    if (serial != null) return;

    serial = new Serial(getBoardPort().getAddress(), serialRate) {
      @Override
      protected void message(char buff[], int n) {
        addToUpdateBuffer(buff, n);
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
