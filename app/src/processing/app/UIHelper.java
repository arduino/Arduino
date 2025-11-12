package processing.app;

import java.awt.Font;
import java.lang.reflect.Field;
import java.util.Map;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JRadioButton;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JSlider;
import javax.swing.JSpinner;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToggleButton;
import javax.swing.LookAndFeel;
import javax.swing.UIManager;
import javax.swing.plaf.FontUIResource;

import processing.app.helpers.OSUtils;

public class UIHelper {
  public static void scaleElements(float scale) throws Exception {

    Font menuFont = UIManager.getFont("Menu.font");
    Font f = new Font(menuFont.getFontName(), menuFont.getStyle(), (int)((float)menuFont.getSize() * scale));
    UIManager.put("Button.font", f);
    UIManager.put("ToggleButton.font", f);
    UIManager.put("RadioButton.font", f);
    UIManager.put("CheckBox.font", f);
    UIManager.put("ColorChooser.font", f);
    UIManager.put("ComboBox.font", f);
    UIManager.put("Label.font", f);
    UIManager.put("List.font", f);
    UIManager.put("MenuBar.font", f);
    UIManager.put("MenuItem.font", f);
    UIManager.put("RadioButtonMenuItem.font", f);
    UIManager.put("CheckBoxMenuItem.font", f);
    UIManager.put("Menu.font", f);
    UIManager.put("PopupMenu.font", f);
    UIManager.put("OptionPane.font", f);
    UIManager.put("Panel.font", f);
    UIManager.put("ProgressBar.font", f);
    UIManager.put("ScrollPane.font", f);
    UIManager.put("Viewport.font", f);
    UIManager.put("TabbedPane.font", f);
    UIManager.put("Table.font", f);
    UIManager.put("TableHeader.font", f);
    UIManager.put("TextField.font", f);
    UIManager.put("PasswordField.font", f);
    UIManager.put("TextArea.font", f);
    UIManager.put("TextPane.font", f);
    UIManager.put("EditorPane.font", f);
    UIManager.put("TitledBorder.font", f);
    UIManager.put("ToolBar.font", f);
    UIManager.put("ToolTip.font", f);
    UIManager.put("Tree.font", f);

    // On Linux this doesn't seem to be enough :(
    if (OSUtils.isLinux()) {
      checkGTKLookAndFeel(scale);
    }
  }

  // Stolen from https://stackoverflow.com/a/31345102 , helps bypassing GTK LaF endless bugs
  private static void checkGTKLookAndFeel(float scale) throws Exception {
    LookAndFeel look = UIManager.getLookAndFeel();
    if (!look.getID().equals("GTK")) return;

    new JFrame();
    new JButton();
    new JComboBox();
    new JRadioButton();
    new JCheckBox();
    new JTextArea();
    new JTextField();
    new JTable();
    new JToggleButton();
    new JSpinner();
    new JSlider();
    new JTabbedPane();
    new JMenu();
    new JMenuBar();
    new JRadioButtonMenuItem();
    new JLabel();
    new JCheckBoxMenuItem();

    Object styleFactory;
    Field styleFactoryField = look.getClass().getDeclaredField("styleFactory");
    styleFactoryField.setAccessible(true);
    styleFactory = styleFactoryField.get(look);

    Field defaultFontField = styleFactory.getClass().getDeclaredField("defaultFont");
    defaultFontField.setAccessible(true);
    Font defaultFont = (Font) defaultFontField.get(styleFactory);
    FontUIResource newFontUI;
    newFontUI = new FontUIResource(defaultFont.deriveFont((float)(defaultFont.getSize() * scale)));
    defaultFontField.set(styleFactory, newFontUI);

    Field stylesCacheField = styleFactory.getClass().getDeclaredField("stylesCache");
    stylesCacheField.setAccessible(true);
    Object stylesCache = stylesCacheField.get(styleFactory);
    Map stylesMap = (Map) stylesCache;
    for (Object mo : stylesMap.values()) {
        Field f = mo.getClass().getDeclaredField("font");
        f.setAccessible(true);
        Font fo = (Font)f.get(mo);
        f.set(mo, fo.deriveFont((float)(fo.getSize() * scale)));
    }
  }
}
