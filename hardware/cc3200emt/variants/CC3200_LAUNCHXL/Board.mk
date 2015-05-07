######################################
# Board specific
ARCH = armv7e-m
CPU = cortex-m4
MCU_FLAG = -mcpu=$(CPU) -march=$(ARCH)
F_CPU = 80000000L
FLASH_SIZE = 262144
UPLOAD_COMMAND = $(CCROOT)/bin/cc3200prog $(SERIAL_PORT) $(shell pwd)/$(MAINSKETCH).bin
######################################
