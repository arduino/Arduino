package cc.arduino.packages.autocomplete;

import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.text.Document;

import org.fife.ui.autocomplete.AutoCompletion;
import org.fife.ui.autocomplete.Completion;
import org.fife.ui.autocomplete.LanguageAwareCompletionProvider;
import org.fife.ui.autocomplete.TemplateCompletion;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;

import processing.app.BaseNoGui;
import processing.app.BaseSketch;
import processing.app.SketchCode;
import processing.app.SketchDocumentProvider;
import processing.app.helpers.StringUtils;
import processing.app.packages.Library;
import processing.app.packages.LibraryList;
import processing.app.packages.LibraryListener;
import processing.app.packages.SketchListener;
import br.com.criativasoft.cpluslibparser.LibraryIndex;
import br.com.criativasoft.cpluslibparser.LibraryIndexListener;
import br.com.criativasoft.cpluslibparser.metadata.*;
import cc.arduino.packages.autocomplete.template.GenerateVarTemplate;
import cc.arduino.packages.autocomplete.template.IncludeTemplate;

/**
 * CompletionProvider for Arduino/CPP Language. <br/>
 * This class is responsible for the settings required for the logic of autocomplete, 
 * external events such as adding libraries, creating new files, etc .. will be monitored. <br/>
 * Filtering and decision will appear in the autocomplete is up to the: {@link CompletionProviderWithContext}. <br/>
 * Another class that works together is the: {@link RealtimeCompletionsListener} , 
 * that monitor real-time changes to the text and notifies when it should be made a new parser.
 * <br/><br/>
 * The analysis(parser) of the source code is made by the library <code>cplus-libparser</code>, Which was specially developed 
 * for the Arduino, more can be used in other projects.
 * 
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * @date 22/11/2014
 */
public class SketchCompletionProvider extends LanguageAwareCompletionProvider implements LibraryListener, LibraryIndexListener, SketchListener{
  
  private final static Logger LOG = Logger.getLogger(RealtimeCompletionsListener.class.getName()); 
  
  public static final String SKETCH_LIB_PREFIX = BaseSketch.SKETCH_LIB_PREFIX;
  
  /**
   * Matches strings like {@code obj.myMethod(params)}
   * {@code (?U)} lets {@code \\w} also match non-ASCII letters.
   */
  public static final Pattern INSTANCE_CALL_REGEX = Pattern.compile("(?U)([.\\w]+)\\.([\\w]+)\\s*\\((.*)\\)");
  
  public static final Pattern FUNCTION_CALL_REGEX = Pattern.compile("(?U)([.\\w]+)\\s*\\((.*)\\)");
  
  private TLibrary sketchLibrary; // classes, variables, functions of sketch
  private BaseSketch sketch;
  private LibraryList importedLibraries; // same instance in Sketch 
  
  private RealtimeCompletionsListener realtimeCompletionsListener;
  
  
  private CompletionProviderWithContext provider = new CompletionProviderWithContext(); // Loaded static auto-completes.

  private AutoCompletion autoCompletion;
  
