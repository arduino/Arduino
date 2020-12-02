/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer.dnd;

import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JComponent;
import javax.swing.JTree;
import javax.swing.SwingUtilities;
import javax.swing.TransferHandler;
import javax.swing.tree.TreeNode;
import javax.swing.tree.TreePath;

import processing.app.tools.jexplorer.utils.StringUtils;

/**
 * Handle Internal and Externaml DND Actions
 * @author Ricardo JL Rufino - (ricardo.jl.rufino@gmail.com)
 * @date 25 de mai de 2020
 */
public abstract class FileTransferHandler extends TransferHandler {
  
  public DataFlavor uriListFlavor;
  
  public FileTransferHandler() {
    try {
      uriListFlavor = new DataFlavor("text/uri-list;class=java.lang.String");
    } catch (ClassNotFoundException e) {
    }
  }
  
  public boolean canImport(JComponent dest, DataFlavor[] flavors) {
    
    // Internal DND Started...
    if(FileTreeDragSource.started.get()) { 
      
      JTree tree = (JTree) dest;

      // Allow only move to another Directory
      Point location = MouseInfo.getPointerInfo().getLocation();
      SwingUtilities.convertPointFromScreen(location, tree);
      TreePath dragPath = tree.getPathForLocation(location.x, location.y);
      
      if(dragPath != null) {
        TreeNode node = (TreeNode) dragPath.getLastPathComponent();
        return (!node.isLeaf()); 
      }
      
      return false; 
      
    }
    
    for (int i = 0; i < flavors.length; i++) {
      if (flavors[i].equals(DataFlavor.javaFileListFlavor)) {
        return true;
      }
      if (flavors[i].equals(uriListFlavor)) {
        return true;
      }
    }
    return false;
  }

  @SuppressWarnings("unchecked")
  public boolean importData(JComponent src, Transferable transferable) {
    

    try {
      List<File> files = new LinkedList<>();

      if (transferable.isDataFlavorSupported(DataFlavor.javaFileListFlavor)) {

        List<File> list = (List<File>) transferable.getTransferData(DataFlavor.javaFileListFlavor);
        files.addAll(list);

      } else if (transferable.isDataFlavorSupported(uriListFlavor)) {

        // Some platforms (Mac OS X and Linux, when this began) preferred
        // this method of moving files.
        String data = (String) transferable.getTransferData(uriListFlavor);
        String[] pieces = StringUtils.splitTokens(data, "\r\n");
        for (String piece : pieces) {
          if (piece.startsWith("#"))
            continue;

          String path = null;
          if (piece.startsWith("file:///")) {
            path = piece.substring(7);
          } else if (piece.startsWith("file:/")) {
            path = piece.substring(5);
          }
          files.add(new File(path));
        }
      }
      
 
      
      handleTranferFile(files);

    } catch (Exception e) {
      e.printStackTrace();
      return false;
    } 

    return true;
  }
  
  
  public abstract void handleTranferFile(List<File> files);


  public static class FileTransferable implements Transferable {

    private List listOfFiles;
    private boolean move;
    private TreePath selectedNode;

    public FileTransferable(List listOfFiles) {
      this.listOfFiles = listOfFiles;
    }

    public void setSelectionPath(TreePath selectedNode) {
      this.selectedNode = selectedNode;
    }

    public FileTransferable(List<File> selectedFiles, boolean move) {
        this.move = move;
        this.listOfFiles = selectedFiles;
    }

    @Override
    public DataFlavor[] getTransferDataFlavors() {
      return new DataFlavor[] { DataFlavor.javaFileListFlavor };
    }

    @Override
    public boolean isDataFlavorSupported(DataFlavor flavor) {
      return DataFlavor.javaFileListFlavor.equals(flavor);
    }

    @Override
    public Object getTransferData(DataFlavor flavor) throws UnsupportedFlavorException, IOException {
      return listOfFiles;
    }
    
    public void setMove(boolean move) {
      this.move = move;
    }
    
    public boolean isMove() {
      return move;
    }
    
    public TreePath getLastSelectedPath() {
      return selectedNode;
    }
    
  }
}
