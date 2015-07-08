package cc.arduino.contributions.packages.filters;

import cc.arduino.contributions.VersionComparator;
import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.packages.ContributionsIndexer;

import java.util.List;
import java.util.function.Predicate;

public class UpdatablePlatformPredicate implements Predicate<ContributedPlatform> {

  private final ContributionsIndexer indexer;
  private final VersionComparator versionComparator;

  public UpdatablePlatformPredicate(ContributionsIndexer indexer) {
    this.indexer = indexer;
    this.versionComparator = new VersionComparator();
  }

  @Override
  public boolean test(ContributedPlatform contributedPlatform) {
    String packageName = contributedPlatform.getParentPackage().getName();
    String architecture = contributedPlatform.getArchitecture();

    ContributedPlatform installed = indexer.getInstalled(packageName, architecture);
    if (installed == null) {
      return false;
    }

    List<ContributedPlatform> platforms = indexer.getIndex().findPlatforms(packageName, architecture);
    return platforms.stream()
      .filter(platform -> versionComparator.greaterThan(platform.getParsedVersion(), installed.getParsedVersion()))
      .count() > 0;
  }
}
