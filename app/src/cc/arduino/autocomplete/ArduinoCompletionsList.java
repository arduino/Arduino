package cc.arduino.autocomplete;

import java.util.ArrayList;
import java.util.List;

public class ArduinoCompletionsList extends ArrayList<ArduinoCompletion> {
}

class ArduinoCompletion {
  ArduinoCompletionDetail completion;
  String type;

  public ArduinoCompletionDetail getCompletion() {
    return completion;
  }

  public String getType() {
    return type;
  }
}

class ArduinoCompletionDetail {
  List<CompletionChunk> chunks;
  String brief;

  public List<CompletionChunk> getChunks() {
    return chunks;
  }

  public String getBrief() {
    return brief;
  }
}

class CompletionChunk {
  String typedtext;
  String t;
  String placeholder;
  String res;
  ArduinoCompletionDetail optional;
  
  public String getTypedtext() {
    return typedtext;
  }

  public String getT() {
    return t;
  }

  public String getPlaceholder() {
    return placeholder;
  }

  public String getRes() {
    return res;
  }
  
  public ArduinoCompletionDetail getOptional() {
    return optional;
  }
}