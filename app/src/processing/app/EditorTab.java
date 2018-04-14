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
import static processing.app.Theme.scale;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseWheelListener;
import java.awt.event.MouseWheelEvent;

import java.io.IOException;

import javax.swing.Action;
import javax.swing.BorderFactory;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.ToolTipManager;
import javax.swing.border.MatteBorder;
import javax.swing.event.PopupMenuEvent;
import javax.swing.event.PopupMenuListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.Element;
import javax.swing.text.PlainDocument;
import javax.swing.text.DefaultCaret;
import javax.swing.text.Document;

import org.fife.ui.rsyntaxtextarea.RSyntaxDocument;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextAreaEditorKit;
import org.fife.ui.rsyntaxtextarea.RSyntaxUtilities;
import org.fife.ui.rtextarea.Gutter;
import org.fife.ui.rtextarea.RTextScrollPane;

import cc.arduino.UpdatableBoardsLibsFakeURLsHandler;
import processing.app.helpers.DocumentTextChangeListener;
import processing.app.syntax.ArduinoTokenMakerFactory;
import processing.app.syntax.PdeKeywords;
import processing.app.syntax.SketchTextArea;
import processing.app.syntax.SketchTextAreaEditorKit;
import processing.app.tools.DiscourseFormat;

/**
 * Single tab, editing a single file, in the main window.
 */
public class EditorTab extends JPanel implements SketchFile.TextStorage, MouseWheelListener {
  protected Editor editor;
  protected SketchTextArea textarea;
  protected RTextScrollPane scrollPane;
  protected SketchFile file;
  protected boolean modified;
  /** Is external editing mode currently enabled? */
  protected boolean external;
  
  /**
   * Create a new EditorTab
   *
   * @param editor
   *          The Editor this tab runs in
   * @param file
   *          The file to display in this tab
   * @param contents
   *          Initial contents to display in this tab. Can be used when editing
   *          a file that doesn't exist yet. If null is passed, code.load() is
   *          called and displayed instead.
   * @throws IOException
   */
  public EditorTab(Editor editor, SketchFile file, String contents)
      throws IOException {
    super(new BorderLayout());

    // Load initial contents contents from file if nothing was specified.
    if (contents == null) {
      contents = file.load();
      modified = false;
    } else {
      modified = true;
    }

    this.editor = editor;
    this.file = file;
    RSyntaxDocument document = createDocument(contents);
    textarea = createTextArea(document);
    scrollPane = createScrollPane(textarea);
    file.setStorage(this);
    applyPreferences();
    add(scrollPane, BorderLayout.CENTER);
	textarea.addMouseWheelListener(this);
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
    textArea.setAutoIndentEnabled(PreferencesData.getBoolean("editor.indent"));
    textArea.setCloseCurlyBraces(PreferencesData.getBoolean("editor.auto_close_braces", true));
    textArea.setAntiAliasingEnabled(PreferencesData.getBoolean("editor.antialias"));
    textArea.setTabsEmulated(PreferencesData.getBoolean("editor.tabs.expand"));
    textArea.setTabSize(PreferencesData.getInteger("editor.tabs.size"));
    textArea.addHyperlinkListener(evt -> {
      try {
        UpdatableBoardsLibsFakeURLsHandler boardLibHandler = new UpdatableBoardsLibsFakeURLsHandler(editor.base);
        boardLibHandler.openBoardLibManager(evt.getURL());
      }
      catch (Exception e) {
        try {
          editor.platform.openURL(editor.getSketch().getFolder(), evt.getURL().toExternalForm());
        } catch (Exception f) {
          Base.showWarning(f.getMessage(), f.getMessage(), f);
        }
      }
    });
    textArea.addCaretListener(e -> {
      Element root = textArea.getDocument().getDefaultRootElement();
      int lineStart = root.getElementIndex(e.getMark());
      int lineEnd = root.getElementIndex(e.getDot());

      editor.lineStatus.set(lineStart, lineEnd);
    });
    ToolTipManager.sharedInstance().registerComponent(textArea);

    configurePopupMenu(textArea);
    return textArea;
  }
  
