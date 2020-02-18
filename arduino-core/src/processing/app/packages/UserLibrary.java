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
package processing.app.packages;

import java.io.File;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import cc.arduino.cli.commands.Lib.LibraryLocation;
import cc.arduino.contributions.libraries.ContributedLibraryDependency;

public class UserLibrary {

  private String name;
  private String version;
  private String author;
  private String maintainer;
  private String sentence;
  private String paragraph;
  private String website;
  private String category;
  private String license;
  private Collection<String> architectures;
  private Collection<String> types = new ArrayList<>();
  private Collection<String> declaredTypes;
  private boolean onGoingDevelopment;
  private Collection<String> includes;
  protected File installedFolder;

  protected LibraryLocation location;

  public UserLibrary(File installedFolder, String name, String version,
                     String author, String maintainer, String sentence,
                     String paraghraph, String website, String category,
                     String license, Collection<String> architectures,
                     String layout, Collection<String> declaredTypes,
                     boolean onGoingDevelopment, Collection<String> includes,
                     LibraryLocation location) {
    this.installedFolder = installedFolder;
    this.name = name;
    this.version = version;
    this.author = author;
    this.maintainer = maintainer;
    this.sentence = sentence;
    this.paragraph = paraghraph;
    this.website = website;
    this.category = category;
    this.license = license;
    this.architectures = architectures;
    switch (layout) {
    case "recursive":
      this.layout = LibraryLayout.RECURSIVE;
      break;
    case "flat":
      this.layout = LibraryLayout.FLAT;
      break;
    default:
      throw new IllegalArgumentException("Invalid library layout: " + layout);
    }
    this.declaredTypes = declaredTypes;
    this.onGoingDevelopment = onGoingDevelopment;
    this.includes = includes;
    this.location = location;
  }

  public String getName() {
    return name;
  }

  public Collection<String> getArchitectures() {
    return architectures;
  }

  public String getAuthor() {
    return author;
  }

  public String getParagraph() {
    return paragraph;
  }

  public String getSentence() {
    return sentence;
  }

  public String getWebsite() {
    return website;
  }

  public String getCategory() {
    return category;
  }

  public Collection<String> getTypes() {
    return types;
  }

  public void setTypes(Collection<String> types) {
    this.types = types;
  }

  public String getLicense() {
    return license;
  }

  public void setCategory(String category) {
    this.category = category;
  }

  public String getVersion() {
    return version;
  }

  public String getMaintainer() {
    return maintainer;
  }

  public List<ContributedLibraryDependency> getRequires() {
    return null;
  }

  public Collection<String> getDeclaredTypes() {
    return declaredTypes;
  }

  public boolean onGoingDevelopment() {
    return onGoingDevelopment;
  }

  public Collection<String> getIncludes() {
    return includes;
  }

  protected enum LibraryLayout {
    FLAT, RECURSIVE
  }

  protected LibraryLayout layout;

  public File getSrcFolder() {
    switch (layout) {
      case FLAT:
        return installedFolder;
      case RECURSIVE:
        return new File(installedFolder, "src");
      default:
        return null; // Keep compiler happy :-(
    }
  }

  public boolean useRecursion() {
    return (layout == LibraryLayout.RECURSIVE);
  }

  public LibraryLocation getLocation() {
    return location;
  }

  public boolean isIDEBuiltIn() {
    return getLocation().equals(LibraryLocation.ide_builtin);
  }

  @Override
  public String toString() {
    return name + ":" + version + " " + architectures + " " + location;
  }

  public File getInstalledFolder() {
    return installedFolder;
  }

}
