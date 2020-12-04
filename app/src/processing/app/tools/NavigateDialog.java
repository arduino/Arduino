package processing.app.tools;

import processing.app.Editor;
import processing.app.tools.jexplorer.JExplorerPanel;

import javax.swing.*;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;

public class NavigateDialog extends JExplorerPanel implements ActionListener {

  private JTextField pathfield;
  private JDialog dialog;
  private JButton open, cancel;

  public NavigateDialog(File rootFile, File projectDir){
    super(rootFile);
    this.getTree().addMouseListener(new MouseListener() {
      @Override
      public void mouseClicked(MouseEvent e) {
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
    });
    pathfield = new JTextField();

    dialog = new JDialog();
    dialog.setBackground(Color.BLACK);
    pathfield = new JTextField();
    dialog.setPreferredSize(new Dimension(400,400));
    dialog.setTitle("Choose the directory to navigate to :");
    JPanel panel = new JPanel(new BorderLayout());
    panel.setOpaque(false);
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

    }
    if(e.getSource() == cancel){
      dialog.setVisible(false);
      dialog.dispose();
    }
  }


}
