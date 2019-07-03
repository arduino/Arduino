package cc.arduino.utils.network;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Represents a HTTP Cache-Control response header and parses it from string.
 *
 * <p>Note: This class ignores <tt>1#field-name</tt> parameter for
 * <tt>private</tt> and <tt>no-cache</tt> directive and cache extensions.</p>
 *
 * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9">HTTP/1.1 section 14.9</a>
 */
public class CacheControl {


  // copied from org.apache.abdera.protocol.util.CacheControlUtil
  private static final Pattern PATTERN
    = Pattern.compile("\\s*([\\w\\-]+)\\s*(=)?\\s*(\\-?\\d+|\\\"([^\"\\\\]*(\\\\.[^\"\\\\]*)*)+\\\")?\\s*");

  /**
   * Corresponds to the <tt>max-age</tt> cache control directive.
   * The default value is <tt>-1</tt>, i.e. not specified.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.3">HTTP/1.1 section 14.9.3</a>
   */
  private int maxAge = -1;

  /**
   * Corresponds to the <tt>s-maxage</tt> cache control directive.
   * The default value is <tt>-1</tt>, i.e. not specified.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.3">HTTP/1.1 section 14.9.3</a>
   */
  private int sMaxAge = -1;

  /**
   * Whether the <tt>must-revalidate</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.4">HTTP/1.1 section 14.9.4</a>
   */
  private boolean isMustRevalidate = false;

  /**
   * Whether the <tt>no-cache</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.1">HTTP/1.1 section 14.9.1</a>
   */
  private boolean isNoCache = false;

  /**
   * Whether the <tt>no-store</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.2">HTTP/1.1 section 14.9.2</a>
   */
  private boolean isNoStore = false;

  /**
   * Whether the <tt>no-transform</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.5">HTTP/1.1 section 14.9.5</a>
   */
  private boolean isNoTransform = false;

  /**
   * Whether the <tt>private</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.1">HTTP/1.1 section 14.9.1</a>
   */
  private boolean isPrivate = false;

  /**
   * Whether the <tt>public</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.1">HTTP/1.1 section 14.9.1</a>
   */
  private boolean isPublic = false;

  /**
   * Whether the <tt>proxy-revalidate</tt> directive is specified.
   * The default value is <tt>false</tt>.
   *
   * @see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9.4">HTTP/1.1 section 14.9.4</a>
   */
  private boolean isProxyRevalidate = false;


  /**
   * Creates a new instance of CacheControl by parsing the supplied string.
   *
   * @param value A value the Cache-Control header.
   */
  public static CacheControl valueOf(String value) {
    CacheControl cc = new CacheControl();

    if (value != null) {
      Matcher matcher = PATTERN.matcher(value);
      while (matcher.find()) {
        switch (matcher.group(1).toLowerCase()) {
        case "max-age":
          cc.setMaxAge(Integer.parseInt(matcher.group(3))); break;
        case "s-maxage":
          cc.setSMaxAge(Integer.parseInt(matcher.group(3))); break;
        case "must-revalidate":
          cc.setMustRevalidate(true); break;
        case "no-cache":
          cc.setNoCache(true); break;
        case "no-store":
          cc.setNoStore(true); break;
        case "no-transform":
          cc.setNoTransform(true); break;
        case "private":
          cc.setPrivate(true); break;
        case "public":
          cc.setPublic(true); break;
        case "proxy-revalidate":
          cc.setProxyRevalidate(true); break;
        default: //ignore
        }
      }
    }
    return cc;
  }

  /**
   * Returns <tt>max-age</tt>, or <tt>s-maxage</tt> according to whether
   * considering a shared cache, or a private cache. If shared cache and the
   * <tt>s-maxage</tt> is negative (i.e. not set), then returns
   * <tt>max-age</tt> instead.
   *
   * @param sharedCache <tt>true</tt> for a shared cache,
   *                    or <tt>false</tt> for a private cache
   * @return A {@link #maxAge}, or {@link #sMaxAge} according to the given
   *         sharedCache argument.
   */
  public int getMaxAge(boolean sharedCache) {
    if (sharedCache) {
      return sMaxAge >= 0 ? sMaxAge : maxAge;
    } else {
      return maxAge;
    }
  }

  public void setMaxAge(int maxAge) {
    this.maxAge = maxAge;
  }

  public int getMaxAge() {
    return maxAge;
  }

  public int getSMaxAge() {
    return sMaxAge;
  }

  public void setSMaxAge(int sMaxAge) {
    this.sMaxAge = sMaxAge;
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

  public boolean isNoTransform() {
    return isNoTransform;
  }

  public void setNoTransform(boolean noTransform) {
    isNoTransform = noTransform;
  }

  public boolean isPrivate() {
    return isPrivate;
  }

  public void setPrivate(boolean aPrivate) {
    isPrivate = aPrivate;
  }

  public boolean isPublic() {
    return isPublic;
  }

  public void setPublic(boolean aPublic) {
    isPublic = aPublic;
  }

  public boolean isProxyRevalidate() {
    return isProxyRevalidate;
  }

  public void setProxyRevalidate(boolean proxyRevalidate) {
    isProxyRevalidate = proxyRevalidate;
  }

  @Override
  public String toString() {
    return "CacheControl{" +
      "maxAge=" + maxAge +
      ", sMaxAge=" + sMaxAge +
      ", isMustRevalidate=" + isMustRevalidate +
      ", isNoCache=" + isNoCache +
      ", isNoStore=" + isNoStore +
      ", isNoTransform=" + isNoTransform +
      ", isPrivate=" + isPrivate +
      ", isPublic=" + isPublic +
      ", isProxyRevalidate=" + isProxyRevalidate +
      '}';
  }
}
