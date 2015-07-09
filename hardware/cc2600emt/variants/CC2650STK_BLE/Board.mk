######################################
# Board specific
ARCH = ARM
MCU = __CC2650__
MCU_FLAG = -D$(MCU)
F_CPU = 48000000L
FLASH_SIZE = 131072
UPLOAD_COMMAND = $(CCROOT)/bin/cc3200prog $(SERIAL_PORT) $(shell pwd)/$(MAINSKETCH).bin
######################################
