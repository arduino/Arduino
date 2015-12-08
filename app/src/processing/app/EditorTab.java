/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Arduino project - http://www.arduino.cc

  Copyright (c) 2015 Matthijs Kooijman
  Copyright (c) 2004-09 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 2
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package processing.app;

import static processing.app.I18n.tr;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.Action;
import javax.swing.BorderFactory;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.ToolTipManager;
import javax.swing.border.MatteBorder;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;
import javax.swing.event.PopupMenuEvent;
import javax.swing.event.PopupMenuListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.PlainDocument;
import javax.swing.undo.UndoManager;

import org.fife.ui.rsyntaxtextarea.RSyntaxDocument;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextAreaEditorKit;
import org.fife.ui.rsyntaxtextarea.RSyntaxUtilities;
import org.fife.ui.rtextarea.Gutter;
import org.fife.ui.rtextarea.RTextScrollPane;

import processing.app.helpers.DocumentTextChangeListener;
import processing.app.syntax.ArduinoTokenMakerFactory;
import processing.app.syntax.PdeKeywords;
import processing.app.syntax.SketchTextArea;
import processing.app.syntax.SketchTextAreaEditorKit;
import processing.app.tools.DiscourseFormat;

/**
 * Single tab, editing a single file, in the main window.
 */
public class EditorTab extends JPanel implements SketchCode.TextStorage {
  protected Editor editor;
  protected SketchTextArea textarea;
  protected RTextScrollPane scrollPane;
  protected SketchCode code;
  protected boolean modified;
  
  /**
   * Create a new EditorTab
   *
   * @param editor
   *          The Editor this tab runs in
   * @param code
   *          The file to display in this tab
   * @param contents
   *          Initial contents to display in this tab. Can be used when
   *          editing a file that doesn't exist yet. If null is passed,
   *          code.load() is called and displayed instead.
   * @throws IOException
   */
  public EditorTab(Editor editor, SketchCode code, String contents)
      throws IOException {
    super(new BorderLayout());

    // Load initial contents contents from file if nothing was specified.
    if (contents == null) {
      contents = code.load();
      modified = false;
    } else {
      modified = true;
    }

    this.editor = editor;
    this.code = code;
    RSyntaxDocument document = createDocument(contents);
    this.textarea = createTextArea(document);
    this.scrollPane = createScrollPane(this.textarea);
    applyPreferences();
    add(this.scrollPane, BorderLayout.CENTER);

    UndoManager undo = new LastUndoableEditAwareUndoManager(this.textarea, this.editor);
    ((RSyntaxDocument)textarea.getDocument()).addUndoableEditListener(undo);
    code.setStorage(this);
  }

  private RSyntaxDocument createDocument(String contents) {
    RSyntaxDocument document = new RSyntaxDocument(new ArduinoTokenMakerFactory(editor.base.getPdeKeywords()), RSyntaxDocument.SYNTAX_STYLE_CPLUSPLUS);
    document.putProperty(PlainDocument.tabSizeAttribute, PreferencesData.getInteger("editor.tabs.size"));

    // insert the program text into the document object
    try {
      document.insertString(0, contents, null);
    } catch (BadLocationException bl) {
      bl.printStackTrace();
    }
    document.addDocumentListener(new DocumentTextChangeListener(
        () -> setModified(true)));
    return document;
  }
  
  private RTextScrollPane createScrollPane(SketchTextArea textArea) throws IOException {
    RTextScrollPane scrollPane = new RTextScrollPane(textArea, true);
    scrollPane.setBorder(new MatteBorder(0, 6, 0, 0, Theme.getColor("editor.bgcolor")));
    scrollPane.setViewportBorder(BorderFactory.createEmptyBorder());
    scrollPane.setLineNumbersEnabled(PreferencesData.getBoolean("editor.linenumbers"));
    scrollPane.setIconRowHeaderEnabled(false);

    Gutter gutter = scrollPane.getGutter();
    gutter.setBookmarkingEnabled(false);
    //gutter.setBookmarkIcon(CompletionsRenderer.getIcon(CompletionType.TEMPLATE));
    gutter.setIconRowHeaderInheritsGutterBackground(true);

    return scrollPane;
  }

