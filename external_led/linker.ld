MEMORY
{
    FLASH : ORIGIN = 0x08000000, LENGTH = 1024K
}

SECTIONS
{
    .text :
    {
        *(.text*)
    } > FLASH
}

