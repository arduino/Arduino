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

import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;

import processing.app.ToolButton.Range;


/**
 * run/stop/etc buttons for the ide
 */
public class EditorToolbar extends JComponent implements MouseInputListener,
    KeyListener, ToolButtonMetrics {
  /** Rollover titles for each button. */
  private static final long serialVersionUID = 1L;

  public static Color bgcolor;
  static Color statusColor;
  static Font statusFont;

  static {
    bgcolor = Theme.getColor("buttons.bgcolor");
    statusFont = Theme.getFont("buttons.status.font");
    statusColor = Theme.getColor("buttons.status.color");
  }

  // .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. ..
  
  List<ToolButton> allButtons = null;
  ToolButton currentRolloverBtn;
  Map<ButtonID, ToolButton> buttonsById = null;
  
  Editor editor;

  Image offscreen = null;
  int width, height;

  JPopupMenu popup;
  JMenu menu;
  boolean shiftPressed;

  private ToolButton btnOpen; // used often

  // .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. ..

  public EditorToolbar(Editor editor, JMenu menu) {
    this.editor = editor;
    this.menu = menu;
    currentRolloverBtn = null;

    allButtons = new ArrayList<ToolButton>();

    addMouseListener(this);
    addMouseMotionListener(this);
  }

  @Override
  public void paintComponent(Graphics screen) {

    createToolButtons();
    adjustHorizontalPositions();

    Graphics g = offscreen.getGraphics();
    renderButtons(g);
    renderHelpText(g, shiftPressed);
    updateScreenWithRenderedBuffer(screen);
    FillOnDisabledToolbar(screen); // TODO: [acd] Could this be done before any rendering?
  }

  private void createToolButtons() {

    if (buttonsById == null) {
      // once per instance of EditorToolbar
      buttonsById = new HashMap<ButtonID, ToolButton>();

      addToolButton(new ToolButton(ButtonID.NEW));
      addToolButton(new ToolButton(ButtonID.OPEN));
      addToolButton(new ToolButton(ButtonID.SAVE));
      addToolButton(new ToolButton(ButtonID.RUN, ButtonGAP));
      addToolButton(new ToolButton(ButtonID.EXPORT));
      addToolButton(new ToolButton(ButtonID.SERIAL, RightJUSTIFIED));

      btnOpen = buttonsById.get(ButtonID.OPEN);

      // ...the Graphics context exists now, so...
      ToolButtonImage.loadButtons(this);
    }
  }

  private ToolButton indexToolButton(ToolButton button) {
    buttonsById.put(button.getId(), button);
    return button;
  }

  private void addToolButton(ToolButton button) {
    button.setToolbarPosition(allButtons.size());
    allButtons.add(indexToolButton(button));
  }

  private void adjustHorizontalPositions() {
    Dimension size = getSize();
    if ((offscreen == null) || (size.width != width) || (size.height != height)) {
      offscreen = createImage(size.width, size.height);
      width = size.width;
      height = size.height;

      setHorizontalPositions();
    }
  }

  public void setHorizontalPositions() {
    int offsetX = 3;
    int rightOffsetX = width - 14;

    Range x = new Range();

    for (ToolButton button : allButtons) {
      if (button.isRightJustified()) {
        x.start = (rightOffsetX -= ButtonWIDTH);
        x.end = x.start + ButtonWIDTH;
      } else {
        x.start = offsetX + button.getGap();
        x.end = x.start + ButtonWIDTH;
        offsetX = x.end;
      }

      button.setXRange(x);
    }

    offsetX += ButtonGAP;
    rightOffsetX -= ButtonGAP;

    for (ToolButton button : allButtons) {
      button.setHelpTextPosition(button.isRightJustified() ? rightOffsetX
          : offsetX);
    }
  }

  private void renderButtons(Graphics g) {
    g.setColor(bgcolor);
    g.fillRect(0, 0, width, height);

    for (ToolButton button : allButtons) {
      button.renderOn(g);
    }
  }

  private void renderHelpText(Graphics g, boolean shiftPressed) {
    if (currentRolloverBtn != null)
      currentRolloverBtn.renderHelpTextOn(g, shiftPressed, statusFont, statusColor);
  }

  private void updateScreenWithRenderedBuffer(Graphics screen) {
    screen.drawImage(offscreen, 0, 0, null);
  }

  private void FillOnDisabledToolbar(Graphics screen) {
    if (!isEnabled()) {
      screen.setColor(new Color(0, 0, 0, 100));
      screen.fillRect(0, 0, getWidth(), getHeight());
    }
  }

  // ////////////////////////////////////////////////////

  @Override
  public void mouseMoved(MouseEvent e) {
    if (!isEnabled())
      return;

    // mouse events before paint();
    if (!ToolButtonImage.isLoaded())
      return;

    if (btnOpen.getState() != State.INACTIVE) {
      setState(btnOpen.getToolbarPosition(), State.INACTIVE, false);
    }

    handleMouse(e);
  }

  @Override
  public void mouseDragged(MouseEvent e) {
  }

  public void handleMouse(MouseEvent e) {

    Point clickPosition = new Point(e.getX(), e.getY());

    if (currentRolloverBtn != null) { // then a tool might have been active
      if (currentRolloverBtn.contains(clickPosition)) {
        return;
      } else {
        setState(currentRolloverBtn.getToolbarPosition(), State.INACTIVE, true);
        currentRolloverBtn = null;
      }
    }

    ToolButton newButton;
    if ((newButton = getClickedButton(clickPosition)) == null)
      return;

    if (newButton.getState() != State.ACTIVE) {
      setState(newButton.getToolbarPosition(), State.ROLLOVER, true);
      currentRolloverBtn = newButton;
    }
  }

  private ToolButton getClickedButton(final Point position) {

    ToolButton foundButton = null;

    // if app loads slowly and cursor is near the buttons
    // when it comes up, the app may not have time to load
    if (ToolButtonImage.isLoaded()) {

      for (ToolButton button : allButtons) {
        if (button.contains(position)) {
          foundButton = button;
          break;
        }
      }
    }

    return foundButton;
  }

  private void setState(int index, State newState, boolean updateAfter) {
    ToolButton button = allButtons.get(index);
    button.setState(newState);
    if (updateAfter) {
      repaint();
    }
  }

  private void setState(ButtonID id, State newState, boolean updateAfter) {
    setState(buttonsById.get(id).getToolbarPosition(), newState, updateAfter);
  }

  @Override
  public void mouseEntered(MouseEvent e) {
    handleMouse(e);
  }

  @Override
  public void mouseExited(MouseEvent e) {
    // if the popup menu for is visible, don't register this,
    // because the popup being set visible will fire a mouseExited() event
    if ((popup != null) && popup.isVisible())
      return;

    if (btnOpen.getState() != State.INACTIVE) {
      setState(btnOpen.getToolbarPosition(), State.INACTIVE, true);
    }

    handleMouse(e);
  }

  int wasDown = -1;

  @Override
  public void mousePressed(MouseEvent e) {
    
    // jdf
    if (!isEnabled())
      return;

    final Point clickPosition = new Point(e.getX(), e.getY());

    ToolButton clickedButton;

    if ((clickedButton = getClickedButton(clickPosition)) == null)
      return;

    currentRolloverBtn = null;

    switch (clickedButton.getId()) {
    case RUN:
      doClickRun();
      break;
    case OPEN:
      doClickOpen(clickPosition);
      break;
    case NEW:
      doClickNew();
      break;
    case SAVE:
      doClickSAVE();
      break;
    case EXPORT:
      doClickExport();
      break;
    case SERIAL:
      doClickSerial();
      break;
      // case STOP:
      // editor.handleStop();
      // break;
    default:
      break;
    }
  }

  private void doClickRun() {
    editor.handleRun(false);
  }

  private void doClickOpen(final Point clickPosition) {
    popup = menu.getPopupMenu();
    popup.show(EditorToolbar.this, clickPosition.x, clickPosition.y);
  }

  private void doClickNew() {
    if (shiftPressed) {
      try {
        editor.base.handleNew();
      } catch (Exception e1) {
        e1.printStackTrace();
      }
    } else {
      editor.base.handleNewReplace();
    }
  }

  private void doClickSAVE() {
    editor.handleSave(false);
  }

  private void doClickExport() {
    editor.handleExport(shiftPressed);
  }

  private void doClickSerial() {
    editor.handleSerial();
  }

  @Override
  public void mouseClicked(MouseEvent e) {
  }

  @Override
  public void mouseReleased(MouseEvent e) {
  }

  /**
   * Set a particular button to be active.
   */
  public void activate(ButtonID what) {
    if (ToolButtonImage.isLoaded()) {
      setState(what, State.ACTIVE, true);
    }
  }

  /**
   * Set a particular button to be active.
   */
  public void deactivate(ButtonID what) {
    if (ToolButtonImage.isLoaded()) {
      setState(what, State.INACTIVE, true);
    }
  }

  @Override
  public Dimension getPreferredSize() {
    return getMinimumSize();
  }

  @Override
  public Dimension getMinimumSize() {
    return new Dimension((allButtons.size() + 1) * ButtonWIDTH, ButtonHEIGHT);
  }

  @Override
  public Dimension getMaximumSize() {
    return new Dimension(3000, ButtonHEIGHT);
  }

  
  @Override
  public void keyPressed(KeyEvent e) {
    if (e.getKeyCode() == KeyEvent.VK_SHIFT) {
      shiftPressed = true;
      repaint();
    }
  }

  @Override
  public void keyReleased(KeyEvent e) {
    if (e.getKeyCode() == KeyEvent.VK_SHIFT) {
      shiftPressed = false;
      repaint();
    }
  }

  @Override
  public void keyTyped(KeyEvent e) {
  }

  // /////////////////////////////////////////////////////
  // /////////////////////////////////////////////////////

}
