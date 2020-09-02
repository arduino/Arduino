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


package cc.arduino.utils.network;

import cc.arduino.utils.FileHash;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.databind.node.ObjectNode;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import processing.app.BaseNoGui;
import processing.app.PreferencesData;
import processing.app.helpers.FileUtils;

import javax.script.ScriptException;
import java.io.File;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.ProtocolException;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.NoSuchAlgorithmException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.stream.Collectors;

public class FileDownloaderCache {
  private final static String CACHE_ENABLE_PREFERENCE_KEY = "cache.enable";
  private final static Logger log = LogManager
    .getLogger(FileDownloaderCache.class);
  private final static Map<String, FileCached> cachedFiles = Collections
    .synchronizedMap(new HashMap<>());
  private final static String cacheFolder;
  private static boolean enableCache;

  static {
    enableCache = Boolean.valueOf(PreferencesData.get(CACHE_ENABLE_PREFERENCE_KEY, "true"));
    if (!enableCache) {
      log.info("The cache is disable cache.enable=false");
    }
    PreferencesData.set(CACHE_ENABLE_PREFERENCE_KEY, Boolean.toString(enableCache));

    final File settingsFolder;
    settingsFolder = BaseNoGui.getSettingsFolder();
    if (settingsFolder != null) {
      cacheFolder = Paths.get(settingsFolder.getPath(), "cache")
        .toString();
    } else {
      enableCache = false;
      cacheFolder = null;
      log.error("The cache will disable because the setting folder is null, cannot generate the cache path");
    }
    final Path pathCacheInfo = getCachedInfoPath();
    log.info("Cache folder {}", cacheFolder);
    try {
      if (Files.exists(pathCacheInfo)) {
        ObjectMapper mapper = new ObjectMapper();
        final JsonNode jsonNode = mapper.readTree(pathCacheInfo.toFile());

        // Read the files array
        TypeReference<List<FileCached>> typeRef = new TypeReference<List<FileCached>>() {
        };
        final List<FileCached> files = mapper
          .readValue(mapper.treeAsTokens(jsonNode.get("files")), typeRef);

        // Update the map with the remote url as a key and the file cache info as a value
        cachedFiles.putAll(Collections
          .synchronizedMap(files
            .stream()
            .filter(FileCached::exists)
            .collect(Collectors.toMap(FileCached::getRemoteURL, Function.identity()))
          )
        );
        log.info("Number of file already in the cache {}", cachedFiles.size());

      }
    } catch (Exception e) {
      log.error("Cannot initialized the cache", e);
    }
  }

  public static Optional<FileCached> getFileCached(final URL remoteURL)
    throws URISyntaxException, NoSuchMethodException, ScriptException,
    IOException {
    return getFileCached(remoteURL, true);
  }

  public static Optional<FileCached> getFileCached(final URL remoteURL, boolean enableCache)
    throws URISyntaxException, NoSuchMethodException, ScriptException,
    IOException {
    // Return always and empty file if the cache is not enable
    if (!(enableCache && FileDownloaderCache.enableCache)) {
      log.info("The cache is not enable.");
      return Optional.empty();
    }
    final String[] splitPath = remoteURL.getPath().split("/");
    if (splitPath.length == 0) {
      log.warn("The remote path as no file name {}", remoteURL);
      return Optional.empty();
    }
    // Create the path where the cached file should exist
    final Deque<String> addFirstRemoteURL = new LinkedList<>(Arrays.asList(splitPath));
    addFirstRemoteURL.addFirst(remoteURL.getHost());
    final Path cacheFilePath = Paths.get(cacheFolder, addFirstRemoteURL.toArray(new String[0]));

    // Take from the cache the file info or build from scratch
    final FileCached fileCached = Optional.ofNullable(cachedFiles.get(remoteURL.toString()))
      .orElseGet(() -> new FileCached(remoteURL.toString(), cacheFilePath.toString()));

    // If the file is change of the cache is disable run the HEAD request to check if the file is changed
    log.info("Get file cached is expire {}, exist {}, info {} ", fileCached.isExpire(), fileCached.exists(), fileCached);
    if (fileCached.isExpire() || !fileCached.exists()) {
      // Update remote etag and cache control header
      final Optional<FileCached> fileCachedInfoUpdated =
        FileDownloaderCache.updateCacheInfo(remoteURL, (remoteETagClean, cacheControl) -> {
          // Check cache control data
          if (cacheControl.isNoCache() || cacheControl.isMustRevalidate() || cacheControl.isNoStore()) {
            log.warn("The file {} must not be cache due to cache control header {}",
              remoteURL, cacheControl);
            return Optional.empty();
          }
          log.info("Update cached info of {}, createdAt {}, previous eTag {}, last eTag {}, cache control header {} ",
            remoteURL, fileCached.createdAt, fileCached.eTag, remoteETagClean, cacheControl);
          final FileCached fileCachedUpdateETag = new FileCached(
            remoteURL.toString(),
            cacheFilePath.toString(),
            fileCached.eTag,
            remoteETagClean, // Set the lastETag
            fileCached.md5,
            cacheControl // Set the new cache control
          );
          cachedFiles.put(remoteURL.toString(), fileCachedUpdateETag);
          return Optional.of(fileCachedUpdateETag);
        });
      FileDownloaderCache.updateCacheFilesInfo();
      return fileCachedInfoUpdated;
    }
    return Optional.of(fileCached);
  }

