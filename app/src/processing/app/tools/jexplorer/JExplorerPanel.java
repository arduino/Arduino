/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.datatransfer.Transferable;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.FileFilter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JComponent;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;
import javax.swing.event.TreeExpansionEvent;
import javax.swing.event.TreeExpansionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.MutableTreeNode;
import javax.swing.tree.TreeNode;
import javax.swing.tree.TreePath;
import javax.swing.tree.TreeSelectionModel;


import processing.app.I18n;
import processing.app.tools.jexplorer.FileTreeModel.FileTreeNode;
import processing.app.tools.jexplorer.utils.Translate;
import processing.app.tools.jexplorer.utils.LimitedQueue;
import processing.app.tools.jexplorer.dnd.FileTransferHandler.*;
import processing.app.tools.jexplorer.dnd.FileTransferHandler;
import processing.app.tools.jexplorer.dnd.FileTreeDragSource;
import processing.app.tools.jexplorer.FileOperation.*;


/**
 * A file explorer supporting file operations (copy, delete, remove) and others and with drag & drop support <br/>
 * It was designed to be used in the context of a specific project directory (Workspace). <br/>
 * It is not designed to browse a full file system.
 * @author Ricardo JL Rufino - (ricardo.jl.rufino@gmail.com)
 * @date 24 de mai de 2020
 */
public class JExplorerPanel extends JPanel {

  private static final long serialVersionUID = 1L;

  /** File-system tree. Built Lazily */
  private JTree tree;
  private FileTreeModel treeModel;
  
  protected JPopupMenu popup;

  private File rootDir;
  
  private FileTreeNode rootNode;

  private Translate translate;

  
  // Alow Ctrl+Z last file operation.
  private LimitedQueue<FileOperation> undoQueue = new LimitedQueue<FileOperation>(5);

  private FileTransferable currentFileTransferable;
  
  public JExplorerPanel(File rootDir) {
    super();
    this.rootDir = rootDir;
    initComponents();
    initMenus();
    initKeyboard();
  }

  private void initComponents() {

    setLayout(new BorderLayout());

    // the File tree
    rootNode = new FileTreeNode(rootDir);

    // Populate the root node with its subdirectories
    rootNode.populateDirectories(true);

    treeModel = new FileTreeModel(rootNode);

    // TreeSelectionListener treeSelectionListener = new TreeSelectionListener() {
    // public void valueChanged(TreeSelectionEvent tse) {
    // // Double clicik ?!
    // }
    // };
    
    tree = new JTree(treeModel);
    tree.setRootVisible(true);
    tree.setEditable(false);
    tree.getSelectionModel().setSelectionMode(TreeSelectionModel.CONTIGUOUS_TREE_SELECTION);
//    tree.setDragEnabled(false);
//    tree.setDropMode(DropMode.USE_SELECTION);
    
    // tree.addTreeSelectionListener(treeSelectionListener);
    tree.setCellRenderer(new FileTreeCellRenderer());

    // Listen for Tree Selection Events
    tree.addTreeExpansionListener(new TreeExpansionHandler());
    
    tree.setTransferHandler(new FileTransferHandler() {
      @Override
      public void handleTranferFile(List<File> files) {
        try {
          if (currentFileTransferable instanceof FileTransferable) { // from Internal DnD Move / Ctrl+X
            JExplorerPanel.this.handleTransferFile(files, currentFileTransferable.isMove());
          } else {
            JExplorerPanel.this.handleTransferFile(files, false);
          }
        } catch (IOException e) {
          showException(e.getMessage(), e);
        }
      }
    });
    
    tree.addMouseListener(new MouseAdapter() {
      public void mouseReleased(MouseEvent e) {
        if (e.getClickCount() == 2) {
          int selRow = tree.getRowForLocation(e.getX(), e.getY());
          if (selRow > -1) {
            tree.setSelectionRow(selRow);
            handleOpen();
          }
        }
      }
    });
    
    // Internal DND support
    FileTreeDragSource.install(this);

    JScrollPane treeScroll = new JScrollPane(tree);

    Dimension preferredSize = treeScroll.getPreferredSize();
    Dimension widePreferred = new Dimension(200, (int) preferredSize.getHeight());
    treeScroll.setPreferredSize(widePreferred);

    add(treeScroll);
    
    configureTree(tree);
    
    // translete
    translate = new Translate() {
      @Override
      public String get(String name) {
        return tr(name);
      }
    };
    
  }
  
