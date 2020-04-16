/*
 * This file is part of Arduino.
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
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino.net;

import java.io.IOException;
import java.net.Authenticator;
import java.net.HttpURLConnection;
import java.net.InetSocketAddress;
import java.net.MalformedURLException;
import java.net.PasswordAuthentication;
import java.net.Proxy;
import java.net.ProxySelector;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.Charset;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Stream;

import javax.script.Invocable;
import javax.script.ScriptContext;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

import org.apache.commons.compress.utils.IOUtils;

import cc.arduino.Constants;

public class CustomProxySelector {

  private final Map<String, String> preferences;

  public CustomProxySelector(Map<String, String> preferences) {
    this.preferences = preferences;
    clearPreviousAuthenticator();
  }

  public Optional<URI> getProxyURIFor(URI uri) throws URISyntaxException {
    String auth = "";
    String user = preferences.getOrDefault(Constants.PREF_PROXY_USERNAME, "");
    if (!user.isEmpty()) {
      String pass = preferences.getOrDefault(Constants.PREF_PROXY_PASSWORD, "");
      auth = user + ":" + pass + "@";
    }
    String host, port, proto;

    switch (preferences.get(Constants.PREF_PROXY_TYPE)) {
    default:
      return Optional.empty();

    case Constants.PROXY_TYPE_NONE:
      return Optional.empty();

    case Constants.PROXY_TYPE_MANUAL:
      host = preferences.get(Constants.PREF_PROXY_MANUAL_HOSTNAME);
      port = preferences.get(Constants.PREF_PROXY_MANUAL_PORT);
      proto = preferences.get(Constants.PREF_PROXY_MANUAL_TYPE).toLowerCase();
      break;

    case Constants.PROXY_TYPE_AUTO:
      String pac = preferences.getOrDefault(Constants.PREF_PROXY_PAC_URL, "");
      if (pac.isEmpty()) {
        return Optional.empty();
      }

      try {
        String proxyConfigs = pacProxy(pac, uri);
        System.out.println(proxyConfigs);
        String proxyConfig = proxyConfigs.split(";")[0];
        if (proxyConfig.startsWith("DIRECT")) {
          return Optional.empty();
        }
        proto = proxyConfig.startsWith("PROXY ") ? "http" : "socks";
        proxyConfig = proxyConfig.substring(6);
        String[] hostPort = proxyConfig.split(":");
        host = hostPort[0];
        port = hostPort[1];
      } catch (Exception e) {
        e.printStackTrace();
        return Optional.empty();
      }
      break;
    }

    return Optional.of(new URI(proto + "://" + auth + host + ":" + port + "/"));
  }

  public Proxy getProxyFor(URI uri) throws IOException, ScriptException, NoSuchMethodException {
    String proxyType = preferences.get(Constants.PREF_PROXY_TYPE);
    if (proxyType == null || proxyType.isEmpty()) {
      proxyType = Constants.PROXY_TYPE_AUTO;
    }

    if (Constants.PROXY_TYPE_NONE.equals(proxyType)) {
      return Proxy.NO_PROXY;
    }

    if (Constants.PROXY_TYPE_AUTO.equals(proxyType)) {
      String pac = preferences.get(Constants.PREF_PROXY_PAC_URL);
      if (pac == null || pac.isEmpty()) {
        return ProxySelector.getDefault().select(uri).get(0);
      }

      return makeProxyFrom(pacProxy(pac, uri));
    }

    if (Constants.PROXY_TYPE_MANUAL.equals(proxyType)) {
      return manualProxy();
    }

    throw new IllegalStateException("Unable to understand proxy settings");
  }

  private String pacProxy(String pac, URI uri) throws IOException, ScriptException, NoSuchMethodException {
    setAuthenticator(preferences.get(Constants.PREF_PROXY_USERNAME), preferences.get(Constants.PREF_PROXY_PASSWORD));

    URLConnection urlConnection = new URL(pac).openConnection();
    urlConnection.connect();
    if (urlConnection instanceof HttpURLConnection) {
      int responseCode = ((HttpURLConnection) urlConnection).getResponseCode();
      if (responseCode != 200) {
        throw new IOException("Unable to fetch PAC file at " + pac + ". Response code is " + responseCode);
      }
    }
    String pacScript = new String(IOUtils.toByteArray(urlConnection.getInputStream()), Charset.forName("ASCII"));

    ScriptEngine nashorn = new ScriptEngineManager().getEngineByName("nashorn");
    nashorn.getBindings(ScriptContext.ENGINE_SCOPE).put("pac", new PACSupportMethods());
    Stream.of("isPlainHostName(host)",
      "dnsDomainIs(host, domain)",
      "localHostOrDomainIs(host, hostdom)",
      "isResolvable(host)",
      "isInNet(host, pattern, mask)",
      "dnsResolve(host)",
      "myIpAddress()",
      "dnsDomainLevels(host)",
      "shExpMatch(str, shexp)").forEach((fn) -> {
      try {
        nashorn.eval("function " + fn + " { return pac." + fn + "; }");
      } catch (ScriptException e) {
        throw new RuntimeException(e);
      }
    });
    nashorn.eval(pacScript);
    return callFindProxyForURL(uri, nashorn);
  }

  private String callFindProxyForURL(URI uri, ScriptEngine nashorn) throws ScriptException, NoSuchMethodException {
    Invocable script = (Invocable) nashorn;
    URL url = toUrl(uri);
    return (String) script.invokeFunction("FindProxyForURL", url.toExternalForm(), url.getHost());
  }

  private Proxy makeProxyFrom(String proxyConfigs) {
    String proxyConfig = proxyConfigs.split(";")[0];
    if (proxyConfig.startsWith("DIRECT")) {
      return Proxy.NO_PROXY;
    }
    Proxy.Type type;
    if (proxyConfig.startsWith("PROXY")) {
      type = Proxy.Type.HTTP;
      proxyConfig = proxyConfig.replace("PROXY ", "");
    } else {
      type = Proxy.Type.SOCKS;
      proxyConfig = proxyConfig.replace("SOCKS ", "");
    }
    String[] hostPort = proxyConfig.split(":");
    return new Proxy(type, new InetSocketAddress(hostPort[0], Integer.valueOf(hostPort[1])));
  }

  private URL toUrl(URI uri) {
    try {
      return uri.toURL();
    } catch (MalformedURLException e) {
      throw new RuntimeException(e);
    }
  }

  private Proxy manualProxy() {
    setAuthenticator(preferences.get(Constants.PREF_PROXY_USERNAME), preferences.get(Constants.PREF_PROXY_PASSWORD));
    Proxy.Type type = Proxy.Type.valueOf(preferences.get(Constants.PREF_PROXY_MANUAL_TYPE));
    return new Proxy(type, new InetSocketAddress(preferences.get(Constants.PREF_PROXY_MANUAL_HOSTNAME), Integer.valueOf(preferences.get(Constants.PREF_PROXY_MANUAL_PORT))));
  }

  private void clearPreviousAuthenticator() {
    Authenticator.setDefault(null);
  }

  private void setAuthenticator(String username, String password) {
    if (username == null || username.isEmpty()) {
      return;
    }
    String actualPassword;
    if (password == null) {
      actualPassword = "";
    } else {
      actualPassword = password;
    }
    Authenticator.setDefault(
      new Authenticator() {
        @Override
        public PasswordAuthentication getPasswordAuthentication() {
          return new PasswordAuthentication(username, actualPassword.toCharArray());
        }
      }
    );
  }
}
