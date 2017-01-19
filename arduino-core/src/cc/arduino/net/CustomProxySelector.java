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

import cc.arduino.Constants;
import org.apache.commons.compress.utils.IOUtils;

import javax.script.*;
import java.io.IOException;
import java.net.*;
import java.nio.charset.Charset;
import java.util.Map;
import java.util.stream.Stream;

public class CustomProxySelector {

  private final Map<String, String> preferences;

  public CustomProxySelector(Map<String, String> preferences) {
    this.preferences = preferences;
    clearPreviousAuthenticator();
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

      return pacProxy(pac, uri);
    }

    if (Constants.PROXY_TYPE_MANUAL.equals(proxyType)) {
      return manualProxy();
    }

    throw new IllegalStateException("Unable to understand proxy settings");
  }

  private Proxy pacProxy(String pac, URI uri) throws IOException, ScriptException, NoSuchMethodException {
    setAuthenticator(preferences.get(Constants.PREF_PROXY_AUTO_USERNAME), preferences.get(Constants.PREF_PROXY_AUTO_PASSWORD));

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
    String proxyConfigs = callFindProxyForURL(uri, nashorn);
    return makeProxyFrom(proxyConfigs);
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
    setAuthenticator(preferences.get(Constants.PREF_PROXY_MANUAL_USERNAME), preferences.get(Constants.PREF_PROXY_MANUAL_PASSWORD));
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
