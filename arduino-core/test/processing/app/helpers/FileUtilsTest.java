package processing.app.helpers;

import java.io.File;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

import org.junit.Assert;
import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.ExpectedException;
import org.junit.rules.TemporaryFolder;
import org.junit.runner.RunWith;
import org.powermock.api.mockito.PowerMockito;
import org.powermock.core.classloader.annotations.PrepareForTest;
import org.powermock.modules.junit4.PowerMockRunner;

import static org.mockito.Matchers.anyInt;

@RunWith(PowerMockRunner.class)
public class FileUtilsTest {

	@Rule
	public final ExpectedException thrown = ExpectedException.none();

  @Rule
  private TemporaryFolder folder = new TemporaryFolder();

  @Test
  public void testIsSubDirectory1() throws Exception {
    final File base = PowerMockito.mock(File.class);
    final File file = PowerMockito.mock(File.class);
    final File child = PowerMockito.mock(File.class);
    final File file1 = PowerMockito.mock(File.class);

    PowerMockito.when(base.getCanonicalFile()).thenReturn(file);
    PowerMockito.when(file1.getParentFile()).thenReturn(null);
    PowerMockito.when(child.getCanonicalFile()).thenReturn(file1);

    Assert.assertFalse(FileUtils.isSubDirectory(base, child));
  }

  @Test
  public void testIsSubDirectory2() throws Exception {
    final File base = PowerMockito.mock(File.class);
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(base.getCanonicalFile()).thenReturn(file);

    Assert.assertTrue(FileUtils.isSubDirectory(base, base));
  }

  @PrepareForTest({FileUtils.class})
  @Test
  public void testCreateTempFolder1() throws Exception {
    final Path path = PowerMockito.mock(Path.class);
    final File file = PowerMockito.mock(File.class);
    final Random random = PowerMockito.mock(Random.class);

    PowerMockito.when(file.getPath()).thenReturn("bar");
    PowerMockito.when(path.toFile()).thenReturn(file);
    PowerMockito.when(random.nextInt(anyInt())).thenReturn(5);
    PowerMockito.whenNew(Random.class).withAnyArguments().thenReturn(random);

    Assert.assertEquals("bar5",
      FileUtils.createTempFolder(file, "bar").getName());
    Assert.assertEquals("null/bar5",
      FileUtils.createTempFolder(file, "bar").getPath());
  }

  @Test
  public void testCreateTempFolder2() throws Exception {
    Assert.assertEquals("foobar",
      FileUtils.createTempFolder("foo", "bar").getName());
    Assert.assertEquals("/tmp/foobar",
      FileUtils.createTempFolder("foo", "bar").getPath());
  }

  @PrepareForTest({FileUtils.class})
  @Test
  public void testCreateTempFolder3() throws Exception {
    final File file = PowerMockito.mock(File.class);
    final Random random = PowerMockito.mock(Random.class);

    PowerMockito.when(random.nextInt(anyInt())).thenReturn(1337);
    PowerMockito.whenNew(Random.class).withAnyArguments().thenReturn(random);

    Assert.assertEquals("arduino_1337",
      FileUtils.createTempFolder(file).getName());
  }

  @PrepareForTest({FileUtils.class})
  @Test
  public void testCreateTempFolder4() throws Exception {
    final Random random = PowerMockito.mock(Random.class);

    PowerMockito.when(random.nextInt(anyInt())).thenReturn(1337);
    PowerMockito.whenNew(Random.class).withAnyArguments().thenReturn(random);

    Assert.assertEquals("foo_1337",
      FileUtils.createTempFolder("foo_").getName());
  }

  @PrepareForTest({FileUtils.class})
  @Test
  public void testCreateTempFolder5() throws Exception {
    final Random random = PowerMockito.mock(Random.class);

    PowerMockito.when(random.nextInt(anyInt())).thenReturn(1337);
    PowerMockito.whenNew(Random.class).withAnyArguments().thenReturn(random);

    Assert.assertEquals("arduino_1337",
      FileUtils.createTempFolder().getName());
  }

