######################################
# Board specific
ARCH = ARM
MCU = __MSP432P401R__
MCU_FLAG = -D$(MCU)
F_CPU = 48000000L
FLASH_SIZE = 262144
UPLOAD_COMMAND = $(CCROOT)/bin/cc3200prog $(SERIAL_PORT) $(shell pwd)/$(MAINSKETCH).bin
######################################
