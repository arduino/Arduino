/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer;

import processing.app.BaseNoGui;
import processing.app.Sketch;
import processing.app.Theme;
import processing.app.helpers.FileUtils;

import java.awt.*;
import java.io.File;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;

/** A TreeCellRenderer for a File. */
public class FileTreeCellRenderer extends DefaultTreeCellRenderer {

    private FileSystemView fileSystemView;

    private JLabel label;
    
    private Color deletedColor = Color.LIGHT_GRAY;

    private ImageIcon icon;

    FileTreeCellRenderer() {
        label = new JLabel();
        label.setOpaque(false);
        fileSystemView = FileSystemView.getFileSystemView();

        // Get the icon for the Arduino supported files
        icon = new ImageIcon(Stream
        .of("16")
        .map(res -> "/lib/icons/" + res + "x" + res + "/apps/arduino.png")
        .map(path -> BaseNoGui.getContentFile(path).getAbsolutePath())
        .map(absPath -> Toolkit.getDefaultToolkit().createImage(absPath))
        .collect(Collectors.toList()).get(0));
    }

    @Override
    public Component getTreeCellRendererComponent(JTree tree, Object value, boolean selected, boolean expanded,
                                                  boolean leaf, int row, boolean hasFocus) {

        DefaultMutableTreeNode node = (DefaultMutableTreeNode)value;
        File file = (File) node.getUserObject();


        if (selected) {
          label.setBackground(new Color(23, 161, 165));
          label.setForeground(new Color(255, 255, 255));

        } else {
          label.setBackground(backgroundNonSelectionColor);
          label.setForeground(textNonSelectionColor);
        }

        if(file.exists()) {
          if(FileUtils.hasExtension(file, Sketch.EXTENSIONS)){
            label.setIcon(icon);
          }else{
            label.setIcon(fileSystemView.getSystemIcon(file));
          }
          label.setToolTipText(file.getPath());
          label.setText(fileSystemView.getSystemDisplayName(file));
        }else {
          label.setText(file.getName());
          label.setForeground(deletedColor);
        }

        return label;
    }

    @Override
    public Color getBackgroundNonSelectionColor() {
      return (null);
    }

    @Override
    public Color getBackgroundSelectionColor() {
      return Color.GREEN;
    }

    @Override
    public Color getBackground() {
      return (null);
    }
}
