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

import cc.arduino.Constants;
import cc.arduino.contributions.DownloadableContribution;
import cc.arduino.contributions.SignatureVerifier;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.module.mrbean.MrBeanModule;
import org.apache.commons.compress.utils.IOUtils;

import processing.app.BaseNoGui;
import processing.app.Platform;
import processing.app.PreferencesData;
import processing.app.debug.TargetPackage;
import processing.app.debug.TargetPlatform;
import processing.app.debug.TargetPlatformException;
import processing.app.helpers.FileUtils;
import processing.app.helpers.PreferencesMap;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.stream.Collectors;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;
import static processing.app.helpers.filefilters.OnlyDirs.ONLY_DIRS;

public class ContributionsIndexer {

  private final File packagesFolder;
  private final File stagingFolder;
  private final File preferencesFolder;
  private final File builtInHardwareFolder;
  private final Platform platform;
  private final SignatureVerifier signatureVerifier;
  private final ContributionsIndex index;

  public ContributionsIndexer(File preferencesFolder, File builtInHardwareFolder, Platform platform, SignatureVerifier signatureVerifier) {
    this.preferencesFolder = preferencesFolder;
    this.builtInHardwareFolder = builtInHardwareFolder;
    this.platform = platform;
    this.signatureVerifier = signatureVerifier;
    index = new EmptyContributionIndex();
    packagesFolder = new File(preferencesFolder, "packages");
    stagingFolder = new File(preferencesFolder, "staging" + File.separator + "packages");
  }

  public void parseIndex() throws Exception {
    // Read bundled index...
    File bundledIndexFile = new File(builtInHardwareFolder, Constants.BUNDLED_INDEX_FILE_NAME);
    mergeContributions(bundledIndexFile);

    // ...and overlay the default index if present
    File defaultIndexFile = getIndexFile(Constants.DEFAULT_INDEX_FILE_NAME);
    if (defaultIndexFile.exists()) {
      // Check main index signature
      if (signatureVerifier.isSigned(defaultIndexFile)) {
        mergeContributions(defaultIndexFile);
      } else if (PreferencesData.areInsecurePackagesAllowed()) {
        System.err.println(format(tr("Warning: forced trusting untrusted contributions")));
        mergeContributions(defaultIndexFile);
      } else {
        BaseNoGui
            .showWarning(Constants.DEFAULT_INDEX_FILE_NAME,
                              tr("A package index has an invalid signature and needs to be updated.\n"
                                 + "Please open the Board Manager from the menu\n"
                                 + "\n" //
                                 + "      Tools -> Board -> Board Manager\n"
                                 + "\nto update it"),
                              null);
      }
    }

    // Set main and bundled indexes as trusted
    index.getPackages().forEach(pack -> pack.setTrusted(true));

    // Overlay 3rd party indexes
    File[] indexFiles = preferencesFolder.listFiles(new TestPackageIndexFilenameFilter(new PackageIndexFilenameFilter(Constants.DEFAULT_INDEX_FILE_NAME)));

    if (indexFiles != null) {
      for (File indexFile : indexFiles) {
        try {
          mergeContributions(indexFile);
        } catch (JsonProcessingException e) {
          System.err.println(format(tr("Skipping contributed index file {0}, parsing error occured:"), indexFile));
          System.err.println(e);
        }
      }
    } else {
      System.err.println(format(tr("Error reading package indexes folder: {0}\n(maybe a permission problem?)"), preferencesFolder));
    }

    // Fill tools and toolsDependency cross references
    List<ContributedPackage> packages = index.getPackages();
    Collection<ContributedPackage> packagesWithTools = packages.stream()
      .filter(input -> input.getTools() != null && !input.getTools().isEmpty())
      .collect(Collectors.toList());

    for (ContributedPackage pack : packages) {
      // Fill references to package in tools
      for (ContributedTool tool : pack.getTools()) {
        tool.setPackage(pack);
      }

      for (ContributedPlatform plat : pack.getPlatforms()) {
        // Set a reference to parent packages
        plat.setParentPackage(pack);

        // Resolve tools dependencies (works also as a check for file integrity)
        plat.resolveToolsDependencies(packagesWithTools);
      }
    }

    index.fillCategories();
  }