  protected void initMenus() {
    popup = new JPopupMenu();
    
    addMenu(tr("Add File"), KeyEvent.VK_F, e -> {
        handleAddNew(false);
    });
    
    addMenu(tr("Add Directory"), KeyEvent.VK_D, e -> {
        handleAddNew(true);
    });
    
    addMenu(tr("Refresh"), KeyStroke.getKeyStroke(KeyEvent.VK_F5, 0), e -> {
      handleReload();
    });
    
    popup.addSeparator();
    
    addMenu(tr("Rename"), KeyStroke.getKeyStroke(KeyEvent.VK_F2, 0), e -> {
        handleRename();
    });
    
    addMenu(tr("Cut"), "control X", e -> {
        handleCut();
    });
    
    addMenu(tr("Copy"), "control C", e -> {
        handleCopy();
    });
    
    addMenu(tr("Paste"), "control V", e -> {
        handlePaste();
    });
    
    addMenu(tr("Delete"), KeyStroke.getKeyStroke(KeyEvent.VK_DELETE, 0), e -> {
        handleDelete();
    });
    
    popup.addSeparator();
    
    addMenu(tr("Properties"), "alt ENTER", e -> {
      handleProperties();
    });

    tree.addMouseListener(new MouseAdapter() {
      public void mouseReleased(MouseEvent e) {
        if (SwingUtilities.isRightMouseButton(e)) {
          int selRow = tree.getRowForLocation(e.getX(), e.getY());
          if (selRow > -1) {
            tree.setSelectionRow(selRow);
          }else {
            tree.clearSelection(); // allow root operations..
          }
          popup.show((JComponent) e.getSource(), e.getX(), e.getY());
        }
      }
    });
    
    configureMenu(popup);
  }
  
  protected void initKeyboard() {
    
    tree.addKeyListener(new KeyAdapter() {
      @Override
      public void keyPressed(KeyEvent evt) {
        
        if (KeyEvent.VK_DELETE == evt.getKeyCode()) {
          
          handleDelete();
          
        }else if (evt.isAltDown() && evt.getKeyCode() == KeyEvent.VK_ENTER ) {
          
          handleProperties();
          
        }else if (KeyEvent.VK_ENTER == evt.getKeyCode()) {
          
          handleOpen();         
          
        }else if (KeyEvent.VK_F2 == evt.getKeyCode()) {
          
          handleRename();
          
        }else if (KeyEvent.VK_F5 == evt.getKeyCode()) {
          
          handleReload();
          
        }else if (evt.isControlDown() && evt.getKeyCode() == KeyEvent.VK_C) {
          
          handleCopy();
          
        } else if (evt.isControlDown() && evt.getKeyCode() == KeyEvent.VK_X) {
          
          handleCut();
          
        } else if (evt.isControlDown() && evt.getKeyCode() == KeyEvent.VK_V) {
          
          // Handler by default by JTree
        } else if (evt.isControlDown() && evt.getKeyCode() == KeyEvent.VK_Z) {
          
          handleUndo();
          
        }
      }

    });
  }
  
  // ================================================================
  // Access
  // ================================================================
  
  /* used for DND actions */
  public void setCurrentFileTransferable(FileTransferable currentFileTransferable) {
    this.currentFileTransferable = currentFileTransferable;
  }
  
  public void setFileFilter(FileFilter fileFilter) {
    treeModel.setFileFilter(fileFilter);
  }
  
  public JTree getTree() {
    return tree;
  }
  
  /**
   * Change root directory
   */
  public void replaceWorkingDirectory( File selectedFile ) {
      this.rootDir = selectedFile;

      FileFilter fileFilter=rootNode.getFileFilter();

      // the File tree
      rootNode = new FileTreeNode(rootDir);

      rootNode.setFileFilter(fileFilter);

      // Populate the root node with its subdirectories
      rootNode.populateDirectories(true);
      
      treeModel = new FileTreeModel(rootNode);
      
      tree.setModel(treeModel);
      
      undoQueue.clear();
  }

  private JMenuItem addMenu(String title, int mnemonic, ActionListener actionListener) {
    JMenuItem mi = new JMenuItem(title);
    mi.setMnemonic(mnemonic);
    mi.addActionListener(actionListener);
    popup.add(mi);
    return mi;
  }

