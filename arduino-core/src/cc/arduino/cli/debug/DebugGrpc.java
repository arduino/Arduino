package cc.arduino.cli.debug;

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
 * Service that abstract a debug Session usage
 * </pre>
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.20.0)",
    comments = "Source: debug/debug.proto")
public final class DebugGrpc {

  private DebugGrpc() {}

  public static final String SERVICE_NAME = "cc.arduino.cli.debug.Debug";

  // Static method descriptors that strictly reflect the proto.
  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.debug.DebugOuterClass.DebugReq,
      cc.arduino.cli.debug.DebugOuterClass.DebugResp> getDebugMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Debug",
      requestType = cc.arduino.cli.debug.DebugOuterClass.DebugReq.class,
      responseType = cc.arduino.cli.debug.DebugOuterClass.DebugResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.BIDI_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.debug.DebugOuterClass.DebugReq,
      cc.arduino.cli.debug.DebugOuterClass.DebugResp> getDebugMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.debug.DebugOuterClass.DebugReq, cc.arduino.cli.debug.DebugOuterClass.DebugResp> getDebugMethod;
    if ((getDebugMethod = DebugGrpc.getDebugMethod) == null) {
      synchronized (DebugGrpc.class) {
        if ((getDebugMethod = DebugGrpc.getDebugMethod) == null) {
          DebugGrpc.getDebugMethod = getDebugMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.debug.DebugOuterClass.DebugReq, cc.arduino.cli.debug.DebugOuterClass.DebugResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.BIDI_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.debug.Debug", "Debug"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.debug.DebugOuterClass.DebugReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.debug.DebugOuterClass.DebugResp.getDefaultInstance()))
                  .setSchemaDescriptor(new DebugMethodDescriptorSupplier("Debug"))
                  .build();
          }
        }
     }
     return getDebugMethod;
  }

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static DebugStub newStub(io.grpc.Channel channel) {
    return new DebugStub(channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static DebugBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    return new DebugBlockingStub(channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static DebugFutureStub newFutureStub(
      io.grpc.Channel channel) {
    return new DebugFutureStub(channel);
  }

  /**
   * <pre>
   * Service that abstract a debug Session usage
   * </pre>
   */
  public static abstract class DebugImplBase implements io.grpc.BindableService {

    /**
     * <pre>
     * Start a debug session and communicate with the debugger tool.
     * </pre>
     */
    public io.grpc.stub.StreamObserver<cc.arduino.cli.debug.DebugOuterClass.DebugReq> debug(
        io.grpc.stub.StreamObserver<cc.arduino.cli.debug.DebugOuterClass.DebugResp> responseObserver) {
      return asyncUnimplementedStreamingCall(getDebugMethod(), responseObserver);
    }

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
          .addMethod(
            getDebugMethod(),
            asyncBidiStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.debug.DebugOuterClass.DebugReq,
                cc.arduino.cli.debug.DebugOuterClass.DebugResp>(
                  this, METHODID_DEBUG)))
          .build();
    }
  }

  /**
   * <pre>
   * Service that abstract a debug Session usage
   * </pre>
   */
  public static final class DebugStub extends io.grpc.stub.AbstractStub<DebugStub> {
    private DebugStub(io.grpc.Channel channel) {
      super(channel);
    }

    private DebugStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected DebugStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new DebugStub(channel, callOptions);
    }

    /**
     * <pre>
     * Start a debug session and communicate with the debugger tool.
     * </pre>
     */
    public io.grpc.stub.StreamObserver<cc.arduino.cli.debug.DebugOuterClass.DebugReq> debug(
        io.grpc.stub.StreamObserver<cc.arduino.cli.debug.DebugOuterClass.DebugResp> responseObserver) {
      return asyncBidiStreamingCall(
          getChannel().newCall(getDebugMethod(), getCallOptions()), responseObserver);
    }
  }

  /**
   * <pre>
   * Service that abstract a debug Session usage
   * </pre>
   */
  public static final class DebugBlockingStub extends io.grpc.stub.AbstractStub<DebugBlockingStub> {
    private DebugBlockingStub(io.grpc.Channel channel) {
      super(channel);
    }

    private DebugBlockingStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected DebugBlockingStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new DebugBlockingStub(channel, callOptions);
    }
  }

  /**
   * <pre>
   * Service that abstract a debug Session usage
   * </pre>
   */
  public static final class DebugFutureStub extends io.grpc.stub.AbstractStub<DebugFutureStub> {
    private DebugFutureStub(io.grpc.Channel channel) {
      super(channel);
    }

    private DebugFutureStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected DebugFutureStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new DebugFutureStub(channel, callOptions);
    }
  }

  private static final int METHODID_DEBUG = 0;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final DebugImplBase serviceImpl;
    private final int methodId;

    MethodHandlers(DebugImplBase serviceImpl, int methodId) {
      this.serviceImpl = serviceImpl;
      this.methodId = methodId;
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public void invoke(Req request, io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        default:
          throw new AssertionError();
      }
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public io.grpc.stub.StreamObserver<Req> invoke(
        io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        case METHODID_DEBUG:
          return (io.grpc.stub.StreamObserver<Req>) serviceImpl.debug(
              (io.grpc.stub.StreamObserver<cc.arduino.cli.debug.DebugOuterClass.DebugResp>) responseObserver);
        default:
          throw new AssertionError();
      }
    }
  }

  private static abstract class DebugBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoFileDescriptorSupplier, io.grpc.protobuf.ProtoServiceDescriptorSupplier {
    DebugBaseDescriptorSupplier() {}

    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return cc.arduino.cli.debug.DebugOuterClass.getDescriptor();
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.ServiceDescriptor getServiceDescriptor() {
      return getFileDescriptor().findServiceByName("Debug");
    }
  }

  private static final class DebugFileDescriptorSupplier
      extends DebugBaseDescriptorSupplier {
    DebugFileDescriptorSupplier() {}
  }

  private static final class DebugMethodDescriptorSupplier
      extends DebugBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoMethodDescriptorSupplier {
    private final String methodName;

    DebugMethodDescriptorSupplier(String methodName) {
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
      synchronized (DebugGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new DebugFileDescriptorSupplier())
              .addMethod(getDebugMethod())
              .build();
        }
      }
    }
    return result;
  }
}
