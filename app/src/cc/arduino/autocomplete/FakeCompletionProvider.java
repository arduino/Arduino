package cc.arduino.autocomplete;

import java.util.LinkedList;
import java.util.List;

import javax.swing.text.JTextComponent;

import org.fife.ui.autocomplete.BasicCompletion;
import org.fife.ui.autocomplete.Completion;

import processing.app.syntax.SketchTextArea;

public class FakeCompletionProvider extends BaseCCompletionProvider {
  
  @Override
  protected List<Completion> getCompletionsImpl(JTextComponent comp) {
    List<Completion> list = new LinkedList<>();
    
    SketchTextArea area = (SketchTextArea) comp;
    
    list.add(new BasicCompletion(this, "Text: " + getAlreadyEnteredText(comp)));
    list.add(new BasicCompletion(this, "Line: " + area.getCaretLineNumber()));

    return list;
  }


}
