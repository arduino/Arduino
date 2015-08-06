SDK_LIBS := #$(APPLICATION_PATH)/hardware/secret/cc3200-sdk/simplelink/gcc/exe/libsimplelink.a
SDK_INCS := -I$(APPLICATION_PATH)/hardware/cc2600emt/cores/cc2600emt/driverlib

VFP :=

CPPFLAGS +=
CFLAGS += -DF_CPU=$(F_CPU) -Dxdc__nolocalstring=1
OBJCOPY =
OBJCOPY_FLAGS =
PLAT := cc26xx
