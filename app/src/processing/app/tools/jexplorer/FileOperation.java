/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Stream;

import javax.swing.JTree;
import javax.swing.tree.TreePath;

import  processing.app.tools.jexplorer.FileTreeModel.FileTreeNode;

public abstract class FileOperation {

  private TreePath[] selections; // Initially selected rows
  private TreePath leadSelection; // Initial lead selection
  protected JTree tree;

  public abstract boolean execute() throws IOException;

  public abstract boolean undo() throws IOException;

  public void setTree(JTree tree) {
    this.tree = tree;
  }

  protected void saveTreeSelection() {
    selections = tree.getSelectionPaths();
    leadSelection = tree.getLeadSelectionPath();
  }

  protected void restoreTreeSelection() {
    tree.setSelectionPaths(selections);

    // Restore the lead selection
    if (leadSelection != null) {
      tree.removeSelectionPath(leadSelection);
      tree.addSelectionPath(leadSelection);
    }
  }

  public TreePath[] getSelections() {
    return selections;
  }

  public TreePath getLeadSelection() {
    return leadSelection;
  }

  //
  // Implementations
  //

  public static class FileOperationCopy extends FileOperation {

    protected List<File> originFiles = new LinkedList<File>();

    protected File toDir;

    private boolean move;

    public FileOperationCopy(List<File> originFiles, File toDir, boolean move) {
      super();
      this.originFiles = buildFolderList(originFiles);
      this.toDir = toDir;
      this.move = move;
    }

    /**
     * make safe copy/move a directory.
     */
    private List<File> buildFolderList(List<File> originFiles) {
//      List<File> sequence = new LinkedList<File>();
//      for (File file : originFiles) {
//        if (file.isDirectory()) {
//          sequence.add(file); // directory must be frist.
//          sequence.addAll(buildFolderList(Arrays.asList(file.listFiles())));
//        } else {
//          sequence.add(file);
//        }
//      }
//      return sequence;
      
      return originFiles;
    }

    @Override
    public boolean execute() throws IOException {

      for (File from : originFiles) {
        File to = new File(toDir, from.getName());
        
        // Copy duplicate, create append 1
        if (to.exists() && !to.isDirectory() && !move) {
          to = new File(toDir, "copy_"+from.getName());
          continue;
        }

        if (move) {
          // On linux, move DIR operations are can be node using rename. 
          // This only work if files in same partition...
          if(from.isDirectory()) moveTree(from, to); // from.renameTo(to);
          else Files.move(from.toPath(), to.toPath(), StandardCopyOption.REPLACE_EXISTING);
          
        } else {
            if(from.isDirectory()) {
              copyTree(from.toPath(), to.toPath());
            } else {
              Files.copy(from.toPath(), to.toPath(), StandardCopyOption.REPLACE_EXISTING);
            }
        }
          
//          if (move) {
//            if (from.isDirectory())
//              to.mkdir();
//            else
//              Files.move(from.toPath(), to.toPath());
//          } else {
//            if (from.isDirectory())
//              to.mkdir();
//            else
//              Files.copy(from.toPath(), to.toPath());
//          }

      }

      return true;
    }
    
    private void copyTree(Path src, Path dest) throws IOException {
      try (Stream<Path> stream = Files.walk(src)) {
        stream.forEach(source -> copy(source, dest.resolve(src.relativize(source))));
      }
    }
    
    private void copy(Path source, Path dest) {
      try {
        Files.copy(source, dest, StandardCopyOption.REPLACE_EXISTING);
      } catch (Exception e) {
        throw new RuntimeException(e.getMessage(), e);
      }
    }
    
    private static void moveTree( File currDir, File toDir) throws IOException {
      try {
        
        System.out.println("form: " + currDir);
        System.out.println("to: " + toDir);
        
        if(!toDir.exists()) toDir.mkdirs();
        
        for (File file : currDir.listFiles()) {
          if (file.isDirectory()) {
            System.out.println("  >>" + new File(toDir, currDir.getName()));
            moveTree(file, new File(toDir, file.getName()));
//            Files.move(currDir.toPath(), new File(toDir, currDir.getName()).toPath(), StandardCopyOption.REPLACE_EXISTING);
          } else {
//             file.renameTo(new File(toDir, file.getName()));
            File to = new File(toDir, file.getName());
            System.out.println("  >>" + to);
            Files.move(file.toPath(), to.toPath(), StandardCopyOption.REPLACE_EXISTING);
          }
        }
        
        currDir.delete();
        
      } catch (Exception e) {
        e.printStackTrace();
        throw e;
      }

    }

    public List<File> getTargetFiles() {
      List<File> targetFiles = new ArrayList<File>();
      for (File from : originFiles) {
        File to = new File(toDir, from.getName());
        if (to.exists())
          targetFiles.add(to);
      }
      return targetFiles;
    }

    @Override
    public boolean undo() throws IOException{

      List<File> reverFiles = getTargetFiles();

      if (move) {
        File reverDir = originFiles.get(0).getParentFile();
        FileOperationCopy copy = new FileOperationCopy(reverFiles, reverDir, true);
        copy.execute();
      } else {
        for (File file : reverFiles) {
          file.delete();
        }
      }

      // Rebuild Jtree nodes.
      TreePath[] selections = getSelections();
      for (TreePath treePath : selections) {
        FileTreeNode parentNode = (FileTreeNode) treePath.getParentPath().getLastPathComponent();
        parentNode.reloadChildren();
      }

      return true;
    }

  }

  public static class FileOperationMove extends FileOperationCopy {

    public FileOperationMove(List<File> originFiles, File toDir) {
      super(originFiles, toDir, true);
    }

  }

  public static class FileOperationRename extends FileOperation {

    private FileTreeNode fileNode;

    private File oldFile;

    private String newName;

    public FileOperationRename(FileTreeNode selectedNode, String newName) {
      super();
      this.fileNode = selectedNode;
      this.newName = newName;
      this.oldFile = fileNode.getFile();
    }

    private File getOldFile() {
      return oldFile;
    }

    public File getNewFile() {
      return new File(getOldFile().getParent(), newName);
    }

    @Override
    public boolean execute() {
      File newFile = getNewFile();
      boolean renamed = oldFile.renameTo(newFile);
      if (renamed)
        fileNode.setUserObject(newFile);

      if (newFile.isDirectory()) {
        fileNode.reloadChildren();
      }

      return renamed;
    }

    @Override
    public boolean undo() {
      File newFile = getNewFile();
      boolean renamed = newFile.renameTo(oldFile);
      if (renamed) {
        fileNode.setUserObject(oldFile);
        if (oldFile.isDirectory()) {
          fileNode.reloadChildren();
        }
      }

      return renamed;
    }

  }

  public static class FileOperationDelete extends FileOperationMove {

    public FileOperationDelete(List<File> originFiles) {
      super(originFiles, null);
    }

    @Override
    public boolean execute() throws IOException{
        Path path = Files.createTempDirectory("jfileexplorer" + System.currentTimeMillis());
        toDir = path.toFile();
        return super.execute();
    }

    @Override
    public boolean undo() throws IOException{
      boolean undo = super.undo();
      if (undo) {
        toDir.delete();
      }
      return undo;
    }

  }

}
