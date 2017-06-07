/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Ricardo JL Rufino (ricardo@criativasoft.com.br)
 * Copyright 2015 Arduino LLC
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */
package cc.arduino.autocomplete;

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

//import br.com.criativasoft.cpluslibparser.metadata.TElement;
//import br.com.criativasoft.cpluslibparser.metadata.TFunction;

/**
 * Class responsible for formatting the elements of the autocomplete list
 */
public class CompletionsRenderer extends DefaultListCellRenderer {

  private static final long serialVersionUID = 1L;

  private static final Color HIGHLIGHT_COLOR = new Color(74, 144, 217);

  private static final String GRAY = "#A0A0A0";
  private static final String LIGHT_BLUE = "#008080";

  /**
   * Keeps the HTML descriptions from "wrapping" in the list, which cuts off
   * words.
   */
  private static final String PREFIX = "<html><nobr>";

  private static Map<CompletionType, Icon> iconsTypes = new HashMap<CompletionType, Icon>();

  static {
    iconsTypes.put(CompletionType.CLASS, getIcon("class.gif"));
    iconsTypes.put(CompletionType.ENUM, getIcon("enum.gif"));
    iconsTypes.put(CompletionType.VARIABLE, getIcon("variable.gif"));
    iconsTypes.put(CompletionType.LOCAL_VAR, getIcon("variable_local.gif"));
    iconsTypes.put(CompletionType.STATIC_VAR, getIcon("variable_static.gif"));
    iconsTypes.put(CompletionType.FUNCTION, getIcon("function.gif"));
    iconsTypes.put(CompletionType.ERROR, getIcon("error.gif"));
    iconsTypes.put(CompletionType.TEMPLATE, getIcon("template_obj.gif"));
  }

  private static Icon getIcon(String image) {
    return new ImageIcon(
        CompletionsRenderer.class.getResource("icons/" + image));
  }

  public static Icon getIcon(CompletionType tokenType) {
    return iconsTypes.get(tokenType);
  }

  public CompletionsRenderer() {
    setOpaque(true);
    // Font f = Theme.getDefaultFont();
    Font f = RSyntaxTextArea.getDefaultFont();
    setFont(f.deriveFont(f.getStyle() & ~Font.BOLD)); // remove bold.
  }

  @Override
  public Component getListCellRendererComponent(JList list, Object value,
                                                int index, boolean isSelected,
                                                boolean cellHasFocus) {

    String text = null;
    CompletionType tokenType = null;

    // if (value instanceof TElementCompletion) {
    //
    // TElementCompletion completion = (TElementCompletion) value;
    // TElement element = completion.getElement();
    // tokenType = completion.getType();
    // text = element.getHtmlRepresentation();
    //
    // } else if (value instanceof TFunctionCompletion) {
    //
    // TFunctionCompletion completion = (TFunctionCompletion) value;
    // TFunction function = completion.getFunction();
    // text = function.getHtmlRepresentation();
    // tokenType = CompletionType.FUNCTION;
    //
    // } else
    if (value instanceof ShorthandCompletion) {
      text = ((ShorthandCompletion) value).getShortDescription();
      tokenType = CompletionType.TEMPLATE;
    } else if (value instanceof FunctionCompletion) {
      text = ((FunctionCompletion) value).getShortDescription();
      tokenType = CompletionType.FUNCTION;
    } else if (value instanceof BasicCompletion) {
      text = ((BasicCompletion) value).getInputText();
      if (((BasicCompletion) value).getShortDescription() != null) {
        text = ((BasicCompletion) value).getShortDescription();
      }
    } else if (value instanceof TemplateCompletion) {
      TemplateCompletion template = (TemplateCompletion) value;
      text = font(template.getInputText(), LIGHT_BLUE)
             + font(" - " + template.getDefinitionString(), GRAY);
    }

    if (text == null) {
      text = value.toString();
    }

    // Find Icon
    if (tokenType != null) {
      setIcon(iconsTypes.get(tokenType));
    } else {
      setIcon(iconsTypes.get(CompletionType.TEMPLATE));
    }

    if (isSelected) {
      setText(text.replaceAll("\\<[^>]*>", ""));
      setBackground(HIGHLIGHT_COLOR);
      setForeground(Color.white);
    } else {
      setText(PREFIX + text);
      setBackground(Color.white);
      setForeground(Color.black);
    }

    return this;
  }

  private String font(String text, String color) {
    return "<font color='" + color + "'>" + text + "</font>";
  }

}