package cc.arduino.view;

import java.awt.Component;
import java.io.File;
import java.util.LinkedList;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.JSeparator;
import javax.swing.event.MenuEvent;
import javax.swing.event.MenuListener;

import processing.app.BaseNoGui;

/**
 * Avoid break rendering of menu while load full menu tree in background  
 * @author Ricardo JL Rufino - (ricardo.jl.rufino@gmail.com)
 * @date 13 de mai de 2020
 */
public class JMenuLazy extends JMenu {
  
  private LinkedList<Component> components = new LinkedList<>();
  
  private boolean loading = false;
  
  public JMenuLazy(String s) {
    super(s);
    addMenuListener(new MenuListenerLazy());
  }

  public void setLoading(boolean loading) {
    this.loading = loading;
    this.setEnabled(!loading);
  }
  
  public boolean isLoading() {
    return loading;
  }
  
  @Override
  public Component add(Component c) {
    if(isLoading()) {
      components.add(c);
      return c;
    }
    return super.add(c);
  }
  
  @Override
  public JMenuItem add(JMenuItem c) {
    if(isLoading()) {
      components.add(c);
      return c;
    }
    return super.add(c);
  }
  
  @Override
  public void addSeparator() {
    if(isLoading()) {
      components.add(new JPopupMenu.Separator());
      return;
    }
    super.addSeparator();
  }
  
  private class MenuListenerLazy implements MenuListener{ 

    @Override
    public void menuSelected(MenuEvent e) {
      if(!isLoading()) {
        if(loading == false) {
          if(!components.isEmpty()) {
            for (Component component : components) {
              if(component instanceof JSeparator) {
                JMenuLazy.super.addSeparator();
              }else {
                JMenuLazy.super.add(component);
                
              }
            }
            components.clear();
          }
        }
      }
    }
  
    @Override
    public void menuDeselected(MenuEvent e) {
      
    }
  
    @Override
    public void menuCanceled(MenuEvent e) {
      
    }
  }

}
