package processing.app.tools;

import processing.app.Editor;
import processing.app.EditorProject;
import processing.app.tools.jexplorer.JExplorerPanel;

import javax.swing.*;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.*;
import java.io.File;

public class NavigateDialog extends JExplorerPanel implements ActionListener, MouseListener, KeyListener {

  private JTextField pathfield;
  private JDialog dialog;
  private JButton open, cancel;
  private EditorProject editorProject;

  public NavigateDialog(File rootFile, File projectDir, EditorProject editorProject){
    super(rootFile);
    this.editorProject = editorProject;
    this.getTree().addMouseListener(this);
    pathfield = new JTextField();

    dialog = new JDialog();
    pathfield = new JTextField();
    dialog.setPreferredSize(new Dimension(400,400));
    dialog.setTitle("Choose the directory to navigate to :");
    dialog.setFocusable(true);
    dialog.addKeyListener(this);
    JPanel panel = new JPanel(new BorderLayout());
    panel.add(pathfield, BorderLayout.NORTH);
    panel.add(this, BorderLayout.CENTER);
    JPanel buttonPanel = new JPanel();
    panel.setOpaque(false);
    open = new JButton("Open");
    open.addActionListener(this);
    buttonPanel.add(open);
    cancel = new JButton("Cancel");
    cancel.addActionListener(this);
    buttonPanel.add(cancel);
    panel.add(buttonPanel, BorderLayout.SOUTH);
    dialog.add(panel);
    dialog.pack();
    dialog.setLocationRelativeTo(null);
    dialog.setVisible(true);
  }

  @Override
  public void actionPerformed(ActionEvent e) {

    if(e.getSource() == open){
      handleOpen();
    }
    if(e.getSource() == cancel){
      dialog.setVisible(false);
      dialog.dispose();
    }
  }


  @Override
  public void mouseClicked(MouseEvent e) {
     if(e.getSource() == this.getTree()){
       if(this.getSelectedFile() != null) {
         // Update the pathfield
         pathfield.setText(this.getSelectedFile().getAbsolutePath());
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


  @Override
  public void keyTyped(KeyEvent e) {
      if(e.getKeyCode() == KeyEvent.VK_ENTER){
        handleOpen();
      }
  }

  @Override
  public void keyPressed(KeyEvent e) {

  }

  @Override
  public void keyReleased(KeyEvent e) {

  }

  public void handleOpen(){
    String newdir = pathfield.getText();
    if(!newdir.equals("")){
      // Check if the path given is true file
      File prjdir = new File(newdir);
      if(prjdir.exists()){
        // Check if its a directory, if it's a file go to its parent dir
        if(prjdir.isDirectory()){
          editorProject.resetProject(prjdir);
        }else if(prjdir.isFile()){
          editorProject.resetProject(prjdir.getParentFile());
        }
        // Quit the dialog
        dialog.setVisible(false);
        dialog.dispose();
      }
    }
  }

  public JDialog getDialog(){
    return dialog;
  }
}
