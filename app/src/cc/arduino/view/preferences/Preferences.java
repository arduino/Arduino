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

package cc.arduino.view.preferences;

import cc.arduino.Constants;
import processing.app.Base;
import processing.app.BaseNoGui;
import processing.app.I18n;
import processing.app.PreferencesData;
import processing.app.helpers.FileUtils;
import processing.app.legacy.PApplet;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.io.File;
import java.util.LinkedList;

import static processing.app.I18n.tr;

public class Preferences extends javax.swing.JDialog {

  private final Language[] languages;

  // Languages that are not translated at least to 65% are
  // kept in the "missingLanguages" array until they have enough
  // translated strings.
  @SuppressWarnings("unused")
  private final Language[] missingLanguages;

  private final WarningItem[] warningItems;
  private final Base base;

  public static class Language {

    private final String name;
    private final String originalName;
    private final String isoCode;

    public Language(String name, String originalName, String isoCode) {
      this.name = name;
      this.originalName = originalName;
      this.isoCode = isoCode;
    }

    public String toString() {
      if (originalName.length() == 0) {
        return name;
      }
      return originalName + " (" + name + ")";
    }

    public String getIsoCode() {
      return isoCode;
    }
  }

  private static class WarningItem {
    private final String value;
    private final String translation;

    public WarningItem(String value, String translation) {
      this.value = value;
      this.translation = translation;
    }

    public String getValue() {
      return value;
    }

    @Override
    public String toString() {
      return translation;
    }
  }

  public Preferences(Window parent, Base base) {
    super(parent);
    this.base = base;

    this.languages = new Language[]{
      new Language(tr("System Default"), "", ""),
      new Language(tr("Albanian"), "shqip", "sq"),
      new Language(tr("Arabic"), "العربية", "ar"),
      new Language(tr("Aragonese"), "Aragonés", "an"),
      new Language(tr("Basque"), "Euskara", "eu"),
      new Language(tr("Belarusian"), "Беларуская мова", "be"),
      new Language(tr("Bulgarian"), "български", "bg"),
      new Language(tr("Canadian French"), "Canadienne-français", "fr_CA"),
      new Language(tr("Catalan"), "Català", "ca"),
      new Language(tr("Chinese (China)"), "简体中文", "zh_CN"),
      new Language(tr("Chinese (Taiwan) (Big5)"), "", "zh_TW.Big5"),
      new Language(tr("Chinese (Taiwan)"), "", "zh_TW"),
      new Language(tr("Croatian"), "Hrvatski", "hr_HR"),
      new Language(tr("Czech (Czech Republic)"), "český (Czech Republic)", "cs_CZ"),
      new Language(tr("Dutch"), "Nederlands", "nl"),
      new Language(tr("English"), "English", "en"),
      new Language(tr("English (United Kingdom)"), "English (United Kingdom)", "en_GB"),
      new Language(tr("Estonian"), "Eesti", "et"),
      new Language(tr("Estonian (Estonia)"), "Eesti keel", "et_EE"),
      new Language(tr("Filipino"), "Pilipino", "fil"),
      new Language(tr("Finnish"), "Suomi", "fi"),
      new Language(tr("French"), "Français", "fr"),
      new Language(tr("Galician"), "Galego", "gl"),
      new Language(tr("Galician (Spain)"), "Galego (Spain)", "gl_ES"),
      new Language(tr("Georgian"), "საქართველოს", "ka_GE"),
      new Language(tr("German"), "Deutsch", "de_DE"),
      new Language(tr("Hebrew"), "עברית", "he"),
      new Language(tr("Hindi"), "हिंदी", "hi"),
      new Language(tr("Indonesian"), "Bahasa Indonesia", "id"),
      new Language(tr("Italian"), "Italiano", "it_IT"),
      new Language(tr("Japanese"), "日本語", "ja_JP"),
      new Language(tr("Korean"), "한국어", "ko_KR"),
      new Language(tr("Latvian"), "Latviešu", "lv_LV"),
      new Language(tr("Norwegian Bokmål"), "Norsk bokmål", "nb_NO"),
      new Language(tr("Persian"), "فارسی", "fa"),
      new Language(tr("Polish"), "Język Polski", "pl"),
      new Language(tr("Portugese"), "Português", "pt"),
      new Language(tr("Portuguese (Brazil)"), "Português (Brazil)", "pt_BR"),
      new Language(tr("Portuguese (Portugal)"), "Português (Portugal)", "pt_PT"),
      new Language(tr("Romanian"), "Română", "ro"),
      new Language(tr("Russian"), "Русский", "ru"),
      new Language(tr("Slovak"), "Slovenčina", "sk"),
      new Language(tr("Slovenian"), "Slovenščina", "sl_SI"),
      new Language(tr("Spanish"), "Español", "es"),
      new Language(tr("Swedish"), "Svenska", "sv"),
      new Language(tr("Tamil"), "தமிழ்", "ta"),
      new Language(tr("Turkish"), "Türk", "tr"),
      new Language(tr("Ukrainian"), "Український", "uk"),
      new Language(tr("Vietnamese"), "Tiếng Việt", "vi"),
    };

    this.missingLanguages = new Language[]{
      new Language(tr("Afrikaans"), "Afrikaans", "af"),
      new Language(tr("Armenian"), "Հայերեն", "hy"),
      new Language(tr("Asturian"), "Asturianu", "ast"),
      new Language(tr("Bosnian"), "Bosanski", "bs"),
      new Language(tr("Burmese (Myanmar)"), "ဗမာစကား", "my_MM"),
      new Language(tr("Danish (Denmark)"), "Dansk (Denmark)", "da_DK"),
      new Language(tr("Dutch (Netherlands)"), "Nederlands", "nl_NL"),
      new Language(tr("Greek"), "ελληνικά", "el_GR"),
      new Language(tr("Hungarian"), "Magyar", "hu"),
      new Language(tr("Lithuaninan"), "Lietuvių Kalba", "lt_LT"),
      new Language(tr("Marathi"), "मराठी", "mr"),
      new Language(tr("Nepali"), "नेपाली", "ne"),
      new Language(tr("Persian (Iran)"), "فارسی (Iran)", "fa_IR"),
      new Language(tr("Talossan"), "Talossan", "tzl"),
      new Language(tr("Western Frisian"), "Western Frisian", "fy")
    };

    this.warningItems = new WarningItem[]{
      new WarningItem("none", tr("None")),
      new WarningItem("default", tr("Default")),
      new WarningItem("more", tr("More")),
      new WarningItem("all", tr("All"))
    };

    initComponents();

    Base.registerWindowCloseKeys(getRootPane(), this::cancelButtonActionPerformed);

    showPrerefencesData();
  }

