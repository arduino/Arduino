/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2005-07 Ben Fry and Casey Reas

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

import java.awt.*;
import java.awt.geom.Rectangle2D;
import javax.swing.JComponent;

import processing.app.helpers.OSUtils;
import processing.app.helpers.PreferencesMap;
import static processing.app.I18n.tr;

import static processing.app.Theme.scale;

/**
 * Li'l status bar fella that shows the line number.
 */
public class EditorLineStatus extends JComponent {

  int start = -1, stop;

  Image resize;
  private static final int RESIZE_IMAGE_SIZE = scale(20);

  Color foreground;
  Color background;
  Color messageForeground;
  
  Font font;
  int height;

  String text = "";
  String name = "";
  String serialport = "";

  public EditorLineStatus() {
    background = Theme.getColor("linestatus.bgcolor");
    font = Theme.getFont("linestatus.font");
    foreground = Theme.getColor("linestatus.color");
    height = Theme.getInteger("linestatus.height");

    if (OSUtils.isMacOS()) {
      resize = Theme.getThemeImage("resize", this, RESIZE_IMAGE_SIZE, RESIZE_IMAGE_SIZE);
    }
    //linestatus.bgcolor = #000000
    //linestatus.font    = SansSerif,plain,10
    //linestatus.color   = #FFFFFF
  }

  public void set(int newStart, int newStop) {
    if ((newStart == start) && (newStop == stop)) return;

    start = newStart;
    stop = newStop;

    /*
    if (start == stop) {
      text = "Line " + (start + 1);
    } else {
      text = "Lines " + (start + 1) + " to " + (stop + 1);
    }
    */
    if (start == stop) {
      text = String.valueOf(start+1);
    } else {
      text = (start+1) + " - " + (stop+1);
    }

    repaint();
  }

  public void paintComponent(Graphics graphics) {
    Graphics2D g = Theme.setupGraphics2D(graphics);
    if (name == "" && serialport == "") {
      PreferencesMap boardPreferences = BaseNoGui.getBoardPreferences();
      if (boardPreferences != null)
        setBoardName(boardPreferences.get("name"));
      else
        setBoardName("-");
      setSerialPort(PreferencesData.get("serial.port"));
    }
    g.setColor(background);
    Dimension size = getSize();
    g.fillRect(0, 0, size.width, size.height);

    g.setFont(font);
    g.setColor(foreground);
    int baseline = (size.height + g.getFontMetrics().getAscent()) / 2;
    g.drawString(text, scale(6), baseline);

    g.setColor(messageForeground);
    String tmp = I18n.format(tr("{0} on {1}"), name, serialport);
    
    Rectangle2D bounds = g.getFontMetrics().getStringBounds(tmp, null);
    
    g.drawString(tmp, size.width - (int) bounds.getWidth() - RESIZE_IMAGE_SIZE,
                 baseline);

    if (OSUtils.isMacOS()) {
      g.drawImage(resize, size.width - RESIZE_IMAGE_SIZE, 0, this);
    }
  }

  public void setBoardName(String name) {
    this.name = name;
  }

  public void setSerialPort(String serialport) {
    this.serialport = serialport;
  }

  public Dimension getPreferredSize() {
    return scale(new Dimension(300, height));
  }

  public Dimension getMinimumSize() {
    return getPreferredSize();
  }

  public Dimension getMaximumSize() {
    return scale(new Dimension(3000, height));
  }
}
