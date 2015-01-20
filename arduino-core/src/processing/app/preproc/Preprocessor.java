package processing.app.preproc;

import processing.app.helpers.PreferencesMap;

import java.util.Map;

public interface Preprocessor {

  void preprocess(Map<String, Object> context, PreferencesMap dict) throws Exception;

}
