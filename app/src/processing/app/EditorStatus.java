/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-08 Ben Fry and Casey Reas
  Copyright (c) 2001-04 Massachusetts Institute of Technology

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package processing.app;

import processing.app.helpers.OSUtils;
import cc.arduino.CompilerProgressListener;

import javax.swing.*;
import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

/**
 * Panel just below the editing area that contains status messages.
 */
public class EditorStatus extends JPanel {

  private static final int NOTICE = 0;
  private static final int ERR = 1;
  private static final int EDIT = 2;
  private static final int PROGRESS = 5;
  private static final String NO_MESSAGE = "";

  private static final Color[] BGCOLOR;
  private static final Color[] FGCOLOR;

  static {
    BGCOLOR = new Color[6];
    BGCOLOR[0] = Theme.getColor("status.notice.bgcolor");
    BGCOLOR[1] = Theme.getColor("status.error.bgcolor");
    BGCOLOR[2] = Theme.getColor("status.edit.bgcolor");
    BGCOLOR[3] = null;
    BGCOLOR[4] = null;
    BGCOLOR[5] = Theme.getColor("status.notice.bgcolor");

    FGCOLOR = new Color[6];
    FGCOLOR[0] = Theme.getColor("status.notice.fgcolor");
    FGCOLOR[1] = Theme.getColor("status.error.fgcolor");
    FGCOLOR[2] = Theme.getColor("status.edit.fgcolor");
    FGCOLOR[3] = null;
    FGCOLOR[4] = null;
    FGCOLOR[5] = Theme.getColor("status.notice.fgcolor");
  }

  // value for the size bars, buttons, etc
  // TODO: Should be a Theme value?
  static final int GRID_SIZE = 33;

  private final Editor editor;
  private final Font font;

  private int mode;
  private String message;

  private Image offscreen;
  private int sizeW;
  private int sizeH;
  private int imageW;
  private int imageH;

  private JButton cancelButton;
  private JButton okButton;
  private JTextField editField;
  private JProgressBar progressBar;
  private JButton copyErrorButton;
  
  private ArrayList<CompilerProgressListener> compilerProgressListeners;

  public EditorStatus(Editor editor) {
    this.editor = editor;
    this.message = NO_MESSAGE;
    this.mode = NOTICE;
    this.font = Theme.getFont("status.font");
    this.compilerProgressListeners = new ArrayList<>();
    this.compilerProgressListeners.add(this::progressUpdate);
    initialize();
  }

  public void clearState() {
    changeState(NOTICE);
    repaint();
  }

  private void changeState(int newMode) {
    if (mode == newMode) {
      return;
    }

    mode = newMode;

    if (cancelButton.isVisible()) {
      cancelButton.doClick();
    }
    cancelButton.setVisible(false);
    okButton.setVisible(false);
    editField.setVisible(false);
    progressBar.setVisible(false);
    copyErrorButton.setVisible(false);
    message = NO_MESSAGE;
  }

  public void notice(String message) {
    changeState(NOTICE);
    this.message = message;
    if (copyErrorButton != null) {
      copyErrorButton.setVisible(false);
    }
    repaint();
  }

  public void error(String message) {
    changeState(ERR);
    this.message = message;
    if (copyErrorButton != null) {
      copyErrorButton.setVisible(true);
    }
    repaint();
  }

  public void edit(String message, String dflt) {
    changeState(EDIT);
    this.message = message;

    okButton.setVisible(true);
    cancelButton.setVisible(true);
    editField.setVisible(true);
    editField.setText(dflt);
    editField.selectAll();
    editField.requestFocusInWindow();

    repaint();
  }

  private void unedit() {
    okButton.setVisible(false);
    cancelButton.setVisible(false);
    editField.setVisible(false);
    clearState();
    repaint();
  }

  public void progress(String message) {
    changeState(PROGRESS);
    this.message = message;
    progressBar.setIndeterminate(false);
    progressBar.setVisible(true);
    copyErrorButton.setVisible(false);
    setCursor(Cursor.getPredefinedCursor(Cursor.WAIT_CURSOR));
    repaint();
  }

