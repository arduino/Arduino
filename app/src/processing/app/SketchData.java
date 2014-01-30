package processing.app;

import static processing.app.I18n._;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SketchData {

  /**
   * Name of sketch, which is the name of main file (without .pde or .java
   * extension)
   */
  private String name;
  
  private List<SketchCodeDoc> codeDocs = new ArrayList<SketchCodeDoc>();

  private static final Comparator<SketchCodeDoc> CODE_DOCS_COMPARATOR = new Comparator<SketchCodeDoc>() {
    @Override
    public int compare(SketchCodeDoc cd1, SketchCodeDoc cd2) {
      return cd1.getCode().getFileName().compareTo(cd2.getCode().getFileName());
    }
  };


  public int getCodeCount() {
    return codeDocs.size();
  }

  public SketchCodeDoc[] getCodeDocs() {
    return codeDocs.toArray(new SketchCodeDoc[0]);
  }

  public void addCodeDoc(SketchCodeDoc sketchCodeDoc) {
    codeDocs.add(sketchCodeDoc);
  }

  public void moveCodeDocToFront(SketchCodeDoc codeDoc) {
    codeDocs.remove(codeDoc);
    codeDocs.add(0, codeDoc);
  }

  protected void replaceCode(SketchCode newCode) {
    for (SketchCodeDoc codeDoc : codeDocs) {
      if (codeDoc.getCode().getFileName().equals(newCode.getFileName())) {
        codeDoc.setCode(newCode);
        return;
      }
    }
  }

  protected void insertCode(SketchCode sketchCode) {
    addCodeDoc(new SketchCodeDoc(sketchCode, null));
  }

  protected void sortCode() {
    Collections.sort(codeDocs, CODE_DOCS_COMPARATOR);
  }

  public SketchCodeDoc getCodeDoc(int i) {
    return codeDocs.get(i);
  }

  public SketchCode getCode(int i) {
    return codeDocs.get(i).getCode();
  }

  protected void removeCode(SketchCode which) {
    for (SketchCodeDoc codeDoc : codeDocs) {
      if (codeDoc.getCode() == which) {
        codeDocs.remove(codeDoc);
        return;
      }
    }
    System.err.println(_("removeCode: internal error.. could not find code"));
  }

  public int indexOfCodeDoc(SketchCodeDoc codeDoc) {
    return codeDocs.indexOf(codeDoc);
  }

  public int indexOfCode(SketchCode who) {
    for (SketchCodeDoc codeDoc : codeDocs) {
      if (codeDoc.getCode() == who) {
        return codeDocs.indexOf(codeDoc);
      }
    }
    return -1;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void clearCodeDocs() {
    codeDocs.clear();
  }
}
