package processing.app;

import processing.app.tools.jexplorer.JExplorerPanel;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;

public class EditorProject extends Panel implements ActionListener, MouseListener{

  private JExplorerPanel fileExplorerPanel;

  private File fileRoot;

  private Base base;

  private Editor editor;

  private JPanel settingsbox;

  private String path;

  private JButton settings;

  private JButton toggle;

  private JFileChooser chooser;

  private Label buttons_popup;

  public EditorProject(String path, Base base, Editor editor){
    this.setLayout(new BorderLayout());
    fileRoot = new File(path);
    this.base = base;
    this.editor = editor;
    fileExplorerPanel = new JExplorerPanel(fileRoot, editor);
    buttons_popup = new Label("Toggle Project View");
    buttons_popup.setForeground(new Color(23, 161, 165));
    buttons_popup.setBackground(new Color(23, 161, 165));
    settingsbox = new JPanel();
    settingsbox.setLayout(new BoxLayout(settingsbox, BoxLayout.LINE_AXIS));
    settingsbox.setOpaque(true);
    settingsbox.setBackground(new Color(23, 161, 165));
    this.path = path;
    settings = new JButton("S");
    settings.addActionListener(this);
    settings.addMouseListener(this);
    toggle = new JButton("T");
    toggle.addActionListener(this);
    toggle.addMouseListener(this);
    this.add(settings);
    //settingsbox.add(new Label("Project View"));
    JPanel buttons_panel = new JPanel();
    buttons_panel.setLayout(new FlowLayout());
    buttons_panel.setOpaque(false);

    settingsbox.add(settings);
    settingsbox.add(toggle);
    settingsbox.add(buttons_popup);
    //settingsbox.add(Box.createHorizontalGlue());
    //settingsbox.add(buttons_panel);
    this.add(settingsbox, BorderLayout.NORTH);
    this.add(fileExplorerPanel);

  }

  public void resetProject(){
    // Resetting the project View and root directory
    fileRoot = new File(path);
    fileExplorerPanel.replaceWorkingDirectory(fileRoot);

    // Resetting the sketchbook path
    PreferencesData.set("sketchbook.path", path);
  }


  @Override
  public void actionPerformed(ActionEvent e) {
    if(e.getSource() == settings){
      chooser = new JFileChooser();
      chooser.setCurrentDirectory(fileRoot);
      chooser.setDialogTitle("Choose project directory : ");
      chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);

      if (chooser.showOpenDialog(fileExplorerPanel) == JFileChooser.APPROVE_OPTION) {
        System.out.println("You moved your workspace to : " + chooser.getSelectedFile());
        this.path = chooser.getSelectedFile().getAbsolutePath();
        resetProject();
      }
      else {
        System.out.println("No Selection ");
      }
    }

    if(e.getSource() == toggle){
      //TODO
    }
    }


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
      if(e.getSource() == settings){
          buttons_popup.setForeground(Color.WHITE);
          buttons_popup.setText("Change Workspace");
      }

      if(e.getSource() == toggle){
        buttons_popup.setForeground(Color.WHITE);
        buttons_popup.setText("Toggle Project View");
      }
  }

  @Override
  public void mouseExited(MouseEvent e) {
    buttons_popup.setText("");
  }
}



