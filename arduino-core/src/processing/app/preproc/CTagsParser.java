package processing.app.preproc;

import java.util.*;

public class CTagsParser {

  private static final List<String> KNOWN_TAG_KINDS = Arrays.asList("prototype", "function");

  public List<String> parse(String ctagsOutput) {
    String[] rows = ctagsOutput.split("\n");

    List<Map<String, String>> tags = new LinkedList<Map<String, String>>();

    for (String row : rows) {
      Map<String, String> tag = new HashMap<String, String>();
      String[] columns = row.split("\t");
      tag.put("functionName", columns[0]);

      tag.put("kind", columns[columns.length - 3]);
      tag.put("signature", columns[columns.length - 2]);
      tag.put("returntype", columns[columns.length - 1]);
      /*
      if (columns[columns.length - 2].startsWith("signature")) {
        tag.put("kind", columns[columns.length - 3]);
        tag.put("signature", columns[columns.length - 2]);
        tag.put("returntype", columns[columns.length - 1]);
      } else {
        tag.put("kind", columns[columns.length - 2]);
        tag.put("signature", "signature:()");
        tag.put("returntype", columns[columns.length - 1]);
      }
      */
      tag.put("code", row.substring(row.indexOf("/^") + 2, row.indexOf("/;")).trim());
      tags.add(tag);
    }

    filterOutUnknownTags(tags);
    cleanReturnType(tags);
    cleanSignature(tags);
    removeDefinedProtypes(tags);
    addPrototypes(tags);

    List<String> prototypes = new LinkedList<String>();
    for (Map<String, String> tag : tags) {
      prototypes.add(tag.get("prototype"));
    }
    return prototypes;
  }

  private void filterOutUnknownTags(List<Map<String, String>> tags) {
    List<Map<String, String>> tagsToRemove = new LinkedList<Map<String, String>>();
    for (Map<String, String> tag : tags) {
      if (!KNOWN_TAG_KINDS.contains(tag.get("kind"))) {
        tagsToRemove.add(tag);
      }
    }
    tags.removeAll(tagsToRemove);
  }

  private void addPrototypes(List<Map<String, String>> tags) {
    for (Map<String, String> tag : tags) {
      if (tag.get("returntype").startsWith("template") || tag.get("code").startsWith("template")) {
        String code = tag.get("code");
        if (code.contains("{")) {
          code = code.substring(0, code.indexOf("{"));
        } else {
          code = code.substring(0, code.lastIndexOf(")") + 1);
        }
        tag.put("prototype", code.trim() + ";");
      } else {
        tag.put("prototype", tag.get("returntype") + " " + tag.get("functionName") + tag.get("signature") + ";");
      }
    }
  }

  private void removeDefinedProtypes(List<Map<String, String>> tags) {
    List<Map<String, String>> tagsToRemove = new LinkedList<Map<String, String>>();
    for (Map<String, String> tag : tags) {
      if ("prototype".equals(tag.get("kind"))) {
        tagsToRemove.add(tag);
        tagsToRemove.add(findFunctionByName(tags, tag.get("functionName")));
      }
    }
    tags.removeAll(tagsToRemove);
  }

  private Map<String, String> findFunctionByName(List<Map<String, String>> tags, String functionName) {
    for (Map<String, String> tag : tags) {
      if ("function".equals(tag.get("kind")) && functionName.equals(tag.get("functionName"))) {
        return tag;
      }
    }
    return new HashMap<String, String>();
  }

  private void cleanSignature(List<Map<String, String>> tags) {
    for (Map<String, String> tag : tags) {
      tag.put("signature", tag.get("signature").replaceAll("signature:", ""));
    }
  }

  private void cleanReturnType(List<Map<String, String>> tags) {
    for (Map<String, String> tag : tags) {
      String returntype = tag.get("returntype");
      returntype = returntype.replaceAll("returntype:", "");
      String[] types = returntype.split(" ");
      returntype = types[types.length - 1];

      tag.put("returntype", returntype);
    }
  }

}
