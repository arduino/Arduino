package cc.arduino.autocomplete;

import java.util.ArrayList;
import java.util.List;

public class ArduinoCompletionsList extends ArrayList<ArduinoCompletion> {
}

class ArduinoCompletion {
  ArduinoCompletionDetail completion;
  String type;
  String location;
  List<ArduinoParameter> parameters;

  public ArduinoCompletionDetail getCompletion() {
    return completion;
  }

  public String getType() {
    return type;
  }

  public String getLocation() {
    return location;
  }

  public List<ArduinoParameter> getParameters() {
    return parameters;
  }
}

class ArduinoParameter {
  String name;
  String type;

  public String getName() {
    return name;
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

  public String getResultType() {
    for (CompletionChunk c : chunks) {
      if (c.res != null)
        return c.res;
    }
    return null;
  }

  public String getTypedText() {
    for (CompletionChunk c : chunks) {
      if (c.typedtext != null)
        return c.typedtext;
    }
    return null;
  }
}

class CompletionChunk {
  String typedtext;
  String t;
  String placeholder;
  String res;
  String info;
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

  public String getInfo() {
    return info;
  }
}