package cc.arduino.autocomplete;

import java.util.List;

import org.fife.ui.autocomplete.Completion;

public interface CompletionProvider {
  
  List<Completion> getSuggestions(CompletionContext context);
  
}