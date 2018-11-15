/*
  Copyright (c) 2014 Paul Stoffregen <paul@pjrc.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

// adapted from https://community.oracle.com/thread/1479784

package processing.app;

import java.io.IOException;
import java.net.URL;
import java.awt.Desktop;
import java.net.URLEncoder;

import java.util.*;
import java.util.regex.*;

import javax.swing.text.html.HTMLDocument;
import javax.swing.JEditorPane;
import javax.swing.JTextPane;
import javax.swing.SwingUtilities;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.html.HTMLEditorKit;

import cc.arduino.UpdatableBoardsLibsFakeURLsHandler;

public class HTMLTextAreaFIFO extends JTextPane implements DocumentListener {
  private int maxChars;
  private int trimMaxChars;

  private int updateCount; // limit how often we trim the document

  private boolean doTrim;
  private final HTMLEditorKit kit;

  public HTMLTextAreaFIFO(int max) {
    maxChars = max;
    trimMaxChars = max / 2;
    updateCount = 0;
    doTrim = true;
    setContentType("text/html");
    getDocument().addDocumentListener(this);
    setText("");
    kit = new HTMLEditorKit();
    this.addHyperlinkListener(new UpdatableBoardsLibsFakeURLsHandler(Base.INSTANCE));
  }

  public void insertUpdate(DocumentEvent e) {
  }

  public void removeUpdate(DocumentEvent e) {
  }

  public void changedUpdate(DocumentEvent e) {
  }

  public void trimDocument() {
    int len = 0;
    len = getDocument().getLength();
    if (len > trimMaxChars) {
      int n = len - trimMaxChars;
      //System.out.println("trimDocument: remove " + n + " chars");
      try {
        getDocument().remove(0, n);
      } catch (BadLocationException ble) {
      }
    }
  }

  private static List<String> extractUrls(String input) {
    List<String> result = new ArrayList<String>();

    Pattern pattern = Pattern.compile(
        "(http|ftp|https)://([^\\s]+)");

    Matcher matcher = pattern.matcher(input);
    while (matcher.find()) {
        result.add(matcher.group());
    }

    return result;
  }

  static public final String WITH_DELIMITER = "((?<=%1$s)|(?=%1$s))";

  public boolean append(String s) {
    boolean htmlFound = false;
    try {
      HTMLDocument doc = (HTMLDocument) getDocument();

      String strings[] = s.split(String.format(WITH_DELIMITER, "\\r?\\n"));

      for (int l = 0; l < strings.length; l++) {
        String str = strings[l];
        List<String> urls = extractUrls(str);

        if (urls.size() > 0) {

          for (int i = 0; i < urls.size(); i++) {
            if (!((urls.get(i)).contains("</a>"))) {
              str = str.replace(urls.get(i), "<a href='" + urls.get(i) + "'>" + urls.get(i) + "</a>");
            }
          }

          kit.insertHTML(doc, doc.getLength(), str, 0, 0, null);
          htmlFound = true;
        } else {
          doc.insertString(doc.getLength(), str, null);
        }
      }
    } catch(BadLocationException exc) {
        exc.printStackTrace();
    } catch(IOException exc) {
        exc.printStackTrace();
    }

    if (++updateCount > 150 && doTrim) {
      updateCount = 0;
      SwingUtilities.invokeLater(new Runnable() {
        public void run() {
          trimDocument();
        }
      });
    }
    return htmlFound;
  }

  public void appendNoTrim(String s) {
    int free = maxChars - getDocument().getLength();
    if (free <= 0)
      return;
    if (s.length() > free)
      append(s.substring(0, free));
    else
      append(s);
    doTrim = false;
  }

  public void appendTrim(String str) {
    append(str);
    doTrim = true;
  }
}
