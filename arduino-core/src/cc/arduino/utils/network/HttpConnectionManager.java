package cc.arduino.utils.network;

import cc.arduino.net.CustomProxySelector;
import org.apache.commons.codec.binary.Base64;
import org.apache.commons.lang3.StringUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;

import javax.script.ScriptException;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.Proxy;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.UUID;
import java.util.function.Consumer;

public class HttpConnectionManager {
  private static Logger log = LogManager.getLogger(HttpConnectionManager.class);
  private static final String userAgent;
  private static final int connectTimeout;
  private final URL requestURL;
  private final String id;

  static {
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
    userAgent = PreferencesData.get("http.user_agent", defaultUserAgent);
    int connectTimeoutFromConfig = 5000;
    try {
      connectTimeoutFromConfig =
        Integer.parseInt(
          PreferencesData.get("http.connection_timeout_ms", "5000"));
    } catch (NumberFormatException e) {
      log.warn(
        "Cannot parse the http.connection_timeout configuration switch to default {} milliseconds", connectTimeoutFromConfig, e.getCause());
    }
    connectTimeout = connectTimeoutFromConfig;
  }

  public HttpConnectionManager(URL requestURL) {
    this.requestURL = requestURL;
    if (requestURL.getHost().endsWith("arduino.cc")) {
      final String idString = PreferencesData.get("update.id", "0");
      id = Long.toString(Long.parseLong(idString));
    } else {
      id = null;
    }

  }

  public HttpURLConnection makeConnection(Consumer<HttpURLConnection> beforeConnection)
    throws IOException, NoSuchMethodException, ScriptException, URISyntaxException {
    return makeConnection(this.requestURL, 0, beforeConnection);
  }


  public HttpURLConnection makeConnection()
    throws IOException, NoSuchMethodException, ScriptException, URISyntaxException {
    return makeConnection(this.requestURL, 0, (c) -> {
    });
  }

  private HttpURLConnection makeConnection(URL requestURL, int movedTimes,
                                           Consumer<HttpURLConnection> beforeConnection) throws IOException, URISyntaxException, ScriptException, NoSuchMethodException {
    if (movedTimes > 3) {
      log.warn("Too many redirect " + requestURL);
      throw new IOException("Too many redirect " + requestURL);
    }

    Proxy proxy = new CustomProxySelector(PreferencesData.getMap())
      .getProxyFor(requestURL.toURI());
    log.debug("Using proxy {}", proxy);

    final String requestId = UUID.randomUUID().toString()
      .toUpperCase().replace("-", "").substring(0, 16);
    HttpURLConnection connection = (HttpURLConnection) requestURL
      .openConnection(proxy);
    connection.setRequestProperty("User-agent", userAgent);
    connection.setRequestProperty("X-Request-ID", requestId);
    if (id != null) {
      connection.setRequestProperty("X-ID", id);
    }
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
    log.info("Connect to {}, method={}, request id={}", requestURL, connection.getRequestMethod(), requestId);

    connection.connect();
    int resp = connection.getResponseCode();
    log.info("Request complete URL=\"{}\", method={}, response code={}, request id={}, headers={}",
      requestURL, connection.getRequestMethod(), resp, requestId, StringUtils.join(connection.getHeaderFields()));

    if (resp == HttpURLConnection.HTTP_MOVED_PERM
      || resp == HttpURLConnection.HTTP_MOVED_TEMP) {

      URL newUrl = new URL(connection.getHeaderField("Location"));
      log.info("The response code was a 301,302 so try again with the new URL " + newUrl);

      return this.makeConnection(newUrl, movedTimes + 1, beforeConnection);
    }

    return connection;
  }

}