  private void mergeContributions(File indexFile) throws IOException {
    if (!indexFile.exists())
      return;

    ContributionsIndex contributionsIndex = parseIndex(indexFile);
    boolean signed = signatureVerifier.isSigned(indexFile);
    boolean trustall = PreferencesData.areInsecurePackagesAllowed();

    for (ContributedPackage contributedPackage : contributionsIndex.getPackages()) {
      contributedPackage.setTrusted(signed || trustall);
      if (!contributedPackage.isTrusted()) {
        for (ContributedPlatform contributedPlatform : contributedPackage.getPlatforms()) {
          contributedPlatform.setCategory("Contributed");
        }
      }

      ContributedPackage targetPackage = index.getPackage(contributedPackage.getName());

      if (targetPackage == null) {
        index.getPackages().add(contributedPackage);
      } else {
        if (contributedPackage.isTrusted() || !isPackageNameProtected(contributedPackage)) {
          if (isPackageNameProtected(contributedPackage) && trustall) {
            System.err.println(format(tr("Warning: forced trusting untrusted contributions")));
          }
          List<ContributedPlatform> platforms = contributedPackage.getPlatforms();
          if (platforms == null) {
            platforms = new LinkedList<>();
          }
          for (ContributedPlatform contributedPlatform : platforms) {
            ContributedPlatform plat = targetPackage.findPlatform(contributedPlatform.getArchitecture(), contributedPlatform.getVersion());
            if (plat != null) {
              targetPackage.getPlatforms().remove(plat);
            }
            targetPackage.getPlatforms().add(contributedPlatform);
          }
          List<ContributedTool> tools = contributedPackage.getTools();
          if (tools == null) {
            tools = new LinkedList<>();
          }
          for (ContributedTool contributedTool : tools) {
            ContributedTool tool = targetPackage.findTool(contributedTool.getName(), contributedTool.getVersion());
            if (tool != null) {
              targetPackage.getTools().remove(tool);
            }
            targetPackage.getTools().add(contributedTool);
          }
        }
      }
    }
  }

  private boolean isPackageNameProtected(ContributedPackage contributedPackage) {
    return Constants.PROTECTED_PACKAGE_NAMES.contains(contributedPackage.getName());
  }

  private ContributionsIndex parseIndex(File indexFile) throws IOException {
    InputStream inputStream = null;
    try {
      inputStream = new FileInputStream(indexFile);
      ObjectMapper mapper = new ObjectMapper();
      mapper.registerModule(new MrBeanModule());
      mapper.configure(DeserializationFeature.ACCEPT_SINGLE_VALUE_AS_ARRAY, true);
      mapper.configure(DeserializationFeature.EAGER_DESERIALIZER_FETCH, true);
      mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
      return mapper.readValue(inputStream, ContributionsIndex.class);
    } finally {
      IOUtils.closeQuietly(inputStream);
    }
  }

  public void syncWithFilesystem() throws IOException {
    syncBuiltInHardware();

    syncLocalPackages();
  }

  private void syncBuiltInHardware() throws IOException {
    if (index == null || builtInHardwareFolder == null) {
      return;
    }
    for (File folder : builtInHardwareFolder.listFiles(ONLY_DIRS)) {
      ContributedPackage pack = index.findPackage(folder.getName());
      if (pack == null)
        continue;
      syncBuiltInPackageWithFilesystem(pack, folder);

      File toolsFolder = new File(builtInHardwareFolder, "tools");
      if (!toolsFolder.isDirectory())
        continue;

      for (File toolFolder : toolsFolder.listFiles(ONLY_DIRS)) {

        // builtin_tools_versions.txt contains tools versions in the format:
        // "PACKAGER.TOOL_NAME=TOOL_VERSION"
        // for example:
        // "arduino.avrdude=6.0.1-arduino5"

        File versionsFile = new File(toolFolder, "builtin_tools_versions.txt");
        if (!versionsFile.isFile())
          continue;
        PreferencesMap toolsVersion = new PreferencesMap(versionsFile).subTree(pack.getName());
        for (String name : toolsVersion.keySet()) {
          String version = toolsVersion.get(name);
          ContributedTool tool = syncToolWithFilesystem(pack, toolFolder, name, version);
          if (tool != null)
            tool.setBuiltIn(true);
        }
      }
    }
  }

