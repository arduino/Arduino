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

import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import org.fife.ui.autocomplete.CompletionProvider;
import org.fife.ui.autocomplete.FunctionCompletion;

import br.com.criativasoft.cpluslibparser.metadata.TFunction;
import br.com.criativasoft.cpluslibparser.metadata.TParam;

public class TFunctionCompletion extends FunctionCompletion {

  private TFunction function;
  private String alreadyEntered; 
  
  public TFunctionCompletion(CompletionProvider provider, TFunction function) {
    this(provider, function, null);
  }

  public TFunctionCompletion(CompletionProvider provider, TFunction function, String alreadyEntered) {
    super(provider, function.name(), function.getReturnType());
    this.function = function;
    this.alreadyEntered = alreadyEntered;
    
    Set<TParam> params = function.getParams();
    List<Parameter> list = new LinkedList<Parameter>();

    for (TParam param : params) {
      list.add(new TFunctionParam(param, function));
    }
    
    setParams(list);
  }
  
  public TFunction getFunction() {
    return function;
  }
  
  @Override
  public String getShortDescription() {
    return function.toDeclarationString();
  }
  
  @Override
  public String getInputText() {
    return function.name();
  }

  
  @Override
  public String getReplacementText() {
    
    if(alreadyEntered == null || alreadyEntered.length() == 0) return super.getReplacementText();
    
    return alreadyEntered  + super.getReplacementText();
  }
  
  @Override
  public int getRelevance() {
    return 3;
  }
  
  @Override
  public String toString() {
    return function.name();
  }
  
  public static class TFunctionParam extends Parameter{

    private TParam param;
    private TFunction function;

    public TFunctionParam(TParam attribute, TFunction function) {
      super(attribute.getType(), attribute.name());
      this.param = attribute;
      this.function = function;
    }
    
    public TFunction getFunction() {
      return function;
    }
    
    public TParam getAttributeParam() {
      return param;
    }
    
  }
  
}
