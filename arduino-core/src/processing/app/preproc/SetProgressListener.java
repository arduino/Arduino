package processing.app.preproc;

import processing.app.debug.Compiler;

import java.util.Map;

public class SetProgressListener implements PreprocessorChainRing {
  private final int value;
  private final Compiler.ProgressListener progressListener;

  public SetProgressListener(Compiler.ProgressListener progressListener, int value) {
    this.value = value;
    this.progressListener = progressListener;
  }

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    progressListener.progress(value);
  }
}
