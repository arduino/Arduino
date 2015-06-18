package processing.app;

import java.io.OutputStream;
import java.io.PrintStream;

class EditorConsoleStream extends OutputStream {

  private static EditorConsole currentConsole;
  private static PrintStream systemErr;
  private static PrintStream systemOut;

  public static void init() {
    if (systemOut == null) {
      systemOut = System.out;
      systemErr = System.err;

      if (PreferencesData.getBoolean("console")) {
        PrintStream consoleOut = new PrintStream(new EditorConsoleStream(false));
        PrintStream consoleErr = new PrintStream(new EditorConsoleStream(true));

        System.setOut(consoleOut);
        System.setErr(consoleErr);
      }
    }
  }

  private final boolean isStdErr; // whether stderr or stdout
  private final PrintStream system;

  private EditorConsoleStream(boolean isStdErr) {
    this.isStdErr = isStdErr;
    if (this.isStdErr) {
      system = systemErr;
    } else {
      system = systemOut;
    }
  }

  public void close() {
  }

  public void flush() {
  }

  public void write(int b) {
    write(new byte[]{(byte) b});
  }

  public void write(byte b[]) { // appears never to be used
    write(b, 0, b.length);
  }

  public void write(byte b[], int offset, int length) {
    if (currentConsole != null) {
      currentConsole.appendText(new String(b, offset, length), isStdErr);
    }

    system.write(b, offset, length);
  }

  public static void setCurrent(EditorConsole console) {
    currentConsole = console;
  }

}