  private SketchTextArea createTextArea(RSyntaxDocument document)
      throws IOException {
    final SketchTextArea textArea = new SketchTextArea(document, editor.base.getPdeKeywords());
    textArea.setName("editor");
    textArea.setFocusTraversalKeysEnabled(false);
    //textArea.requestFocusInWindow();
    textArea.setMarkOccurrences(PreferencesData.getBoolean("editor.advanced"));
    textArea.setMarginLineEnabled(false);
    textArea.setCodeFoldingEnabled(PreferencesData.getBoolean("editor.code_folding"));
    textArea.setAntiAliasingEnabled(PreferencesData.getBoolean("editor.antialias"));
    textArea.setTabsEmulated(PreferencesData.getBoolean("editor.tabs.expand"));
    textArea.setTabSize(PreferencesData.getInteger("editor.tabs.size"));
    textArea.addHyperlinkListener(new HyperlinkListener() {
      @Override
      public void hyperlinkUpdate(HyperlinkEvent hyperlinkEvent) {
        try {
          editor.platform.openURL(editor.getSketch().getFolder(), hyperlinkEvent.getURL().toExternalForm());
        } catch (Exception e) {
          Base.showWarning(e.getMessage(), e.getMessage(), e);
        }
      }
    });
    textArea.addCaretListener(new CaretListener() {
      @Override
      public void caretUpdate(CaretEvent e) {
        int lineStart = textArea.getDocument().getDefaultRootElement().getElementIndex(e.getMark());
        int lineEnd = textArea.getDocument().getDefaultRootElement().getElementIndex(e.getDot());

        editor.lineStatus.set(lineStart, lineEnd);
      }

    });

    ToolTipManager.sharedInstance().registerComponent(textArea);

    configurePopupMenu(textArea);
    return textArea;
  }
  
