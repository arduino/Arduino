package processing.app;

import java.util.LinkedList;
import java.util.ListIterator;

/**
 * Keeps track of command history in console-like applications.
 * @author P.J.S. Kools
 */
public class CommandHistory {

  private final LinkedList<String> commandHistory = new LinkedList<String>();
  private final int maxHistorySize;
  private ListIterator<String> iterator = null;
  private boolean iteratorAsc;

  /**
   * Create a new {@link CommandHistory}.
   * @param maxHistorySize - The max command history size.
   */
  public CommandHistory(int maxHistorySize) {
    this.maxHistorySize = (maxHistorySize < 0 ? 0 : maxHistorySize);
    this.commandHistory.addLast(""); // Current command placeholder.
  }

  /**
   * Adds the given command to the history and resets the history traversal
   * position to the latest command. If the latest command in the history is
   * equal to the given command, it will not be added to the history.
   * If the max history size is exceeded, the oldest command will be removed
   * from the history.
   * @param command - The command to add.
   */
  public void addCommand(String command) {
    if (this.maxHistorySize == 0) {
      return;
    }

    // Remove 'current' command.
    this.commandHistory.removeLast();

    // Add new command if it differs from the latest command.
    if (this.commandHistory.isEmpty()
        || !this.commandHistory.getLast().equals(command)) {

      // Remove oldest command if max history size is exceeded.
      if (this.commandHistory.size() >= this.maxHistorySize) {
        this.commandHistory.removeFirst();
      }

      // Add new command and reset 'current' command.
      this.commandHistory.addLast(command);
    }

    // Re-add 'current' command and reset command iterator.
    this.commandHistory.addLast(""); // Current command placeholder.
    this.iterator = null;
  }

  /**
   * Gets whether a next (more recent) command is available in the history.
   * @return {@code true} if a next command is available,
   * returns {@code false} otherwise.
   */
  public boolean hasNextCommand() {
    if (this.iterator == null) {
      return false;
    }
    if (!this.iteratorAsc) {
      this.iterator.next(); // Current command, ascending.
      this.iteratorAsc = true;
    }
    return this.iterator.hasNext();
  }

  /**
   * Gets the next (more recent) command from the history.
   * @return The next command or {@code null} if no next command is available.
   */
  public String getNextCommand() {

    // Return null if there is no next command available.
    if (!this.hasNextCommand()) {
      return null;
    }

    // Get next command.
    String next = this.iterator.next();

    // Reset 'current' command when at the end of the list.
    if (this.iterator.nextIndex() == this.commandHistory.size()) {
      this.iterator.set(""); // Reset 'current' command.
    }
    return next;
  }

  /**
   * Gets whether a previous (older) command is available in the history.
   * @return {@code true} if a previous command is available,
   * returns {@code false} otherwise.
   */
  public boolean hasPreviousCommand() {
    if (this.iterator == null) {
      return this.commandHistory.size() > 1;
    }
    if (this.iteratorAsc) {
      this.iterator.previous(); // Current command, descending.
      this.iteratorAsc = false;
    }
    return this.iterator.hasPrevious();
  }

  /**
   * Gets the previous (older) command from the history.
   * When this method is called while the most recent command in the history is
   * selected, this will store the current command as temporary latest command
   * so that {@link #getNextCommand()} will return it once. This temporary
   * latest command gets reset when this case occurs again or when
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

    // Store current unexecuted command and create iterator if not traversing.
    if (this.iterator == null) {
      this.iterator =
          this.commandHistory.listIterator(this.commandHistory.size());
      this.iterator.previous(); // Last element, descending.
      this.iteratorAsc = false;
    }

    // Store current unexecuted command if on 'current' index.
    if (this.iterator.nextIndex() == this.commandHistory.size() - 1) {
      this.iterator.set(currentCommand == null ? "" : currentCommand);
    }

    // Return the previous command.
    return this.iterator.previous();
  }

  /**
   * Resets the history location to the most recent command.
   * @returns The latest unexecuted command as stored by
   * {@link #getPreviousCommand(String)} or an empty string if no such command
   * was set.
   */
  public String resetHistoryLocation() {
    this.iterator = null;
    return this.commandHistory.set(this.commandHistory.size() - 1, "");
  }

  /**
   * Clears the command history.
   */
  public void clear() {
    this.iterator = null;
    this.commandHistory.clear();
    this.commandHistory.addLast(""); // Current command placeholder.
  }
}
