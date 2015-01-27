package processing.app.preproc;

import org.junit.Ignore;
import org.junit.Test;

import java.util.List;

import static org.junit.Assert.assertEquals;

public class CTagsParserTest {

  @Test
  public void shouldListPrototypes() {
    String ctagsOutput = "analogCommand\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^void analogCommand(YunClient client) {$/;\"\tfunction\tsignature:(YunClient client)\treturntype:client void\n" +
            "digitalCommand\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^void digitalCommand(YunClient client) {$/;\"\tfunction\tsignature:(YunClient client)\treturntype:client void\n" +
            "loop\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^void loop() {$/;\"\tfunction\tsignature:()\treturntype: void\n" +
            "modeCommand\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^void modeCommand(YunClient client) {$/;\"\tfunction\tsignature:(YunClient client)\treturntype:client void\n" +
            "process\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^\tprocess($/;\"\tfunction\tsignature:( YunClient client )\treturntype:client int\n" +
            "process\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^int process(YunClient client);$/;\"\tprototype\tsignature:(YunClient client)\treturntype:client int\n" +
            "setup\t/home/federico/materiale/works_Arduino/Arduino/libraries/Bridge/examples/Bridge/Bridge.ino\t/^\tsetup($/;\"\tfunction\tsignature:( )\treturntype: void\n";

    List<String> prototypes = new CTagsParser().parse(ctagsOutput);

    assertEquals(5, prototypes.size());
    assertEquals("void analogCommand(YunClient client);", prototypes.get(0));
    assertEquals("void digitalCommand(YunClient client);", prototypes.get(1));
    assertEquals("void loop();", prototypes.get(2));
    assertEquals("void modeCommand(YunClient client);", prototypes.get(3));
    assertEquals("void setup( );", prototypes.get(4));
  }

  @Test
  public void shouldListTemplates() {
    String ctagsOutput = "loop\t/tmp/sketch3773368328959926866.cpp\t/^void loop () { }/;\"\tfunction\tsignature:()\treturntype: void\n" +
            "minimum\t/tmp/sketch3773368328959926866.cpp\t/^template <typename T> T minimum (T a, T b)   {$/;\"\tfunction\tsignature:(T a, T b)\treturntype: templateT\n" +
            "setup\t/tmp/sketch3773368328959926866.cpp\t/^void setup () $/;\"\tfunction\tsignature:()\treturntype: void\n";

    List<String> prototypes = new CTagsParser().parse(ctagsOutput);

    assertEquals(3, prototypes.size());
    assertEquals("void loop();", prototypes.get(0));
    assertEquals("template <typename T> T minimum (T a, T b);", prototypes.get(1));
    assertEquals("void setup();", prototypes.get(2));
  }

  @Test
  public void shouldListTemplates2() {
    String ctagsOutput = "loop\t/tmp/sketch3159399142353673614.cpp\t/^void loop () { }/;\"\tfunction\tsignature:()\treturntype: void\n" +
            "minimum\t/tmp/sketch3159399142353673614.cpp\t/^template <typename T> T minimum (T a, T b) $/;\"\tfunction\tsignature:(T a, T b)\treturntype: templateT\n" +
            "setup\t/tmp/sketch3159399142353673614.cpp\t/^void setup () $/;\"\tfunction\tsignature:()\treturntype: void\n";

    List<String> prototypes = new CTagsParser().parse(ctagsOutput);

    assertEquals(3, prototypes.size());
    assertEquals("void loop();", prototypes.get(0));
    assertEquals("template <typename T> T minimum (T a, T b);", prototypes.get(1));
    assertEquals("void setup();", prototypes.get(2));
  }

  @Test
  public void shouldListTemplates3() {
    String ctagsOutput = "setup\t/tmp/sketch4737149770852317238.cpp\t/^void setup() {$/;\"\tfunction\tsignature:()\treturntype: void\n" +
            "loop\t/tmp/sketch4737149770852317238.cpp\t/^void loop() {$/;\"\tfunction\tsignature:()\treturntype: void\n" +
            "SRAM_writeAnything\t/tmp/sketch4737149770852317238.cpp\t/^template <class T> int SRAM_writeAnything(int ee, const T& value)$/;\"\tfunction\tsignature:(int ee, const T& value)\treturntype: template int\n" +
            "SRAM_readAnything\t/tmp/sketch4737149770852317238.cpp\t/^template <class T> int SRAM_readAnything(int ee, T& value)$/;\"\tfunction\tsignature:(int ee, T& value)\treturntype: template int\n";

    List<String> prototypes = new CTagsParser().parse(ctagsOutput);

    assertEquals(4, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("template <class T> int SRAM_writeAnything(int ee, const T& value);", prototypes.get(2));
    assertEquals("template <class T> int SRAM_readAnything(int ee, T& value);", prototypes.get(3));
  }

  @Test
  public void shouldDealWithClasses() {
    String ctagsOutput = "SleepCycle\t/tmp/sketch1654772829194906518.cpp\t/^class SleepCycle  {$/;\"\tclass\n" +
            "SleepCycle\t/tmp/sketch1654772829194906518.cpp\t/^        SleepCycle( const char* name );$/;\"\tprototype\tsignature:( const char* name )\n" +
            "SleepCycle\t/tmp/sketch1654772829194906518.cpp\t/^    SleepCycle::SleepCycle( const char* name )$/;\"\tfunction\tsignature:( const char* name )\n";

    List<String> prototypes = new CTagsParser().parse(ctagsOutput);

    assertEquals(0, prototypes.size());
  }

  // result of ctags -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzn /tmp/sketch8930345717354294915.cpp
  @Test
  @Ignore
  public void shouldDealWithStructs() {
    String ctagsOutput = "A_NEW_TYPE\t/tmp/sketch8930345717354294915.cpp\t/^struct A_NEW_TYPE {$/;\"\tkind:struct\tline:3\n" +
            "foo\t/tmp/sketch8930345717354294915.cpp\t/^} foo;$/;\"\tkind:variable\tline:7\ttyperef:struct:A_NEW_TYPE\n" +
            "setup\t/tmp/sketch8930345717354294915.cpp\t/^void setup() {$/;\"\tkind:function\tline:9\tsignature:()\treturntype:void\n" +
            "loop\t/tmp/sketch8930345717354294915.cpp\t/^void loop() {$/;\"\tkind:function\tline:13\tsignature:()\treturntype:void\n" +
            "dostuff\t/tmp/sketch8930345717354294915.cpp\t/^void dostuff (A_NEW_TYPE * bar)$/;\"\tkind:function\tline:17\tsignature:(A_NEW_TYPE * bar)\treturntype:void\n";

    List<String> prototypes = new CTagsParser().parse(ctagsOutput);

    assertEquals(3, prototypes.size());
    assertEquals("void setup();", prototypes.get(0));
    assertEquals("void loop();", prototypes.get(1));
    assertEquals("void dostuff (A_NEW_TYPE * bar);", prototypes.get(2));
  }

}
