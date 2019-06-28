package cc.arduino.utils.network;

import cc.arduino.net.CustomProxySelector;
import org.apache.commons.codec.binary.Base64;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;

import javax.script.ScriptException;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.Proxy;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.function.Consumer;
import java.util.logging.Level;
import java.util.logging.Logger;

public class HttpConnectionManager {
  private static Logger log = Logger
    .getLogger(HttpConnectionManager.class.getName());
  private final URL requestURL;
  private final String userAgent;
  private int connectTimeout;


  public HttpConnectionManager(URL requestURL) {
    this.requestURL = requestURL;
    final String defaultUserAgent = String.format(
      "ArduinoIDE/%s (%s; %s; %s; %s) Java/%s (%s)",
      BaseNoGui.VERSION_NAME,
      System.getProperty("os.name"),
      System.getProperty("os.version"),
      System.getProperty("os.arch"),
      System.getProperty("user.language"),
      System.getProperty("java.version"),
      System.getProperty("java.vendor")
    );
    this.userAgent = PreferencesData.get("http.user_agent", defaultUserAgent);
    try {
      this.connectTimeout =
        Integer.parseInt(
          PreferencesData.get("http.connection_timeout", "5000"));
    } catch (NumberFormatException e) {
      log.log(Level.WARNING,
        "Cannot parse the http.connection_timeout configuration switch to default 5000 milliseconds", e.getCause());
      this.connectTimeout = 5000;
    }

  }

  public HttpURLConnection makeConnection(Consumer<HttpURLConnection> beforeConnection)
    throws URISyntaxException, NoSuchMethodException, IOException,
    ScriptException {
    return makeConnection(this.requestURL, 0, beforeConnection);
  }

  private HttpURLConnection makeConnection(URL requestURL, int movedTimes,
                                           Consumer<HttpURLConnection> beforeConnection)
    throws NoSuchMethodException, ScriptException, IOException,
    URISyntaxException {
    log.info("Prepare http request to " + requestURL);
    if (requestURL == null) {
      log.warning("Invalid request url is null");
      throw new RuntimeException("Invalid request url is null");
    }
    if (movedTimes > 3) {
      log.warning("Too many redirect " + requestURL);
      throw new RuntimeException("Too many redirect " + requestURL);
    }

    Proxy proxy = new CustomProxySelector(PreferencesData.getMap())
      .getProxyFor(requestURL.toURI());
    if ("true".equals(System.getProperty("DEBUG"))) {
      System.err.println("Using proxy " + proxy);
    }

    HttpURLConnection connection = (HttpURLConnection) requestURL
      .openConnection(proxy);
    connection.setRequestProperty("User-agent", userAgent);
    if (requestURL.getUserInfo() != null) {
      String auth = "Basic " + new String(
        new Base64().encode(requestURL.getUserInfo().getBytes()));
      connection.setRequestProperty("Authorization", auth);
    }

    int initialSize = 0;
    connection.setRequestProperty("Range", "bytes=" + initialSize + "-");
    connection.setConnectTimeout(connectTimeout);
    beforeConnection.accept(connection);

    // Connect
    log.info("Connect to " + requestURL);

    connection.connect();
    int resp = connection.getResponseCode();

    if (resp == HttpURLConnection.HTTP_MOVED_PERM
        || resp == HttpURLConnection.HTTP_MOVED_TEMP) {

      URL newUrl = new URL(connection.getHeaderField("Location"));
      log.info("The response code was a 301,302 so try again with the new URL " + newUrl);

      return this.makeConnection(newUrl, movedTimes + 1, beforeConnection);
    }
    log.info("The response code was" + resp);

    return connection;
  }

  public void setConnectTimeout(int connectTimeout) {
    this.connectTimeout = connectTimeout;
  }
}

