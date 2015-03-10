package processing.app.syntax;

import static processing.app.I18n._;

import java.awt.AWTKeyStroke;
import java.awt.Dimension;
import java.awt.KeyboardFocusManager;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.logging.Logger;

import javax.swing.JPopupMenu;
import javax.swing.KeyStroke;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.Segment;
import javax.swing.undo.UndoManager;

import org.fife.ui.autocomplete.*;
import org.fife.ui.rsyntaxtextarea.*;
import org.fife.ui.rsyntaxtextarea.Token;
import org.fife.ui.rsyntaxtextarea.focusabletip.FocusableTip;
import org.fife.ui.rtextarea.RUndoManager;

import processing.app.Base;
import processing.app.EditorLineStatus;
import processing.app.EditorListener;
import processing.app.I18n;
import processing.app.helpers.DocumentationUtils;
import processing.app.packages.Library;
import br.com.criativasoft.cpluslibparser.metadata.TAttribute;
import br.com.criativasoft.cpluslibparser.metadata.TFunction;
import cc.arduino.packages.autocomplete.CompletionsRenderer;
import cc.arduino.packages.autocomplete.RealtimeCompletionsListener;
import cc.arduino.packages.autocomplete.SketchCompletionProvider;
import cc.arduino.packages.autocomplete.TDynamicLocation;
import cc.arduino.packages.autocomplete.template.GenerateVarTemplate;
import cc.arduino.packages.autocomplete.template.IncludeTemplate;

public class SketchTextArea extends RSyntaxTextArea {
  
  private final static Logger LOG = Logger.getLogger(SketchTextArea.class.getName());
  
  private SketchCompletionProvider completionProvider;
  
  /** The last docTooltip displayed. */
  private FocusableTip docTooltip;
  
  /**
   * The component that tracks the current line number.
   */
  protected EditorLineStatus editorLineStatus;

  private EditorListener editorListener;
  
  public SketchTextArea() {
    super();
    installFeatures();
  }
  
  
  protected void installFeatures(){
    try {
      Theme theme = Theme.load(Base.getLibStream("theme/syntax/default.xml"));
      theme.apply(this);
    } catch (IOException e) {
      e.printStackTrace();
    }
    
    setLinkGenerator(new DocLinkGenerator());
    
    fixControlTab();
    installTokenMaker();  
  }
  
  // Removing the default focus traversal keys
  // This is because the DefaultKeyboardFocusManager handles the keypress and consumes the event
  protected void fixControlTab(){
    KeyStroke ctrlTab = KeyStroke.getKeyStroke("ctrl TAB");
    KeyStroke ctrlShiftTab = KeyStroke.getKeyStroke("ctrl shift TAB");
 
    // Remove ctrl-tab from normal focus traversal
    Set<AWTKeyStroke> forwardKeys = new HashSet<AWTKeyStroke>(this.getFocusTraversalKeys(KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS));
    forwardKeys.remove(ctrlTab);
    this.setFocusTraversalKeys(KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS, forwardKeys);
 
    // Remove ctrl-shift-tab from normal focus traversal
    Set<AWTKeyStroke> backwardKeys = new HashSet<AWTKeyStroke>(this.getFocusTraversalKeys(KeyboardFocusManager.BACKWARD_TRAVERSAL_KEYS));
    backwardKeys.remove(ctrlShiftTab);
  }


  
  public void setEditorLineStatus(EditorLineStatus editorLineStatus) {
    this.editorLineStatus = editorLineStatus;
  }
  
  @Override
  public void select(int selectionStart, int selectionEnd) {
    super.select(selectionStart, selectionEnd);
    if(editorLineStatus != null) editorLineStatus.set(selectionStart, selectionEnd);
  }

  public boolean isSelectionActive() {
    return this.getSelectedText() != null;
  }
  
  public void setSelectedText(String text){
    
    int old = getTextMode();
    setTextMode(OVERWRITE_MODE);
    replaceSelection(text);
    setTextMode(old);
    
  }

  protected void installTokenMaker(){
    AbstractTokenMakerFactory atmf = (AbstractTokenMakerFactory)TokenMakerFactory.getDefaultInstance();
    atmf.putMapping(SYNTAX_STYLE_CPLUSPLUS, "processing.app.syntax.SketchTokenMaker");
    setSyntaxEditingStyle(SYNTAX_STYLE_CPLUSPLUS);
  }
  
