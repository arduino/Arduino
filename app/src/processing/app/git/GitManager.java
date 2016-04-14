package processing.app.git;

import org.eclipse.jgit.api.Git;
import org.eclipse.jgit.api.errors.GitAPIException;
import org.eclipse.jgit.api.errors.NoHeadException;
import org.eclipse.jgit.errors.RepositoryNotFoundException;
import org.eclipse.jgit.lib.Repository;
import org.eclipse.jgit.revwalk.RevCommit;
import org.eclipse.jgit.storage.file.FileRepositoryBuilder;

import java.io.File;
import java.io.IOException;
import java.util.function.Consumer;


public class GitManager {

  public void init(File repoDir) {
    try (Git git = Git.init().setDirectory(repoDir).call()) {
      System.out.println("Having repository: " + git.getRepository().getDirectory());
    } catch (GitAPIException e) {
      e.printStackTrace();
    }
  }

  public void commit(File repoDir, String message) {
    if (!commitMessageIsValid(message)) {
      System.err.println("Commit message isn't valid.");
      return;
    }

    File[] files = repoDir.listFiles();

    Consumer<Git> commitCommand = git -> {
      try {
        addFiles(files, git);
        commit(message, git);
        System.out.printf("Committed file to repository at: %s%n", git.getRepository().getDirectory());
      } catch (GitAPIException e) {
        e.printStackTrace();
      }
    };

    runGitCommand(repoDir, commitCommand);
  }

  public void log(File repoDir) {

    Consumer<Git> logCommand = git -> {
      try {
        Iterable<RevCommit> logs = git.log()
          .call();

        int count = 0;
        for (RevCommit rev : logs) {
          System.out.printf("Commit: %s, name: %s%n", rev, rev.getName());
          count++;
        }

        System.out.printf("Had %d commits overall on current branch%n", count);

      } catch (NoHeadException e) {
        System.err.printf("Repository %s is empty. Try to commit something.%n", git.getRepository().getDirectory());
      } catch (GitAPIException e) {
        e.printStackTrace();
      }
    };

    runGitCommand(repoDir, logCommand);
  }

  private boolean commitMessageIsValid(String message) {
    return !message.trim().isEmpty();
  }

  private void addFiles(File[] files, Git git) throws GitAPIException {
    for (File file : files) {
      git.add()
        .addFilepattern(file.getName())
        .call();
    }
  }

  private void commit(String message, Git git) throws GitAPIException {
    git.commit()
      .setMessage(message)
      .call();
  }

  private void runGitCommand(File repoDir, Consumer<Git> command) {
    File gitDir = new File(repoDir, ".git");
    if (gitDir.exists()) {
      repoDir = gitDir;
    }

    FileRepositoryBuilder builder = new FileRepositoryBuilder();
    try (Repository repository = builder.setGitDir(repoDir)
      .readEnvironment() // scan environment GIT_* variables
      .findGitDir(repoDir) // scan up the file system tree
      .setMustExist(true)
      .build()) {

      try (Git git = new Git(repository)) {
        command.accept(git);
      }

    } catch (RepositoryNotFoundException e) {
      System.err.printf("Repository not found: %s. Try create git repository.%n", repoDir);
    } catch (IOException e) {
      e.printStackTrace();
    }

  }

}
