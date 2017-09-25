package cc.arduino.builder;

import static io.grpc.MethodDescriptor.generateFullMethodName;
import static io.grpc.stub.ClientCalls.asyncServerStreamingCall;
import static io.grpc.stub.ClientCalls.asyncUnaryCall;
import static io.grpc.stub.ClientCalls.blockingServerStreamingCall;
import static io.grpc.stub.ClientCalls.blockingUnaryCall;
import static io.grpc.stub.ClientCalls.futureUnaryCall;
import static io.grpc.stub.ServerCalls.asyncServerStreamingCall;
import static io.grpc.stub.ServerCalls.asyncUnaryCall;
import static io.grpc.stub.ServerCalls.asyncUnimplementedUnaryCall;

/**
 * <pre>
 * Interface exported by the server.
 * </pre>
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.6.1)",
    comments = "Source: builder.proto")
public final class BuilderGrpc {

  private BuilderGrpc() {}

  public static final String SERVICE_NAME = "proto.Builder";

  // Static method descriptors that strictly reflect the proto.
  @io.grpc.ExperimentalApi("https://github.com/grpc/grpc-java/issues/1901")
  public static final io.grpc.MethodDescriptor<cc.arduino.builder.BuildParams,
      cc.arduino.builder.Response> METHOD_BUILD =
      io.grpc.MethodDescriptor.<cc.arduino.builder.BuildParams, cc.arduino.builder.Response>newBuilder()
          .setType(io.grpc.MethodDescriptor.MethodType.SERVER_STREAMING)
          .setFullMethodName(generateFullMethodName(
              "proto.Builder", "Build"))
          .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
              cc.arduino.builder.BuildParams.getDefaultInstance()))
          .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
              cc.arduino.builder.Response.getDefaultInstance()))
          .build();
  @io.grpc.ExperimentalApi("https://github.com/grpc/grpc-java/issues/1901")
  public static final io.grpc.MethodDescriptor<cc.arduino.builder.BuildParams,
      cc.arduino.builder.Response> METHOD_AUTOCOMPLETE =
      io.grpc.MethodDescriptor.<cc.arduino.builder.BuildParams, cc.arduino.builder.Response>newBuilder()
          .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
          .setFullMethodName(generateFullMethodName(
              "proto.Builder", "Autocomplete"))
          .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
              cc.arduino.builder.BuildParams.getDefaultInstance()))
          .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
              cc.arduino.builder.Response.getDefaultInstance()))
          .build();

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static BuilderStub newStub(io.grpc.Channel channel) {
    return new BuilderStub(channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static BuilderBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    return new BuilderBlockingStub(channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static BuilderFutureStub newFutureStub(
      io.grpc.Channel channel) {
    return new BuilderFutureStub(channel);
  }

  /**
   * <pre>
   * Interface exported by the server.
   * </pre>
   */
  public static abstract class BuilderImplBase implements io.grpc.BindableService {

    /**
     * <pre>
     * A server-to-client streaming RPC.
     * Obtains the Features available within the given Rectangle.  Results are
     * streamed rather than returned at once (e.g. in a response message with a
     * repeated field), as the rectangle may cover a large area and contain a
     * huge number of features.
     * </pre>
     */
    public void build(cc.arduino.builder.BuildParams request,
        io.grpc.stub.StreamObserver<cc.arduino.builder.Response> responseObserver) {
      asyncUnimplementedUnaryCall(METHOD_BUILD, responseObserver);
    }

    /**
     */
    public void autocomplete(cc.arduino.builder.BuildParams request,
        io.grpc.stub.StreamObserver<cc.arduino.builder.Response> responseObserver) {
      asyncUnimplementedUnaryCall(METHOD_AUTOCOMPLETE, responseObserver);
    }

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
          .addMethod(
            METHOD_BUILD,
            asyncServerStreamingCall(
              new MethodHandlers<
                cc.arduino.builder.BuildParams,
                cc.arduino.builder.Response>(
                  this, METHODID_BUILD)))
          .addMethod(
            METHOD_AUTOCOMPLETE,
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.builder.BuildParams,
                cc.arduino.builder.Response>(
                  this, METHODID_AUTOCOMPLETE)))
          .build();
    }
  }

  /**
   * <pre>
   * Interface exported by the server.
   * </pre>
   */
  public static final class BuilderStub extends io.grpc.stub.AbstractStub<BuilderStub> {
    private BuilderStub(io.grpc.Channel channel) {
      super(channel);
    }

    private BuilderStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected BuilderStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new BuilderStub(channel, callOptions);
    }

    /**
     * <pre>
     * A server-to-client streaming RPC.
     * Obtains the Features available within the given Rectangle.  Results are
     * streamed rather than returned at once (e.g. in a response message with a
     * repeated field), as the rectangle may cover a large area and contain a
     * huge number of features.
     * </pre>
     */
    public void build(cc.arduino.builder.BuildParams request,
        io.grpc.stub.StreamObserver<cc.arduino.builder.Response> responseObserver) {
      asyncServerStreamingCall(
          getChannel().newCall(METHOD_BUILD, getCallOptions()), request, responseObserver);
    }

    /**
     */
    public void autocomplete(cc.arduino.builder.BuildParams request,
        io.grpc.stub.StreamObserver<cc.arduino.builder.Response> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(METHOD_AUTOCOMPLETE, getCallOptions()), request, responseObserver);
    }
  }

  /**
   * <pre>
   * Interface exported by the server.
   * </pre>
   */
  public static final class BuilderBlockingStub extends io.grpc.stub.AbstractStub<BuilderBlockingStub> {
    private BuilderBlockingStub(io.grpc.Channel channel) {
      super(channel);
    }

    private BuilderBlockingStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected BuilderBlockingStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new BuilderBlockingStub(channel, callOptions);
    }

    /**
     * <pre>
     * A server-to-client streaming RPC.
     * Obtains the Features available within the given Rectangle.  Results are
     * streamed rather than returned at once (e.g. in a response message with a
     * repeated field), as the rectangle may cover a large area and contain a
     * huge number of features.
     * </pre>
     */
    public java.util.Iterator<cc.arduino.builder.Response> build(
        cc.arduino.builder.BuildParams request) {
      return blockingServerStreamingCall(
          getChannel(), METHOD_BUILD, getCallOptions(), request);
    }

    /**
     */
    public cc.arduino.builder.Response autocomplete(cc.arduino.builder.BuildParams request) {
      return blockingUnaryCall(
          getChannel(), METHOD_AUTOCOMPLETE, getCallOptions(), request);
    }
  }

  /**
   * <pre>
   * Interface exported by the server.
   * </pre>
   */
  public static final class BuilderFutureStub extends io.grpc.stub.AbstractStub<BuilderFutureStub> {
    private BuilderFutureStub(io.grpc.Channel channel) {
      super(channel);
    }

    private BuilderFutureStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected BuilderFutureStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new BuilderFutureStub(channel, callOptions);
    }

    /**
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.builder.Response> autocomplete(
        cc.arduino.builder.BuildParams request) {
      return futureUnaryCall(
          getChannel().newCall(METHOD_AUTOCOMPLETE, getCallOptions()), request);
    }
  }

  private static final int METHODID_BUILD = 0;
  private static final int METHODID_AUTOCOMPLETE = 1;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final BuilderImplBase serviceImpl;
    private final int methodId;

    MethodHandlers(BuilderImplBase serviceImpl, int methodId) {
      this.serviceImpl = serviceImpl;
      this.methodId = methodId;
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public void invoke(Req request, io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        case METHODID_BUILD:
          serviceImpl.build((cc.arduino.builder.BuildParams) request,
              (io.grpc.stub.StreamObserver<cc.arduino.builder.Response>) responseObserver);
          break;
        case METHODID_AUTOCOMPLETE:
          serviceImpl.autocomplete((cc.arduino.builder.BuildParams) request,
              (io.grpc.stub.StreamObserver<cc.arduino.builder.Response>) responseObserver);
          break;
        default:
          throw new AssertionError();
      }
    }

    @java.lang.Override
    public io.grpc.stub.StreamObserver<Req> invoke(
        io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        default:
          throw new AssertionError();
      }
    }
  }

  private static final class BuilderDescriptorSupplier implements io.grpc.protobuf.ProtoFileDescriptorSupplier {
    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return cc.arduino.builder.BuilderProto.getDescriptor();
    }
  }

  private static volatile io.grpc.ServiceDescriptor serviceDescriptor;

  public static io.grpc.ServiceDescriptor getServiceDescriptor() {
    io.grpc.ServiceDescriptor result = serviceDescriptor;
    if (result == null) {
      synchronized (BuilderGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new BuilderDescriptorSupplier())
              .addMethod(METHOD_BUILD)
              .addMethod(METHOD_AUTOCOMPLETE)
              .build();
        }
      }
    }
    return result;
  }
}
