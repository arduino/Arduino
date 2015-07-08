package cc.arduino.contributions.libraries.ui;

import cc.arduino.contributions.libraries.ContributedLibrary;
import cc.arduino.contributions.libraries.LibrariesIndexer;
import cc.arduino.contributions.libraries.filters.UpdatableLibraryPredicate;
import cc.arduino.contributions.ui.DropdownItem;

import java.util.function.Predicate;

import static processing.app.I18n._;

public class DropdownUpdatableLibrariesItem implements DropdownItem<ContributedLibrary> {

  private final LibrariesIndexer indexer;

  public DropdownUpdatableLibrariesItem(LibrariesIndexer indexer) {
    this.indexer = indexer;
  }

  @Override
  public Predicate<ContributedLibrary> getFilterPredicate() {
    return new UpdatableLibraryPredicate(indexer);
  }

  @Override
  public String toString() {
    return _("Updatable");
  }

  @Override
  public boolean equals(Object obj) {
    return obj instanceof DropdownUpdatableLibrariesItem;
  }

}
