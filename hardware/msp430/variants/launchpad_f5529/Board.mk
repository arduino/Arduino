######################################
# Board specific
ARCH = msp430
MCU = msp430f5529
MCU_FLAG = -mmcu=$(MCU)
F_CPU = 25000000L
FLASH_SIZE = 131072
UPLOAD_COMMAND = $(MSPDEBUG) $(VERBOSE_UPLOAD) tilib --force-reset "prog build/$(SKETCH_NAME).bin"
######################################