  private void syncBuiltInPackageWithFilesystem(ContributedPackage pack, File hardwareFolder) throws IOException {
    // Scan all hardware folders and mark as installed all the tools found.
    for (File platformFolder : hardwareFolder.listFiles(ONLY_DIRS)) {
      File platformTxt = new File(platformFolder, "platform.txt");
      String version = new PreferencesMap(platformTxt).get("version");
      ContributedPlatform p = syncHardwareWithFilesystem(pack, platformFolder, platformFolder.getName(), version);
      if (p != null) {
        p.setBuiltIn(true);
      }
    }
  }

  private void syncLocalPackages() {
    if (!packagesFolder.isDirectory()) {
      return;
    }

    if (index == null) {
      return;
    }

    // Scan all hardware folders and mark as installed all the
    // platforms found.
    for (File folder : packagesFolder.listFiles(ONLY_DIRS)) {
      ContributedPackage pack = index.findPackage(folder.getName());
      if (pack != null) {
        syncPackageWithFilesystem(pack, folder);
      }
    }
  }

  private void syncPackageWithFilesystem(ContributedPackage pack, File root) {
    // Scan all hardware folders and mark as installed all the tools found.
    File hardwareFolder = new File(root, "hardware");
    if (hardwareFolder.isDirectory()) {
      for (File platformFolder : hardwareFolder.listFiles(ONLY_DIRS)) {
        for (File versionFolder : platformFolder.listFiles(ONLY_DIRS)) {
          syncHardwareWithFilesystem(pack, versionFolder, platformFolder.getName(), versionFolder.getName());
        }
      }
    }

    // Scan all tools folders and mark as installed all the tools found.
    File toolsFolder = new File(root, "tools");
    if (toolsFolder.isDirectory()) {
      for (File toolFolder : toolsFolder.listFiles(ONLY_DIRS)) {
        for (File versionFolder : toolFolder.listFiles(ONLY_DIRS)) {
          syncToolWithFilesystem(pack, versionFolder, toolFolder.getName(), versionFolder.getName());
        }
      }
    }
  }

  private ContributedTool syncToolWithFilesystem(ContributedPackage pack, File installationFolder, String toolName, String version) {
    ContributedTool tool = pack.findTool(toolName, version);
    if (tool == null) {
      tool = pack.findResolvedTool(toolName, version);
    }
    if (tool == null) {
      return null;
    }
    DownloadableContribution contrib = tool.getDownloadableContribution(platform);
    if (contrib == null) {
      System.err.println(tool + " seems to have no downloadable contributions for your operating system, but it is installed in\n" + installationFolder);
      return null;
    }
    tool.setInstalled(true);
    tool.setInstalledFolder(installationFolder);
    tool.setBuiltIn(false);
    return tool;
  }

  private ContributedPlatform syncHardwareWithFilesystem(ContributedPackage pack, File installationFolder, String architecture, String version) {
    ContributedPlatform p = pack.findPlatform(architecture, version);
    if (p != null) {
      p.setInstalled(true);
      p.setBuiltIn(false);
      p.setInstalledFolder(installationFolder);
    }
    return p;
  }

  @Override
  public String toString() {
    return index.toString();
  }

