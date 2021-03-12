package processing.app.tools;

import processing.app.Editor;
import processing.app.tools.jexplorer.JExplorerPanel;

import java.io.File;

public class ProjectExplorer extends JExplorerPanel {

  private Editor editor;

  public ProjectExplorer(File rootDir, Editor editor) {
    super(rootDir);
    this.editor = editor;
  }

 @Override
  protected void handleOpenFile(File file) {
    editor.getSketchController().addFile(file);
  }
}
