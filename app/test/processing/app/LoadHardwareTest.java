package processing.app;

import org.junit.Test;
import processing.app.debug.TargetPlatform;
import processing.app.helpers.PreferencesMap;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class LoadHardwareTest extends AbstractWithPreferencesTest {

  @Test
  public void shouldHaveLoadedTheParentPlatformTxtFiles() {
    TargetPlatform targetPlatform = BaseNoGui.getTargetPlatform("arduino", "avr");

    PreferencesMap ctags = targetPlatform.getTool("ctags");
    assertNotNull(ctags);
    assertEquals("{runtime.ide.path}/hardware/tools/ctags", ctags.get("cmd.path"));
    assertEquals("\"{cmd.path}\" -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzn \"{source_file}\"", ctags.get("pattern"));

    PreferencesMap coan = targetPlatform.getTool("coan");
    assertNotNull(coan);
    assertEquals("{runtime.ide.path}/hardware/tools/coan", coan.get("cmd.path"));
    assertEquals("\"{cmd.path}\" source -m -E -P -kb {compiler.c.flags} -mmcu={build.mcu} -DF_CPU={build.f_cpu} -DARDUINO={runtime.ide.version} -DARDUINO_{build.board} -DARDUINO_ARCH_{build.arch} {compiler.c.extra_flags} {build.extra_flags} \"{source_file}\"", coan.get("pattern"));

    targetPlatform = BaseNoGui.getTargetPlatform("arduino", "sam");

    ctags = targetPlatform.getTool("ctags");
    assertNotNull(ctags);
    assertEquals("{runtime.ide.path}/hardware/tools/ctags", ctags.get("cmd.path"));
    assertEquals("\"{cmd.path}\" -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzn \"{source_file}\"", ctags.get("pattern"));

    coan = targetPlatform.getTool("coan");
    assertNotNull(coan);
    assertEquals("{runtime.ide.path}/hardware/tools/coan", coan.get("cmd.path"));
    assertEquals("\"{cmd.path}\" source -m -E -P -kb {compiler.c.flags} -mcpu={build.mcu} -DF_CPU={build.f_cpu} -DARDUINO={runtime.ide.version} -DARDUINO_{build.board} -DARDUINO_ARCH_{build.arch} {compiler.c.extra_flags} {build.extra_flags} {compiler.libsam.c.flags} \"{source_file}\"", coan.get("pattern"));
  }

}
