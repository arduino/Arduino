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
import javax.swing.text.SimpleAttributeSet;

import cc.arduino.packages.BoardPort;
import processing.app.Editor.SerialMenuListener;
import processing.app.SerialBar.SerialBarListener;
import processing.app.debug.TargetBoard;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.io.File;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Serial bar to show SerialBarButton(s) representing serial ports, added by Felix Rusu
 */
public class BoardsBar extends JPanel {
  private final Editor editor;
  
  class BoardsBarListener implements ActionListener {
    private final String board;

    public BoardsBarListener(String board) {
      this.board = board;
    }

    public void actionPerformed(ActionEvent e) {
      //editor.selectBoard(board);
      //editor.base.onBoardOrPortChange();
      //refresh();
    }
  }
  
  public BoardsBar(Editor editor) {
    this.editor = editor;
    refresh(true);
  }

  public void refresh(boolean init) {
    if (!init) this.removeAll();
    setLayout(new FlowLayout(FlowLayout.LEFT));

    String selBoard = PreferencesData.get("board");
    String selPackage = PreferencesData.get("target_package");
    String selPlatform = PreferencesData.get("target_platform");

    int count=0;
    for (String board : PreferencesData.getCollection("recent.boards")) {
      String[] brd = board.split(":");
      if (brd.length != 3) continue;

      //find the board in the Boards menu, and assign the shortcut button the same action as the menu action
      JMenuItem itemToClick = null;
      String brdName = brd[0];
      for (JMenu menu : editor.base.getBoardsCustomMenus()) {
        for (int i=0;i<menu.getItemCount();i++)
        {
          if (menu.getItem(i) instanceof JRadioButtonMenuItem)
          {
            JRadioButtonMenuItem menuItem = (JRadioButtonMenuItem) menu.getItem(i);
            if (menuItem.getAction().getValue("b")!=null)
            {
              TargetBoard menuBoard = (TargetBoard)menuItem.getAction().getValue("b");
              if (menuBoard.getId().equals(brd[0]) && menuBoard.getContainerPlatform().getId().equals(brd[1]) && menuBoard.getContainerPlatform().getContainerPackage().getId().equals(brd[2]))
              {
                itemToClick = menuItem;
                brdName = menuBoard.getName();
                break;
              }
            }
          }
        }
      }

      ShortcutBarButton btn = new ShortcutBarButton(brdName, "", itemToClick, selBoard.equals(brd[0]) && selPlatform.equals(brd[1]) && selPackage.equals(brd[2]), Color.RED);
      this.add(btn);
      count++;
    }

    editor.base.getBoardsCustomMenus();

    if (count == 0) this.add(new JLabel(tr("No boards selected...")));
    else {
      addClearButton();
    }
    
    if (!init) {
      this.revalidate();
      this.repaint();
    }
  }
  
  private void addClearButton() {
    ShortcutBarButton btn = new ShortcutBarButton(tr("[Clear]"), "", null, true, Color.BLUE);
    btn.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        clear();
      }
    });
    
    this.add(btn);
  }
  
  public void clear() {
    for (Component c : this.getComponents()) if (!((ShortcutBarButton)c).selected) this.remove(c);
    String selBoard = PreferencesData.get("board");
    String selPackage = PreferencesData.get("target_package");
    String selPlatform = PreferencesData.get("target_platform");
    PreferencesData.set("recent.boards", selBoard.concat(":").concat(selPlatform).concat(":").concat(selPackage));
    this.revalidate();
    this.repaint();
  }
  
  public static void addBoardPreference(String board, String platform, String pkg) {
    Set<String> boards = new LinkedHashSet<>();
    boards.addAll(PreferencesData.getCollection("recent.boards"));
    for (String brd : boards) if (brd.equals("") || brd.split(":").length!=3) { boards.remove(brd); break; } //cleanup after first init
    boards.add(board.concat(":").concat(platform).concat(":").concat(pkg));

    int count = boards.size();
    int keep = 5; //how many shortcut buttons to keep in the bar
    if (count > keep)
    {
      int removed=0;
      for (String brd: boards) {
        boards.remove(brd);
        removed++;
        if (removed==count-keep) break;
      }
    }

    PreferencesData.setCollection("recent.boards", boards);
  }

  public Dimension getPreferredSize() {
    return getMinimumSize();
  }

  public Dimension getMinimumSize() {
    return new Dimension(100, 32);
  }

  public Dimension getMaximumSize() {
    return new Dimension(scale(30000), 32);
  }
}