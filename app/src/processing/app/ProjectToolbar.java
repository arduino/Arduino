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

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.event.MouseInputListener;

import com.thizzer.jtouchbar.JTouchBar;
import com.thizzer.jtouchbar.item.TouchBarItem;
import com.thizzer.jtouchbar.item.view.TouchBarButton;

import cc.arduino.contributions.VersionComparator;
import processing.app.helpers.OSUtils;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

/**
 * run/stop/etc buttons for the ide
 */
public class ProjectToolbar extends JComponent implements MouseInputListener {

  /**
   * Rollover titles for each button.
   */
  private static final String[] title = {
    tr("Navigate"), tr("Sketch Folder"), tr("Toggle View")
  };

  private static final int BUTTON_COUNT = title.length;
  /**
   * Width of each toolbar button.
   */
  private static final int BUTTON_WIDTH = scale(30);
  /**
   * Height of each toolbar button.
   */
  private static final int BUTTON_HEIGHT = scale(26);
  /**
   * The amount of space between groups of buttons on the toolbar.
   */
  private static final int BUTTON_GAP = scale(6);
  /**
   * Size of the button image being chopped up.
   */
  private static final int BUTTON_IMAGE_SIZE = scale(33);


  private static final int NAVIGATE = 0;
  private static final int SKETCH = 1;
  private static final int TOGGLE = 2;

  private static final int INACTIVE = 0;
  private static final int ROLLOVER = 1;
  private static final int ACTIVE = 2;

  private final Editor editor;

  private Image offscreen;
  private int width;
  private int height;

  private final Color bgcolor;

  private static Image[][] buttonImages;
  private static com.thizzer.jtouchbar.common.Image[][] touchBarImages;
  private int currentRollover;

  private JTouchBar touchBar;
  private TouchBarButton[] touchBarButtons;

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

  private EditorProject editorProject;

  public ProjectToolbar(Editor editor, EditorProject editorProject) {
    this.editor = editor;
    this.editorProject = editorProject;

    buttonCount = 0;
    which = new int[BUTTON_COUNT];

    //which[buttonCount++] = NOTHING;
    which[buttonCount++] = NAVIGATE;
    which[buttonCount++] = SKETCH;
    which[buttonCount++] = TOGGLE;

    currentRollover = -1;

    bgcolor = Theme.getColor("buttons.bgcolor");
    statusFont = Theme.getFont("buttons.status.font");
    statusColor = Theme.getColor("buttons.status.color");

    if (OSUtils.isMacOS() && VersionComparator.greaterThanOrEqual(OSUtils.version(), "10.12")) {
      editor.addWindowListener(new WindowAdapter() {
        public void windowActivated(WindowEvent e) {
          if (touchBar == null) {
            buildTouchBar();

            touchBar.show(editor);
          }
        }
      });
    }

    addMouseListener(this);
    addMouseMotionListener(this);
  }

  private void buildTouchBar() {
    if (touchBarImages == null) {
      loadTouchBarImages();
    }

    touchBar = new JTouchBar();
    touchBarButtons = new TouchBarButton[BUTTON_COUNT];
    touchBar.setCustomizationIdentifier("Arduino");

    for (int i = 0; i < BUTTON_COUNT; i++) {
      final int selection = i;

      if (i == TOGGLE) {
        touchBar.addItem(new TouchBarItem(TouchBarItem.NSTouchBarItemIdentifierFlexibleSpace));
      }

      touchBarButtons[i] = new TouchBarButton();
      touchBarButtons[i].setImage(touchBarImages[i][ROLLOVER]);
      touchBarButtons[i].setAction(event -> {
        // Run event handler later to prevent hanging if a dialog needs to be open
        EventQueue.invokeLater(new Runnable() {
          @Override
          public void run() {
            handleSelectionPressed(selection);
          }
        });
      });

      TouchBarItem touchBarItem = new TouchBarItem(title[i], touchBarButtons[i], true);
      touchBarItem.setCustomizationLabel(title[i]);
      touchBar.addItem(touchBarItem);
    }
  }

