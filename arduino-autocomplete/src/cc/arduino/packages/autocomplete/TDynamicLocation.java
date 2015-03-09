package cc.arduino.packages.autocomplete;

import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.Element;
import javax.swing.text.Position;

import br.com.criativasoft.cpluslibparser.metadata.TElement;
import br.com.criativasoft.cpluslibparser.metadata.TElementLocation;

/**
 * Element to track positions of methods and variables even after document changes.<br/>
 * This feature is implemented by the swing api ({@link Position}) 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class TDynamicLocation extends TElementLocation {
  
  private Document document;
  private Position startOffs;
  private Position endOffs;
  
  private int lastEndOffs = -1;
  private int cachedEndLine;
  private TElementLocation reference;
  
  public TDynamicLocation(Document document, TElement element) {
    this(document, element.getLocation());
    element.setLocation(this);
  }
  
  public TDynamicLocation(Document document, TElementLocation reference) {
    super();
    this.document = document;
    try {
      this.startOffs = document.createPosition(reference.getStartOffset());
      this.endOffs = document.createPosition(reference.getEndOffset());
      this.reference = reference;
    } catch (BadLocationException e) {
      e.printStackTrace();
    }
  }
  
  
  
  /**
   * Returns whether the specified offset is "inside".  This method
   * returns <code>true</code> if the offset is greater than the element start
   * offset, and no further than the last offset of the last element line.
   *
   * @param offs The offset to check.
   * @return Whether the offset is "inside" the element.
   * @see #containsLine(int)
   */
  public boolean containsOffset(int offs) {
    boolean contained = false;
    if (offs>getStartOffset()) {
      // Use Elements to avoid BadLocationExceptions
      Element root = document.getDefaultRootElement();
      int line = root.getElementIndex(offs);
      contained = line<=getEndLine();
    }
    return contained;
  }
  
  /**
   * Returns the end line of this Element.
   *
   * The value returned by this method will automatically update as the
   * text area's contents are modified, to track the ending line of the
   * code block.
   *
   * @return The end line of this code block.
   * @see #getEndOffset()
   */
  public int getEndLine() {
    int endOffs = getEndOffset();
    if (lastEndOffs==endOffs) {
      return cachedEndLine;
    }
    lastEndOffs = endOffs;
    Element root = document.getDefaultRootElement();
    return cachedEndLine = root.getElementIndex(endOffs);
  }
  
  
  /**
   * Returns the starting offset of this Element.
   *
   * The value returned by this method will automatically update as the
   * text area's contents are modified, to track the starting offset of the
   * code block.
   *
   * @return The start offset of this fold.
   * @see #getEndOffset()
   */
  public int getStartOffset() {
    return startOffs.getOffset();
  }
  
  /**
   * Returns the end offset of this Element.
   *
   * The value returned by this method will automatically update as the
   * text area's contents are modified, to track the ending offset of the
   * code block.
   *
   * @return The end offset of this code block.
   * @see #getEndLine()
   */
  public int getEndOffset() {
    return endOffs!=null ? endOffs.getOffset() : Integer.MAX_VALUE;
  }
  
  
  @Override
  public String toString() {
    return "["+getStartOffset()+", "+getEndOffset()+"], orig: " + reference.toString();
  }

}
