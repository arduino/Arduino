package cc.arduino.autocomplete;

import java.util.ArrayList;
import java.util.List;

import javax.swing.text.BadLocationException;
import javax.swing.text.JTextComponent;

import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.TemplateCompletion;

import com.fasterxml.jackson.databind.ObjectMapper;

import processing.app.Editor;
import processing.app.EditorTab;

public class ClangCompletionProvider extends BaseCCompletionProvider {

  private Editor editor;

  public ClangCompletionProvider(Editor e) {
    super();
    editor = e;
  }

  @Override
  public List<Completion> getCompletionByInputText(String inputText) {
    System.out.println("INPUTTEXT: " + inputText);
    return super.getCompletionByInputText(inputText);
  }

  @Override
  protected List<Completion> getCompletionsImpl(JTextComponent textarea) {

    // Retrieve current line and column
    EditorTab tab = editor.getCurrentTab();
    int line, col;
    try {
      int pos = tab.getTextArea().getCaretPosition();
      line = tab.getTextArea().getLineOfOffset(pos);
      col = pos - tab.getTextArea().getLineStartOffset(line);
      line++;
      col++;
    } catch (BadLocationException e1) {
      // Should never happen...
      e1.printStackTrace();
      return completions;
    }

    try {
      // Run codecompletion engine
      String out = editor.getSketchController()
          .codeComplete(tab.getSketchFile(), line, col);

      List<Completion> res = new ArrayList<>();
      res.add(new TemplateCompletion(this, "for", "interate over array",
          "for (int ${i} = 0; ${i} < ${array}.length; ${i}++) {\n  ${cursor}\n}"));

      // Parse engine output and build code completions
      ObjectMapper mapper = new ObjectMapper();
      ArduinoCompletionsList allCc;
      allCc = mapper.readValue(out, ArduinoCompletionsList.class);
      for (ArduinoCompletion cc : allCc) {
        if (cc.type.equals("macro")) {
          // for now skip macro
          continue;
        }
        String returnType;
        String typedText;
        String template = "";
        for (CompletionChunk chunk : cc.completion.chunks) {
          if (chunk.t != null) {
            template += "t";
          }
          if (chunk.res != null) {
            returnType = chunk.res;
          }
          if (chunk.typedtext != null) {
            typedText = chunk.typedtext;
          }
        }
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
    return completions;
  }
}
