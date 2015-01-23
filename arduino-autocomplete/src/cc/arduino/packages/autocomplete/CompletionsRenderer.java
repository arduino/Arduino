package cc.arduino.packages.autocomplete;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;
import java.util.HashMap;
import java.util.Map;

import javax.swing.DefaultListCellRenderer;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JList;

import org.fife.ui.autocomplete.BasicCompletion;
import org.fife.ui.autocomplete.FunctionCompletion;
import org.fife.ui.autocomplete.ShorthandCompletion;
import org.fife.ui.autocomplete.TemplateCompletion;
import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;

import br.com.criativasoft.cpluslibparser.metadata.TElement;
import br.com.criativasoft.cpluslibparser.metadata.TFunction;

/**
 * Class responsible for formatting the elements of the autocomplete list
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br) 
 * @date 11/12/2014
 */
public class CompletionsRenderer extends DefaultListCellRenderer {
  
  private static final long serialVersionUID = 1L;

  private static final Color HIGHLIGHT_COLOR = new Color(74, 144, 217);
  
  private static final String GRAY = "#A0A0A0";
  private static final String LIGHT_BLUE = "#008080";
  
  /** Keeps the HTML descriptions from "wrapping" in the list, which cuts off words. */
  private static final String PREFIX = "<html><nobr>";
  
  private static Map<CompletionType, Icon> iconsTypes = new HashMap<CompletionType, Icon>();
  
  static{
    iconsTypes.put(CompletionType.CLASS, getIcon("class.gif"));
    iconsTypes.put(CompletionType.ENUM, getIcon("enum.gif"));
    iconsTypes.put(CompletionType.VARIABLE, getIcon("variable.gif"));
    iconsTypes.put(CompletionType.LOCAL_VAR, getIcon("variable_local.gif"));
    iconsTypes.put(CompletionType.STATIC_VAR, getIcon("variable_static.gif"));
    iconsTypes.put(CompletionType.FUNCTION, getIcon("function.gif"));
    iconsTypes.put(CompletionType.ERROR, getIcon("error.gif"));
    iconsTypes.put(CompletionType.TEMPLATE, getIcon("template_obj.gif"));
  }
  
  
  private static Icon getIcon(String image){
     return new ImageIcon(CompletionsRenderer.class.getResource("icons/"+image));
  }
  
  public static Icon getIcon(CompletionType tokenType){
    return iconsTypes.get(tokenType);
  }

  public CompletionsRenderer() {
    setOpaque(true);
    // Font f = Theme.getDefaultFont();
    Font f = RSyntaxTextArea.getDefaultFont();
    setFont(f.deriveFont(f.getStyle() & ~Font.BOLD)); // remove bold.
  }
  
  @Override
  public Component getListCellRendererComponent(JList<?> list, Object value,
                                                int index, boolean isSelected,
                                                boolean cellHasFocus) {
    
    String text = null;
    CompletionType tokenType = null;
    
    if(value instanceof TElementCompletion){
      
      TElementCompletion completion = (TElementCompletion) value;
      TElement element = completion.getElement();
      tokenType = completion.getType();
      text = element.getHtmlRepresentation();
      
    }else if(value instanceof TFunctionCompletion){
      
      TFunctionCompletion completion =  (TFunctionCompletion) value;
      TFunction function = completion.getFunction();
      text = function.getHtmlRepresentation();
      tokenType =  CompletionType.FUNCTION;      
      
    }else if(value instanceof ShorthandCompletion){
      text = ((ShorthandCompletion) value).getShortDescription();
      tokenType = CompletionType.TEMPLATE;
    }else if(value instanceof FunctionCompletion){
      text = ((FunctionCompletion) value).getShortDescription();
      tokenType = CompletionType.FUNCTION;
    }else if(value instanceof BasicCompletion){
      text = ((BasicCompletion) value).getInputText();
    }else if(value instanceof TemplateCompletion){
      TemplateCompletion template = (TemplateCompletion) value;
      text = font(template.getInputText(), LIGHT_BLUE) + font(" - " + template.getDefinitionString(), GRAY) ;
    }
    
    if(text == null){
      text = value.toString();
    }
    
    // Find Icon
    if(tokenType != null){
      setIcon(iconsTypes.get(tokenType));
    }else{
      setIcon(iconsTypes.get(CompletionType.TEMPLATE));
    }
    
    if (isSelected) {
      setText(text.replaceAll("\\<[^>]*>",""));
      setBackground(HIGHLIGHT_COLOR);
      setForeground(Color.white);
    } else {
      setText(PREFIX + text);
      setBackground(Color.white);
      setForeground(Color.black);
    }
    
    return this;
  }
  
  private String font(String text, String color){
    return "<font color='"+color+"'>"+text+"</font>";
  }

}
