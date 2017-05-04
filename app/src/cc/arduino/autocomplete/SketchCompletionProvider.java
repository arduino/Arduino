package cc.arduino.autocomplete;

import org.fife.ui.autocomplete.CompletionProvider;
import org.fife.ui.autocomplete.LanguageAwareCompletionProvider;

import processing.app.Sketch;
import processing.app.syntax.SketchTextArea;

/**
 * CompletionProvider for Arduino/CPP Language. <br/>
 * Setup basic logic for completions using {@link LanguageAwareCompletionProvider}. <br/>
 * Filtering and decision will appear in the autocomplete dialog by implementations of: {@link CompletionProvider}.<br/>
 * 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * @date 28/04/2017
 */
public class SketchCompletionProvider extends LanguageAwareCompletionProvider {

  public SketchCompletionProvider(Sketch sketch, SketchTextArea textArea, CompletionProvider provider) {

    setDefaultCompletionProvider(provider);
    // provider.setParameterChoicesProvider(new ParameterChoicesProvider(this));
    // provider.setParameterizedCompletionParams('(', ", ", ')');

  }

}