package processing.app.preproc;

import java.util.*;

public class CTagsParser implements PreprocessorChainRing {

  private static final List<String> FIELDS = Arrays.asList("kind", "line", "typeref", "signature", "returntype");
  private static final List<String> KNOWN_TAG_KINDS = Arrays.asList("prototype", "function");

  @Override
  public void preprocess(Map<String, Object> context) throws Exception {
    List<String> rows = Arrays.asList(context.get("ctagsOutput").toString().split("\n"));

    rows = removeEmptyRows(rows);

    List<Map<String, String>> tags = new LinkedList<Map<String, String>>();

    for (String row : rows) {
      Map<String, String> tag = new HashMap<String, String>();
      String[] columns = row.split("\t");
      tag.put("functionName", columns[0]);

      for (int i = 1; i < columns.length; i++) {
        if (columns[i].contains(":") && FIELDS.contains(columns[i].substring(0, columns[i].indexOf(":")))) {
          tag.put(columns[i].substring(0, columns[i].indexOf(":")), columns[i].substring(columns[i].indexOf(":") + 1).trim());
        }
      }
      if (row.contains("/^") && row.contains("/;")) {
        tag.put("code", row.substring(row.indexOf("/^") + 2, row.indexOf("/;")).trim());
      }
      tags.add(tag);
    }

    filterOutUnknownTags(tags);
    removeDefinedProtypes(tags);
    addPrototypes(tags);

    if (!tags.isEmpty()) {
      context.put("firstFunctionAtLine", Integer.valueOf(tags.get(0).get("line")));
    }

    List<String> prototypes = new LinkedList<String>();
    for (Map<String, String> tag : tags) {
      prototypes.add(tag.get("prototype"));
    }
    context.put("prototypes", prototypes);
  }

  private List<String> removeEmptyRows(List<String> rows) {
    List<String> goodRows = new LinkedList<String>();
    for (String row : rows) {
      if (!row.isEmpty()) {
        goodRows.add(row);
      }
    }
    return goodRows;
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

}
