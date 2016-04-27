package processing.app.git;

import cc.arduino.view.git.GitDiffForm;
import org.eclipse.jgit.api.Git;
import org.eclipse.jgit.api.errors.GitAPIException;
import org.eclipse.jgit.api.errors.NoHeadException;
import org.eclipse.jgit.diff.DiffEntry;
import org.eclipse.jgit.diff.DiffFormatter;
import org.eclipse.jgit.errors.RepositoryNotFoundException;
import org.eclipse.jgit.lib.Constants;
import org.eclipse.jgit.lib.ObjectReader;
import org.eclipse.jgit.lib.Repository;
import org.eclipse.jgit.revwalk.RevCommit;
import org.eclipse.jgit.revwalk.RevTree;
import org.eclipse.jgit.revwalk.RevWalk;
import org.eclipse.jgit.storage.file.FileRepositoryBuilder;
import org.eclipse.jgit.treewalk.AbstractTreeIterator;
import org.eclipse.jgit.treewalk.CanonicalTreeParser;
import org.eclipse.jgit.treewalk.FileTreeIterator;
import org.eclipse.jgit.treewalk.filter.PathFilter;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.function.Consumer;


public class GitManager {

  public void init(File repoDir) {
    try (Git git = Git.init().setDirectory(repoDir).call()) {
      System.out.println("Having repository: " + git.getRepository().getDirectory());
    } catch (GitAPIException e) {
      e.printStackTrace();
    }
  }

  public void reset(File repoDir, File file) {
    Consumer<Git> resetCommand = git -> {
      try {
        // We need get relative repository path
        git.checkout().addPath(
          getRelativePath(repoDir, file)
        ).call();

        System.out.println("Reset file " + file.getName());
      } catch (GitAPIException e) {
        e.printStackTrace();
      }
    };
    runGitCommand(repoDir, resetCommand);
  }

  private String getRelativePath(File repoDir, File file) {
    Path pathAbsolute = Paths.get(file.getPath());
    Path pathBase = Paths.get(repoDir.getPath());
    Path pathRelative = pathBase.relativize(pathAbsolute);
    return pathRelative.toString();
  }

  public void diff(File repoDir, File file) {
    Consumer<Git> commitCommand = git -> {
      ByteArrayOutputStream outputStream = new ByteArrayOutputStream();

      try (DiffFormatter diffFormatter = new DiffFormatter(outputStream)) {
        diffFormatter.setContext(20);
        diffFormatter.setRepository(git.getRepository());
        diffFormatter.setPathFilter(PathFilter.create(
          getRelativePath(repoDir, file)
        ));

        AbstractTreeIterator commitTreeIterator = prepareTreeParser(git.getRepository(), Constants.HEAD);
        FileTreeIterator workTreeIterator = new FileTreeIterator(git.getRepository());

        List<DiffEntry> diffEntries = diffFormatter.scan(commitTreeIterator, workTreeIterator);
        diffFormatter.format(diffEntries);

        GitOutputParser parser = new GitOutputParser();
        GitOutputParser.ParserResult result = parser.diffParser(new ByteArrayInputStream(outputStream.toByteArray()));

        GitDiffForm gitDiffForm = new GitDiffForm(result);
        gitDiffForm.setVisible(true);

      } catch (IOException e) {
        e.printStackTrace();
      }
    };
    runGitCommand(repoDir, commitCommand);
  }

  private AbstractTreeIterator prepareTreeParser(Repository repository, String objectId) throws IOException {
    // from the commit we can build the tree which allows us to construct the TreeParser
    try (RevWalk walk = new RevWalk(repository)) {
      RevCommit commit = walk.parseCommit(repository.resolve(objectId));
      RevTree tree = walk.parseTree(commit.getTree().getId());

      CanonicalTreeParser oldTreeParser = new CanonicalTreeParser();
      try (ObjectReader oldReader = repository.newObjectReader()) {
        oldTreeParser.reset(oldReader, tree.getId());
      }

      walk.dispose();

      return oldTreeParser;
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