  /**
   * This method is called from within the constructor to initialize the form.
   * WARNING: Do NOT modify this code. The content of this method is always
   * regenerated by the Form Editor.
   */
  @SuppressWarnings("unchecked")
  // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
  private void initComponents() {

    proxyTypeButtonGroup = new javax.swing.ButtonGroup();
    manualProxyTypeButtonGroup = new javax.swing.ButtonGroup();
    javax.swing.JPanel jPanel2 = new javax.swing.JPanel();
    javax.swing.JTabbedPane jTabbedPane1 = new javax.swing.JTabbedPane();
    javax.swing.JPanel jPanel1 = new javax.swing.JPanel();
    javax.swing.JLabel sketchbookLocationLabel = new javax.swing.JLabel();
    sketchbookLocationField = new javax.swing.JTextField();
    javax.swing.JButton browseButton = new javax.swing.JButton();
    javax.swing.JLabel comboLanguageLabel = new javax.swing.JLabel();
    comboLanguage = new JComboBox(languages);
    javax.swing.JLabel requiresRestartLabel = new javax.swing.JLabel();
    javax.swing.JLabel fontSizeLabel = new javax.swing.JLabel();
    fontSizeField = new javax.swing.JTextField();
    javax.swing.JLabel showVerboseLabel = new javax.swing.JLabel();
    verboseCompilationBox = new javax.swing.JCheckBox();
    verboseUploadBox = new javax.swing.JCheckBox();
    javax.swing.JLabel comboWarningsLabel = new javax.swing.JLabel();
    comboWarnings = new JComboBox(warningItems);
    javax.swing.JLabel additionalBoardsManagerLabel = new javax.swing.JLabel();
    additionalBoardsManagerField = new javax.swing.JTextField();
    javax.swing.JButton extendedAdditionalUrlFieldWindow = new javax.swing.JButton();
    javax.swing.JLabel morePreferencesLabel = new javax.swing.JLabel();
    preferencesFileLabel = new javax.swing.JLabel();
    javax.swing.JLabel arduinoNotRunningLabel = new javax.swing.JLabel();
    javax.swing.JPanel checkboxesContainer = new javax.swing.JPanel();
    displayLineNumbersBox = new javax.swing.JCheckBox();
    enableCodeFoldingBox = new javax.swing.JCheckBox();
    verifyUploadBox = new javax.swing.JCheckBox();
    externalEditorBox = new javax.swing.JCheckBox();
    checkUpdatesBox = new javax.swing.JCheckBox();
    updateExtensionBox = new javax.swing.JCheckBox();
    saveVerifyUploadBox = new javax.swing.JCheckBox();
    javax.swing.JPanel jPanel4 = new javax.swing.JPanel();
    noProxy = new javax.swing.JRadioButton();
    autoProxy = new javax.swing.JRadioButton();
    manualProxy = new javax.swing.JRadioButton();
    autoProxyUsePAC = new javax.swing.JCheckBox();
    autoProxyPACURL = new javax.swing.JTextField();
    manualProxyHTTP = new javax.swing.JRadioButton();
    manualProxySOCKS = new javax.swing.JRadioButton();
    manualProxyHostNameLabel = new javax.swing.JLabel();
    manualProxyPortLabel = new javax.swing.JLabel();
    manualProxyHostName = new javax.swing.JTextField();
    manualProxyPort = new javax.swing.JTextField();
    manualProxyUsernameLabel = new javax.swing.JLabel();
    manualProxyUsername = new javax.swing.JTextField();
    manualProxyPasswordLabel = new javax.swing.JLabel();
    manualProxyPassword = new javax.swing.JPasswordField();
    autoProxyUsernameLabel = new javax.swing.JLabel();
    autoProxyUsername = new javax.swing.JTextField();
    autoProxyPassword = new javax.swing.JPasswordField();
    autoProxyPasswordLabel = new javax.swing.JLabel();
    javax.swing.JPanel jPanel3 = new javax.swing.JPanel();
    javax.swing.JButton okButton = new javax.swing.JButton();
    javax.swing.JButton cancelButton = new javax.swing.JButton();

    setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
    setTitle(tr("Preferences"));
    setModal(true);
    setResizable(false);

    jPanel2.setLayout(new javax.swing.BoxLayout(jPanel2, javax.swing.BoxLayout.Y_AXIS));

    jTabbedPane1.setFocusable(false);
    jTabbedPane1.setRequestFocusEnabled(false);

    sketchbookLocationLabel.setText(tr("Sketchbook location:"));

    sketchbookLocationField.setColumns(40);

    browseButton.setText(I18n.PROMPT_BROWSE);
    browseButton.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(java.awt.event.ActionEvent evt) {
        browseButtonActionPerformed(evt);
      }
    });

    comboLanguageLabel.setText(tr("Editor language: "));

    requiresRestartLabel.setText(tr("  (requires restart of Arduino)"));

    fontSizeLabel.setText(tr("Editor font size: "));

    fontSizeField.setColumns(4);

    showVerboseLabel.setText(tr("Show verbose output during: "));

    verboseCompilationBox.setText(tr("compilation "));

    verboseUploadBox.setText(tr("upload"));

    comboWarningsLabel.setText(tr("Compiler warnings: "));

    additionalBoardsManagerLabel.setText(tr("Additional Boards Manager URLs: "));
    additionalBoardsManagerLabel.setToolTipText(tr("Enter a comma separated list of urls"));

    additionalBoardsManagerField.setToolTipText(tr("Enter a comma separated list of urls"));

    extendedAdditionalUrlFieldWindow.setIcon(new ImageIcon(Base.getThemeImage("newwindow.gif", this)));
    extendedAdditionalUrlFieldWindow.setMargin(new java.awt.Insets(1, 1, 1, 1));
    extendedAdditionalUrlFieldWindow.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(java.awt.event.ActionEvent evt) {
        extendedAdditionalUrlFieldWindowActionPerformed(evt);
      }
    });

    morePreferencesLabel.setForeground(Color.GRAY);
    morePreferencesLabel.setText(tr("More preferences can be edited directly in the file"));

    preferencesFileLabel.setText(PreferencesData.getPreferencesFile().getAbsolutePath());
    preferencesFileLabel.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
    preferencesFileLabel.addMouseListener(new java.awt.event.MouseAdapter() {
      public void mousePressed(java.awt.event.MouseEvent evt) {
        preferencesFileLabelMousePressed(evt);
      }

      public void mouseExited(java.awt.event.MouseEvent evt) {
        preferencesFileLabelMouseExited(evt);
      }

      public void mouseEntered(java.awt.event.MouseEvent evt) {
        preferencesFileLabelMouseEntered(evt);
      }
    });

    arduinoNotRunningLabel.setForeground(Color.GRAY);
    arduinoNotRunningLabel.setText(tr("(edit only when Arduino is not running)"));

    checkboxesContainer.setLayout(new javax.swing.BoxLayout(checkboxesContainer, javax.swing.BoxLayout.Y_AXIS));

    displayLineNumbersBox.setText(tr("Display line numbers"));
    checkboxesContainer.add(displayLineNumbersBox);

    enableCodeFoldingBox.setText(tr("Enable Code Folding"));
    checkboxesContainer.add(enableCodeFoldingBox);

    verifyUploadBox.setText(tr("Verify code after upload"));
    checkboxesContainer.add(verifyUploadBox);

    externalEditorBox.setText(tr("Use external editor"));
    checkboxesContainer.add(externalEditorBox);

    checkUpdatesBox.setText(tr("Check for updates on startup"));
    checkboxesContainer.add(checkUpdatesBox);

    updateExtensionBox.setText(tr("Update sketch files to new extension on save (.pde -> .ino)"));
    checkboxesContainer.add(updateExtensionBox);

    saveVerifyUploadBox.setText(tr("Save when verifying or uploading"));
    checkboxesContainer.add(saveVerifyUploadBox);

    javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
    jPanel1.setLayout(jPanel1Layout);
    jPanel1Layout.setHorizontalGroup(
      jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGroup(jPanel1Layout.createSequentialGroup()
          .addContainerGap()
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
              .addComponent(sketchbookLocationField)
              .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
              .addComponent(browseButton))
            .addComponent(checkboxesContainer, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(jPanel1Layout.createSequentialGroup()
              .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel1Layout.createSequentialGroup()
                  .addComponent(comboWarningsLabel)
                  .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                  .addComponent(comboWarnings, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGroup(jPanel1Layout.createSequentialGroup()
                  .addComponent(showVerboseLabel)
                  .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                  .addComponent(verboseCompilationBox)
                  .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                  .addComponent(verboseUploadBox))
                .addGroup(jPanel1Layout.createSequentialGroup()
                  .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(comboLanguageLabel)
                    .addComponent(fontSizeLabel))
                  .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                  .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(fontSizeField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                      .addComponent(comboLanguage, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                      .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                      .addComponent(requiresRestartLabel))))
                .addComponent(arduinoNotRunningLabel)
                .addComponent(morePreferencesLabel)
                .addComponent(preferencesFileLabel)
                .addComponent(sketchbookLocationLabel)
                .addGroup(jPanel1Layout.createSequentialGroup()
                  .addComponent(additionalBoardsManagerLabel)
                  .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                  .addComponent(additionalBoardsManagerField, javax.swing.GroupLayout.PREFERRED_SIZE, 500, javax.swing.GroupLayout.PREFERRED_SIZE)
                  .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                  .addComponent(extendedAdditionalUrlFieldWindow)))
              .addGap(0, 0, Short.MAX_VALUE)))
          .addContainerGap())
    );
    jPanel1Layout.setVerticalGroup(
      jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
          .addContainerGap()
          .addComponent(sketchbookLocationLabel)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(sketchbookLocationField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(browseButton))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(comboLanguageLabel)
            .addComponent(comboLanguage, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(requiresRestartLabel))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(fontSizeLabel)
            .addComponent(fontSizeField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(showVerboseLabel)
            .addComponent(verboseCompilationBox)
            .addComponent(verboseUploadBox))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(comboWarningsLabel)
            .addComponent(comboWarnings, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(checkboxesContainer, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
              .addComponent(additionalBoardsManagerLabel)
              .addComponent(additionalBoardsManagerField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addComponent(extendedAdditionalUrlFieldWindow))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(morePreferencesLabel)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(preferencesFileLabel)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(arduinoNotRunningLabel)
          .addContainerGap())
    );

    jTabbedPane1.addTab(tr("Settings"), jPanel1);

    proxyTypeButtonGroup.add(noProxy);
    noProxy.setText(tr("No proxy"));
    noProxy.setActionCommand(Constants.PROXY_TYPE_NONE);

    proxyTypeButtonGroup.add(autoProxy);
    autoProxy.setText(tr("Auto-detect proxy settings"));
    autoProxy.setActionCommand(Constants.PROXY_TYPE_AUTO);
    autoProxy.addItemListener(new java.awt.event.ItemListener() {
      public void itemStateChanged(java.awt.event.ItemEvent evt) {
        autoProxyItemStateChanged(evt);
      }
    });

    proxyTypeButtonGroup.add(manualProxy);
    manualProxy.setText(tr("Manual proxy configuration"));
    manualProxy.setActionCommand(Constants.PROXY_TYPE_MANUAL);
    manualProxy.addItemListener(new java.awt.event.ItemListener() {
      public void itemStateChanged(java.awt.event.ItemEvent evt) {
        manualProxyItemStateChanged(evt);
      }
    });

    autoProxyUsePAC.setText(tr("Automatic proxy configuration URL:"));
    autoProxyUsePAC.addItemListener(new java.awt.event.ItemListener() {
      public void itemStateChanged(java.awt.event.ItemEvent evt) {
        autoProxyUsePACItemStateChanged(evt);
      }
    });

    manualProxyTypeButtonGroup.add(manualProxyHTTP);
    manualProxyHTTP.setText("HTTP");
    manualProxyHTTP.setActionCommand(Constants.PROXY_MANUAL_TYPE_HTTP);

    manualProxyTypeButtonGroup.add(manualProxySOCKS);
    manualProxySOCKS.setText("SOCKS");
    manualProxySOCKS.setActionCommand(Constants.PROXY_MANUAL_TYPE_SOCKS);

    manualProxyHostNameLabel.setText(tr("Host name:"));

    manualProxyPortLabel.setText(tr("Port number:"));

    manualProxyUsernameLabel.setText(tr("Username:"));

    manualProxyPasswordLabel.setText(tr("Password:"));

    manualProxyPassword.setToolTipText("");

    autoProxyUsernameLabel.setText(tr("Username:"));

    autoProxyPassword.setToolTipText("");

    autoProxyPasswordLabel.setText(tr("Password:"));

    javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
    jPanel4.setLayout(jPanel4Layout);
    jPanel4Layout.setHorizontalGroup(
      jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGroup(jPanel4Layout.createSequentialGroup()
          .addContainerGap()
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
              .addGap(12, 12, 12)
              .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(autoProxyUsePAC)
                .addGroup(jPanel4Layout.createSequentialGroup()
                  .addGap(12, 12, 12)
                  .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(autoProxyUsernameLabel)
                    .addComponent(autoProxyPasswordLabel))))
              .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
              .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(autoProxyPACURL)
                .addGroup(jPanel4Layout.createSequentialGroup()
                  .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(autoProxyUsername, javax.swing.GroupLayout.PREFERRED_SIZE, 178, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(autoProxyPassword, javax.swing.GroupLayout.PREFERRED_SIZE, 180, javax.swing.GroupLayout.PREFERRED_SIZE))
                  .addGap(0, 0, Short.MAX_VALUE))))
            .addGroup(jPanel4Layout.createSequentialGroup()
              .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(noProxy)
                .addComponent(autoProxy)
                .addComponent(manualProxy)
                .addGroup(jPanel4Layout.createSequentialGroup()
                  .addGap(12, 12, 12)
                  .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel4Layout.createSequentialGroup()
                      .addComponent(manualProxyHTTP)
                      .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                      .addComponent(manualProxySOCKS))
                    .addGroup(jPanel4Layout.createSequentialGroup()
                      .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(manualProxyHostNameLabel)
                        .addComponent(manualProxyPortLabel)
                        .addComponent(manualProxyUsernameLabel)
                        .addComponent(manualProxyPasswordLabel))
                      .addGap(18, 18, 18)
                      .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(manualProxyHostName, javax.swing.GroupLayout.PREFERRED_SIZE, 541, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(manualProxyPort, javax.swing.GroupLayout.PREFERRED_SIZE, 74, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                          .addComponent(manualProxyPassword, javax.swing.GroupLayout.Alignment.LEADING)
                          .addComponent(manualProxyUsername, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, 180, javax.swing.GroupLayout.PREFERRED_SIZE)))))))
              .addGap(0, 0, Short.MAX_VALUE)))
          .addContainerGap())
    );
    jPanel4Layout.setVerticalGroup(
      jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGroup(jPanel4Layout.createSequentialGroup()
          .addContainerGap()
          .addComponent(noProxy)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(autoProxy)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(autoProxyUsePAC)
            .addComponent(autoProxyPACURL, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(autoProxyUsername, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(autoProxyUsernameLabel))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(autoProxyPasswordLabel)
            .addComponent(autoProxyPassword, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(manualProxy)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(manualProxyHTTP)
            .addComponent(manualProxySOCKS))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(manualProxyHostNameLabel)
            .addComponent(manualProxyHostName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(manualProxyPort, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(manualProxyPortLabel))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(manualProxyUsername, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(manualProxyUsernameLabel))
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(manualProxyPassword, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(manualProxyPasswordLabel))
          .addContainerGap(163, Short.MAX_VALUE))
    );

    jTabbedPane1.addTab(tr("Network"), jPanel4);

    jPanel2.add(jTabbedPane1);

    okButton.setText(I18n.PROMPT_OK);
    okButton.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(java.awt.event.ActionEvent evt) {
        okButtonActionPerformed(evt);
      }
    });

    cancelButton.setText(I18n.PROMPT_CANCEL);
    cancelButton.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(java.awt.event.ActionEvent evt) {
        cancelButtonActionPerformed(evt);
      }
    });

    javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
    jPanel3.setLayout(jPanel3Layout);
    jPanel3Layout.setHorizontalGroup(
      jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
          .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
          .addComponent(okButton)
          .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
          .addComponent(cancelButton)
          .addContainerGap())
    );
    jPanel3Layout.setVerticalGroup(
      jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
          .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
          .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
            .addComponent(okButton)
            .addComponent(cancelButton))
          .addContainerGap())
    );

    jPanel2.add(jPanel3);

    javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
    getContentPane().setLayout(layout);
    layout.setHorizontalGroup(
      layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGap(0, 691, Short.MAX_VALUE)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
          .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
    );
    layout.setVerticalGroup(
      layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
        .addGap(0, 610, Short.MAX_VALUE)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
          .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
    );

    pack();
  }// </editor-fold>//GEN-END:initComponents

  private void browseButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_browseButtonActionPerformed
    File dflt = new File(sketchbookLocationField.getText());
    File file = Base.selectFolder(tr("Select new sketchbook location"), dflt, this);
    if (file != null) {
      String path = file.getAbsolutePath();
      if (BaseNoGui.getPortableFolder() != null) {
        path = FileUtils.relativePath(BaseNoGui.getPortableFolder().toString(), path);
        if (path == null) {
          path = BaseNoGui.getPortableSketchbookFolder();
        }
      }
      sketchbookLocationField.setText(path);
    }
  }//GEN-LAST:event_browseButtonActionPerformed

  private void extendedAdditionalUrlFieldWindowActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_extendedAdditionalUrlFieldWindowActionPerformed
    final AdditionalBoardsManagerURLTextArea additionalBoardsManagerURLTextArea = new AdditionalBoardsManagerURLTextArea(this);
    additionalBoardsManagerURLTextArea.setText(additionalBoardsManagerField.getText());
    additionalBoardsManagerURLTextArea.onOk(e -> additionalBoardsManagerField.setText(additionalBoardsManagerURLTextArea.getText()));
    additionalBoardsManagerURLTextArea.setVisible(true);
  }//GEN-LAST:event_extendedAdditionalUrlFieldWindowActionPerformed

  private void preferencesFileLabelMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_preferencesFileLabelMouseEntered
    preferencesFileLabel.setForeground(new Color(0, 0, 140));
  }//GEN-LAST:event_preferencesFileLabelMouseEntered

  private void preferencesFileLabelMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_preferencesFileLabelMousePressed
    Base.openFolder(PreferencesData.getPreferencesFile().getParentFile());
  }//GEN-LAST:event_preferencesFileLabelMousePressed

  private void preferencesFileLabelMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_preferencesFileLabelMouseExited
    preferencesFileLabel.setForeground(new Color(76, 76, 76));
  }//GEN-LAST:event_preferencesFileLabelMouseExited

  private void cancelButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelButtonActionPerformed
    dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
  }//GEN-LAST:event_cancelButtonActionPerformed

  private void okButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_okButtonActionPerformed
    java.util.List<String> errors = validateData();
    if (!errors.isEmpty()) {
      Base.showWarning(tr("Error"), errors.get(0), null);
      return;
    }

    savePreferencesData();
    base.getEditors().forEach(processing.app.Editor::applyPreferences);
    cancelButtonActionPerformed(evt);
  }//GEN-LAST:event_okButtonActionPerformed

  private void autoProxyItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_autoProxyItemStateChanged
    disableAllProxyFields();
    autoProxyFieldsSetEnabled(autoProxy.isSelected());
  }//GEN-LAST:event_autoProxyItemStateChanged

  private void manualProxyItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_manualProxyItemStateChanged
    disableAllProxyFields();
    manualProxyFieldsSetEnabled(manualProxy.isSelected());
  }//GEN-LAST:event_manualProxyItemStateChanged

  private void autoProxyUsePACItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_autoProxyUsePACItemStateChanged
    autoProxyPACFieldsSetEnabled(autoProxyUsePAC.isSelected());
  }//GEN-LAST:event_autoProxyUsePACItemStateChanged

  // Variables declaration - do not modify//GEN-BEGIN:variables
  private javax.swing.JTextField additionalBoardsManagerField;
  private javax.swing.JRadioButton autoProxy;
  private javax.swing.JTextField autoProxyPACURL;
  private javax.swing.JPasswordField autoProxyPassword;
  private javax.swing.JLabel autoProxyPasswordLabel;
  private javax.swing.JCheckBox autoProxyUsePAC;
  private javax.swing.JTextField autoProxyUsername;
  private javax.swing.JLabel autoProxyUsernameLabel;
  private javax.swing.JCheckBox checkUpdatesBox;
  private javax.swing.JComboBox comboLanguage;
  private javax.swing.JComboBox comboWarnings;
  private javax.swing.JCheckBox displayLineNumbersBox;
  private javax.swing.JCheckBox enableCodeFoldingBox;
  private javax.swing.JCheckBox externalEditorBox;
  private javax.swing.JTextField fontSizeField;
  private javax.swing.JRadioButton manualProxy;
  private javax.swing.JRadioButton manualProxyHTTP;
  private javax.swing.JTextField manualProxyHostName;
  private javax.swing.JLabel manualProxyHostNameLabel;
  private javax.swing.JPasswordField manualProxyPassword;
  private javax.swing.JLabel manualProxyPasswordLabel;
  private javax.swing.JTextField manualProxyPort;
  private javax.swing.JLabel manualProxyPortLabel;
  private javax.swing.JRadioButton manualProxySOCKS;
  private javax.swing.ButtonGroup manualProxyTypeButtonGroup;
  private javax.swing.JTextField manualProxyUsername;
  private javax.swing.JLabel manualProxyUsernameLabel;
  private javax.swing.JRadioButton noProxy;
  private javax.swing.JLabel preferencesFileLabel;
  private javax.swing.ButtonGroup proxyTypeButtonGroup;
  private javax.swing.JCheckBox saveVerifyUploadBox;
  private javax.swing.JTextField sketchbookLocationField;
  private javax.swing.JCheckBox updateExtensionBox;
  private javax.swing.JCheckBox verboseCompilationBox;
  private javax.swing.JCheckBox verboseUploadBox;
  private javax.swing.JCheckBox verifyUploadBox;
  // End of variables declaration//GEN-END:variables

  private java.util.List<String> validateData() {
    java.util.List<String> errors = new LinkedList<>();
    if (FileUtils.isSubDirectory(new File(sketchbookLocationField.getText()), new File(PreferencesData.get("runtime.ide.path")))) {
      errors.add(tr("The specified sketchbook folder contains your copy of the IDE.\nPlease choose a different folder for your sketchbook."));
    }
    return errors;
  }

  private void savePreferencesData() {
    String oldPath = PreferencesData.get("sketchbook.path");
    String newPath = sketchbookLocationField.getText();
    if (newPath.isEmpty()) {
      if (BaseNoGui.getPortableFolder() == null) {
        newPath = base.getDefaultSketchbookFolderOrPromptForIt().toString();
      } else {
        newPath = BaseNoGui.getPortableSketchbookFolder();
      }
    }
    if (!newPath.equals(oldPath)) {
      base.rebuildSketchbookMenus();
      PreferencesData.set("sketchbook.path", newPath);
    }

    Language newLanguage = (Language) comboLanguage.getSelectedItem();
    PreferencesData.set("editor.languages.current", newLanguage.getIsoCode());

    String newSizeText = fontSizeField.getText();
    try {
      int newSize = Integer.parseInt(newSizeText.trim());
      String pieces[] = PApplet.split(PreferencesData.get("editor.font"), ',');
      pieces[2] = String.valueOf(newSize);
      PreferencesData.set("editor.font", PApplet.join(pieces, ','));

    } catch (Exception e) {
      System.err.println(I18n.format(tr("ignoring invalid font size {0}"), newSizeText));
    }

    // put each of the settings into the table
    PreferencesData.setBoolean("build.verbose", verboseCompilationBox.isSelected());
    PreferencesData.setBoolean("upload.verbose", verboseUploadBox.isSelected());

    WarningItem warningItem = (WarningItem) comboWarnings.getSelectedItem();
    PreferencesData.set("compiler.warning_level", warningItem.getValue());

    PreferencesData.setBoolean("editor.linenumbers", displayLineNumbersBox.isSelected());

    PreferencesData.setBoolean("editor.code_folding", enableCodeFoldingBox.isSelected());

    PreferencesData.setBoolean("upload.verify", verifyUploadBox.isSelected());

    PreferencesData.setBoolean("editor.save_on_verify", saveVerifyUploadBox.isSelected());

    PreferencesData.setBoolean("editor.external", externalEditorBox.isSelected());

    PreferencesData.setBoolean("update.check", checkUpdatesBox.isSelected());

    PreferencesData.setBoolean("editor.update_extension", updateExtensionBox.isSelected());

    PreferencesData.setBoolean("editor.save_on_verify", saveVerifyUploadBox.isSelected());

    PreferencesData.set("boardsmanager.additional.urls", additionalBoardsManagerField.getText().replace("\r\n", "\n").replace("\r", "\n").replace("\n", ","));

    PreferencesData.set(Constants.PREF_PROXY_TYPE, proxyTypeButtonGroup.getSelection().getActionCommand());
    PreferencesData.set(Constants.PREF_PROXY_PAC_URL, autoProxyUsePAC.isSelected() ? autoProxyPACURL.getText() : "");
    PreferencesData.set(Constants.PREF_PROXY_MANUAL_TYPE, manualProxyTypeButtonGroup.getSelection().getActionCommand());
    PreferencesData.set(Constants.PREF_PROXY_MANUAL_HOSTNAME, manualProxyHostName.getText());
    PreferencesData.set(Constants.PREF_PROXY_MANUAL_PORT, manualProxyPort.getText());
    PreferencesData.set(Constants.PREF_PROXY_MANUAL_USERNAME, manualProxyUsername.getText());
    PreferencesData.set(Constants.PREF_PROXY_MANUAL_PASSWORD, String.valueOf(manualProxyPassword.getPassword()));
    PreferencesData.set(Constants.PREF_PROXY_AUTO_USERNAME, autoProxyUsername.getText());
    PreferencesData.set(Constants.PREF_PROXY_AUTO_PASSWORD, String.valueOf(autoProxyPassword.getPassword()));
  }

  private void showPrerefencesData() {
    sketchbookLocationField.setText(PreferencesData.get("sketchbook.path"));

    String currentLanguageISOCode = PreferencesData.get("editor.languages.current");
    for (Language language : languages) {
      if (language.getIsoCode().equals(currentLanguageISOCode)) {
        comboLanguage.setSelectedItem(language);
      }
    }

    Font editorFont = PreferencesData.getFont("editor.font");
    fontSizeField.setText(String.valueOf(editorFont.getSize()));

    verboseCompilationBox.setSelected(PreferencesData.getBoolean("build.verbose"));
    verboseUploadBox.setSelected(PreferencesData.getBoolean("upload.verbose"));

    String currentWarningLevel = PreferencesData.get("compiler.warning_level", "none");
    for (WarningItem item : warningItems) {
      if (currentWarningLevel.equals(item.getValue())) {
        comboWarnings.setSelectedItem(item);
      }
    }

    displayLineNumbersBox.setSelected(PreferencesData.getBoolean("editor.linenumbers"));

    enableCodeFoldingBox.setSelected(PreferencesData.getBoolean("editor.code_folding"));

    verifyUploadBox.setSelected(PreferencesData.getBoolean("upload.verify"));

    externalEditorBox.setSelected(PreferencesData.getBoolean("editor.external"));

    checkUpdatesBox.setSelected(PreferencesData.getBoolean("update.check"));

    updateExtensionBox.setSelected(PreferencesData.get("editor.update_extension") == null || PreferencesData.getBoolean("editor.update_extension"));

    saveVerifyUploadBox.setSelected(PreferencesData.getBoolean("editor.save_on_verify"));

    additionalBoardsManagerField.setText(PreferencesData.get("boardsmanager.additional.urls"));

    disableAllProxyFields();
    String proxyType = PreferencesData.get(Constants.PREF_PROXY_TYPE, Constants.PROXY_TYPE_AUTO);

    if (Constants.PROXY_TYPE_NONE.equals(proxyType)) {
      noProxy.setSelected(true);
    } else if (Constants.PROXY_TYPE_AUTO.equals(proxyType)) {
      autoProxy.setSelected(true);
      autoProxyFieldsSetEnabled(true);
      if (!PreferencesData.get(Constants.PREF_PROXY_PAC_URL, "").isEmpty()) {
        autoProxyUsePAC.setSelected(true);
        autoProxyPACURL.setText(PreferencesData.get(Constants.PREF_PROXY_PAC_URL));
        autoProxyUsername.setText(PreferencesData.get(Constants.PREF_PROXY_AUTO_USERNAME));
        autoProxyPassword.setText(PreferencesData.get(Constants.PREF_PROXY_AUTO_PASSWORD));
      }
    } else {
      manualProxy.setSelected(true);
      manualProxyFieldsSetEnabled(true);
      manualProxyHostName.setText(PreferencesData.get(Constants.PREF_PROXY_MANUAL_HOSTNAME));
      manualProxyPort.setText(PreferencesData.get(Constants.PREF_PROXY_MANUAL_PORT));
      manualProxyUsername.setText(PreferencesData.get(Constants.PREF_PROXY_MANUAL_USERNAME));
      manualProxyPassword.setText(PreferencesData.get(Constants.PREF_PROXY_MANUAL_PASSWORD));
    }

    String selectedManualProxyType = PreferencesData.get(Constants.PREF_PROXY_MANUAL_TYPE, Constants.PROXY_MANUAL_TYPE_HTTP);
    manualProxyHTTP.setSelected(Constants.PROXY_MANUAL_TYPE_HTTP.equals(selectedManualProxyType));
    manualProxySOCKS.setSelected(Constants.PROXY_MANUAL_TYPE_SOCKS.equals(selectedManualProxyType));
  }

  private void manualProxyFieldsSetEnabled(boolean enabled) {
    manualProxySOCKS.setEnabled(enabled);
    manualProxyHTTP.setEnabled(enabled);
    manualProxyHostNameLabel.setEnabled(enabled);
    manualProxyHostName.setEnabled(enabled);
    manualProxyPortLabel.setEnabled(enabled);
    manualProxyPort.setEnabled(enabled);
    manualProxyUsernameLabel.setEnabled(enabled);
    manualProxyUsername.setEnabled(enabled);
    manualProxyPasswordLabel.setEnabled(enabled);
    manualProxyPassword.setEnabled(enabled);
  }

  private void autoProxyFieldsSetEnabled(boolean enabled) {
    autoProxyUsePAC.setEnabled(enabled);
    autoProxyPACFieldsSetEnabled(enabled && autoProxyUsePAC.isSelected());
  }

  private void autoProxyPACFieldsSetEnabled(boolean enabled) {
    autoProxyPACURL.setEnabled(enabled);
    autoProxyUsername.setEnabled(enabled);
    autoProxyUsernameLabel.setEnabled(enabled);
    autoProxyPassword.setEnabled(enabled);
    autoProxyPasswordLabel.setEnabled(enabled);
  }

  private void disableAllProxyFields() {
    autoProxyFieldsSetEnabled(false);
    manualProxyFieldsSetEnabled(false);
  }
}
