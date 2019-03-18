package processing.app;

import java.util.ArrayList;
import java.util.List;

/**
 * Keeps track of command history in console-like applications.
 * @author P.J.S. Kools
 */
public class CommandHistory {

  private List<String> commandHistory = new ArrayList<String>();
  private int selectedCommandIndex = 0;
  private final int maxHistorySize;

  /**
   * Create a new {@link CommandHistory}.
   * @param maxHistorySize - The max command history size.
   */
  public CommandHistory(int maxHistorySize) {
    this.maxHistorySize = (maxHistorySize < 0 ? 0 : maxHistorySize);
    this.commandHistory.add(""); // Current command placeholder.
  }

  /**
   * Adds the given command to the history and resets the history traversal
   * position to the latest command. If the max history size is exceeded,
   * the oldest command will be removed from the history.
   * @param command - The command to add.
   */
  public void addCommand(String command) {

    // Remove the oldest command if the max history size is exceeded.
    if(this.commandHistory.size() >= this.maxHistorySize + 1) {
      this.commandHistory.remove(0);
    }

    // Add the new command, reset the 'current' command and reset the index.
    this.commandHistory.set(this.commandHistory.size() - 1, command);
    this.commandHistory.add(""); // Current command placeholder.
    this.selectedCommandIndex = this.commandHistory.size() - 1;
  }

  /**
   * Gets whether a next (more recent) command is available in the history.
   * @return {@code true} if a next command is available,
   * returns {@code false} otherwise.
   */
  public boolean hasNextCommand() {
    return this.selectedCommandIndex + 1 < this.commandHistory.size();
  }

  /**
   * Gets the next (more recent) command from the history.
   * @return The next command or {@code null} if no next command is available.
   */
  public String getNextCommand() {
    return this.hasNextCommand()
        ? this.commandHistory.get(++this.selectedCommandIndex) : null;
  }

  /**
   * Gets whether a previous (older) command is available in the history.
   * @return {@code true} if a previous command is available,
   * returns {@code false} otherwise.
   */
  public boolean hasPreviousCommand() {
    return this.selectedCommandIndex > 0;
  }

  /**
   * Gets the previous (older) command from the history.
   * When this method is called while the most recent command in the history is
   * selected, this will store the current command as temporary latest command
   * so that {@link #getNextCommand()} will return it. This temporary latest
   * command gets reset when this case occurs again or when
   * {@link #addCommand(String)} is invoked.
   * @param currentCommand - The current unexecuted command.
   * @return The previous command or {@code null} if no previous command is
   * available.
   */
  public String getPreviousCommand(String currentCommand) {

    // Return null if there is no previous command available.
    if (!this.hasPreviousCommand()) {
      return null;
    }

    // Store current unexecuted command if not traversing already.
    if (this.selectedCommandIndex == this.commandHistory.size() - 1) {
      this.commandHistory.set(this.commandHistory.size() - 1,
          (currentCommand == null ? "" : currentCommand));
    }

    // Return the previous command.
    return this.commandHistory.get(--this.selectedCommandIndex);
  }

  /**
   * Resets the history location to the most recent command.
   * @returns The latest unexecuted command as stored by
   * {@link #getPreviousCommand(String)} or an empty string if no such command
   * was set.
   */
  public String resetHistoryLocation() {
    this.selectedCommandIndex = this.commandHistory.size() - 1;
    return this.commandHistory.set(this.commandHistory.size() - 1, "");
  }

  /**
   * Clears the command history.
   */
  public void clear() {
    this.commandHistory.clear();
    this.commandHistory.add(""); // Current command placeholder.
    this.selectedCommandIndex = 0;
  }
}
