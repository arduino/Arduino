package cc.arduino.utils.network;

import cc.arduino.net.CustomProxySelector;
import org.apache.commons.codec.binary.Base64;
import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;

import javax.script.ScriptException;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.Proxy;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.function.Consumer;

public class HttpConnectionManager {
  private static Logger log = LoggerFactory.getLogger(HttpConnectionManager.class);
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
      log.warn(
        "Cannot parse the http.connection_timeout configuration switch to default 5000 milliseconds", e.getCause());
      this.connectTimeout = 5000;
    }

  }

  public HttpURLConnection makeConnection(Consumer<HttpURLConnection> beforeConnection)
    throws IOException, NoSuchMethodException, ScriptException, URISyntaxException {
    return makeConnection(this.requestURL, 0, beforeConnection);
  }


  public HttpURLConnection makeConnection()
    throws IOException, NoSuchMethodException, ScriptException, URISyntaxException {
    return makeConnection(this.requestURL, 0, (c) -> {});
  }

  private HttpURLConnection makeConnection(URL requestURL, int movedTimes,
                                           Consumer<HttpURLConnection> beforeConnection) throws IOException, URISyntaxException, ScriptException, NoSuchMethodException {
    log.info("Prepare http request to " + requestURL);
    if (movedTimes > 3) {
      log.warn("Too many redirect " + requestURL);
      throw new IOException("Too many redirect " + requestURL);
    }

    Proxy proxy = new CustomProxySelector(PreferencesData.getMap())
      .getProxyFor(requestURL.toURI());
    log.debug("Using proxy {}", proxy);

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
    log.info("Connect to {} with method {}", requestURL, connection.getRequestMethod());

    connection.connect();
    int resp = connection.getResponseCode();

    if (resp == HttpURLConnection.HTTP_MOVED_PERM
        || resp == HttpURLConnection.HTTP_MOVED_TEMP) {

      URL newUrl = new URL(connection.getHeaderField("Location"));
      log.info("The response code was a 301,302 so try again with the new URL " + newUrl);

      return this.makeConnection(newUrl, movedTimes + 1, beforeConnection);
    }
    log.info("The response code {}, headers {}", resp, StringUtils.join(connection.getHeaderFields()));

    return connection;
  }

  public void setConnectTimeout(int connectTimeout) {
    this.connectTimeout = connectTimeout;
  }
}

