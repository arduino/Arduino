package cc.arduino.autocomplete;

import org.fife.ui.autocomplete.DefaultCompletionProvider;

/**
 * Base completion provider for C/C++.
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * @date 28/04/2017
 */
public class BaseCCompletionProvider extends DefaultCompletionProvider {
 
  @Override
  protected boolean isValidChar(char ch) {
    return super.isValidChar(ch) || '.' == ch || '>' == ch  || '-' == ch  || '<' == ch || '#' == ch || ':' == ch /**|| getParameterListStart() == ch */;
  }

}
