package cc.arduino.net;

import cc.arduino.Constants;
import org.apache.commons.compress.utils.IOUtils;

import javax.script.Invocable;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.io.IOException;
import java.net.*;
import java.nio.charset.Charset;
import java.util.Map;

public class CustomProxySelector {

  private final Map<String, String> preferences;

  public CustomProxySelector(Map<String, String> preferences) {
    this.preferences = preferences;
    clearPreviousAuthenticator();
  }

  public Proxy getProxyFor(URI uri) throws IOException, ScriptException, NoSuchMethodException {
    if (Constants.PROXY_TYPE_NONE.equals(preferences.get(Constants.PREF_PROXY_TYPE))) {
      return Proxy.NO_PROXY;
    }

    if (Constants.PROXY_TYPE_AUTO.equals(preferences.get(Constants.PREF_PROXY_TYPE))) {
      String pac = preferences.get(Constants.PREF_PROXY_PAC_URL);
      if (pac == null || pac.isEmpty()) {
        return ProxySelector.getDefault().select(uri).get(0);
      }

      return pacProxy(pac, uri);
    }

    if (preferences.get(Constants.PREF_PROXY_TYPE).equals(Constants.PROXY_TYPE_MANUAL)) {
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
    nashorn.eval(pacScript);
    String proxyConfigs = callFindProxyForURL(uri, nashorn);
    return makeProxyFrom(proxyConfigs);
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

  private String callFindProxyForURL(URI uri, ScriptEngine nashorn) throws ScriptException, NoSuchMethodException {
    Invocable script = (Invocable) nashorn;
    return (String) script.invokeFunction("FindProxyForURL", toUrl(uri).toExternalForm());
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
        public PasswordAuthentication getPasswordAuthentication() {
          return new PasswordAuthentication(username, actualPassword.toCharArray());
        }
      }
    );
  }
}
