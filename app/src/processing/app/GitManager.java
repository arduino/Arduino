package processing.app;

/**
 * Created by carlos on 1/04/16.
 */

import java.io.IOException;
import java.io.File;
import org.eclipse.jgit.api.*;
import org.eclipse.jgit.api.errors.*;
import org.eclipse.jgit.revwalk.*;


public class GitManager {
  private Git git;

  public String gitInit(File dirUrl)
  {

    try {
      System.out.println(dirUrl.getAbsolutePath());
      git = Git.init().setDirectory( dirUrl ).call();

    } catch (Exception e) {
      return "Something went wrong, check if you have git already installed ";
    }

    return "Git initialized successfully";

  }

  private boolean gitStage(File[] FilesToStage)
  {
    for(File f : FilesToStage)
    {
      try {
        git.add().addFilepattern(f.getName()).call();
      }catch(Exception e){
        return false;
      }

    }
    return true;
  }

  public String gitCommit(String coment, File[] fileToCommit)
  {

    if(gitStage(fileToCommit))
    {
      try{
        git.commit().setMessage( coment ).call();
      }catch(Exception e)
      {
        return "There was a problem while committing the files";
      }
      return "File Committed successfully";
    }
    else
    {
      return "There was a problem while staging the files";
    }
  }

  public Iterable<RevCommit> gitLog()
  {
    Iterable<RevCommit> iterable = null;
    try {

      iterable = git.log().call();

    }catch(GitAPIException ex)
    { }

    return iterable;
  }

}
