######################################
# Board specific
ARCH = ARM
MCU = cc3200
#MCU_FLAG = -mmcu=$(MCU)
F_CPU = 80000000L
FLASH_SIZE = 262144
UPLOAD_COMMAND = $(CCROOT)/bin/cc3200prog $(SERIAL_PORT) $(shell pwd)/$(MAINSKETCH).bin
######################################
