package processing.app;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JMenuItem;

/**
 * Serial button on serial bar, added by Felix Rusu
 */
public class ShortcutBarButton extends JButton {
  public boolean selected;
  public String ref;
  JMenuItem itemToClick;
  
  public ShortcutBarButton(String label, String ref, JMenuItem itemToClick, boolean selected, Color selectedColor) {
    super(label);
    this.ref = ref;
    this.selected = selected;
    this.itemToClick = itemToClick;
    this.setBackground(selected ? selectedColor : Color.GRAY);
    this.setForeground(selected ? selectedColor : Color.BLACK);
    this.setOpaque(true);
    this.setBorderPainted(false);

    if (itemToClick != null)
    {
      addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
          itemToClick.doClick();
        }
      });
    }
  }
  
  @Override
  public String toString() {
    StringBuilder str = new StringBuilder();
    str.append("[");
    if (this.selected) str.append("!");
    str.append(this.ref);
    str.append("]");
    return str.toString();
  }
}