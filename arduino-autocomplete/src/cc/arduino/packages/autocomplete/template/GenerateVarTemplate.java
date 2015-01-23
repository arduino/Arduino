package cc.arduino.packages.autocomplete.template;

import org.fife.ui.autocomplete.CompletionProvider;
import org.fife.ui.autocomplete.TemplateCompletion;

import cc.arduino.packages.autocomplete.SketchCompletionProvider;

/**
 * Used in {@link SketchCompletionProvider#generateNewVariableFor(String, int)}
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br) 
 * @date 11/12/2014
 */
public class GenerateVarTemplate extends TemplateCompletion {

  private String type, name;
  
  public GenerateVarTemplate(CompletionProvider provider,String type, String name) {
    super(provider, name, name, type + " ${" + name + "} = ");
    this.type = type;
    this.name = name;
  }
  
  public String getName() {
    return name;
  }
  
  public String getType() {
    return type;
  }
  

}
