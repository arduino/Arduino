package cc.arduino.utils.network;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
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
import java.util.Optional;

public class FileDownloaderCache {
  private static Logger log = LoggerFactory.getLogger(FileDownloaderCache.class);
  private final Path cacheFilePath;
  private final String remoteETag;
  private final String preferencesDataKey;

  // BaseNoGui.getSettingsFolder()
  private FileDownloaderCache(Path cacheFilePath, String remoteETag, String preferencesDataKey) {
    this.cacheFilePath = cacheFilePath;
    this.remoteETag = remoteETag;
    this.preferencesDataKey = preferencesDataKey;
  }

  public static FileDownloaderCache getFileCached(String cacheFolder, URL remoteURL)
    throws IOException, NoSuchMethodException, ScriptException, URISyntaxException {

    final String[] splitPath = remoteURL.getPath().split("/");
    final String preferencesDataKey = "cache.file." + remoteURL.getPath();
    final Path cacheFilePath;
    if (splitPath.length > 0) {
      cacheFilePath = Paths.get(cacheFolder, splitPath);
    } else {
      cacheFilePath = null;
    }

    final HttpURLConnection headRequest = new HttpConnectionManager(remoteURL)
      .makeConnection((connection) -> {
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
      return new FileDownloaderCache(cacheFilePath, null, preferencesDataKey);
    }

    final String remoteETag = headRequest.getHeaderField("ETag");
    String remoteETagClean = null;
    if (remoteETag != null) {
      remoteETagClean = remoteETag.trim().replace("\"", "");
    }

    return new FileDownloaderCache(cacheFilePath, remoteETagClean, preferencesDataKey);
  }

  public boolean isChange() {

    final String localETag = PreferencesData.get(preferencesDataKey);

    // If the header doesn't exist or the local cache doesn't exist you need to download the file
    if (cacheFilePath == null || remoteETag == null || localETag == null) {
      return true;
    }

    // If are different means that the file is change
    return !remoteETag.equals(localETag);
  }

  public Optional<File> getFileFromCache() {
    if (Optional.ofNullable(cacheFilePath).isPresent() && Files.exists(cacheFilePath)) {
      return Optional.of(new File(cacheFilePath.toUri()));
    }
    return Optional.empty();

  }

  public void fillCache(File fileToCache) throws Exception {
    if (Optional.ofNullable(remoteETag).isPresent() &&
      Optional.ofNullable(cacheFilePath).isPresent()) {

      PreferencesData.set(preferencesDataKey, remoteETag);
      // If the cache directory does not exist create it
      if (!Files.exists(cacheFilePath.getParent())) {
        Files.createDirectories(cacheFilePath.getParent());
      }
      FileUtils.copyFile(fileToCache, cacheFilePath.toFile());
    }
  }

}
