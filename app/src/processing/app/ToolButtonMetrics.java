package processing.app;

public interface ToolButtonMetrics {
  
  static enum ButtonID {
    NONE, RUN, EXPORT, NEW, OPEN, SAVE, SERIAL
  };

  static enum State {
    INACTIVE, ROLLOVER, ACTIVE
  };

  static final int StateCOUNT = 3;

  static final int ButtonWIDTH = 27; // pixels
  static final int ButtonHEIGHT = 32; // pixels
  static final int ButtonGAP = 8; // pixels
  static final int ButtonImageHW = 33; // pixels

  static final boolean RightJUSTIFIED = true;

}
