package processing.app.syntax;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import javax.swing.text.BadLocationException;
import javax.swing.text.Element;

import org.fife.ui.rsyntaxtextarea.RSyntaxDocument;
import org.fife.ui.rsyntaxtextarea.RSyntaxUtilities;
import org.fife.ui.rsyntaxtextarea.parser.*;
import org.fife.ui.rtextarea.Gutter;
import org.fife.ui.rtextarea.GutterIconInfo;

import processing.app.Sketch;
import br.com.criativasoft.cpluslibparser.LibraryIndex;
import br.com.criativasoft.cpluslibparser.LibraryIndexListener;
import br.com.criativasoft.cpluslibparser.metadata.TError;
import br.com.criativasoft.cpluslibparser.metadata.TLibrary;
import cc.arduino.packages.autocomplete.CompletionType;
import cc.arduino.packages.autocomplete.CompletionsRenderer;
import cc.arduino.packages.autocomplete.SketchCodeScanner;
import cc.arduino.packages.autocomplete.SketchCompletionProvider;


/**
 * Shows the result of the errors found after running the parser ({@link LibraryIndex}, {@link SketchCodeScanner}).<br/>
 * Only well ugly syntax errors will be caught (because of the nature of the analysis to be made).
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 */
public class SyntaxErrorMarker extends AbstractParser implements LibraryIndexListener {
  
  private TLibrary sketchLibrary;
  private DefaultParseResult result;
  private SketchTextArea textarea;
  
  // TODO: this can be removed on fix: https://github.com/bobbylight/RSyntaxTextArea/issues/87
  private Gutter gutter;
  private List<GutterIconInfo> errorIcons = new ArrayList<GutterIconInfo>();
  
  public SyntaxErrorMarker(SketchTextArea textarea) {
    this.textarea = textarea;
    this.gutter = RSyntaxUtilities.getGutter(textarea);
    LibraryIndex.addListener(this);
    result = new DefaultParseResult(this);
  }
  
  @Override
  public ParseResult parse(RSyntaxDocument doc, String style) {
    
    Element root = doc.getDefaultRootElement();
    int lineCount = root.getElementCount();

    if(sketchLibrary != null){
      result.setParsedLines(0, lineCount-1);
    }

    return result;
  }
  

  @Override
  public void onLoadLibrary(TLibrary library) {
    if(library.name().startsWith(Sketch.SKETCH_LIB_PREFIX)){ // Sketch indexing finish
      sketchLibrary = library;
      collectErrors();
    }
  }


  @Override
  public void onUnloadLibrary(TLibrary library) {
    if(library.name().startsWith(Sketch.SKETCH_LIB_PREFIX)){ // Sketch indexing finish
      removeAll();
    }
  }

  @Override
  public void onReloadLibrary(TLibrary library) {
    if(library.name().startsWith(SketchCompletionProvider.SKETCH_LIB_PREFIX)){ // Sketch indexing finish
      sketchLibrary = library;
      collectErrors();
    }
  }
  
  private void collectErrors(){
    
    if(sketchLibrary != null){
      
      Set<TError> errors = sketchLibrary.getErrors();
      
      result.clearNotices();
      
      for (GutterIconInfo gutterIconInfo : errorIcons) {
        gutter.removeTrackingIcon(gutterIconInfo);
      }
      
      if(!errors.isEmpty()){
       for (TError error : errors) {
         addError(error);
       }
      }
      textarea.forceReparsing(this);
    }
    
  }
  
  public void addError(TError error){
    ErrorParserNotice notice = new ErrorParserNotice(this, error);
    result.addNotice(notice);
    // TODO: This(gutter) can be removed on fix: RSyntaxTextArea/issues/87
    if(gutter != null){
      try {
       GutterIconInfo errorIcon = gutter.addOffsetTrackingIcon(error.getStartOffset(), CompletionsRenderer.getIcon(CompletionType.ERROR), error.name());
       errorIcons.add(errorIcon);
     } catch (BadLocationException e) {
       e.printStackTrace();
     }
    }
  }
  
  public static class ErrorParserNotice extends DefaultParserNotice{

    private TError error;

    public ErrorParserNotice(Parser parser, TError error) {
      super(parser, error.getName(), -1, error.getStartOffset() , error.getLength());
      this.error = error;
      setColor(Color.RED);
      setShowInEditor(true);
    }
    
    public TError getError() {
      return error;
    }
    
    @Override
    public String getToolTipText() {
      return error.getName();
    }
    
  }

  public void removeAll() {
    result.clearNotices();
    textarea.forceReparsing(this);
    for (GutterIconInfo gutterIconInfo : errorIcons) {
      gutter.removeTrackingIcon(gutterIconInfo);
    }
  }

}
