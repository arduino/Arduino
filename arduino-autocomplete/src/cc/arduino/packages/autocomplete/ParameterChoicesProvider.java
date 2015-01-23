package cc.arduino.packages.autocomplete;

import java.util.LinkedList;
import java.util.List;

import javax.swing.text.JTextComponent;

import org.fife.ui.autocomplete.BasicCompletion;
import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.CompletionProvider;
import org.fife.ui.autocomplete.CompletionProviderBase;
import org.fife.ui.autocomplete.ParameterizedCompletion;
import org.fife.ui.autocomplete.ParameterizedCompletion.Parameter;

import cc.arduino.packages.autocomplete.TFunctionCompletion.TFunctionParam;
import br.com.criativasoft.cpluslibparser.metadata.TFunction;
import br.com.criativasoft.cpluslibparser.metadata.TParam;

/**
 * This is used when a user code-completes a parameterized completion, such as a function or method. <br/>
 * For any parameter to the function/method, this object can return possible completions.
 * @see {@link CompletionProviderBase#setParameterChoicesProvider(org.fife.ui.autocomplete.ParameterChoicesProvider)}
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br) 
 * @date 09/12/2014
 */
public class ParameterChoicesProvider implements org.fife.ui.autocomplete.ParameterChoicesProvider {

  private SketchCompletionProvider provider;

  public ParameterChoicesProvider(SketchCompletionProvider provider) {
    super();
    this.provider = provider;
  }

  @Override
  public List<Completion> getParameterChoices(JTextComponent tc, ParameterizedCompletion pc, Parameter param) {

    if (param instanceof TFunctionParam) {

      TFunctionParam functionParam = (TFunctionParam) param;
      TFunction function = functionParam.getFunction();
      TParam tParam = functionParam.getAttributeParam();

      // FIXME: REMOVE AFTER IMPLEMENT PARSER FROM SOURCE
      if (function.name().equals("begin") && tParam.name().equals("baud")) {
        // @param baud (Values: 300, 600, 1200 ...)
        tParam.setAllowedValues("300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, 115200");
      }
      
      if (function.name().equals("pinMode") && tParam.name().equals("mode")) {
        tParam.setAllowedValues("OUTPUT, INPUT, INPUT_PULLUP");
      }
      
      if (function.name().equals("digitalWrite") && tParam.name().equals("value")) {
        tParam.setAllowedValues("HIGH, LOW");
      }
      
      // and: remove --------------

      if (tParam.getAllowedValues() != null) {
        return createFromAllowedValues(tParam);
      }

    }
    
    if(pc instanceof TemplateChoicesCompletion){
      TemplateChoicesCompletion choicesCompletion = (TemplateChoicesCompletion) pc;
      return choicesCompletion.getChoices(param);
    }
    
    return null;
  }

  private List<Completion> createFromAllowedValues(TParam param) {

    List<Completion> completions = new LinkedList<Completion>();

    String allowedValues = param.getAllowedValues();

    String[] strings = allowedValues.split(",");

    for (String key : strings) {
      completions.add(new ParamCompletion(provider, key.trim(), param.getType()));
    }

    return completions;
  }

  
  // it is only necessary to properly sort integer values.
  private static class ParamCompletion extends BasicCompletion {

    private Long value;

    public ParamCompletion(CompletionProvider provider, String replacementText,
                           String type) {
      super(provider, replacementText);

      if (isNumber(type)) {
        try {
          value = Long.parseLong(replacementText);
        } catch (Exception e) {}
      }

    }

    private boolean isNumber(String type) {
      if (type.contains("int") || type.contains("long")) {
        return true;
      }

      return false;
    }

    public Long getValue() {
      return value;
    }

    @Override
    public int compareTo(Completion c2) {
      
      if(value != null){
        return value.compareTo(((ParamCompletion)c2).getValue());
      }else{
        return super.compareTo(c2);
      }
      
    }

  }

}
