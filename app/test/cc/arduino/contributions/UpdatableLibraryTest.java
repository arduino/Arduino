package cc.arduino.contributions;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.LibrariesIndexer;
import processing.app.BaseNoGui;
import processing.app.packages.UserLibraryFolder;
import processing.app.packages.UserLibraryFolder.Location;

public class UpdatableLibraryTest {

  File testdata = new File(
      UpdatableLibraryTest.class.getResource("/").getFile(),
      "../testdata/libraries");
  File index_SD_only = new File(testdata, "index_SD_only");
  File SD111 = new File(testdata, "SD_1.1.1");
  File SD121 = new File(testdata, "SD_1.2.1");
  File index_Bridge_only = new File(testdata, "index_Bridge_only");
  File Bridge163 = new File(testdata, "Bridge_1.6.3");
  File Bridge170 = new File(testdata, "Bridge_1.7.0");

  @Test
  public void testUpdatableLibrary() throws Exception {
    List<UserLibraryFolder> folders = new ArrayList<>();
    folders.add(new UserLibraryFolder(SD111, Location.IDE_BUILTIN));

    LibrariesIndexer indexer = new LibrariesIndexer(index_SD_only);
    BaseNoGui.librariesIndexer = indexer;
    indexer.parseIndex();
    indexer.setLibrariesFolders(folders);
    indexer.rescanLibraries();

    ContributedLibrary sdLib = indexer.getIndex().getInstalled("SD").get();
    assertTrue("SD lib is installed", sdLib.isLibraryInstalled());
    assertEquals("SD installed version", "1.1.1", sdLib.getParsedVersion());

    assertTrue(ContributionsSelfCheck.checkForUpdatableLibraries());

    folders.add(new UserLibraryFolder(SD121, Location.SKETCHBOOK));
    indexer.setLibrariesFolders(folders);

    sdLib = indexer.getIndex().getInstalled("SD").get();
    assertTrue("SD lib is installed", sdLib.isLibraryInstalled());
    assertEquals("SD installed version", "1.2.1", sdLib.getParsedVersion());

    assertFalse(ContributionsSelfCheck.checkForUpdatableLibraries());
  }

  @Test
  public void testUpdatableLibraryWithBundled() throws Exception {
    List<UserLibraryFolder> folders = new ArrayList<>();
    folders.add(new UserLibraryFolder(Bridge163, Location.IDE_BUILTIN));

    LibrariesIndexer indexer = new LibrariesIndexer(index_Bridge_only);
    BaseNoGui.librariesIndexer = indexer;
    indexer.parseIndex();
    indexer.setLibrariesFolders(folders);
    indexer.rescanLibraries();

    ContributedLibrary l = indexer.getIndex().getInstalled("Bridge").get();
    assertTrue("Bridge lib is installed", l.isLibraryInstalled());
    assertEquals("Bridge installed version", "1.6.3", l.getParsedVersion());

    assertTrue(ContributionsSelfCheck.checkForUpdatableLibraries());

    folders.add(new UserLibraryFolder(Bridge170, Location.SKETCHBOOK));
    indexer.setLibrariesFolders(folders);

    l = indexer.getIndex().getInstalled("Bridge").get();
    assertTrue("Bridge lib is installed", l.isLibraryInstalled());
    assertEquals("Bridge installed version", "1.7.0", l.getParsedVersion());

    assertFalse(ContributionsSelfCheck.checkForUpdatableLibraries());
  }
}
