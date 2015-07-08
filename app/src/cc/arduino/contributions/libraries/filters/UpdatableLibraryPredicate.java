package cc.arduino.contributions.libraries.filters;

import cc.arduino.contributions.VersionComparator;
import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.LibrariesIndexer;
import processing.app.packages.UserLibrary;

import java.util.List;
import java.util.function.Predicate;

public class UpdatableLibraryPredicate implements Predicate<ContributedLibrary> {

  private final LibrariesIndexer indexer;
  private final VersionComparator versionComparator;

  public UpdatableLibraryPredicate(LibrariesIndexer indexer) {
    this.indexer = indexer;
    this.versionComparator = new VersionComparator();
  }

  @Override
  public boolean test(ContributedLibrary contributedLibrary) {
    String libraryName = contributedLibrary.getName();
    UserLibrary installed = indexer.getInstalledLibraries().getByName(libraryName);
    if (installed == null) {
      return false;
    }
    List<ContributedLibrary> libraries = indexer.getIndex().find(libraryName);
    return libraries.stream()
      .filter(library -> versionComparator.greaterThan(library.getParsedVersion(), installed.getParsedVersion()))
      .count() > 0;
  }
}
