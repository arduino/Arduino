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
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import org.apache.commons.compress.utils.IOUtils;
import org.apache.logging.log4j.core.util.NullOutputStream;

import processing.app.Editor;
import processing.app.helpers.ProcessUtils;
import processing.app.tools.Tool;

public class ClangFormat implements Tool {

  private Editor editor;

  public ClangFormat() {
  }

  @Override
  public void init(Editor editor) {
    this.editor = editor;
  }

  @Override
  public void run() {
    String originalText = editor.getCurrentTab().getText();

    try {
      String formattedText = runClangFormatOn(originalText);
      if (formattedText.equals(originalText)) {
        editor.statusNotice(tr("No changes necessary for Auto Format."));
        return;
      }
      editor.getCurrentTab().setText(formattedText);
      editor.statusNotice(tr("Auto Format finished."));
    } catch (IOException | InterruptedException e) {
      editor.statusError("Auto format error: " + e.getMessage());
      e.printStackTrace();
    }
  }

  @Override
  public String getMenuTitle() {
    return tr("Auto Format");
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

  String runClangFormatOn(String source)
      throws IOException, InterruptedException {
    String cmd[] = new String[] { "clang-format" };

    Process process = ProcessUtils.exec(cmd);
    ByteArrayOutputStream result = new ByteArrayOutputStream();
    ByteArrayInputStream dataOut = new ByteArrayInputStream(source.getBytes());
    Thread out = copyAndClose(process.getInputStream(), result);
    Thread err = copyAndClose(process.getErrorStream(),
                              NullOutputStream.getInstance());
    Thread in = copyAndClose(dataOut, process.getOutputStream());
    /* int r = */process.waitFor();
    in.join();
    out.join();
    err.join();
    return result.toString();
  }
}