  @Test
  public void testIsSCCSOrHiddenFile1() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.getName()).thenReturn("1a 2b 3c");
    PowerMockito.when(file.isDirectory()).thenReturn(false);
    PowerMockito.when(file.isHidden()).thenReturn(false);

    Assert.assertFalse(FileUtils.isSCCSOrHiddenFile(file));
  }

  @Test
  public void testIsSCCSOrHiddenFile2() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.isDirectory()).thenReturn(false);
    PowerMockito.when(file.isHidden()).thenReturn(true);

    Assert.assertTrue(FileUtils.isSCCSOrHiddenFile(file));
  }

  @Test
  public void testIsHiddenFile1() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.getName()).thenReturn("foo");
    PowerMockito.when(file.isHidden()).thenReturn(false);

    Assert.assertFalse(FileUtils.isHiddenFile(file));
  }

  @Test
  public void testIsHiddenFile2() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.isHidden()).thenReturn(true);

    Assert.assertTrue(FileUtils.isHiddenFile(file));
  }

  @Test
  public void testIsHiddenFile3() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.isHidden()).thenReturn(false);
    PowerMockito.when(file.getName()).thenReturn(".foo");

    Assert.assertTrue(FileUtils.isHiddenFile(file));
  }

  @Test
  public void testIsHiddenFileThrowsException() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.getName()).thenReturn("");
    PowerMockito.when(file.isHidden()).thenReturn(false);

    thrown.expect(StringIndexOutOfBoundsException.class);
    FileUtils.isHiddenFile(file);
  }

  @Test
  public void testIsSCCSFolder1() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.isDirectory()).thenReturn(false);

    Assert.assertFalse(FileUtils.isSCCSFolder(file));
  }

  @Test
  public void testIsSCCSFolder2() {
    final File file = PowerMockito.mock(File.class);

    PowerMockito.when(file.isDirectory()).thenReturn(true);
    PowerMockito.when(file.getName()).thenReturn(null);

    Assert.assertFalse(FileUtils.isSCCSFolder(file));
  }

  @Test
  public void testHasExtension() throws Exception {
    final File file1 = folder.newFile("foo");
    final File file2 = folder.newFile("bar.txt");

    Assert.assertFalse(FileUtils.hasExtension(file1, new ArrayList<>()));
    Assert.assertTrue(FileUtils.hasExtension(file2,
      new ArrayList<>(Arrays.asList("txt"))));
  }

  @Test
  public void testReplaceExtension1() {
    Assert.assertEquals("hello.txt", FileUtils.replaceExtension("hello", "txt"));
  }

  @PrepareForTest({FileUtils.class})
  @Test
  public void testReplaceExtension2() throws Exception {
    final File file = PowerMockito.mock(File.class);
    final File file2 = PowerMockito.mock(File.class);

    PowerMockito.when(file.getName()).thenReturn("foo");
    PowerMockito.whenNew(File.class).withAnyArguments().thenReturn(file2);

    Assert.assertEquals(file2, FileUtils.replaceExtension(file, "txt"));
  }

	@Test
	public void testAddExtension() {
    Assert.assertNull(FileUtils.addExtension((String) null, ""));
    Assert.assertEquals("hello.txt'", FileUtils.addExtension("hello", "txt'"));
	}

	@Test
	public void testListFiles1() {
		final File folder = PowerMockito.mock(File.class);

		PowerMockito.when(folder.exists()).thenReturn(false);

		Assert.assertEquals(new ArrayList<File>(),
      FileUtils.listFiles(folder, false, new ArrayList<>()));
	}

	@Test
  public void testListFiles2() {
		final File folder = PowerMockito.mock(File.class);

		PowerMockito.when(folder.exists()).thenReturn(false);

		Assert.assertEquals(new ArrayList<>(),
      FileUtils.listFiles(folder, false, new String[0]));
	}

	@Test
  public void testListFiles3() {
		final File folder = PowerMockito.mock(File.class);

		PowerMockito.when(folder.exists()).thenReturn(true);
		PowerMockito.when(folder.listFiles()).thenReturn(new File[]{});

		Assert.assertEquals(new ArrayList<>(),
      FileUtils.listFiles(folder, false, "hello"));
	}

	@Test
  public void testListFiles4() {
		final File folder = PowerMockito.mock(File.class);
		final File file = PowerMockito.mock(File.class);

		PowerMockito.when(folder.exists()).thenReturn(true);
		PowerMockito.when(file.isHidden()).thenReturn(true);
		PowerMockito.when(file.isDirectory()).thenReturn(true);
		PowerMockito.when(folder.listFiles()).thenReturn(new File[]{file});

		Assert.assertEquals(new ArrayList<>(),
      FileUtils.listFiles(folder, false, new String[0]));
	}
}
