package cc.arduino.utils.network;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CacheControl {


  // see org.apache.abdera.protocol.util.CacheControlUtil
  private static final Pattern PATTERN
    = Pattern.compile("\\s*([\\w\\-]+)\\s*(=)?\\s*(\\-?\\d+|\\\"([^\"\\\\]*(\\\\.[^\"\\\\]*)*)+\\\")?\\s*");

  private int maxAge = -1;

  private boolean isMustRevalidate = false;

  private boolean isNoCache = false;

  private boolean isNoStore = false;


  public static CacheControl valueOf(String value) {
    CacheControl cc = new CacheControl();

    if (value != null) {
      Matcher matcher = PATTERN.matcher(value);
      while (matcher.find()) {
        switch (matcher.group(1).toLowerCase()) {
        case "max-age":
          cc.setMaxAge(Integer.parseInt(matcher.group(3))); break;
        case "must-revalidate":
          cc.setMustRevalidate(true); break;
        case "no-cache":
          cc.setNoCache(true); break;
        case "no-store":
          cc.setNoStore(true); break;
        default: //ignore
        }
      }
    }
    return cc;
  }

  public void setMaxAge(int maxAge) {
    this.maxAge = maxAge;
  }

  public int getMaxAge() {
    return maxAge;
  }

  public boolean isMustRevalidate() {
    return isMustRevalidate;
  }

  public void setMustRevalidate(boolean mustRevalidate) {
    isMustRevalidate = mustRevalidate;
  }

  public boolean isNoCache() {
    return isNoCache;
  }

  public void setNoCache(boolean noCache) {
    isNoCache = noCache;
  }

  public boolean isNoStore() {
    return isNoStore;
  }

  public void setNoStore(boolean noStore) {
    isNoStore = noStore;
  }

  @Override
  public String toString() {
    return "CacheControl{" +
      "maxAge=" + maxAge +
      ", isMustRevalidate=" + isMustRevalidate +
      ", isNoCache=" + isNoCache +
      ", isNoStore=" + isNoStore +
      '}';
  }
}