  public void progressNotice(String message) {
    this.message = message;
    repaint();
  }

  public void unprogress() {
    if (PreferencesData.getBoolean("editor.beep.compile")) {
      Toolkit.getDefaultToolkit().beep();
    }
    if (progressBar == null) {
      return;
    }
    progressBar.setVisible(false);
    progressBar.setValue(0);
    setCursor(null);
  }

  public void progressUpdate(int value) {
    if (progressBar == null) return;
    progressBar.setValue(value);
    repaint();
  }

  public void paintComponent(Graphics screen) {
    Dimension size = getSize();
    if ((size.width != sizeW) || (size.height != sizeH)) {
      // component has been resized

      if ((size.width > imageW) || (size.height > imageH)) {
        // nix the image and recreate, it's too small
        offscreen = null;

      } else {
        // who cares, just resize
        sizeW = size.width;
        sizeH = size.height;
        setButtonBounds();
      }
    }

    if (offscreen == null) {
      sizeW = size.width;
      sizeH = size.height;
      setButtonBounds();
      imageW = sizeW;
      imageH = sizeH;
      offscreen = createImage(imageW, imageH);
    }

    Graphics2D g = Theme.setupGraphics2D(offscreen.getGraphics());
    g.setColor(BGCOLOR[mode]);
    g.fillRect(0, 0, imageW, imageH);
    g.setColor(FGCOLOR[mode]);

    g.setFont(font); // needs to be set each time on osx
    int ascent = g.getFontMetrics().getAscent();
    assert message != null;
    g.drawString(message, Preferences.GUI_SMALL, (sizeH + ascent) / 2);

    screen.drawImage(offscreen, 0, 0, null);
  }

  private void initialize() {
    cancelButton = new JButton(I18n.PROMPT_CANCEL);
    okButton = new JButton(I18n.PROMPT_OK);

    cancelButton.addActionListener(e -> {
      if (mode == EDIT) {
        unedit();
      }
    });

    okButton.addActionListener(e -> {
      // answering to rename/new code question
      if (mode == EDIT) {  // this if() isn't (shouldn't be?) necessary
        String answer = editField.getText();
        editor.getSketchController().nameCode(answer);
        unedit();
      }
    });

    if (OSUtils.isMacOS()) {
      cancelButton.setBackground(BGCOLOR[EDIT]);
      okButton.setBackground(BGCOLOR[EDIT]);
    }
    setLayout(null);

    add(cancelButton);
    add(okButton);

    cancelButton.setVisible(false);
    okButton.setVisible(false);

    editField = new JTextField();

    editField.addKeyListener(new KeyAdapter() {

      // Grab ESC with keyPressed, because it's not making it to keyTyped
      public void keyPressed(KeyEvent event) {
        if (event.getKeyChar() == KeyEvent.VK_ESCAPE) {
          unedit();
          event.consume();
        }
      }

      // use keyTyped to catch when the feller is actually
      // added to the text field. with keyTyped, as opposed to
      // keyPressed, the keyCode will be zero, even if it's
      // enter or backspace or whatever, so the keychar should
      // be used instead. grr.
      public void keyTyped(KeyEvent event) {
        int c = event.getKeyChar();

        if (c == KeyEvent.VK_ENTER) {  // accept the input
          String answer = editField.getText();
          editor.getSketchController().nameCode(answer);
          unedit();
          event.consume();

          // easier to test the affirmative case than the negative
        } else if ((c == KeyEvent.VK_BACK_SPACE) ||
          (c == KeyEvent.VK_DELETE) ||
          (c == KeyEvent.VK_RIGHT) ||
          (c == KeyEvent.VK_LEFT) ||
          (c == KeyEvent.VK_UP) ||
          (c == KeyEvent.VK_DOWN) ||
          (c == KeyEvent.VK_HOME) ||
          (c == KeyEvent.VK_END) ||
          (c == KeyEvent.VK_SHIFT)) {
          // these events are ignored

        } else if (c == KeyEvent.VK_SPACE) {
          String t = editField.getText();
          int start = editField.getSelectionStart();
          int end = editField.getSelectionEnd();
          editField.setText(t.substring(0, start) + "_" +
            t.substring(end));
          editField.setCaretPosition(start + 1);
          event.consume();

        } else if ((c == '_') || (c == '.') || ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) { // allow .pde and .java
          // these are ok, allow them through

        } else if ((c >= '0') && (c <= '9')) {
          // these are ok, allow them through

        } else {
          event.consume();
        }
      }
    });
    add(editField);
    editField.setVisible(false);

    progressBar = new JProgressBar(JScrollBar.HORIZONTAL);
    progressBar.setIndeterminate(false);
    progressBar.setValue(0);
    progressBar.setBorderPainted(true);
    add(progressBar);
    progressBar.setVisible(false);

    copyErrorButton = new JButton(tr("Copy error messages"));
    add(copyErrorButton);
    copyErrorButton.setVisible(false);
    copyErrorButton.addActionListener(e -> {
      String message1 = "";
      message1 += tr("Arduino: ") + BaseNoGui.VERSION_NAME_LONG + " (" + System.getProperty("os.name") + "), ";
      message1 += tr("Board: ") + "\"" + BaseNoGui.getBoardPreferences().get("name") + "\"\n\n";
      message1 += editor.console.getText();
      if (!(PreferencesData.getBoolean("build.verbose"))) {
        message1 += "\n\n";
        message1 += tr("This report would have more information with\n" +
                       "\"Show verbose output during compilation\"\n" +
                       "option enabled in File -> Preferences.\n");
      }
      Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
      StringSelection data = new StringSelection(message1);
      clipboard.setContents(data, null);
      Clipboard unixclipboard = Toolkit.getDefaultToolkit().getSystemSelection();
      if (unixclipboard != null) {
        unixclipboard.setContents(data, null);
      }
    });
  }


