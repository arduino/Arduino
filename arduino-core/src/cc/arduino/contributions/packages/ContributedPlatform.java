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

import java.io.File;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import com.fasterxml.jackson.annotation.JsonIgnore;

import cc.arduino.contributions.DownloadableContribution;

public class ContributedPlatform extends DownloadableContribution {

  private String url;
  private String version;
  private long size;
  private String archiveFileName;
  private String name;
  private String category;
  private String architecture;
  private String checksum;
  private ArrayList<ContributedToolReference> toolsDependencies = new ArrayList<>();
  private ArrayList<ContributedBoard> boards = new ArrayList<>();
  private ContributedHelp help;
  private boolean installed;
  private File installedFolder;
  private boolean builtIn;
  private Map<ContributedToolReference, ContributedTool> resolvedToolReferences;
  private ContributedPackage parentPackage;
  private boolean deprecated;

  @Override
  public String getUrl() { return url; }

  @Override
  public String getVersion() { return version; }

  @Override
  public long getSize() { return size; }

  @Override
  public String getArchiveFileName() { return archiveFileName; }

  public String getName() { return name; }

  public String getCategory() { return category; }

  public void setCategory(String category) { this.category = category; }

  public String getArchitecture() { return architecture; }

  @Override
  public String getChecksum() { return checksum; }

  public List<ContributedToolReference> getToolsDependencies() { return toolsDependencies; }

  public List<ContributedBoard> getBoards() { return boards; }

  public ContributedHelp getHelp() { return help; }

  public boolean isInstalled() {
    return installed;
  }

  public void setInstalled(boolean installed) {
    this.installed = installed;
  }

  public File getInstalledFolder() {
    return installedFolder;
  }

  public void setInstalledFolder(File installedFolder) {
    this.installedFolder = installedFolder;
  }

  public boolean isBuiltIn() {
    return builtIn;
  }

  public void setBuiltIn(boolean builtIn) {
    this.builtIn = builtIn;
  }

  public static final Comparator<ContributedPlatform> BUILTIN_AS_LAST = (x, y) -> {
    int px = x.isBuiltIn() ? 1 : -1;
    int py = y.isBuiltIn() ? 1 : -1;
    return px - py;
  };

  public List<ContributedTool> getResolvedTools() {
    return new LinkedList<>(resolvedToolReferences.values());
  }

  @JsonIgnore
  public Map<ContributedToolReference, ContributedTool> getResolvedToolReferences() {
    return resolvedToolReferences;
  }

  public void resolveToolsDependencies(Collection<ContributedPackage> packages) {
    resolvedToolReferences = new HashMap<>();

    // If there are no dependencies return empty list
    if (getToolsDependencies() == null) {
      return;
    }

    // For each tool dependency
    for (ContributedToolReference dep : getToolsDependencies()) {
      // Search the referenced tool
      ContributedTool tool = dep.resolve(packages);
      if (tool == null) {
        System.err.println("Index error: could not find referenced tool " + dep);
      } else {
        resolvedToolReferences.put(dep, tool);
      }
    }
  }

  public ContributedPackage getParentPackage() {
    return parentPackage;
  }

  public void setParentPackage(ContributedPackage parentPackage) {
    this.parentPackage = parentPackage;
  }

  public boolean isDeprecated() {
    return deprecated;
  }

  public void setDeprecated(boolean deprecated) {
    this.deprecated = deprecated;
  }

  @Override
  public String toString() {
    return getParsedVersion();
  }

  @Override
  public boolean equals(Object obj) {
    if (obj == null) {
      return false;
    }
    if (!(obj instanceof ContributedPlatform)) {
      return false;
    }

    ContributedPlatform obj1 = (ContributedPlatform) obj;

    ContributedPackage parent = getParentPackage();
    ContributedPackage parent1 = obj1.getParentPackage();
    if (parent == null) {
      if (parent1 != null)
        return false;
    } else {
      if (parent1 == null)
        return false;
      if (!parent.getName().equals(parent1.getName()))
        return false;
    }
    if (!getArchitecture().equals(obj1.getArchitecture())) {
      return false;
    }
    if (!getVersion().equals(obj1.getVersion())) {
      return false;
    }
    return getName().equals(obj1.getName());
  }
}