  public SketchCompletionProvider(BaseSketch sketch) {
    super();
    this.sketch = sketch;
    
    provider.setParameterChoicesProvider(new ParameterChoicesProvider(this));
    setDefaultCompletionProvider(provider); 
    provider.setParameterizedCompletionParams('(', ", ", ')');
    
    LibraryIndex.addListener(this); 
    sketch.addListener(this);
    realtimeCompletionsListener = new RealtimeCompletionsListener(sketch);
    
    // Import existing...
    
    // Arduino Core
    //=======================
    File folder = BaseNoGui.getTargetPlatform().getFolder();
    File coreFolder = new File(folder,"cores"+File.separator+"arduino");
    if(coreFolder.exists()){
      Library coreLib;
      try {
        coreLib = Library.create(coreFolder);
        LibraryIndex.scanFolder(coreFolder, new ArduinoLibraryScanner(coreLib)); // fire #onLoadLibrary on finish
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    
    LibraryIndex.scanFolder(sketch.getFolder(), new SketchCodeScanner(sketch)); // fire #onLoadLibrary on finish
  
    
    onSketchLoad(sketch);
    for (SketchCode sketchCode : sketch.getCodes()) {
      onSketchInserted(sketch, sketchCode);
    }
    
    loadDefaultAutocompletes();
  }
  

  /**
   * Remove all added listeners
   */
  public void uninstall() {
    LibraryIndex.removeListener(this); 
    sketch.removeListener(this);
    importedLibraries.addListener(this);
    
    for (SketchCode code : sketch.getCodes()) {
      Document document = getDocument(code);
      if(document != null)
        document.removeDocumentListener(realtimeCompletionsListener);
    }
  }  
  
  
  // ==========================================
  // Sketch Library (importedLibraries) Listener
  // ==========================================

  @Override
  public void onInsertLibrary(Library library) {
    
    if(sketch.isExternalMode()) return;
    
    LOG.fine("Arduino Lib: " + library);
    LibraryIndex.scanFolder(library.getFolder(), new ArduinoLibraryScanner(library)); // scan lib and fire #onLoadLibrary
  }

  @Override
  public void onRemoveLibrary(Library library) {
    
    if(sketch.isExternalMode()) return;
    
    LOG.fine("Arduino Lib: " + library);
  }

  @Override
  public void onClearLibraryList() {
    
    if(sketch.isExternalMode()) return;
    
  }

  
  // ==========================================
  // SketchCode Listener
  // ==========================================

  @Override
  public void onSketchLoad(BaseSketch sketch) {
    
    if(sketch.isExternalMode()) return;
    
    LOG.fine(sketch.getName());
    
    importedLibraries = sketch.getImportedLibraries();
    importedLibraries.addListener(this);
    for (Library library : importedLibraries) {
      onInsertLibrary(library);
    }
  }


  @Override
  public void onSketchInserted(BaseSketch sketch, SketchCode code) {
    
    if(sketch.isExternalMode()) return;
    
    LOG.fine(code.getFileName());
    
    Object metadata = code.getMetadata();
    if(metadata instanceof SketchDocumentProvider){
      Document document = ((SketchDocumentProvider) metadata).getDocument();
      if(document != null)
      document.addDocumentListener(realtimeCompletionsListener);
    }
    
  }

  @Override
  public void onSketchSaved(BaseSketch sketch, SketchCode code) {
    
    if(sketch.isExternalMode()) return;
    
    LOG.fine(code.getFileName());
    
    if(sketchLibrary != null){
      sketchLibrary.clear(); // Clear to get the new variables and remove those that no longer exist
    }
    
    LibraryIndex.scanFolder(sketch.getFolder(), new SketchCodeScanner(code)); // fire #onLoadLibrary on finish
  }
  
  
  // ==========================================
  // LibraryIndex Listener
  // ==========================================
  
  @Override
  public void onLoadLibrary(TLibrary library) {
    
      if(sketch.isExternalMode()) return;
      
      if(library.name().equals(SKETCH_LIB_PREFIX+sketch.getName())){ // Sketch indexing finish
        sketchLibrary = library;
        sketchLibrary.setReloadable(true);
        provider.setSketchLibrary(sketchLibrary);
        sketch.setSketchMetadata(sketchLibrary);
      }
      
      createCompletions(library);
  }

  @Override
  public void onUnloadLibrary(TLibrary library) {
    LOG.fine(library.name());
    
  }

  @Override
  public void onReloadLibrary(TLibrary library) {
    
    if(sketch.isExternalMode()) return;
    
    createCompletions(library);
  }
  
  protected void loadDefaultAutocompletes(){
    
    List<Completion> completions = new ArrayList<Completion>();
    
    completions.add(new IncludeTemplate(provider));
    completions.add(new TemplateCompletion(provider, "for", "interate over array", "for (int ${i} = 0; ${i} < ${array}.length; ${i}++) {\n\t${cursor}\n}"));
    completions.add(new TemplateCompletion(provider, "while", "while block", "while (${condition}) {\n\t${cursor}\n}"));
    completions.add(new TemplateCompletion(provider, "if", "if block", "if (${condition}) {\n\t${cursor}\n}"));
    completions.add(new TemplateCompletion(provider, "elseif", "elseif block", "else if (${condition}) {\n\t${cursor}\n}"));
    completions.add(new TemplateCompletion(provider, "else", "else block", "else{\n\t${cursor}\n}"));
    
    completions.add(new TemplateCompletion(provider, "println", "Serial.println()", "Serial.println(\"${cursor}\");"));
    
    completions.add(new TemplateCompletion(provider, "dw", "digitalWrite", "digitalWrite(${cursor});"));
    completions.add(new TemplateCompletion(provider, "dr", "digitalRead", "digitalRead(${cursor});"));
    completions.add(new TemplateCompletion(provider, "aw", "analogWrite", "analogWrite(${cursor});"));
    completions.add(new TemplateCompletion(provider, "ar", "analogRead", "analogRead(${cursor});"));
    
    
    //Add as ENUNM
    // TODO: only show if in method params
    String[] names = {"HIGH", "LOW", "OUTPUT", "INPUT", "INPUT_PULLUP", "CHANGE", "FALLING", "RISING", "RISING", "DEC", "HEX", "OCT", "BIN"};
    for (String name : names) {
      TAttribute attribute = new TAttribute("int", name);
      attribute.setEnum(true);
      completions.add(new TElementCompletion(provider, attribute));
    }
    
    provider.addCompletions(completions);
  }
  
  
  /**
   * Add Completions from parsed lib
   */
  protected void createCompletions( TLibrary library ) {

    LOG.fine("build auto-complete for: " + library.name());

    Set<TElement> allMembers = library.getAllMembers();

    // Sketch indexing finish
    // sketchCompletions are dynamic.
    if (sketchLibrary != null && library.name().equals(sketchLibrary.name())) {

      List<Completion> sketchCompletions = new ArrayList<Completion>();

      for (TElement element : allMembers) {

        // Set sketck attrs as not static
        if (element instanceof TAttribute) {
          ((TAttribute) element).setStatic(false);
        }

        // track positions of methods and variables even after document changes
        TElementLocation location = element.getLocation();
        if (location != null) {
          Document document = findSketchDocument(element);
          // If if document already loaded
          if (document != null) {
            TDynamicLocation dynamicLocation = new TDynamicLocation(document, location);
            element.setLocation(dynamicLocation);
          }
        }

        if (element instanceof TFunction) {
          if (element.name().equals("setup") || element.name().equals("loop")) continue;
          TFunctionCompletion completion = new TFunctionCompletion(provider, (TFunction) element);
          completion.setRelevance(3);
          sketchCompletions.add(completion);
        } else {
          sketchCompletions.add(new TElementCompletion(provider, element));
        }
      }

      provider.setSketchCompletions(sketchCompletions);

    } else {

      List<Completion> staticCompletions = new ArrayList<Completion>();

      Set<TClass> classes = library.getClasses();
      for (TClass tClass : classes) {
        // XXX autocomplete: PdeTokenMaker.addKeyword(tClass.name(), Token.DATA_TYPE);
      }

      for (TElement element : allMembers) {
        if (element instanceof TFunction) { // global func.
          if (element.name().equals("setup") || element.name().equals("loop")) continue;
          TFunctionCompletion completion = new TFunctionCompletion(provider, (TFunction) element);
          staticCompletions.add(completion);
        } else {
          staticCompletions.add(new TElementCompletion(provider, element));
        }
      }

      provider.addCompletions(staticCompletions);

    }

  }
  
  protected Document findSketchDocument(TElement element){
    
    TElementLocation location = element.getLocation();
    
    String name = location.getFileName();
    
    SketchCode[] codes = sketch.getCodes();
    
    if(codes.length == 1) return getDocument(codes[0]);
    
    for (SketchCode sketchCode : codes) {
      if(sketchCode.getFileName().equals(name)){
        return getDocument(sketchCode);
      }
    }
    
    return null;
  }
  
  static Document getDocument(SketchCode code){
    Object metadata = code.getMetadata();
    if(metadata instanceof SketchDocumentProvider){
      return  ((SketchDocumentProvider) metadata).getDocument();
    }
    return null;
  }
  
  public BaseSketch getSketch() {
    return sketch;
  }
  
  public TFunction getCurrentFunctionScope(RSyntaxTextArea textarea){
    return provider.getCurrentFunctionScope(textarea);
  }


  public void generateNewVariableFor(String expression, int startOffSet) {
    
    Matcher instanceCall = INSTANCE_CALL_REGEX.matcher(expression);

    String returnType = null;
    String function = null;
    String varname = null;
    
    RSyntaxTextArea textArea = (RSyntaxTextArea) autoCompletion.getTextComponent();
    
    // find retun type of function like (obj.myMethod(params))
    if (instanceCall.find()) {
        String instance = instanceCall.group(1);
        function = instanceCall.group(2);
        
        Set<TAttribute> variables = new HashSet<TAttribute>();
        
        variables.addAll(sketchLibrary.getGlobalVariables());
        
        TFunction functionScope = provider.getCurrentFunctionScope(textArea);
        if(functionScope != null){
          variables.addAll(functionScope.getLocalVariables());
        }
        
        TClass varClass = null;
        
        for (TAttribute var : variables) {
          
          LOG.fine("generateVariableName , var : " + var);
          
          // find class of instance.
          if(var.name().equals(instance)){
            LOG.fine("generateVariableName , found : " + var);
            
            String type = var.getType();
            varClass = LibraryIndex.getClass(type);
            if(varClass != null) break;
          }
            
        }
        
        // Find like: Serial / Ethernet.
        if(varClass == null){
          varClass = LibraryIndex.getClass(instance);
        }
        
        if(varClass != null){
          
          LOG.fine("Class : " +varClass + "");
          TFunction tFunction = varClass.getFunction(function, true);
          
          LOG.fine("Function = "  +tFunction + " (for:" + function + ")");
          
          if(tFunction != null){
            returnType = tFunction.getReturnType();
          }
          
        }
        
        
    }else{
      
      Matcher functionCall = FUNCTION_CALL_REGEX.matcher(expression);
      if (functionCall.find()) {
        function = functionCall.group(1);
        String param = functionCall.group(2);
        
        if(function.equals("digitalRead") || function.equals("analoadRead")){
          returnType = "int";
          varname = param +"Val";
        }else{
          Set<TFunction> functions = LibraryIndex.getGlobalFunctions(function);
          
          if(!functions.isEmpty()){
            returnType = functions.iterator().next().getReturnType();
          }    
        }
        
      }
      
    }
    
    
    if(returnType != null){
      
      if(varname == null){
        if(TElement.isPrimitive(returnType)){
          varname = function;
        }else{
          String lastWord = StringUtils.findLastWord(returnType);
          if(lastWord == null) lastWord = returnType;
          varname = StringUtils.uncapitalize(lastWord);
        }  
      }
      
      if(varname != null){
        
        GenerateVarTemplate completion = new GenerateVarTemplate(provider, returnType, varname);
        
        textArea.setCaretPosition(startOffSet);
        
        AutoCompletion autoCompletion = getAutoCompletion();
        autoCompletion.startParameterizedCompletionAssistance(completion, false);
        
      }
    }
    
  }


  public void setAutoCompletion(AutoCompletion autoCompletion) {
    this.autoCompletion = autoCompletion;
  }
  
  public AutoCompletion getAutoCompletion() {
    return autoCompletion;
  }


  
}
