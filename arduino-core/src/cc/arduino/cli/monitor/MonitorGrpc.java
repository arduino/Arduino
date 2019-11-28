package cc.arduino.cli.monitor;

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
 * Service that abstract a Monitor usage
 * </pre>
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.20.0)",
    comments = "Source: monitor/monitor.proto")
public final class MonitorGrpc {

  private MonitorGrpc() {}

  public static final String SERVICE_NAME = "cc.arduino.cli.monitor.Monitor";

  // Static method descriptors that strictly reflect the proto.
  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq,
      cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp> getStreamingOpenMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "StreamingOpen",
      requestType = cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq.class,
      responseType = cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp.class,
      methodType = io.grpc.MethodDescriptor.MethodType.BIDI_STREAMING)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq,
      cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp> getStreamingOpenMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq, cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp> getStreamingOpenMethod;
    if ((getStreamingOpenMethod = MonitorGrpc.getStreamingOpenMethod) == null) {
      synchronized (MonitorGrpc.class) {
        if ((getStreamingOpenMethod = MonitorGrpc.getStreamingOpenMethod) == null) {
          MonitorGrpc.getStreamingOpenMethod = getStreamingOpenMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq, cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.BIDI_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.monitor.Monitor", "StreamingOpen"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp.getDefaultInstance()))
                  .setSchemaDescriptor(new MonitorMethodDescriptorSupplier("StreamingOpen"))
                  .build();
          }
        }
     }
     return getStreamingOpenMethod;
  }

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static MonitorStub newStub(io.grpc.Channel channel) {
    return new MonitorStub(channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static MonitorBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    return new MonitorBlockingStub(channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static MonitorFutureStub newFutureStub(
      io.grpc.Channel channel) {
    return new MonitorFutureStub(channel);
  }

  /**
   * <pre>
   * Service that abstract a Monitor usage
   * </pre>
   */
  public static abstract class MonitorImplBase implements io.grpc.BindableService {

    /**
     */
    public io.grpc.stub.StreamObserver<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq> streamingOpen(
        io.grpc.stub.StreamObserver<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp> responseObserver) {
      return asyncUnimplementedStreamingCall(getStreamingOpenMethod(), responseObserver);
    }

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
          .addMethod(
            getStreamingOpenMethod(),
            asyncBidiStreamingCall(
              new MethodHandlers<
                cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq,
                cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp>(
                  this, METHODID_STREAMING_OPEN)))
          .build();
    }
  }

  /**
   * <pre>
   * Service that abstract a Monitor usage
   * </pre>
   */
  public static final class MonitorStub extends io.grpc.stub.AbstractStub<MonitorStub> {
    private MonitorStub(io.grpc.Channel channel) {
      super(channel);
    }

    private MonitorStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected MonitorStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new MonitorStub(channel, callOptions);
    }

    /**
     */
    public io.grpc.stub.StreamObserver<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenReq> streamingOpen(
        io.grpc.stub.StreamObserver<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp> responseObserver) {
      return asyncBidiStreamingCall(
          getChannel().newCall(getStreamingOpenMethod(), getCallOptions()), responseObserver);
    }
  }

  /**
   * <pre>
   * Service that abstract a Monitor usage
   * </pre>
   */
  public static final class MonitorBlockingStub extends io.grpc.stub.AbstractStub<MonitorBlockingStub> {
    private MonitorBlockingStub(io.grpc.Channel channel) {
      super(channel);
    }

    private MonitorBlockingStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected MonitorBlockingStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new MonitorBlockingStub(channel, callOptions);
    }
  }

  /**
   * <pre>
   * Service that abstract a Monitor usage
   * </pre>
   */
  public static final class MonitorFutureStub extends io.grpc.stub.AbstractStub<MonitorFutureStub> {
    private MonitorFutureStub(io.grpc.Channel channel) {
      super(channel);
    }

    private MonitorFutureStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected MonitorFutureStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new MonitorFutureStub(channel, callOptions);
    }
  }

  private static final int METHODID_STREAMING_OPEN = 0;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final MonitorImplBase serviceImpl;
    private final int methodId;

    MethodHandlers(MonitorImplBase serviceImpl, int methodId) {
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
        case METHODID_STREAMING_OPEN:
          return (io.grpc.stub.StreamObserver<Req>) serviceImpl.streamingOpen(
              (io.grpc.stub.StreamObserver<cc.arduino.cli.monitor.MonitorOuterClass.StreamingOpenResp>) responseObserver);
        default:
          throw new AssertionError();
      }
    }
  }

  private static abstract class MonitorBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoFileDescriptorSupplier, io.grpc.protobuf.ProtoServiceDescriptorSupplier {
    MonitorBaseDescriptorSupplier() {}

    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return cc.arduino.cli.monitor.MonitorOuterClass.getDescriptor();
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.ServiceDescriptor getServiceDescriptor() {
      return getFileDescriptor().findServiceByName("Monitor");
    }
  }

  private static final class MonitorFileDescriptorSupplier
      extends MonitorBaseDescriptorSupplier {
    MonitorFileDescriptorSupplier() {}
  }

  private static final class MonitorMethodDescriptorSupplier
      extends MonitorBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoMethodDescriptorSupplier {
    private final String methodName;

    MonitorMethodDescriptorSupplier(String methodName) {
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
      synchronized (MonitorGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new MonitorFileDescriptorSupplier())
              .addMethod(getStreamingOpenMethod())
              .build();
        }
      }
    }
    return result;
  }
}