  private void setButtonBounds() {
    int top = (sizeH - Preferences.BUTTON_HEIGHT) / 2;
    int eachButton = Preferences.GUI_SMALL + Preferences.BUTTON_WIDTH;

    int cancelLeft = sizeW - eachButton;
    int noLeft = cancelLeft - eachButton;
    int yesLeft = noLeft - eachButton;

    cancelButton.setLocation(cancelLeft, top);
    okButton.setLocation(noLeft, top);
    progressBar.setLocation(noLeft, top);

    cancelButton.setSize(Preferences.BUTTON_WIDTH, Preferences.BUTTON_HEIGHT);
    okButton.setSize(Preferences.BUTTON_WIDTH, Preferences.BUTTON_HEIGHT);
    progressBar.setSize(2 * Preferences.BUTTON_WIDTH, Preferences.BUTTON_HEIGHT);

    // edit field height is awkward, and very different between mac and pc,
    // so use at least the preferred height for now.
    int editWidth = 2 * Preferences.BUTTON_WIDTH;
    int editHeight = editField.getPreferredSize().height;
    int editTop = (1 + sizeH - editHeight) / 2;  // add 1 for ceil
    editField.setBounds(yesLeft - Preferences.BUTTON_WIDTH, editTop, editWidth, editHeight);
    progressBar.setBounds(noLeft, editTop, editWidth, editHeight);

    Dimension copyErrorButtonSize = copyErrorButton.getPreferredSize();
    copyErrorButton.setLocation(sizeW - copyErrorButtonSize.width - 5, top);
    copyErrorButton.setSize(copyErrorButtonSize.width, Preferences.BUTTON_HEIGHT);
  }

  public Dimension getPreferredSize() {
    return getMinimumSize();
  }

  public Dimension getMinimumSize() {
    return scale(new Dimension(300, GRID_SIZE));
  }

  public Dimension getMaximumSize() {
    return scale(new Dimension(3000, GRID_SIZE));
  }

  public boolean isErr() {
    return mode == ERR;
  }
  
  public void addCompilerProgressListener(CompilerProgressListener listener){
    compilerProgressListeners.add(listener);
  }
  
  public ArrayList<CompilerProgressListener> getCompilerProgressListeners(){
    return compilerProgressListeners;
  }

}
