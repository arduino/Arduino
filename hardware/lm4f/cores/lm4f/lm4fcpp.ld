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

REGION_ALIAS("REGION_TEXT", flash);
REGION_ALIAS("REGION_RAM", ram);

SECTIONS 
{
    .text :
    {
        _text = .;
        KEEP(*(.isr_vector))
        *(.text .text* .gnu.linkonce.t.*)
    } > REGION_TEXT
    
    .preinit_array : {
    	. = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(SORT(.preinit_array*)))
        KEEP (*(.preinit_array))
        __preinit_array_end = .;
    } > REGION_TEXT
    
    .init_array :
    {
    	. = ALIGN(4);
	    __init_array_start = .;
	    KEEP (*(SORT(.init_array.*)))
	    KEEP (*(.init_array))
	    __init_array_end = .;
    } > REGION_TEXT
    
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata .rodata* .gnu.linkonce.r.*)
        . = ALIGN(4);
    } > REGION_TEXT

    _etext = .;

    .data : 
    {
        . = ALIGN(4);
        _data = .;
        *(vtable)
        *(.data .data* .gnu.linkonce.d.*)
        _edata = .;
    } > REGION_RAM AT > REGION_TEXT

    .bss :
    {
        . = ALIGN(4);
        _bss = .; 
        *(.bss .bss*) 
        *(COMMON)
        . = ALIGN(4); 
        _ebss = .; 
        . = ALIGN(8);
        _end = .;
    } > REGION_RAM 
}

/* end of allocated ram is start of heap, heap grows up towards stack*/
PROVIDE(end = _end);

/* top of stack starts at end of ram, stack grows down towards heap */
PROVIDE (_estack = ORIGIN(ram) + LENGTH(ram));
