/******************************************************************************
 *
 * Default Linker script for the Texas Instruments CC2650
 *
 *****************************************************************************/

MEMORY
{
    FLASH (RX)      : ORIGIN = 0x00000000, LENGTH = 0x0001ffa8
    /*
     * Customer Configuration Area and Bootloader Backdoor configuration in
     * flash, 40 bytes
     */
    FLASH_CCFG (RX) : ORIGIN = 0x0001ffa8, LENGTH = 0x00000058
    SRAM (RWX)      : ORIGIN = 0x20000000, LENGTH = 0x00005000
}

REGION_ALIAS("REGION_TEXT", FLASH);
REGION_ALIAS("REGION_BSS", SRAM);
REGION_ALIAS("REGION_DATA", SRAM);
REGION_ALIAS("REGION_STACK", SRAM);
REGION_ALIAS("REGION_HEAP", SRAM);
REGION_ALIAS("REGION_ARM_EXIDX", FLASH);
REGION_ALIAS("REGION_ARM_EXTAB", FLASH);

SECTIONS {

    PROVIDE (_intvecs_base_address =
        DEFINED(_intvecs_base_address) ? _intvecs_base_address : 0x0);

    .intvecs (_intvecs_base_address) : AT (_intvecs_base_address) {
        KEEP (*(.intvecs))
    } > REGION_TEXT

    PROVIDE (_vtable_base_address =
        DEFINED(_vtable_base_address) ? _vtable_base_address : 0x20000000);

    .vtable (_vtable_base_address) : AT (_vtable_base_address) {
        KEEP (*(.vtable))
    } > REGION_DATA

    /* these hard-coded addrs are needed by the TI-RTOS SPICC26XXDMA driver
     * and must match appropriate offsets from UDMACC26XX_CONFIG_BASE defined
     * by ti/drivers/dma/UDMACC26XX.h
     */
    .dmaRxControlTableEntry0 0x20000430 : AT (0x20000430) {*(.dmaRxControlTableEntry0)} > REGION_DATA
    .dmaTxControlTableEntry0 0x20000440 : AT (0x20000440) {*(.dmaTxControlTableEntry0)} > REGION_DATA
    .dmaRxControlTableEntry1 0x20000500 : AT (0x20000500) {*(.dmaRxControlTableEntry1)} > REGION_DATA
    .dmaTxControlTableEntry1 0x20000510 : AT (0x20000510) {*(.dmaTxControlTableEntry1)} > REGION_DATA

    /* remove unnecessary sections included in some TI object files */
    /DISCARD/ : {
        *(__TI_ICODE)
    }

    .text : {
        CREATE_OBJECT_SYMBOLS
        *(.text)
        *(.text.*)
        . = ALIGN(0x4);
        KEEP (*(.ctors))
        . = ALIGN(0x4);
        KEEP (*(.dtors))
        . = ALIGN(0x4);
        __init_array_start = .;
        KEEP (*(.init_array*))
        __init_array_end = .;
        *(.init)
        *(.fini*)
    } > REGION_TEXT AT> REGION_TEXT

    PROVIDE (__etext = .);
    PROVIDE (_etext = .);
    PROVIDE (etext = .);

    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > REGION_TEXT AT> REGION_TEXT

    .data : ALIGN (4) {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN (4);
        __data_end__ = .;
    } > REGION_DATA AT> REGION_TEXT

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > REGION_ARM_EXIDX AT> REGION_ARM_EXIDX

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > REGION_ARM_EXTAB AT> REGION_ARM_EXTAB

    .ccfg : {
        KEEP (*(.ccfg))
    } > FLASH_CCFG AT> FLASH_CCFG

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN (4);
        __bss_end__ = .;
    } > REGION_BSS AT> REGION_BSS

    .heap : {
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        KEEP(*(.heap))
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > REGION_HEAP AT> REGION_HEAP

    .stack (NOLOAD) : ALIGN(0x8) {
        _stack = .;
        __stack = .;
        KEEP(*(.stack))
    } > REGION_STACK AT> REGION_STACK

}
