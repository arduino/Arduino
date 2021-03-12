package processing.app.tools.jexplorer.utils;

import java.awt.Component;
import java.awt.Container;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.JLabel;

/**
 * Simple utility class for creating forms that have a column
 * of labels and a column of fields. All of the labels have the
 * same width, determined by the width of the widest label
 * component.
 * <P>
 * Philip Isenhour - 060628 - http://javatechniques.com/
 */
public class FormUtility {
    /**
     * Grid bag constraints for fields and labels
     */
    private GridBagConstraints lastConstraints = null;
    private GridBagConstraints middleConstraints = null;
    private GridBagConstraints labelConstraints = null;

    public FormUtility() {
        // Set up the constraints for the "last" field in each 
        // row first, then copy and modify those constraints.

        // weightx is 1.0 for fields, 0.0 for labels
        // gridwidth is REMAINDER for fields, 1 for labels
        lastConstraints = new GridBagConstraints();

        // Stretch components horizontally (but not vertically)
        lastConstraints.fill = GridBagConstraints.HORIZONTAL;

        // Components that are too short or narrow for their space
        // Should be pinned to the northwest (upper left) corner
        lastConstraints.anchor = GridBagConstraints.NORTHWEST;

        // Give the "last" component as much space as possible
        lastConstraints.weightx = 1.0;

        // Give the "last" component the remainder of the row
        lastConstraints.gridwidth = GridBagConstraints.REMAINDER;

        // Add a little padding
        lastConstraints.insets = new Insets(1, 1, 1, 1);

        // Now for the "middle" field components
        middleConstraints = 
             (GridBagConstraints) lastConstraints.clone();

        // These still get as much space as possible, but do
        // not close out a row
        middleConstraints.gridwidth = GridBagConstraints.RELATIVE;

        // And finally the "label" constrains, typically to be
        // used for the first component on each row
        labelConstraints = 
            (GridBagConstraints) lastConstraints.clone();

        // Give these as little space as necessary
        labelConstraints.weightx = 0.0;
        labelConstraints.gridwidth = 1;
    }

    /**
     * Adds a field component. Any component may be used. The 
     * component will be stretched to take the remainder of 
     * the current row.
     */
    public void addLastField(Component c, Container parent) {
        GridBagLayout gbl = (GridBagLayout) parent.getLayout();
        gbl.setConstraints(c, lastConstraints);
        parent.add(c);
    }
    
    /**
     * Adds an arbitrary label component, starting a new row
     * if appropriate. The width of the component will be set
     * to the minimum width of the widest component on the
     * form.
     */
    public void addLabel(Component c, Container parent) {
        GridBagLayout gbl = (GridBagLayout) parent.getLayout();
        gbl.setConstraints(c, labelConstraints);
        parent.add(c);
    }

    /**
     * Adds a JLabel with the given string to the label column
     */
    public JLabel addLabel(String s, Container parent) {
        JLabel c = new JLabel(s);
        addLabel(c, parent);
        return c;
    }

    /**
     * Adds a "middle" field component. Any component may be 
     * used. The component will be stretched to take all of
     * the space between the label and the "last" field. All
     * "middle" fields in the layout will be the same width.
     */
    public void addMiddleField(Component c, Container parent) {
        GridBagLayout gbl = (GridBagLayout) parent.getLayout();
        gbl.setConstraints(c, middleConstraints);
        parent.add(c);
    }
    
}