  private static Optional<FileCached> updateCacheInfo(URL remoteURL, BiFunction<String, CacheControl, Optional<FileCached>> getNewFile)
    throws URISyntaxException, NoSuchMethodException, ScriptException,
    IOException {
    // Update the headers of the cached file
    final HttpURLConnection headRequest = new HttpConnectionManager(
      remoteURL).makeConnection((connection) -> {
      try {
        connection.setRequestMethod("HEAD");
      } catch (ProtocolException e) {
        log.error("Invalid protocol", e);
      }
    });
    final int responseCode = headRequest.getResponseCode();
    headRequest.disconnect();
    // Something bad is happening return a conservative true to try to download the file
    if (responseCode < 200 || responseCode >= 300) {
      log.warn("The head request return a bad response code " + responseCode);
      // if something bad happend
      return Optional.empty();
    }
    // Get all the useful headers
    String remoteETag = headRequest.getHeaderField("ETag");
    String cacheControlHeader = headRequest.getHeaderField("Cache-Control");
    if (remoteETag != null && cacheControlHeader != null) {
      final String remoteETagClean = remoteETag.trim().replace("\"", "");
      final CacheControl cacheControl = CacheControl.valueOf(cacheControlHeader);
      return getNewFile.apply(remoteETagClean, cacheControl);
    }
    log.warn("The head request do not return the ETag {} or the Cache-Control {}", remoteETag, cacheControlHeader);
    return Optional.empty();
  }

  private synchronized static void updateCacheFilesInfo() throws IOException {
    ObjectMapper mapper = new ObjectMapper();
    // Generate a pretty json
    mapper.enable(SerializationFeature.INDENT_OUTPUT);
    final ObjectNode objectNode = mapper.createObjectNode();
    // Generate a json {"files":[...{files_info}...]}
    objectNode.putArray("files").addAll(
      cachedFiles.values().stream()
        .map((v) -> mapper.convertValue(v, JsonNode.class))
        .collect(Collectors.toList()));
    // Create the path Arduino15/cache
    Path cachedFileInfo = getCachedInfoPath();
    if (Files.notExists(cachedFileInfo)) {
      Files.createDirectories(cachedFileInfo.getParent());
    }
    log.info("Update cache file info in {}, number of cached files is {}", cachedFileInfo.toFile(), cachedFiles.size());
    // Write to cache.json
    mapper.writeValue(cachedFileInfo.toFile(), objectNode);
  }

  private static Path getCachedInfoPath() {
    return Paths.get(cacheFolder, "cache.json");
  }

  @JsonIgnoreProperties(ignoreUnknown = true)
  static class FileCached {
    private final String remoteURL;
    private final String localPath;
    private final String eTag;
    private final String lastETag;
    private final String md5;
    private final String createdAt;
    private final CacheControl cacheControl;

    FileCached() {
      this.remoteURL = null;
      this.localPath = null;
      lastETag = null;
      eTag = null;
      md5 = null;
      createdAt = null;
      cacheControl = null;
    }

    FileCached(String remoteURL, String localPath) {
      this.remoteURL = remoteURL;
      this.localPath = localPath;
      lastETag = null;
      eTag = null;
      md5 = null;
      createdAt = LocalDateTime.now().format(DateTimeFormatter.ISO_DATE_TIME);
      cacheControl = null;
    }

