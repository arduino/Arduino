# define CC3200 SDK libs and headers based on definitions above
SDK_LIBS := #$(APPLICATION_PATH)/hardware/secret/cc3200-sdk/simplelink/gcc/exe/libsimplelink.a

SDK_INCS := -I$(APPLICATION_PATH)/hardware/msp432/cores/msp432/inc/CMSIS

VFP := -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant

CFLAGS := -DF_CPU=$(F_CPU)
#SDK_LIBS := ti/runtime/wiring/msp432/lib/ti.runtime.wiring.msp432.lib
