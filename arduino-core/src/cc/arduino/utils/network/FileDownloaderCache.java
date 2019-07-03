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
  private final static Logger log = LogManager
    .getLogger(FileDownloaderCache.class);
  private static Map<String, FileCached> cachedFiles = Collections
    .synchronizedMap(new HashMap<>());
  private static String cacheFolder;
  private static boolean enableCache;

  static {
    final File settingsFolder;
    try {
      settingsFolder = BaseNoGui.getPlatform().getSettingsFolder();
      cacheFolder = Paths.get(settingsFolder.getPath(), "cache")
        .toString();
      final Path pathCacheInfo = getCachedInfoPath();
      if (Files.exists(pathCacheInfo)) {
        ObjectMapper mapper = new ObjectMapper();
        final JsonNode jsonNode = mapper.readTree(pathCacheInfo.toFile());

        // Read the files array
        TypeReference<List<FileCached>> typeRef = new TypeReference<List<FileCached>>() {
        };
        final List<FileCached> files = mapper
          .readValue(mapper.treeAsTokens(jsonNode.get("files")), typeRef);

        // Create a map with the remote url as a key and the file cache info as a value
        cachedFiles = Collections
          .synchronizedMap(files.stream().collect(
            Collectors.toMap(FileCached::getRemoteURL, Function.identity())));
      }
    } catch (Exception e) {
      log.error("Cannot initialized the cache", e);
    }
    enableCache = Boolean.valueOf(PreferencesData.get("cache.enable", "true"));
    if (!enableCache) {
      log.info("The cache is disable cache.enable=false");
    }
  }

  public static Optional<FileCached> getFileCached(URL remoteURL)
    throws URISyntaxException, NoSuchMethodException, ScriptException,
    IOException {

    final String[] splitPath = remoteURL.getPath().split("/");
    if (splitPath.length == 0) {
      log.warn("The remote path as no file name {}", remoteURL);
      return Optional.empty();
    }

    // Take from the cache the file info or build from scratch
    final FileCached fileCachedOpt = Optional.ofNullable(cachedFiles.get(remoteURL.toString()))
      .orElseGet(() -> {
        Deque<String> addFirstRemoteURL = new LinkedList<>(Arrays.asList(splitPath));
        addFirstRemoteURL.addFirst(remoteURL.getHost());
        final Path cacheFilePath = Paths.get(cacheFolder, addFirstRemoteURL.toArray(new String[0]));
        return new FileCached(remoteURL.toString(), cacheFilePath.toString());
      });
    // If the file is change of the cache is disable run the HEAD request to check if the file is changed
    if (fileCachedOpt.isChange() || !enableCache) {
      // Update remote etag and cache control header
      return FileDownloaderCache.updateCacheInfo(remoteURL, (remoteETagClean, cacheControl) -> {
        // Check cache control data
        if (cacheControl.isNoCache() || cacheControl.isMustRevalidate() || cacheControl.isNoStore()) {
          log.warn("The file {} must not be cache due to cache control header {}",
            remoteURL, cacheControl);
          return Optional.empty();
        }
        fileCachedOpt.setLastETag(remoteETagClean);
        fileCachedOpt.setCacheControl(cacheControl);
        return Optional.of(fileCachedOpt);
      });
    }
    return Optional.of(fileCachedOpt);
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

  private static void updateCacheFilesInfo() throws IOException {
    if (cachedFiles != null) {
      synchronized (cachedFiles) {
        ObjectMapper mapper = new ObjectMapper();
        mapper.enable(SerializationFeature.INDENT_OUTPUT);
        final ObjectNode objectNode = mapper.createObjectNode();
        objectNode.putArray("files").addAll(
          cachedFiles.values().stream()
            .map((v) -> mapper.convertValue(v, JsonNode.class))
            .collect(Collectors.toList()));
        // Create the path Arduino15/cache
        Path cachedFileInfo = getCachedInfoPath();
        if (Files.notExists(cachedFileInfo)) {
          Files.createDirectories(cachedFileInfo.getParent());
        }
        mapper.writeValue(cachedFileInfo.toFile(), objectNode);
      }
    }
  }

  private static Path getCachedInfoPath() {
    return Paths.get(cacheFolder, "cache.json");
  }

  @JsonIgnoreProperties(ignoreUnknown = true)
  static class FileCached {
    private final String remoteURL;
    private final String localPath;
    private String eTag;
    private String lastETag;
    private String md5;
    private String createdAt;
    private CacheControl cacheControl;

    FileCached() {
      this.remoteURL = null;
      this.localPath = null;
    }

    FileCached(String remoteURL, String localPath) {
      this.remoteURL = remoteURL;
      this.localPath = localPath;
    }

    @JsonIgnore
    public boolean isChange() {
      // Check if the file is expire
      if (this.getExpiresTime().isAfter(LocalDateTime.now())) {
        log.info("The file \"{}\" is no expire, the etag will not be checked. Expire time: {}", localPath, this.getExpiresTime().toString());
        return false;
      }

      if (lastETag != null) {
        // If are different means that the file is change
        return !lastETag.equals(eTag);
      }
      return true;
    }

    @JsonIgnore
    public boolean exists() throws IOException {
      if (localPath != null && Files.exists(Paths.get(localPath))) {
        try {
          final String md5Local = FileHash.hash(Paths.get(localPath).toFile(), "MD5");
          if (md5Local.equals(md5)) {
            return true;
          }
        } catch (NoSuchAlgorithmException e) {
          log.error("MD5 algorithm is not supported", e);
        }
      }
      return false;
    }

    @JsonIgnore
    public Optional<File> getFileFromCache() {
      if (localPath != null && Files.exists(Paths.get(localPath))) {
        return Optional.of(new File(localPath));
      }
      return Optional.empty();

    }

    public void updateCacheFile(File fileToCache) throws Exception {
      if (Optional.ofNullable(lastETag).isPresent() && Optional
        .ofNullable(localPath).isPresent()) {
        Path cacheFilePath = Paths.get(localPath);

        // If the cache directory does not exist create it
        if (!Files.exists(cacheFilePath.getParent())) {
          Files.createDirectories(cacheFilePath.getParent());
        }
        final File cacheFile = cacheFilePath.toFile();
        FileUtils.copyFile(fileToCache, cacheFile);
        eTag = lastETag;
        createdAt = LocalDateTime.now().format(DateTimeFormatter.ISO_DATE_TIME);
        updateMD5();
      }
      log.info("Update cache file: {}", this);
      cachedFiles.put(remoteURL, this);
      updateCacheFilesInfo();
    }

    private void updateMD5() throws IOException, NoSuchAlgorithmException {
      if (localPath != null) {
        md5 = FileHash.hash(Paths.get(localPath).toFile(), "MD5");
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

    public void setMd5(String md5) {
      this.md5 = md5;
    }

    public String getCreatedAt() {
      return createdAt;
    }

    public CacheControl getCacheControl() {
      return cacheControl;
    }

    public void seteTag(String eTag) {
      this.eTag = eTag;
    }

    public void setLastETag(String lastETag) {
      this.lastETag = lastETag;
    }

    public void setCacheControl(CacheControl cacheControl) {
      this.cacheControl = cacheControl;
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
