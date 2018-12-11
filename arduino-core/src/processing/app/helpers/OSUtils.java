package processing.app.helpers;

public class OSUtils {

  /**
   * returns true if running on windows.
   */
  static public boolean isWindows() {
    //return PApplet.platform == PConstants.WINDOWS;
    return System.getProperty("os.name").contains("Windows");
  }

  /**
   * true if running on linux.
   */
  static public boolean isLinux() {
    //return PApplet.platform == PConstants.LINUX;
    return System.getProperty("os.name").contains("Linux");
  }

  /**
   * returns true if Processing is running on a Mac OS X machine.
   */
  static public boolean isMacOS() {
    //return PApplet.platform == PConstants.MACOSX;
    return System.getProperty("os.name").contains("Mac");
  }

  static public boolean hasMacOSStyleMenus() {
    return OSUtils.isMacOS() && "true".equals(System.getProperty("apple.laf.useScreenMenuBar"));
  }

  static public String version() {
    return System.getProperty("os.version");
  }
}
