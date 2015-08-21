package cc.arduino.net;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class PACSupportMethodsTest {

  private PACSupportMethods pacSupportMethods;

  @Before
  public void setUp() throws Exception {
    pacSupportMethods = new PACSupportMethods();
  }

  @Test
  public void testIsInNet() throws Exception {
    assertFalse(pacSupportMethods.isInNet("192.168.0.121", "198.95.249.79", "255.255.255.255"));
    assertFalse(pacSupportMethods.isInNet("198.95.249.78", "198.95.249.79", "255.255.255.255"));
    assertTrue(pacSupportMethods.isInNet("198.95.249.79", "198.95.249.79", "255.255.255.255"));

    assertFalse(pacSupportMethods.isInNet("192.168.0.121", "198.95.0.0", "255.255.0.0"));
    assertTrue(pacSupportMethods.isInNet("198.95.249.78", "198.95.0.0", "255.255.0.0"));
    assertTrue(pacSupportMethods.isInNet("198.95.249.79", "198.95.0.0", "255.255.0.0"));
  }
}
