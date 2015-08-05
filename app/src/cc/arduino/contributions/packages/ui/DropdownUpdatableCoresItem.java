package cc.arduino.contributions.packages.ui;

import cc.arduino.contributions.packages.ContributedPlatform;
import cc.arduino.contributions.packages.ContributionsIndexer;
import cc.arduino.contributions.packages.filters.UpdatablePlatformPredicate;
import cc.arduino.contributions.ui.DropdownItem;

import java.util.function.Predicate;

import static processing.app.I18n.tr;

public class DropdownUpdatableCoresItem implements DropdownItem<ContributedPlatform> {

  private final ContributionsIndexer indexer;

  public DropdownUpdatableCoresItem(ContributionsIndexer indexer) {
    this.indexer = indexer;
  }

  @Override
  public Predicate<ContributedPlatform> getFilterPredicate() {
    return new UpdatablePlatformPredicate(indexer);
  }

  @Override
  public String toString() {
    return tr("Updatable");
  }

  @Override
  public boolean equals(Object obj) {
    return obj instanceof DropdownUpdatableCoresItem;
  }
}
