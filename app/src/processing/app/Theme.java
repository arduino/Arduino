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

import static processing.app.I18n.format;
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
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import java.util.Properties;
import java.util.TreeMap;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import javax.swing.text.StyleContext;

import org.apache.batik.transcoder.Transcoder;
import org.apache.batik.transcoder.TranscoderException;
import org.apache.batik.transcoder.TranscoderInput;
import org.apache.batik.transcoder.TranscoderOutput;
import org.apache.batik.transcoder.image.PNGTranscoder;
import org.apache.commons.compress.utils.IOUtils;
import org.apache.commons.lang3.StringUtils;
import processing.app.helpers.OSUtils;
import processing.app.helpers.PreferencesHelper;
import processing.app.helpers.PreferencesMap;

/**
 * Storage class for theme settings. This was separated from the Preferences
 * class for 1.0 so that the coloring wouldn't conflict with previous releases
 * and to make way for future ability to customize.
 */
public class Theme {
  
  static final String THEME_DIR = "theme/";
  static final String THEME_FILE_NAME = "theme.txt";
  
  static final String NAMESPACE_APP = "app:";
  static final String NAMESPACE_USER = "user:";
  
  /**
   * A theme resource, this is returned instead of {@link File} so that we can
   * support zip-packaged resources as well as files in the file system
   */
  public static class Resource {
    
    // Priority levels used to determine whether one resource should override
    // another
    static public final int PRIORITY_DEFAULT = 0;
    static public final int PRIORITY_USER_ZIP = 1;
    static public final int PRIORITY_USER_FILE = 2;
    
    /**
     * Priority of this resource.
     */
    private final int priority;
    
    /**
     * Resource name (original name of requested resource, relative path only).
     */
    private final String name;
    
    /**
     * File if this resource represents a file, can be null. 
     */
    private final File file;
    
    /**
     * Zip theme if the resource is contained within a zipped theme 
     */
    private final ZippedTheme theme;
    
    /**
     * Zip entry if this resource represents a zip entry, can be null.
     */
    private final ZipEntry zipEntry;
    
    /**
     * URL of this resource regardless of type, theoretically shouldn't ever be
     * null though it might be if a particular resource path can't be
     * successfully transformed into a URL (eg. {@link Theme#getUrl} traps a
     * <tt>MalformedURLException</tt>).
     */
    private final URL url;
    
    /**
     * If this resource supercedes a resource with a lower priority, this field
     * stores a reference to the superceded resource. This allows consumers to
     * traverse the resource hierarchy if required.
     */
    private Resource parent;

    /**
     * ctor for file resources
     */
    Resource(int priority, String name, URL url, File file) {
      this(priority, name, url, file, null, null);
    }
    
    /**
     * ctor for zip resources
     */
    Resource(int priority, String name, URL url, ZippedTheme theme, ZipEntry entry) {
      this(priority, name, url, null, theme, entry);
    }

    private Resource(int priority, String name, URL url, File file, ZippedTheme theme, ZipEntry zipEntry) {
      this.priority = priority;
      this.name = name;
      this.file = file;
      this.theme = theme;
      this.zipEntry = zipEntry;
      this.url = url;
    }
    
    public Resource getParent() {
      return this.parent;
    }
    
    public String getName() {
      return this.name;
    }
    
    public URL getUrl() {
      return this.url;
    }
    
    public int getPriority() {
      return this.priority;
    }
    
    public boolean isUserDefined() {
      return this.priority > PRIORITY_DEFAULT;
    }
    
    public boolean exists() {
      return this.zipEntry != null ||  this.file == null || this.file.exists();
    }
    
    public InputStream getInputStream() throws IOException {
      if (this.file != null) {
        return new FileInputStream(this.file);
      }
      
      if (this.zipEntry != null) {
        return this.theme.getZip().getInputStream(this.zipEntry);
      }
      
      if (this.url != null) {
        return this.url.openStream();
      }
      
      throw new FileNotFoundException(this.name);
    }
    
    public String toString() {
      return this.name;
    }
    
    Resource withParent(Resource parent) {
      this.parent = parent;
      return this;
    }
  }
  
  /**
   * Struct which keeps information about a discovered .zip theme file
   */
  public static class ZippedTheme {
    
    /**
     * Configuration key, this key consists of a "namespace" which determines
     * the root folder the theme was found in without actually storing the path
     * itself, followed by the file name. 
     */
    private final String key;
    
    /**
     * File containing the theme 
     */
    private final File file;
    
