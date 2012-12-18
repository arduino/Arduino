package processing.app.tools;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpMethod;
import org.apache.commons.httpclient.methods.GetMethod;
import processing.app.Sketch;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class FromURLLibraryImporter {

  private final HttpClient client;

  public FromURLLibraryImporter() {
    client = new HttpClient();
  }

  public File fetchLibraryFrom(String url) throws IOException {
    HttpMethod get = new GetMethod(url);
    get.setFollowRedirects(true);
    try {
      client.executeMethod(get);

      if (get.getStatusCode() != 200) {
        throw new IOException("Server returned error " + get.getStatusCode() + ": " + get.getStatusText());
      }

      String filename = fileNameFrom(get);

      return saveLocalFile(get, filename);
    } finally {
      get.releaseConnection();
    }

  }

  private File saveLocalFile(HttpMethod get, String filename) throws IOException {
    File tempFile = File.createTempFile("arduinoLibrary", "tmp");
    FileOutputStream fos = null;
    try {
      fos = new FileOutputStream(tempFile);
      fos.write(get.getResponseBody());
    } finally {
      if (fos != null) {
        fos.close();
      }
    }

    filename = Sketch.sanitizeName(filename);

    File localFile = new File(tempFile.getParent(), filename);
    if (tempFile.renameTo(localFile)) {
      return localFile;
    }

    return tempFile;
  }

  private String fileNameFrom(HttpMethod get) {
    String filename = get.getPath().substring(get.getPath().lastIndexOf("/"));
    Header contentDisposition = get.getResponseHeader("Content-Disposition");
    if (contentDisposition != null) {
      filename = contentDisposition.getElements()[0].getParameters()[0].getValue();
    }
    return filename;
  }
}
