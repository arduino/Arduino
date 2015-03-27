package processing.app.preproc;

import org.junit.Test;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.assertEquals;

public class CTagsParserTest {

  @Test
  public void shouldListPrototypes() throws Exception {
    String ctagsOutput = "server\t/tmp/sketch7210316334309249705.cpp\t/^YunServer server;$/;\"\tkind:variable\tline:31\n" +
            "setup\t/tmp/sketch7210316334309249705.cpp\t/^void setup() {$/;\"\tkind:function\tline:33\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch7210316334309249705.cpp\t/^void loop() {$/;\"\tkind:function\tline:46\tsignature:()\treturntype:void\n" +
            "process\t/tmp/sketch7210316334309249705.cpp\t/^void process(YunClient client);$/;\"\tkind:prototype\tline:61\tsignature:(YunClient client)\treturntype:void\n" +
            "process\t/tmp/sketch7210316334309249705.cpp\t/^void process(YunClient client) {$/;\"\tkind:function\tline:62\tsignature:(YunClient client)\treturntype:void\n" +
            "digitalCommand\t/tmp/sketch7210316334309249705.cpp\t/^void digitalCommand(YunClient client) {$/;\"\tkind:function\tline:82\tsignature:(YunClient client)\treturntype:void\n" +
            "analogCommand\t/tmp/sketch7210316334309249705.cpp\t/^void analogCommand(YunClient client) {$/;\"\tkind:function\tline:110\tsignature:(YunClient client)\treturntype:void\n" +
            "modeCommand\t/tmp/sketch7210316334309249705.cpp\t/^void modeCommand(YunClient client) {$/;\"\tkind:function\tline:151\tsignature:(YunClient client)\treturntype:void\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(5, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("void digitalCommand(YunClient client);", prototypes.get(2));
    assertEquals("void analogCommand(YunClient client);", prototypes.get(3));
    assertEquals("void modeCommand(YunClient client);", prototypes.get(4));
  }

  @Test
  public void shouldListTemplates() throws Exception {
    String ctagsOutput = "minimum\t/tmp/sketch8398023134925534708.cpp\t/^template <typename T> T minimum (T a, T b) $/;\"\tkind:function\tline:2\tsignature:(T a, T b)\treturntype:templateT\n" +
            "setup\t/tmp/sketch8398023134925534708.cpp\t/^void setup () $/;\"\tkind:function\tline:9\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch8398023134925534708.cpp\t/^void loop () { }$/;\"\tkind:function\tline:13\tsignature:()\treturntype:void\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(3, prototypes.size());
    assertEquals("template <typename T> T minimum (T a, T b);", prototypes.get(0));
    assertEquals("void setup();", prototypes.get(1));
    assertEquals("void loop();", prototypes.get(2));
  }

  @Test
  public void shouldListTemplates2() throws Exception {
    String ctagsOutput = "setup\t/tmp/sketch463160524247569568.cpp\t/^void setup() {$/;\"\tkind:function\tline:1\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch463160524247569568.cpp\t/^void loop() {$/;\"\tkind:function\tline:6\tsignature:()\treturntype:void\n" +
            "SRAM_writeAnything\t/tmp/sketch463160524247569568.cpp\t/^template <class T> int SRAM_writeAnything(int ee, const T& value)$/;\"\tkind:function\tline:11\tsignature:(int ee, const T& value)\treturntype:template int\n" +
            "SRAM_readAnything\t/tmp/sketch463160524247569568.cpp\t/^template <class T> int SRAM_readAnything(int ee, T& value)$/;\"\tkind:function\tline:21\tsignature:(int ee, T& value)\treturntype:template int\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(4, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("template <class T> int SRAM_writeAnything(int ee, const T& value);", prototypes.get(2));
    assertEquals("template <class T> int SRAM_readAnything(int ee, T& value);", prototypes.get(3));
  }

