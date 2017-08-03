package cc.arduino.autocomplete;

import java.util.ArrayList;
import java.util.List;

import javax.swing.text.BadLocationException;
import javax.swing.text.JTextComponent;

import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.DefaultCompletionProvider;
import org.fife.ui.autocomplete.FunctionCompletion;
import org.fife.ui.autocomplete.ParameterizedCompletion.Parameter;
import org.fife.ui.autocomplete.TemplateCompletion;

import com.fasterxml.jackson.databind.ObjectMapper;

import processing.app.Editor;
import processing.app.EditorTab;

public class ClangCompletionProvider extends DefaultCompletionProvider {

  private Editor editor;

  public ClangCompletionProvider(Editor e) {
    super();
    editor = e;
    setParameterizedCompletionParams('(', ", ", ')');
  }

  @Override
  public List<Completion> getCompletionByInputText(String inputText) {
    System.out.println("INPUTTEXT: " + inputText);
    return super.getCompletionByInputText(inputText);
  }

  @Override
  protected List<Completion> getCompletionsImpl(JTextComponent textarea) {

    List<Completion> res = new ArrayList<>();

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
      return res;
    }

    try {
      // Run codecompletion engine
      String out = editor.getSketchController()
          .codeComplete(tab.getSketchFile(), line, col);

      // Parse engine output and build code completions
      ObjectMapper mapper = new ObjectMapper();
      ArduinoCompletionsList allCc;
      allCc = mapper.readValue(out, ArduinoCompletionsList.class);
      for (ArduinoCompletion cc : allCc) {
        if (cc.type.equals("Macro")) {
          // for now skip macro
          continue;
        }

        if (cc.type.equals("Function")) {
          List<Parameter> params = new ArrayList<>();
          int i=0;
          for (CompletionChunk chunk : cc.completion.chunks) {
            if (chunk.placeholder != null) {
              ArduinoParameter p = cc.parameters.get(i);
              params.add(new Parameter(p.type, p.name));
              i++;
            }
          }

          FunctionCompletion compl = new FunctionCompletion(this,
              cc.getCompletion().getTypedText(),
              cc.getCompletion().getResultType());
          compl.setParams(params);
          res.add(compl);
          continue;
        }

        String returnType = "";
        String typedText = null;
        String template = "";
        for (CompletionChunk chunk : cc.completion.chunks) {
          if (chunk.t != null) {
            template += chunk.t;
          }
          if (chunk.res != null) {
            returnType = " - " + chunk.res;
          }
          if (chunk.typedtext != null) {
            template += chunk.typedtext;
            typedText = chunk.typedtext;
          }
          if (chunk.placeholder != null) {
            String[] spl = chunk.placeholder.split(" ");
            template += "${" + spl[spl.length - 1] + "}";
          }
          if (chunk.info != null) {
            System.out.println("INFO: "+chunk.info);
          }
        }
        template += "${cursor}";
        System.out.println("TEMPLATE: " + template);
        res.add(new TemplateCompletion(this, typedText, typedText + returnType,
            template));
      }
      return res;
    } catch (Exception e) {
      e.printStackTrace();
      return res;
    }
  }
}