  private void loadButtons() {
    Image allButtons = Theme.getThemeImage("ProjectButtons", this,
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

  private void loadTouchBarImages() {
    Image allButtonsRetina = Theme.getThemeImage("ProjectButtons", this,
      BUTTON_IMAGE_SIZE * BUTTON_COUNT * 2,
      BUTTON_IMAGE_SIZE * 3 * 2);
    touchBarImages = new com.thizzer.jtouchbar.common.Image[BUTTON_COUNT][3];

    for (int i = 0; i < BUTTON_COUNT; i++) {
      for (int state = 0; state < 3; state++) {
        BufferedImage image = new BufferedImage(BUTTON_WIDTH * 2, BUTTON_HEIGHT * 2,
          BufferedImage.TYPE_INT_ARGB);
        Graphics g = image.getGraphics();

        int offset = (BUTTON_IMAGE_SIZE * 2 - BUTTON_WIDTH * 2) / 2;
        g.drawImage(allButtonsRetina, -(i * BUTTON_IMAGE_SIZE * 2) - offset,
          (-2 + state) * BUTTON_IMAGE_SIZE * 2, null);

        // convert the image to a PNG to display on the touch bar
        ByteArrayOutputStream pngStream = new ByteArrayOutputStream();

        try {
          ImageIO.write(image, "PNG", pngStream);

          touchBarImages[i][state] = new com.thizzer.jtouchbar.common.Image(pngStream.toByteArray());
        } catch (IOException e) {
          // ignore errors
        }
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
      x1[TOGGLE] = width - BUTTON_WIDTH - 14;
      x2[TOGGLE] = width - 14;
    }
    Graphics2D g = Theme.setupGraphics2D(offscreen.getGraphics());
    g.setColor(bgcolor); //getBackground());
    g.fillRect(0, 0, width, height);

    for (int i = 0; i < buttonCount; i++) {
      g.drawImage(stateImage[i], x1[i], y1, null);
    }

    g.setColor(statusColor);
    g.setFont(statusFont);


    if (currentRollover != -1) {
      int statusY = (BUTTON_HEIGHT + g.getFontMetrics().getAscent()) / 2;
      String status = title[currentRollover];
      if (currentRollover != TOGGLE)
        g.drawString(status, (buttonCount) * BUTTON_WIDTH + 3 * BUTTON_GAP, statusY);
      else {
        int statusX = x1[TOGGLE] - BUTTON_GAP;
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


    setState(sel, ROLLOVER, true);
    currentRollover = sel;

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

    if (touchBarButtons != null) {
      if (newState == INACTIVE) {
        // use ROLLOVER state when INACTIVE
        newState = ROLLOVER;
      }

      touchBarButtons[slot].setImage(touchBarImages[slot][newState]);
    }
  }
  private void deactivate() {
    if (buttonImages != null) {
      setState(NAVIGATE, INACTIVE, true);
    }
  }


  public void mouseEntered(MouseEvent e) {
    handleMouse(e);
  }


  public void mouseExited(MouseEvent e) {
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

    handleSelectionPressed(sel, x, y);
  }

  public void mouseClicked(MouseEvent e) {
  }

  public void mouseReleased(MouseEvent e) {
  }

  private void handleSelectionPressed(int sel) {
    handleSelectionPressed(sel, 0, 0);
  }

  private void handleSelectionPressed(int sel, int x, int y) {
    switch (sel) {
      case NAVIGATE:
        editorProject.handleNavigate();
        deactivate();
        break;

      case SKETCH:
        // TODO
        // Check save state (if not save) then open sketch folder
        if(editor.untitled){
          editor.handleSaveAs();
        }
        // Get the diretory of the sketch
        editorProject.resetProject(editor.sketch.getFolder());
        break;

      case TOGGLE:
        editor.handleRemoveProjectView();
        break;

      default:
        break;
    }
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

}








