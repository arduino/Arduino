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

import cc.arduino.contributions.DownloadableContributionBuiltInAtTheBottomComparator;
import cc.arduino.contributions.filters.DownloadableContributionWithVersionPredicate;
import cc.arduino.contributions.filters.InstalledPredicate;
import cc.arduino.contributions.packages.filters.PlatformArchitecturePredicate;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public abstract class ContributionsIndex {

  public abstract List<ContributedPackage> getPackages();

  public ContributedPackage findPackage(String packageName) {
    for (ContributedPackage pack : getPackages()) {
      if (pack.getName().equals(packageName))
        return pack;
    }
    return null;
  }

  public List<ContributedPlatform> findPlatforms(String packageName, final String platformArch) {
    if (packageName == null || platformArch == null) {
      return null;

    }
    ContributedPackage aPackage = findPackage(packageName);
    if (aPackage == null) {
      return null;
    }
    return aPackage.getPlatforms().stream().filter(new PlatformArchitecturePredicate(platformArch)).collect(Collectors.toList());
  }

  public ContributedPlatform findPlatform(String packageName, final String platformArch, final String platformVersion) {
    if (platformVersion == null) {
      return null;

    }

    Collection<ContributedPlatform> platformsByName = findPlatforms(packageName, platformArch);
    if (platformsByName == null) {
      return null;
    }

    Collection<ContributedPlatform> platforms = platformsByName.stream().filter(new DownloadableContributionWithVersionPredicate(platformVersion)).collect(Collectors.toList());
    if (platforms.isEmpty()) {
      return null;
    }

    return platforms.iterator().next();
  }

  public List<ContributedPlatform> getInstalledPlatforms() {
    return getPlatforms().stream().filter(new InstalledPredicate()).collect(Collectors.toList());
  }

  public ContributedPlatform getInstalledPlatform(String packageName, String platformArch) {
    List<ContributedPlatform> platforms = findPlatforms(packageName, platformArch);
    if (platforms == null) {
      return null;
    }
    List<ContributedPlatform> installedPlatforms = platforms.stream().filter(new InstalledPredicate()).collect(Collectors.toList());
    Collections.sort(installedPlatforms, new DownloadableContributionBuiltInAtTheBottomComparator());

    if (installedPlatforms.isEmpty()) {
      return null;
    }

    return installedPlatforms.get(0);
  }

  private List<ContributedPlatform> getPlatforms() {
    return getPackages().stream().map(ContributedPackage::getPlatforms).flatMap(Collection::stream).collect(Collectors.toList());
  }

  private final List<String> categories = new ArrayList<>();

  public List<String> getCategories() {
    return categories;
  }

  public void fillCategories() {
    categories.clear();
    for (ContributedPackage pack : getPackages()) {
      pack.getPlatforms().stream()
        .filter(platform -> !categories.contains(platform.getCategory()))
        .forEach(platform -> categories.add(platform.getCategory()));
    }
  }

  public ContributedPackage getPackage(String packageName) {
    for (ContributedPackage pack : getPackages()) {
      if (pack.getName().equals(packageName)) {
        return pack;
      }
    }
    return null;
  }

  @Override
  public String toString() {
    String res = "";
    res += "Categories: ";
    for (String c : getCategories())
      res += "'" + c + "' ";
    res += "\n";
    for (ContributedPackage pack : getPackages())
      res += pack + "\n";
    return res;
  }
}
