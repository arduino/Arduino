package  processing.app.tools.jexplorer.dnd;

import java.awt.Point;
import java.awt.datatransfer.Transferable;
import java.awt.dnd.DnDConstants;
import java.awt.dnd.DragGestureEvent;
import java.awt.dnd.DragGestureListener;
import java.awt.dnd.DragSource;
import java.awt.dnd.DragSourceDragEvent;
import java.awt.dnd.DragSourceDropEvent;
import java.awt.dnd.DragSourceEvent;
import java.awt.dnd.DragSourceListener;
import java.io.File;
import java.util.Arrays;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.swing.JTree;
import javax.swing.tree.TreePath;

import processing.app.tools.jexplorer.JExplorerPanel;
import processing.app.tools.jexplorer.dnd.FileTransferHandler.FileTransferable;

/**
 * Prepare DragSource to COPY/MOVE to External And Internal
 * 
 * @author Ricardo JL Rufino - (ricardo.jl.rufino@gmail.com)
 * @date 25 de mai de 2020
 */
public class FileTreeDragSource implements DragGestureListener, DragSourceListener {

  protected JTree tree; // The associated tree
  protected JExplorerPanel panel;

  protected File[] dragFiles; // Dragged files

  protected TreePath[] paths; // Dragged paths

  public static AtomicBoolean started = new AtomicBoolean(false);

  public static void install(JExplorerPanel panel) {
    new FileTreeDragSource(panel);
  }

  public FileTreeDragSource(JExplorerPanel panel) {
    this.panel = panel;
    this.tree = panel.getTree();

    // Use the default DragSource
    DragSource dragSource = DragSource.getDefaultDragSource();

    // Create a DragGestureRecognizer and
    // register as the listener
    dragSource.createDefaultDragGestureRecognizer(tree, DnDConstants.ACTION_COPY_OR_MOVE, this);
  }

  @Override
  public void dragGestureRecognized(DragGestureEvent dge) {
    // Get the mouse location and convert it to
    // a location within the tree.
    Point location = dge.getDragOrigin();
    TreePath dragPath = tree.getPathForLocation(location.x, location.y);

    started.set(true);

    if (dragPath != null && tree.isPathSelected(dragPath)) {

      // Get the list of selected files and create a Transferable
      // The list of files and the is saved for use when
      // the drop completes.
      paths = tree.getSelectionPaths();

      if (paths != null && paths.length > 0) {

        dragFiles = new File[paths.length];
        for (int i = 0; i < paths.length; i++) {
          dragFiles[i] = panel.getSelectedFile(paths[i]);
        }

        FileTransferable transferable = new FileTransferable(Arrays.asList(dragFiles), true);

        transferable.setSelectionPath(tree.getSelectionPath());

        panel.setCurrentFileTransferable(transferable); // make this action MOVE...

        dge.startDrag(null, transferable, this);

        tree.clearSelection();
      }
    }

  }

  @Override
  public void dragEnter(DragSourceDragEvent dsde) {

  }

  // This is call only if FileTransferHandler.canImport, return true..
  @Override
  public void dragOver(DragSourceDragEvent dsde) {
  }

  @Override
  public void dropActionChanged(DragSourceDragEvent dsde) {
    // Set MOVE / COPY action...
    Transferable transferable = dsde.getDragSourceContext().getTransferable();
    if (transferable instanceof FileTransferable) {
      FileTransferable fileTransferable = (FileTransferable) transferable;
      fileTransferable.setMove(DnDConstants.ACTION_MOVE == dsde.getDropAction());
      panel.setCurrentFileTransferable(fileTransferable);
    }

  }

  @Override
  public void dragExit(DragSourceEvent dse) {
  }

  @Override
  public void dragDropEnd(DragSourceDropEvent dsde) {
    started.set(false);
  }

}
