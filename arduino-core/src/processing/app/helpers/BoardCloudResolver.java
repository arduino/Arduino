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

package processing.app.helpers;

import cc.arduino.utils.network.HttpConnectionManager;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.debug.TargetBoard;
import processing.app.debug.TargetPackage;
import processing.app.debug.TargetPlatform;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Map;

import static processing.app.I18n.tr;

public class BoardCloudResolver {
  private static Logger log = LogManager.getLogger(BoardCloudResolver.class);

  public synchronized void getBoardBy(String vid, String pid) {
    // this method is less useful in Windows < WIN10 since you need drivers to be already installed
    ObjectMapper mapper = new ObjectMapper();
    mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
    try {
      URL jsonUrl = new URL(String.format("https://builder.arduino.cc/builder/v1/boards/0x%s/0x%s", vid, pid));

      final HttpURLConnection httpConnection = new HttpConnectionManager(jsonUrl)
        .makeConnection();
      int code = httpConnection.getResponseCode();
      if (code == 404) {
        log.warn("Fail to get the Vid Pid information from the builder response code={}", code);
        return;
      }
      InputStream is = httpConnection.getInputStream();
      BoardCloudAPIid board = mapper.readValue(is, BoardCloudAPIid.class);
      log.info("Board info from the cloud {}", board);
      // Launch a popup with a link to boardmanager#board.getName()
      // replace spaces with &
      String realBoardName = board.getName().replaceAll("\\(.*?\\)", "").trim();
      String boardNameReplaced = realBoardName.replaceAll(" ", "&");
      String message = I18n.format(tr("{0}Install this package{1} to use your {2} board"), "<a href=\"http://boardsmanager/all#" + boardNameReplaced + "\">", "</a>", realBoardName);
      BaseNoGui.setBoardManagerLink(message);
    } catch (Exception e) {
      // No connection no problem, fail silently
      //e.printStackTrace();
      log.warn("Error during get board information by vid, pid", e);

    }
  }

  public String resolveDeviceByBoardID(Map<String, TargetPackage> packages, String boardId) {
    assert packages != null;
    assert boardId != null;
    for (TargetPackage targetPackage : packages.values()) {
      for (TargetPlatform targetPlatform : targetPackage.getPlatforms().values()) {
        for (TargetBoard board : targetPlatform.getBoards().values()) {
          if (boardId.equals(board.getId())) {
            return board.getName();
          }
        }
      }
    }
    return null;
  }

  private static class BoardCloudAPIid {

    private String fqbn;
    private String name;
    private String architecture;
    private String id;

    public String getName() {
      return name;
    }

    public void setName(String tmp) {
      name = tmp;
    }

    public String getFqbn() {
      return fqbn;
    }

    public void setFqbn(String fqbn) {
      this.fqbn = fqbn;
    }

    public String getArchitecture() {
      return architecture;
    }

    public void setArchitecture(String tmp) {
      architecture = tmp;
    }

    public String getId() {
      return id;
    }

    public void setId(String tmp) {
      id = tmp;
    }

    @Override
    public String toString() {
      return "BoardCloudAPIid{" +
        "name='" + name + '\'' +
        ", fqbn='" + fqbn + '\'' +
        ", architecture='" + architecture + '\'' +
        ", id='" + id + '\'' +
        '}';
    }
  }

}
