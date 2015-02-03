# define CC3200 SDK libs and headers based on definitions above
SDK_LIBS := $(APPLICATION_PATH)/hardware/secret/cc3200-sdk/simplelink/gcc/exe/libsimplelink.a \
           $(APPLICATION_PATH)/hardware/secret/cc3200-sdk/oslib/gcc/exe/libtirtos.a \
           $(APPLICATION_PATH)/hardware/secret/cc3200-sdk/driverlib/gcc/exe/libdriver.a

SDK_INCS := -I$(APPLICATION_PATH)/hardware/secret/cc3200-sdk/simplelink/include \
           -I$(APPLICATION_PATH)/hardware/secret/cc3200-sdk


