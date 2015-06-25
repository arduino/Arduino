package processing.app.packages;

public class LibrarySelection {
  private LibraryList list;
  private int index;
  public LibrarySelection(LibraryList list, int index) {
    this.list = list;
    this.index = index;
  }
  public UserLibrary get() {
    return list.get(index);
  }
  public LibraryList getList() {
    return list;
  }
  public int getIndex() {
    return index;
  }
  public boolean equals(Object otherObj) {
    if (!(otherObj instanceof LibrarySelection)) {
      return false;
    }
    LibrarySelection other = (LibrarySelection) otherObj;
    return this.get().equals(other.get());
  }
}
