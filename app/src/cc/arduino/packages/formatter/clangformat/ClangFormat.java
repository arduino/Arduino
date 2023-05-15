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
 * Copyright 2021 Arduino LLC (http://www.arduino.cc/)
 */

package cc.arduino.packages.formatter.clangformat;

import static processing.app.I18n.tr;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import org.apache.commons.compress.utils.IOUtils;

import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;

import processing.app.Base;
import processing.app.BaseNoGui;
import processing.app.Editor;
import processing.app.syntax.SketchTextArea;

public class ClangFormat implements Runnable {

  private final String clangExecutable = Base.getContentFile("clang-format")
      .getAbsolutePath();
  private Editor editor;

  public ClangFormat(Editor editor) {
    this.editor = editor;
  }

  @Override
  public void run() {
    SketchTextArea tab = editor.getCurrentTab().getTextArea();
    String originalText = tab.getText();
    int cursorOffset = tab.getCaretPosition();
    try {
      FormatResult result = runClangFormatOn(originalText, cursorOffset);
      if (result.FormattedText.equals(originalText)) {
        editor.statusNotice(tr("No changes necessary for Auto Format."));
        return;
      }

      // To keep cursor position after UNDO we produce a bogus edit (insertion
      // and removal of a " " at cursor position) and we compound this change
      // with the full auto-format update.
      tab.beginAtomicEdit();
      tab.insert(" ", cursorOffset);
      tab.replaceRange("", cursorOffset, cursorOffset + 1);
      tab.setText(result.FormattedText);
      tab.endAtomicEdit();

      tab.setCaretPosition(result.Cursor);

      editor.statusNotice(tr("Auto Format finished."));
    } catch (IOException | InterruptedException e) {
      editor.statusError("Auto format error: " + e.getMessage());
      e.printStackTrace();
    } catch (ClangException e) {
      editor.statusError("Auto format error: " + e.getMessage());
    }
  }

  private Thread copyAndClose(InputStream input, OutputStream output) {
    Thread t = new Thread(() -> {
      try {
        IOUtils.copy(input, output);
      } catch (IOException e) {
        e.printStackTrace();
      }
      try {
        input.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
      try {
        output.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    });
    t.start();
    return t;
  }

  private File findConfigFile() {
    // check if sketch has a config file
    File sketchDir = editor.getSketch().getFolder();
    if (new File(sketchDir, ".clang-format").isFile()) {
      return sketchDir;
    }

    // check if a global config file exists
    if (BaseNoGui.getSettingsFile(".clang-format").isFile()) {
      return BaseNoGui.getSettingsFolder();
    }

    // otherwise: no custom configs, return Arduino IDE app dir.
    return new File(clangExecutable).getParentFile();
  }

  FormatResult runClangFormatOn(String source, int cursorOffset)
      throws IOException, InterruptedException, ClangException {
    String cmd[] = new String[] { clangExecutable, "--cursor=" + cursorOffset };

    Process process = Runtime.getRuntime().exec(cmd, null, findConfigFile());
    ByteArrayOutputStream clangOutput = new ByteArrayOutputStream();
    ByteArrayOutputStream clangError = new ByteArrayOutputStream();
    ByteArrayInputStream dataOut = new ByteArrayInputStream(source.getBytes());

    Thread in = copyAndClose(dataOut, process.getOutputStream());
    Thread err = copyAndClose(process.getErrorStream(), clangError);
    Thread out = copyAndClose(process.getInputStream(), clangOutput);

    int r = process.waitFor();
    in.join();
    out.join();
    err.join();

    if (r != 0) {
      throw new ClangException(clangError.toString());
    }

    // clang-format will output first a JSON object with:
    // - the resulting cursor position and
    // - a flag teling if the conversion was successful
    // for example:
    //
    // { "Cursor": 34, "IncompleteFormat": false }
    ObjectMapper mapper = new ObjectMapper();
    mapper.configure(DeserializationFeature.ACCEPT_SINGLE_VALUE_AS_ARRAY, true);
    mapper.configure(DeserializationFeature.EAGER_DESERIALIZER_FETCH, true);
    mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
    FormatResult res = mapper.readValue(clangOutput.toByteArray(),
                                        FormatResult.class);

    // After the JSON object above clang-format will output the formatted source
    // code in plain text
    String formattedText = clangOutput.toString();
    formattedText = formattedText.substring(formattedText.indexOf('}') + 1);
    // handle different line endings
    res.FormattedText = formattedText.replaceFirst("\\R", "");
    return res;
  }
}

class ClangException extends Exception {
  public ClangException(String string) {
    super(string);
  }
}

class FormatResult {
  public String FormattedText;
  public int Cursor;
  public boolean IncompleteFormat;
}