    public FileCached(String remoteURL, String localPath, String eTag, String lastETag, String md5, CacheControl cacheControl) {
      this.remoteURL = remoteURL;
      this.localPath = localPath;
      this.eTag = eTag;
      this.lastETag = lastETag;
      this.md5 = md5;
      this.createdAt = LocalDateTime.now().format(DateTimeFormatter.ISO_DATE_TIME);
      this.cacheControl = cacheControl;
    }

    @JsonIgnore
    public boolean isExpire() {
      // Check if the file is expire
      final LocalDateTime now = LocalDateTime.now();
      return this.getExpiresTime().isBefore(now) || this.getExpiresTime().isEqual(now);
    }

    @JsonIgnore
    public boolean isNotChange() {
      return !isChange();
    }

    @JsonIgnore
    public boolean isChange() {
      // Check if the file is expire
      boolean isChange = false;
      if (isExpire()) {
        log.debug("The file \"{}\" is expire. Expire time: {}", localPath,
          this.getExpiresTime().format(DateTimeFormatter.ISO_DATE_TIME));
        isChange = true;
      }

      if (lastETag != null && !lastETag.equals(eTag)) {
        // If are different means that the file is change
        log.debug("The file \"{}\" is changed last ETag != now Etag ({}!={})", localPath, lastETag, eTag);
        isChange = true;
      }
      return isChange;
    }

    @JsonIgnore
    public boolean exists() {
      return localPath != null && Files.exists(Paths.get(localPath));
    }

    @JsonIgnore
    public Optional<File> getFileFromCache() {
      if (md5Check()) {
        return Optional.of(Paths.get(localPath).toFile());
      }
      return Optional.empty();

    }

    public synchronized void updateCacheFile(File fileToCache) throws Exception {
      Path cacheFilePath = Paths.get(localPath);

      // If the cache directory does not exist create it
      if (!Files.exists(cacheFilePath.getParent())) {
        Files.createDirectories(cacheFilePath.getParent());
      }
      FileUtils.copyFile(fileToCache, cacheFilePath.toFile());
      final String md5 = this.calculateMD5();
      final String eTag;
      if (lastETag == null) {
        log.warn("The eTag was not calculate this time, is not the right behaviour fileCached={}, md5={}", this, md5);
        eTag = this.eTag;
      } else {
        eTag = this.lastETag;
      }
      FileCached newFileCached = new FileCached(
        this.remoteURL,
        this.localPath,
        eTag, // Initialize the right eTag with the last eTag because the file was updated
        eTag,
        md5,
        this.cacheControl
      );
      log.info("Update cache file: {}", newFileCached);
      cachedFiles.put(remoteURL, newFileCached);
      updateCacheFilesInfo();

    }

    public synchronized void invalidateCache() throws IOException {
      cachedFiles.remove(remoteURL);
      Files.deleteIfExists(Paths.get(localPath));
    }

    private String calculateMD5() throws IOException, NoSuchAlgorithmException {
      if (exists()) {
        return FileHash.hash(Paths.get(localPath).toFile(), "MD5");
      }
      return null;
    }

    @JsonIgnore
    public boolean md5Check() {
      try {
        return !Objects.isNull(getMD5()) && Objects.equals(calculateMD5(), getMD5());
      } catch (Exception e) {
        log.error("Fail to calculate the MD5. file={}", this, e);
        return false;
      }
    }

    @JsonIgnore
    public LocalDateTime getExpiresTime() {
      final int maxAge;
      if (cacheControl != null) {
        maxAge = cacheControl.getMaxAge();
      } else {
        maxAge = 0;
      }
      if (createdAt != null) {
        return LocalDateTime.parse(createdAt, DateTimeFormatter.ISO_DATE_TIME)
          .plusSeconds(maxAge);
      }
      return LocalDateTime.now();

    }

    public String getExpires() {
      return getExpiresTime().toString();
    }

    public String getMD5() {
      return md5;
    }

    public String geteTag() {
      return eTag;
    }

    public String getRemoteURL() {
      return remoteURL;
    }

    public String getLocalPath() {
      return localPath;
    }

    public String getCreatedAt() {
      return createdAt;
    }

    public CacheControl getCacheControl() {
      return cacheControl;
    }

    @Override
    public String toString() {
      return "FileCached{" +
        "eTag='" + eTag + '\'' +
        ", lastETag='" + lastETag + '\'' +
        ", remoteURL='" + remoteURL + '\'' +
        ", localPath='" + localPath + '\'' +
        ", md5='" + md5 + '\'' +
        ", createdAt='" + createdAt + '\'' +
        ", cacheControl=" + cacheControl +
        '}';
    }
  }
}
