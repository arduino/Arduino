package cc.arduino.contributions;

import cc.arduino.utils.Progress;

public class ConsoleProgressListener implements ProgressListener {
  private String lastStatus = "";

  @Override
  public void onProgress(Progress progress) {
    if (!lastStatus.equals(progress.getStatus())) {
      System.out.println(progress.getStatus());
    }
    lastStatus = progress.getStatus();
  }
}
