package processing.app;

import processing.app.tools.NavigateDialog;
import processing.app.tools.ProjectExplorer;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import static processing.app.I18n.tr;


public class EditorProject extends JPanel {

  private ProjectExplorer fileExplorerPanel;

  private File fileRoot;

  private Base base;

  private Editor editor;

  private String path;

  private JFileChooser chooser;

  private ProjectToolbar projectToolbar;

  boolean navigating;


  public EditorProject(String path, Base base, Editor editor){
    this.setLayout(new BorderLayout());
    fileRoot = new File(path);
    this.base = base;
    this.editor = editor;
    fileExplorerPanel = new ProjectExplorer(fileRoot, editor);
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

  public void resetProject(File file){
    // Resetting the project View and root directory
    fileRoot = file;
    path = file.getPath();
    fileExplorerPanel.replaceWorkingDirectory(fileRoot);

    // Resetting the sketchbook path
    //PreferencesData.set("sketchbook.path", path);


    editor.statusNotice(tr("Navigated to :")+path);
  }


  public void handleNavigate(){
    /*chooser = new JFileChooser();
    chooser.setCurrentDirectory(fileRoot);
    chooser.setDialogTitle("Choose project directory : ");
    chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
    chooser.setAcceptAllFileFilterUsed(false);
    if (chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
      resetProject(chooser.getSelectedFile());
    }
    /*JDialog jDialog = new JDialog();
    JTextField pathfield = new JTextField();
    jDialog.setPreferredSize(new Dimension(400,400));
    jDialog.setTitle("Choose the directory to navigate to :");
    JPanel panel = new JPanel(new BorderLayout());
    panel.add(pathfield, BorderLayout.NORTH);
    JExplorerPanel navigator =  new JExplorerPanel(new File("/home/sami"), editor);
    panel.add(navigator, BorderLayout.CENTER);
    JPanel buttonPanel = new JPanel();
    JButton open = new JButton("Open");
    buttonPanel.add(open);
    open.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
      }
    });
    JButton cancel = new JButton("Cancel");
    buttonPanel.add(cancel);
    open.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        jDialog.dispose();
      }
    });
    panel.add(buttonPanel, BorderLayout.SOUTH);
    jDialog.add(panel);
    jDialog.pack();
    jDialog.setLocationRelativeTo(null);
    jDialog.setVisible(true);*/
    if(!navigating) {
      NavigateDialog navigateDialog = new NavigateDialog(new File(System.getProperty("user.home")), fileRoot, this);
      navigating = true;
    }else{

    }
  }


}