  public void processKeyEvent(KeyEvent evt) {
  
    // this had to be added because the menu key events weren't making it up to the frame.
    
    switch(evt.getID()) {
    case KeyEvent.KEY_TYPED:
      if (editorListener != null) editorListener.keyTyped(evt);
      break;
    case KeyEvent.KEY_PRESSED:
      if (editorListener != null) editorListener.keyPressed(evt);
      break;
    case KeyEvent.KEY_RELEASED:
      // inputHandler.keyReleased(evt);
      break;
    }
    
    if(!evt.isConsumed()){
       super.processKeyEvent(evt);
    }
  }
  
  public void setupAutoComplete(SketchCompletionProvider provider) {
    
    if(this.completionProvider != null){
      completionProvider.uninstall();
    }
    
    this.completionProvider = provider;
    AutoCompletion ac = new AutoCompletion(provider);
    provider.setAutoCompletion(ac);
    
    ac.setAutoActivationEnabled(true);
    ac.setShowDescWindow(false);
    ac.setListCellRenderer(new CompletionsRenderer());
    // ac.setParamChoicesRenderer(r);
    ac.setAutoCompleteSingleChoices(true);
    ac.setParameterAssistanceEnabled(true);
    
    // NOTE: Monitor changes. On 'SketchCompletionProvider.onSketchInserted' was installed a DocumentListener
    this.addKeyListener(new RealtimeCompletionsListener(provider.getSketch())); 
    
    ac.addAutoCompletionListener(new AutoCompletionListener() {
      @Override
      public void autoCompleteUpdate(AutoCompletionEvent e) {
        
        if(e instanceof ParameterizedCompletionEvent){
          ParameterizedCompletionEvent event = (ParameterizedCompletionEvent) e;
          
          ParameterizedCompletion completion = event.getCompletion();
          
          if(e.getEventType() == AutoCompletionEvent.Type.PARAMETER_COMPLETION_FINISH){
            List<String> parameterValues = event.getContext().getParameterValues();
            
            // Force parser/load new Lib for autocomplete.
            if(completion instanceof IncludeTemplate && !parameterValues.isEmpty()){
              Library library = Base.getLibraries().getByName(parameterValues.get(0));
              completionProvider.getSketch().getData().addLibrary(library);
            }
            
            if(completion instanceof GenerateVarTemplate && !parameterValues.isEmpty()){
              GenerateVarTemplate varTemplate = (GenerateVarTemplate) completion;
              TAttribute var =  new TAttribute(varTemplate.getType(), parameterValues.iterator().next());
              
              // Insert new var in current function scope
              TFunction functionScope = completionProvider.getCurrentFunctionScope(SketchTextArea.this);
              if(functionScope != null){
                TDynamicLocation location = new TDynamicLocation(SketchTextArea.this.getDocument(), functionScope.getLocation());
                var.setLocation(location);
                functionScope.addLocalVariable(var);
              }
              
            }
            
          }
          
          if(e.getEventType() == AutoCompletionEvent.Type.PARAMETER_COMPLETION_SELECT){
            
          }
        }
      }
    });
    ac.install(this);
  }
  
 public SketchCompletionProvider getCompletionProvider() {
  return completionProvider;
}
  
  public void switchDocument(Document document, UndoManager newUndo) {
    
    // HACK: Dont discard changes on curret UndoManager.
    // BUG: https://github.com/bobbylight/RSyntaxTextArea/issues/84
    setUndoManager(null); // bypass reset current undo manager...
    
    super.setDocument(document);
    
    setUndoManager((RUndoManager) newUndo);
    
    // HACK: Complement previous hack (hide code folding on switch) | Drawback: Lose folding state
//  if(sketch.getCodeCount() > 1 && textarea.isCodeFoldingEnabled()){
//    textarea.setCodeFoldingEnabled(false);
//    textarea.setCodeFoldingEnabled(true);
//  }
    
    
  }

  @Override
  protected JPopupMenu createPopupMenu() {
    JPopupMenu menu = super.createPopupMenu();
    return menu;
  }
  
  @Override
  protected void configurePopupMenu(JPopupMenu popupMenu) {
    super.configurePopupMenu(popupMenu);
  }
  
  public void getTextLine(int line, Segment segment) {
    try {
      int offset = getLineStartOffset(line);
      int end = getLineEndOffset(line);
      getDocument().getText(offset, end - offset, segment);
    } catch (BadLocationException e) {
    }
  }
  
