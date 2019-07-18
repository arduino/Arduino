/*
 * This file is part of Arduino.
 *
 * Copyright 2019 Arduino LLC (http://www.arduino.cc/)
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */

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
  private static final int maxRedirectNumber;
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
    // Set by default 20 max redirect to follow
    int maxRedirectNumberConfig = 20;
    try {
      maxRedirectNumberConfig =
        Integer.parseInt(
          PreferencesData.get("http.max_redirect_number", "20"));
    } catch (NumberFormatException e) {
      log.warn(
        "Cannot parse the http.max_redirect_number configuration switch to default {}", maxRedirectNumberConfig, e.getCause());
    }
    maxRedirectNumber = maxRedirectNumberConfig;
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
    if (movedTimes > maxRedirectNumber) {
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

