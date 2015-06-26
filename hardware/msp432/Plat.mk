SDK_LIBS := #$(APPLICATION_PATH)/hardware/secret/cc3200-sdk/simplelink/gcc/exe/libsimplelink.a
SDK_INCS := -I$(APPLICATION_PATH)/hardware/msp432/cores/msp432/inc/CMSIS -I$(APPLICATION_PATH)/hardware/msp432/cores/msp432/driverlib/MSP432P4xx

VFP := -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant

CPPFLAGS +=
CFLAGS += -DF_CPU=$(F_CPU) -D__MSP432P401R__ -DTARGET_IS_MSP432P4XX -Dxdc__nolocalstring=1
#SDK_LIBS := ti/runtime/wiring/msp432/lib/ti.runtime.wiring.msp432.lib
OBJCOPY =
OBJCOPY_FLAGS =
