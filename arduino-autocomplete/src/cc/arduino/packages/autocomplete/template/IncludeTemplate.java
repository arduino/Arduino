package cc.arduino.packages.autocomplete.template;

import java.util.LinkedList;
import java.util.List;

import org.fife.ui.autocomplete.BasicCompletion;
import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.CompletionProvider;

import processing.app.BaseNoGui;
import processing.app.packages.Library;
import processing.app.packages.LibraryList;
import cc.arduino.packages.autocomplete.TemplateChoicesCompletion;

public class IncludeTemplate extends TemplateChoicesCompletion {

  public IncludeTemplate(CompletionProvider provider) {
    super(provider, "#include", "#include <>", "#include <${include}.h>");
  }

  @Override
  public List<Completion> getChoices(Parameter param) {
      List<Completion> completions = new LinkedList<Completion>();
      
      LibraryList libraries = BaseNoGui.getLibraries();
      for (Library library : libraries) {
        completions.add(new BasicCompletion(getProvider(), library.getName()));
      }
      
      return completions;
  }

}