    /**
     * Zip file handle for retrieving entries 
     */
    private final ZipFile zip;

    /**
     * Display name, defaulted to filename but can be read from metadata 
     */
    private final String name;
    
    /**
     * Version number, plain text string read from metadata 
     */
    private final String version;
    
    private ZippedTheme(String namespace, File file, ZipFile zip, String name, String version) {
      this.key = namespace + file.getName();
      this.file = file;
      this.zip = zip;
      this.name = name;
      this.version = version;
    }
    
    public String getKey() {
      return this.key;
    }
    
    public File getFile() {
      return this.file;
    }
    
    public ZipFile getZip() {
      return this.zip;
    }
    
    public String getName() {
      return this.name;
    }
    
    public String getVersion() {
      return this.version;
    }
    
    public String toString() {
      String description = String.format("%s %s (%s)", this.getName(), this.getVersion(), this.file.getName());
      return StringUtils.abbreviate(description, 40);
    }
    
    /**
     * Attempts to parse the supplied zip file as a theme file. This is largely
     * determined by the file being readable and containing a theme.txt entry.
     * Returns null if the file is unreadable or doesn't contain theme.txt 
     */
    static ZippedTheme load(String namespace, File file) {
      ZipFile zip = null;
      try {
        zip = new ZipFile(file);
        ZipEntry themeTxtEntry = zip.getEntry(THEME_FILE_NAME);
        if (themeTxtEntry != null) {
          String name = file.getName().substring(0, file.getName().length() - 4);
          String version = "";
          
          ZipEntry themePropsEntry = zip.getEntry("theme.properties");
          if (themePropsEntry != null) {
            Properties themeProperties = new Properties();
            themeProperties.load(zip.getInputStream(themePropsEntry));
            
            name = themeProperties.getProperty("name", name);
            version = themeProperties.getProperty("version", version);
          }
          
          return new ZippedTheme(namespace, file, zip, name, version);
        }
      } catch (Exception ex) {
        System.err.println(format(tr("Error loading theme {0}: {1}"),
                                  file.getAbsolutePath(), ex.getMessage()));
        IOUtils.closeQuietly(zip);
      }
      
      return null;
    }
    
  }

  /**
   * Copy of the defaults in case the user mangles a preference.
   */
  static PreferencesMap defaults;
  /**
   * Table of attributes/values for the theme.
   */
  static PreferencesMap table = new PreferencesMap();
  
  /**
   * Available zipped themes 
   */
  static private final Map<String, ZippedTheme> availableThemes = new TreeMap<>();
  
  /**
   * Zip file containing user-defined theme elements 
   */
  static private ZippedTheme zipTheme;
  
