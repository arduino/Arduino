/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

  Copyright (c) 2004-09 Ben Fry and Casey Reas
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

import javax.swing.*;
import javax.swing.event.MouseInputListener;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

/**
 * run/stop/etc buttons for the ide
 */
public class EditorToolbar extends JComponent implements MouseInputListener, KeyEventDispatcher {

  /**
   * Rollover titles for each button.
   */
  private static final String[] title = {
    tr("Verify"), tr("Upload"), tr("New"), tr("Open"), tr("Save"), tr("Serial Monitor")
  };

  /**
   * Titles for each button when the shift key is pressed.
   */
  private static final String[] titleShift = {
    tr("Verify"), tr("Upload Using Programmer"), tr("New"), tr("Open"), tr("Save As..."), tr("Serial Monitor")
  };

  private static final int BUTTON_COUNT = title.length;
  /**
   * Width of each toolbar button.
   */
  private static final int BUTTON_WIDTH = scale(27);
  /**
   * Height of each toolbar button.
   */
  private static final int BUTTON_HEIGHT = scale(32);
  /**
   * The amount of space between groups of buttons on the toolbar.
   */
  private static final int BUTTON_GAP = scale(5);
  /**
   * Size of the button image being chopped up.
   */
  private static final int BUTTON_IMAGE_SIZE = scale(33);


  private static final int RUN = 0;
  private static final int EXPORT = 1;

  private static final int NEW = 2;
  private static final int OPEN = 3;
  private static final int SAVE = 4;

  private static final int SERIAL = 5;

  private static final int INACTIVE = 0;
  private static final int ROLLOVER = 1;
  private static final int ACTIVE = 2;

  private final Editor editor;

  private Image offscreen;
  private int width;
  private int height;

  private final Color bgcolor;

  private static Image[][] buttonImages;
  private int currentRollover;

  private JPopupMenu popup;
  private final JMenu menu;

  private int buttonCount;
  private int[] state = new int[BUTTON_COUNT];
  private Image[] stateImage;
  private final int[] which; // mapping indices to implementation

  private int[] x1;
  private int[] x2;
  private int y1;
  private int y2;

  private final Font statusFont;
  private final Color statusColor;

  private boolean shiftPressed;

  public EditorToolbar(Editor editor, JMenu menu) {
    this.editor = editor;
    this.menu = menu;

    buttonCount = 0;
    which = new int[BUTTON_COUNT];

    //which[buttonCount++] = NOTHING;
    which[buttonCount++] = RUN;
    which[buttonCount++] = EXPORT;
    which[buttonCount++] = NEW;
    which[buttonCount++] = OPEN;
    which[buttonCount++] = SAVE;
    which[buttonCount++] = SERIAL;

    currentRollover = -1;

    bgcolor = Theme.getColor("buttons.bgcolor");
    statusFont = Theme.getFont("buttons.status.font");
    statusColor = Theme.getColor("buttons.status.color");

    addMouseListener(this);
    addMouseMotionListener(this);
    KeyboardFocusManager.getCurrentKeyboardFocusManager().addKeyEventDispatcher(this);
  }

