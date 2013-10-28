package processing.app.debug;

import java.io.*;
import java.util.*;

import processing.app.*;

public class Sizer implements MessageConsumer {
  private String buildPath, sketchName;
  private String firstLine;
  private long size;
  private RunnerException exception;

  public Sizer(String buildPath, String sketchName) {
    this.buildPath = buildPath;
    this.sketchName = sketchName;
  }

  public long computeSize() throws RunnerException {
    String userdir = System.getProperty("user.dir") + File.separator;
    String avrBasePath;
    if(Base.isMacOS()) {
      avrBasePath = new String("Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/");
    }
    else if(Base.isLinux()) {
      avrBasePath = new String("");
    }
    else {
      avrBasePath = new String(userdir + "hardware/tools/avr/bin/");
    }
    String commandSize[] = new String[] {
        avrBasePath + "avr-objdump",
        "-h",
        ""
    };

    commandSize[2] = buildPath + File.separator + sketchName + ".elf";

    try {
      exception = null;
      size = -1;
      firstLine = null;
      Process process = Runtime.getRuntime().exec(commandSize);
      MessageSiphon messageSiphon = new MessageSiphon(process.getInputStream(), this);
      boolean running = true;
      while(running) {
        try {
          process.waitFor();
          if (messageSiphon.getThread() != null) {
            Thread.sleep(100);
          }
          running = false;
        } catch (InterruptedException intExc) { }
      }
    } catch (Exception e) {
      // The default Throwable.toString() never returns null, but apparently
      // some sub-class has overridden it to do so, thus we need to check for
      // it.  See: http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1166589459
      exception = new RunnerException(
                                      (e.toString() == null) ? e.getClass().getName() : e.toString());
    }

    if (exception != null)
      throw exception;

    if (size == -1)
      throw new RunnerException(firstLine);

    return size+1;
  }

  public int data = 0;
  public void message(String s) {
    if (firstLine == null)
      firstLine = s;
    else {
      size+=checkTag(s," .text ");
      data+=checkTag(s," .data ");
      data+=checkTag(s," .bss ");
      //    exception = new RunnerException(e.toString());

    }
  }

  private int checkTag(String s, String tag){
    int size=0;
    int p = s.indexOf(tag);
    if(p != -1){
      s=s.substring(p+6).trim();
      p=s.indexOf(" ");
      if(p != -1)
        size = Integer.parseInt(s.substring(0,p).trim(),16);
    }
    return size;
  }
}