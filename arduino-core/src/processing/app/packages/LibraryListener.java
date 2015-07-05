package processing.app.packages;

/**
 * Interface to monitor sketck library changes
 * @author Ricardo JL Rufino (ricardo@criativasoft.com.br) 
 */
public interface LibraryListener {
  
  void onInsertLibrary(UserLibrary library);
  
  void onRemoveLibrary(UserLibrary library);
  
  void onClearLibraryList();

}
