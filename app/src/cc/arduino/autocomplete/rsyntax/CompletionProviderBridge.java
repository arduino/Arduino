package cc.arduino.autocomplete.rsyntax;

import java.util.List;

import javax.swing.text.JTextComponent;

import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.DefaultCompletionProvider;

import cc.arduino.autocomplete.CompletionContext;
import cc.arduino.autocomplete.CompletionProvider;

public class CompletionProviderBridge extends DefaultCompletionProvider{
  
  private CompletionProvider provider;
  
  private CompletionContext context;
  
  public CompletionProviderBridge(CompletionContext context, CompletionProvider provider) {
    this.provider = provider;
    this.context = context;
  }


  @Override
  public List<Completion> getCompletionsImpl(JTextComponent comp) {
    return provider.getSuggestions(context);
    
  }
  
  @Override
  protected boolean isValidChar(char ch) {
    return super.isValidChar(ch) || '.' == ch || '>' == ch  || '-' == ch  || '<' == ch || '#' == ch || ':' == ch /**|| getParameterListStart() == ch */;
  }

}
