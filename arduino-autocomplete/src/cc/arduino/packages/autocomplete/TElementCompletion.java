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

import org.fife.ui.autocomplete.AbstractCompletion;
import org.fife.ui.autocomplete.CompletionProvider;

import br.com.criativasoft.cpluslibparser.metadata.*;

public class TElementCompletion extends AbstractCompletion {

  private TElement element;
  private String alreadyEntered; 

  public TElementCompletion(CompletionProvider provider, TElement element) {
    super(provider);
    this.element = element;
  }
  
  public TElementCompletion(CompletionProvider provider, TElement element, String alreadyEntered) {
    super(provider);
    this.element = element;
    this.alreadyEntered = alreadyEntered;
  }

  @Override
  public String getReplacementText() {
    
    if(alreadyEntered == null || alreadyEntered.length() == 0) return element.name();
    
    return alreadyEntered  + element.name();
  }

  @Override
  public String getSummary() {
    return element.toString();
  }
  
  @Override
  public String getInputText() {
    return element.name();
  }
  
  public TElement getElement() {
    return element;
  }
  
  public String getShortDescription(){
    return element.name();
  }

  
  public CompletionType getType(){
    
    if(element instanceof TLibrary){
      return CompletionType.LIBRARY;
    }
    
    if(element instanceof TClass){
      return CompletionType.CLASS;
    }
    
    if(element instanceof TFunction){
      return CompletionType.FUNCTION;
    }
    
    if(element instanceof TAttribute){
      TAttribute attribute = (TAttribute) element;
      if(attribute.isLocal()) return CompletionType.LOCAL_VAR;
      if(attribute.isEnum()) return CompletionType.ENUM;
      if(attribute.isStatic()) return CompletionType.STATIC_VAR;
      return CompletionType.VARIABLE;
    }
    
    return CompletionType.VARIABLE;
    
  }
  
  
  @Override
  public int getRelevance() {
    if(element instanceof TLibrary){
      return 1;
    }
    
    if(element instanceof TClass){
      return 2;
    }
    
    if(element instanceof TFunction){
      return 3;
    }
    
    if(element instanceof TAttribute){
      TAttribute attribute = (TAttribute) element;
      if(attribute.isLocal()) return 7;
      if(attribute.isEnum()) return 5;
      if(attribute.isStatic()) return 4;
      return 6;
    }
    
    return 0;
  }

  @Override
  public String toString() {
    return element.name();
  }
  
}