  public void mouseWheelMoved(MouseWheelEvent e) {
    if (e.isControlDown()) {
      if (e.getWheelRotation() < 0) {
        editor.base.handleFontSizeChange(1);
      } else {
        editor.base.handleFontSizeChange(-1);
      }
    } else {
      e.getComponent().getParent().dispatchEvent(e);
    }
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

    // apply the setting for 'use external editor', but only if it changed
    if (external != PreferencesData.getBoolean("editor.external")) {
      external = !external;
      if (external) {
        // disable line highlight and turn off the caret when disabling
        textarea.setBackground(Theme.getColor("editor.external.bgcolor"));
        textarea.setHighlightCurrentLine(false);
        textarea.setEditable(false);
        // Detach from the code, since we are no longer the authoritative source
        // for file contents.
        file.setStorage(null);
        // Reload, in case the file contents already changed.
        reload();
      } else {
        textarea.setBackground(Theme.getColor("editor.bgcolor"));
        textarea.setHighlightCurrentLine(Theme.getBoolean("editor.linehighlight"));
        textarea.setEditable(true);
        file.setStorage(this);
        // Reload once just before disabling external mode, to ensure we have
        // the latest contents.
        reload();
      }
    }
    // apply changes to the font size for the editor
    Font editorFont = scale(PreferencesData.getFont("editor.font"));
    textarea.setFont(editorFont);
    scrollPane.getGutter().setLineNumberFont(editorFont);
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
   * Called when this tab is made the current one, or when it is the current one
   * and the window is activated.
   */
  public void activated() {
    // When external editing is enabled, reload the text whenever we get activated.
    if (external) {
      reload();
    }
  }

  /**
   * Reload the contents of our file.
   */
  public void reload() {
    String text;
    try {
      text = file.load();
    } catch (IOException e) {
      System.err.println(I18n.format("Warning: Failed to reload file: \"{0}\"",
                                     file.getFileName()));
      return;
    }
    setText(text);
    setModified(false);
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
  public SketchController getSketch() {
    return editor.getSketchController();
  }
  
  /**
   * Get the SketchFile that is being edited in this tab.
   */
  public SketchFile getSketchFile() {
    return this.file;
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
    // Remove all highlights, since these will all end up at the start of the
    // text otherwise. Preserving them is tricky, so better just remove them.
    textarea.removeAllLineHighlights();
    // Set the caret update policy to NEVER_UPDATE while completely replacing
    // the current text. Normally, the caret tracks inserts and deletions, but
    // replacing the entire text will always make the caret end up at the end,
    // which isn't really useful. With NEVER_UPDATE, the caret will just keep
    // its absolute position (number of characters from the start), which isn't
    // always perfect, but the best we can do without making a diff of the old
    // and new text and some guesswork.
    // Note that we cannot use textarea.setText() here, since that first removes
    // text and then inserts the new text. Even with NEVER_UPDATE, the caret
    // always makes sure to stay valid, so first removing all text makes it
    // reset to 0. Also note that simply saving and restoring the caret position
    // will work, but then the scroll position might change in response to the
    // caret position.
    DefaultCaret caret = (DefaultCaret) textarea.getCaret();
    int policy = caret.getUpdatePolicy();
    caret.setUpdatePolicy(DefaultCaret.NEVER_UPDATE);
    try {
      Document doc = textarea.getDocument();
      int oldLength = doc.getLength();
      // The undo manager already seems to group the insert and remove together
      // automatically, but better be explicit about it.
      textarea.beginAtomicEdit();
      try {
        doc.insertString(oldLength, what, null);
        doc.remove(0, oldLength);
      } catch (BadLocationException e) {
        System.err.println("Unexpected failure replacing text");
      } finally {
        textarea.endAtomicEdit();
      }
    } finally {
      caret.setUpdatePolicy(policy);
    }
  }

  /**
   * Is the text modified since the last save / load?
   */
  public boolean isModified() {
    return modified;
  }

  /**
   * Clear modified status. Should only be called by SketchFile through the
   * TextStorage interface.
   */
  public void clearModified() {
    setModified(false);
  }

  private void setModified(boolean value) {
    if (value != modified) {
      modified = value;
      // TODO: Improve decoupling
      editor.getSketchController().calcModified();
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
    // XXX: RSyntaxDocument doesn't fire DocumentListener events, it should be fixed in RSyntaxTextArea?
    editor.updateUndoRedoState();
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
    // XXX: RSyntaxDocument doesn't fire DocumentListener events, it should be fixed in RSyntaxTextArea?
    editor.updateUndoRedoState();
  }

  void handleUndo() {
    textarea.undoLastAction();
  }
  
  void handleRedo() {
    textarea.redoLastAction();
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
  public boolean requestFocusInWindow() {
    /** If focus is requested, focus the textarea instead. */
    return textarea.requestFocusInWindow();
  }

}