  private void configurePopupMenu(final SketchTextArea textarea){

    JPopupMenu menu = textarea.getPopupMenu();

    menu.addSeparator();

    JMenuItem item = editor.createToolMenuItem("cc.arduino.packages.formatter.AStyle");
    if (item == null) {
      throw new NullPointerException("Tool cc.arduino.packages.formatter.AStyle unavailable");
    }
    item.setName("menuToolsAutoFormat");

    menu.add(item);
    
    item = new JMenuItem(tr("Comment/Uncomment"), '/');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleCommentUncomment();
        }
    });
    menu.add(item);

    item = new JMenuItem(tr("Increase Indent"), ']');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleIndentOutdent(true);
        }
    });
    menu.add(item);

    item = new JMenuItem(tr("Decrease Indent"), '[');
    item.setName("menuDecreaseIndent");
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleIndentOutdent(false);
        }
    });
    menu.add(item);

    item = new JMenuItem(tr("Copy for Forum"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        handleDiscourseCopy();
      }
    });
    menu.add(item);

    item = new JMenuItem(tr("Copy as HTML"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        handleHTMLCopy();
      }
    });
    menu.add(item);

    final JMenuItem referenceItem = new JMenuItem(tr("Find in Reference"));
    referenceItem.addActionListener(editor::handleFindReference);
    menu.add(referenceItem);  

    final JMenuItem openURLItem = new JMenuItem(tr("Open URL"));
    openURLItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.openURL(e.getActionCommand());
      }
    });
    menu.add(openURLItem);   
    
    menu.addPopupMenuListener(new PopupMenuListener() {

      @Override
      public void popupMenuWillBecomeVisible(PopupMenuEvent e) {
            String referenceFile = editor.base.getPdeKeywords().getReference(getCurrentKeyword());
            referenceItem.setEnabled(referenceFile != null);
    
            int offset = textarea.getCaretPosition();
            org.fife.ui.rsyntaxtextarea.Token token = RSyntaxUtilities.getTokenAtOffset(textarea, offset);
            if (token != null && token.isHyperlink()) {
              openURLItem.setEnabled(true);
              openURLItem.setActionCommand(token.getLexeme());
            } else {
              openURLItem.setEnabled(false);
            }
      }

      @Override
      public void popupMenuWillBecomeInvisible(PopupMenuEvent e) {
      }

      @Override
      public void popupMenuCanceled(PopupMenuEvent e) {
      }
    });

  }
  
  public void applyPreferences() {
    textarea.setCodeFoldingEnabled(PreferencesData.getBoolean("editor.code_folding"));
    scrollPane.setFoldIndicatorEnabled(PreferencesData.getBoolean("editor.code_folding"));
    scrollPane.setLineNumbersEnabled(PreferencesData.getBoolean("editor.linenumbers"));

    // apply the setting for 'use external editor'
    if (PreferencesData.getBoolean("editor.external")) {
      // disable line highlight and turn off the caret when disabling
      textarea.setBackground(Theme.getColor("editor.external.bgcolor"));
      textarea.setHighlightCurrentLine(false);
      textarea.setEditable(false);

    } else {
      textarea.setBackground(Theme.getColor("editor.bgcolor"));
      textarea.setHighlightCurrentLine(Theme.getBoolean("editor.linehighlight"));
      textarea.setEditable(true);
    }

    // apply changes to the font size for the editor
    textarea.setFont(PreferencesData.getFont("editor.font"));
  }
  
  public void updateKeywords(PdeKeywords keywords) {
    // update GUI for "Find In Reference"
    textarea.setKeywords(keywords);
    // update document for syntax highlighting
    RSyntaxDocument document = (RSyntaxDocument) textarea.getDocument();
    document.setTokenMakerFactory(new ArduinoTokenMakerFactory(keywords));
    document.setSyntaxStyle(RSyntaxDocument.SYNTAX_STYLE_CPLUSPLUS);
  }
  
  /**
   * Get the TextArea object for use (not recommended). This should only
   * be used in obscure cases that really need to hack the internals of the
   * JEditTextArea. Most tools should only interface via the get/set functions
   * found in this class. This will maintain compatibility with future releases,
   * which will not use TextArea.
   */
  public SketchTextArea getTextArea() {
    return textarea;
  }

  /**
   * Get the sketch this tab is editing a file from.
   */
  public Sketch getSketch() {
    return editor.getSketch();
  }
  
  /**
   * Get the SketchCodeDocument that is being edited in this tab.
   */
  public SketchCode getSketchCode() {
    return this.code;
  }
  
  /**
   * Get the contents of the text area.
   */
  public String getText() {
    return textarea.getText();
  }

  /**
   * Replace the entire contents of this tab.
   */
  public void setText(String what) {
    textarea.setText(what);
  }

  /**
   * Is the text modified since the last save / load?
   */
  public boolean isModified() {
    return modified;
  }

  /**
   * Clear modified status. Should only be called by SketchCode through
   * the TextStorage interface.
   */
  public void clearModified() {
    setModified(false);
  }

  private void setModified(boolean value) {
    if (value != modified) {
      modified = value;
      // TODO: Improve decoupling
      editor.getSketch().calcModified();
    }
  }

  public String getSelectedText() {
    return textarea.getSelectedText();
  }


  public void setSelectedText(String what) {
    textarea.replaceSelection(what);
  }

  public void setSelection(int start, int stop) {
    textarea.select(start, stop);
  }
  
  public int getScrollPosition() {
    return scrollPane.getVerticalScrollBar().getValue();
  }
    
  public void setScrollPosition(int pos) {
    scrollPane.getVerticalScrollBar().setValue(pos);
  }

  /**
   * Get the beginning point of the current selection.
   */
  public int getSelectionStart() {
    return textarea.getSelectionStart();
  }

  /**
   * Get the end point of the current selection.
   */
  public int getSelectionStop() {
    return textarea.getSelectionEnd();
  }

  /**
   * Get text for a specified line.
   */
  public String getLineText(int line) {
    try {
      return textarea.getText(textarea.getLineStartOffset(line), textarea.getLineEndOffset(line));
    } catch (BadLocationException e) {
      return "";
    }
  }

  /**
   * Jump to the given line
   * @param line The line number to jump to, 1-based. 
   */
  public void goToLine(int line) {
    if (line <= 0) {
      return;
    }
    try {
      textarea.setCaretPosition(textarea.getLineStartOffset(line - 1));
    } catch (BadLocationException e) {
      //ignore
    }
  }
  
  void handleCut() {
    textarea.cut();
  }
 
  void handleCopy() {
    textarea.copy();
  }
  
  void handlePaste() {
    textarea.paste();
  }
  
  void handleSelectAll() {
    textarea.selectAll();
  }

  void handleCommentUncomment() {
    Action action = textarea.getActionMap().get(RSyntaxTextAreaEditorKit.rstaToggleCommentAction);
    action.actionPerformed(null);

  }

  void handleDiscourseCopy() {
    new DiscourseFormat(editor, this, false).show();
  }


  void handleHTMLCopy() {
    new DiscourseFormat(editor, this, true).show();
  }

  void handleIndentOutdent(boolean indent) {
    if (indent) {
      Action action = textarea.getActionMap().get(SketchTextAreaEditorKit.rtaIncreaseIndentAction);
      action.actionPerformed(null);
    } else {
      Action action = textarea.getActionMap().get(RSyntaxTextAreaEditorKit.rstaDecreaseIndentAction);
      action.actionPerformed(null);
    }
  }

  void handleUndo() {
    textarea.undoLastAction();
  }
  
  void handleRedo() {
    textarea.redoLastAction();
  }
  
  public UndoManager getUndoManager() {
    return textarea.getUndoManager();
  }
  
  public String getCurrentKeyword() {
    String text = "";
    if (textarea.getSelectedText() != null)
      text = textarea.getSelectedText().trim();

    try {
      int current = textarea.getCaretPosition();
      int startOffset = 0;
      int endIndex = current;
      String tmp = textarea.getDocument().getText(current, 1);
      // TODO probably a regexp that matches Arduino lang special chars
      // already exists.
      String regexp = "[\\s\\n();\\\\.!='\\[\\]{}]";

      while (!tmp.matches(regexp)) {
        endIndex++;
        tmp = textarea.getDocument().getText(endIndex, 1);
      }
      // For some reason document index start at 2.
      // if( current - start < 2 ) return;

      tmp = "";
      while (!tmp.matches(regexp)) {
        startOffset++;
        if (current - startOffset < 0) {
          tmp = textarea.getDocument().getText(0, 1);
          break;
        } else
          tmp = textarea.getDocument().getText(current - startOffset, 1);
      }
      startOffset--;

      int length = endIndex - current + startOffset;
      text = textarea.getDocument().getText(current - startOffset, length);

    } catch (BadLocationException bl) {
      bl.printStackTrace();
    }
    return text;
  }

  @Override
  public void requestFocus() {
    /** If focus is requested, focus the textarea instead. */
    textarea.requestFocus();
  }

}