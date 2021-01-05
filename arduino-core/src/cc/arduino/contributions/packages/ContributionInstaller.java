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
import cc.arduino.contributions.DownloadableContributionsDownloader;
import cc.arduino.contributions.ProgressListener;
import cc.arduino.contributions.SignatureVerifier;
import cc.arduino.filters.FileExecutablePredicate;
import cc.arduino.utils.ArchiveExtractor;
import cc.arduino.utils.MultiStepProgress;
import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.DefaultExecutor;
import org.apache.commons.exec.Executor;
import org.apache.commons.exec.PumpStreamHandler;
import org.apache.commons.io.FilenameUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.Platform;
import processing.app.PreferencesData;
import processing.app.helpers.FileUtils;
import processing.app.helpers.filefilters.OnlyDirs;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;

import static processing.app.I18n.format;
import static processing.app.I18n.tr;

public class ContributionInstaller {
  private static Logger log = LogManager.getLogger(ContributionInstaller.class);

  private final Platform platform;
  private final SignatureVerifier signatureVerifier;

  public ContributionInstaller(Platform platform, SignatureVerifier signatureVerifier) {
    this.platform = platform;
    this.signatureVerifier = signatureVerifier;
  }

  public synchronized List<String> install(ContributedPlatform contributedPlatform, ProgressListener progressListener) throws Exception {
    List<String> errors = new LinkedList<>();
    if (contributedPlatform.isInstalled()) {
      throw new Exception("Platform is already installed!");
    }

    // Do not download already installed tools
    List<ContributedTool> tools = new ArrayList<>();
    for (ContributedTool tool : contributedPlatform.getResolvedTools()) {
      DownloadableContribution downloadable = tool.getDownloadableContribution(platform);
      if (downloadable == null) {
        throw new Exception(format(tr("Tool {0} is not available for your operating system."), tool.getName()));
      }
      // Download the tool if it's not installed or it's a built-in tool
      if (!tool.isInstalled() || tool.isBuiltIn()) {
        tools.add(tool);
      }
    }

    DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.indexer.getStagingFolder());

    // Calculate progress increases
    MultiStepProgress progress = new MultiStepProgress((tools.size() + 1) * 2);

    // Download all
    try {
      // Download platform
      downloader.download(contributedPlatform, progress, tr("Downloading boards definitions."), progressListener, false);
      progress.stepDone();

      // Download tools
      int i = 1;
      for (ContributedTool tool : tools) {
        String msg = format(tr("Downloading tools ({0}/{1})."), i, tools.size());
        i++;
        downloader.download(tool.getDownloadableContribution(platform), progress, msg, progressListener, false);
        progress.stepDone();
      }
    } catch (InterruptedException e) {
      // Download interrupted... just exit
      return errors;
    }

    ContributedPackage pack = contributedPlatform.getParentPackage();
    File packageFolder = new File(BaseNoGui.indexer.getPackagesFolder(), pack.getName());

    // TODO: Extract to temporary folders and move to the final destination only
    // once everything is successfully unpacked. If the operation fails remove
    // all the temporary folders and abort installation.

    List<Map.Entry<ContributedToolReference, ContributedTool>> resolvedToolReferences = contributedPlatform
      .getResolvedToolReferences().entrySet().stream()
      .filter((entry) -> !entry.getValue().isInstalled()
        || entry.getValue().isBuiltIn())
      .collect(Collectors.toList());

    int i = 1;
    for (Map.Entry<ContributedToolReference, ContributedTool> entry : resolvedToolReferences) {
      progress.setStatus(format(tr("Installing tools ({0}/{1})..."), i, resolvedToolReferences.size()));
      progressListener.onProgress(progress);
      i++;
      ContributedTool tool = entry.getValue();
      Path destFolder = Paths.get(BaseNoGui.indexer.getPackagesFolder().getAbsolutePath(), entry.getKey().getPackager(), "tools", tool.getName(), tool.getVersion());

      Files.createDirectories(destFolder);

      DownloadableContribution toolContrib = tool.getDownloadableContribution(platform);
      assert toolContrib.getDownloadedFile() != null;
      new ArchiveExtractor(platform).extract(toolContrib.getDownloadedFile(), destFolder.toFile(), 1);
      try {
        findAndExecutePostInstallScriptIfAny(destFolder.toFile(), contributedPlatform.getParentPackage().isTrusted(), PreferencesData.areInsecurePackagesAllowed());
      } catch (IOException e) {
        errors.add(tr("Error running post install script"));
      }
      tool.setInstalled(true);
      tool.setInstalledFolder(destFolder.toFile());
      progress.stepDone();
    }

