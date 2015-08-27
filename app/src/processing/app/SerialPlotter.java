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

import processing.app.helpers.*;
import static processing.app.I18n.tr;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;
import javax.swing.border.*;

public class SerialPlotter extends AbstractMonitor {
  private StringBuffer messageBuffer;
  private CircularBuffer buffer;
  private GraphPanel graphPanel;
  private JComboBox serialRates;

  private Serial serial;
  private int serialRate;

  private class GraphPanel extends JPanel {
    private double minY, maxY, rangeY;
    private Rectangle bounds;
    private int xOffset;
    private Font font;
    private Color graphColor;
    
    public GraphPanel() {
      font = Theme.getFont("console.font");
      graphColor = Theme.getColor("header.bgcolor");
      xOffset = 20;
    }
    
    @Override
    public void paintComponent(Graphics g1) {
      Graphics2D g = (Graphics2D)g1;
      g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
      g.setFont(font);
      super.paintComponent(g);
      
      bounds = g.getClipBounds();
      setBackground(Color.WHITE);
      if(buffer.isEmpty()) {
        return;
      }
      
      minY = buffer.min();
      maxY = buffer.max();
      Ticks ticks = new Ticks(minY, maxY, 3);
      minY = Math.min(minY, ticks.getTick(0));
      maxY = Math.max(maxY, ticks.getTick(ticks.getTickCount() - 1));
      rangeY = maxY - minY;
      minY -= 0.05 * rangeY;
      maxY += 0.05 * rangeY;
      rangeY = maxY - minY;

      g.setStroke(new BasicStroke(1.0f));
      FontMetrics fm = g.getFontMetrics();
      for(int i = 0; i < ticks.getTickCount(); ++i) {
        double tick = ticks.getTick(i);
        Rectangle2D fRect = fm.getStringBounds(String.valueOf(tick), g);
        xOffset = Math.max(xOffset, (int)fRect.getWidth() + 15);

        // draw tick
        g.drawLine(xOffset - 5, (int)transformY(tick), xOffset + 2, (int)transformY(tick));
        // draw tick label
        g.drawString(String.valueOf(tick), xOffset - (int)fRect.getWidth() - 10, transformY(tick) - (float)fRect.getHeight() * 0.5f + fm.getAscent());
      }

      g.drawLine(bounds.x + xOffset, bounds.y + 5, bounds.x + xOffset, bounds.y + bounds.height - 10);
      
      g.setTransform(AffineTransform.getTranslateInstance(xOffset, 0));		
      float xstep = (float)(bounds.width - xOffset) / (float)buffer.capacity();
      
      g.setColor(graphColor);
      g.setStroke(new BasicStroke(0.75f));
      
      for(int i = 0; i < buffer.size() - 1; ++i) {
        g.drawLine(
          (int)(i * xstep), (int)transformY(buffer.get(i)),
          (int)((i + 1) * xstep), (int)transformY(buffer.get(i + 1))
        );
      }
    }
    
    @Override
    public Dimension getMinimumSize() {
      return new Dimension(200, 100);
    }
    
    @Override
    public Dimension getPreferredSize() {
      return new Dimension(500, 250);
    }
    
    private float transformY(double rawY) {
      return (float)(5 + (bounds.height - 10) * (1.0 - (rawY - minY) / rangeY));
    }
  }

  public SerialPlotter(BoardPort port) {
    super(port);

    serialRate = PreferencesData.getInteger("serial.debug_rate");
    serialRates.setSelectedItem(serialRate + " " + tr("baud"));
    onSerialRateChange(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
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
      }
    });

    messageBuffer = new StringBuffer();
  }
  
  protected void onCreateWindow(Container mainPane) {
    mainPane.setLayout(new BorderLayout());
    
    Font consoleFont = Theme.getFont("console.font");
    Font editorFont = PreferencesData.getFont("editor.font");
    Font font = new Font(consoleFont.getName(), consoleFont.getStyle(), editorFont.getSize());
   
    buffer = new CircularBuffer(500);
    graphPanel = new GraphPanel();
    
    mainPane.add(graphPanel, BorderLayout.CENTER);
    
    JPanel pane = new JPanel();
    pane.setLayout(new BoxLayout(pane, BoxLayout.X_AXIS));
    pane.setBorder(new EmptyBorder(4, 4, 4, 4));
    
    serialRates = new JComboBox();
    for (int i = 0; i < serialRateStrings.length; i++)
      serialRates.addItem(serialRateStrings[i] + " " + tr("baud"));
    
    serialRates.setMaximumSize(serialRates.getMinimumSize());

    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(serialRates);
    
    mainPane.add(pane, BorderLayout.SOUTH);
  }
  
  protected void onEnableWindow(boolean enable)
  {
    serialRates.setEnabled(enable); 
  }
  
  public void onSerialRateChange(ActionListener listener) {
    serialRates.addActionListener(listener);
  }
  
  public void message(final String s) {
    messageBuffer.append(s);
    while(true) {
      int linebreak = messageBuffer.indexOf("\n");
      if(linebreak == -1) {
        break;
      }
    
      String line = messageBuffer.substring(0, linebreak);
      line = line.trim();
      messageBuffer.delete(0, linebreak + 1);
    
      try {
        double value = Double.valueOf(line);
        buffer.add(value);
      } catch(NumberFormatException e) {
        continue; // ignore lines that can't be cast to a number
      }
    }

    SwingUtilities.invokeLater(new Runnable() {
      public void run() {        
        SerialPlotter.this.repaint();
    }});
  }
  
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

  public void close() throws Exception {
    if (serial != null) {
      super.close();
      int[] location = getPlacement();
      String locationStr = PApplet.join(PApplet.str(location), ",");
      PreferencesData.set("last.serial.location", locationStr);
      serial.dispose();
      serial = null;
    }
  }
}