  @Test
  public void shouldDealWithClasses() throws Exception {
    String ctagsOutput = "SleepCycle\t/tmp/sketch9043227824785312266.cpp\t/^        SleepCycle( const char* name );$/;\"\tkind:prototype\tline:4\tsignature:( const char* name )\n" +
            "SleepCycle\t/tmp/sketch9043227824785312266.cpp\t/^    SleepCycle::SleepCycle( const char* name )$/;\"\tkind:function\tline:8\tsignature:( const char* name )\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(0, prototypes.size());
  }

  @Test
  public void shouldDealWithStructs() throws Exception {
    String ctagsOutput = "A_NEW_TYPE\t/tmp/sketch8930345717354294915.cpp\t/^struct A_NEW_TYPE {$/;\"\tkind:struct\tline:3\n" +
            "foo\t/tmp/sketch8930345717354294915.cpp\t/^} foo;$/;\"\tkind:variable\tline:7\ttyperef:struct:A_NEW_TYPE\n" +
            "setup\t/tmp/sketch8930345717354294915.cpp\t/^void setup() {$/;\"\tkind:function\tline:9\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch8930345717354294915.cpp\t/^void loop() {$/;\"\tkind:function\tline:13\tsignature:()\treturntype:void\n" +
            "dostuff\t/tmp/sketch8930345717354294915.cpp\t/^void dostuff (A_NEW_TYPE * bar)$/;\"\tkind:function\tline:17\tsignature:(A_NEW_TYPE * bar)\treturntype:void\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(3, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("void dostuff(A_NEW_TYPE * bar);", prototypes.get(2));
  }

  @Test
  public void shouldDealWithMacros() throws Exception {
    String ctagsOutput = "DEBUG\t/tmp/sketch5976699731718729500.cpp\t1;\"\tkind:macro\tline:1\n" +
            "DISABLED\t/tmp/sketch5976699731718729500.cpp\t2;\"\tkind:macro\tline:2\n" +
            "hello\t/tmp/sketch5976699731718729500.cpp\t/^String hello = \"world!\";$/;\"\tkind:variable\tline:16\n" +
            "setup\t/tmp/sketch5976699731718729500.cpp\t/^void setup() {$/;\"\tkind:function\tline:18\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch5976699731718729500.cpp\t/^void loop() {$/;\"\tkind:function\tline:23\tsignature:()\treturntype:void\n" +
            "debug\t/tmp/sketch5976699731718729500.cpp\t/^void debug() {$/;\"\tkind:function\tline:35\tsignature:()\treturntype:void\n" +
            "disabledIsDefined\t/tmp/sketch5976699731718729500.cpp\t/^void disabledIsDefined() {$/;\"\tkind:function\tline:46\tsignature:()\treturntype:void\n" +
            "useMyType\t/tmp/sketch5976699731718729500.cpp\t/^int useMyType(MyType type) {$/;\"\tkind:function\tline:50\tsignature:(MyType type)\treturntype:int\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(5, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("void debug();", prototypes.get(2));
    assertEquals("void disabledIsDefined();", prototypes.get(3));
    assertEquals("int useMyType(MyType type);", prototypes.get(4));

    assertEquals(18, context.get("firstFunctionAtLine"));
  }


  @Test
  public void shouldRemoveDefaultArgsValues() throws Exception {
    String ctagsOutput = "setup\t/tmp/sketch3020016532877959639.cpp\t/^void setup() {$/;\"\tkind:function\tline:2\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch3020016532877959639.cpp\t/^void loop() {$/;\"\tkind:function\tline:7\tsignature:()\treturntype:void\n" +
            "program\t/tmp/sketch3020016532877959639.cpp\t/^byte program (const byte b1, const byte b2 = 0, const byte b3 = 0, const byte b4 = 0)$/;\"\tkind:function\tline:12\tsignature:(const byte b1, const byte b2 = 0, const byte b3 = 0, const byte b4 = 0)\treturntype:byte\n";

    Map<String, Object> context = new HashMap<String, Object>();
    context.put("ctagsOutput", ctagsOutput);
    new CTagsParser().preprocess(context);
    List<String> prototypes = (List<String>) context.get("prototypes");

    assertEquals(3, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("byte program(const byte b1, const byte b2, const byte b3, const byte b4);", prototypes.get(2));
  }

}
