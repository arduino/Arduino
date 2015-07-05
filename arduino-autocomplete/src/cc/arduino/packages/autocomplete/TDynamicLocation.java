/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * Copyright 2015 Arduino LLC
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */
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
