/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Processing project - http://processing.org

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

import cc.arduino.packages.BoardPort;
import cc.arduino.packages.MonitorFactory;
import cc.arduino.packages.Uploader;
import cc.arduino.packages.uploaders.SerialUploader;
import cc.arduino.view.GoToLineNumber;
import cc.arduino.view.StubMenuListener;
import cc.arduino.view.findreplace.FindReplace;
import com.jcraft.jsch.JSchException;
import jssc.SerialPortException;
import processing.app.debug.RunnerException;
import processing.app.forms.PasswordAuthorizationDialog;
import processing.app.helpers.Keys;
import processing.app.helpers.OSUtils;
import processing.app.helpers.PreferencesMapException;
import processing.app.legacy.PApplet;
import processing.app.syntax.PdeKeywords;
import processing.app.tools.MenuScroller;
import processing.app.tools.Tool;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.BadLocationException;
import javax.swing.undo.CannotRedoException;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.UndoManager;
import java.awt.*;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.awt.event.*;
import java.awt.print.PageFormat;
import java.awt.print.PrinterException;
import java.awt.print.PrinterJob;
import java.io.File;
import java.io.FileFilter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.net.ConnectException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.*;
import java.util.List;
import java.util.function.Predicate;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

/**
 * Main editor panel for the Processing Development Environment.
 */
@SuppressWarnings("serial")
public class Editor extends JFrame implements RunnerListener {

  public static final int MAX_TIME_AWAITING_FOR_RESUMING_SERIAL_MONITOR = 10000;

  final Platform platform;
  private JMenu recentSketchesMenu;
  private JMenu programmersMenu;
  private final Box upper;
  private ArrayList<EditorTab> tabs = new ArrayList<>();
  private int currentTabIndex = -1;

  private static class ShouldSaveIfModified
      implements Predicate<SketchController> {

    @Override
    public boolean test(SketchController controller) {
      return PreferencesData.getBoolean("editor.save_on_verify")
             && controller.getSketch().isModified()
             && !controller.isReadOnly(
                                       BaseNoGui.librariesIndexer
                                           .getInstalledLibraries(),
                                       BaseNoGui.getExamplesPath());
    }
  }

  private static class ShouldSaveReadOnly implements Predicate<SketchController> {

