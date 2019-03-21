package processing.app.helpers;

public class StringUtils {

  /**
   * Returns the string without trailing whitespace characters
   * 
   * @param s
   * @return
   */
  public static String rtrim(String s) {
    int i = s.length() - 1;
    while (i >= 0 && Character.isWhitespace(s.charAt(i))) {
      i--;
    }
    return s.substring(0, i + 1);
  }
}
