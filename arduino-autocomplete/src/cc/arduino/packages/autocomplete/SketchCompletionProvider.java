/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * Copyright 2015 Arduino LLC
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */
package cc.arduino.packages.autocomplete;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
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
import processing.app.PreferencesData;
import processing.app.SketchCode;
import processing.app.SketchData;
import processing.app.SketchDocumentProvider;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.StringUtils;
import processing.app.packages.LibraryList;
import processing.app.packages.LibraryListener;
import processing.app.packages.SketchListener;
import processing.app.packages.UserLibrary;
import br.com.criativasoft.cpluslibparser.LibraryIndex;
import br.com.criativasoft.cpluslibparser.LibraryIndexListener;
import br.com.criativasoft.cpluslibparser.metadata.TAttribute;
import br.com.criativasoft.cpluslibparser.metadata.TClass;
import br.com.criativasoft.cpluslibparser.metadata.TElement;
import br.com.criativasoft.cpluslibparser.metadata.TElementLocation;
import br.com.criativasoft.cpluslibparser.metadata.TFunction;
import br.com.criativasoft.cpluslibparser.metadata.TLibrary;
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
  
  public static final String SKETCH_LIB_PREFIX = ArduinoLibraryScanner.SKETCH_LIB_PREFIX;
  
  /**
   * Matches strings like {@code obj.myMethod(params)}
   * {@code (?U)} lets {@code \\w} also match non-ASCII letters.
   */
  public static final Pattern INSTANCE_CALL_REGEX = Pattern.compile("(?U)([.\\w]+)\\.([\\w]+)\\s*\\((.*)\\)");
  
  public static final Pattern FUNCTION_CALL_REGEX = Pattern.compile("(?U)([.\\w]+)\\s*\\((.*)\\)");
  
  private TLibrary sketchLibrary; // classes, variables, functions of sketch
  private SketchData sketchData;
  private LibraryList importedLibraries; // same instance in Sketch 
  
  private RealtimeCompletionsListener realtimeCompletionsListener;
  
  private CompletionProviderWithContext provider = new CompletionProviderWithContext(); // Loaded static auto-completes.

  private AutoCompletion autoCompletion;
  
  public SketchCompletionProvider(SketchData sketchData) {
    super();
    this.sketchData = sketchData;
    
    provider.setParameterChoicesProvider(new ParameterChoicesProvider(this));
    setDefaultCompletionProvider(provider); 
    provider.setParameterizedCompletionParams('(', ", ", ')');
    
    LibraryIndex.addListener(this); 
    sketchData.addListener(this);
    realtimeCompletionsListener = new RealtimeCompletionsListener(sketchData);
    
    // Import existing...
    
    // Arduino Core
    //=======================
    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform();
    File folder = targetPlatform.getFolder();
    File coreFolder = new File(folder,"cores"+File.separator+"arduino");
    if(coreFolder.exists()){
      UserLibrary coreLib;
      try {
        coreLib = UserLibrary.create(coreFolder);
        LibraryIndex.scanFolder(coreFolder, new ArduinoLibraryScanner(coreLib)); // fire #onLoadLibrary on finish
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    
    LibraryIndex.scanFolder(sketchData.getFolder(), new SketchCodeScanner(sketchData)); // fire #onLoadLibrary on finish
  
    
    onSketchLoad(sketchData);
    for (SketchCode sketchCode : sketchData.getCodes()) {
      onSketchInserted(sketchData, sketchCode);
    }
    
    loadDefaultAutocompletes();
  }
  

  /**
   * Remove all listeners
   */
  public void uninstall() {
    LibraryIndex.removeListener(this);
    LibraryIndex.removeLibrary(sketchLibrary);
    sketchData.removeListener(this);
    importedLibraries.removeListener(this);
    
    autoCompletion.getTextComponent().removeKeyListener(realtimeCompletionsListener);
    
    for (SketchCode code : sketchData.getCodes()) {
      Document document = getDocument(code);
      if(document != null)
        document.removeDocumentListener(realtimeCompletionsListener);
    }
  }  
  
  
  // ==========================================
  // Sketch Library (importedLibraries) Listener
  // ==========================================

  @Override
  public void onInsertLibrary(UserLibrary library) {
    
    if(isExternalMode()) return;
    
    LOG.fine("Arduino Lib: " + library);
    LibraryIndex.scanFolder(library.getSrcFolder(), new ArduinoLibraryScanner(library)); // scan lib and fire #onLoadLibrary
  }

  @Override
  public void onRemoveLibrary(UserLibrary library) {
    
    if(isExternalMode()) return;
    
    LOG.fine("Arduino Lib: " + library);
  }

  @Override
  public void onClearLibraryList() {
    
    if(isExternalMode()) return;
    
  }

  
  // ==========================================
  // SketchCode Listener
  // ==========================================

  @Override
  public void onSketchLoad(SketchData sketch) {
    
    if(isExternalMode()) return;
    
    LOG.fine(sketch.getName());
    
    importedLibraries = sketch.getImportedLibraries();
    importedLibraries.addListener(this);
    for (UserLibrary library : importedLibraries) {
      onInsertLibrary(library);
    }
  }


  @Override
  public void onSketchInserted(SketchData sketch, SketchCode code) {
    
    if(isExternalMode()) return;
    
    LOG.fine(code.getFileName());
    
    Object metadata = code.getMetadata();
    if(metadata instanceof SketchDocumentProvider){
      Document document = ((SketchDocumentProvider) metadata).getDocument();
      if(document != null){
    	  document.addDocumentListener(realtimeCompletionsListener);
      }
    }
    
  }

  @Override
  public void onSketchSaved(SketchData sketch, SketchCode code) {
    
    if(isExternalMode()) return;
    
    LOG.fine(code.getFileName());
    
    if(sketchLibrary != null){
      sketchLibrary.clear(code.getFile().getPath()); // Clear to get the new variables and remove those that no longer exist
    }
    
    LibraryIndex.scanFolder(sketch.getFolder(), new SketchCodeScanner(sketch, code)); // fire #onLoadLibrary on finish
  }
  
  
  // ==========================================
  // LibraryIndex Listener (Parser)
  // ==========================================
  
  @Override
  public void onLoadLibrary(TLibrary library) {
    
      if(isExternalMode()) return;
      
      if(library.name().equals(SKETCH_LIB_PREFIX+sketchData.getName())){ // Sketch indexing finish
        sketchLibrary = library;
        sketchLibrary.setReloadable(true);
        provider.setSketchLibrary(sketchLibrary);
        sketchData.setSketchMetadata(sketchLibrary);
      }
      
      createCompletions(library);
  }

  @Override
  public void onUnloadLibrary(TLibrary library) {
    LOG.fine(library.name());
    
  }

  @Override
  public void onReloadLibrary(TLibrary library) {
    
    if(isExternalMode()) return;
    
    createCompletions(library);
  }
  
  private boolean isExternalMode(){
	  return PreferencesData.getBoolean("editor.external");
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
    String[] names = {"HIGH", "LOW", "OUTPUT", "INPUT", "INPUT_PULLUP", "CHANGE", "FALLING", "RISING", "RISING", "DEC", "HEX", "OCT", "BIN", "LED_BUILTIN"};
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
    
    SketchCode[] codes = sketchData.getCodes();
    
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
  
  public SketchData getSketchData() {
    return sketchData;
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
        
        // Find like: EEPROM (static struct)
        if(varClass == null){
        	
        	TLibrary library = LibraryIndex.getLibrary(instance);
        	if(library != null){
        		TElement variable = library.findMember(instance); 
        		if(variable instanceof TAttribute){
        			varClass = LibraryIndex.getClass(((TAttribute) variable).getType());
        		}
        		
        	}
        	
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
    autoCompletion.getTextComponent().addKeyListener(realtimeCompletionsListener);
  }
  
  public AutoCompletion getAutoCompletion() {
    return autoCompletion;
  }
  


  
}
