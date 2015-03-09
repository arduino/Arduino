package cc.arduino.packages.autocomplete;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Set;
import java.util.logging.Logger;

import javax.swing.Timer;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.Element;
import javax.swing.text.Segment;

import processing.app.BaseSketch;
import processing.app.SketchCode;
import br.com.criativasoft.cpluslibparser.LibraryIndex;
import br.com.criativasoft.cpluslibparser.metadata.TElement;
import br.com.criativasoft.cpluslibparser.metadata.TError;
import br.com.criativasoft.cpluslibparser.metadata.TFunction;
import br.com.criativasoft.cpluslibparser.metadata.TLibrary;

/**
 * This is the class responsible for monitoring the events and changes in the code and decide when it should 
 * be done a parser to extract the metadata to make the autocomplete <br/>
 * This listener is registered by: {@link SketchCompletionProvider#onSketchInserted(Sketch, SketchCode)} and {@link PdeTextArea}. 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * @date 22/11/2014
 */
public class RealtimeCompletionsListener implements KeyListener, DocumentListener {

  private final static Logger LOG = Logger.getLogger(RealtimeCompletionsListener.class.getName()); 
  
  private BaseSketch sketch;
  private Segment segment = new Segment();
  private Timer debounce;
  private int startOffs;
  private int endOffs;
  private int startLine;
  private int endLine;

  public RealtimeCompletionsListener(BaseSketch sketch) {
    this.sketch = sketch;
    debounce = new Timer(800, new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        analizeModified();
      }
    });
    debounce.setRepeats(false);
    
  }

  @Override
  public void keyTyped(KeyEvent e) {
    
  }

  @Override
  public void keyPressed(KeyEvent e) {
    
  }

  @Override
  public void keyReleased(KeyEvent e) {
    if(e.getKeyChar() == ';' || e.getKeyChar() == '}'){
      fireParser();
    }   
  }
  

  protected void fireParser(){
    SketchCode sketchCode = sketch.getCurrentCode();
    TLibrary library = sketch.getSketchMetadata();
    if(library != null){
      
      long time = System.currentTimeMillis();
      if(library.getLastUpdate() > 0 && (time - library.getLastUpdate() < 2000 )){
        LOG.fine("Ignoring parser, a recent parser has been done !");
        return;
      }
      
      library.clear();
    }
    
    try {
      Document document = SketchCompletionProvider.getDocument(sketchCode);
      String code = document.getText(0, document.getLength());
      LibraryIndex.scanSource(code, new SketchCodeScanner(sketch.getCurrentCode())); // fire #onLoadLibrary on finish
    } catch (BadLocationException e) {
      LOG.severe(e.getMessage());
    }
  }

  @Override
  public void insertUpdate(DocumentEvent e) {
      startOffs = e.getOffset();
      endOffs = startOffs + e.getLength();
      Document doc = e.getDocument();
      Element root = doc.getDefaultRootElement();
      startLine = root.getElementIndex(startOffs);
      endLine = root.getElementIndex(endOffs);
      
      debounce.restart();  // waits for the user stops typing
      
      try {
        doc.getText(startOffs, e.getLength(), segment);
  
        if (startLine != endLine) { // Inserted text covering > 1 line...
          // fireParser();
          // System.out.println("RealtimeCompletionsListener.insertUpdate: startLine != endLine");
          
        } else if (segment.length() > 0&& segment.charAt(segment.length() - 1) == '}') {
         // System.out.println("RealtimeCompletionsListener.insertUpdate: == '}'");
        }
      } catch (BadLocationException e2) {
        e2.printStackTrace();
      }
      
  }

  @Override
  public void removeUpdate(DocumentEvent e) {
    
    debounce.restart(); // waits for the user stops typing
    
  }

  @Override
  public void changedUpdate(DocumentEvent e) {
    
  }
  
  protected void analizeModified(){
    
    
    if(sketch != null && sketch.getSketchMetadata() != null){
      TLibrary metadata = sketch.getSketchMetadata();
      
      // Check errors
      if(TError.containsError(startOffs, metadata.getErrors())){
        LOG.fine("Offset contains erros, firing parser");
        fireParser();
        return;
      }
      
      // Variables
      if(TElement.contains(startOffs, metadata.getGlobalVariables())){
        LOG.fine("Changing a global variable, firing parser");
        fireParser();
        return;
      }
      
      Set<TFunction> functions = metadata.getGlobalFunctions();
      
      for (TFunction function : functions) {
        if(!"setup".equals(function.name())){
          if(TElement.contains(startOffs, function.getLocalVariables())){
            LOG.fine("Changing a local variable, firing parser");
            fireParser();
            return;
          }
        }
      }
      
    }
    
  }
  

}
