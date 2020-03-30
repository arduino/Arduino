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

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import org.apache.commons.compress.utils.IOUtils;
import org.bouncycastle.bcpg.ArmoredInputStream;
import org.bouncycastle.openpgp.PGPException;
import org.bouncycastle.openpgp.PGPObjectFactory;
import org.bouncycastle.openpgp.PGPPublicKey;
import org.bouncycastle.openpgp.PGPPublicKeyRingCollection;
import org.bouncycastle.openpgp.PGPSignature;
import org.bouncycastle.openpgp.PGPSignatureList;
import org.bouncycastle.openpgp.PGPUtil;
import org.bouncycastle.openpgp.jcajce.JcaPGPObjectFactory;
import org.bouncycastle.openpgp.operator.bc.BcKeyFingerprintCalculator;
import org.bouncycastle.openpgp.operator.bc.BcPGPContentVerifierBuilderProvider;

import processing.app.BaseNoGui;

public class SignatureVerifier {

  private File keyRingFile;

  public SignatureVerifier() {
    keyRingFile = new File(BaseNoGui.getContentFile("lib"), "public.gpg.key");
  }

  public void setKeyRingFile(File keyRingFile) {
    this.keyRingFile = keyRingFile;
  }

  public boolean isSigned(File indexFile) {
    File signature = new File(indexFile.getParent(), indexFile.getName() + ".sig");
    if (!signature.exists()) {
      return false;
    }

    try {
      return verify(indexFile, signature);
    } catch (Exception e) {
      BaseNoGui.showWarning(e.getMessage(), e.getMessage(), e);
      return false;
    }
  }

  public boolean isSigned(File indexFile, File signature) {
    try {
      return verify(indexFile, signature);
    } catch (Exception e) {
      BaseNoGui.showWarning(e.getMessage(), e.getMessage(), e);
      return false;
    }
  }

  protected boolean verify(File signedFile, File signatureFile) throws IOException {
    try {
      // Read signature from signatureFile
      PGPSignature signature;
      try (FileInputStream in = new FileInputStream(signatureFile)) {
        PGPObjectFactory objFactory = new PGPObjectFactory(in, new BcKeyFingerprintCalculator());
        Object obj = objFactory.nextObject();
        if (!(obj instanceof PGPSignatureList)) {
          return false;
        }
        PGPSignatureList signatureList = (PGPSignatureList) obj;
        if (signatureList.size() != 1) {
          return false;
        }
        signature = signatureList.get(0);
      } catch (Exception e) {
        return false;
      }

      // Extract public key from keyring
      PGPPublicKey pgpPublicKey = readPublicKey(signature.getKeyID());

      // Check signature
      signature.init(new BcPGPContentVerifierBuilderProvider(), pgpPublicKey);
      try (FileInputStream in = new FileInputStream(signedFile)) {
        signature.update(IOUtils.toByteArray(in));
        return signature.verify();
      }
    } catch (PGPException e) {
      throw new IOException(e);
    }
  }

  private PGPPublicKey readPublicKey(long id) throws IOException, PGPException {
    try (InputStream in = PGPUtil.getDecoderStream(new FileInputStream(keyRingFile))) {
      PGPPublicKeyRingCollection pubRing = new PGPPublicKeyRingCollection(in, new BcKeyFingerprintCalculator());

      PGPPublicKey publicKey = pubRing.getPublicKey(id);
      if (publicKey == null) {
        throw new IllegalArgumentException("Can't find public key in key ring.");
      }
      return publicKey;
    }
  }

  public String[] extractTextFromCleartextSignature(File inFile) throws FileNotFoundException, IOException {
    try (ArmoredInputStream in = new ArmoredInputStream(new FileInputStream(inFile))) {
      return extractTextFromCleartextSignature(in);
    }
  }

  public boolean verifyCleartextSignature(File inFile) {
    try (ArmoredInputStream in = new ArmoredInputStream(new FileInputStream(inFile))) {
      String[] clearTextLines = extractTextFromCleartextSignature(in);
      int clearTextSize = clearTextLines.length;

      JcaPGPObjectFactory pgpFact = new JcaPGPObjectFactory(in);
      PGPSignatureList p3 = (PGPSignatureList) pgpFact.nextObject();
      PGPSignature sig = p3.get(0);
      PGPPublicKey publicKey = readPublicKey(sig.getKeyID());

      sig.init(new BcPGPContentVerifierBuilderProvider(), publicKey);
      for (int i = 0; i < clearTextSize; i++) {
        sig.update(clearTextLines[i].getBytes());
        if (i + 1 < clearTextSize) {
          // https://tools.ietf.org/html/rfc4880#section-7
          // Convert all line endings to '\r\n'
          sig.update((byte) '\r');
          sig.update((byte) '\n');
        }
      }
      return sig.verify();
    } catch (Exception e) {
      e.printStackTrace();
      return false;
    }
  }

  private String[] extractTextFromCleartextSignature(ArmoredInputStream in) throws FileNotFoundException, IOException {
    // https://tools.ietf.org/html/rfc4880#section-7
    // ArmoredInputStream does unescape dash-escaped string in armored text and skips
    // all headers. To calculate the signature we still need to:
    // 1. handle different line endings \n or \n\r or \r\n
    // 2. remove trailing whitespaces from each line (' ' and '\t')
    // 3. remove the latest line ending

    String clearText = "";
    for (;;) {
      int c = in.read();
      // in.isClearText() refers to the PREVIOUS byte read
      if (c == -1 || !in.isClearText()) {
        break;
      }
      // 1. convert all line endings to '\r\n'
      if (c == '\r') {
        continue;
      }
      clearText += (char) c;
    }

    // 3. remove the latest line ending
    if (clearText.endsWith("\n")) {
      clearText = clearText.substring(0, clearText.length() - 1);
    }
    String[] lines = clearText.split("\n", -1);
    for (int i = 0; i < lines.length; i++) {
      // 2. remove trailing whitespaces from each line (' ' and '\t')
      lines[i] = lines[i].replaceAll("[ \\t]+$", "");
    }
    return lines;
  }
}
