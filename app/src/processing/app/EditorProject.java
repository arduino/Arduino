package processing.app;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;

public class EditorProject extends JScrollPane implements Runnable, MouseListener {

  private DefaultMutableTreeNode root;

  private DefaultTreeModel treeModel;

  private JTree tree;

  private File fileRoot;

  private Base base;

  private Editor editor;

  private String workspace = System.getProperty("user.home") + "/";

  public EditorProject(String path, Base base, Editor editor){
    fileRoot = new File(path);
    this.base = base;
    this.editor = editor;
    this.setPreferredSize(new Dimension(400, 1000));
  }

  @Override
  public void run() {
    root = new DefaultMutableTreeNode(new FileNode(fileRoot));
    treeModel = new DefaultTreeModel(root);


    tree = new JTree(treeModel);
    tree.setShowsRootHandles(true);
    tree.addMouseListener(this);
    setViewportView(tree);


    CreateChildNodes ccn =
      new CreateChildNodes(fileRoot, root);
    new Thread(ccn).start();
  }

  @Override
  public void mouseClicked(MouseEvent e) {
    int selRow = tree.getRowForLocation(e.getX(), e.getY());
    TreePath selPath = tree.getPathForLocation(e.getX(), e.getY());
    if(selRow != -1) {
      if(e.getClickCount() == 2) {
        String path = selPath.toString().replaceAll("\\]| |\\[|", "").replaceAll(",", File.separator);
        try {
          editor.getSketchController().addFile(new File(workspace + path));

        } catch (Exception exception) {
          exception.printStackTrace();
        }
      }
    }
  }

  @Override
  public void mousePressed(MouseEvent e) {

  }

  @Override
  public void mouseReleased(MouseEvent e) {

  }

  @Override
  public void mouseEntered(MouseEvent e) {

  }

  @Override
  public void mouseExited(MouseEvent e) {

  }

  public class CreateChildNodes implements Runnable {

    private DefaultMutableTreeNode root;

    private File fileRoot;

    public CreateChildNodes(File fileRoot,
                            DefaultMutableTreeNode root) {
      this.fileRoot = fileRoot;
      this.root = root;
    }

    @Override
    public void run() {
      createChildren(fileRoot, root);
    }

    private void createChildren(File fileRoot,
                                DefaultMutableTreeNode node) {
      File[] files = fileRoot.listFiles();
      if (files == null) return;

      for (File file : files) {
        DefaultMutableTreeNode childNode =
          new DefaultMutableTreeNode(new FileNode(file));
        node.add(childNode);
        if (file.isDirectory()) {
          createChildren(file, childNode);
        }
      }
    }

  }

  public class FileNode {

    private File file;

    public FileNode(File file) {
      this.file = file;
    }

    @Override
    public String toString() {
      String name = file.getName();
      if (name.equals("")) {
        return file.getAbsolutePath();
      } else {
        return name;
      }
    }
  }

}



