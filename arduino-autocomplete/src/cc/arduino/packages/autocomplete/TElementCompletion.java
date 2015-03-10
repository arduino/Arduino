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