    @Override
    public boolean test(SketchController sketch) {
      return sketch.isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath());
    }
  }

  private final static List<String> BOARD_PROTOCOLS_ORDER = Arrays.asList("serial", "network");
  private final static List<String> BOARD_PROTOCOLS_ORDER_TRANSLATIONS = Arrays.asList(tr("Serial ports"), tr("Network ports"));

  final Base base;

  // otherwise, if the window is resized with the message label
  // set to blank, it's preferredSize() will be fukered
  private static final String EMPTY =
    "                                                                     " +
    "                                                                     " +
    "                                                                     ";

  /** Command on Mac OS X, Ctrl on Windows and Linux */
  private static final int SHORTCUT_KEY_MASK =
    Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
  /** Command-W on Mac OS X, Ctrl-W on Windows and Linux */
  static final KeyStroke WINDOW_CLOSE_KEYSTROKE =
    KeyStroke.getKeyStroke('W', SHORTCUT_KEY_MASK);
  /** Command-Option on Mac OS X, Ctrl-Alt on Windows and Linux */
  static final int SHORTCUT_ALT_KEY_MASK = ActionEvent.ALT_MASK |
    Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();

  /**
   * true if this file has not yet been given a name by the user
   */
  boolean untitled;

  private PageFormat pageFormat;

  // file, sketch, and tools menus for re-inserting items
  private JMenu fileMenu;
  private JMenu toolsMenu;

  private int numTools = 0;

  public boolean avoidMultipleOperations = false;

  private final EditorToolbar toolbar;
  // these menus are shared so that they needn't be rebuilt for all windows
  // each time a sketch is created, renamed, or moved.
  static JMenu toolbarMenu;
  static JMenu sketchbookMenu;
  static JMenu examplesMenu;
  static JMenu importMenu;

  private static JMenu portMenu;

  static volatile AbstractMonitor serialMonitor;
  static AbstractMonitor serialPlotter;
  
  final EditorHeader header;
  EditorStatus status;
  EditorConsole console;

  private JSplitPane splitPane;

  // currently opened program
  SketchController sketchController;
  Sketch sketch;

  EditorLineStatus lineStatus;

  //JEditorPane editorPane;

  /** Contains all EditorTabs, of which only one will be visible */
  private JPanel codePanel;

  //Runner runtime;

  private JMenuItem saveMenuItem;
  private JMenuItem saveAsMenuItem;

  //boolean presenting;
  private boolean uploading;

  // undo fellers
  private JMenuItem undoItem;
  private JMenuItem redoItem;
  protected UndoAction undoAction;
  protected RedoAction redoAction;

  private FindReplace find;

  Runnable runHandler;
  Runnable presentHandler;
  private Runnable runAndSaveHandler;
  private Runnable presentAndSaveHandler;
  Runnable exportHandler;
  private Runnable exportAppHandler;
  private Runnable timeoutUploadHandler;

  public Editor(Base ibase, File file, int[] storedLocation, int[] defaultLocation, Platform platform) throws Exception {
    super("Arduino");
    this.base = ibase;
    this.platform = platform;

    Base.setIcon(this);

    // Install default actions for Run, Present, etc.
    resetHandlers();

    // add listener to handle window close box hit event
    addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent e) {
          base.handleClose(Editor.this);
        }
      });
    // don't close the window when clicked, the app will take care
    // of that via the handleQuitInternal() methods
    // http://dev.processing.org/bugs/show_bug.cgi?id=440
    setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);

    // When bringing a window to front, let the Base know
    addWindowListener(new WindowAdapter() {
        public void windowActivated(WindowEvent e) {
          base.handleActivated(Editor.this);
        }

        // added for 1.0.5
        // http://dev.processing.org/bugs/show_bug.cgi?id=1260
        public void windowDeactivated(WindowEvent e) {
          fileMenu.remove(sketchbookMenu);
          fileMenu.remove(examplesMenu);
          List<Component> toolsMenuItemsToRemove = new LinkedList<>();
          for (Component menuItem : toolsMenu.getMenuComponents()) {
            if (menuItem instanceof JComponent) {
              Object removeOnWindowDeactivation = ((JComponent) menuItem).getClientProperty("removeOnWindowDeactivation");
              if (removeOnWindowDeactivation != null && Boolean.valueOf(removeOnWindowDeactivation.toString())) {
                toolsMenuItemsToRemove.add(menuItem);
              }
            }
          }
          for (Component menuItem : toolsMenuItemsToRemove) {
            toolsMenu.remove(menuItem);
          }
          toolsMenu.remove(portMenu);
        }
      });

    //PdeKeywords keywords = new PdeKeywords();
    //sketchbook = new Sketchbook(this);
    
    buildMenuBar();

    // For rev 0120, placing things inside a JPanel
    Container contentPain = getContentPane();
    contentPain.setLayout(new BorderLayout());
    JPanel pane = new JPanel();
    pane.setLayout(new BorderLayout());
    contentPain.add(pane, BorderLayout.CENTER);

    Box box = Box.createVerticalBox();
    upper = Box.createVerticalBox();

    if (toolbarMenu == null) {
      toolbarMenu = new JMenu();
      base.rebuildToolbarMenu(toolbarMenu);
    }
    toolbar = new EditorToolbar(this, toolbarMenu);
    upper.add(toolbar);

    header = new EditorHeader(this);
    upper.add(header);

    // assemble console panel, consisting of status area and the console itself
    JPanel consolePanel = new JPanel();
    consolePanel.setLayout(new BorderLayout());

    status = new EditorStatus(this);
    consolePanel.add(status, BorderLayout.NORTH);

    console = new EditorConsole();
    console.setName("console");
    // windows puts an ugly border on this guy
    console.setBorder(null);
    consolePanel.add(console, BorderLayout.CENTER);

    lineStatus = new EditorLineStatus();
    consolePanel.add(lineStatus, BorderLayout.SOUTH);

    codePanel = new JPanel(new BorderLayout());
    upper.add(codePanel);

    splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, upper, consolePanel);

    // repaint child panes while resizing
    splitPane.setContinuousLayout(true);
    // if window increases in size, give all of increase to
    // the textarea in the uppper pane
    splitPane.setResizeWeight(1D);

    // to fix ugliness.. normally macosx java 1.3 puts an
    // ugly white border around this object, so turn it off.
    splitPane.setBorder(null);
    // By default, the split pane binds Ctrl-Tab and Ctrl-Shift-Tab for changing
    // focus. Since we do not use that, but want to use these shortcuts for
    // switching tabs, remove the bindings from the split pane. This allows the
    // events to bubble up and be handled by the EditorHeader.
    Keys.killBinding(splitPane, Keys.ctrl(KeyEvent.VK_TAB));
    Keys.killBinding(splitPane, Keys.ctrlShift(KeyEvent.VK_TAB));

    splitPane.setDividerSize(scale(splitPane.getDividerSize()));

    // the following changed from 600, 400 for netbooks
    // http://code.google.com/p/arduino/issues/detail?id=52
    splitPane.setMinimumSize(scale(new Dimension(600, 100)));
    box.add(splitPane);

    // hopefully these are no longer needed w/ swing
    // (har har har.. that was wishful thinking)
    // listener = new EditorListener(this, textarea);
    pane.add(box);

    pane.setTransferHandler(new FileDropHandler());

    // Set the minimum size for the editor window
    setMinimumSize(scale(new Dimension(
        PreferencesData.getInteger("editor.window.width.min"),
        PreferencesData.getInteger("editor.window.height.min"))));

    // Bring back the general options for the editor
    applyPreferences();

    // Finish preparing Editor (formerly found in Base)
    pack();

    // Set the window bounds and the divider location before setting it visible
    setPlacement(storedLocation, defaultLocation);

    // Open the document that was passed in
    boolean loaded = handleOpenInternal(file);
    if (!loaded) sketchController = null;
  }


  /**
   * Handles files dragged & dropped from the desktop and into the editor
   * window. Dragging files into the editor window is the same as using
   * "Sketch &rarr; Add File" for each file.
   */
  private class FileDropHandler extends TransferHandler {
    public boolean canImport(JComponent dest, DataFlavor[] flavors) {
      return true;
    }

    @SuppressWarnings("unchecked")
    public boolean importData(JComponent src, Transferable transferable) {
      int successful = 0;

      try {
        DataFlavor uriListFlavor =
          new DataFlavor("text/uri-list;class=java.lang.String");

        if (transferable.isDataFlavorSupported(DataFlavor.javaFileListFlavor)) {
          List<File> list = (List<File>)
            transferable.getTransferData(DataFlavor.javaFileListFlavor);
          for (File file : list) {
            if (sketchController.addFile(file)) {
              successful++;
            }
          }
        } else if (transferable.isDataFlavorSupported(uriListFlavor)) {
          // Some platforms (Mac OS X and Linux, when this began) preferred
          // this method of moving files.
          String data = (String)transferable.getTransferData(uriListFlavor);
          String[] pieces = PApplet.splitTokens(data, "\r\n");
          for (String piece : pieces) {
            if (piece.startsWith("#")) continue;

            String path = null;
            if (piece.startsWith("file:///")) {
              path = piece.substring(7);
            } else if (piece.startsWith("file:/")) {
              path = piece.substring(5);
            }
            if (sketchController.addFile(new File(path))) {
              successful++;
            }
          }
        }
      } catch (Exception e) {
        e.printStackTrace();
        return false;
      }

      if (successful == 0) {
        statusError(tr("No files were added to the sketch."));

      } else if (successful == 1) {
        statusNotice(tr("One file added to the sketch."));

      } else {
        statusNotice(
	    I18n.format(tr("{0} files added to the sketch."), successful));
      }
      return true;
    }
  }

  private void setPlacement(int[] storedLocation, int[] defaultLocation) {
    if (storedLocation.length > 5 && storedLocation[5] != 0) {
      setExtendedState(storedLocation[5]);
      setPlacement(defaultLocation);
    } else {
      setPlacement(storedLocation);
    }
  }

  private void setPlacement(int[] location) {
    setBounds(location[0], location[1], location[2], location[3]);
    if (location[4] != 0) {
      splitPane.setDividerLocation(location[4]);
    }
  }

  protected int[] getPlacement() {
    int[] location = new int[6];

    // Get the dimensions of the Frame
    Rectangle bounds = getBounds();
    location[0] = bounds.x;
    location[1] = bounds.y;
    location[2] = bounds.width;
    location[3] = bounds.height;

    // Get the current placement of the divider
    location[4] = splitPane.getDividerLocation();
    location[5] = getExtendedState() & MAXIMIZED_BOTH;

    return location;
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  /**
   * Read and apply new values from the preferences, either because
   * the app is just starting up, or the user just finished messing
   * with things in the Preferences window.
   */
  public void applyPreferences() {
    boolean external = PreferencesData.getBoolean("editor.external");
    saveMenuItem.setEnabled(!external);
    saveAsMenuItem.setEnabled(!external);
    for (EditorTab tab: tabs)
      tab.applyPreferences();
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  private void buildMenuBar() {
    JMenuBar menubar = new JMenuBar();
    final JMenu fileMenu = buildFileMenu();
    fileMenu.addMenuListener(new StubMenuListener() {
      @Override
      public void menuSelected(MenuEvent e) {
        List<Component> components = Arrays.asList(fileMenu.getComponents());
        if (!components.contains(sketchbookMenu)) {
          fileMenu.insert(sketchbookMenu, 3);
        }
        if (!components.contains(sketchbookMenu)) {
          fileMenu.insert(examplesMenu, 4);
        }
        fileMenu.revalidate();
        validate();
      }
    });
    menubar.add(fileMenu);

    menubar.add(buildEditMenu());

    final JMenu sketchMenu = new JMenu(tr("Sketch"));
    sketchMenu.setMnemonic(KeyEvent.VK_S);
    sketchMenu.addMenuListener(new StubMenuListener() {

      @Override
      public void menuSelected(MenuEvent e) {
        buildSketchMenu(sketchMenu);
        sketchMenu.revalidate();
        validate();
      }
    });
    buildSketchMenu(sketchMenu);
    menubar.add(sketchMenu);

    final JMenu toolsMenu = buildToolsMenu();
    toolsMenu.addMenuListener(new StubMenuListener() {
      @Override
      public void menuSelected(MenuEvent e) {
        List<Component> components = Arrays.asList(toolsMenu.getComponents());
        int offset = 0;
        for (JMenu menu : base.getBoardsCustomMenus()) {
          if (!components.contains(menu)) {
            toolsMenu.insert(menu, numTools + offset);
            offset++;
          }
        }
        if (!components.contains(portMenu)) {
          toolsMenu.insert(portMenu, numTools + offset);
        }
        programmersMenu.removeAll();
        base.getProgrammerMenus().forEach(programmersMenu::add);
        toolsMenu.revalidate();
        validate();
      }
    });
    menubar.add(toolsMenu);

    menubar.add(buildHelpMenu());
    setJMenuBar(menubar);
  }


  private JMenu buildFileMenu() {
    JMenuItem item;
    fileMenu = new JMenu(tr("File"));
    fileMenu.setMnemonic(KeyEvent.VK_F);

    item = newJMenuItem(tr("New"), 'N');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          try {
            base.handleNew();
          } catch (Exception e1) {
            e1.printStackTrace();
          }
        }
      });
    fileMenu.add(item);

    item = Editor.newJMenuItem(tr("Open..."), 'O');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          try {
            base.handleOpenPrompt();
          } catch (Exception e1) {
            e1.printStackTrace();
          }
        }
      });
    fileMenu.add(item);

    base.rebuildRecentSketchesMenuItems();
    recentSketchesMenu = new JMenu(tr("Open Recent"));
    SwingUtilities.invokeLater(new Runnable() {
      @Override
      public void run() {
        rebuildRecentSketchesMenu();
      }
    });
    fileMenu.add(recentSketchesMenu);

    if (sketchbookMenu == null) {
      sketchbookMenu = new JMenu(tr("Sketchbook"));
      MenuScroller.setScrollerFor(sketchbookMenu);
      base.rebuildSketchbookMenu(sketchbookMenu);
    }
    fileMenu.add(sketchbookMenu);

    if (examplesMenu == null) {
      examplesMenu = new JMenu(tr("Examples"));
      MenuScroller.setScrollerFor(examplesMenu);
      base.rebuildExamplesMenu(examplesMenu);
    }
    fileMenu.add(examplesMenu);

    item = Editor.newJMenuItem(tr("Close"), 'W');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          base.handleClose(Editor.this);
        }
      });
    fileMenu.add(item);

    saveMenuItem = newJMenuItem(tr("Save"), 'S');
    saveMenuItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleSave(false);
        }
      });
    fileMenu.add(saveMenuItem);

    saveAsMenuItem = newJMenuItemShift(tr("Save As..."), 'S');
    saveAsMenuItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleSaveAs();
        }
      });
    fileMenu.add(saveAsMenuItem);

    fileMenu.addSeparator();

    item = newJMenuItemShift(tr("Page Setup"), 'P');
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        handlePageSetup();
      }
    });
    fileMenu.add(item);

    item = newJMenuItem(tr("Print"), 'P');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handlePrint();
        }
      });
    fileMenu.add(item);

    // macosx already has its own preferences and quit menu
    if (!OSUtils.isMacOS()) {
      fileMenu.addSeparator();

      item = newJMenuItem(tr("Preferences"), ',');
      item.addActionListener(new ActionListener() {
          public void actionPerformed(ActionEvent e) {
            base.handlePrefs();
          }
        });
      fileMenu.add(item);

      fileMenu.addSeparator();

      item = newJMenuItem(tr("Quit"), 'Q');
      item.addActionListener(new ActionListener() {
          public void actionPerformed(ActionEvent e) {
            base.handleQuit();
          }
        });
      fileMenu.add(item);
    }
    return fileMenu;
  }

  public void rebuildRecentSketchesMenu() {
    recentSketchesMenu.removeAll();
    for (JMenuItem recentSketchMenuItem  : base.getRecentSketchesMenuItems()) {
      recentSketchesMenu.add(recentSketchMenuItem);
    }
  }

  private void buildSketchMenu(JMenu sketchMenu) {
    sketchMenu.removeAll();

    JMenuItem item = newJMenuItem(tr("Verify/Compile"), 'R');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleRun(false, Editor.this.presentHandler, Editor.this.runHandler);
        }
      });
    sketchMenu.add(item);

    item = newJMenuItem(tr("Upload"), 'U');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleExport(false);
        }
      });
    sketchMenu.add(item);

    item = newJMenuItemShift(tr("Upload Using Programmer"), 'U');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handleExport(true);
        }
      });
    sketchMenu.add(item);


    item = newJMenuItemAlt(tr("Export compiled Binary"), 'S');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          if (new ShouldSaveReadOnly().test(sketchController) && !handleSave(true)) {
            System.out.println(tr("Export canceled, changes must first be saved."));
            return;
          }
          handleRun(false, new ShouldSaveReadOnly(), Editor.this.presentAndSaveHandler, Editor.this.runAndSaveHandler);
        }
      });
    sketchMenu.add(item);

