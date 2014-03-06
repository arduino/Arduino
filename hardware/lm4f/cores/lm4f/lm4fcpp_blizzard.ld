/**
 *
 * lm4fcpp.ld - Linker configuration file for Energia c++ programs.
 *
 */ 

MEMORY 
{
    flash (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000 
    ram  (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000 
}

/* STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : 0x800 ; */

REGION_ALIAS("REGION_TEXT", flash);
REGION_ALIAS("REGION_RAM", ram);

SECTIONS 
{
    .text :
    {
        . = ALIGN(4);
        _text = .;
        KEEP(*(.isr_vector))
        *(.text .text* .gnu.linkonce.t.*)
        *(.glue_7t) *(.glue_7)
        *(.rodata .rodata* .gnu.linkonce.r.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)

        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(SORT(.preinit_array*)))
        KEEP (*(.preinit_array))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;

        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;

        . = ALIGN(4);
        _etext = .;
    } > REGION_TEXT

    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        . = ALIGN(4);
        _data = .;
        *(vtable)
        *(.data .data* .gnu.linkonce.d.*)
        _edata = .;
    } > REGION_RAM

    .bss (NOLOAD):
    {
        . = ALIGN(4);
        _bss = .; 
        *(.bss .bss*) 
        *(COMMON)
        . = ALIGN(4); 
        _ebss = .; 
        . = ALIGN(8);
    } > REGION_RAM 

/*
    .stack (NOLOAD):
    {
        . = ALIGN(8);
        _stack = .;
        . = . + STACK_SIZE;
        . = ALIGN(8);
        _estack = .;
    } > REGION_RAM
*/

    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > REGION_RAM
    PROVIDE_HIDDEN (__exidx_end = .);

    . = ALIGN(4);
    _end = . ;
}

/* end of allocated ram is start of heap, heap grows up towards stack*/
PROVIDE(end = _end);

/* top of stack starts at end of ram, stack grows down towards heap */
PROVIDE (_estack = ORIGIN(ram) + LENGTH(ram));
