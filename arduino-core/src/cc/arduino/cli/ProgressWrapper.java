/*
 * This file is part of Arduino.
 *
 * Copyright 2019 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.cli;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import cc.arduino.cli.commands.Common.DownloadProgress;
import cc.arduino.contributions.ProgressListener;
import cc.arduino.utils.MultiStepProgress;
import cc.arduino.utils.Progress;

class ProgressWrapper {
  final ProgressListener progressListener;
  String file = "";
  String url = "";
  private long downloaded, totalSize;
  Progress progress = new MultiStepProgress(1);

  public ProgressWrapper(ProgressListener progressListener) {
    this.progressListener = progressListener;
  }

  public void update(DownloadProgress d) {
    if (d == null) {
      return;
    }
    if (!d.getFile().isEmpty()) {
      file = d.getFile();
    }
    if (!d.getUrl().isEmpty()) {
      url = d.getUrl();
    }
    if (d.getTotalSize() > 0) {
      totalSize = d.getTotalSize();
    }
    if (d.getDownloaded() > 0) {
      downloaded = d.getDownloaded();
    }

    String msg = format(tr("Downloaded {0}kb of {1}kb."), downloaded, totalSize);
    if (d.getCompleted()) {
      file = "";
      url = "";
      totalSize = 0;
      downloaded = 0;
    } else {
      progress.setStatus("Downloading " + file + url + " (" + downloaded
                         + " of " + totalSize + ")");
      progress.setProgress(((float) downloaded / totalSize) * 100);
    }
    progressListener.onProgress(progress);
  }
}