//    item = new JMenuItem("Stop");
//    item.addActionListener(new ActionListener() {
//        public void actionPerformed(ActionEvent e) {
//          handleStop();
//        }
//      });
//    sketchMenu.add(item);

    sketchMenu.addSeparator();

    item = newJMenuItem(tr("Show Sketch Folder"), 'K');
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.openFolder(sketch.getFolder());
      }
    });
    sketchMenu.add(item);
    item.setEnabled(Base.openFolderAvailable());

    if (importMenu == null) {
      importMenu = new JMenu(tr("Include Library"));
      MenuScroller.setScrollerFor(importMenu);
      base.rebuildImportMenu(importMenu);
    }
    sketchMenu.add(importMenu);

    item = new JMenuItem(tr("Add File..."));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        sketchController.handleAddFile();
      }
    });
    sketchMenu.add(item);
  }


  private JMenu buildToolsMenu() {
    toolsMenu = new JMenu(tr("Tools"));
    toolsMenu.setMnemonic(KeyEvent.VK_T);

    addInternalTools(toolsMenu);

    JMenuItem item = newJMenuItemShift(tr("Serial Monitor"), 'M');
    item.addActionListener(e -> handleSerial());
    toolsMenu.add(item);

    item = newJMenuItemShift(tr("Serial Plotter"), 'L');
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          handlePlotter();
        }
    });
    toolsMenu.add(item);

    addTools(toolsMenu, BaseNoGui.getToolsFolder());
    File sketchbookTools = new File(BaseNoGui.getSketchbookFolder(), "tools");
    addTools(toolsMenu, sketchbookTools);

    toolsMenu.addSeparator();

    numTools = toolsMenu.getItemCount();

    // XXX: DAM: these should probably be implemented using the Tools plugin
    // API, if possible (i.e. if it supports custom actions, etc.)

    base.getBoardsCustomMenus().stream().forEach(toolsMenu::add);

    if (portMenu == null)
      portMenu = new JMenu(tr("Port"));
    populatePortMenu();
    toolsMenu.add(portMenu);
    item = new JMenuItem(tr("Get Board Info"));
    item.addActionListener(e -> handleBoardInfo());
    toolsMenu.add(item);
    toolsMenu.addSeparator();

    base.rebuildProgrammerMenu();
    programmersMenu = new JMenu(tr("Programmer"));
    base.getProgrammerMenus().stream().forEach(programmersMenu::add);
    toolsMenu.add(programmersMenu);

    item = new JMenuItem(tr("Burn Bootloader"));
    item.addActionListener(e -> handleBurnBootloader());
    toolsMenu.add(item);

    toolsMenu.addMenuListener(new StubMenuListener() {
      public void menuSelected(MenuEvent e) {
        //System.out.println("Tools menu selected.");
        populatePortMenu();
        for (Component c : toolsMenu.getMenuComponents()) {
          if ((c instanceof JMenu) && c.isVisible()) {
            JMenu menu = (JMenu)c;
            String name = menu.getText();
            if (name == null) continue;
            String basename = name;
            int index = name.indexOf(':');
            if (index > 0) basename = name.substring(0, index);
            String sel = null;
            int count = menu.getItemCount();
            for (int i=0; i < count; i++) {
              JMenuItem item = menu.getItem(i);
              if (item != null && item.isSelected()) {
                sel = item.getText();
                if (sel != null) break;
              }
            }
            if (sel == null) {
              if (!name.equals(basename)) menu.setText(basename);
            } else {
              if (sel.length() > 50) sel = sel.substring(0, 50) + "...";
              String newname = basename + ": \"" + sel + "\"";
              if (!name.equals(newname)) menu.setText(newname);
            }
          }
        }
      }
    });

    return toolsMenu;
  }


  private void addTools(JMenu menu, File sourceFolder) {
    if (sourceFolder == null)
      return;

    Map<String, JMenuItem> toolItems = new HashMap<>();

    File[] folders = sourceFolder.listFiles(new FileFilter() {
      public boolean accept(File folder) {
        if (folder.isDirectory()) {
          //System.out.println("checking " + folder);
          File subfolder = new File(folder, "tool");
          return subfolder.exists();
        }
        return false;
      }
    });

    if (folders == null || folders.length == 0) {
      return;
    }

    for (File folder : folders) {
      File toolDirectory = new File(folder, "tool");

      try {
        // add dir to classpath for .classes
        //urlList.add(toolDirectory.toURL());

        // add .jar files to classpath
        File[] archives = toolDirectory.listFiles(new FilenameFilter() {
          public boolean accept(File dir, String name) {
            return (name.toLowerCase().endsWith(".jar") ||
              name.toLowerCase().endsWith(".zip"));
          }
        });

        URL[] urlList = new URL[archives.length];
        for (int j = 0; j < urlList.length; j++) {
          urlList[j] = archives[j].toURI().toURL();
        }
        URLClassLoader loader = new URLClassLoader(urlList);

        String className = null;
        for (File archive : archives) {
          className = findClassInZipFile(folder.getName(), archive);
          if (className != null) break;
        }

        /*
        // Alternatively, could use manifest files with special attributes:
        // http://java.sun.com/j2se/1.3/docs/guide/jar/jar.html
        // Example code for loading from a manifest file:
        // http://forums.sun.com/thread.jspa?messageID=3791501
        File infoFile = new File(toolDirectory, "tool.txt");
        if (!infoFile.exists()) continue;

        String[] info = PApplet.loadStrings(infoFile);
        //Main-Class: org.poo.shoe.AwesomerTool
        //String className = folders[i].getName();
        String className = null;
        for (int k = 0; k < info.length; k++) {
          if (info[k].startsWith(";")) continue;

          String[] pieces = PApplet.splitTokens(info[k], ": ");
          if (pieces.length == 2) {
            if (pieces[0].equals("Main-Class")) {
              className = pieces[1];
            }
          }
        }
        */
        // If no class name found, just move on.
        if (className == null) continue;

        Class<?> toolClass = Class.forName(className, true, loader);
        final Tool tool = (Tool) toolClass.newInstance();

        tool.init(Editor.this);

        String title = tool.getMenuTitle();
        JMenuItem item = new JMenuItem(title);
        item.addActionListener(new ActionListener() {
          public void actionPerformed(ActionEvent e) {
            SwingUtilities.invokeLater(tool);
            //new Thread(tool).start();
          }
        });
        //menu.add(item);
        toolItems.put(title, item);

      } catch (Exception e) {
        e.printStackTrace();
      }
    }
    ArrayList<String> toolList = new ArrayList<>(toolItems.keySet());
    if (toolList.size() == 0) return;

    menu.addSeparator();
    Collections.sort(toolList);
    for (String title : toolList) {
      menu.add(toolItems.get(title));
    }
  }


  private String findClassInZipFile(String base, File file) {
    // Class file to search for
    String classFileName = "/" + base + ".class";

    ZipFile zipFile = null;
    try {
      zipFile = new ZipFile(file);
      Enumeration<?> entries = zipFile.entries();
      while (entries.hasMoreElements()) {
        ZipEntry entry = (ZipEntry) entries.nextElement();

        if (!entry.isDirectory()) {
          String name = entry.getName();
          //System.out.println("entry: " + name);

          if (name.endsWith(classFileName)) {
            //int slash = name.lastIndexOf('/');
            //String packageName = (slash == -1) ? "" : name.substring(0, slash);
            // Remove .class and convert slashes to periods.
            return name.substring(0, name.length() - 6).replace('/', '.');
          }
        }
      }
    } catch (IOException e) {
      //System.err.println("Ignoring " + filename + " (" + e.getMessage() + ")");
      e.printStackTrace();
    } finally {
      if (zipFile != null) {
        try {
          zipFile.close();
        } catch (IOException e) {
          // noop
        }
      }
    }
    return null;
	}

  public void updateKeywords(PdeKeywords keywords) {
    for (EditorTab tab : tabs)
      tab.updateKeywords(keywords);
  }

  JMenuItem createToolMenuItem(String className) {
    try {
      Class<?> toolClass = Class.forName(className);
      final Tool tool = (Tool) toolClass.newInstance();

      JMenuItem item = new JMenuItem(tool.getMenuTitle());

      tool.init(Editor.this);

      item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          SwingUtilities.invokeLater(tool);
        }
      });
      return item;

    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  }


  private void addInternalTools(JMenu menu) {
    JMenuItem item;

    item = createToolMenuItem("cc.arduino.packages.formatter.AStyle");
    if (item == null) {
      throw new NullPointerException("Tool cc.arduino.packages.formatter.AStyle unavailable");
    }
    item.setName("menuToolsAutoFormat");
    int modifiers = Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
    item.setAccelerator(KeyStroke.getKeyStroke('T', modifiers));
    menu.add(item);

    //menu.add(createToolMenuItem("processing.app.tools.CreateFont"));
    //menu.add(createToolMenuItem("processing.app.tools.ColorSelector"));
    menu.add(createToolMenuItem("processing.app.tools.Archiver"));
    menu.add(createToolMenuItem("processing.app.tools.FixEncoding"));
  }


  class SerialMenuListener implements ActionListener {

    private final String serialPort;

    public SerialMenuListener(String serialPort) {
      this.serialPort = serialPort;
    }

    public void actionPerformed(ActionEvent e) {
      selectSerialPort(serialPort);
      base.onBoardOrPortChange();
    }

  }

  private void selectSerialPort(String name) {
    if(portMenu == null) {
      System.out.println(tr("serialMenu is null"));
      return;
    }
    if (name == null) {
      System.out.println(tr("name is null"));
      return;
    }
    JCheckBoxMenuItem selection = null;
    for (int i = 0; i < portMenu.getItemCount(); i++) {
      JMenuItem menuItem = portMenu.getItem(i);
      if (!(menuItem instanceof JCheckBoxMenuItem)) {
        continue;
      }
      JCheckBoxMenuItem checkBoxMenuItem = ((JCheckBoxMenuItem) menuItem);
      checkBoxMenuItem.setState(false);
      if (name.equals(checkBoxMenuItem.getText())) selection = checkBoxMenuItem;
    }
    if (selection != null) selection.setState(true);
    //System.out.println(item.getLabel());

    BaseNoGui.selectSerialPort(name);
    if (serialMonitor != null) {
      try {
        serialMonitor.close();
        serialMonitor.setVisible(false);
      } catch (Exception e) {
        // ignore
      }
    }

    if (serialPlotter != null) {
      try {
        serialPlotter.close();
        serialPlotter.setVisible(false);
      } catch (Exception e) {
        // ignore
      }
    }

    onBoardOrPortChange();
    base.onBoardOrPortChange();

    //System.out.println("set to " + get("serial.port"));
  }


  private void populatePortMenu() {
    portMenu.removeAll();

    String selectedPort = PreferencesData.get("serial.port");

    List<BoardPort> ports = Base.getDiscoveryManager().discovery();

    ports = platform.filterPorts(ports, PreferencesData.getBoolean("serial.ports.showall"));

    Collections.sort(ports, new Comparator<BoardPort>() {
      @Override
      public int compare(BoardPort o1, BoardPort o2) {
        return BOARD_PROTOCOLS_ORDER.indexOf(o1.getProtocol()) - BOARD_PROTOCOLS_ORDER.indexOf(o2.getProtocol());
      }
    });

    String lastProtocol = null;
    String lastProtocolTranslated;
    for (BoardPort port : ports) {
      if (lastProtocol == null || !port.getProtocol().equals(lastProtocol)) {
        if (lastProtocol != null) {
          portMenu.addSeparator();
        }
        lastProtocol = port.getProtocol();

        if (BOARD_PROTOCOLS_ORDER.indexOf(port.getProtocol()) != -1) {
          lastProtocolTranslated = BOARD_PROTOCOLS_ORDER_TRANSLATIONS.get(BOARD_PROTOCOLS_ORDER.indexOf(port.getProtocol()));
        } else {
          lastProtocolTranslated = port.getProtocol();
        }
        JMenuItem lastProtocolMenuItem = new JMenuItem(tr(lastProtocolTranslated));
        lastProtocolMenuItem.setEnabled(false);
        portMenu.add(lastProtocolMenuItem);
      }
      String address = port.getAddress();
      String label = port.getLabel();

      JCheckBoxMenuItem item = new JCheckBoxMenuItem(label, address.equals(selectedPort));
      item.addActionListener(new SerialMenuListener(address));
      portMenu.add(item);
    }

    portMenu.setEnabled(portMenu.getMenuComponentCount() > 0);
  }


  private JMenu buildHelpMenu() {
    // To deal with a Mac OS X 10.5 bug, add an extra space after the name
    // so that the OS doesn't try to insert its slow help menu.
    JMenu menu = new JMenu(tr("Help"));
    menu.setMnemonic(KeyEvent.VK_H);
    JMenuItem item;

    /*
    // testing internal web server to serve up docs from a zip file
    item = new JMenuItem("Web Server Test");
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          //WebServer ws = new WebServer();
          SwingUtilities.invokeLater(new Runnable() {
            public void run() {
              try {
                int port = WebServer.launch("/Users/fry/coconut/processing/build/shared/reference.zip");
                Base.openURL("http://127.0.0.1:" + port + "/reference/setup_.html");

              } catch (IOException e1) {
                e1.printStackTrace();
              }
            }
          });
        }
      });
    menu.add(item);
    */

    /*
    item = new JMenuItem("Browser Test");
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          //Base.openURL("http://processing.org/learning/gettingstarted/");
          //JFrame browserFrame = new JFrame("Browser");
          BrowserStartup bs = new BrowserStartup("jar:file:/Users/fry/coconut/processing/build/shared/reference.zip!/reference/setup_.html");
          bs.initUI();
          bs.launch();
        }
      });
    menu.add(item);
    */

    item = new JMenuItem(tr("Getting Started"));
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          Base.showArduinoGettingStarted();
        }
      });
    menu.add(item);

    item = new JMenuItem(tr("Environment"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showEnvironment();
      }
    });
    menu.add(item);

    item = new JMenuItem(tr("Troubleshooting"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showTroubleshooting();
      }
    });
    menu.add(item);

    item = new JMenuItem(tr("Reference"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showReference();
      }
    });
    menu.add(item);

    menu.addSeparator();

    item = new JMenuItem(tr("Galileo Help"));
    item.setEnabled(false);
    menu.add(item);

    item = new JMenuItem(tr("Getting Started"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showReference("reference/Galileo_help_files", "ArduinoIDE_guide_galileo");
      }
    });
    menu.add(item);
    item = new JMenuItem(tr("Troubleshooting"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showReference("reference/Galileo_help_files", "Guide_Troubleshooting_Galileo");
      }
    });
    menu.add(item);

    menu.addSeparator();

    item = new JMenuItem(tr("Edison Help"));
    item.setEnabled(false);
    menu.add(item);

    item = new JMenuItem(tr("Getting Started"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showReference("reference/Edison_help_files", "ArduinoIDE_guide_edison");
      }
    });
    menu.add(item);
    item = new JMenuItem(tr("Troubleshooting"));
    item.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        Base.showReference("reference/Edison_help_files", "Guide_Troubleshooting_Edison");
      }
    });
    menu.add(item);

    menu.addSeparator();

    item = newJMenuItemShift(tr("Find in Reference"), 'F');
    item.addActionListener(this::handleFindReference);
    menu.add(item);

    item = new JMenuItem(tr("Frequently Asked Questions"));
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          Base.showFAQ();
        }
      });
    menu.add(item);

    item = new JMenuItem(tr("Visit Arduino.cc"));
    item.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          Base.openURL(tr("http://www.arduino.cc/"));
        }
      });
    menu.add(item);

    // macosx already has its own about menu
    if (!OSUtils.isMacOS()) {
      menu.addSeparator();
      item = new JMenuItem(tr("About Arduino"));
      item.addActionListener(new ActionListener() {
          public void actionPerformed(ActionEvent e) {
            base.handleAbout();
          }
        });
      menu.add(item);
    }

    return menu;
  }


  private JMenu buildEditMenu() {
    JMenu menu = new JMenu(tr("Edit"));
    menu.setName("menuEdit");
    menu.setMnemonic(KeyEvent.VK_E);

    undoItem = newJMenuItem(tr("Undo"), 'Z');
    undoItem.setName("menuEditUndo");
    undoItem.addActionListener(undoAction = new UndoAction());
    menu.add(undoItem);

    if (!OSUtils.isMacOS()) {
        redoItem = newJMenuItem(tr("Redo"), 'Y');
    } else {
        redoItem = newJMenuItemShift(tr("Redo"), 'Z');
    }
    redoItem.setName("menuEditRedo");
    redoItem.addActionListener(redoAction = new RedoAction());
    menu.add(redoItem);

    menu.addSeparator();

    JMenuItem cutItem = newJMenuItem(tr("Cut"), 'X');
    cutItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleCut();
        }
      });
    menu.add(cutItem);

    JMenuItem copyItem = newJMenuItem(tr("Copy"), 'C');
    copyItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().getTextArea().copy();
        }
      });
    menu.add(copyItem);

    JMenuItem copyForumItem = newJMenuItemShift(tr("Copy for Forum"), 'C');
    copyForumItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleHTMLCopy();
        }
      });
    menu.add(copyForumItem);

    JMenuItem copyHTMLItem = newJMenuItemAlt(tr("Copy as HTML"), 'C');
    copyHTMLItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleDiscourseCopy();
        }
      });
    menu.add(copyHTMLItem);

    JMenuItem pasteItem = newJMenuItem(tr("Paste"), 'V');
    pasteItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handlePaste();
        }
      });
    menu.add(pasteItem);

    JMenuItem selectAllItem = newJMenuItem(tr("Select All"), 'A');
    selectAllItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleSelectAll();
        }
      });
    menu.add(selectAllItem);

    JMenuItem gotoLine = newJMenuItem(tr("Go to line..."), 'L');
    gotoLine.addActionListener(e -> {
      GoToLineNumber goToLineNumber = new GoToLineNumber(Editor.this);
      goToLineNumber.setLocationRelativeTo(Editor.this);
      goToLineNumber.setVisible(true);
    });
    menu.add(gotoLine);

    menu.addSeparator();

    JMenuItem commentItem = newJMenuItem(tr("Comment/Uncomment"), '/');
    commentItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleCommentUncomment();
        }
    });
    menu.add(commentItem);

    JMenuItem increaseIndentItem = new JMenuItem(tr("Increase Indent"));
    increaseIndentItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_TAB, 0));
    increaseIndentItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleIndentOutdent(true);
        }
    });
    menu.add(increaseIndentItem);

    JMenuItem decreseIndentItem = new JMenuItem(tr("Decrease Indent"));
    decreseIndentItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_TAB, InputEvent.SHIFT_MASK));
    decreseIndentItem.setName("menuDecreaseIndent");
    decreseIndentItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          getCurrentTab().handleIndentOutdent(false);
        }
    });
    menu.add(decreseIndentItem);

    menu.addSeparator();

    JMenuItem findItem = newJMenuItem(tr("Find..."), 'F');
    findItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if (find == null) {
          find = new FindReplace(Editor.this, Base.FIND_DIALOG_STATE);
        }
        if (!OSUtils.isMacOS()) {
          find.setFindText(getCurrentTab().getSelectedText());
        }
        find.setLocationRelativeTo(Editor.this);
        find.setVisible(true);
      }
    });
    menu.add(findItem);

    JMenuItem findNextItem = newJMenuItem(tr("Find Next"), 'G');
    findNextItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if (find != null) {
          find.findNext();
        }
      }
    });
    menu.add(findNextItem);

    JMenuItem findPreviousItem = newJMenuItemShift(tr("Find Previous"), 'G');
    findPreviousItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if (find != null) {
          find.findPrevious();
        }
      }
    });
    menu.add(findPreviousItem);

    if (OSUtils.isMacOS()) {
      JMenuItem useSelectionForFindItem = newJMenuItem(tr("Use Selection For Find"), 'E');
      useSelectionForFindItem.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          if (find == null) {
            find = new FindReplace(Editor.this, Base.FIND_DIALOG_STATE);
          }
          find.setFindText(getCurrentTab().getSelectedText());
        }
      });
      menu.add(useSelectionForFindItem);
    }

    menu.addMenuListener(new MenuListener() {
      @Override
      public void menuSelected(MenuEvent e) {
        boolean enabled = getCurrentTab().getSelectedText() != null;
        cutItem.setEnabled(enabled);
        copyItem.setEnabled(enabled);
      }

      @Override
      public void menuDeselected(MenuEvent e) {}

      @Override
      public void menuCanceled(MenuEvent e) {}
    });

    return menu;
  }


  /**
   * A software engineer, somewhere, needs to have his abstraction
   * taken away. In some countries they jail or beat people for writing
   * the sort of API that would require a five line helper function
   * just to set the command key for a menu item.
   */
  static public JMenuItem newJMenuItem(String title, int what) {
    JMenuItem menuItem = new JMenuItem(title);
    menuItem.setAccelerator(KeyStroke.getKeyStroke(what, SHORTCUT_KEY_MASK));
    return menuItem;
  }


  /**
   * Like newJMenuItem() but adds shift as a modifier for the key command.
   */
  static public JMenuItem newJMenuItemShift(String title, int what) {
    JMenuItem menuItem = new JMenuItem(title);
    menuItem.setAccelerator(KeyStroke.getKeyStroke(what, SHORTCUT_KEY_MASK | ActionEvent.SHIFT_MASK));
    return menuItem;
  }


  /**
   * Same as newJMenuItem(), but adds the ALT (on Linux and Windows)
   * or OPTION (on Mac OS X) key as a modifier.
   */
  private static JMenuItem newJMenuItemAlt(String title, int what) {
    JMenuItem menuItem = new JMenuItem(title);
    menuItem.setAccelerator(KeyStroke.getKeyStroke(what, SHORTCUT_ALT_KEY_MASK));
    return menuItem;
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  class UndoAction extends AbstractAction {
    public UndoAction() {
      super("Undo");
      this.setEnabled(false);
    }

    public void actionPerformed(ActionEvent e) {
      try {
        getCurrentTab().handleUndo();
      } catch (CannotUndoException ex) {
        //System.out.println("Unable to undo: " + ex);
        //ex.printStackTrace();
      }
    }

    protected void updateUndoState() {
      UndoManager undo = getCurrentTab().getUndoManager();

      if (undo.canUndo()) {
        this.setEnabled(true);
        undoItem.setEnabled(true);
        undoItem.setText(undo.getUndoPresentationName());
        putValue(Action.NAME, undo.getUndoPresentationName());
      } else {
        this.setEnabled(false);
        undoItem.setEnabled(false);
        undoItem.setText(tr("Undo"));
        putValue(Action.NAME, "Undo");
      }
    }
  }


  class RedoAction extends AbstractAction {
    public RedoAction() {
      super("Redo");
      this.setEnabled(false);
    }

    public void actionPerformed(ActionEvent e) {
      try {
        getCurrentTab().handleRedo();
      } catch (CannotRedoException ex) {
        //System.out.println("Unable to redo: " + ex);
        //ex.printStackTrace();
      }
    }

    protected void updateRedoState() {
      UndoManager undo = getCurrentTab().getUndoManager();

      if (undo.canRedo()) {
        redoItem.setEnabled(true);
        redoItem.setText(undo.getRedoPresentationName());
        putValue(Action.NAME, undo.getRedoPresentationName());
      } else {
        this.setEnabled(false);
        redoItem.setEnabled(false);
        redoItem.setText(tr("Redo"));
        putValue(Action.NAME, "Redo");
      }
    }
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  // these will be done in a more generic way soon, more like:
  // setHandler("action name", Runnable);
  // but for the time being, working out the kinks of how many things to
  // abstract from the editor in this fashion.


  private void resetHandlers() {
    runHandler = new BuildHandler();
    presentHandler = new BuildHandler(true);
    runAndSaveHandler = new BuildHandler(false, true);
    presentAndSaveHandler = new BuildHandler(true, true);
    exportHandler = new DefaultExportHandler();
    exportAppHandler = new DefaultExportAppHandler();
    timeoutUploadHandler = new TimeoutUploadHandler();
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  /**
   * Gets the current sketch controller.
   */
  public SketchController getSketchController() {
    return sketchController;
  }

  /**
   * Gets the current sketch.
   */
  public Sketch getSketch() {
    return sketch;
  }

  /**
   * Gets the currently displaying tab.
   */
  public EditorTab getCurrentTab() {
    return tabs.get(currentTabIndex);
  }

  /**
   * Gets the index of the currently displaying tab.
   */
  public int getCurrentTabIndex() {
    return currentTabIndex;
  }

  /**
   * Returns an (unmodifiable) list of currently opened tabs.
   */
  public List<EditorTab> getTabs() {
    return Collections.unmodifiableList(tabs);
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
  /**
   * Change the currently displayed tab.
   * Note that the GUI might not update immediately, since this needs
   * to run in the Event dispatch thread.
   * @param index The index of the tab to select
   */
  public void selectTab(final int index) {
    currentTabIndex = index;
    undoAction.updateUndoState();
    redoAction.updateRedoState();
    updateTitle();
    header.rebuild();
    getCurrentTab().activated();

    // This must be run in the GUI thread
    SwingUtilities.invokeLater(() -> {
      codePanel.removeAll();
      codePanel.add(tabs.get(index), BorderLayout.CENTER);
      tabs.get(index).requestFocusInWindow(); // get the caret blinking
      // For some reason, these are needed. Revalidate says it should be
      // automatically called when components are added or removed, but without
      // it, the component switched to is not displayed. repaint() is needed to
      // clear the entire text area of any previous text.
      codePanel.revalidate();
      codePanel.repaint();
    });
  }

  public void selectNextTab() {
    selectTab((currentTabIndex + 1) % tabs.size());
  }

  public void selectPrevTab() {
    selectTab((currentTabIndex - 1 + tabs.size()) % tabs.size());
  }

  public EditorTab findTab(final SketchFile file) {
    return tabs.get(findTabIndex(file));
  }

  /**
   * Finds the index of the tab showing the given file. Matches the file against
   * EditorTab.getSketchFile() using ==.
   *
   * @returns The index of the tab for the given file, or -1 if no such tab was
   *          found.
   */
  public int findTabIndex(final SketchFile file) {
    for (int i = 0; i < tabs.size(); ++i) {
      if (tabs.get(i).getSketchFile() == file)
        return i;
    }
    return -1;
  }

  /**
   * Finds the index of the tab showing the given file. Matches the file against
   * EditorTab.getSketchFile().getFile() using equals.
   *
   * @returns The index of the tab for the given file, or -1 if no such tab was
   *          found.
   */
  public int findTabIndex(final File file) {
    for (int i = 0; i < tabs.size(); ++i) {
      if (tabs.get(i).getSketchFile().getFile().equals(file))
        return i;
    }
    return -1;
  }

  /**
   * Create tabs for each of the current sketch's files, removing any existing
   * tabs.
   */
  public void createTabs() {
    tabs.clear();
    currentTabIndex = -1;
    tabs.ensureCapacity(sketch.getCodeCount());
    for (SketchFile file : sketch.getFiles()) {
      try {
        addTab(file, null);
      } catch(IOException e) {
        // TODO: Improve / move error handling
        System.err.println(e);
      }
    }
    selectTab(0);
  }

  /**
   * Add a new tab.
   *
   * @param file
   *          The file to show in the tab.
   * @param contents
   *          The contents to show in the tab, or null to load the contents from
   *          the given file.
   * @throws IOException
   */
  protected void addTab(SketchFile file, String contents) throws IOException {
    EditorTab tab = new EditorTab(this, file, contents);
    tabs.add(tab);
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void handleFindReference(ActionEvent e) {
    String text = getCurrentTab().getCurrentKeyword();

    String referenceFile = base.getPdeKeywords().getReference(text);
    if (referenceFile == null) {
      statusNotice(I18n.format(tr("No reference available for \"{0}\""), text));
    } else {
      if (referenceFile.startsWith("Serial_")) {
        Base.showReference("Serial/" + referenceFile.substring("Serial_".length()));
      } else {
        Base.showReference("Reference/" + referenceFile);
      }
    }
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  /**
   * Implements Sketch &rarr; Run.
   * @param verbose Set true to run with verbose output.
   * @param verboseHandler
   * @param nonVerboseHandler
   */
  public void handleRun(final boolean verbose, Runnable verboseHandler, Runnable nonVerboseHandler) {
    handleRun(verbose, new ShouldSaveIfModified(), verboseHandler, nonVerboseHandler);
  }

  private void handleRun(final boolean verbose, Predicate<SketchController> shouldSavePredicate, Runnable verboseHandler, Runnable nonVerboseHandler) {
    if (shouldSavePredicate.test(sketchController)) {
      handleSave(true);
    }
    toolbar.activateRun();
    status.progress(tr("Compiling sketch..."));

    // do this to advance/clear the terminal window / dos prompt / etc
    for (int i = 0; i < 10; i++) System.out.println();

    // clear the console on each run, unless the user doesn't want to
    if (PreferencesData.getBoolean("console.auto_clear")) {
      console.clear();
    }

    // Cannot use invokeLater() here, otherwise it gets
    // placed on the event thread and causes a hang--bad idea all around.
    new Thread(verbose ? verboseHandler : nonVerboseHandler).start();
  }

  class BuildHandler implements Runnable {

    private final boolean verbose;
    private final boolean saveHex;

    public BuildHandler() {
      this(false);
    }

    public BuildHandler(boolean verbose) {
      this(verbose, false);
    }

    public BuildHandler(boolean verbose, boolean saveHex) {
      this.verbose = verbose;
      this.saveHex = saveHex;
    }

    @Override
    public void run() {
      try {
        removeAllLineHighlights();
        sketchController.build(verbose, saveHex);
        statusNotice(tr("Done compiling."));
      } catch (PreferencesMapException e) {
        statusError(I18n.format(
                tr("Error while compiling: missing '{0}' configuration parameter"),
                e.getMessage()));
      } catch (Exception e) {
        status.unprogress();
        statusError(e);
      }

      status.unprogress();
      toolbar.deactivateRun();
      avoidMultipleOperations = false;
    }
  }

  public void removeAllLineHighlights() {
    for (EditorTab tab : tabs)
      tab.getTextArea().removeAllLineHighlights();
  }

  public void addLineHighlight(int line) throws BadLocationException {
    getCurrentTab().getTextArea().addLineHighlight(line, new Color(1, 0, 0, 0.2f));
    getCurrentTab().getTextArea().setCaretPosition(getCurrentTab().getTextArea().getLineStartOffset(line));
  }


  /**
   * Implements Sketch &rarr; Stop, or pressing Stop on the toolbar.
   */
  private void handleStop() {  // called by menu or buttons
//    toolbar.activate(EditorToolbar.STOP);

    toolbar.deactivateRun();
//    toolbar.deactivate(EditorToolbar.STOP);

    // focus the PDE again after quitting presentation mode [toxi 030903]
    toFront();
  }

  /**
   * Check if the sketch is modified and ask user to save changes.
   * @return false if canceling the close/quit operation
   */
  protected boolean checkModified() {
    if (!sketch.isModified())
      return true;

    // As of Processing 1.0.10, this always happens immediately.
    // http://dev.processing.org/bugs/show_bug.cgi?id=1456

    toFront();

    String prompt = I18n.format(tr("Save changes to \"{0}\"?  "),
                                sketch.getName());

    if (!OSUtils.isMacOS()) {
      int result =
        JOptionPane.showConfirmDialog(this, prompt, tr("Close"),
                                      JOptionPane.YES_NO_CANCEL_OPTION,
                                      JOptionPane.QUESTION_MESSAGE);

      switch (result) {
        case JOptionPane.YES_OPTION:
          return handleSave(true);
        case JOptionPane.NO_OPTION:
          return true;  // ok to continue
        case JOptionPane.CANCEL_OPTION:
        case JOptionPane.CLOSED_OPTION:  // Escape key pressed
          return false;
        default:
          throw new IllegalStateException();
      }

    } else {
      // This code is disabled unless Java 1.5 is being used on Mac OS X
      // because of a Java bug that prevents the initial value of the
      // dialog from being set properly (at least on my MacBook Pro).
      // The bug causes the "Don't Save" option to be the highlighted,
      // blinking, default. This sucks. But I'll tell you what doesn't
      // suck--workarounds for the Mac and Apple's snobby attitude about it!
      // I think it's nifty that they treat their developers like dirt.

      JOptionPane pane =
        new JOptionPane(tr("<html> " +
                          "<head> <style type=\"text/css\">"+
                          "b { font: 13pt \"Lucida Grande\" }"+
                          "p { font: 11pt \"Lucida Grande\"; margin-top: 8px }"+
                          "</style> </head>" +
                          "<b>Do you want to save changes to this sketch<BR>" +
                          " before closing?</b>" +
                          "<p>If you don't save, your changes will be lost."),
                        JOptionPane.QUESTION_MESSAGE);

      String[] options = new String[] {
        tr("Save"), tr("Cancel"), tr("Don't Save")
      };
      pane.setOptions(options);

      // highlight the safest option ala apple hig
      pane.setInitialValue(options[0]);

      JDialog dialog = pane.createDialog(this, null);
      dialog.setVisible(true);

      Object result = pane.getValue();
      if (result == options[0]) {  // save (and close/quit)
        return handleSave(true);
      } else {
        return result == options[2];
      }
    }
  }

  /**
   * Second stage of open, occurs after having checked to see if the
   * modifications (if any) to the previous sketch need to be saved.
   */
  protected boolean handleOpenInternal(File sketchFile) {
    // check to make sure that this .pde file is
    // in a folder of the same name
    String fileName = sketchFile.getName();

    File file = Sketch.checkSketchFile(sketchFile);

    if (file == null) {
      if (!fileName.endsWith(".ino") && !fileName.endsWith(".pde")) {

        Base.showWarning(tr("Bad file selected"), tr("Arduino can only open its own sketches\n" +
          "and other files ending in .ino or .pde"), null);
        return false;

      } else {
        String properParent = fileName.substring(0, fileName.length() - 4);

        Object[] options = {tr("OK"), tr("Cancel")};
        String prompt = I18n.format(tr("The file \"{0}\" needs to be inside\n" +
            "a sketch folder named \"{1}\".\n" +
            "Create this folder, move the file, and continue?"),
          fileName,
          properParent);

        int result = JOptionPane.showOptionDialog(this, prompt, tr("Moving"), JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, options, options[0]);

        if (result != JOptionPane.YES_OPTION) {
          return false;
        }

        // create properly named folder
        File properFolder = new File(sketchFile.getParent(), properParent);
        if (properFolder.exists()) {
          Base.showWarning(tr("Error"), I18n.format(tr("A folder named \"{0}\" already exists. " +
            "Can't open sketch."), properParent), null);
          return false;
        }
        if (!properFolder.mkdirs()) {
          //throw new IOException("Couldn't create sketch folder");
          Base.showWarning(tr("Error"), tr("Could not create the sketch folder."), null);
          return false;
        }
        // copy the sketch inside
        File properPdeFile = new File(properFolder, sketchFile.getName());
        try {
          Base.copyFile(sketchFile, properPdeFile);
        } catch (IOException e) {
          Base.showWarning(tr("Error"), tr("Could not copy to a proper location."), e);
          return false;
        }

        // remove the original file, so user doesn't get confused
        sketchFile.delete();

        // update with the new path
        file = properPdeFile;

      }
    }

    try {
      sketch = new Sketch(file);
    } catch (IOException e) {
      Base.showWarning(tr("Error"), tr("Could not create the sketch."), e);
      return false;
    }
    sketchController = new SketchController(this, sketch);
    createTabs();

    // Disable untitled setting from previous document, if any
    untitled = false;

    // opening was successful
    return true;
  }

  private void updateTitle() {
    if (sketchController == null) {
      return;
    }
    SketchFile current = getCurrentTab().getSketchFile();
    if (current.isPrimary()) {
      setTitle(I18n.format(tr("{0} | Arduino {1}"), sketch.getName(),
                           BaseNoGui.VERSION_NAME_LONG));
    } else {
      setTitle(I18n.format(tr("{0} - {1} | Arduino {2}"), sketch.getName(),
                           current.getFileName(), BaseNoGui.VERSION_NAME_LONG));
    }
  }


  /**
   * Actually handle the save command. If 'immediately' is set to false,
   * this will happen in another thread so that the message area
   * will update and the save button will stay highlighted while the
   * save is happening. If 'immediately' is true, then it will happen
   * immediately. This is used during a quit, because invokeLater()
   * won't run properly while a quit is happening. This fixes
   * <A HREF="http://dev.processing.org/bugs/show_bug.cgi?id=276">Bug 276</A>.
   */
  public boolean handleSave(boolean immediately) {
    //stopRunner();
    handleStop();  // 0136
    removeAllLineHighlights();

    if (untitled) {
      return handleSaveAs();
      // need to get the name, user might also cancel here

    } else if (immediately) {
      return handleSave2();

    } else {
      SwingUtilities.invokeLater(new Runnable() {
          public void run() {
            handleSave2();
          }
        });
    }
    return true;
  }


  private boolean handleSave2() {
    toolbar.activateSave();
    statusNotice(tr("Saving..."));
    boolean saved = false;
    try {
      boolean wasReadOnly = sketchController.isReadOnly(BaseNoGui.librariesIndexer.getInstalledLibraries(), BaseNoGui.getExamplesPath());
      String previousMainFilePath = sketch.getMainFilePath();
      saved = sketchController.save();
      if (saved) {
        statusNotice(tr("Done Saving."));
        if (wasReadOnly) {
          base.removeRecentSketchPath(previousMainFilePath);
        }
        base.storeRecentSketches(sketchController);
        base.rebuildRecentSketchesMenuItems();
      } else {
        statusEmpty();
      }
      // rebuild sketch menu in case a save-as was forced
      // Disabling this for 0125, instead rebuild the menu inside
      // the Save As method of the Sketch object, since that's the
      // only one who knows whether something was renamed.
      //sketchbook.rebuildMenus();
      //sketchbook.rebuildMenusAsync();

    } catch (Exception e) {
      // show the error as a message in the window
      statusError(e);

      // zero out the current action,
      // so that checkModified2 will just do nothing
      //checkModifiedMode = 0;
      // this is used when another operation calls a save
    }
    //toolbar.clear();
    toolbar.deactivateSave();
    return saved;
  }


  public boolean handleSaveAs() {
    //stopRunner();  // formerly from 0135
    handleStop();

    toolbar.activateSave();

    //SwingUtilities.invokeLater(new Runnable() {
    //public void run() {
    statusNotice(tr("Saving..."));
    try {
      if (sketchController.saveAs()) {
        base.storeRecentSketches(sketchController);
        base.rebuildRecentSketchesMenuItems();
        statusNotice(tr("Done Saving."));
        // Disabling this for 0125, instead rebuild the menu inside
        // the Save As method of the Sketch object, since that's the
        // only one who knows whether something was renamed.
        //sketchbook.rebuildMenusAsync();
      } else {
        statusNotice(tr("Save Canceled."));
        return false;
      }
    } catch (Exception e) {
      // show the error as a message in the window
      statusError(e);

    } finally {
      // make sure the toolbar button deactivates
      toolbar.deactivateSave();

      // Update editor window title in case of "Save as..."
      updateTitle();
    }

    return true;
  }


  private boolean serialPrompt() {
    int count = portMenu.getItemCount();
    Object[] names = new Object[count];
    for (int i = 0; i < count; i++) {
      names[i] = portMenu.getItem(i).getText();
    }

    String result = (String)
      JOptionPane.showInputDialog(this,
	I18n.format(
	  tr("Serial port {0} not found.\n" +
	    "Retry the upload with another serial port?"),
	  PreferencesData.get("serial.port")
	),
				  "Serial port not found",
                                  JOptionPane.PLAIN_MESSAGE,
                                  null,
                                  names,
                                  0);
    if (result == null) return false;
    selectSerialPort(result);
    base.onBoardOrPortChange();
    return true;
  }


  /**
   * Called by Sketch &rarr; Export.
   * Handles calling the export() function on sketch, and
   * queues all the gui status stuff that comes along with it.
   * <p/>
   * Made synchronized to (hopefully) avoid problems of people
   * hitting export twice, quickly, and horking things up.
   */
  /**
   * Handles calling the export() function on sketch, and
   * queues all the gui status stuff that comes along with it.
   *
   * Made synchronized to (hopefully) avoid problems of people
   * hitting export twice, quickly, and horking things up.
   */
  synchronized public void handleExport(final boolean usingProgrammer) {
    if (PreferencesData.getBoolean("editor.save_on_verify")) {
      if (sketch.isModified()
          && !sketchController.isReadOnly(
                                          BaseNoGui.librariesIndexer
                                              .getInstalledLibraries(),
                                          BaseNoGui.getExamplesPath())) {
        handleSave(true);
      }
    }
    toolbar.activateExport();
    console.clear();
    status.progress(tr("Uploading to I/O Board..."));

    new Thread(timeoutUploadHandler).start();
    new Thread(usingProgrammer ? exportAppHandler : exportHandler).start();
  }

  // DAM: in Arduino, this is upload
  class DefaultExportHandler implements Runnable {
    public void run() {

      try {
        removeAllLineHighlights();
        if (serialMonitor != null) {
          serialMonitor.suspend();
        }
        if (serialPlotter != null) {
          serialPlotter.suspend();
        }

        uploading = true;

        boolean success = sketchController.exportApplet(false);
        if (success) {
          statusNotice(tr("Done uploading."));
        }
      } catch (SerialNotFoundException e) {
        if (portMenu.getItemCount() == 0) statusError(e);
        else if (serialPrompt()) run();
        else statusNotice(tr("Upload canceled."));
      } catch (PreferencesMapException e) {
        statusError(I18n.format(
                    tr("Error while uploading: missing '{0}' configuration parameter"),
                    e.getMessage()));
      } catch (RunnerException e) {
        //statusError("Error during upload.");
        //e.printStackTrace();
        status.unprogress();
        statusError(e);
      } catch (Exception e) {
        e.printStackTrace();
      } finally {
        populatePortMenu();
        avoidMultipleOperations = false;
      }
      status.unprogress();
      uploading = false;
      //toolbar.clear();
      toolbar.deactivateExport();

      resumeOrCloseSerialMonitor();
      resumeOrCloseSerialPlotter();
      base.onBoardOrPortChange();
    }
  }

  private void resumeOrCloseSerialMonitor() {
    // Return the serial monitor window to its initial state
    if (serialMonitor != null) {
      BoardPort boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
      long sleptFor = 0;
      while (boardPort == null && sleptFor < MAX_TIME_AWAITING_FOR_RESUMING_SERIAL_MONITOR) {
        try {
          Thread.sleep(100);
          sleptFor += 100;
          boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
        } catch (InterruptedException e) {
          // noop
        }
      }
      try {
        if (serialMonitor != null) {
          serialMonitor.resume(boardPort);
          if (boardPort == null) {
            serialMonitor.close();
            handleSerial();
          } else {
            serialMonitor.resume(boardPort);
          }
        }
      } catch (Exception e) {
        statusError(e);
      }
   }
  }

  private void resumeOrCloseSerialPlotter() {
    // Return the serial plotter window to its initial state
    if (serialPlotter != null) {
      BoardPort boardPort = BaseNoGui.getDiscoveryManager().find(PreferencesData.get("serial.port"));
      try {
        if (serialPlotter != null)
          serialPlotter.resume(boardPort);
        if (boardPort == null) {
          serialPlotter.close();
          handlePlotter();
        } else {
          serialPlotter.resume(boardPort);
        }
      } catch (Exception e) {
        statusError(e);
      }
   }
  }

  // DAM: in Arduino, this is upload (with verbose output)
  class DefaultExportAppHandler implements Runnable {
    public void run() {

      try {
        if (serialMonitor != null) {
          serialMonitor.suspend();
        }
        if (serialPlotter != null) {
          serialPlotter.suspend();
        }

        uploading = true;

        boolean success = sketchController.exportApplet(true);
        if (success) {
          statusNotice(tr("Done uploading."));
        }
      } catch (SerialNotFoundException e) {
        if (portMenu.getItemCount() == 0) statusError(e);
        else if (serialPrompt()) run();
        else statusNotice(tr("Upload canceled."));
      } catch (PreferencesMapException e) {
        statusError(I18n.format(
                    tr("Error while uploading: missing '{0}' configuration parameter"),
                    e.getMessage()));
      } catch (RunnerException e) {
        //statusError("Error during upload.");
        //e.printStackTrace();
        status.unprogress();
        statusError(e);
      } catch (Exception e) {
        e.printStackTrace();
      } finally {
        avoidMultipleOperations = false;
        populatePortMenu();
      }
      status.unprogress();
      uploading = false;
      //toolbar.clear();
      toolbar.deactivateExport();

      resumeOrCloseSerialMonitor();
      resumeOrCloseSerialPlotter();

      base.onBoardOrPortChange();
    }
  }

  class TimeoutUploadHandler implements Runnable {

    public void run() {
      try {
        //10 seconds, than reactivate upload functionality and let the programmer pid being killed
        Thread.sleep(1000 * 10);
        if (uploading) {
          avoidMultipleOperations = false;
        }
      } catch (InterruptedException e) {
          // noop
      }
    }
  }

  public void handleSerial() {
    if(serialPlotter != null) {
      if(serialPlotter.isClosed()) {
        serialPlotter = null;
      } else {
        statusError(tr("Serial monitor not available while plotter is open"));
        return;
      }
    }
  
    if (serialMonitor != null) {
      // The serial monitor already exists

      if (serialMonitor.isClosed()) {
        serialMonitor.dispose();
        // If it's closed, clear the refrence to the existing
        // monitor and create a new one
        serialMonitor = null;
      }
      else {
        // If it's not closed, give it the focus
        try {
          serialMonitor.toFront();
          serialMonitor.requestFocus();
          return;
        } catch (Exception e) {
          // noop
        }
      }
    }

    BoardPort port = Base.getDiscoveryManager().find(PreferencesData.get("serial.port"));

    if (port == null) {
      statusError(I18n.format(tr("Board at {0} is not available"), PreferencesData.get("serial.port")));
      return;
    }

    serialMonitor = new MonitorFactory().newMonitor(port);
    Base.setIcon(serialMonitor);

    // If currently uploading, disable the monitor (it will be later
    // enabled when done uploading)
    if (uploading || avoidMultipleOperations) {
      try {
        serialMonitor.suspend();
      } catch (Exception e) {
        statusError(e);
      }
    }

    boolean success = false;
    do {
      if (serialMonitor.requiresAuthorization() && !PreferencesData.has(serialMonitor.getAuthorizationKey())) {
        PasswordAuthorizationDialog dialog = new PasswordAuthorizationDialog(this, tr("Type board password to access its console"));
        dialog.setLocationRelativeTo(this);
        dialog.setVisible(true);

        if (dialog.isCancelled()) {
          statusNotice(tr("Unable to open serial monitor"));
          return;
        }

        PreferencesData.set(serialMonitor.getAuthorizationKey(), dialog.getPassword());
      }

      try {
        serialMonitor.setVisible(true);
        if (!avoidMultipleOperations) {
          serialMonitor.open();
        }
        success = true;
      } catch (ConnectException e) {
        statusError(tr("Unable to connect: is the sketch using the bridge?"));
      } catch (JSchException e) {
        statusError(tr("Unable to connect: wrong password?"));
      } catch (SerialException e) {
        String errorMessage = e.getMessage();
        if (e.getCause() != null && e.getCause() instanceof SerialPortException) {
          errorMessage += " (" + ((SerialPortException) e.getCause()).getExceptionType() + ")";
        }
        statusError(errorMessage);
        try {
          serialMonitor.close();
        } catch (Exception e1) {
          // noop
        }
      } catch (Exception e) {
        statusError(e);
      } finally {
        if (serialMonitor.requiresAuthorization() && !success) {
          PreferencesData.remove(serialMonitor.getAuthorizationKey());
        }
      }

    } while (serialMonitor.requiresAuthorization() && !success);

  }
  
  public void handlePlotter() {
    if(serialMonitor != null) {
      if(serialMonitor.isClosed()) {
        serialMonitor = null;
      } else {
        statusError(tr("Plotter not available while serial monitor is open"));
        return;
      }
    }
  
    if (serialPlotter != null) {
      // The serial plotter already exists

      if (serialPlotter.isClosed()) {
        // If it's closed, clear the refrence to the existing
        // plotter and create a new one
        serialPlotter = null;
      }
      else {
        // If it's not closed, give it the focus
        try {
          serialPlotter.toFront();
          serialPlotter.requestFocus();
          return;
        } catch (Exception e) {
          // noop
        }
      }
    }

    BoardPort port = Base.getDiscoveryManager().find(PreferencesData.get("serial.port"));

    if (port == null) {
      statusError(I18n.format(tr("Board at {0} is not available"), PreferencesData.get("serial.port")));
      return;
    }

    serialPlotter = new SerialPlotter(port);
    Base.setIcon(serialPlotter);

    // If currently uploading, disable the plotter (it will be later
    // enabled when done uploading)
    if (uploading) {
      try {
        serialPlotter.suspend();
      } catch (Exception e) {
        statusError(e);
      }
    }

    boolean success = false;
    do {
      if (serialPlotter.requiresAuthorization() && !PreferencesData.has(serialPlotter.getAuthorizationKey())) {
        PasswordAuthorizationDialog dialog = new PasswordAuthorizationDialog(this, tr("Type board password to access its console"));
        dialog.setLocationRelativeTo(this);
        dialog.setVisible(true);

        if (dialog.isCancelled()) {
          statusNotice(tr("Unable to open serial plotter"));
          return;
        }

        PreferencesData.set(serialPlotter.getAuthorizationKey(), dialog.getPassword());
      }

      try {
        serialPlotter.open();
        serialPlotter.setVisible(true);
        success = true;
      } catch (ConnectException e) {
        statusError(tr("Unable to connect: is the sketch using the bridge?"));
      } catch (JSchException e) {
        statusError(tr("Unable to connect: wrong password?"));
      } catch (SerialException e) {
        String errorMessage = e.getMessage();
        if (e.getCause() != null && e.getCause() instanceof SerialPortException) {
          errorMessage += " (" + ((SerialPortException) e.getCause()).getExceptionType() + ")";
        }
        statusError(errorMessage);
      } catch (Exception e) {
        statusError(e);
      } finally {
        if (serialPlotter.requiresAuthorization() && !success) {
          PreferencesData.remove(serialPlotter.getAuthorizationKey());
        }
      }

    } while (serialPlotter.requiresAuthorization() && !success);

  }

  private void handleBurnBootloader() {
    console.clear();
    statusNotice(tr("Burning bootloader to I/O Board (this may take a minute)..."));
    new Thread(() -> {
      try {
        Uploader uploader = new SerialUploader();
        if (uploader.burnBootloader()) {
          SwingUtilities.invokeLater(() -> statusNotice(tr("Done burning bootloader.")));
        } else {
          SwingUtilities.invokeLater(() -> statusError(tr("Error while burning bootloader.")));
          // error message will already be visible
        }
      } catch (PreferencesMapException e) {
        SwingUtilities.invokeLater(() -> {
          statusError(I18n.format(
            tr("Error while burning bootloader: missing '{0}' configuration parameter"),
            e.getMessage()));
        });
      } catch (RunnerException e) {
        SwingUtilities.invokeLater(() -> statusError(e.getMessage()));
      } catch (Exception e) {
        SwingUtilities.invokeLater(() -> statusError(tr("Error while burning bootloader.")));
        e.printStackTrace();
      }
    }).start();
  }

  private void handleBoardInfo() {
    console.clear();

    String selectedPort = PreferencesData.get("serial.port");
    List<BoardPort> ports = Base.getDiscoveryManager().discovery();

    String label = "";
    String vid = "";
    String pid = "";
    String iserial = "";
    String protocol = "";
    boolean found = false;

    for (BoardPort port : ports) {
      if (port.getAddress().equals(selectedPort)) {
        label = port.getBoardName();
        vid = port.getVID();
        pid = port.getPID();
        iserial = port.getISerial();
        protocol = port.getProtocol();
        found = true;
        break;
      }
    }

    if (!found) {
      statusNotice(tr("Please select a port to obtain board info"));
      return;
    }

    if (protocol.equals("network")) {
      statusNotice(tr("Network port, can't obtain info"));
      return;
    }

    if (vid == null || vid.equals("") || vid.equals("0000")) {
      statusNotice(tr("Native serial port, can't obtain info"));
      return;
    }

    if (iserial == null || iserial.equals("")) {
      iserial = tr("Upload any sketch to obtain it");
    }

    if (label == null) {
      label = tr("Unknown board");
    }

    String infos = I18n.format("BN: {0}\nVID: {1}\nPID: {2}\nSN: {3}", label, vid, pid, iserial);
    JTextArea textArea = new JTextArea(infos);

    JOptionPane.showMessageDialog(this, textArea, tr("Board Info"), JOptionPane.PLAIN_MESSAGE);
  }

  /**
   * Handler for File &rarr; Page Setup.
   */
  private void handlePageSetup() {
    PrinterJob printerJob = PrinterJob.getPrinterJob();
    if (pageFormat == null) {
      pageFormat = printerJob.defaultPage();
    }
    pageFormat = printerJob.pageDialog(pageFormat);
  }


  /**
   * Handler for File &rarr; Print.
   */
  private void handlePrint() {
    statusNotice(tr("Printing..."));
    //printerJob = null;
    PrinterJob printerJob = PrinterJob.getPrinterJob();
    if (pageFormat != null) {
      //System.out.println("setting page format " + pageFormat);
      printerJob.setPrintable(getCurrentTab().getTextArea(), pageFormat);
    } else {
      printerJob.setPrintable(getCurrentTab().getTextArea());
    }
    // set the name of the job to the code name
    printerJob.setJobName(getCurrentTab().getSketchFile().getPrettyName());

    if (printerJob.printDialog()) {
      try {
        printerJob.print();
        statusNotice(tr("Done printing."));

      } catch (PrinterException pe) {
        statusError(tr("Error while printing."));
        pe.printStackTrace();
      }
    } else {
      statusNotice(tr("Printing canceled."));
    }
    //printerJob = null;  // clear this out?
  }


  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  /**
   * Show an error int the status bar.
   */
  public void statusError(String what) {
    System.err.println(what);
    status.error(what);
    //new Exception("deactivating RUN").printStackTrace();
    toolbar.deactivateRun();
  }


  /**
   * Show an exception in the editor status bar.
   */
  public void statusError(Exception e) {
    e.printStackTrace();
//    if (e == null) {
//      System.err.println("Editor.statusError() was passed a null exception.");
//      return;
//    }

    if (e instanceof RunnerException) {
      RunnerException re = (RunnerException) e;
      if (re.hasCodeFile()) {
        selectTab(findTabIndex(re.getCodeFile()));
      }
      if (re.hasCodeLine()) {
        int line = re.getCodeLine();
        // subtract one from the end so that the \n ain't included
        if (line >= getCurrentTab().getTextArea().getLineCount()) {
          // The error is at the end of this current chunk of code,
          // so the last line needs to be selected.
          line = getCurrentTab().getTextArea().getLineCount() - 1;
          if (getCurrentTab().getLineText(line).length() == 0) {
            // The last line may be zero length, meaning nothing to select.
            // If so, back up one more line.
            line--;
          }
        }
        if (line < 0 || line >= getCurrentTab().getTextArea().getLineCount()) {
          System.err.println(I18n.format(tr("Bad error line: {0}"), line));
        } else {
          try {
            addLineHighlight(line);
          } catch (BadLocationException e1) {
            e1.printStackTrace();
          }
        }
      }
    }

    // Since this will catch all Exception types, spend some time figuring
    // out which kind and try to give a better error message to the user.
    String mess = e.getMessage();
    if (mess != null) {
      String javaLang = "java.lang.";
      if (mess.indexOf(javaLang) == 0) {
        mess = mess.substring(javaLang.length());
      }
      String rxString = "RuntimeException: ";
      if (mess.indexOf(rxString) == 0) {
        mess = mess.substring(rxString.length());
      }
      statusError(mess);
    }
//    e.printStackTrace();
  }


  /**
   * Show a notice message in the editor status bar.
   */
  public void statusNotice(String msg) {
    status.notice(msg);
  }


  /**
   * Clear the status area.
   */
  private void statusEmpty() {
    statusNotice(EMPTY);
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  protected void onBoardOrPortChange() {
    Map<String, String> boardPreferences = BaseNoGui.getBoardPreferences();
    if (boardPreferences != null)
      lineStatus.setBoardName(boardPreferences.get("name"));
    else
      lineStatus.setBoardName("-");
    lineStatus.setSerialPort(PreferencesData.get("serial.port"));
    lineStatus.repaint();
  }


}
