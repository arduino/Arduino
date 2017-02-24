package processing.app.helpers;

import java.awt.event.ActionEvent;
import java.beans.PropertyChangeListener;

import javax.swing.Action;

public class ActionWrapper implements Action {
  protected Action action;

  public ActionWrapper(Action wrapped) {
    this.action = wrapped;
  }

  public Action getWrappedAction() {
    return this.action;
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    this.action.actionPerformed(e);
  }

  @Override
  public Object getValue(String key) {
    return this.action.getValue(key);
  }

  @Override
  public void putValue(String key, Object value) {
    this.action.putValue(key, value);
  }

  @Override
  public void setEnabled(boolean b) {
    this.action.setEnabled(b);
  }

  @Override
  public boolean isEnabled() {
    return this.action.isEnabled();
  }

  @Override
  public void addPropertyChangeListener(PropertyChangeListener listener) {
    this.action.addPropertyChangeListener(listener);
  }

  @Override
  public void removePropertyChangeListener(PropertyChangeListener listener) {
    this.action.removePropertyChangeListener(listener);
  }

}
