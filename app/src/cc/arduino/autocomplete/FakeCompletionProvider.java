package cc.arduino.autocomplete;

import java.util.LinkedList;
import java.util.List;

import org.fife.ui.autocomplete.BasicCompletion;
import org.fife.ui.autocomplete.Completion;

public class FakeCompletionProvider implements CompletionProvider {
  

  @Override
  public List<Completion> getSuggestions(CompletionContext context) {
    List<Completion> list = new LinkedList<>();
    list.add(new BasicCompletion(context.getDelegate(), "Text: " + context.getAlreadyEnteredText()));
    list.add(new BasicCompletion(context.getDelegate(), "Line: " + context.getLineNumber()));

    return list;
  }
  

}
