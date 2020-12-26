ENTRY(Reset_Handler)

MEMORY
{
    rom (rw) : ORIGIN = 0x08000000, LENGTH = 1024K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

/* symbol declaration */
__max_heap_size = 0x400;
__max_stack_size = 0x200;

SECTIONS
{
    .text : 
    { 
        *(.isr_vector)
        *(.text) 
        *(.rodata)
        . = ALIGN(4); /* using ALIGN you can match end of sections to align properly with the start of the next section */
        _etext = .; /* store the updated location counter into a symbol 'end_of_text' */
    } > rom

    _la_data = LOADADDR(.data);
    /*.rodata : { *(.rodata) } > rom*/

    .data : 
    { 
        _sdata = .; /* assign value to symbol 'start_of_data' note. location counter always = vma */
        *(.data) 
        . = ALIGN(4);
        _edata = .; /* end of data */
    } > ram AT> rom

    .bss : 
    { 
        _sbss = .;
        *(.bss) 
        . = ALIGN(4);
        _ebss = .;
    } > ram
}
