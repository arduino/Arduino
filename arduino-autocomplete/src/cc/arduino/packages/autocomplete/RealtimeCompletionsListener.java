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

import processing.app.SketchCode;
import processing.app.SketchData;
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
  
  private SketchData sketchData;
  private Segment segment = new Segment();
  private Timer debounce;
  private int startOffs;
  private int endOffs;
  private int startLine;
  private int endLine;

  public RealtimeCompletionsListener(SketchData sketchData) {
    this.sketchData = sketchData;
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
    SketchCode sketchCode = sketchData.getCurrentCode();
    TLibrary library = sketchData.getSketchMetadata();
    if(library != null){
      
      long time = System.currentTimeMillis();
      if(library.getLastUpdate() > 0 && (time - library.getLastUpdate() < 2000 )){
        LOG.fine("Ignoring parser, a recent parser has been done !");
        return;
      }
      
      library.clear(sketchCode.getFile().getPath());
    }
    
    try {
      Document document = SketchCompletionProvider.getDocument(sketchCode);
      String code = document.getText(0, document.getLength());
      LibraryIndex.scanSource(code, new SketchCodeScanner(sketchData, sketchData.getCurrentCode())); // fire #onLoadLibrary on finish
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
    
    
    if(sketchData != null && sketchData.getSketchMetadata() != null){
      TLibrary metadata = sketchData.getSketchMetadata();
      
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
