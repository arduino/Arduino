package processing.app.helpers;

import static processing.app.I18n.tr;

public class BasicUserNotifier extends UserNotifier {

  /**
   * Show an error message that's actually fatal to the program.
   * This is an error that can't be recovered. Use showWarning()
   * for errors that allow P5 to continue running.
   */
  @Override
  public void showError(String title, String message, Throwable e, int exit_code) {
    if (title == null) title = tr("Error");

    System.err.println(title + ": " + message);

    if (e != null) e.printStackTrace();
    System.exit(exit_code);
  }

  @Override
  public void showMessage(String title, String message) {
    if (title == null) title = tr("Message");

    System.out.println(title + ": " + message);
  }

  /**
   * Non-fatal error message with optional stack trace side dish.
   */
  @Override
  public void showWarning(String title, String message, Exception e) {
    if (title == null) title = tr("Warning");

    System.out.println(title + ": " + message);

    if (e != null) e.printStackTrace();
  }

}
