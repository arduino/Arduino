package cc.arduino.builder;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import cc.arduino.Compiler;
import cc.arduino.builder.BuilderGrpc.BuilderBlockingStub;
import io.grpc.ManagedChannel;
import io.grpc.ManagedChannelBuilder;
import processing.app.BaseNoGui;
import processing.app.debug.MessageSiphon;
import processing.app.debug.TargetBoard;
import processing.app.helpers.ProcessUtils;

public class ArduinoBuilder {

  private ManagedChannel channel;
  private BuilderBlockingStub blockingStub;
  // private BuilderStub asyncStub;

  private Process builder;
  private MessageSiphon builderOut, builderErr;
//  private Exception exception = null;

  public ArduinoBuilder() throws IOException {
    channel = ManagedChannelBuilder.forAddress("127.0.0.1", 12345).usePlaintext(true).build();
    blockingStub = BuilderGrpc.newBlockingStub(channel);
    // asyncStub = BuilderGrpc.newStub(channel);

    List<String> cmd = new ArrayList<>();
    cmd.add(BaseNoGui.getContentFile("arduino-builder").getAbsolutePath());
    cmd.add("-daemon");
    builder = ProcessUtils.exec(cmd.toArray(new String[0]));
    builderOut = new MessageSiphon(builder.getInputStream(), (msg) -> {
      System.out.println(msg);
      // try {
      // xxx.write(msg.getBytes());
      // } catch (Exception e) {
      // exception = new RunnerException(e);
      // }
    });
    builderErr = new MessageSiphon(builder.getErrorStream(), (msg) -> {
      System.err.println(msg);
      // try {
      // xxx.write(msg.getBytes());
      // } catch (Exception e) {
      // exception = new RunnerException(e);
      // }
    });
  }

  public int close() throws InterruptedException {
    builder.destroy();
    builderOut.join();
    builderErr.join();
    return builder.waitFor();
  }

  public String codeComplete(TargetBoard board, File pathToSketch, File requestedFile, int line, int col) {
    BuildParams.Builder request = BuildParams.newBuilder();

    File builtInLibs = BaseNoGui.getContentFile("libraries");
    if (builtInLibs.isDirectory()) {
      request.setBuiltInLibrariesFolders(builtInLibs.getAbsolutePath());
    }
    request.setCodeCompleteAt(requestedFile.getAbsolutePath() + ":" + line + ":" + col);
    request.setFQBN(Compiler.getBoardFQBN(board));
    request.setCustomBuildProperties("build.warn_data_percentage=75");
    String hardwareFolders = BaseNoGui.getAllHardwareFolders().stream().map(x -> x.getAbsolutePath()).collect(Collectors.joining(","));
    request.setHardwareFolders(hardwareFolders);
    request.setOtherLibrariesFolders(BaseNoGui.getSketchbookLibrariesFolder().getAbsolutePath());
    request.setArduinoAPIVersion("10805");
    request.setSketchLocation(pathToSketch.getAbsolutePath());
    String toolsFolders = BaseNoGui.getAllToolsFolders().stream().map(x->x.getAbsolutePath()).collect(Collectors.joining(","));
    request.setToolsFolders(toolsFolders);
    //request.setVerbose(true);
    //request.setWarningsLevel("all");
    //request.setBuildCachePath("/tmp/arduino_cache_761418/");
    Response resp = blockingStub.autocomplete(request.build());
    return resp.getLine();
  }

}
