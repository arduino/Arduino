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

  private NavigateDialog navigateDialog;

  boolean navigating;


  public EditorProject(String path, Base base, Editor editor){
    this.setLayout(new BorderLayout());
    fileRoot = new File(path);
    this.base = base;
    this.editor = editor;
    fileExplorerPanel = new ProjectExplorer(fileRoot, editor);
    projectToolbar = new ProjectToolbar(editor, this);
    this.add(projectToolbar, BorderLayout.NORTH);
    this.add(fileExplorerPanel);

  }

  public void resetProject(File file){
    // Resetting the project View and root directory
    fileRoot = file;
    path = file.getPath();
    fileExplorerPanel.replaceWorkingDirectory(fileRoot);

    editor.statusNotice(tr("Navigated to :")+path);
  }


  public void handleNavigate(){
    if(!navigating) {
      navigateDialog = new NavigateDialog(new File(System.getProperty("user.home")), fileRoot, this);
      navigating = true;
    }else{
      navigateDialog.getDialog().toFront();
    }
  }


}
