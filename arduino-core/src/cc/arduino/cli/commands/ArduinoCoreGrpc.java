package cc.arduino.cli.commands;

import static io.grpc.MethodDescriptor.generateFullMethodName;
import static io.grpc.stub.ClientCalls.asyncBidiStreamingCall;
import static io.grpc.stub.ClientCalls.asyncClientStreamingCall;
import static io.grpc.stub.ClientCalls.asyncServerStreamingCall;
import static io.grpc.stub.ClientCalls.asyncUnaryCall;
import static io.grpc.stub.ClientCalls.blockingServerStreamingCall;
import static io.grpc.stub.ClientCalls.blockingUnaryCall;
import static io.grpc.stub.ClientCalls.futureUnaryCall;
import static io.grpc.stub.ServerCalls.asyncBidiStreamingCall;
import static io.grpc.stub.ServerCalls.asyncClientStreamingCall;
import static io.grpc.stub.ServerCalls.asyncServerStreamingCall;
import static io.grpc.stub.ServerCalls.asyncUnaryCall;
import static io.grpc.stub.ServerCalls.asyncUnimplementedStreamingCall;
import static io.grpc.stub.ServerCalls.asyncUnimplementedUnaryCall;

/**
 * <pre>
 * The main Arduino Platform Service
 * </pre>
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.20.0)",
    comments = "Source: commands/commands.proto")
public final class ArduinoCoreGrpc {

  private ArduinoCoreGrpc() {}

  public static final String SERVICE_NAME = "cc.arduino.cli.commands.ArduinoCore";

  // Static method descriptors that strictly reflect the proto.
  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.InitReq,
      cc.arduino.cli.commands.Commands.InitResp> getInitMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Init",
      requestType = cc.arduino.cli.commands.Commands.InitReq.class,
      responseType = cc.arduino.cli.commands.Commands.InitResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.InitReq,
      cc.arduino.cli.commands.Commands.InitResp> getInitMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.InitReq, cc.arduino.cli.commands.Commands.InitResp> getInitMethod;
    if ((getInitMethod = ArduinoCoreGrpc.getInitMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getInitMethod = ArduinoCoreGrpc.getInitMethod) == null) {
          ArduinoCoreGrpc.getInitMethod = getInitMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Commands.InitReq, cc.arduino.cli.commands.Commands.InitResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "Init"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.InitReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.InitResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("Init"))
                  .build();
          }
        }
     }
     return getInitMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.DestroyReq,
      cc.arduino.cli.commands.Commands.DestroyResp> getDestroyMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Destroy",
      requestType = cc.arduino.cli.commands.Commands.DestroyReq.class,
      responseType = cc.arduino.cli.commands.Commands.DestroyResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.DestroyReq,
      cc.arduino.cli.commands.Commands.DestroyResp> getDestroyMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.DestroyReq, cc.arduino.cli.commands.Commands.DestroyResp> getDestroyMethod;
    if ((getDestroyMethod = ArduinoCoreGrpc.getDestroyMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getDestroyMethod = ArduinoCoreGrpc.getDestroyMethod) == null) {
          ArduinoCoreGrpc.getDestroyMethod = getDestroyMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Commands.DestroyReq, cc.arduino.cli.commands.Commands.DestroyResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "Destroy"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.DestroyReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.DestroyResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("Destroy"))
                  .build();
          }
        }
     }
     return getDestroyMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.RescanReq,
      cc.arduino.cli.commands.Commands.RescanResp> getRescanMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Rescan",
      requestType = cc.arduino.cli.commands.Commands.RescanReq.class,
      responseType = cc.arduino.cli.commands.Commands.RescanResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.RescanReq,
      cc.arduino.cli.commands.Commands.RescanResp> getRescanMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.RescanReq, cc.arduino.cli.commands.Commands.RescanResp> getRescanMethod;
    if ((getRescanMethod = ArduinoCoreGrpc.getRescanMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getRescanMethod = ArduinoCoreGrpc.getRescanMethod) == null) {
          ArduinoCoreGrpc.getRescanMethod = getRescanMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Commands.RescanReq, cc.arduino.cli.commands.Commands.RescanResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "Rescan"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.RescanReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.RescanResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("Rescan"))
                  .build();
          }
        }
     }
     return getRescanMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.UpdateIndexReq,
      cc.arduino.cli.commands.Commands.UpdateIndexResp> getUpdateIndexMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "UpdateIndex",
      requestType = cc.arduino.cli.commands.Commands.UpdateIndexReq.class,
      responseType = cc.arduino.cli.commands.Commands.UpdateIndexResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.UpdateIndexReq,
      cc.arduino.cli.commands.Commands.UpdateIndexResp> getUpdateIndexMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.UpdateIndexReq, cc.arduino.cli.commands.Commands.UpdateIndexResp> getUpdateIndexMethod;
    if ((getUpdateIndexMethod = ArduinoCoreGrpc.getUpdateIndexMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getUpdateIndexMethod = ArduinoCoreGrpc.getUpdateIndexMethod) == null) {
          ArduinoCoreGrpc.getUpdateIndexMethod = getUpdateIndexMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Commands.UpdateIndexReq, cc.arduino.cli.commands.Commands.UpdateIndexResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "UpdateIndex"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.UpdateIndexReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.UpdateIndexResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("UpdateIndex"))
                  .build();
          }
        }
     }
     return getUpdateIndexMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq,
      cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp> getUpdateLibrariesIndexMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "UpdateLibrariesIndex",
      requestType = cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq.class,
      responseType = cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq,
      cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp> getUpdateLibrariesIndexMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq, cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp> getUpdateLibrariesIndexMethod;
    if ((getUpdateLibrariesIndexMethod = ArduinoCoreGrpc.getUpdateLibrariesIndexMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getUpdateLibrariesIndexMethod = ArduinoCoreGrpc.getUpdateLibrariesIndexMethod) == null) {
          ArduinoCoreGrpc.getUpdateLibrariesIndexMethod = getUpdateLibrariesIndexMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq, cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "UpdateLibrariesIndex"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("UpdateLibrariesIndex"))
                  .build();
          }
        }
     }
     return getUpdateLibrariesIndexMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.VersionReq,
      cc.arduino.cli.commands.Commands.VersionResp> getVersionMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Version",
      requestType = cc.arduino.cli.commands.Commands.VersionReq.class,
      responseType = cc.arduino.cli.commands.Commands.VersionResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.VersionReq,
      cc.arduino.cli.commands.Commands.VersionResp> getVersionMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Commands.VersionReq, cc.arduino.cli.commands.Commands.VersionResp> getVersionMethod;
    if ((getVersionMethod = ArduinoCoreGrpc.getVersionMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getVersionMethod = ArduinoCoreGrpc.getVersionMethod) == null) {
          ArduinoCoreGrpc.getVersionMethod = getVersionMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Commands.VersionReq, cc.arduino.cli.commands.Commands.VersionResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "Version"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.VersionReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Commands.VersionResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("Version"))
                  .build();
          }
        }
     }
     return getVersionMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardDetailsReq,
      cc.arduino.cli.commands.Board.BoardDetailsResp> getBoardDetailsMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "BoardDetails",
      requestType = cc.arduino.cli.commands.Board.BoardDetailsReq.class,
      responseType = cc.arduino.cli.commands.Board.BoardDetailsResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardDetailsReq,
      cc.arduino.cli.commands.Board.BoardDetailsResp> getBoardDetailsMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardDetailsReq, cc.arduino.cli.commands.Board.BoardDetailsResp> getBoardDetailsMethod;
    if ((getBoardDetailsMethod = ArduinoCoreGrpc.getBoardDetailsMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getBoardDetailsMethod = ArduinoCoreGrpc.getBoardDetailsMethod) == null) {
          ArduinoCoreGrpc.getBoardDetailsMethod = getBoardDetailsMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Board.BoardDetailsReq, cc.arduino.cli.commands.Board.BoardDetailsResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "BoardDetails"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardDetailsReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardDetailsResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("BoardDetails"))
                  .build();
          }
        }
     }
     return getBoardDetailsMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardAttachReq,
      cc.arduino.cli.commands.Board.BoardAttachResp> getBoardAttachMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "BoardAttach",
      requestType = cc.arduino.cli.commands.Board.BoardAttachReq.class,
      responseType = cc.arduino.cli.commands.Board.BoardAttachResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardAttachReq,
      cc.arduino.cli.commands.Board.BoardAttachResp> getBoardAttachMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardAttachReq, cc.arduino.cli.commands.Board.BoardAttachResp> getBoardAttachMethod;
    if ((getBoardAttachMethod = ArduinoCoreGrpc.getBoardAttachMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getBoardAttachMethod = ArduinoCoreGrpc.getBoardAttachMethod) == null) {
          ArduinoCoreGrpc.getBoardAttachMethod = getBoardAttachMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Board.BoardAttachReq, cc.arduino.cli.commands.Board.BoardAttachResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "BoardAttach"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardAttachReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardAttachResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("BoardAttach"))
                  .build();
          }
        }
     }
     return getBoardAttachMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardListReq,
      cc.arduino.cli.commands.Board.BoardListResp> getBoardListMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "BoardList",
      requestType = cc.arduino.cli.commands.Board.BoardListReq.class,
      responseType = cc.arduino.cli.commands.Board.BoardListResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardListReq,
      cc.arduino.cli.commands.Board.BoardListResp> getBoardListMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardListReq, cc.arduino.cli.commands.Board.BoardListResp> getBoardListMethod;
    if ((getBoardListMethod = ArduinoCoreGrpc.getBoardListMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getBoardListMethod = ArduinoCoreGrpc.getBoardListMethod) == null) {
          ArduinoCoreGrpc.getBoardListMethod = getBoardListMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Board.BoardListReq, cc.arduino.cli.commands.Board.BoardListResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "BoardList"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardListReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardListResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("BoardList"))
                  .build();
          }
        }
     }
     return getBoardListMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardListAllReq,
      cc.arduino.cli.commands.Board.BoardListAllResp> getBoardListAllMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "BoardListAll",
      requestType = cc.arduino.cli.commands.Board.BoardListAllReq.class,
      responseType = cc.arduino.cli.commands.Board.BoardListAllResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardListAllReq,
      cc.arduino.cli.commands.Board.BoardListAllResp> getBoardListAllMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Board.BoardListAllReq, cc.arduino.cli.commands.Board.BoardListAllResp> getBoardListAllMethod;
    if ((getBoardListAllMethod = ArduinoCoreGrpc.getBoardListAllMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getBoardListAllMethod = ArduinoCoreGrpc.getBoardListAllMethod) == null) {
          ArduinoCoreGrpc.getBoardListAllMethod = getBoardListAllMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Board.BoardListAllReq, cc.arduino.cli.commands.Board.BoardListAllResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "BoardListAll"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardListAllReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Board.BoardListAllResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("BoardListAll"))
                  .build();
          }
        }
     }
     return getBoardListAllMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Compile.CompileReq,
      cc.arduino.cli.commands.Compile.CompileResp> getCompileMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Compile",
      requestType = cc.arduino.cli.commands.Compile.CompileReq.class,
      responseType = cc.arduino.cli.commands.Compile.CompileResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Compile.CompileReq,
      cc.arduino.cli.commands.Compile.CompileResp> getCompileMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Compile.CompileReq, cc.arduino.cli.commands.Compile.CompileResp> getCompileMethod;
    if ((getCompileMethod = ArduinoCoreGrpc.getCompileMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getCompileMethod = ArduinoCoreGrpc.getCompileMethod) == null) {
          ArduinoCoreGrpc.getCompileMethod = getCompileMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Compile.CompileReq, cc.arduino.cli.commands.Compile.CompileResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "Compile"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Compile.CompileReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Compile.CompileResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("Compile"))
                  .build();
          }
        }
     }
     return getCompileMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformInstallReq,
      cc.arduino.cli.commands.Core.PlatformInstallResp> getPlatformInstallMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "PlatformInstall",
      requestType = cc.arduino.cli.commands.Core.PlatformInstallReq.class,
      responseType = cc.arduino.cli.commands.Core.PlatformInstallResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformInstallReq,
      cc.arduino.cli.commands.Core.PlatformInstallResp> getPlatformInstallMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformInstallReq, cc.arduino.cli.commands.Core.PlatformInstallResp> getPlatformInstallMethod;
    if ((getPlatformInstallMethod = ArduinoCoreGrpc.getPlatformInstallMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getPlatformInstallMethod = ArduinoCoreGrpc.getPlatformInstallMethod) == null) {
          ArduinoCoreGrpc.getPlatformInstallMethod = getPlatformInstallMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Core.PlatformInstallReq, cc.arduino.cli.commands.Core.PlatformInstallResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "PlatformInstall"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformInstallReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformInstallResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("PlatformInstall"))
                  .build();
          }
        }
     }
     return getPlatformInstallMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformDownloadReq,
      cc.arduino.cli.commands.Core.PlatformDownloadResp> getPlatformDownloadMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "PlatformDownload",
      requestType = cc.arduino.cli.commands.Core.PlatformDownloadReq.class,
      responseType = cc.arduino.cli.commands.Core.PlatformDownloadResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformDownloadReq,
      cc.arduino.cli.commands.Core.PlatformDownloadResp> getPlatformDownloadMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformDownloadReq, cc.arduino.cli.commands.Core.PlatformDownloadResp> getPlatformDownloadMethod;
    if ((getPlatformDownloadMethod = ArduinoCoreGrpc.getPlatformDownloadMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getPlatformDownloadMethod = ArduinoCoreGrpc.getPlatformDownloadMethod) == null) {
          ArduinoCoreGrpc.getPlatformDownloadMethod = getPlatformDownloadMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Core.PlatformDownloadReq, cc.arduino.cli.commands.Core.PlatformDownloadResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "PlatformDownload"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformDownloadReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformDownloadResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("PlatformDownload"))
                  .build();
          }
        }
     }
     return getPlatformDownloadMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformUninstallReq,
      cc.arduino.cli.commands.Core.PlatformUninstallResp> getPlatformUninstallMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "PlatformUninstall",
      requestType = cc.arduino.cli.commands.Core.PlatformUninstallReq.class,
      responseType = cc.arduino.cli.commands.Core.PlatformUninstallResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformUninstallReq,
      cc.arduino.cli.commands.Core.PlatformUninstallResp> getPlatformUninstallMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformUninstallReq, cc.arduino.cli.commands.Core.PlatformUninstallResp> getPlatformUninstallMethod;
    if ((getPlatformUninstallMethod = ArduinoCoreGrpc.getPlatformUninstallMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getPlatformUninstallMethod = ArduinoCoreGrpc.getPlatformUninstallMethod) == null) {
          ArduinoCoreGrpc.getPlatformUninstallMethod = getPlatformUninstallMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Core.PlatformUninstallReq, cc.arduino.cli.commands.Core.PlatformUninstallResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "PlatformUninstall"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformUninstallReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformUninstallResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("PlatformUninstall"))
                  .build();
          }
        }
     }
     return getPlatformUninstallMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformUpgradeReq,
      cc.arduino.cli.commands.Core.PlatformUpgradeResp> getPlatformUpgradeMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "PlatformUpgrade",
      requestType = cc.arduino.cli.commands.Core.PlatformUpgradeReq.class,
      responseType = cc.arduino.cli.commands.Core.PlatformUpgradeResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformUpgradeReq,
      cc.arduino.cli.commands.Core.PlatformUpgradeResp> getPlatformUpgradeMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformUpgradeReq, cc.arduino.cli.commands.Core.PlatformUpgradeResp> getPlatformUpgradeMethod;
    if ((getPlatformUpgradeMethod = ArduinoCoreGrpc.getPlatformUpgradeMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getPlatformUpgradeMethod = ArduinoCoreGrpc.getPlatformUpgradeMethod) == null) {
          ArduinoCoreGrpc.getPlatformUpgradeMethod = getPlatformUpgradeMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Core.PlatformUpgradeReq, cc.arduino.cli.commands.Core.PlatformUpgradeResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "PlatformUpgrade"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformUpgradeReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformUpgradeResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("PlatformUpgrade"))
                  .build();
          }
        }
     }
     return getPlatformUpgradeMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Upload.UploadReq,
      cc.arduino.cli.commands.Upload.UploadResp> getUploadMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Upload",
      requestType = cc.arduino.cli.commands.Upload.UploadReq.class,
      responseType = cc.arduino.cli.commands.Upload.UploadResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Upload.UploadReq,
      cc.arduino.cli.commands.Upload.UploadResp> getUploadMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Upload.UploadReq, cc.arduino.cli.commands.Upload.UploadResp> getUploadMethod;
    if ((getUploadMethod = ArduinoCoreGrpc.getUploadMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getUploadMethod = ArduinoCoreGrpc.getUploadMethod) == null) {
          ArduinoCoreGrpc.getUploadMethod = getUploadMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Upload.UploadReq, cc.arduino.cli.commands.Upload.UploadResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "Upload"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Upload.UploadReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Upload.UploadResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("Upload"))
                  .build();
          }
        }
     }
     return getUploadMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformSearchReq,
      cc.arduino.cli.commands.Core.PlatformSearchResp> getPlatformSearchMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "PlatformSearch",
      requestType = cc.arduino.cli.commands.Core.PlatformSearchReq.class,
      responseType = cc.arduino.cli.commands.Core.PlatformSearchResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformSearchReq,
      cc.arduino.cli.commands.Core.PlatformSearchResp> getPlatformSearchMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformSearchReq, cc.arduino.cli.commands.Core.PlatformSearchResp> getPlatformSearchMethod;
    if ((getPlatformSearchMethod = ArduinoCoreGrpc.getPlatformSearchMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getPlatformSearchMethod = ArduinoCoreGrpc.getPlatformSearchMethod) == null) {
          ArduinoCoreGrpc.getPlatformSearchMethod = getPlatformSearchMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Core.PlatformSearchReq, cc.arduino.cli.commands.Core.PlatformSearchResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "PlatformSearch"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformSearchReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformSearchResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("PlatformSearch"))
                  .build();
          }
        }
     }
     return getPlatformSearchMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformListReq,
      cc.arduino.cli.commands.Core.PlatformListResp> getPlatformListMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "PlatformList",
      requestType = cc.arduino.cli.commands.Core.PlatformListReq.class,
      responseType = cc.arduino.cli.commands.Core.PlatformListResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformListReq,
      cc.arduino.cli.commands.Core.PlatformListResp> getPlatformListMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Core.PlatformListReq, cc.arduino.cli.commands.Core.PlatformListResp> getPlatformListMethod;
    if ((getPlatformListMethod = ArduinoCoreGrpc.getPlatformListMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getPlatformListMethod = ArduinoCoreGrpc.getPlatformListMethod) == null) {
          ArduinoCoreGrpc.getPlatformListMethod = getPlatformListMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Core.PlatformListReq, cc.arduino.cli.commands.Core.PlatformListResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "PlatformList"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformListReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Core.PlatformListResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("PlatformList"))
                  .build();
          }
        }
     }
     return getPlatformListMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryDownloadReq,
      cc.arduino.cli.commands.Lib.LibraryDownloadResp> getLibraryDownloadMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "LibraryDownload",
      requestType = cc.arduino.cli.commands.Lib.LibraryDownloadReq.class,
      responseType = cc.arduino.cli.commands.Lib.LibraryDownloadResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryDownloadReq,
      cc.arduino.cli.commands.Lib.LibraryDownloadResp> getLibraryDownloadMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryDownloadReq, cc.arduino.cli.commands.Lib.LibraryDownloadResp> getLibraryDownloadMethod;
    if ((getLibraryDownloadMethod = ArduinoCoreGrpc.getLibraryDownloadMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getLibraryDownloadMethod = ArduinoCoreGrpc.getLibraryDownloadMethod) == null) {
          ArduinoCoreGrpc.getLibraryDownloadMethod = getLibraryDownloadMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Lib.LibraryDownloadReq, cc.arduino.cli.commands.Lib.LibraryDownloadResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "LibraryDownload"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryDownloadReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryDownloadResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("LibraryDownload"))
                  .build();
          }
        }
     }
     return getLibraryDownloadMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryInstallReq,
      cc.arduino.cli.commands.Lib.LibraryInstallResp> getLibraryInstallMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "LibraryInstall",
      requestType = cc.arduino.cli.commands.Lib.LibraryInstallReq.class,
      responseType = cc.arduino.cli.commands.Lib.LibraryInstallResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryInstallReq,
      cc.arduino.cli.commands.Lib.LibraryInstallResp> getLibraryInstallMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryInstallReq, cc.arduino.cli.commands.Lib.LibraryInstallResp> getLibraryInstallMethod;
    if ((getLibraryInstallMethod = ArduinoCoreGrpc.getLibraryInstallMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getLibraryInstallMethod = ArduinoCoreGrpc.getLibraryInstallMethod) == null) {
          ArduinoCoreGrpc.getLibraryInstallMethod = getLibraryInstallMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Lib.LibraryInstallReq, cc.arduino.cli.commands.Lib.LibraryInstallResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "LibraryInstall"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryInstallReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryInstallResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("LibraryInstall"))
                  .build();
          }
        }
     }
     return getLibraryInstallMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryUninstallReq,
      cc.arduino.cli.commands.Lib.LibraryUninstallResp> getLibraryUninstallMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "LibraryUninstall",
      requestType = cc.arduino.cli.commands.Lib.LibraryUninstallReq.class,
      responseType = cc.arduino.cli.commands.Lib.LibraryUninstallResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryUninstallReq,
      cc.arduino.cli.commands.Lib.LibraryUninstallResp> getLibraryUninstallMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryUninstallReq, cc.arduino.cli.commands.Lib.LibraryUninstallResp> getLibraryUninstallMethod;
    if ((getLibraryUninstallMethod = ArduinoCoreGrpc.getLibraryUninstallMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getLibraryUninstallMethod = ArduinoCoreGrpc.getLibraryUninstallMethod) == null) {
          ArduinoCoreGrpc.getLibraryUninstallMethod = getLibraryUninstallMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Lib.LibraryUninstallReq, cc.arduino.cli.commands.Lib.LibraryUninstallResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "LibraryUninstall"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryUninstallReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryUninstallResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("LibraryUninstall"))
                  .build();
          }
        }
     }
     return getLibraryUninstallMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq,
      cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp> getLibraryUpgradeAllMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "LibraryUpgradeAll",
      requestType = cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq.class,
      responseType = cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq,
      cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp> getLibraryUpgradeAllMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq, cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp> getLibraryUpgradeAllMethod;
    if ((getLibraryUpgradeAllMethod = ArduinoCoreGrpc.getLibraryUpgradeAllMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getLibraryUpgradeAllMethod = ArduinoCoreGrpc.getLibraryUpgradeAllMethod) == null) {
          ArduinoCoreGrpc.getLibraryUpgradeAllMethod = getLibraryUpgradeAllMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq, cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "LibraryUpgradeAll"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("LibraryUpgradeAll"))
                  .build();
          }
        }
     }
     return getLibraryUpgradeAllMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibrarySearchReq,
      cc.arduino.cli.commands.Lib.LibrarySearchResp> getLibrarySearchMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "LibrarySearch",
      requestType = cc.arduino.cli.commands.Lib.LibrarySearchReq.class,
      responseType = cc.arduino.cli.commands.Lib.LibrarySearchResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibrarySearchReq,
      cc.arduino.cli.commands.Lib.LibrarySearchResp> getLibrarySearchMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibrarySearchReq, cc.arduino.cli.commands.Lib.LibrarySearchResp> getLibrarySearchMethod;
    if ((getLibrarySearchMethod = ArduinoCoreGrpc.getLibrarySearchMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getLibrarySearchMethod = ArduinoCoreGrpc.getLibrarySearchMethod) == null) {
          ArduinoCoreGrpc.getLibrarySearchMethod = getLibrarySearchMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Lib.LibrarySearchReq, cc.arduino.cli.commands.Lib.LibrarySearchResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "LibrarySearch"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibrarySearchReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibrarySearchResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("LibrarySearch"))
                  .build();
          }
        }
     }
     return getLibrarySearchMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryListReq,
      cc.arduino.cli.commands.Lib.LibraryListResp> getLibraryListMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "LibraryList",
      requestType = cc.arduino.cli.commands.Lib.LibraryListReq.class,
      responseType = cc.arduino.cli.commands.Lib.LibraryListResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryListReq,
      cc.arduino.cli.commands.Lib.LibraryListResp> getLibraryListMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.commands.Lib.LibraryListReq, cc.arduino.cli.commands.Lib.LibraryListResp> getLibraryListMethod;
    if ((getLibraryListMethod = ArduinoCoreGrpc.getLibraryListMethod) == null) {
      synchronized (ArduinoCoreGrpc.class) {
        if ((getLibraryListMethod = ArduinoCoreGrpc.getLibraryListMethod) == null) {
          ArduinoCoreGrpc.getLibraryListMethod = getLibraryListMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.commands.Lib.LibraryListReq, cc.arduino.cli.commands.Lib.LibraryListResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.commands.ArduinoCore", "LibraryList"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryListReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.commands.Lib.LibraryListResp.getDefaultInstance()))
                  .setSchemaDescriptor(new ArduinoCoreMethodDescriptorSupplier("LibraryList"))
                  .build();
          }
        }
     }
     return getLibraryListMethod;
  }

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static ArduinoCoreStub newStub(io.grpc.Channel channel) {
    return new ArduinoCoreStub(channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static ArduinoCoreBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    return new ArduinoCoreBlockingStub(channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static ArduinoCoreFutureStub newFutureStub(
      io.grpc.Channel channel) {
    return new ArduinoCoreFutureStub(channel);
  }

  /**
   * <pre>
   * The main Arduino Platform Service
   * </pre>
   */
  public static abstract class ArduinoCoreImplBase implements io.grpc.BindableService {

    /**
     * <pre>
     * Start a new instance of the Arduino Core Service
     * </pre>
     */
    public void init(cc.arduino.cli.commands.Commands.InitReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.InitResp> responseObserver) {
      asyncUnimplementedUnaryCall(getInitMethod(), responseObserver);
    }

    /**
     * <pre>
     * Destroy an instance of the Arduino Core Service
     * </pre>
     */
    public void destroy(cc.arduino.cli.commands.Commands.DestroyReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.DestroyResp> responseObserver) {
      asyncUnimplementedUnaryCall(getDestroyMethod(), responseObserver);
    }

    /**
     * <pre>
     * Rescan instance of the Arduino Core Service
     * </pre>
     */
    public void rescan(cc.arduino.cli.commands.Commands.RescanReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.RescanResp> responseObserver) {
      asyncUnimplementedUnaryCall(getRescanMethod(), responseObserver);
    }

    /**
     * <pre>
     * Update package index of the Arduino Core Service
     * </pre>
     */
    public void updateIndex(cc.arduino.cli.commands.Commands.UpdateIndexReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.UpdateIndexResp> responseObserver) {
      asyncUnimplementedUnaryCall(getUpdateIndexMethod(), responseObserver);
    }

    /**
     * <pre>
     * Update libraries index
     * </pre>
     */
    public void updateLibrariesIndex(cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp> responseObserver) {
      asyncUnimplementedUnaryCall(getUpdateLibrariesIndexMethod(), responseObserver);
    }

    /**
     */
    public void version(cc.arduino.cli.commands.Commands.VersionReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.VersionResp> responseObserver) {
      asyncUnimplementedUnaryCall(getVersionMethod(), responseObserver);
    }

    /**
     * <pre>
     * Requests details about a board
     * </pre>
     */
    public void boardDetails(cc.arduino.cli.commands.Board.BoardDetailsReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardDetailsResp> responseObserver) {
      asyncUnimplementedUnaryCall(getBoardDetailsMethod(), responseObserver);
    }

    /**
     */
    public void boardAttach(cc.arduino.cli.commands.Board.BoardAttachReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardAttachResp> responseObserver) {
      asyncUnimplementedUnaryCall(getBoardAttachMethod(), responseObserver);
    }

    /**
     */
    public void boardList(cc.arduino.cli.commands.Board.BoardListReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardListResp> responseObserver) {
      asyncUnimplementedUnaryCall(getBoardListMethod(), responseObserver);
    }

    /**
     */
    public void boardListAll(cc.arduino.cli.commands.Board.BoardListAllReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardListAllResp> responseObserver) {
      asyncUnimplementedUnaryCall(getBoardListAllMethod(), responseObserver);
    }

    /**
     */
    public void compile(cc.arduino.cli.commands.Compile.CompileReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Compile.CompileResp> responseObserver) {
      asyncUnimplementedUnaryCall(getCompileMethod(), responseObserver);
    }

    /**
     */
    public void platformInstall(cc.arduino.cli.commands.Core.PlatformInstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformInstallResp> responseObserver) {
      asyncUnimplementedUnaryCall(getPlatformInstallMethod(), responseObserver);
    }

    /**
     */
    public void platformDownload(cc.arduino.cli.commands.Core.PlatformDownloadReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformDownloadResp> responseObserver) {
      asyncUnimplementedUnaryCall(getPlatformDownloadMethod(), responseObserver);
    }

    /**
     */
    public void platformUninstall(cc.arduino.cli.commands.Core.PlatformUninstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformUninstallResp> responseObserver) {
      asyncUnimplementedUnaryCall(getPlatformUninstallMethod(), responseObserver);
    }

    /**
     */
    public void platformUpgrade(cc.arduino.cli.commands.Core.PlatformUpgradeReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformUpgradeResp> responseObserver) {
      asyncUnimplementedUnaryCall(getPlatformUpgradeMethod(), responseObserver);
    }

    /**
     */
    public void upload(cc.arduino.cli.commands.Upload.UploadReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Upload.UploadResp> responseObserver) {
      asyncUnimplementedUnaryCall(getUploadMethod(), responseObserver);
    }

    /**
     */
    public void platformSearch(cc.arduino.cli.commands.Core.PlatformSearchReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformSearchResp> responseObserver) {
      asyncUnimplementedUnaryCall(getPlatformSearchMethod(), responseObserver);
    }

    /**
     */
    public void platformList(cc.arduino.cli.commands.Core.PlatformListReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformListResp> responseObserver) {
      asyncUnimplementedUnaryCall(getPlatformListMethod(), responseObserver);
    }

    /**
     */
    public void libraryDownload(cc.arduino.cli.commands.Lib.LibraryDownloadReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryDownloadResp> responseObserver) {
      asyncUnimplementedUnaryCall(getLibraryDownloadMethod(), responseObserver);
    }

    /**
     */
    public void libraryInstall(cc.arduino.cli.commands.Lib.LibraryInstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryInstallResp> responseObserver) {
      asyncUnimplementedUnaryCall(getLibraryInstallMethod(), responseObserver);
    }

    /**
     */
    public void libraryUninstall(cc.arduino.cli.commands.Lib.LibraryUninstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryUninstallResp> responseObserver) {
      asyncUnimplementedUnaryCall(getLibraryUninstallMethod(), responseObserver);
    }

    /**
     */
    public void libraryUpgradeAll(cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp> responseObserver) {
      asyncUnimplementedUnaryCall(getLibraryUpgradeAllMethod(), responseObserver);
    }

    /**
     */
    public void librarySearch(cc.arduino.cli.commands.Lib.LibrarySearchReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibrarySearchResp> responseObserver) {
      asyncUnimplementedUnaryCall(getLibrarySearchMethod(), responseObserver);
    }

    /**
     */
    public void libraryList(cc.arduino.cli.commands.Lib.LibraryListReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryListResp> responseObserver) {
      asyncUnimplementedUnaryCall(getLibraryListMethod(), responseObserver);
    }

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
          .addMethod(
            getInitMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Commands.InitReq,
                cc.arduino.cli.commands.Commands.InitResp>(
                  this, METHODID_INIT)))
          .addMethod(
            getDestroyMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Commands.DestroyReq,
                cc.arduino.cli.commands.Commands.DestroyResp>(
                  this, METHODID_DESTROY)))
          .addMethod(
            getRescanMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Commands.RescanReq,
                cc.arduino.cli.commands.Commands.RescanResp>(
                  this, METHODID_RESCAN)))
          .addMethod(
            getUpdateIndexMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Commands.UpdateIndexReq,
                cc.arduino.cli.commands.Commands.UpdateIndexResp>(
                  this, METHODID_UPDATE_INDEX)))
          .addMethod(
            getUpdateLibrariesIndexMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq,
                cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp>(
                  this, METHODID_UPDATE_LIBRARIES_INDEX)))
          .addMethod(
            getVersionMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Commands.VersionReq,
                cc.arduino.cli.commands.Commands.VersionResp>(
                  this, METHODID_VERSION)))
          .addMethod(
            getBoardDetailsMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Board.BoardDetailsReq,
                cc.arduino.cli.commands.Board.BoardDetailsResp>(
                  this, METHODID_BOARD_DETAILS)))
          .addMethod(
            getBoardAttachMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Board.BoardAttachReq,
                cc.arduino.cli.commands.Board.BoardAttachResp>(
                  this, METHODID_BOARD_ATTACH)))
          .addMethod(
            getBoardListMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Board.BoardListReq,
                cc.arduino.cli.commands.Board.BoardListResp>(
                  this, METHODID_BOARD_LIST)))
          .addMethod(
            getBoardListAllMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Board.BoardListAllReq,
                cc.arduino.cli.commands.Board.BoardListAllResp>(
                  this, METHODID_BOARD_LIST_ALL)))
          .addMethod(
            getCompileMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Compile.CompileReq,
                cc.arduino.cli.commands.Compile.CompileResp>(
                  this, METHODID_COMPILE)))
          .addMethod(
            getPlatformInstallMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Core.PlatformInstallReq,
                cc.arduino.cli.commands.Core.PlatformInstallResp>(
                  this, METHODID_PLATFORM_INSTALL)))
          .addMethod(
            getPlatformDownloadMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Core.PlatformDownloadReq,
                cc.arduino.cli.commands.Core.PlatformDownloadResp>(
                  this, METHODID_PLATFORM_DOWNLOAD)))
          .addMethod(
            getPlatformUninstallMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Core.PlatformUninstallReq,
                cc.arduino.cli.commands.Core.PlatformUninstallResp>(
                  this, METHODID_PLATFORM_UNINSTALL)))
          .addMethod(
            getPlatformUpgradeMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Core.PlatformUpgradeReq,
                cc.arduino.cli.commands.Core.PlatformUpgradeResp>(
                  this, METHODID_PLATFORM_UPGRADE)))
          .addMethod(
            getUploadMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Upload.UploadReq,
                cc.arduino.cli.commands.Upload.UploadResp>(
                  this, METHODID_UPLOAD)))
          .addMethod(
            getPlatformSearchMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Core.PlatformSearchReq,
                cc.arduino.cli.commands.Core.PlatformSearchResp>(
                  this, METHODID_PLATFORM_SEARCH)))
          .addMethod(
            getPlatformListMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Core.PlatformListReq,
                cc.arduino.cli.commands.Core.PlatformListResp>(
                  this, METHODID_PLATFORM_LIST)))
          .addMethod(
            getLibraryDownloadMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Lib.LibraryDownloadReq,
                cc.arduino.cli.commands.Lib.LibraryDownloadResp>(
                  this, METHODID_LIBRARY_DOWNLOAD)))
          .addMethod(
            getLibraryInstallMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Lib.LibraryInstallReq,
                cc.arduino.cli.commands.Lib.LibraryInstallResp>(
                  this, METHODID_LIBRARY_INSTALL)))
          .addMethod(
            getLibraryUninstallMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Lib.LibraryUninstallReq,
                cc.arduino.cli.commands.Lib.LibraryUninstallResp>(
                  this, METHODID_LIBRARY_UNINSTALL)))
          .addMethod(
            getLibraryUpgradeAllMethod(),
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq,
                cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp>(
                  this, METHODID_LIBRARY_UPGRADE_ALL)))
          .addMethod(
            getLibrarySearchMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Lib.LibrarySearchReq,
                cc.arduino.cli.commands.Lib.LibrarySearchResp>(
                  this, METHODID_LIBRARY_SEARCH)))
          .addMethod(
            getLibraryListMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.commands.Lib.LibraryListReq,
                cc.arduino.cli.commands.Lib.LibraryListResp>(
                  this, METHODID_LIBRARY_LIST)))
          .build();
    }
  }

  /**
   * <pre>
   * The main Arduino Platform Service
   * </pre>
   */
  public static final class ArduinoCoreStub extends io.grpc.stub.AbstractStub<ArduinoCoreStub> {
    private ArduinoCoreStub(io.grpc.Channel channel) {
      super(channel);
    }

    private ArduinoCoreStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected ArduinoCoreStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new ArduinoCoreStub(channel, callOptions);
    }

    /**
     * <pre>
     * Start a new instance of the Arduino Core Service
     * </pre>
     */
    public void init(cc.arduino.cli.commands.Commands.InitReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.InitResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getInitMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Destroy an instance of the Arduino Core Service
     * </pre>
     */
    public void destroy(cc.arduino.cli.commands.Commands.DestroyReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.DestroyResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getDestroyMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Rescan instance of the Arduino Core Service
     * </pre>
     */
    public void rescan(cc.arduino.cli.commands.Commands.RescanReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.RescanResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getRescanMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Update package index of the Arduino Core Service
     * </pre>
     */
    public void updateIndex(cc.arduino.cli.commands.Commands.UpdateIndexReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.UpdateIndexResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getUpdateIndexMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Update libraries index
     * </pre>
     */
    public void updateLibrariesIndex(cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getUpdateLibrariesIndexMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void version(cc.arduino.cli.commands.Commands.VersionReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.VersionResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getVersionMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Requests details about a board
     * </pre>
     */
    public void boardDetails(cc.arduino.cli.commands.Board.BoardDetailsReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardDetailsResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getBoardDetailsMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void boardAttach(cc.arduino.cli.commands.Board.BoardAttachReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardAttachResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getBoardAttachMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void boardList(cc.arduino.cli.commands.Board.BoardListReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardListResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getBoardListMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void boardListAll(cc.arduino.cli.commands.Board.BoardListAllReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardListAllResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getBoardListAllMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void compile(cc.arduino.cli.commands.Compile.CompileReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Compile.CompileResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getCompileMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void platformInstall(cc.arduino.cli.commands.Core.PlatformInstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformInstallResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getPlatformInstallMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void platformDownload(cc.arduino.cli.commands.Core.PlatformDownloadReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformDownloadResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getPlatformDownloadMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void platformUninstall(cc.arduino.cli.commands.Core.PlatformUninstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformUninstallResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getPlatformUninstallMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void platformUpgrade(cc.arduino.cli.commands.Core.PlatformUpgradeReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformUpgradeResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getPlatformUpgradeMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void upload(cc.arduino.cli.commands.Upload.UploadReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Upload.UploadResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getUploadMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void platformSearch(cc.arduino.cli.commands.Core.PlatformSearchReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformSearchResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getPlatformSearchMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void platformList(cc.arduino.cli.commands.Core.PlatformListReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformListResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getPlatformListMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void libraryDownload(cc.arduino.cli.commands.Lib.LibraryDownloadReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryDownloadResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getLibraryDownloadMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void libraryInstall(cc.arduino.cli.commands.Lib.LibraryInstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryInstallResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getLibraryInstallMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void libraryUninstall(cc.arduino.cli.commands.Lib.LibraryUninstallReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryUninstallResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getLibraryUninstallMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void libraryUpgradeAll(cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(getLibraryUpgradeAllMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void librarySearch(cc.arduino.cli.commands.Lib.LibrarySearchReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibrarySearchResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getLibrarySearchMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void libraryList(cc.arduino.cli.commands.Lib.LibraryListReq request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryListResp> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getLibraryListMethod(), getCallOptions()), request, responseObserver);
    }
  }

  /**
   * <pre>
   * The main Arduino Platform Service
   * </pre>
   */
  public static final class ArduinoCoreBlockingStub extends io.grpc.stub.AbstractStub<ArduinoCoreBlockingStub> {
    private ArduinoCoreBlockingStub(io.grpc.Channel channel) {
      super(channel);
    }

    private ArduinoCoreBlockingStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected ArduinoCoreBlockingStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new ArduinoCoreBlockingStub(channel, callOptions);
    }

    /**
     * <pre>
     * Start a new instance of the Arduino Core Service
     * </pre>
     */
    public java.util.Iterator<cc.arduino.cli.commands.Commands.InitResp> init(
        cc.arduino.cli.commands.Commands.InitReq request) {
      return blockingServerStreamingCall(
          getChannel(), getInitMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Destroy an instance of the Arduino Core Service
     * </pre>
     */
    public cc.arduino.cli.commands.Commands.DestroyResp destroy(cc.arduino.cli.commands.Commands.DestroyReq request) {
      return blockingUnaryCall(
          getChannel(), getDestroyMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Rescan instance of the Arduino Core Service
     * </pre>
     */
    public cc.arduino.cli.commands.Commands.RescanResp rescan(cc.arduino.cli.commands.Commands.RescanReq request) {
      return blockingUnaryCall(
          getChannel(), getRescanMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Update package index of the Arduino Core Service
     * </pre>
     */
    public java.util.Iterator<cc.arduino.cli.commands.Commands.UpdateIndexResp> updateIndex(
        cc.arduino.cli.commands.Commands.UpdateIndexReq request) {
      return blockingServerStreamingCall(
          getChannel(), getUpdateIndexMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Update libraries index
     * </pre>
     */
    public java.util.Iterator<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp> updateLibrariesIndex(
        cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq request) {
      return blockingServerStreamingCall(
          getChannel(), getUpdateLibrariesIndexMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Commands.VersionResp version(cc.arduino.cli.commands.Commands.VersionReq request) {
      return blockingUnaryCall(
          getChannel(), getVersionMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Requests details about a board
     * </pre>
     */
    public cc.arduino.cli.commands.Board.BoardDetailsResp boardDetails(cc.arduino.cli.commands.Board.BoardDetailsReq request) {
      return blockingUnaryCall(
          getChannel(), getBoardDetailsMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Board.BoardAttachResp> boardAttach(
        cc.arduino.cli.commands.Board.BoardAttachReq request) {
      return blockingServerStreamingCall(
          getChannel(), getBoardAttachMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Board.BoardListResp boardList(cc.arduino.cli.commands.Board.BoardListReq request) {
      return blockingUnaryCall(
          getChannel(), getBoardListMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Board.BoardListAllResp boardListAll(cc.arduino.cli.commands.Board.BoardListAllReq request) {
      return blockingUnaryCall(
          getChannel(), getBoardListAllMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Compile.CompileResp> compile(
        cc.arduino.cli.commands.Compile.CompileReq request) {
      return blockingServerStreamingCall(
          getChannel(), getCompileMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Core.PlatformInstallResp> platformInstall(
        cc.arduino.cli.commands.Core.PlatformInstallReq request) {
      return blockingServerStreamingCall(
          getChannel(), getPlatformInstallMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Core.PlatformDownloadResp> platformDownload(
        cc.arduino.cli.commands.Core.PlatformDownloadReq request) {
      return blockingServerStreamingCall(
          getChannel(), getPlatformDownloadMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Core.PlatformUninstallResp> platformUninstall(
        cc.arduino.cli.commands.Core.PlatformUninstallReq request) {
      return blockingServerStreamingCall(
          getChannel(), getPlatformUninstallMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Core.PlatformUpgradeResp> platformUpgrade(
        cc.arduino.cli.commands.Core.PlatformUpgradeReq request) {
      return blockingServerStreamingCall(
          getChannel(), getPlatformUpgradeMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Upload.UploadResp> upload(
        cc.arduino.cli.commands.Upload.UploadReq request) {
      return blockingServerStreamingCall(
          getChannel(), getUploadMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Core.PlatformSearchResp platformSearch(cc.arduino.cli.commands.Core.PlatformSearchReq request) {
      return blockingUnaryCall(
          getChannel(), getPlatformSearchMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Core.PlatformListResp platformList(cc.arduino.cli.commands.Core.PlatformListReq request) {
      return blockingUnaryCall(
          getChannel(), getPlatformListMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Lib.LibraryDownloadResp> libraryDownload(
        cc.arduino.cli.commands.Lib.LibraryDownloadReq request) {
      return blockingServerStreamingCall(
          getChannel(), getLibraryDownloadMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Lib.LibraryInstallResp> libraryInstall(
        cc.arduino.cli.commands.Lib.LibraryInstallReq request) {
      return blockingServerStreamingCall(
          getChannel(), getLibraryInstallMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Lib.LibraryUninstallResp> libraryUninstall(
        cc.arduino.cli.commands.Lib.LibraryUninstallReq request) {
      return blockingServerStreamingCall(
          getChannel(), getLibraryUninstallMethod(), getCallOptions(), request);
    }

    /**
     */
    public java.util.Iterator<cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp> libraryUpgradeAll(
        cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq request) {
      return blockingServerStreamingCall(
          getChannel(), getLibraryUpgradeAllMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Lib.LibrarySearchResp librarySearch(cc.arduino.cli.commands.Lib.LibrarySearchReq request) {
      return blockingUnaryCall(
          getChannel(), getLibrarySearchMethod(), getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.cli.commands.Lib.LibraryListResp libraryList(cc.arduino.cli.commands.Lib.LibraryListReq request) {
      return blockingUnaryCall(
          getChannel(), getLibraryListMethod(), getCallOptions(), request);
    }
  }

  /**
   * <pre>
   * The main Arduino Platform Service
   * </pre>
   */
  public static final class ArduinoCoreFutureStub extends io.grpc.stub.AbstractStub<ArduinoCoreFutureStub> {
    private ArduinoCoreFutureStub(io.grpc.Channel channel) {
      super(channel);
    }

    private ArduinoCoreFutureStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected ArduinoCoreFutureStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new ArduinoCoreFutureStub(channel, callOptions);
    }

    /**
     * <pre>
     * Destroy an instance of the Arduino Core Service
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Commands.DestroyResp> destroy(
        cc.arduino.cli.commands.Commands.DestroyReq request) {
      return futureUnaryCall(
          getChannel().newCall(getDestroyMethod(), getCallOptions()), request);
    }

    /**
     * <pre>
     * Rescan instance of the Arduino Core Service
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Commands.RescanResp> rescan(
        cc.arduino.cli.commands.Commands.RescanReq request) {
      return futureUnaryCall(
          getChannel().newCall(getRescanMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Commands.VersionResp> version(
        cc.arduino.cli.commands.Commands.VersionReq request) {
      return futureUnaryCall(
          getChannel().newCall(getVersionMethod(), getCallOptions()), request);
    }

    /**
     * <pre>
     * Requests details about a board
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Board.BoardDetailsResp> boardDetails(
        cc.arduino.cli.commands.Board.BoardDetailsReq request) {
      return futureUnaryCall(
          getChannel().newCall(getBoardDetailsMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Board.BoardListResp> boardList(
        cc.arduino.cli.commands.Board.BoardListReq request) {
      return futureUnaryCall(
          getChannel().newCall(getBoardListMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Board.BoardListAllResp> boardListAll(
        cc.arduino.cli.commands.Board.BoardListAllReq request) {
      return futureUnaryCall(
          getChannel().newCall(getBoardListAllMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Core.PlatformSearchResp> platformSearch(
        cc.arduino.cli.commands.Core.PlatformSearchReq request) {
      return futureUnaryCall(
          getChannel().newCall(getPlatformSearchMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Core.PlatformListResp> platformList(
        cc.arduino.cli.commands.Core.PlatformListReq request) {
      return futureUnaryCall(
          getChannel().newCall(getPlatformListMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Lib.LibrarySearchResp> librarySearch(
        cc.arduino.cli.commands.Lib.LibrarySearchReq request) {
      return futureUnaryCall(
          getChannel().newCall(getLibrarySearchMethod(), getCallOptions()), request);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.commands.Lib.LibraryListResp> libraryList(
        cc.arduino.cli.commands.Lib.LibraryListReq request) {
      return futureUnaryCall(
          getChannel().newCall(getLibraryListMethod(), getCallOptions()), request);
    }
  }

  private static final int METHODID_INIT = 0;
  private static final int METHODID_DESTROY = 1;
  private static final int METHODID_RESCAN = 2;
  private static final int METHODID_UPDATE_INDEX = 3;
  private static final int METHODID_UPDATE_LIBRARIES_INDEX = 4;
  private static final int METHODID_VERSION = 5;
  private static final int METHODID_BOARD_DETAILS = 6;
  private static final int METHODID_BOARD_ATTACH = 7;
  private static final int METHODID_BOARD_LIST = 8;
  private static final int METHODID_BOARD_LIST_ALL = 9;
  private static final int METHODID_COMPILE = 10;
  private static final int METHODID_PLATFORM_INSTALL = 11;
  private static final int METHODID_PLATFORM_DOWNLOAD = 12;
  private static final int METHODID_PLATFORM_UNINSTALL = 13;
  private static final int METHODID_PLATFORM_UPGRADE = 14;
  private static final int METHODID_UPLOAD = 15;
  private static final int METHODID_PLATFORM_SEARCH = 16;
  private static final int METHODID_PLATFORM_LIST = 17;
  private static final int METHODID_LIBRARY_DOWNLOAD = 18;
  private static final int METHODID_LIBRARY_INSTALL = 19;
  private static final int METHODID_LIBRARY_UNINSTALL = 20;
  private static final int METHODID_LIBRARY_UPGRADE_ALL = 21;
  private static final int METHODID_LIBRARY_SEARCH = 22;
  private static final int METHODID_LIBRARY_LIST = 23;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final ArduinoCoreImplBase serviceImpl;
    private final int methodId;

    MethodHandlers(ArduinoCoreImplBase serviceImpl, int methodId) {
      this.serviceImpl = serviceImpl;
      this.methodId = methodId;
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public void invoke(Req request, io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        case METHODID_INIT:
          serviceImpl.init((cc.arduino.cli.commands.Commands.InitReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.InitResp>) responseObserver);
          break;
        case METHODID_DESTROY:
          serviceImpl.destroy((cc.arduino.cli.commands.Commands.DestroyReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.DestroyResp>) responseObserver);
          break;
        case METHODID_RESCAN:
          serviceImpl.rescan((cc.arduino.cli.commands.Commands.RescanReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.RescanResp>) responseObserver);
          break;
        case METHODID_UPDATE_INDEX:
          serviceImpl.updateIndex((cc.arduino.cli.commands.Commands.UpdateIndexReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.UpdateIndexResp>) responseObserver);
          break;
        case METHODID_UPDATE_LIBRARIES_INDEX:
          serviceImpl.updateLibrariesIndex((cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp>) responseObserver);
          break;
        case METHODID_VERSION:
          serviceImpl.version((cc.arduino.cli.commands.Commands.VersionReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Commands.VersionResp>) responseObserver);
          break;
        case METHODID_BOARD_DETAILS:
          serviceImpl.boardDetails((cc.arduino.cli.commands.Board.BoardDetailsReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardDetailsResp>) responseObserver);
          break;
        case METHODID_BOARD_ATTACH:
          serviceImpl.boardAttach((cc.arduino.cli.commands.Board.BoardAttachReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardAttachResp>) responseObserver);
          break;
        case METHODID_BOARD_LIST:
          serviceImpl.boardList((cc.arduino.cli.commands.Board.BoardListReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardListResp>) responseObserver);
          break;
        case METHODID_BOARD_LIST_ALL:
          serviceImpl.boardListAll((cc.arduino.cli.commands.Board.BoardListAllReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Board.BoardListAllResp>) responseObserver);
          break;
        case METHODID_COMPILE:
          serviceImpl.compile((cc.arduino.cli.commands.Compile.CompileReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Compile.CompileResp>) responseObserver);
          break;
        case METHODID_PLATFORM_INSTALL:
          serviceImpl.platformInstall((cc.arduino.cli.commands.Core.PlatformInstallReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformInstallResp>) responseObserver);
          break;
        case METHODID_PLATFORM_DOWNLOAD:
          serviceImpl.platformDownload((cc.arduino.cli.commands.Core.PlatformDownloadReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformDownloadResp>) responseObserver);
          break;
        case METHODID_PLATFORM_UNINSTALL:
          serviceImpl.platformUninstall((cc.arduino.cli.commands.Core.PlatformUninstallReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformUninstallResp>) responseObserver);
          break;
        case METHODID_PLATFORM_UPGRADE:
          serviceImpl.platformUpgrade((cc.arduino.cli.commands.Core.PlatformUpgradeReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformUpgradeResp>) responseObserver);
          break;
        case METHODID_UPLOAD:
          serviceImpl.upload((cc.arduino.cli.commands.Upload.UploadReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Upload.UploadResp>) responseObserver);
          break;
        case METHODID_PLATFORM_SEARCH:
          serviceImpl.platformSearch((cc.arduino.cli.commands.Core.PlatformSearchReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformSearchResp>) responseObserver);
          break;
        case METHODID_PLATFORM_LIST:
          serviceImpl.platformList((cc.arduino.cli.commands.Core.PlatformListReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Core.PlatformListResp>) responseObserver);
          break;
        case METHODID_LIBRARY_DOWNLOAD:
          serviceImpl.libraryDownload((cc.arduino.cli.commands.Lib.LibraryDownloadReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryDownloadResp>) responseObserver);
          break;
        case METHODID_LIBRARY_INSTALL:
          serviceImpl.libraryInstall((cc.arduino.cli.commands.Lib.LibraryInstallReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryInstallResp>) responseObserver);
          break;
        case METHODID_LIBRARY_UNINSTALL:
          serviceImpl.libraryUninstall((cc.arduino.cli.commands.Lib.LibraryUninstallReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryUninstallResp>) responseObserver);
          break;
        case METHODID_LIBRARY_UPGRADE_ALL:
          serviceImpl.libraryUpgradeAll((cc.arduino.cli.commands.Lib.LibraryUpgradeAllReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryUpgradeAllResp>) responseObserver);
          break;
        case METHODID_LIBRARY_SEARCH:
          serviceImpl.librarySearch((cc.arduino.cli.commands.Lib.LibrarySearchReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibrarySearchResp>) responseObserver);
          break;
        case METHODID_LIBRARY_LIST:
          serviceImpl.libraryList((cc.arduino.cli.commands.Lib.LibraryListReq) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.commands.Lib.LibraryListResp>) responseObserver);
          break;
        default:
          throw new AssertionError();
      }
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public io.grpc.stub.StreamObserver<Req> invoke(
        io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        default:
          throw new AssertionError();
      }
    }
  }

  private static abstract class ArduinoCoreBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoFileDescriptorSupplier, io.grpc.protobuf.ProtoServiceDescriptorSupplier {
    ArduinoCoreBaseDescriptorSupplier() {}

    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return cc.arduino.cli.commands.Commands.getDescriptor();
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.ServiceDescriptor getServiceDescriptor() {
      return getFileDescriptor().findServiceByName("ArduinoCore");
    }
  }

  private static final class ArduinoCoreFileDescriptorSupplier
      extends ArduinoCoreBaseDescriptorSupplier {
    ArduinoCoreFileDescriptorSupplier() {}
  }

  private static final class ArduinoCoreMethodDescriptorSupplier
      extends ArduinoCoreBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoMethodDescriptorSupplier {
    private final String methodName;

    ArduinoCoreMethodDescriptorSupplier(String methodName) {
      this.methodName = methodName;
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.MethodDescriptor getMethodDescriptor() {
      return getServiceDescriptor().findMethodByName(methodName);
    }
  }

  private static volatile io.grpc.ServiceDescriptor serviceDescriptor;

  public static io.grpc.ServiceDescriptor getServiceDescriptor() {
    io.grpc.ServiceDescriptor result = serviceDescriptor;
    if (result == null) {
      synchronized (ArduinoCoreGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new ArduinoCoreFileDescriptorSupplier())
              .addMethod(getInitMethod())
              .addMethod(getDestroyMethod())
              .addMethod(getRescanMethod())
              .addMethod(getUpdateIndexMethod())
              .addMethod(getUpdateLibrariesIndexMethod())
              .addMethod(getVersionMethod())
              .addMethod(getBoardDetailsMethod())
              .addMethod(getBoardAttachMethod())
              .addMethod(getBoardListMethod())
              .addMethod(getBoardListAllMethod())
              .addMethod(getCompileMethod())
              .addMethod(getPlatformInstallMethod())
              .addMethod(getPlatformDownloadMethod())
              .addMethod(getPlatformUninstallMethod())
              .addMethod(getPlatformUpgradeMethod())
              .addMethod(getUploadMethod())
              .addMethod(getPlatformSearchMethod())
              .addMethod(getPlatformListMethod())
              .addMethod(getLibraryDownloadMethod())
              .addMethod(getLibraryInstallMethod())
              .addMethod(getLibraryUninstallMethod())
              .addMethod(getLibraryUpgradeAllMethod())
              .addMethod(getLibrarySearchMethod())
              .addMethod(getLibraryListMethod())
              .build();
        }
      }
    }
    return result;
  }
}
