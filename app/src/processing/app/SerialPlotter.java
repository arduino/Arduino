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
import processing.app.helpers.CircularBuffer;
import processing.app.helpers.Ticks;
import processing.app.legacy.PApplet;

import java.util.ArrayList;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;

import static processing.app.I18n.tr;

public class SerialPlotter extends AbstractMonitor {

  private final StringBuffer messageBuffer;
  private JComboBox<String> serialRates;
  private Serial serial;
  private int serialRate;

  private ArrayList<Graph> graphs;
  private final static int BUFFER_CAPACITY = 500;

  private static class Graph {
    public CircularBuffer buffer;
    private Color color;

    public Graph(int id) {
      buffer = new CircularBuffer(BUFFER_CAPACITY);
      color = Theme.getColorCycleColor("plotting.graphcolor", id);
    }

    public void paint(Graphics2D g, float xstep, double minY, 
                      double maxY, double rangeY, double height) {
      g.setColor(color);
      g.setStroke(new BasicStroke(1.0f));

      for (int i = 0; i < buffer.size() - 1; ++i) {
        g.drawLine(
          (int) (i * xstep), (int) transformY(buffer.get(i), minY, rangeY, height),
          (int) ((i + 1) * xstep), (int) transformY(buffer.get(i + 1), minY, rangeY, height)
        );
      }
    }

    private float transformY(double rawY, double minY, double rangeY, double height) {
      return (float) (5 + (height - 10) * (1.0 - (rawY - minY) / rangeY));
    }
  }

  private class GraphPanel extends JPanel {
    private double minY, maxY, rangeY;
    private Rectangle bounds;
    private int xOffset;
    private final Font font;
    private final Color bgColor;

    public GraphPanel() {
      font = Theme.getFont("console.font");
      bgColor = Theme.getColor("plotting.bgcolor");
      xOffset = 20;
    }

    private Ticks computeBounds() {
      minY = Double.POSITIVE_INFINITY;
      maxY = Double.NEGATIVE_INFINITY;
      for(Graph g : graphs) {
        if (!g.buffer.isEmpty()) {
          minY = Math.min(g.buffer.min(), minY);
          maxY = Math.max(g.buffer.max(), maxY);
        }
      }

      final double MIN_DELTA = 10.0;
      if (maxY - minY < MIN_DELTA) {
        double mid = (maxY + minY) / 2;
        maxY = mid + MIN_DELTA / 2;
        minY = mid - MIN_DELTA / 2;
      }

      Ticks ticks = new Ticks(minY, maxY, 3);
      minY = Math.min(minY, ticks.getTick(0));
      maxY = Math.max(maxY, ticks.getTick(ticks.getTickCount() - 1));
      rangeY = maxY - minY;
      minY -= 0.05 * rangeY;
      maxY += 0.05 * rangeY;
      rangeY = maxY - minY;
      return ticks;
    }

    @Override
    public void paintComponent(Graphics g1) {
      Graphics2D g = (Graphics2D) g1;
      g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
      g.setFont(font);
      super.paintComponent(g);

      bounds = g.getClipBounds();
      setBackground(bgColor);
      if (graphs.isEmpty()) {
        return;
      }

      Ticks ticks = computeBounds();

      g.setStroke(new BasicStroke(1.0f));
      FontMetrics fm = g.getFontMetrics();
      for (int i = 0; i < ticks.getTickCount(); ++i) {
        double tick = ticks.getTick(i);
        Rectangle2D fRect = fm.getStringBounds(String.valueOf(tick), g);
        xOffset = Math.max(xOffset, (int) fRect.getWidth() + 15);

        // draw tick
        g.drawLine(xOffset - 5, (int) transformY(tick), xOffset + 2, (int) transformY(tick));
        // draw tick label
        g.drawString(String.valueOf(tick), xOffset - (int) fRect.getWidth() - 10, transformY(tick) - (float) fRect.getHeight() * 0.5f + fm.getAscent());
      }

      g.drawLine(bounds.x + xOffset, bounds.y + 5, bounds.x + xOffset, bounds.y + bounds.height - 10);

      g.setTransform(AffineTransform.getTranslateInstance(xOffset, 0));
      float xstep = (float) (bounds.width - xOffset) / (float) BUFFER_CAPACITY;
      int legendLength = graphs.size() * 10 + (graphs.size() - 1) * 3;

      for(int i = 0; i < graphs.size(); ++i) {
        graphs.get(i).paint(g, xstep, minY, maxY, rangeY, bounds.height);
        if(graphs.size() > 1) {    
          g.fillRect(bounds.width - (xOffset + legendLength + 10) + i * 13, 10, 10, 10);
        }
      }
    }

    private float transformY(double rawY) {
      return (float) (5 + (bounds.height - 10) * (1.0 - (rawY - minY) / rangeY));
    }

    @Override
    public Dimension getMinimumSize() {
      return new Dimension(200, 100);
    }

    @Override
    public Dimension getPreferredSize() {
      return new Dimension(500, 250);
    }
  }

  public SerialPlotter(BoardPort port) {
    super(port);

    serialRate = PreferencesData.getInteger("serial.debug_rate");
    serialRates.setSelectedItem(serialRate + " " + tr("baud"));
    onSerialRateChange(event -> {
      String wholeString = (String) serialRates.getSelectedItem();
      String rateString = wholeString.substring(0, wholeString.indexOf(' '));
      serialRate = Integer.parseInt(rateString);
      PreferencesData.set("serial.debug_rate", rateString);
      try {
        close();
        Thread.sleep(100); // Wait for serial port to properly close
        open();
      } catch (Exception e) {
        // ignore
      }
    });

    messageBuffer = new StringBuffer();
    graphs = new ArrayList<>();
  }

  protected void onCreateWindow(Container mainPane) {
    mainPane.setLayout(new BorderLayout());

    GraphPanel graphPanel = new GraphPanel();

    mainPane.add(graphPanel, BorderLayout.CENTER);

    JPanel pane = new JPanel();
    pane.setLayout(new BoxLayout(pane, BoxLayout.X_AXIS));
    pane.setBorder(new EmptyBorder(4, 4, 4, 4));

    serialRates = new JComboBox<>();
    for (String serialRateString : serialRateStrings) serialRates.addItem(serialRateString + " " + tr("baud"));

    serialRates.setMaximumSize(serialRates.getMinimumSize());

    pane.add(Box.createRigidArea(new Dimension(8, 0)));
    pane.add(serialRates);

    mainPane.add(pane, BorderLayout.SOUTH);
  }

  protected void onEnableWindow(boolean enable) {
    serialRates.setEnabled(enable);
  }

  private void onSerialRateChange(ActionListener listener) {
    serialRates.addActionListener(listener);
  }

  public void message(final String s) {
    messageBuffer.append(s);
    while (true) {
      int linebreak = messageBuffer.indexOf("\n");
      if (linebreak == -1) {
        break;
      }

      String line = messageBuffer.substring(0, linebreak);
      messageBuffer.delete(0, linebreak + 1);

      line = line.trim();
      String[] parts = line.split("[, \t]+");
      if(parts.length == 0) {
        continue;
      }

      int validParts = 0;
      for(int i = 0; i < parts.length; ++i) {
        try {          
          double value = Double.valueOf(parts[i]);
          if(validParts >= graphs.size()) {
            graphs.add(new Graph(validParts));
          }
          graphs.get(validParts).buffer.add(value);
          validParts++;
        } catch (NumberFormatException e) {
          // ignore
        }
      }
    }

    SwingUtilities.invokeLater(SerialPlotter.this::repaint);
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