  public String getTextLine(int line) {
    try {
      int offset = getLineStartOffset(line);
      int end = getLineEndOffset(line);
      return getDocument().getText(offset, end - offset);
    } catch (BadLocationException e) {
      return null;
    }
  }
  
  @Override
  protected String getToolTipTextImpl(MouseEvent e) {

    // FIXME: This part is still in testing phase
    // NOTA(R.R) - Já tem no :
    // org.fife.ui.autocomplete.Completion.getToolTipText() , nãos sei como poderia integrar
    
    boolean enabled = false;
    
    // Function responsible for displaying a toolip documentation when CTRL is pressed
    if (e.isControlDown() && enabled) {

      Point p = e.getPoint();

      final Token token = viewToToken(p);

      final String reference = PdeKeywords.getReference(token.getLexeme());
      
      System.out.println("token: "+token.getLexeme() + ", reference: "
                         + reference
                         + ", match: "
                         + (token.getType() == TokenTypes.DATA_TYPE
                            || token.getType() == TokenTypes.VARIABLE || token
                             .getType() == TokenTypes.FUNCTION));

      if (token != null && (reference != null || (token.getType() == TokenTypes.DATA_TYPE
                                               || token.getType() == TokenTypes.VARIABLE 
                                               || token.getType() == TokenTypes.FUNCTION))) {


        String text = DocumentationUtils.getDocumentation(token.getLexeme(), null);

        // Use custom tooltip for arduino reference
        if (reference != null && getUseFocusableTips()) {
          if (text != null) {
            if (docTooltip == null) {
              docTooltip = new FocusableTip(this, new HyperlinkListener() {

                @Override
                public void hyperlinkUpdate(HyperlinkEvent e) {
                  System.out.println("link clicked !");

                }
              });
            }
            // docTooltip.setImageBase(imageBase);
            docTooltip.toolTipRequested(e, text);
            docTooltip.setMaxSize(new Dimension(500, 300));
          }
          // No tool tip text at new location - hide tip window if one is
          // currently visible
          else if (docTooltip != null) {
            docTooltip.possiblyDisposeOfTipWindow();
          }
          return null;
        // Use simple tooltips for source-code documentation
        }else{
            // completionProvider.getal

        }

      }else{
          // find instance name.
          Token previous = RSyntaxUtilities.getPreviousImportantTokenFromOffs((RSyntaxDocument)getDocument(), token.getOffset());
          if(previous.is(Token.OPERATOR, ".") || previous.is(Token.OPERATOR, ">") ||  previous.is(Token.OPERATOR, ":")){
            if(!previous.is(Token.OPERATOR, ".")) previous = RSyntaxUtilities.getPreviousImportantTokenFromOffs((RSyntaxDocument)getDocument(), previous.getOffset());
            previous = RSyntaxUtilities.getPreviousImportantTokenFromOffs((RSyntaxDocument)getDocument(), previous.getOffset());
          }
          System.out.println("last:" + previous.getType() +" -> " + previous); 
      }

    }

    return super.getToolTipTextImpl(e);
  }
  


  public void setEditorListener(EditorListener editorListener) {
    this.editorListener = editorListener;
  }
  
  private static class DocLinkGenerator implements LinkGenerator{
    
     @Override
      public LinkGeneratorResult isLinkAtOffset(RSyntaxTextArea textArea, final int offs) {
        
        final Token token = textArea.modelToToken(offs);
        
        final String reference = PdeKeywords.getReference(token.getLexeme());

        // LOG.fine("reference: " + reference + ", match: " + (token.getType() == TokenTypes.DATA_TYPE || token.getType() == TokenTypes.VARIABLE || token.getType() == TokenTypes.FUNCTION));
        
        if(token != null && (reference != null || (token.getType() == TokenTypes.DATA_TYPE || token.getType() == TokenTypes.VARIABLE || token.getType() == TokenTypes.FUNCTION) )){
          
          LinkGeneratorResult generatorResult = new LinkGeneratorResult() {
            
            @Override
            public int getSourceOffset() {
              return offs;
            }
            
            @Override
            public HyperlinkEvent execute() {
              
              LOG.fine("Open Reference: " + reference);
              
              Base.showReference("Reference/" + reference);
              
              return null;
            }
          };
          
          return generatorResult;
        }
        
        return null;
      }
    };

}
