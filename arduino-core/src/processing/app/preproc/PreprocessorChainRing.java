package processing.app.preproc;

import java.util.Map;

public interface PreprocessorChainRing {

  void preprocess(Map<String, Object> context) throws Exception;

}
