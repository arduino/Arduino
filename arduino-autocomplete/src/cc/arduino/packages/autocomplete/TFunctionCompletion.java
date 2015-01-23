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
