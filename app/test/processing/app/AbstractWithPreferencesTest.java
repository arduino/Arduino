package processing.app;

import org.junit.Before;

import java.io.File;
import java.util.LinkedList;

public abstract class AbstractWithPreferencesTest {

  @Before
  public void init() throws Exception {
    Base.initPlatform();
    BaseNoGui.initPackages();
    BaseNoGui.scanAndUpdateLibraries(new LinkedList<File>());
    BaseNoGui.populateImportToLibraryTable();
    Preferences.init(null);
    Theme.init();

    Base.untitledFolder = Base.createTempFolder("untitled");
    Base.untitledFolder.deleteOnExit();

  }
}
