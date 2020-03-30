/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.contributions;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.io.File;

import org.junit.Before;
import org.junit.Test;

public class SignatureVerifierTest {

  private SignatureVerifier verifier;

  @Before
  public void setUp() throws Exception {
    verifier = new SignatureVerifier();
    File keyRingFile = new File(SignatureVerifierTest.class.getResource("./test.public.gpg.key").getFile());
    verifier.setKeyRingFile(keyRingFile);
  }

  @Test
  public void testSignatureSuccessfulVerification() throws Exception {
    File signedFile = new File(SignatureVerifierTest.class.getResource("./package_index.json").getFile());
    File sign = new File(SignatureVerifierTest.class.getResource("./package_index.json.sig").getFile());
    assertTrue(verifier.verify(signedFile, sign));
  }

  @Test
  public void testSignatureFailingVerification() throws Exception {
    File fakeSignedFile = File.createTempFile("fakeSigned", "txt");
    fakeSignedFile.deleteOnExit();
    File sign = new File(SignatureVerifierTest.class.getResource("./package_index.json.sig").getFile());
    assertFalse(verifier.verify(fakeSignedFile, sign));
  }

  @Test
  public void testClearTextSignatureVerification() throws Exception {
    File signedFile = new File(SignatureVerifierTest.class.getResource("./text.txt.asc").getFile());
    assertTrue(verifier.verifyCleartextSignature(signedFile));
    File signedFile2 = new File(SignatureVerifierTest.class.getResource("./escaped-text.txt.asc").getFile());
    assertTrue(verifier.verifyCleartextSignature(signedFile2));
    File oneBlankLines = new File(SignatureVerifierTest.class.getResource("./one-blank-line.txt.asc").getFile());
    assertTrue(verifier.verifyCleartextSignature(oneBlankLines));
    File twoBlankLines = new File(SignatureVerifierTest.class.getResource("./two-blank-lines.txt.asc").getFile());
    assertTrue(verifier.verifyCleartextSignature(twoBlankLines));
    File noBlankLines = new File(SignatureVerifierTest.class.getResource("./no-blank-lines.txt.asc").getFile());
    assertTrue(verifier.verifyCleartextSignature(noBlankLines));
  }

  @Test
  public void testClearTextSignatureFailingVerification() throws Exception {
    File signedFile = new File(SignatureVerifierTest.class.getResource("./wrong-text.txt.asc").getFile());
    assertFalse(verifier.verifyCleartextSignature(signedFile));
  }
}
