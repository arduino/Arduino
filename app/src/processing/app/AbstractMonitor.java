package processing.app;

import cc.arduino.packages.BoardPort;
import processing.app.legacy.PApplet;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
public abstract class AbstractMonitor extends JFrame implements ActionListener {

  private boolean closed;

  private StringBuffer updateBuffer;
  private Timer updateTimer;

  private BoardPort boardPort;

  protected String[] serialRateStrings = {"300", "1200", "2400", "4800", "9600", "19200", "38400", "57600", "74880", "115200", "230400", "250000"};

  public AbstractMonitor(BoardPort boardPort) {
    super(boardPort.getLabel());
    this.boardPort = boardPort;

    addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent event) {
        try {
          closed = true;
          close();
        } catch (Exception e) {
          // ignore
        }
      }
    });

    // obvious, no?
    KeyStroke wc = Editor.WINDOW_CLOSE_KEYSTROKE;
    getRootPane().getInputMap(JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT).put(wc, "close");
    getRootPane().getActionMap().put("close", (new AbstractAction() {
      public void actionPerformed(ActionEvent event) {
        try {
          close();
        } catch (Exception e) {
          // ignore
        }
        setVisible(false);
      }
    }));


    onCreateWindow(getContentPane());

    this.setMinimumSize(new Dimension(getContentPane().getMinimumSize().width, this.getPreferredSize().height));

    pack();

    Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
    if (PreferencesData.get("last.screen.height") != null) {
      // if screen size has changed, the window coordinates no longer
      // make sense, so don't use them unless they're identical
      int screenW = PreferencesData.getInteger("last.screen.width");
      int screenH = PreferencesData.getInteger("last.screen.height");
      if ((screen.width == screenW) && (screen.height == screenH)) {
        String locationStr = PreferencesData.get("last.serial.location");
        if (locationStr != null) {
          int[] location = PApplet.parseInt(PApplet.split(locationStr, ','));
          setPlacement(location);
        }
      }
    }

    updateBuffer = new StringBuffer(1048576);
    updateTimer = new Timer(33, this);  // redraw serial monitor at 30 Hz
    updateTimer.start();

    closed = false;
  }

  protected abstract void onCreateWindow(Container mainPane);

  public void enableWindow(boolean enable) {
    onEnableWindow(enable);
  }

  protected abstract void onEnableWindow(boolean enable);

  // Puts the window in suspend state, closing the serial port
  // to allow other entity (the programmer) to use it
  public void suspend() throws Exception {
    enableWindow(false);

    close();
  }

  public void resume(BoardPort boardPort) throws Exception {
    setBoardPort(boardPort);

    // Enable the window
    enableWindow(true);

    // If the window is visible, try to open the serial port
    if (!isVisible()) {
      return;
    }

    open();
  }

  protected void setPlacement(int[] location) {
    setBounds(location[0], location[1], location[2], location[3]);
  }

  protected int[] getPlacement() {
    int[] location = new int[4];

    // Get the dimensions of the Frame
    Rectangle bounds = getBounds();
    location[0] = bounds.x;
    location[1] = bounds.y;
    location[2] = bounds.width;
    location[3] = bounds.height;

    return location;
  }

  public abstract void message(final String s);

  public boolean requiresAuthorization() {
    return false;
  }

  public String getAuthorizationKey() {
    return null;
  }

  public boolean isClosed() {
    return closed;
  }

  public void open() throws Exception {
    closed = false;
  }

  public void close() throws Exception {
    closed = true;
  }

  public BoardPort getBoardPort() {
    return boardPort;
  }

  public void setBoardPort(BoardPort boardPort) {
    if (boardPort == null) {
      return;
    }
    setTitle(boardPort.getLabel());
    this.boardPort = boardPort;
  }

  public synchronized void addToUpdateBuffer(char buff[], int n) {
    updateBuffer.append(buff, 0, n);
  }

  private synchronized String consumeUpdateBuffer() {
    String s = updateBuffer.toString();
    updateBuffer.setLength(0);
    return s;
  }

  public void actionPerformed(ActionEvent e) {
    String s = consumeUpdateBuffer();
    if (s.isEmpty()) {
      return;
    } else {
      message(s);
    }
  }
}
