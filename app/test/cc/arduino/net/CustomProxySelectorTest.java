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
