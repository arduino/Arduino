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
        public PasswordAuthentication getPasswordAuthentication() {
          return new PasswordAuthentication(username, actualPassword.toCharArray());
        }
      }
    );
  }
}