  private JMenuItem addMenu(String title, String acelerator, ActionListener actionListener) {
    return addMenu(title, KeyStroke.getKeyStroke(acelerator), actionListener);
  }
  private JMenuItem addMenu(String title, KeyStroke keyStroke, ActionListener actionListener) {
    JMenuItem mi = new JMenuItem(title);
    mi.setAccelerator(keyStroke);;
    mi.addActionListener(actionListener);
    popup.add(mi);
    return mi;
  }
  
  // ================================================================
  // To override
  // ================================================================

  /**
   * Handle translation
   */
  protected String tr(String name) {
    return I18n.tr(name);
  }
  
  protected void log(String message) {
    System.out.println("[JEXPLORER]: " + message);
  }
  
  private void showMessage(String message) {
    JOptionPane.showMessageDialog(this, message);
  }
  
  private void showErrorMessage(String title, String message) {
    JOptionPane.showMessageDialog(this, message, title, JOptionPane.INFORMATION_MESSAGE);
  }
  
  public void showException(String string, Exception e) {
    e.printStackTrace();
  }
  
  protected void configureTree(JTree tree) {};
  
  protected void configureMenu(JPopupMenu popup) {};
  
  // ================================================================
  // Actions
  // ================================================================
  
  protected void handleAddNew(boolean directory) {
    
    String name = JOptionPane.showInputDialog(this, (directory ? tr("New Directory") : tr("New File")));

    // Check if user quit dialog
    if(name == null){
      return;
    }
    TreePath selectionPath = getSelectedPathOrRoot();
    DefaultMutableTreeNode parentNode = (DefaultMutableTreeNode) selectionPath.getLastPathComponent();
    File parentFile = (File) parentNode.getUserObject();
    
    if(parentFile == null) {
      showMessage(tr("Please select a folder to add"));
      return;
    }
    
    // get parent
    if(parentFile.isFile()) {
      parentFile = parentFile.getParentFile();
      selectionPath = selectionPath.getParentPath();
    }

    File file = new File(parentFile, name);
    
    if(file.exists()) {
        showMessage(tr("File already exists"));
        return;
    }
    
    // Create Files
    try {
      
      if(directory) file.mkdir();
      else file.createNewFile();
      
    } catch (Exception e) {
        showErrorMessage("Error creating file or directory", e.getMessage());
    }
    
    insertFileIntoTree(file, selectionPath);
    
  }
  
  protected void handleReload() {
    System.out.println("reload...");
    FileTreeNode node = (FileTreeNode) getSelectedPathOrRoot().getLastPathComponent();
    if(node == null) return;
    
    boolean rootChanged = detectRootChanges();
    
    if(rootChanged) {
      log("Root files changed, reload all...");
      node = rootNode;
    }
    
    node.reloadChildren();
    treeModel.nodeStructureChanged(node);
  }
  
  /**
   * Detect new external files on root directory
   */
  private boolean detectRootChanges() {
    File[] listFiles = rootDir.listFiles(treeModel.getFileFilter());
    return rootNode.getChildCount() != listFiles.length;
  }
  
  /**
   * Callend from Enter and Double-Click on JTree
   * By default allow only file selection.
   * @see #handleOpenFile(File)
   */
  protected void handleOpen() {
    FileTreeNode selectedNode = getSelectedNode();
    if(selectedNode != null && selectedNode.isLeaf() &&  validateSelectionPaths()) {
      handleOpenFile(getSelectedFile());
    }
  }
  

  protected void handleProperties() {
    
    if(validateSelectionPaths()) {
      File selectedFile = getSelectedFile();
      FilePropertiesDialog dialog = new FilePropertiesDialog(selectedFile, translate);
      dialog.setLocationRelativeTo(this);
      dialog.setVisible(true);
    }
  }
  
  
  protected void handleOpenFile(File file) {}

  protected void handleRename() {

    FileTreeNode selectedNode = getSelectedNode();
    if(selectedNode == null) return;
    
    File selected = selectedNode.getFile();
    String name = JOptionPane.showInputDialog(this, tr("Rename"), selected.getName());

    if (name != null && !name.isEmpty()) {
        
    FileOperationRename rename = new FileOperationRename(selectedNode, name);
    executeOperation(rename);
    
    // Update
    selected = rename.getNewFile();

    treeModel.nodeStructureChanged(selectedNode.getParent());

    }

  }
  
