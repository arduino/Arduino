package cc.arduino.cli.settings;

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
 * The Settings service provides an interface to Arduino CLI's configuration
 * options
 * </pre>
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.20.0)",
    comments = "Source: settings/settings.proto")
public final class SettingsGrpc {

  private SettingsGrpc() {}

  public static final String SERVICE_NAME = "cc.arduino.cli.settings.Settings";

  // Static method descriptors that strictly reflect the proto.
  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest,
      cc.arduino.cli.settings.SettingsOuterClass.RawData> getGetAllMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "GetAll",
      requestType = cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest.class,
      responseType = cc.arduino.cli.settings.SettingsOuterClass.RawData.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest,
      cc.arduino.cli.settings.SettingsOuterClass.RawData> getGetAllMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest, cc.arduino.cli.settings.SettingsOuterClass.RawData> getGetAllMethod;
    if ((getGetAllMethod = SettingsGrpc.getGetAllMethod) == null) {
      synchronized (SettingsGrpc.class) {
        if ((getGetAllMethod = SettingsGrpc.getGetAllMethod) == null) {
          SettingsGrpc.getGetAllMethod = getGetAllMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest, cc.arduino.cli.settings.SettingsOuterClass.RawData>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.settings.Settings", "GetAll"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.RawData.getDefaultInstance()))
                  .setSchemaDescriptor(new SettingsMethodDescriptorSupplier("GetAll"))
                  .build();
          }
        }
     }
     return getGetAllMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.RawData,
      cc.arduino.cli.settings.SettingsOuterClass.MergeResponse> getMergeMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "Merge",
      requestType = cc.arduino.cli.settings.SettingsOuterClass.RawData.class,
      responseType = cc.arduino.cli.settings.SettingsOuterClass.MergeResponse.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.RawData,
      cc.arduino.cli.settings.SettingsOuterClass.MergeResponse> getMergeMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.RawData, cc.arduino.cli.settings.SettingsOuterClass.MergeResponse> getMergeMethod;
    if ((getMergeMethod = SettingsGrpc.getMergeMethod) == null) {
      synchronized (SettingsGrpc.class) {
        if ((getMergeMethod = SettingsGrpc.getMergeMethod) == null) {
          SettingsGrpc.getMergeMethod = getMergeMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.settings.SettingsOuterClass.RawData, cc.arduino.cli.settings.SettingsOuterClass.MergeResponse>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.settings.Settings", "Merge"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.RawData.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.MergeResponse.getDefaultInstance()))
                  .setSchemaDescriptor(new SettingsMethodDescriptorSupplier("Merge"))
                  .build();
          }
        }
     }
     return getMergeMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest,
      cc.arduino.cli.settings.SettingsOuterClass.Value> getGetValueMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "GetValue",
      requestType = cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest.class,
      responseType = cc.arduino.cli.settings.SettingsOuterClass.Value.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest,
      cc.arduino.cli.settings.SettingsOuterClass.Value> getGetValueMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest, cc.arduino.cli.settings.SettingsOuterClass.Value> getGetValueMethod;
    if ((getGetValueMethod = SettingsGrpc.getGetValueMethod) == null) {
      synchronized (SettingsGrpc.class) {
        if ((getGetValueMethod = SettingsGrpc.getGetValueMethod) == null) {
          SettingsGrpc.getGetValueMethod = getGetValueMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest, cc.arduino.cli.settings.SettingsOuterClass.Value>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.settings.Settings", "GetValue"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.Value.getDefaultInstance()))
                  .setSchemaDescriptor(new SettingsMethodDescriptorSupplier("GetValue"))
                  .build();
          }
        }
     }
     return getGetValueMethod;
  }

  private static volatile io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.Value,
      cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse> getSetValueMethod;

  @io.grpc.stub.annotations.RpcMethod(
      fullMethodName = SERVICE_NAME + '/' + "SetValue",
      requestType = cc.arduino.cli.settings.SettingsOuterClass.Value.class,
      responseType = cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse.class,
      methodType = io.grpc.MethodDescriptor.MethodType.UNARY)
  public static io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.Value,
      cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse> getSetValueMethod() {
    io.grpc.MethodDescriptor<cc.arduino.cli.settings.SettingsOuterClass.Value, cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse> getSetValueMethod;
    if ((getSetValueMethod = SettingsGrpc.getSetValueMethod) == null) {
      synchronized (SettingsGrpc.class) {
        if ((getSetValueMethod = SettingsGrpc.getSetValueMethod) == null) {
          SettingsGrpc.getSetValueMethod = getSetValueMethod = 
              io.grpc.MethodDescriptor.<cc.arduino.cli.settings.SettingsOuterClass.Value, cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.UNARY)
              .setFullMethodName(generateFullMethodName(
                  "cc.arduino.cli.settings.Settings", "SetValue"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.Value.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse.getDefaultInstance()))
                  .setSchemaDescriptor(new SettingsMethodDescriptorSupplier("SetValue"))
                  .build();
          }
        }
     }
     return getSetValueMethod;
  }

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static SettingsStub newStub(io.grpc.Channel channel) {
    return new SettingsStub(channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static SettingsBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    return new SettingsBlockingStub(channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static SettingsFutureStub newFutureStub(
      io.grpc.Channel channel) {
    return new SettingsFutureStub(channel);
  }

  /**
   * <pre>
   * The Settings service provides an interface to Arduino CLI's configuration
   * options
   * </pre>
   */
  public static abstract class SettingsImplBase implements io.grpc.BindableService {

    /**
     * <pre>
     * List all the settings.
     * </pre>
     */
    public void getAll(cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.RawData> responseObserver) {
      asyncUnimplementedUnaryCall(getGetAllMethod(), responseObserver);
    }

    /**
     * <pre>
     * Set multiple settings values at once.
     * </pre>
     */
    public void merge(cc.arduino.cli.settings.SettingsOuterClass.RawData request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.MergeResponse> responseObserver) {
      asyncUnimplementedUnaryCall(getMergeMethod(), responseObserver);
    }

    /**
     * <pre>
     * Get the value of a specific setting.
     * </pre>
     */
    public void getValue(cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.Value> responseObserver) {
      asyncUnimplementedUnaryCall(getGetValueMethod(), responseObserver);
    }

    /**
     * <pre>
     * Set the value of a specific setting.
     * </pre>
     */
    public void setValue(cc.arduino.cli.settings.SettingsOuterClass.Value request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse> responseObserver) {
      asyncUnimplementedUnaryCall(getSetValueMethod(), responseObserver);
    }

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
          .addMethod(
            getGetAllMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest,
                cc.arduino.cli.settings.SettingsOuterClass.RawData>(
                  this, METHODID_GET_ALL)))
          .addMethod(
            getMergeMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.settings.SettingsOuterClass.RawData,
                cc.arduino.cli.settings.SettingsOuterClass.MergeResponse>(
                  this, METHODID_MERGE)))
          .addMethod(
            getGetValueMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest,
                cc.arduino.cli.settings.SettingsOuterClass.Value>(
                  this, METHODID_GET_VALUE)))
          .addMethod(
            getSetValueMethod(),
            asyncUnaryCall(
              new MethodHandlers<
                cc.arduino.cli.settings.SettingsOuterClass.Value,
                cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse>(
                  this, METHODID_SET_VALUE)))
          .build();
    }
  }

  /**
   * <pre>
   * The Settings service provides an interface to Arduino CLI's configuration
   * options
   * </pre>
   */
  public static final class SettingsStub extends io.grpc.stub.AbstractStub<SettingsStub> {
    private SettingsStub(io.grpc.Channel channel) {
      super(channel);
    }

    private SettingsStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected SettingsStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new SettingsStub(channel, callOptions);
    }

    /**
     * <pre>
     * List all the settings.
     * </pre>
     */
    public void getAll(cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.RawData> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getGetAllMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Set multiple settings values at once.
     * </pre>
     */
    public void merge(cc.arduino.cli.settings.SettingsOuterClass.RawData request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.MergeResponse> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getMergeMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Get the value of a specific setting.
     * </pre>
     */
    public void getValue(cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.Value> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getGetValueMethod(), getCallOptions()), request, responseObserver);
    }

    /**
     * <pre>
     * Set the value of a specific setting.
     * </pre>
     */
    public void setValue(cc.arduino.cli.settings.SettingsOuterClass.Value request,
        io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse> responseObserver) {
      asyncUnaryCall(
          getChannel().newCall(getSetValueMethod(), getCallOptions()), request, responseObserver);
    }
  }

  /**
   * <pre>
   * The Settings service provides an interface to Arduino CLI's configuration
   * options
   * </pre>
   */
  public static final class SettingsBlockingStub extends io.grpc.stub.AbstractStub<SettingsBlockingStub> {
    private SettingsBlockingStub(io.grpc.Channel channel) {
      super(channel);
    }

    private SettingsBlockingStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected SettingsBlockingStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new SettingsBlockingStub(channel, callOptions);
    }

    /**
     * <pre>
     * List all the settings.
     * </pre>
     */
    public cc.arduino.cli.settings.SettingsOuterClass.RawData getAll(cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest request) {
      return blockingUnaryCall(
          getChannel(), getGetAllMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Set multiple settings values at once.
     * </pre>
     */
    public cc.arduino.cli.settings.SettingsOuterClass.MergeResponse merge(cc.arduino.cli.settings.SettingsOuterClass.RawData request) {
      return blockingUnaryCall(
          getChannel(), getMergeMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Get the value of a specific setting.
     * </pre>
     */
    public cc.arduino.cli.settings.SettingsOuterClass.Value getValue(cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest request) {
      return blockingUnaryCall(
          getChannel(), getGetValueMethod(), getCallOptions(), request);
    }

    /**
     * <pre>
     * Set the value of a specific setting.
     * </pre>
     */
    public cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse setValue(cc.arduino.cli.settings.SettingsOuterClass.Value request) {
      return blockingUnaryCall(
          getChannel(), getSetValueMethod(), getCallOptions(), request);
    }
  }

  /**
   * <pre>
   * The Settings service provides an interface to Arduino CLI's configuration
   * options
   * </pre>
   */
  public static final class SettingsFutureStub extends io.grpc.stub.AbstractStub<SettingsFutureStub> {
    private SettingsFutureStub(io.grpc.Channel channel) {
      super(channel);
    }

    private SettingsFutureStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected SettingsFutureStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new SettingsFutureStub(channel, callOptions);
    }

    /**
     * <pre>
     * List all the settings.
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.settings.SettingsOuterClass.RawData> getAll(
        cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest request) {
      return futureUnaryCall(
          getChannel().newCall(getGetAllMethod(), getCallOptions()), request);
    }

    /**
     * <pre>
     * Set multiple settings values at once.
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.settings.SettingsOuterClass.MergeResponse> merge(
        cc.arduino.cli.settings.SettingsOuterClass.RawData request) {
      return futureUnaryCall(
          getChannel().newCall(getMergeMethod(), getCallOptions()), request);
    }

    /**
     * <pre>
     * Get the value of a specific setting.
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.settings.SettingsOuterClass.Value> getValue(
        cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest request) {
      return futureUnaryCall(
          getChannel().newCall(getGetValueMethod(), getCallOptions()), request);
    }

    /**
     * <pre>
     * Set the value of a specific setting.
     * </pre>
     */
    public com.google.common.util.concurrent.ListenableFuture<cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse> setValue(
        cc.arduino.cli.settings.SettingsOuterClass.Value request) {
      return futureUnaryCall(
          getChannel().newCall(getSetValueMethod(), getCallOptions()), request);
    }
  }

  private static final int METHODID_GET_ALL = 0;
  private static final int METHODID_MERGE = 1;
  private static final int METHODID_GET_VALUE = 2;
  private static final int METHODID_SET_VALUE = 3;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final SettingsImplBase serviceImpl;
    private final int methodId;

    MethodHandlers(SettingsImplBase serviceImpl, int methodId) {
      this.serviceImpl = serviceImpl;
      this.methodId = methodId;
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public void invoke(Req request, io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        case METHODID_GET_ALL:
          serviceImpl.getAll((cc.arduino.cli.settings.SettingsOuterClass.GetAllRequest) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.RawData>) responseObserver);
          break;
        case METHODID_MERGE:
          serviceImpl.merge((cc.arduino.cli.settings.SettingsOuterClass.RawData) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.MergeResponse>) responseObserver);
          break;
        case METHODID_GET_VALUE:
          serviceImpl.getValue((cc.arduino.cli.settings.SettingsOuterClass.GetValueRequest) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.Value>) responseObserver);
          break;
        case METHODID_SET_VALUE:
          serviceImpl.setValue((cc.arduino.cli.settings.SettingsOuterClass.Value) request,
              (io.grpc.stub.StreamObserver<cc.arduino.cli.settings.SettingsOuterClass.SetValueResponse>) responseObserver);
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

  private static abstract class SettingsBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoFileDescriptorSupplier, io.grpc.protobuf.ProtoServiceDescriptorSupplier {
    SettingsBaseDescriptorSupplier() {}

    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return cc.arduino.cli.settings.SettingsOuterClass.getDescriptor();
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.ServiceDescriptor getServiceDescriptor() {
      return getFileDescriptor().findServiceByName("Settings");
    }
  }

  private static final class SettingsFileDescriptorSupplier
      extends SettingsBaseDescriptorSupplier {
    SettingsFileDescriptorSupplier() {}
  }

  private static final class SettingsMethodDescriptorSupplier
      extends SettingsBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoMethodDescriptorSupplier {
    private final String methodName;

    SettingsMethodDescriptorSupplier(String methodName) {
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
      synchronized (SettingsGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new SettingsFileDescriptorSupplier())
              .addMethod(getGetAllMethod())
              .addMethod(getMergeMethod())
              .addMethod(getGetValueMethod())
              .addMethod(getSetValueMethod())
              .build();
        }
      }
    }
    return result;
  }
}
