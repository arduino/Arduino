package processing.app.preproc;

import java.util.Map;

public class DumpContext implements PreprocessorChainRing {
  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    System.out.println(context);
  }
}
