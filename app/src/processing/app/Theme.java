/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-06 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

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

import static processing.app.I18n.tr;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.SystemColor;
import java.awt.Toolkit;
import java.awt.font.TextAttribute;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.net.URL;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;

import javax.swing.text.StyleContext;

import org.apache.batik.transcoder.Transcoder;
import org.apache.batik.transcoder.TranscoderException;
import org.apache.batik.transcoder.TranscoderInput;
import org.apache.batik.transcoder.TranscoderOutput;
import org.apache.batik.transcoder.image.PNGTranscoder;

import processing.app.helpers.OSUtils;
import processing.app.helpers.PreferencesHelper;
import processing.app.helpers.PreferencesMap;

/**
 * Storage class for theme settings. This was separated from the Preferences
 * class for 1.0 so that the coloring wouldn't conflict with previous releases
 * and to make way for future ability to customize.
 */
public class Theme {

  /**
   * Copy of the defaults in case the user mangles a preference.
   */
  static PreferencesMap defaults;
  /**
   * Table of attributes/values for the theme.
   */
  static PreferencesMap table = new PreferencesMap();

  static protected void init() {
    try {
      table.load(new File(BaseNoGui.getContentFile("lib"), "theme/theme.txt"));
    } catch (Exception te) {
      Base.showError(null, tr("Could not read color theme settings.\n"
                              + "You'll need to reinstall Arduino."),
                     te);
    }

    // other things that have to be set explicitly for the defaults
    setColor("run.window.bgcolor", SystemColor.control);

    // clone the hash table
    defaults = new PreferencesMap(table);
  }

  static public String get(String attribute) {
    return table.get(attribute);
  }

  static public String getDefault(String attribute) {
    return defaults.get(attribute);
  }

  static public void set(String attribute, String value) {
    table.put(attribute, value);
  }

  static public boolean getBoolean(String attribute) {
    return table.getBoolean(attribute);
  }

  static public void setBoolean(String attribute, boolean value) {
    table.putBoolean(attribute, value);
  }

  static public int getInteger(String attribute) {
    return Integer.parseInt(get(attribute));
  }

  static public void setInteger(String key, int value) {
    set(key, String.valueOf(value));
  }

  static public int getScale() {
    try {
      int scale = PreferencesData.getInteger("gui.scale", -1);
      if (scale != -1)
        return scale;
    } catch (NumberFormatException ignore) {
    }
    return 100;
  }

  static public int scale(int size) {
    return size * getScale() / 100;
  }

  static public Dimension scale(Dimension dim) {
    return new Dimension(scale(dim.width), scale(dim.height));
  }

  static public Font scale(Font font) {
    float size = scale(font.getSize());
    // size must be float to call the correct Font.deriveFont(float)
    // method that is different from Font.deriveFont(int)!
    Font scaled = font.deriveFont(size);
    return scaled;
  }

  static public Rectangle scale(Rectangle rect) {
    Rectangle res = new Rectangle(rect);
    res.x = scale(res.x);
    res.y = scale(res.y);
    res.width = scale(res.width);
    res.height = scale(res.height);
    return res;
  }

  static public Color getColorCycleColor(String name, int i) {
    int cycleSize = getInteger(name + ".size");
    name = String.format("%s.%02d", name, i % cycleSize);
    return PreferencesHelper.parseColor(get(name));
  }

  static public void setColorCycleColor(String name, int i, Color color) {
    name = String.format("%s.%02d", name, i);
    PreferencesHelper.putColor(table, name, color);
    int cycleSize = getInteger(name + ".size");
    setInteger(name + ".size", (i + 1) > cycleSize ? (i + 1) : cycleSize);
  }

  static public Color getColor(String name) {
    return PreferencesHelper.parseColor(get(name));
  }

  static public void setColor(String attr, Color color) {
    PreferencesHelper.putColor(table, attr, color);
  }

  static public Font getFont(String attr) {
    Font font = PreferencesHelper.getFont(table, attr);
    if (font == null) {
      String value = getDefault(attr);
      set(attr, value);
      font = PreferencesHelper.getFont(table, attr);
    }
    return font.deriveFont((float) scale(font.getSize()));
  }

