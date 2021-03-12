/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer;

import java.io.File;
import java.io.FileFilter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeNode;
import processing.app.tools.jexplorer.utils.AcceptAllFileFilter;

public class FileTreeModel extends DefaultTreeModel {

  public FileTreeModel(TreeNode root) {
    super(root);
  }

  public FileFilter getFileFilter() {
    if(getRoot() instanceof FileTreeNode) {
      return ((FileTreeNode) getRoot()).getFileFilter();
    } else {
      return new AcceptAllFileFilter();
    }
  }

  public void setFileFilter(FileFilter fileFilter) {
    final FileTreeNode root = (FileTreeNode) getRoot();
    root.setFileFilter(fileFilter);
    root.reloadChildren();
    nodeStructureChanged(root);
  }

  @Override
  public void setRoot(TreeNode root) {
    // keep the file filter
    FileFilter fileFilter=getFileFilter();
    super.setRoot(root);
    setFileFilter(fileFilter);
  }

//  @Override
//  public void valueForPathChanged(TreePath path, Object newValue) {
//    FileTreeNode  aNode = (FileTreeNode) path.getLastPathComponent();
//    
//    // Handle edit
//    if(newValue instanceof String) {
//      aNode.rename((String) newValue);
//    }
//    
//    File file = (File) aNode.getUserObject();
//    if(file.isDirectory()) {
//      nodeStructureChanged(aNode);
//    }else {
//      nodeChanged(aNode);
//    }
//    
//  }
  
  public static class FileTreeNode extends DefaultMutableTreeNode {
  
    private File file; // user object
  
    private FileFilter fileFilter= new AcceptAllFileFilter();

    public FileTreeNode(File f) {
  
      this.file = f;
  
      this.setUserObject(f);
  
      this.name = f.getName();
  
      isDir = f.isDirectory();
  
      // Hack for Windows which doesn't consider a drive to be a
      // directory!
      if (isDir == false && f.isFile() == false) {
        isDir = true;
      }
  
    }
  
    public void reloadChildren() {
      populated = false;
      removeAllChildren();
      populateDirectories(true);
    }
  
//    /**
//     * Calend from default nodeEditor, from FileTreeModel
//     * 
//     * @param newValue
//     */
//    public void rename(String newValue) {
//      this.setName(newValue);
//      File newFile = new File(file.getParentFile(), newValue);
//  
//      try {
//        boolean success = file.renameTo(newFile);
//        if (success) {
//          file = newFile;
//          setUserObject(newFile);
//          if (file.isDirectory()) {
//            reloadChildren();
//          }
//        }
//      } catch (Exception e) {
//        handleExeption("Error while renaming", e);
//      }
//  
//    }
  
    public void setName(String name) {
      this.name = name;
    }
  
    public boolean isLeaf() {
      return !isDir;
    }
  
    // Override getAllowsChildren to check whether this is a directory
    public boolean getAllowsChildren() {
      return isDir;
    }
  
    public boolean isDir() {
      return isDir;
    }
  
    // Get full path
    public String getFullName() {
      return file.getAbsolutePath();
    }
  
    public File getFile() {
      return file;
    }
  
    // For display purposes, we return our own name
    public String toString() {
      return name;
    }
    
    @Override
    public void setUserObject(Object userObject) {
      this.file = (File) userObject;
      super.setUserObject(userObject);
    }
  
    // If we are a directory, scan our contents and populate
    // with children. In addition, populate those children
    // if the "descend" flag is true. We only descend once,
    // to avoid recursing the whole subtree.
    // Returns true if some nodes were added
    boolean populateDirectories(boolean descend) {
      boolean addedNodes = false;
  
      // Do this only once
      if (populated == false) {
        File f = getFile();
        
        if(! f.isDirectory()) return false;
        
        try {
          f.canRead();
        } catch (SecurityException e) {
          populated = true;
          return false;
        }
  
        if (interim == true) {
          // We have had a quick look here before:
          // remove the dummy node that we added last time
          removeAllChildren();
          interim = false;
        }
  
        File[] files = f.listFiles(getFileFilter()); // Get list of contents
  
        // Process the contents
        ArrayList list = new ArrayList();
        for (int i = 0; i < files.length; i++) {
          File d = files[i];
          try {
            FileTreeNode node = new FileTreeNode(d);
            list.add(node);
            if (descend && d.isDirectory()) {
              node.populateDirectories(false);
            }
            addedNodes = true;
            if (descend == false) {
              // Only add one node if not descending
              break;
            }
          } catch (Throwable t) {
            // Ignore phantoms or access problems
          }
        }
  
        if (addedNodes == true) {
          // Now sort the list of contained files and directories
          Object[] nodes = list.toArray();
          Arrays.sort(nodes, new Comparator() {
            public boolean equals(Object o) {
              return false;
            }
  
            public int compare(Object o1, Object o2) {
              FileTreeNode node1 = (FileTreeNode) o1;
              FileTreeNode node2 = (FileTreeNode) o2;
  
              // Directories come first
              if (node1.isDir != node2.isDir) {
                return node1.isDir ? -1 : +1;
              }
  
              // Both directories or both files -
              // compare based on pathname
              return node1.getFullName().compareTo(node2.getFullName());
            }
          });
  
          // Add sorted items as children of this node
          for (int j = 0; j < nodes.length; j++) {
            this.add((FileTreeNode) nodes[j]);
          }
        }
  
        // If we were scanning to get all subdirectories,
        // or if we found no content, there is no
        // reason to look at this directory again, so
        // set populated to true. Otherwise, we set interim
        // so that we look again in the future if we need to
        if (descend == true || addedNodes == false) {
          populated = true;
        } else {
          // Just set interim state
          interim = true;
        }
      }
      return addedNodes;
    }
  
    // Adding a new file or directory after
    // constructing the FileTree. Returns
    // the index of the inserted node.
    public int addNode(String name) {
      // If not populated yet, do nothing
      if (populated == true) {
        // Do not add a new node if
        // the required node is already there
        int childCount = getChildCount();
        for (int i = 0; i < childCount; i++) {
          FileTreeNode node = (FileTreeNode) getChildAt(i);
          if (node.name.equals(name)) {
            // Already exists - ensure
            // we repopulate
            if (node.isDir()) {
              node.interim = true;
              node.populated = false;
            }
            return -1;
          }
        }
  
        // Add a new node
        try {
          FileTreeNode node = new FileTreeNode(new File(file, name));
          add(node);
          return childCount;
        } catch (Exception e) {
        }
      }
      return -1;
    }
  
    protected String name; // Name of this component
  
    protected boolean populated;// true if we have been populated
  
    protected boolean interim; // true if we are in interim state
  
    protected boolean isDir; // true if this is a directory

    public FileFilter getFileFilter() {
      if(getParent()!=null){
        return ((FileTreeNode)getParent()).getFileFilter();
      } else {
        return this.fileFilter;
      }
    }

    public void setFileFilter(FileFilter fileFilter) {
      if(getParent() instanceof FileTreeNode){
        ((FileTreeNode)getParent()).setFileFilter(fileFilter);
      } else {
        this.fileFilter = fileFilter;
      }
    }
  }
}
