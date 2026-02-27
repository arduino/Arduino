/*
 * This file is part of Arduino.
 *
 * Copyright 2017 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.contributions.libraries;

import java.util.ArrayList;
import java.util.List;

public class UnavailableContributedLibrary extends ContributedLibrary {

  private String name;
  private String version;

  public UnavailableContributedLibrary(ContributedLibraryDependency dependency) {
    this(dependency.getName(), dependency.getVersion());
  }

  public UnavailableContributedLibrary(String _name, String _version) {
    name = _name;
    version = _version;
  }

  @Override
  public String getName() {
    return name;
  }

  @Override
  public String getMaintainer() {
    return "Unknown";
  }

  @Override
  public String getAuthor() {
    return "Unknown";
  }

  @Override
  public String getWebsite() {
    return "Unknown";
  }

  @Override
  public String getCategory() {
    return "Uncategorized";
  }

  @Override
  public void setCategory(String category) {
    // Empty
  }

  @Override
  public String getLicense() {
    return "Unknown";
  }

  @Override
  public String getParagraph() {
    return "";
  }

  @Override
  public String getSentence() {
    return "";
  }

  @Override
  public List<String> getArchitectures() {
    return new ArrayList<>();
  }

  @Override
  public List<String> getTypes() {
    return new ArrayList<>();
  }

  @Override
  public List<ContributedLibraryDependency> getDependencies() {
    return new ArrayList<>();
  }

  @Override
  public String getUrl() {
    return "";
  }

  @Override
  public String getVersion() {
    return version;
  }

  @Override
  public String getChecksum() {
    return "";
  }

  @Override
  public long getSize() {
    return 0;
  }

  @Override
  public String getArchiveFileName() {
    return "";
  }

  @Override
  public String toString() {
    return "!" + super.toString();
  }

  @Override
  public List<String> getProvidesIncludes() {
    return new ArrayList<>();
  }
}
