package cc.arduino.utils.network;

import com.sun.istack.internal.NotNull;
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
  private final URL remoteURL;
  private final Path cacheFilePath;
  // Will be initialized by call the checkIfTheFileIsChanged function
  private String eTag;

  // BaseNoGui.getSettingsFolder()
  public FileDownloaderCache(@NotNull String cacheFolder, @NotNull URL remoteURL) {
    this.remoteURL = remoteURL;
    String[] splitPath = remoteURL.getPath().split("/");
    if (splitPath.length > 0) {
      this.cacheFilePath = Paths.get(cacheFolder, splitPath);
    } else {
      this.cacheFilePath = null;
    }
  }

  public boolean checkIfTheFileIsChanged()
    throws NoSuchMethodException, ScriptException, IOException,
    URISyntaxException {

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
      return true;
    }

    final String remoteETag = headRequest.getHeaderField("ETag");
    final String localETag = PreferencesData.get(getPreferencesDataKey());

    // If the header doesn't exist or the local cache doesn't exist you need to download the file
    if (remoteETag == null || localETag == null) {
      return true;
    }
    eTag = remoteETag.trim().replace("\"", "");

    // If are different means that the file is change
    return !eTag.equals(localETag);
  }

  public Optional<File> getFileFromCache() {
    if (Optional.ofNullable(cacheFilePath).isPresent() && Files.exists(cacheFilePath)) {
      return Optional.of(new File(cacheFilePath.toUri()));
    }
    return Optional.empty();

  }

  public void fillCache(File fileToCache) throws Exception {
    if (Optional.ofNullable(eTag).isPresent() &&
      Optional.ofNullable(cacheFilePath).isPresent()) {

      PreferencesData.set(getPreferencesDataKey(), eTag);
      // If the cache directory does not exist create it
      if (!Files.exists(cacheFilePath.getParent())) {
        Files.createDirectories(cacheFilePath.getParent());
      }
      FileUtils.copyFile(fileToCache, cacheFilePath.toFile());
    }
  }

  private String getPreferencesDataKey() {
    return "cache.file." + remoteURL.getPath();
  }
}