  public List<TargetPackage> createTargetPackages() {
    List<TargetPackage> packages = new ArrayList<>();

    if (index == null) {
      return packages;
    }

    for (ContributedPackage aPackage : index.getPackages()) {
      ContributedTargetPackage targetPackage = new ContributedTargetPackage(aPackage.getName());

      List<ContributedPlatform> platforms = aPackage.getPlatforms().stream() //
          .filter(p -> p.isInstalled()) //
          .collect(Collectors.toList());
      Collections.sort(platforms, ContributedPlatform.BUILTIN_AS_LAST);

      for (ContributedPlatform p : platforms) {
        String arch = p.getArchitecture();
        File folder = p.getInstalledFolder();

        try {
          TargetPlatform targetPlatform = new ContributedTargetPlatform(arch, folder, targetPackage);
          if (!targetPackage.hasPlatform(targetPlatform)) {
            targetPackage.addPlatform(targetPlatform);
          }
        } catch (TargetPlatformException e) {
          System.err.println(e.getMessage());
        }
      }

      if (targetPackage.hasPlatforms()) {
        packages.add(targetPackage);
      }
    }

    Collections.sort(packages, (package1, package2) -> {
      assert package1.getId() != null && package2.getId() != null;
      return package1.getId().toLowerCase().compareTo(package2.getId().toLowerCase());
    });

    return packages;
  }

  public boolean isContributedToolUsed(ContributedPlatform platformToIgnore, ContributedTool tool) {
    for (ContributedPackage pack : index.getPackages()) {
      for (ContributedPlatform p : pack.getPlatforms()) {
        if (platformToIgnore.equals(p)) {
          continue;
        }
        if (!p.isInstalled() || p.isBuiltIn()) {
          continue;
        }
        for (ContributedTool requiredTool : p.getResolvedTools()) {
          if (requiredTool.equals(tool))
            return true;
        }
      }
    }
    return false;
  }

  public Set<ContributedTool> getInstalledTools() {
    Set<ContributedTool> tools = new HashSet<>();
    if (index == null) {
      return tools;
    }
    for (ContributedPackage pack : index.getPackages()) {
      Collection<ContributedPlatform> platforms = pack.getPlatforms().stream() //
          .filter(p -> p.isInstalled()) //
          .collect(Collectors.toList());
      Map<String, List<ContributedPlatform>> platformsByName = platforms.stream().collect(Collectors.groupingBy(ContributedPlatform::getName));

      platformsByName.forEach((platformName, platformsWithName) -> {
        if (platformsWithName.size() > 1) {
          platformsWithName = platformsWithName.stream() //
              .filter(p -> !p.isBuiltIn()) //
              .collect(Collectors.toList());
        }
        for (ContributedPlatform p : platformsWithName) {
          tools.addAll(p.getResolvedTools());
        }
      });
    }
    return tools;
  }

  public ContributionsIndex getIndex() {
    return index;
  }

  public File getPackagesFolder() {
    return packagesFolder;
  }

  public File getStagingFolder() {
    return stagingFolder;
  }

  public File getIndexFile(String name) {
    return new File(preferencesFolder, name);
  }

  public List<ContributedPackage> getPackages() {
    if (index == null) {
      return new LinkedList<>();
    }
    return index.getPackages();
  }

  public List<String> getCategories() {
    if (index == null) {
      return new LinkedList<>();
    }
    return index.getCategories();
  }

  public ContributedPlatform getInstalled(String packageName, String platformArch) {
    if (index == null) {
      return null;
    }
    return index.getInstalledPlatform(packageName, platformArch);
  }

  private List<ContributedPlatform> getInstalledPlatforms() {
    if (index == null) {
      return new LinkedList<>();
    }
    return index.getInstalledPlatforms();
  }

  public Optional<ContributedPlatform> getPlatformByFolder(final File folder) {
    return getInstalledPlatforms().stream().filter(contributedPlatform -> {
      assert contributedPlatform.getInstalledFolder() != null;
      return FileUtils.isSubDirectory(contributedPlatform.getInstalledFolder(), folder);
    }).findFirst();
  }

  public ContributedPlatform getContributedPlaform(TargetPlatform targetPlatform) {
    for (ContributedPlatform plat : getInstalledPlatforms()) {
      if (plat.getInstalledFolder().equals(targetPlatform.getFolder()))
        return plat;
    }
    return null;
  }
}