  static protected void init() {
    zipTheme = openZipTheme();

    try {
      loadFromResource(table, THEME_DIR + THEME_FILE_NAME);
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
  
  static private ZippedTheme openZipTheme() {
    refreshAvailableThemes();
    String selectedTheme = PreferencesData.get("theme.file", "");
    synchronized(availableThemes) {
      return availableThemes.get(selectedTheme);
    }
  }
  
  static private void refreshAvailableThemes() {
    Map<String, ZippedTheme> discoveredThemes = new TreeMap<>();
    
    refreshAvailableThemes(discoveredThemes, NAMESPACE_APP, new File(BaseNoGui.getContentFile("lib"), THEME_DIR));
    refreshAvailableThemes(discoveredThemes, NAMESPACE_USER, new File(BaseNoGui.getSketchbookFolder(), THEME_DIR));
    
    synchronized (availableThemes) {
      availableThemes.clear();
      availableThemes.putAll(discoveredThemes);
    }
  }

  static private void refreshAvailableThemes(Map<String, ZippedTheme> discoveredThemes, String namespace, File folder) {
    if (!folder.isDirectory()) {
      return;
    }
    
    for (File zipFile : folder.listFiles((dir, name) -> name.endsWith(".zip"))) {
      ZippedTheme theme = ZippedTheme.load(namespace, zipFile);
      if (theme != null) {
        discoveredThemes.put(theme.getKey(), theme);
      }
    }
  }
  
  public static Collection<ZippedTheme> getAvailablethemes() {
    refreshAvailableThemes();
    return Collections.unmodifiableCollection(availableThemes.values());
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
    return BaseNoGui.getPlatform().getSystemDPI() * 100 / 96;
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
      if (font == null) {
        return null;
      }
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
      Map<TextAttribute, Object> attr = new Hashtable<>();
      attr.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
      styledFont = styledFont.deriveFont(attr);
    }

    Map<String, Object> result = new HashMap<>();
    result.put("color", color);
    result.put("font", styledFont);

    return result;
  }

  /**
   * Return an Image object from inside the Processing lib folder.
   */
  static public Image getLibImage(String filename, Component who, int width,
                                  int height) {
    Image image = null;

    // Use vector image when available
    Resource vectorFile = getThemeResource(filename + ".svg");
    if (vectorFile.exists()) {
      try {
        image = imageFromSVG(vectorFile.getUrl(), width, height);
      } catch (Exception e) {
        System.err.println("Failed to load " + vectorFile + ": " + e.getMessage());
      }
    }

    Resource bitmapFile = getThemeResource(filename + ".png");
    
    // Otherwise fall-back to PNG bitmaps, allowing user-defined bitmaps to
    // override built-in svgs
    if (image == null || bitmapFile.getPriority() > vectorFile.getPriority()) {
      Resource bitmap2xFile = getThemeResource(filename + "@2x.png");

      Resource imageFile;
      if (((getScale() > 125 && bitmap2xFile.exists()) || !bitmapFile.exists())
          && (bitmapFile.isUserDefined() && bitmap2xFile.isUserDefined())) {
        imageFile = bitmap2xFile;
      } else {
        imageFile = bitmapFile;
      }
      Toolkit tk = Toolkit.getDefaultToolkit();
      image = tk.getImage(imageFile.getUrl());
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
    return getLibImage(THEME_DIR + name, who, width, height);
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
  
  /**
   * Loads the supplied {@link PreferencesMap} from the specified resource,
   * recursively loading parent resources such that entries are loaded in order
   * of priority (lowest first).
   * 
   * @param map preference map to populate
   * @param name name of resource to load
   */
  static public PreferencesMap loadFromResource(PreferencesMap map, String name) throws IOException {
    return loadFromResource(map, getThemeResource(name));
  }

  static private PreferencesMap loadFromResource(PreferencesMap map, Resource resource) throws IOException {
    if (resource != null) {
      loadFromResource(map, resource.getParent());
      map.load(resource.getInputStream());
    }
    return map;
  }

  /**
   * @param name
   * @return
   */
  static public Resource getThemeResource(String name) {
    File defaultfile = getDefaultFile(name);
    Resource resource = new Resource(Resource.PRIORITY_DEFAULT, name, getUrl(defaultfile), defaultfile);
    
    ZipEntry themeZipEntry = getThemeZipEntry(name);
    if (themeZipEntry != null) {
      resource = new Resource(Resource.PRIORITY_USER_ZIP, name, getUrl(themeZipEntry), zipTheme, themeZipEntry).withParent(resource);
    }
    
    File themeFile = getThemeFile(name);
    if (themeFile != null) {
      resource = new Resource(Resource.PRIORITY_USER_FILE, name, getUrl(themeFile), themeFile).withParent(resource);
    }
    
    return resource;
  }
  
  static private File getThemeFile(String name) {
    File sketchBookThemeFolder = new File(BaseNoGui.getSketchbookFolder(), THEME_DIR);
    File themeFile = new File(sketchBookThemeFolder, name);
    if (themeFile.exists()) {
      return themeFile;
    }
    
    if (name.startsWith(THEME_DIR)) {
      themeFile = new File(sketchBookThemeFolder, name.substring(THEME_DIR.length()));
      if (themeFile.exists()) {
        return themeFile;
      }
    }
    
    return null;
  }
  
  static private ZipEntry getThemeZipEntry(String name) {
    if (zipTheme == null) {
      return null;
    }
    
    if (name.startsWith(THEME_DIR)) {
      name = name.substring(THEME_DIR.length());
    }
    
    return zipTheme.getZip().getEntry(name);
  }
  
  static private File getDefaultFile(String name) {
    return new File(BaseNoGui.getContentFile("lib"), name);
  }
  
  static URL getUrl(File file) {
    try {
      return file.toURI().toURL();
    } catch (MalformedURLException ex) {
      return null;
    }
  }
  
  static URL getUrl(ZipEntry entry) {
    try {
      // Adjust file name for URL format on Windows
      String zipFile = zipTheme.getZip().getName().replace('\\', '/');
      if (!zipFile.startsWith("/")) {
        zipFile = "/" + zipFile;
      }
      
      // Construct a URL which points to the internal resource
      URI uri = new URI("jar", "file:" + zipFile + "!/" + entry.getName(), null);
      return uri.toURL();
      
    } catch (MalformedURLException | URISyntaxException ex) {
      return null;
    }
  }
}
