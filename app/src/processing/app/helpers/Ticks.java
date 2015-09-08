package processing.app.helpers;

public class Ticks {

  private final int tickCount;
  private final double[] ticks;
  private double tickMin;
  private double tickMax;
  private double tickStep;

  public Ticks(double min, double max, int tickCount) {
    double range = max - min;
    double exp;
    if (range == 0.0) {
      exp = 0;
    } else {
      exp = Math.floor(Math.log10(range / (tickCount - 1)));
    }
    double scale = Math.pow(10, exp);

    double rawTickStep = (range / (tickCount - 1)) / scale;
    for (double potentialStep : new double[]{1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0}) {
      if (potentialStep < rawTickStep) {
        continue;
      }

      tickStep = potentialStep * scale;
      tickMin = tickStep * Math.floor(min / tickStep);
      tickMax = tickMin + tickStep * (tickCount - 1);
      if (tickMax >= max) {
        break;
      }
    }

    tickCount -= (int) Math.floor((tickMax - max) / tickStep);
    this.tickCount = tickCount;

    ticks = new double[tickCount];
    for (int i = 0; i < tickCount; ++i) {
      ticks[i] = tickMin + i * tickStep;
    }
  }

  public double getTick(int i) {
    return ticks[i];
  }

  public int getTickCount() {
    return tickCount;
  }
}
