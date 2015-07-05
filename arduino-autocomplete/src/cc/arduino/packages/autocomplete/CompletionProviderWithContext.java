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

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.logging.Logger;

import javax.swing.text.JTextComponent;

import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.DefaultCompletionProvider;
import org.fife.ui.autocomplete.FunctionCompletion;
import org.fife.ui.autocomplete.Util;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;

import processing.app.helpers.Predicate;
import br.com.criativasoft.cpluslibparser.LibraryIndex;
import br.com.criativasoft.cpluslibparser.metadata.TAttribute;
import br.com.criativasoft.cpluslibparser.metadata.TClass;
import br.com.criativasoft.cpluslibparser.metadata.TClass.TClassType;
import br.com.criativasoft.cpluslibparser.metadata.TElement;
import br.com.criativasoft.cpluslibparser.metadata.TElementLocation;
import br.com.criativasoft.cpluslibparser.metadata.TFunction;
import br.com.criativasoft.cpluslibparser.metadata.TLibrary;

/**
 * Autocomplete logic implementation for instance functions, static functions and local variables.
 * It determines the options that will be presented in accordance with the current context.
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class CompletionProviderWithContext extends DefaultCompletionProvider{
  
  private final static Logger LOG = Logger.getLogger(CompletionProviderWithContext.class.getName()); 
  
  private static final String DOT = ".";
  private static final String POINTER = "->";
  private static final String STATIC = "::";
  private TLibrary sketchLibrary; // classes, variables, functions of sketch
  
  private List<Completion> sketchCompletions = new ArrayList<Completion>(); // variables and functions of sketch
  
  public CompletionProviderWithContext() {
    super();
  }
  
  public void setSketchLibrary(TLibrary sketchLibrary) {
    this.sketchLibrary = sketchLibrary;
  }

  @Override
  public List<Completion> getCompletionsImpl(JTextComponent comp) {
    
    RSyntaxTextArea textarea = (RSyntaxTextArea) comp;

    String entredText = getAlreadyEnteredText(comp);

    List<Completion> contextCompletions = null;
    
    LOG.finest("entredText = "+ entredText);

    // Functions/Attrs of Classes
    if (entredText != null && entredText.length() > 0) {

      String separator = null;

      if (entredText.contains(DOT))    separator = DOT;
      if (entredText.contains(POINTER))separator = POINTER;
      if (entredText.contains(STATIC)) separator = STATIC;

      if (separator != null) {
        String var = entredText.substring(0, entredText.lastIndexOf(separator));
        String startMethod = entredText.substring(entredText.lastIndexOf(separator) + separator.length());
        contextCompletions = getCompletionsForClass(var, separator, startMethod, textarea);
      }

    }

    // Only show functions/attrs of class.
    if (contextCompletions != null) return contextCompletions;

    List<Completion> list = new LinkedList<Completion>();

    TFunction functionScope = getCurrentFunctionScope(textarea);

    if (functionScope != null && sketchCompletions != null  && !sketchCompletions.isEmpty()) {

      // Variables and functions
      list.addAll(sketchCompletions);

      // Local variables of functions.
      list.addAll(getVariablesInCurrentScope(textarea));

      // Need to order before searching
      if(list.size() != sketchCompletions.size()){
        Collections.sort(list, comparator);
      }

      List<Completion> filterCompletions = filterCompletions(entredText, list);
      
      if (filterCompletions != null) list = filterCompletions;

    }

    List<Completion> completions = super.getCompletionsImpl(comp);

    // Outside of function (only show classes)
    if (functionScope == null) {
      for (Completion completion : completions) {
        if (!(completion instanceof FunctionCompletion)) {
          list.add(completion);
        }
      }
    } else {
      list.addAll(completions);
    }

    return list;
    
  }
  
  public List<Completion> getVariablesInCurrentScope(RSyntaxTextArea textarea){
    
    int caretPos = textarea.getCaretPosition();
    TFunction functionScope = getCurrentFunctionScope(textarea);
    List<Completion> completions = new ArrayList<Completion>();
    
    if(functionScope != null){
      
      Set<TAttribute> localVariables = functionScope.getLocalVariables();
      
      if(localVariables != null){
        for (TAttribute var : localVariables) {
          if(var.getLocation().getStartOffset() <= caretPos){ // try to filter variables not declared at cursor position
                                                              // TODO: this may not work if many rows were changed after the last parser
            completions.add(new TElementCompletion(this, var));
          }
        }
      }    
      
    }
    

    return completions;
    
  }
  
  public List<Completion> getCompletionsForClass(String context, String token, String startMethod, RSyntaxTextArea textarea){
    
    List<Completion> list = new LinkedList<Completion>();
    
    boolean isInstance = (token == POINTER || Character.isLowerCase(context.charAt(0)));
    boolean isStatic = (token == STATIC && Character.isUpperCase(context.charAt(0)));
    
    TClass tClass = null;
    
    if(!isStatic){
      // Find the correct type based on global/local variables
      Set<TAttribute> variables = new HashSet<TAttribute>();
      variables.addAll(sketchLibrary.getGlobalVariables());
      
      TFunction functionScope = getCurrentFunctionScope(textarea);
      
      if(functionScope != null){
        variables.addAll(functionScope.getLocalVariables());
      }
      
      for (TAttribute attribute : variables) {
        if(attribute.name().equals(context)){
          tClass = LibraryIndex.getClass(attribute.getType()); 
          isInstance = true;
          break;
        }
      } 
    }
    
    if(tClass == null){
      tClass = LibraryIndex.getClass(context); // if isInstance, ignore case !!
    }
    
    if(tClass == null){
    	
    	TLibrary library = LibraryIndex.getLibrary(context);
    	if(library != null){
    		TElement variable = library.findMember(context); 
    		if(variable instanceof TAttribute){
    			tClass = LibraryIndex.getClass(((TAttribute) variable).getType());
    			if(tClass != null) isInstance = true;
    		}
    		
    	}
    	
    }
      
    
    if(tClass != null){
      
      Collection<TFunction> functions = tClass.getFunctions(true);
      Collection<TAttribute> attributes = tClass.getAttributes();
      
      // if the user had entered part of the function/attr name
      if(startMethod != null && startMethod.length() > 0){
        int matchMode = (startMethod.length() > 2 ? TElementFilter.MATCH_CONTAINS : TElementFilter.MATCH_START);
        functions = Predicate.filter(functions, new TFunctionFilter(startMethod, matchMode));
        attributes = Predicate.filter(attributes, new TAttributeFilter(startMethod, matchMode));
      }
      
      String startTemplate = context + token;
      
      for (TFunction tFunction : functions) {
        
        if(!tFunction.isPublic() || tFunction.isConstructor()) continue;
        
        boolean add = false;
        
        // Instance
        if(isInstance && !tFunction.isStatic()){
          add = true;
        }
        
        // Static
        if(!isInstance && tFunction.isStatic()){
          add = true;
        }   
        
        // Extern (show static and instance)
        if(tClass.getType() == TClassType.EXTERN){
          add = true;
        }   
        
        if(add){
          list.add(new TFunctionCompletion(this, tFunction, startTemplate)); 
        }

      }
      
      for (TAttribute attr : attributes) {
        
        // Instance
        if(isInstance && !attr.isStatic()){
          list.add(new TElementCompletion(this, attr , startTemplate));        
        }
        
        // Static
        if(!isInstance && attr.isStatic() || tClass.getType() == TClassType.EXTERN){
          list.add(new TElementCompletion(this, attr , startTemplate)); 
        }       

      }
      
    }
    
    return list;
  }
  
  public void setSketchCompletions(List<Completion> sketchCompletions) {
    this.sketchCompletions = sketchCompletions;
    Collections.sort(sketchCompletions, comparator);
  }
  
  public List<Completion> getSketchCompletions() {
    return sketchCompletions;
  }
  
  
  /**
   * Find function at the caret position
   * @param textarea
   * @return
   */
  public TFunction getCurrentFunctionScope(RSyntaxTextArea textarea){
    
    int caretPos = textarea.getCaretPosition();
    
    Set<TFunction> globalFunctions = sketchLibrary.getGlobalFunctions();
    
    for (TFunction tFunction : globalFunctions) {
      TElementLocation location = tFunction.getLocation();
      if(location != null && location.containsOffset(caretPos)){
        
        LOG.finest("function = " + tFunction + ", loc: " + location.toString());
        
        return tFunction;
      }
    }

    return null;
  }
  
  /**
   * Filter through the options that can be applied to the text that the user entered
   * @param alreadyEnteredText
   * @param completions - Must be ordered before searching
   * @return
   */
  protected List<Completion> filterCompletions(String alreadyEnteredText, List<Completion> completions) {
    
    if(alreadyEnteredText == null || alreadyEnteredText.isEmpty()) return new ArrayList<Completion>(completions);
    List<Completion> retVal = new ArrayList<Completion>();
    
    if (alreadyEnteredText!=null) {

      int index = Collections.binarySearch(completions, alreadyEnteredText, comparator);
      if (index<0) { // No exact match
        index = -index - 1;
      }
      else {
        // If there are several overloads for the function being
        // completed, Collections.binarySearch() will return the index
        // of one of those overloads, but we must return all of them,
        // so search backward until we find the first one.
        int pos = index - 1;
        while (pos>0 &&
            comparator.compare(completions.get(pos), alreadyEnteredText)==0) {
          retVal.add(completions.get(pos));
          pos--;
        }
      }

      while (index<completions.size()) {
        Completion c = completions.get(index);
        if (Util.startsWithIgnoreCase(c.getInputText(), alreadyEnteredText)) {
          retVal.add(c);
          index++;
        }
        else {
          break;
        }
      }

    }
    
    return retVal;

  }
  
  @Override
  protected boolean isValidChar(char ch) {
    return super.isValidChar(ch) || '.' == ch || '>' == ch  || '-' == ch  || '<' == ch || '#' == ch || ':' == ch /**|| getParameterListStart() == ch */;
  }

}
