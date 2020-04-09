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

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;

import com.github.zafarkhaja.semver.Version;

import cc.arduino.Constants;
import cc.arduino.contributions.VersionHelper;
import cc.arduino.contributions.libraries.ContributedLibraryDependency;
import processing.app.helpers.PreferencesMap;
import processing.app.packages.UserLibraryFolder.Location;

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
  private List<String> architectures;
  private List<String> types = new ArrayList<>();
  private List<String> declaredTypes;
  private boolean onGoingDevelopment;
  private List<String> includes;
  protected File installedFolder;
  protected Location location;

  public static UserLibrary create(UserLibraryFolder libFolderDesc) throws IOException {
    File libFolder = libFolderDesc.folder;
    Location location = libFolderDesc.location;

    // Parse metadata
    File propertiesFile = new File(libFolder, "library.properties");
    PreferencesMap properties = new PreferencesMap();
    properties.load(propertiesFile);

    // Library sanity checks
    // ---------------------

    // Compatibility with 1.5 rev.1 libraries:
    // "email" field changed to "maintainer"
    if (!properties.containsKey("maintainer") && properties.containsKey("email")) {
      properties.put("maintainer", properties.get("email"));
    }

    // Compatibility with 1.5 rev.1 libraries:
    // "arch" folder no longer supported
    File archFolder = new File(libFolder, "arch");
    if (archFolder.isDirectory())
      throw new IOException("'arch' folder is no longer supported! See http://goo.gl/gfFJzU for more information");

    // Check mandatory properties
    for (String p : Constants.LIBRARY_MANDATORY_PROPERTIES)
      if (!properties.containsKey(p))
        throw new IOException("Missing '" + p + "' from library");

    // Check layout
    LibraryLayout layout;
    File srcFolder = new File(libFolder, "src");

    if (srcFolder.exists() && srcFolder.isDirectory()) {
      // Layout with a single "src" folder and recursive compilation
      layout = LibraryLayout.RECURSIVE;
    } else {
      // Layout with source code on library's root and "utility" folders
      layout = LibraryLayout.FLAT;
    }

    // Warn if root folder contains development leftovers
    File[] files = libFolder.listFiles();
    if (files == null) {
      throw new IOException("Unable to list files of library in " + libFolder);
    }

    // Extract metadata info
    String architectures = properties.get("architectures");
    if (architectures == null)
      architectures = "*"; // defaults to "any"
    List<String> archs = new ArrayList<>();
    for (String arch : architectures.split(","))
      archs.add(arch.trim());

    String category = properties.get("category");
    if (category == null) {
      category = "Uncategorized";
    }
    if (!Constants.LIBRARY_CATEGORIES.contains(category)) {
      category = "Uncategorized";
    }

    String license = properties.get("license");
    if (license == null) {
      license = "Unspecified";
    }

    String types = properties.get("types");
    if (types == null) {
      types = "Contributed";
    }
    List<String> typesList = new LinkedList<>();
    for (String type : types.split(",")) {
      typesList.add(type.trim());
    }

    List<String> includes = null;
    if (properties.containsKey("includes") && !properties.get("includes").trim().isEmpty()) {
      includes = new ArrayList<>();
      for (String i : properties.get("includes").split(","))
        includes.add(i.trim());
    }

    String declaredVersion = properties.get("version").trim();
    Optional<Version> version = VersionHelper.valueOf(declaredVersion);
    if (!version.isPresent()) {
      System.out.println(
          format(tr("Invalid version '{0}' for library in: {1}"), declaredVersion, libFolder.getAbsolutePath()));
    }

    UserLibrary res = new UserLibrary();
    res.installedFolder = libFolder;
    res.name = properties.get("name").trim();
    res.version = version.isPresent() ? version.get().toString() : declaredVersion;
    res.author = properties.get("author").trim();
    res.maintainer = properties.get("maintainer").trim();
    res.sentence = properties.get("sentence").trim();
    res.paragraph = properties.get("paragraph").trim();
    res.website = properties.get("url").trim();
    res.category = category.trim();
    res.license = license.trim();
    res.architectures = archs;
    res.layout = layout;
    res.declaredTypes = typesList;
    res.onGoingDevelopment = Files.exists(Paths.get(libFolder.getAbsolutePath(), Constants.LIBRARY_DEVELOPMENT_FLAG_FILE));
    res.includes = includes;
    res.location = location;
    return res;
  }

  public String getName() {
    return name;
  }

  public List<String> getArchitectures() {
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

  public List<String> getTypes() {
    return types;
  }

  public void setTypes(List<String> types) {
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

  public List<String> getDeclaredTypes() {
    return declaredTypes;
  }

  public boolean onGoingDevelopment() {
    return onGoingDevelopment;
  }

  public List<String> getIncludes() {
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

  public Location getLocation() {
    return location;
  }

  public boolean isIDEBuiltIn() {
    return getLocation() == Location.IDE_BUILTIN;
  }

  @Override
  public String toString() {
    return name + ":" + version + " " + architectures + " " + location;
  }

  public File getInstalledFolder() {
    return installedFolder;
  }

}