    // Unpack platform on the correct location
    progress.setStatus(tr("Installing boards..."));
    progressListener.onProgress(progress);
    File platformFolder = new File(packageFolder, "hardware" + File.separator + contributedPlatform.getArchitecture());
    File destFolder = new File(platformFolder, contributedPlatform.getParsedVersion());
    Files.createDirectories(destFolder.toPath());
    new ArchiveExtractor(platform).extract(contributedPlatform.getDownloadedFile(), destFolder, 1);
    contributedPlatform.setInstalled(true);
    contributedPlatform.setInstalledFolder(destFolder);
    try {
      findAndExecutePostInstallScriptIfAny(destFolder, contributedPlatform.getParentPackage().isTrusted(), PreferencesData.areInsecurePackagesAllowed());
    } catch (IOException e) {
      e.printStackTrace();
      errors.add(tr("Error running post install script"));
    }
    progress.stepDone();

    progress.setStatus(tr("Installation completed!"));
    progressListener.onProgress(progress);

    return errors;
  }

  private void findAndExecutePostInstallScriptIfAny(File folder, boolean trusted, boolean trustAll) throws IOException {
    Collection<File> scripts = platform.postInstallScripts(folder).stream().filter(new FileExecutablePredicate()).collect(Collectors.toList());

    if (scripts.isEmpty()) {
      String[] subfolders = folder.list(new OnlyDirs());
      if (subfolders.length != 1) {
        return;
      }

      findAndExecutePostInstallScriptIfAny(new File(folder, subfolders[0]), trusted, trustAll);
      return;
    }

    executeScripts(folder, scripts, trusted, trustAll);
  }

  private void findAndExecutePreUninstallScriptIfAny(File folder, boolean trusted, boolean trustAll) throws IOException {
    Collection<File> scripts = platform.preUninstallScripts(folder).stream().filter(new FileExecutablePredicate()).collect(Collectors.toList());

    if (scripts.isEmpty()) {
      String[] subfolders = folder.list(new OnlyDirs());
      if (subfolders.length != 1) {
        return;
      }

      findAndExecutePreUninstallScriptIfAny(new File(folder, subfolders[0]), trusted, trustAll);
      return;
    }

    executeScripts(folder, scripts, trusted, trustAll);
  }

  private void executeScripts(File folder, Collection<File> postInstallScripts, boolean trusted, boolean trustAll) throws IOException {
    File script = postInstallScripts.iterator().next();

    if (!trusted && !trustAll) {
      System.err.println(I18n.format(tr("Warning: non trusted contribution, skipping script execution ({0})"), script));
      return;
    }

    if (trustAll) {
      System.err.println(I18n.format(tr("Warning: forced untrusted script execution ({0})"), script));
    }

    ByteArrayOutputStream stdout = new ByteArrayOutputStream();
    ByteArrayOutputStream stderr = new ByteArrayOutputStream();
    Executor executor = new DefaultExecutor();
    executor.setStreamHandler(new PumpStreamHandler(stdout, stderr));
    executor.setWorkingDirectory(folder);
    executor.setExitValues(null);
    int exitValue = executor.execute(new CommandLine(script));
    executor.setExitValues(new int[0]);

    System.out.write(stdout.toByteArray());
    System.err.write(stderr.toByteArray());

    if (executor.isFailure(exitValue)) {
      throw new IOException();
    }
  }

  public synchronized List<String> remove(ContributedPlatform contributedPlatform) {
    if (contributedPlatform == null || contributedPlatform.isBuiltIn()) {
      return new LinkedList<>();
    }
    List<String> errors = new LinkedList<>();
    try {
      findAndExecutePreUninstallScriptIfAny(contributedPlatform.getInstalledFolder(), contributedPlatform.getParentPackage().isTrusted(), PreferencesData.areInsecurePackagesAllowed());
    } catch (IOException e) {
      errors.add(tr("Error running post install script"));
    }

    // Check if the tools are no longer needed
    for (ContributedTool tool : contributedPlatform.getResolvedTools()) {
      // Do not remove used tools
      if (BaseNoGui.indexer.isContributedToolUsed(contributedPlatform, tool))
        continue;

      // Do not remove built-in tools
      if (tool.isBuiltIn())
        continue;

      // Ok, delete the tool
      File destFolder = tool.getInstalledFolder();
      FileUtils.recursiveDelete(destFolder);
      tool.setInstalled(false);
      tool.setInstalledFolder(null);

      // We removed the version folder (.../tools/TOOL_NAME/VERSION)
      // now try to remove the containing TOOL_NAME folder
      // (and silently fail if another version of the tool is installed)
      try {
        Files.delete(destFolder.getParentFile().toPath());
      } catch (Exception e) {
        // ignore
        log.info("The directory is not empty there is another version installed. directory {}",
          destFolder.getParentFile().toPath(),  e);
      }
    }

    FileUtils.recursiveDelete(contributedPlatform.getInstalledFolder());
    contributedPlatform.setInstalled(false);
    contributedPlatform.setInstalledFolder(null);

    return errors;
  }

  public synchronized List<String> updateIndex(ProgressListener progressListener) {
    MultiStepProgress progress = new MultiStepProgress(1);

    final DownloadableContributionsDownloader downloader = new DownloadableContributionsDownloader(BaseNoGui.indexer.getStagingFolder());

    final Set<String> packageIndexURLs = new HashSet<>(
      PreferencesData.getCollection(Constants.PREF_BOARDS_MANAGER_ADDITIONAL_URLS)
    );
    packageIndexURLs.add(Constants.PACKAGE_INDEX_URL);
    List<String> downloadedPackageIndexFilesAccumulator = new LinkedList<>();

    for (String packageIndexURLString : packageIndexURLs) {
      try {
        // Extract the file name from the URL
        final URL packageIndexURL = new URL(packageIndexURLString);
        String indexFileName = FilenameUtils.getName(packageIndexURL.getPath());
        downloadedPackageIndexFilesAccumulator.add(BaseNoGui.indexer.getIndexFile(indexFileName).getName());

        log.info("Start download and signature check of={}", packageIndexURLs);
        downloader.downloadIndexAndSignature(progress, packageIndexURL, progressListener, signatureVerifier);
      } catch (Exception e) {
        log.error(e.getMessage(), e);
        System.err.println(e.getMessage());
      }
    }

    progress.stepDone();
    log.info("Downloaded package index URL={}", packageIndexURLs);
    return downloadedPackageIndexFilesAccumulator;
  }

  public synchronized void deleteUnknownFiles(List<String> downloadedPackageIndexFiles) throws IOException {
    File preferencesFolder = BaseNoGui.indexer.getIndexFile(".").getParentFile();
    File[] additionalPackageIndexFiles = preferencesFolder.listFiles(new PackageIndexFilenameFilter(Constants.DEFAULT_INDEX_FILE_NAME));
    if (additionalPackageIndexFiles == null) {
      return;
    }
    log.info("Check unknown files. Additional package index folder files={}, Additional package index url downloaded={}", downloadedPackageIndexFiles, additionalPackageIndexFiles);

    for (File additionalPackageIndexFile : additionalPackageIndexFiles) {
      if (!downloadedPackageIndexFiles.contains(additionalPackageIndexFile.getName())) {
        log.info("Delete this unknown file={} because not included in this list={}", additionalPackageIndexFile, additionalPackageIndexFiles);
        Files.delete(additionalPackageIndexFile.toPath());
      }
    }
  }
}
