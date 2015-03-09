package cc.arduino.packages.autocomplete;

import java.util.List;

import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.CompletionProvider;
import org.fife.ui.autocomplete.ParameterizedCompletion;
import org.fife.ui.autocomplete.TemplateCompletion;

/**
 * Base class for templates that provide assistance to autocomplete parameters
 * @see ParameterizedCompletion
 * @see ParameterChoicesProvider
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * @date 09/12/2014
 */
public abstract class TemplateChoicesCompletion extends TemplateCompletion {

  public TemplateChoicesCompletion(CompletionProvider provider,
                                   String inputText, String definitionString,
                                   String template) {
    super(provider, inputText, definitionString, template);
  }

  public TemplateChoicesCompletion(CompletionProvider provider,
                                   String inputText, String definitionString,
                                   String template, String shortDescription,
                                   String summary) {
    super(provider, inputText, definitionString, template, shortDescription,summary);
  }
  
  
  public abstract List<Completion> getChoices(Parameter param);
  

}
