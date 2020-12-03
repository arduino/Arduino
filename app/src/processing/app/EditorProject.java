package processing.app;

import processing.app.tools.jexplorer.JExplorerPanel;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.io.IOException;

import static java.awt.Color.RED;
import static processing.app.I18n.tr;


public class EditorProject extends JPanel {

  private JExplorerPanel fileExplorerPanel;

  private File fileRoot;

  private Base base;

  private Editor editor;

  private String path;

  private JFileChooser chooser;

  private ProjectToolbar projectToolbar;


  public EditorProject(String path, Base base, Editor editor){
    this.setLayout(new BorderLayout());
    fileRoot = new File(path);
    this.base = base;
    this.editor = editor;
    fileExplorerPanel = new JExplorerPanel(fileRoot, editor);
    projectToolbar = new ProjectToolbar(editor, this);
    /*buttons_popup = new Label("Toggle Project View");
    buttons_popup.setForeground(new Color(23, 161, 165));
    buttons_popup.setBackground(new Color(23, 161, 165));
    settingsbox = new JPanel();
    settingsbox.setLayout(new BoxLayout(settingsbox, BoxLayout.LINE_AXIS));
    settingsbox.setOpaque(true);
    settingsbox.setBackground(new Color(23, 161, 165));
    this.path = path;

    Icon img = new ImageIcon(new ImageIcon("folder1.jpg").getImage().getScaledInstance(35, 30, Image.SCALE_DEFAULT));
    settings = new JButton(img);
    

    settings.setPreferredSize(new Dimension(25, 5));
    settings.addActionListener(this);
    settings.addMouseListener(this);
    toggle = new JButton("T");
    toggle.addActionListener(this);
    toggle.addMouseListener(this);
    //this.add(settings);
    //settingsbox.add(new Label("Project View"));
    JPanel buttons_panel = new JPanel();
    buttons_panel.setLayout(new FlowLayout());
    buttons_panel.setOpaque(false);
    //settingsbox.setBackground(Color.WHITE);
    settingsbox.add(settings);
    settingsbox.add(toggle);
    settingsbox.add(buttons_popup);
    //settingsbox.add(Box.createHorizontalGlue());
    //settingsbox.add(buttons_panel);
    this.add(settingsbox, BorderLayout.NORTH);*/
    this.add(projectToolbar, BorderLayout.NORTH);
    this.add(fileExplorerPanel);

  }

  public void resetProject(){
    // Resetting the project View and root directory
    fileRoot = new File(path);
    fileExplorerPanel.replaceWorkingDirectory(fileRoot);

    // Resetting the sketchbook path
    PreferencesData.set("sketchbook.path", path);


    editor.statusNotice(tr("Navigated to :")+path);
  }


  public void handleNavigate(){
    chooser = new JFileChooser();
    chooser.setCurrentDirectory(fileRoot);
    chooser.setDialogTitle("Choose project directory : ");
    chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);

    if (chooser.showOpenDialog(fileExplorerPanel) == JFileChooser.APPROVE_OPTION) {
      this.path = chooser.getSelectedFile().getAbsolutePath();
      resetProject();
    }
  }


}



