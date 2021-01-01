.thumb
.globl _start

_start:

.word 0x20018000
.word reset
.thumb_func
reset:
    bl main