  protected void handleDelete() {
    
    if(!validateSelectionPaths()) return;
    
    TreePath[] paths = tree.getSelectionPaths();
    
    List<String> names = new ArrayList<String>();
    for (TreePath treePath : paths) {
      FileTreeNode node = (FileTreeNode) treePath.getLastPathComponent();
      File file = node.getFile();
      names.add(file.getName());
    }

    File file = getSelectedFile();
    String question = tr("Delete") + " " + tr(file.isDirectory() ? "Directory" : "File");
    String message = tr("This operation cannot be undone !");
    int response = JOptionPane.showConfirmDialog(this, question + ": " + names + "\n" + message, null, JOptionPane.YES_NO_OPTION);
    
    if(JOptionPane.YES_OPTION == response) {
        
        
      List<File> files = new LinkedList<File>();
      for (TreePath treePath : paths) {
          files.add(getSelectedFile(treePath));
      }
      
      FileOperationDelete delete = new FileOperationDelete(files);
      boolean deleted = executeOperation(delete);

      // Update nodes...
      for (TreePath treePath : paths) {
        if (deleted) {
          TreePath parentPath = treePath.getParentPath();
          tree.addSelectionPath(parentPath);
          treeModel.removeNodeFromParent((MutableTreeNode) treePath.getLastPathComponent());
        }
      }
    }
  }

  // ================================================================
  // File IO
  // ================================================================
  
  
  protected boolean executeOperation(FileOperation operation) {
    try {
      if (operation.execute()) {
        operation.setTree(tree);
        operation.saveTreeSelection();
        undoQueue.push(operation);
        return true;
      }
    } catch (Exception e) {
      showErrorMessage("Error : " + e.getClass().getSimpleName(), e.getMessage());
    }

    return false;
  }
  

  protected void handleUndo() {
    
    FileOperation lasFileOperation = getLastFileOperation();
    
    if(lasFileOperation != null) {
      
      try {
        boolean undo = lasFileOperation.undo();
        
        if(!undo) showErrorMessage(tr("Undo"), tr("Failed to undo last change"));
        
        lasFileOperation.restoreTreeSelection();

        handleReload(); // refresh parent node of changed selection
        
      } catch (Exception e) {
          showErrorMessage("Error : " + e.getClass().getSimpleName(), e.getMessage());
      }

    }
    
  }
  
  
  private void handlePaste() {
    
    Transferable transferable = Toolkit.getDefaultToolkit().getSystemClipboard().getContents(null);
    if(transferable != null ) {
      tree.getTransferHandler().importData(tree, transferable);
    }
    
  }

  private void handleCopy() {

    List<File> selectedFiles = getSelectedFiles();
    
    if(!selectedFiles.isEmpty()) {
      currentFileTransferable = new FileTransferable(selectedFiles, false);
      Toolkit.getDefaultToolkit().getSystemClipboard().setContents(currentFileTransferable, null);
    }
  }

  private void handleCut() {
    
    List<File> selectedFiles = getSelectedFiles();
    TreePath selectedNode = tree.getSelectionPath();
    
    if(!selectedFiles.isEmpty()) {
      currentFileTransferable = new FileTransferable(selectedFiles, true);
      currentFileTransferable.setSelectionPath(selectedNode); // up update previous selected path.
      Toolkit.getDefaultToolkit().getSystemClipboard().setContents(currentFileTransferable, null);
    }
    
  }
  
  // ================================================================
  // JTree methods
  // ================================================================
  
  public FileOperation getLastFileOperation() {
    if (undoQueue.isEmpty()) return null;
    return (FileOperation) undoQueue.pop();
  }
  
  public void handleTransferFile(List<File> files, boolean isMove) throws IOException {

    TreePath selectionPath = tree.getSelectionPath();
    File targetFolder = getSelectedFile();
    
    // use root
    if(targetFolder == null) {
      targetFolder = rootDir;
    }
    
    log("Transfer Files: , mode: " + (isMove ? "MOVE" : "COPY") + ", target: " + targetFolder);
    for (File file : files) {
      log(" - File Origin: " + file);
    }

    // get parent if has a file.
    if (!targetFolder.isDirectory()) {
      selectionPath = selectionPath.getParentPath();
      targetFolder =  ((FileTreeNode)selectionPath.getLastPathComponent()).getFile();
    }
    
    FileOperationCopy copyOrMove = new FileOperationCopy(files, targetFolder, isMove);
    executeOperation(copyOrMove);
    
    List<File> targetFiles = copyOrMove.getTargetFiles();

    // Update parent from last seleced node..
    if (isMove) {
      TreePath selectedNode = currentFileTransferable.getLastSelectedPath().getParentPath();
      if (selectedNode != null) {
        FileTreeNode parentNode = (FileTreeNode) selectedNode.getLastPathComponent();
        parentNode.reloadChildren();
        treeModel.nodeStructureChanged(parentNode);
      }
    }
    
    if(selectionPath != null) {
      insertFileIntoTree(targetFiles, selectionPath);
      tree.addSelectionPath(selectionPath);
    }else { // ROOT
      rootNode.reloadChildren();
      treeModel.nodeStructureChanged(rootNode);
    }
    
    currentFileTransferable = null; // clear
  }
  
