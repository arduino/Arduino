package processing.app.preproc;

import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.helpers.PreferencesMap;
import processing.app.packages.Library;
import processing.app.packages.LibraryList;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import static processing.app.I18n._;

public class IncludesToIncludeFolders implements PreprocessorChainRing {

  private final PreferencesMap prefs;
  private final boolean verbose;

  public IncludesToIncludeFolders(PreferencesMap prefs, boolean verbose) {
    this.prefs = prefs;
    this.verbose = verbose;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    LibraryList importedLibraries = listLibraries((List<String>) context.get("includes"));
    context.put("importedLibraries", importedLibraries);

    List<File> includeFolders = listIncludeFolders(importedLibraries, verbose);
    context.put("includeFolders", includeFolders);
  }

  private LibraryList listLibraries(List<String> includes) {
    LibraryList importedLibraries = new LibraryList();
    for (String include : includes) {
      Library lib = BaseNoGui.importToLibraryTable.get(include);
      if (lib != null && !importedLibraries.contains(lib)) {
        importedLibraries.add(lib);
      }
    }
    return importedLibraries;
  }

  private List<File> listIncludeFolders(LibraryList importedLibraries, boolean verbose) {
    List<File> includeFolders = new ArrayList<File>();
    includeFolders.add(prefs.getFile("build.core.path"));
    if (prefs.getFile("build.variant.path") != null)
      includeFolders.add(prefs.getFile("build.variant.path"));
    for (Library lib : importedLibraries) {
      if (verbose)
        System.out.println(I18n
                .format(_("Using library {0} in folder: {1} {2}"), lib.getName(),
                        lib.getFolder(), lib.isLegacy() ? "(legacy)" : ""));
      includeFolders.add(lib.getSrcFolder());
    }
    return includeFolders;
  }


}
