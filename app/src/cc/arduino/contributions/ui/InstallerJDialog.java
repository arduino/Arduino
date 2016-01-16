/*
 * This file is part of Arduino.
 *
 * Copyright 2015 Arduino LLC (http://www.arduino.cc/)
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

package cc.arduino.contributions.ui;

import static processing.app.I18n.tr;
import static processing.app.Theme.scale;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowEvent;
import java.util.function.Predicate;
import java.util.stream.Stream;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;
import javax.swing.ScrollPaneConstants;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;
import javax.swing.border.EmptyBorder;
import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumn;
import javax.swing.table.TableColumnModel;

import cc.arduino.contributions.ui.listeners.AbstractKeyListener;
import processing.app.Base;
import processing.app.Theme;

public abstract class InstallerJDialog<T> extends JDialog {

  // Toolbar on top of the window:
  // - Categories drop-down menu
  protected final JComboBox categoryChooser;
  // - Search text-field
  protected final FilterJTextField filterField;
  protected final JPanel filtersContainer;
  // Currently selected category and filters
  protected Predicate<T> categoryFilter;
  protected String[] filters;
  protected final String noConnectionErrorMessage;

  // Real contribution table
  protected JTable contribTable;
  // Model behind the table
  protected final FilteredAbstractTableModel<T> contribModel;
  private final JButton closeButton;
  private final JButton dismissErrorMessageButton;

  abstract protected FilteredAbstractTableModel<T> createContribModel();

  abstract protected TableCellRenderer createCellRenderer();

  abstract protected InstallerTableCell createCellEditor();

  // Bottom:
  // - Progress bar
  protected final ProgressJProgressBar progressBar;
  private final Box progressBox;
  private final Box errorMessageBox;
  private final JLabel errorMessage;

  public InstallerJDialog(Frame parent, String title, ModalityType applicationModal, String noConnectionErrorMessage) {
    super(parent, title, applicationModal);
    this.noConnectionErrorMessage = noConnectionErrorMessage;

    setResizable(true);

    Container pane = getContentPane();
    pane.setLayout(new BorderLayout());

    {
      categoryChooser = new JComboBox();
      categoryChooser.setMaximumRowCount(20);
      categoryChooser.setEnabled(false);

      filterField = new FilterJTextField(tr("Filter your search...")) {
        @Override
        protected void onFilter(String[] _filters) {
          filters = _filters;
          if (contribTable.getCellEditor() != null) {
            contribTable.getCellEditor().stopCellEditing();
          }
          updateIndexFilter(filters, categoryFilter);
        }
      };

      filtersContainer = new JPanel();
      filtersContainer.setLayout(new BoxLayout(filtersContainer, BoxLayout.X_AXIS));
      filtersContainer.add(Box.createHorizontalStrut(5));
      filtersContainer.add(new JLabel(tr("Type")));
      filtersContainer.add(Box.createHorizontalStrut(5));
      filtersContainer.add(categoryChooser);
      filtersContainer.add(Box.createHorizontalStrut(5));
      filtersContainer.add(filterField);
      filtersContainer.setBorder(new EmptyBorder(7, 7, 7, 7));
      pane.add(filtersContainer, BorderLayout.NORTH);
    }

    contribModel = createContribModel();
    contribTable = new JTable(contribModel);
    contribTable.setTableHeader(null);
    contribTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    contribTable.setColumnSelectionAllowed(false);
    contribTable.setDragEnabled(false);
    contribTable.setIntercellSpacing(new Dimension(0, 1));
    contribTable.setShowVerticalLines(false);
    contribTable.setSelectionBackground(Theme.getColor("status.notice.bgcolor"));
    contribTable.addKeyListener(new AbstractKeyListener() {

      @Override
      public void keyReleased(KeyEvent keyEvent) {
        if (keyEvent.getKeyCode() != KeyEvent.VK_DOWN && keyEvent.getKeyCode() != KeyEvent.VK_UP) {
          return;
        }

        if (!contribTable.isEnabled()) {
          return;
        }

        contribTable.editCellAt(contribTable.getSelectedRow(), contribTable.getSelectedColumn());
      }
    });

    {
      TableColumnModel tcm = contribTable.getColumnModel();
      TableColumn col = tcm.getColumn(0);
      col.setCellRenderer(createCellRenderer());
      col.setCellEditor(createCellEditor());
      col.setResizable(true);
    }

    {
      JScrollPane scrollPane = new JScrollPane();
      scrollPane.setViewportView(contribTable);
      scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
      scrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
      scrollPane.getVerticalScrollBar().setUnitIncrement(7);
      pane.add(scrollPane, BorderLayout.CENTER);
    }

    pane.add(Box.createHorizontalStrut(10), BorderLayout.WEST);
    pane.add(Box.createHorizontalStrut(10), BorderLayout.EAST);

    progressBar = new ProgressJProgressBar();
    progressBar.setStringPainted(true);
    progressBar.setString(" ");
    progressBar.setVisible(true);

    errorMessage = new JLabel("");
    errorMessage.setForeground(Color.RED);

    {
      JButton cancelButton = new JButton(tr("Cancel"));
      cancelButton.addActionListener(arg0 -> onCancelPressed());

      progressBox = Box.createHorizontalBox();
      progressBox.add(progressBar);
      progressBox.add(Box.createHorizontalStrut(5));
      progressBox.add(cancelButton);

      dismissErrorMessageButton = new JButton(tr("OK"));
      dismissErrorMessageButton.addActionListener(arg0 -> {
        clearErrorMessage();
        setErrorMessageVisible(false);
      });

      closeButton = new JButton(tr("Close"));
      closeButton.addActionListener(arg0 -> InstallerJDialog.this.dispatchEvent(new WindowEvent(InstallerJDialog.this, WindowEvent.WINDOW_CLOSING)));

      errorMessageBox = Box.createHorizontalBox();
      errorMessageBox.add(Box.createHorizontalGlue());
      errorMessageBox.add(errorMessage);
      errorMessageBox.add(Box.createHorizontalGlue());
      errorMessageBox.add(dismissErrorMessageButton);
      errorMessageBox.add(closeButton);
      errorMessageBox.setVisible(false);
    }

    {
      JPanel progressPanel = new JPanel();
      progressPanel.setBorder(new EmptyBorder(7, 10, 7, 10));
      progressPanel.setLayout(new BoxLayout(progressPanel, BoxLayout.Y_AXIS));
      progressPanel.add(progressBox);
      progressPanel.add(errorMessageBox);
      pane.add(progressPanel, BorderLayout.SOUTH);
    }
    setProgressVisible(false, "");

    setMinimumSize(scale(new Dimension(800, 450)));

    setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

    Base.registerWindowCloseKeys(getRootPane(), e -> InstallerJDialog.this.dispatchEvent(new WindowEvent(InstallerJDialog.this, WindowEvent.WINDOW_CLOSING)));

    SwingUtilities.invokeLater(InstallerJDialog.this::onUpdatePressed);
  }

  public void updateIndexFilter(String[] filters, Predicate<T>... additionalFilters) {
    Stream<Predicate<T>> notNullAdditionalFilters = Stream.of(additionalFilters).filter(filter -> filter != null);
    contribModel.updateIndexFilter(filters, notNullAdditionalFilters);
  }

  public void setErrorMessage(String message) {
    errorMessage.setText("<html><body>" + message + "</body></html>");
    setErrorMessageVisible(true);
  }

  public void clearErrorMessage() {
    errorMessage.setText("");
    setErrorMessageVisible(false);
  }

  public void setProgressVisible(boolean visible, String status) {
    if (visible) {
      setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
    } else {
      setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    }
    errorMessageBox.setVisible(!visible);
    progressBox.setVisible(visible);

    filterField.setEnabled(!visible);
    categoryChooser.setEnabled(!visible);
    contribTable.setEnabled(!visible);
    if (contribTable.getCellEditor() != null) {
      ((InstallerTableCell) contribTable.getCellEditor()).setEnabled(!visible);
      ((InstallerTableCell) contribTable.getCellEditor()).setStatus(status);
    }
  }

  private void setErrorMessageVisible(boolean visible) {
    errorMessage.setVisible(visible);
    dismissErrorMessageButton.setVisible(visible);
    closeButton.setVisible(!visible);
    errorMessageBox.setVisible(true);
  }

  protected final ActionListener categoryChooserActionListener = new ActionListener() {

    @Override
    public void actionPerformed(ActionEvent event) {
      DropdownItem<T> selected = (DropdownItem<T>) categoryChooser.getSelectedItem();
      if (categoryFilter == null || !categoryFilter.equals(selected)) {
        categoryFilter = selected.getFilterPredicate();
        if (contribTable.getCellEditor() != null) {
          contribTable.getCellEditor().stopCellEditing();
        }
        updateIndexFilter(filters, categoryFilter);
      }
    }
  };

  public void setFilterText(String filterText) {
    for (FocusListener listener : filterField.getFocusListeners()) {
      listener.focusGained(new FocusEvent(filterField, FocusEvent.FOCUS_GAINED));
    }
    filterField.setText(filterText);
  }

  public void selectDropdownItemByClassName(String dropdownItem) {
    selectDropdownItemByClassName(categoryChooser, dropdownItem);
  }

  public void selectDropdownItemByClassName(JComboBox combo, String dropdownItem) {
    for (int i = 0; i < combo.getItemCount(); i++) {
      if (dropdownItem.equals(combo.getItemAt(i).getClass().getSimpleName())) {
        combo.setSelectedIndex(i);
        return;
      }
    }
  }

  /**
   * Action performed when the Cancel button is pressed.
   */
  protected void onCancelPressed() {
    clearErrorMessage();
  }

  /**
   * Action performed when the "Update List" button is pressed.
   */
  protected void onUpdatePressed() {
    clearErrorMessage();
  }

}