  private FileTreeNode getSelectedNode() {
    TreePath selectionPath = tree.getSelectionPath();
    if(selectionPath == null) return null;
    DefaultMutableTreeNode node = (DefaultMutableTreeNode) selectionPath.getLastPathComponent();
    return (FileTreeNode) node;
  }
  
  protected File getSelectedFile() {
    return getSelectedFile(tree.getSelectionPath());
  }
  
  /**
   * Return root path if no delection found.
   * @return
   */
  private TreePath getSelectedPathOrRoot() {
    TreePath selectionPath = tree.getSelectionPath();
    if(selectionPath == null) {
      selectionPath = new TreePath(rootNode);
    }
    return selectionPath;
  }
  
  
  private boolean validateSelectionPaths() {
    // Avoid
    TreePath[] paths = tree.getSelectionPaths();
    
    if(paths == null) return false;
    
    int leafs = 0;
    int dirs = 0;
    
    for (TreePath treePath : paths) {
      TreeNode node = (TreeNode) treePath.getLastPathComponent();
      if(node.isLeaf()) leafs++;
      else dirs ++;
    }
    
    // 
    if(leafs > 0 && dirs > 0) {
      showMessage(tr("Invalid Selection"));
      return false;
    }
    
    if(dirs > 0 && leafs > 0) {
      showMessage(tr("Invalid Selection"));
      return false;
    }
    
    return true;
    
  }  
  
  public File getSelectedFile(TreePath path) {
    if(path == null) return null;
    FileTreeNode node = (FileTreeNode) path.getLastPathComponent();
    return node.getFile();
  }
  
  private List<File> getSelectedFiles() {
    TreePath[] paths = tree.getSelectionPaths();
    List<File> names = new LinkedList<File>();
    for (TreePath treePath : paths) {
      FileTreeNode node = (FileTreeNode) treePath.getLastPathComponent();
      File file = node.getFile();
      names.add(file);
    }
    return names;
  }
  
  private void insertFileIntoTree(File file, TreePath parentPath) {
    insertFileIntoTree(Arrays.asList(file), parentPath);
  }
  
  private void insertFileIntoTree(List<File> files, TreePath parentPath) {
   
    FileTreeNode parentNode = (FileTreeNode) parentPath.getLastPathComponent();
//
//    for (File file : files) {
//      FileTreeNode newNode = new FileTreeNode(file);
//      // only insert if populated. or wait for lazy load.
//      if(parentNode.populated) treeModel.insertNodeInto(newNode, parentNode, parentNode.getChildCount());
//    }
//    
//    if(!parentNode.populated) parentNode.populateDirectories(true);
    
    parentNode.reloadChildren();
    treeModel.nodeStructureChanged(parentNode);
    
    tree.expandPath(parentPath);
  }
 

  // ================================================================
  // Auxiliary classes
  // ================================================================
  
  // Inner class that handles Tree Expansion Events
  protected class TreeExpansionHandler implements TreeExpansionListener {
    public void treeExpanded(TreeExpansionEvent evt) {
      TreePath path = evt.getPath(); // The expanded path
      JTree tree = (JTree) evt.getSource(); // The tree

      // Get the last component of the path and
      // arrange to have it fully populated.
      FileTreeNode node = (FileTreeNode) path.getLastPathComponent();
      if (node.populateDirectories(true)) {
        ((DefaultTreeModel) tree.getModel()).nodeStructureChanged(node);
      }
    }

    public void treeCollapsed(TreeExpansionEvent evt) {
      // Nothing to do
    }
  }

  public void setRootDir(File rootDir){
    this.rootDir = rootDir;
  }
  
}
