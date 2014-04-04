package processing.app.packages;

import java.io.File;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Collection;
import java.util.Collections;

import processing.app.helpers.FileUtils;

@SuppressWarnings("serial")
public class LibraryList {
  protected ArrayList<LibraryList> subs;
  protected ArrayList<Library> libs;
  protected String name;

  public LibraryList(String name) {
    super();
    this.name = name;
    this.subs = new ArrayList<LibraryList>();
    this.libs = new ArrayList<Library>();
  }

  public Library getByName(String name) {
    for (Library l : libs)
      if (l.getName().equals(name))
        return l;
    return null;
  }

  public void addOrReplace(Library lib) {
    Library l = getByName(lib.getName());
    if (l != null)
      libs.remove(l);
    libs.add(lib);
  }

  public void addOrReplaceAll(Collection<? extends Library> c) {
    for (Library l : c)
      addOrReplace(l);
  }

  public void addSub(LibraryList sub) {
    subs.add(sub);
  }

  public List<LibraryList> getSubs() {
    return subs;
  }

  public List<Library> getLibs() {
    return libs;
  }

  public List<Library> getAll() {
    ArrayList<Library> list = new ArrayList<Library>();

    for (LibraryList sub : subs)
      list.addAll(sub.getAll());

    list.addAll(libs);

    return list;
  }

  public void sort() {
    Collections.sort(libs, Library.CASE_INSENSITIVE_ORDER);
    Collections.sort(subs, LibraryList.CASE_INSENSITIVE_ORDER);
  }

  public Library search(String name, String arch) {
    for (Library lib : libs) {
      if (!lib.getName().equals(name))
        continue;
      if (!lib.supportsArchitecture(arch))
        continue;
      return lib;
    }
    for (LibraryList sub : subs) {
      Library lib = sub.search(name, arch);
      if (lib != null)
        return lib;
    }
    return null;
  }

  public static final Comparator<LibraryList> CASE_INSENSITIVE_ORDER = new Comparator<LibraryList>() {
    @Override
    public int compare(LibraryList o1, LibraryList o2) {
      return o1.getName().compareToIgnoreCase(o2.getName());
    }
  };

  public String getName() {
    return name;
  }

  public boolean isEmpty() {
    return libs.isEmpty() && subs.isEmpty();
  }
}
