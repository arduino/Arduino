package cc.arduino.utils.network;

import com.sun.istack.internal.NotNull;
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
import java.util.logging.Logger;

public class FileDownloaderCache {
  private static Logger log = Logger
    .getLogger(FileDownloaderCache.class.getName());
  private final String cacheFolder;
  private final URL remoteURL;
  private final Path cacheFilePath;
  // Will be initialized by call the checkIfTheFileIsChanged function
  private String eTag;

  // BaseNoGui.getSettingsFolder()
  public FileDownloaderCache(@NotNull String cacheFolder, @NotNull URL remoteURL) {
    this.cacheFolder = cacheFolder;
    this.remoteURL = remoteURL;
    String[] splitPath = remoteURL.getPath().split("/");
    if (splitPath.length > 0) {
      this.cacheFilePath = Paths.get(cacheFolder, splitPath[splitPath.length - 1]);
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
          throw new RuntimeException(e);
        }
      });
    final int responseCode = headRequest.getResponseCode();
    // Something bad is happening return a conservative true to try to download the file
    if (responseCode < 200 || responseCode >= 300) {
      log.warning("The head request return a bad response code " + responseCode);
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
    if (Optional.ofNullable(cacheFilePath).isPresent()) {
      if (Files.exists(cacheFilePath)) {
        return Optional.of(new File(cacheFilePath.toUri()));
      }
    }
    return Optional.empty();

  }

  public void fillCache(File fileToCache) throws Exception {
    if (Optional.ofNullable(eTag).isPresent() &&
      Optional.ofNullable(cacheFilePath).isPresent()) {

      PreferencesData.set(getPreferencesDataKey(), eTag);
      // If the cache directory does not exist create it
      final Path cachePath = Paths.get(cacheFolder);
      if (!Files.exists(cachePath)) {
        Files.createDirectory(cachePath);
      }
      FileUtils.copyFile(fileToCache, cacheFilePath.toFile());
    }
  }

  private String getPreferencesDataKey() {
    return "cache.file." + remoteURL.getPath();
  }
}
