/**
 * This file courtesy of Rob Camick
 * <p>
 * https://tips4java.wordpress.com/2008/11/08/message-console/
 * <p>
 * About page at https://tips4java.wordpress.com/about/ says something
 * like MIT
 */

package cc.arduino;

import javax.swing.*;
import javax.swing.event.DocumentListener;
import javax.swing.text.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/*
 *  Create a simple console to display text messages.
 *
 *  Messages can be directed here from different sources. Each source can
 *  have its messages displayed in a different color.
 *
 *  You can limit the number of lines to hold in the Document.
 */
public class MessageConsole {

  private final JTextComponent textComponent;
  private final JScrollPane scrollPane;
  private final Document document;
  private DocumentListener limitLinesListener;

  /*
   *	Use the text component specified as a simply console to display
   *  text messages.
   */
  public MessageConsole(JTextComponent textComponent, JScrollPane scrollPane) {
    this.textComponent = textComponent;
    this.scrollPane = scrollPane;
    this.document = textComponent.getDocument();
    this.textComponent.setEditable(false);
    DefaultCaret caret = (DefaultCaret) this.textComponent.getCaret();
    caret.setUpdatePolicy(DefaultCaret.NEVER_UPDATE);
  }

  /*
   *  Redirect the output from the standard output to the console
   *  using the default text color and null PrintStream
   */
  public void redirectOut() {
    redirectOut(null, null);
  }

  /*
   *  Redirect the output from the standard output to the console
   *  using the specified color and PrintStream. When a PrintStream
   *  is specified the message will be added to the Document before
   *  it is also written to the PrintStream.
   */
  public void redirectOut(SimpleAttributeSet style, PrintStream printStream) {
    ConsoleOutputStream cos = new ConsoleOutputStream(style, printStream);
    System.setOut(new PrintStream(cos, true));
  }

  /*
   *  Redirect the output from the standard error to the console
   *  using the default text color and null PrintStream
   */
  public void redirectErr() {
    redirectErr(null, null);
  }

  /*
   *  Redirect the output from the standard error to the console
   *  using the specified color and PrintStream. When a PrintStream
   *  is specified the message will be added to the Document before
   *  it is also written to the PrintStream.
   */
  public void redirectErr(SimpleAttributeSet style, PrintStream printStream) {
    ConsoleOutputStream cos = new ConsoleOutputStream(style, printStream);
    System.setErr(new PrintStream(cos, true));
  }

  /*
   *  To prevent memory from being used up you can control the number of
   *  lines to display in the console
   *
   *  This number can be dynamically changed, but the console will only
   *  be updated the next time the Document is updated.
   */
  public void setMessageLines(int lines) {
    if (limitLinesListener != null) {
      document.removeDocumentListener(limitLinesListener);
    }

    limitLinesListener = new LimitLinesDocumentListener(lines, true);
    document.addDocumentListener(limitLinesListener);
  }

  /*
   *	Class to intercept output from a PrintStream and add it to a Document.
   *  The output can optionally be redirected to a different PrintStream.
   *  The text displayed in the Document can be color coded to indicate
   *  the output source.
   */
  class ConsoleOutputStream extends ByteArrayOutputStream {

    private SimpleAttributeSet attributes;
    private final PrintStream printStream;
    private final StringBuffer buffer = new StringBuffer(1000);
    private boolean isFirstLine;

    /*
         *  Specify the option text color and PrintStream
         */
    public ConsoleOutputStream(SimpleAttributeSet attributes, PrintStream printStream) {
      this.attributes = attributes;
      this.printStream = printStream;
      this.isFirstLine = true;
    }

    /*
     *  Override this method to intercept the output text. Each line of text
     *  output will actually involve invoking this method twice:
     *
     *  a) for the actual text message
     *  b) for the newLine string
     *
     *  The message will be treated differently depending on whether the line
     *  will be appended or inserted into the Document
     */
    public void flush() {
      String message = toString();

      if (message.length() == 0) {
        return;
      }

      handleAppend(message);

      reset();
    }

    /*
     *	We don't want to have blank lines in the Document. The first line
     *  added will simply be the message. For additional lines it will be:
     *
     *  newLine + message
     */
    private void handleAppend(String message) {
      //  This check is needed in case the text in the Document has been
      //	cleared. The buffer may contain the EOL string from the previous
      //  message.

      if (document.getLength() == 0) {
        buffer.setLength(0);
      }

      buffer.append(message);
      clearBuffer();
    }

    /*
     *  The message and the newLine have been added to the buffer in the
     *  appropriate order so we can now update the Document and send the
     *  text to the optional PrintStream.
     */
    private void clearBuffer() {
      //  In case both the standard out and standard err are being redirected
      //  we need to insert a newline character for the first line only

      synchronized (document) {
        if (isFirstLine && document.getLength() != 0) {
          buffer.insert(0, "\n");
        }

        isFirstLine = false;
        String line = buffer.toString();

        int offset = document.getLength();
        SwingUtilities.invokeLater(() -> {
          try {
            document.insertString(offset, line, attributes);
          } catch (BadLocationException ble) {
            //ignore
          }
        });

        Timer timer = new Timer(200, (e) -> {
          scrollPane.getHorizontalScrollBar().setValue(0);
          scrollPane.getVerticalScrollBar().setValue(scrollPane.getVerticalScrollBar().getMaximum());
        });
        timer.setRepeats(false);
        timer.start();

        if (printStream != null) {
          printStream.print(line);
        }

        buffer.setLength(0);
      }
    }
  }
}
