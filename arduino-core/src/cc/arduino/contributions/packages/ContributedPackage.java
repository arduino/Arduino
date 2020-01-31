/*
 * This file is part of Arduino.
 *
 * Copyright 2014 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.contributions.packages;

import java.util.ArrayList;
import java.util.List;

public class ContributedPackage {

  private String name;
  private String maintainer;
  private String websiteURL;
  private String email;
  private ArrayList<ContributedPlatform> platforms = new ArrayList<ContributedPlatform>();
  private ArrayList<ContributedTool> tools = new ArrayList<ContributedTool>();
  private ContributedHelp help;
  private boolean trusted;

  public String getName() { return name; }

  public String getMaintainer() { return maintainer; }

  public String getWebsiteURL() { return websiteURL; }

  public String getEmail() { return email; }

  public List<ContributedPlatform> getPlatforms() { return platforms; }

  public List<ContributedTool> getTools() { return tools; }

  public ContributedHelp getHelp() { return help; }

  public ContributedPlatform findPlatform(String architecture, String version) {
    if (architecture == null || version == null) {
      return null;
    }
    for (ContributedPlatform platform : getPlatforms()) {
      if (platform.getArchitecture().equals(architecture) && version.equals(platform.getParsedVersion()))
        return platform;
    }
    return null;
  }

  public ContributedTool findTool(String name, String version) {
    if (getTools() == null) {
      return null;
    }
    for (ContributedTool tool : getTools()) {
      if (tool.getName().equals(name) && tool.getVersion().equals(version))
        return tool;
    }
    return null;
  }

  public ContributedTool findResolvedTool(String toolName, String version) {
    for (ContributedPlatform platform : getPlatforms()) {
      for (ContributedTool tool : platform.getResolvedTools()) {
        if (toolName.equals(tool.getName()) && version.equals(tool.getVersion())) {
          return tool;
        }
      }
    }
    return null;
  }

  public boolean isTrusted() {
    return trusted;
  }

  public void setTrusted(boolean trusted) {
    this.trusted = trusted;
  }

  @Override
  public String toString() {
    String res;
    res = "Package name      : " + getName() + "\n";
    res += "        maintaner : " + getMaintainer() + " (" + getEmail() + ")\n";
    if (getPlatforms() != null) {
      for (ContributedPlatform plat : getPlatforms()) {
        res += "\n        Plaform   : name         : " + plat.getName();
        if (plat.isInstalled()) {
          res += "\n                    " + plat;
        }
        res += "\n                    category     : " + plat.getCategory();
        res += "\n                    architecture : " +
          plat.getArchitecture() + " " + plat.getParsedVersion() + "\n";
        if (plat.getToolsDependencies() != null)
          for (ContributedToolReference t : plat.getToolsDependencies()) {
            res += "                    tool dep     : " + t.getName() + " " +
              t.getVersion() + "\n";
          }
        if (plat.getBoards() != null)
          for (ContributedBoard board : plat.getBoards())
            res += "                    board        : " + board.getName() +
              "\n";
      }
    }
    if (getTools() != null) {
      for (ContributedTool tool : getTools())
        res += tool + "\n";
    }
    return res;
  }
}