  /**
   * Returns the default font for text areas.
   *
   * @return The default font.
   */
  public static final Font getDefaultFont() {

    // Use StyleContext to get a composite font for better Asian language
    // support; see Sun bug S282887.
    StyleContext sc = StyleContext.getDefaultStyleContext();
    Font font = null;

    if (OSUtils.isMacOS()) {
      // Snow Leopard (1.6) uses Menlo as default monospaced font,
      // pre-Snow Leopard used Monaco.
      font = sc.getFont("Menlo", Font.PLAIN, 12);
      if (!"Menlo".equals(font.getFamily())) {
        font = sc.getFont("Monaco", Font.PLAIN, 12);
        if (!"Monaco".equals(font.getFamily())) { // Shouldn't happen
          font = sc.getFont("Monospaced", Font.PLAIN, 13);
        }
      }
    } else {
      // Consolas added in Vista, used by VS2010+.
      font = sc.getFont("Consolas", Font.PLAIN, 13);
      if (!"Consolas".equals(font.getFamily())) {
        font = sc.getFont("Monospaced", Font.PLAIN, 13);
      }
    }

    // System.out.println(font.getFamily() + ", " + font.getName());
    return font;
  }

  public static Map<String, Object> getStyledFont(String what, Font font) {
    String split[] = get("editor." + what + ".style").split(",");

    Color color = PreferencesHelper.parseColor(split[0]);

    String style = split[1];
    boolean bold = style.contains("bold");
    boolean italic = style.contains("italic");
    boolean underlined = style.contains("underlined");

    Font styledFont = new Font(font.getFamily(),
        (bold ? Font.BOLD : 0) | (italic ? Font.ITALIC : 0), font.getSize());
    if (underlined) {
      Map<TextAttribute, Object> attr = new Hashtable<TextAttribute, Object>();
      attr.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
      styledFont = styledFont.deriveFont(attr);
    }

    Map<String, Object> result = new HashMap<String, Object>();
    result.put("color", color);
    result.put("font", styledFont);

    return result;
  }

  /**
   * Return an Image object from inside the Processing lib folder.
   */
  static public Image getLibImage(String filename, Component who, int width,
                                  int height) {
    File libFolder = BaseNoGui.getContentFile("lib");
    Image image = null;

    // Use vector image when available
    File vectorFile = new File(libFolder, filename + ".svg");
    if (vectorFile.exists()) {
      try {
        image = imageFromSVG(vectorFile.toURI().toURL(), width, height);
      } catch (Exception e) {
        System.err.println("Failed to load " + vectorFile.getAbsolutePath()
                           + ": " + e.getMessage());
      }
    }

    // Otherwise fall-back to PNG bitmaps
    if (image == null) {
      File bitmapFile = new File(libFolder, filename + ".png");
      File bitmap2xFile = new File(libFolder, filename + "@2x.png");

      File imageFile;
      if ((getScale() > 125 && bitmap2xFile.exists()) || !bitmapFile.exists()) {
        imageFile = bitmap2xFile;
      } else {
        imageFile = bitmapFile;
      }
      Toolkit tk = Toolkit.getDefaultToolkit();
      image = tk.getImage(imageFile.getAbsolutePath());
    }

    MediaTracker tracker = new MediaTracker(who);
    try {
      tracker.addImage(image, 0);
      tracker.waitForAll();
    } catch (InterruptedException e) {
    }

    if (image.getWidth(null) != width || image.getHeight(null) != height) {
      image = image.getScaledInstance(width, height, Image.SCALE_SMOOTH);
      try {
        tracker.addImage(image, 1);
        tracker.waitForAll();
      } catch (InterruptedException e) {
      }
    }

    return image;
  }

  /**
   * Get an image associated with the current color theme.
   */
  static public Image getThemeImage(String name, Component who, int width,
                                    int height) {
    return getLibImage("theme/" + name, who, width, height);
  }

  private static Image imageFromSVG(URL url, int width, int height)
      throws TranscoderException {
    Transcoder t = new PNGTranscoder();
    t.addTranscodingHint(PNGTranscoder.KEY_WIDTH, new Float(width));
    t.addTranscodingHint(PNGTranscoder.KEY_HEIGHT, new Float(height));

    TranscoderInput input = new TranscoderInput(url.toString());
    ByteArrayOutputStream ostream = new ByteArrayOutputStream();
    TranscoderOutput output = new TranscoderOutput(ostream);
    t.transcode(input, output);

    byte[] imgData = ostream.toByteArray();
    return Toolkit.getDefaultToolkit().createImage(imgData);
  }

  static public Graphics2D setupGraphics2D(Graphics graphics) {
    Graphics2D g = (Graphics2D) graphics;
    if (PreferencesData.getBoolean("editor.antialias")) {
      g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
                         RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
    }
    return g;
  }

}
