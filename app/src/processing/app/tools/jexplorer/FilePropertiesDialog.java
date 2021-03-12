package processing.app.tools.jexplorer;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.text.DateFormat;
import java.util.Date;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.KeyStroke;

import processing.app.tools.jexplorer.utils.FormUtility;
import processing.app.tools.jexplorer.utils.Translate;

public class FilePropertiesDialog extends JDialog {

  private File file;

  private Translate translate;

  public FilePropertiesDialog(File file, Translate translate) {
    super((JFrame)null);
    this.file = file;
    this.translate = translate;
    initComponents();
  }

  private void initComponents() {
    
    setTitle(tr("Properties"));
    
    Action escapeAction = new AbstractAction() {
      @Override
      public void actionPerformed(ActionEvent ae) {
          dispose();
      }
    };
  
    getRootPane().getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW).put(KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), "ESCAPE_KEY");
    getRootPane().getActionMap().put("ESCAPE_KEY", escapeAction);
    
    JPanel form = new JPanel(new GridBagLayout());
    getContentPane().setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
    getContentPane().add(form);
    
    form.setBorder(BorderFactory.createTitledBorder(tr("File Properties")));
    
    FormUtility formUtility = new FormUtility();
    
    formUtility.addLabel(tr("Name: "), form);
    formUtility.addLastField(new JLabel(file.getName()), form);
    
    formUtility.addLabel(tr("Size: "), form);
    formUtility.addLastField(new JLabel(file.length()+ " bytes"), form);
    
    String date = DateFormat.getDateTimeInstance().format(new Date(file.lastModified()));
    formUtility.addLabel(tr("Date: "), form);
    formUtility.addLastField(new JLabel(date), form);
    
    JPanel form2 = new JPanel(new GridBagLayout());
    form2.setBorder(BorderFactory.createTitledBorder(tr("Location")));
    getContentPane().add(form2); 
    
    JButton open = new JButton(tr("Open"));
    JTextField textField = new JTextField(file.getAbsolutePath(), 30);
    textField.setEditable(false);
    open.setPreferredSize(new Dimension(open.getPreferredSize().width, textField.getPreferredSize().height));
    
    formUtility.addLabel(textField, form2);
    formUtility.addLastField(open, form2);
    
    JPanel buttons = new JPanel(new FlowLayout(FlowLayout.RIGHT));
    getContentPane().add(buttons); 
    
    JButton close = new JButton(tr("Close"));
    close.addActionListener(escapeAction);
    buttons.add(close);
    pack();

    // add listener to handle window close box hit event
    addWindowListener(new WindowAdapter() {
      @Override
      public void windowOpened(WindowEvent e) {
        close.requestFocus();
      }
    });
    
  }

  private static final long serialVersionUID = 1L;

  
  public void setTranslate(Translate translate) {
    this.translate = translate;
  }
  
  private String tr(String name) {
    if(translate == null) return name;
    return translate.get(name);
  }
  
}
