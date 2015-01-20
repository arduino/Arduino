package processing.app.preproc;

import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.helpers.PreferencesMap;
import processing.app.packages.Library;
import processing.app.packages.LibraryList;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

import static processing.app.I18n._;

public class VerifyLibraryArch implements PreprocessorChainRing {

  private final PreferencesMap prefs;

  public VerifyLibraryArch(PreferencesMap prefs) {
    this.prefs = prefs;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    LibraryList importedLibraries = (LibraryList) context.get("importedLibraries");

    List<String> archs = new ArrayList<String>();
    archs.add(BaseNoGui.getTargetPlatform().getId());
    if (prefs.containsKey("architecture.override_check")) {
      String[] overrides = prefs.get("architecture.override_check").split(",");
      archs.addAll(Arrays.asList(overrides));
    }

    for (Library lib : importedLibraries) {
      if (!lib.supportsArchitecture(archs)) {
        System.err.println(I18n
                .format(_("WARNING: library {0} claims to run on {1} "
                        + "architecture(s) and may be incompatible with your"
                        + " current board which runs on {2} architecture(s)."), lib
                        .getName(), lib.getArchitectures(), archs));
        System.err.println();
      }
    }

  }
}
