package processing.app.helpers;

import org.apache.commons.compress.utils.IOUtils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class FileUtils {

  private static final List<String> SOURCE_CONTROL_FOLDERS = Arrays.asList("CVS", "RCS", ".git", ".svn", ".hg", ".bzr");

  /**
   * Checks, whether the child directory is a subdirectory of the base directory.
   *
   * @param base  the base directory.
   * @param child the suspected child directory.
   * @return true, if the child is a subdirectory of the base directory.
   */
  public static boolean isSubDirectory(File base, File child) {
    try {
      base = base.getCanonicalFile();
      child = child.getCanonicalFile();
    } catch (IOException e) {
      return false;
    }

    File parentFile = child;
    while (parentFile != null) {
      if (base.equals(parentFile)) {
        return true;
      }
      parentFile = parentFile.getParentFile();
    }
    return false;
  }

  public static void copyFile(File source, File dest) throws IOException {
    FileInputStream fis = null;
    FileOutputStream fos = null;
    try {
      fis = new FileInputStream(source);
      fos = new FileOutputStream(dest);
      byte[] buf = new byte[4096];
      int readBytes = -1;
      while ((readBytes = fis.read(buf, 0, buf.length)) != -1) {
        fos.write(buf, 0, readBytes);
      }
    } finally {
      IOUtils.closeQuietly(fis);
      IOUtils.closeQuietly(fos);
    }
  }

  public static void copy(File sourceFolder, File destFolder) throws IOException {
    for (File file : sourceFolder.listFiles()) {
      File destFile = new File(destFolder, file.getName());
      if (file.isDirectory() && !SOURCE_CONTROL_FOLDERS.contains(file.getName())) {
        if (!destFile.exists() && !destFile.mkdir()) {
          throw new IOException("Unable to create folder: " + destFile);
        }
        copy(file, destFile);
      } else if (!file.isDirectory()) {
        copyFile(file, destFile);
      }
    }
  }

  public static void recursiveDelete(File file) {
    if (file == null) {
      return;
    }
    if (file.isDirectory()) {
      File[] files = file.listFiles();
      if (files == null) {
        return;
      }
      for (File current : files) {
        recursiveDelete(current);
      }
    }
    file.delete();
  }

  public static File createTempFolder() throws IOException {
    return createTempFolder(new File(System.getProperty("java.io.tmpdir")));
  }

  public static File createTempFolder(File parent) throws IOException {
    return createTempFolder(parent, "arduino_");
  }

  public static File createTempFolder(File parent, String prefix) throws IOException {
    return createTempFolder(parent, prefix, Integer.toString(new Random().nextInt(1000000)));
  }

  public static File createTempFolder(String prefix) throws IOException {
    return createTempFolder(new File(System.getProperty("java.io.tmpdir")), prefix);
  }

  public static File createTempFolder(String prefix, String suffix) throws IOException {
    return createTempFolder(new File(System.getProperty("java.io.tmpdir")), prefix, suffix);
  }

  public static File createTempFolder(File parent, String prefix, String suffix) throws IOException {
    return Files.createDirectories(Paths.get(parent.getAbsolutePath(), prefix + suffix)).toFile();
  }

  public static boolean isSCCSOrHiddenFile(File file) {
    return isSCCSFolder(file) || isHiddenFile(file);
  }

  public static boolean isHiddenFile(File file) {
    return file.isHidden() || file.getName().charAt(0) == '.';
  }

  public static boolean isSCCSFolder(File file) {
    return file.isDirectory() && SOURCE_CONTROL_FOLDERS.contains(file.getName());
  }

  public static String readFileToString(File file) throws IOException {
    return readFileToString(file, "UTF-8");
  }

  public static String readFileToString(File file, String encoding) throws IOException {
    BufferedReader reader = null;
    try {
      reader = new BufferedReader(new InputStreamReader(new FileInputStream(file), encoding));
      StringBuilder sb = new StringBuilder();
      String line;
      while ((line = reader.readLine()) != null) {
        sb.append(line).append("\n");
      }
      return sb.toString();
    } finally {
      IOUtils.closeQuietly(reader);
    }
  }

  /**
   * Writes the given data to the given file, creating the file if it does not exist.
   * This method is equivalent to calling {@code writeStringToFile(file, data, StandardCharsets.UTF_8)}.
   * @param file - The file to write to.
   * @param data - The string to write.
   * @throws IOException If an I/O error occurs.
   */
  public static void writeStringToFile(File file, String data) throws IOException {
    writeStringToFile(file, data, StandardCharsets.UTF_8);
  }

  /**
   * Writes the given data to the given file, creating the file if it does not exist.
   * @param file - The file to write to.
   * @param data - The string to write.
   * @param charset - The charset used to convert the string to bytes.
   * @throws IOException If an I/O error occurs.
   */
  public static void writeStringToFile(File file, String data, Charset charset) throws IOException {
    OutputStream out = null;
    try {
      out = new FileOutputStream(file);
      out.write(data.getBytes(charset));
    } finally {
      IOUtils.closeQuietly(out);
    }
  }

  /**
   * Returns true if the given file has any of the given extensions.
   *
   * @param file       File whose name to look at
   * @param extensions Extensions to consider (just the extension, without the
   *                   dot). Should all be lowercase, case insensitive matching
   *                   is used.
   */
  public static boolean hasExtension(File file, List<String> extensions) {
    String extension = splitFilename(file).extension;
    return extensions.contains(extension.toLowerCase());
  }

  /**
   * Returns the given filename with the extension replaced by the one
   * given. If the filename does not have an extension yet, one is
   * added.
   */
  public static String replaceExtension(String filename, String extension) {
    SplitFile split = splitFilename(filename);
    split.extension = extension;
    return split.join();
  }

  /**
   * Returns the given filename with the extension replaced by the one
   * given. If the filename does not have an extension yet, one is
   * added.
   */
  public static File replaceExtension(File file, String extension) {
    return new File(file.getParentFile(), replaceExtension(file.getName(), extension));
  }

  /**
   * Adds an extension to the given filename. If it already contains
   * one, an additional extension is added. If the extension is the
   * empty string, the file is returned unmodified.
   */
  public static String addExtension(String filename, String extension) {
    return extension.equals("") ? filename : (filename + "." + extension);
  }

  /**
   * Adds an extension to the given filename. If it already contains
   * one, an additional extension is added. If the extension is the
   * empty string, the file is returned unmodified.
   */
  public static File addExtension(File file, String extension) {
    return new File(file.getParentFile(), addExtension(file.getName(), extension));
  }

  /**
   * The result of a splitFilename call.
   */
  public static class SplitFile {
    public SplitFile(String basename, String extension) {
      this.basename = basename;
      this.extension = extension;
    }

    public String basename;
    public String extension;

    public String join() {
      return addExtension(basename, extension);
    }
  }

  /**
   * Splits the given filename into a basename (everything up to the
   * last dot) and an extension (everything from the last dot). The dot
   * is not included in either part.
   *
   * If no dot is present, the entire filename is returned as the
   * basename, leaving the extension empty (empty string, not null).
   */
  public static SplitFile splitFilename(String filename) {
    int index = filename.lastIndexOf(".");

    if (index >= 0)
      return new SplitFile(filename.substring(0, index), filename.substring(index + 1));
    return new SplitFile(filename, "");
  }

  /**
   * Helper function returning splitFilename(file.getName()).
   */
  public static SplitFile splitFilename(File file) {
    return splitFilename(file.getName());
  }

  /**
   * Recursively find all files in a folder with the specified
   * extension. Excludes hidden files and folders and
   * source control folders.
   *
   * @param folder     Folder to look into
   * @param recursive  <b>true</b> will recursively find all files in sub-folders
   * @param extensions A list of file extensions to search (just the extension,
   *                   without the dot). Should all be lowercase, case
   *                   insensitive matching is used. If no extensions are
   *                   passed, all files are returned.
   * @return
   */
  public static List<File> listFiles(File folder, boolean recursive,
                                     String... extensions) {
    return listFiles(folder, recursive, Arrays.asList(extensions));
  }

  public static List<File> listFiles(File folder, boolean recursive,
                                     List<String> extensions) {
    List<File> result = new ArrayList<>();
    if (!folder.exists()) {
      return result;
    }

    for (File file : folder.listFiles()) {
      if (isSCCSOrHiddenFile(file))
        continue;

      if (file.isDirectory()) {
        if (recursive)
          result.addAll(listFiles(file, true, extensions));
        continue;
      }

      if (extensions.isEmpty() || hasExtension(file, extensions))
        result.add(file);
    }
    return result;
  }

}