  private void loadButtons() {
    Image allButtons = Theme.getThemeImage("buttons", this,
                                           BUTTON_IMAGE_SIZE * BUTTON_COUNT,
                                           BUTTON_IMAGE_SIZE * 3);
    buttonImages = new Image[BUTTON_COUNT][3];

    for (int i = 0; i < BUTTON_COUNT; i++) {
      for (int state = 0; state < 3; state++) {
        Image image = createImage(BUTTON_WIDTH, BUTTON_HEIGHT);
        Graphics g = image.getGraphics();
        g.setColor(bgcolor);
        g.fillRect(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
        int offset = (BUTTON_IMAGE_SIZE - BUTTON_WIDTH) / 2;
        g.drawImage(allButtons, -(i * BUTTON_IMAGE_SIZE) - offset,
                    (-2 + state) * BUTTON_IMAGE_SIZE, null);
        buttonImages[i][state] = image;
      }
    }
  }

  @Override
  public void paintComponent(Graphics screen) {
    // this data is shared by all EditorToolbar instances
    if (buttonImages == null) {
      loadButtons();
    }

    // this happens once per instance of EditorToolbar
    if (stateImage == null) {
      state = new int[buttonCount];
      stateImage = new Image[buttonCount];
      for (int i = 0; i < buttonCount; i++) {
        setState(i, INACTIVE, false);
      }
      y1 = 0;
      y2 = BUTTON_HEIGHT;
      x1 = new int[buttonCount];
      x2 = new int[buttonCount];
    }

    Dimension size = getSize();
    if ((offscreen == null) ||
      (size.width != width) || (size.height != height)) {
      offscreen = createImage(size.width, size.height);
      width = size.width;
      height = size.height;

      int offsetX = 3;
      for (int i = 0; i < buttonCount; i++) {
        x1[i] = offsetX;
        if (i == 2 || i == 6) x1[i] += BUTTON_GAP;
        x2[i] = x1[i] + BUTTON_WIDTH;
        offsetX = x2[i];
      }

      // Serial button must be on the right
      x1[SERIAL] = width - BUTTON_WIDTH - 14;
      x2[SERIAL] = width - 14;
    }
    Graphics2D g = Theme.setupGraphics2D(offscreen.getGraphics());
    g.setColor(bgcolor); //getBackground());
    g.fillRect(0, 0, width, height);

    for (int i = 0; i < buttonCount; i++) {
      g.drawImage(stateImage[i], x1[i], y1, null);
    }

    g.setColor(statusColor);
    g.setFont(statusFont);

    /*
    // if i ever find the guy who wrote the java2d api, i will hurt him.
     * 
     * whereas I love the Java2D API. --jdf. lol.
     * 
    Graphics2D g2 = (Graphics2D) g;
    FontRenderContext frc = g2.getFontRenderContext();
    float statusW = (float) statusFont.getStringBounds(status, frc).getWidth();
    float statusX = (getSize().width - statusW) / 2;
    g2.drawString(status, statusX, statusY);
    */
    if (currentRollover != -1) {
      int statusY = (BUTTON_HEIGHT + g.getFontMetrics().getAscent()) / 2;
      String status = shiftPressed ? titleShift[currentRollover] : title[currentRollover];
      if (currentRollover != SERIAL)
        g.drawString(status, (buttonCount - 1) * BUTTON_WIDTH + 3 * BUTTON_GAP, statusY);
      else {
        int statusX = x1[SERIAL] - BUTTON_GAP;
        statusX -= g.getFontMetrics().stringWidth(status);
        g.drawString(status, statusX, statusY);
      }
    }

    screen.drawImage(offscreen, 0, 0, null);

    if (!isEnabled()) {
      screen.setColor(new Color(0, 0, 0, 100));
      screen.fillRect(0, 0, getWidth(), getHeight());
    }
  }


  public void mouseMoved(MouseEvent e) {
    if (!isEnabled())
      return;

    // mouse events before paint();
    if (state == null) return;

    if (state[OPEN] != INACTIVE) {
      // avoid flicker, since there will probably be an update event
      setState(OPEN, INACTIVE, false);
    }
    handleMouse(e);
  }


  public void mouseDragged(MouseEvent e) {
  }


  private void handleMouse(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();

    if (currentRollover != -1) {
      if ((x > x1[currentRollover]) && (y > y1) &&
        (x < x2[currentRollover]) && (y < y2)) {
        return;

      } else {
        setState(currentRollover, INACTIVE, true);
        currentRollover = -1;
      }
    }
    int sel = findSelection(x, y);
    if (sel == -1) return;

    if (state[sel] != ACTIVE) {
      setState(sel, ROLLOVER, true);
      currentRollover = sel;
    }
  }


  private int findSelection(int x, int y) {
    // if app loads slowly and cursor is near the buttons
    // when it comes up, the app may not have time to load
    if ((x1 == null) || (x2 == null)) return -1;

    for (int i = 0; i < buttonCount; i++) {
      if ((y > y1) && (x > x1[i]) &&
        (y < y2) && (x < x2[i])) {
        //System.out.println("sel is " + i);
        return i;
      }
    }
    return -1;
  }


  private void setState(int slot, int newState, boolean updateAfter) {
    state[slot] = newState;
    stateImage[slot] = buttonImages[which[slot]][newState];
    if (updateAfter) {
      repaint();
    }
  }


  public void mouseEntered(MouseEvent e) {
    handleMouse(e);
  }


  public void mouseExited(MouseEvent e) {
    // if the popup menu for is visible, don't register this,
    // because the popup being set visible will fire a mouseExited() event
    if ((popup != null) && popup.isVisible()) return;

    if (state[OPEN] != INACTIVE) {
      setState(OPEN, INACTIVE, true);
    }
    handleMouse(e);
  }


  public void mousePressed(MouseEvent e) {

    // jdf
    if (!isEnabled())
      return;

    final int x = e.getX();
    final int y = e.getY();

    int sel = findSelection(x, y);
    ///if (sel == -1) return false;
    if (sel == -1) return;
    currentRollover = -1;

    switch (sel) {
      case RUN:
        if (!editor.avoidMultipleOperations) {
          editor.handleRun(false, editor.presentHandler, editor.runHandler);
          editor.avoidMultipleOperations = true;
        }
        break;

//    case STOP:
//      editor.handleStop();
//      break;
//
      case OPEN:
        popup = menu.getPopupMenu();
        popup.show(EditorToolbar.this, x, y);
        break;

      case NEW:
        try {
          editor.base.handleNew();
        } catch (Exception e1) {
          throw new RuntimeException(e1);
        }
        break;

      case SAVE:
        if (e.isShiftDown()) {
          editor.handleSaveAs();
        } else {
          editor.handleSave(false);
        }
        break;

      case EXPORT:
        // launch a timeout timer which can reenable to upload button functionality an
        if (!editor.avoidMultipleOperations) {
          editor.handleExport(e.isShiftDown());
        }
        break;

      case SERIAL:
        editor.handleSerial();
        break;

      default:
        break;
    }
  }


  public void mouseClicked(MouseEvent e) {
  }


  public void mouseReleased(MouseEvent e) {
  }


  /**
   * Set a particular button to be active.
   */
  private void activate(int what) {
    if (buttonImages != null) {
      setState(what, ACTIVE, true);
    }
  }

  public void activateRun() {
    activate(RUN);
  }

  public void activateSave() {
    activate(SAVE);
  }

  public void activateExport() {
    activate(EXPORT);
  }

  /**
   * Set a particular button to be active.
   */
  private void deactivate(int what) {
    if (buttonImages != null) {
      setState(what, INACTIVE, true);
    }
  }

  public void deactivateRun() {
    deactivate(RUN);
  }

  public void deactivateSave() {
    deactivate(SAVE);
  }

  public void deactivateExport() {
    deactivate(EXPORT);
  }

  public Dimension getPreferredSize() {
    return getMinimumSize();
  }


  public Dimension getMinimumSize() {
    return new Dimension((BUTTON_COUNT + 1) * BUTTON_WIDTH, BUTTON_HEIGHT);
  }


  public Dimension getMaximumSize() {
    return new Dimension(scale(30000), BUTTON_HEIGHT);
  }

  public boolean dispatchKeyEvent(final KeyEvent e) {
    if (shiftPressed != e.isShiftDown()) {
      shiftPressed = !shiftPressed;
      repaint();
    }
    // Return false to continue processing this keyEvent
    return false;
  }
}
