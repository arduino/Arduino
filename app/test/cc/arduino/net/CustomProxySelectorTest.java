package cc.arduino.net;

import cc.arduino.Constants;
import org.junit.Before;
import org.junit.Test;

import java.net.*;
import java.util.HashMap;
import java.util.Map;

import static org.junit.Assert.assertEquals;

public class CustomProxySelectorTest {

  private Map<String, String> preferences;
  private URI uri;

  @Before
  public void setUp() throws Exception {
    System.setProperty("java.net.useSystemProxies", "true");
    uri = new URL("https://www.arduino.cc").toURI();
    preferences = new HashMap<>();
  }

  @Test
  public void testNoProxy() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_NONE);
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(Proxy.NO_PROXY, proxy);
  }

  @Test
  public void testSystemProxy() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(ProxySelector.getDefault().select(uri).get(0), proxy);
  }

  @Test
  public void testProxyPACHTTP() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    preferences.put(Constants.PREF_PROXY_PAC_URL, CustomProxySelectorTest.class.getResource("proxy_http.pac").toExternalForm());
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(new Proxy(Proxy.Type.HTTP, new InetSocketAddress("proxy.example.com", 8080)), proxy);
  }

  @Test
  public void testProxyPACHTTPWithLogin() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    preferences.put(Constants.PREF_PROXY_PAC_URL, CustomProxySelectorTest.class.getResource("proxy_http.pac").toExternalForm());
    preferences.put(Constants.PREF_PROXY_AUTO_USERNAME, "auto");
    preferences.put(Constants.PREF_PROXY_AUTO_PASSWORD, "autopassword");
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(new Proxy(Proxy.Type.HTTP, new InetSocketAddress("proxy.example.com", 8080)), proxy);

    PasswordAuthentication authentication = Authenticator.requestPasswordAuthentication(null, 8080, uri.toURL().getProtocol(), "ciao", "");
    assertEquals(authentication.getUserName(), "auto");
    assertEquals(String.valueOf(authentication.getPassword()), "autopassword");
  }

  @Test
  public void testProxyPACSOCKS() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    preferences.put(Constants.PREF_PROXY_PAC_URL, CustomProxySelectorTest.class.getResource("proxy_socks.pac").toExternalForm());
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(new Proxy(Proxy.Type.SOCKS, new InetSocketAddress("proxy.example.com", 8080)), proxy);
  }

  @Test
  public void testProxyPACDirect() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    preferences.put(Constants.PREF_PROXY_PAC_URL, CustomProxySelectorTest.class.getResource("proxy_direct.pac").toExternalForm());
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(Proxy.NO_PROXY, proxy);
  }

  @Test
  public void testProxyPACComplex() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    preferences.put(Constants.PREF_PROXY_PAC_URL, CustomProxySelectorTest.class.getResource("proxy_complex.pac").toExternalForm());
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(new Proxy(Proxy.Type.HTTP, new InetSocketAddress("4.5.6.7", 8080)), proxy);
  }

  @Test
  public void testProxyPACComplex2() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);
    preferences.put(Constants.PREF_PROXY_PAC_URL, CustomProxySelectorTest.class.getResource("proxy_complex.pac").toExternalForm());
    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(new URL("http://www.intranet.domain.com/ciao").toURI());

    assertEquals(Proxy.NO_PROXY, proxy);
  }

  @Test
  public void testManualProxy() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_MANUAL);
    preferences.put(Constants.PREF_PROXY_MANUAL_TYPE, Constants.PROXY_MANUAL_TYPE_HTTP);
    preferences.put(Constants.PREF_PROXY_MANUAL_HOSTNAME, "localhost");
    preferences.put(Constants.PREF_PROXY_MANUAL_PORT, "8080");

    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(new Proxy(Proxy.Type.HTTP, new InetSocketAddress("localhost", 8080)), proxy);
  }

  @Test
  public void testManualProxyWithLogin() throws Exception {
    preferences.put(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_MANUAL);
    preferences.put(Constants.PREF_PROXY_MANUAL_TYPE, Constants.PROXY_MANUAL_TYPE_HTTP);
    preferences.put(Constants.PREF_PROXY_MANUAL_HOSTNAME, "localhost");
    preferences.put(Constants.PREF_PROXY_MANUAL_PORT, "8080");
    preferences.put(Constants.PREF_PROXY_MANUAL_USERNAME, "username");
    preferences.put(Constants.PREF_PROXY_MANUAL_PASSWORD, "pwd");

    CustomProxySelector proxySelector = new CustomProxySelector(preferences);
    Proxy proxy = proxySelector.getProxyFor(uri);

    assertEquals(new Proxy(Proxy.Type.HTTP, new InetSocketAddress("localhost", 8080)), proxy);

    PasswordAuthentication authentication = Authenticator.requestPasswordAuthentication(null, 8080, uri.toURL().getProtocol(), "ciao", "");
    assertEquals(authentication.getUserName(), "username");
    assertEquals(String.valueOf(authentication.getPassword()), "pwd");
  }
}
