ARMGNU=arm-none-eabi
CFLAGS=-c -mcpu=cortex-m4 -mthumb -Wall -std=gnu11
LFLAGS=-nostdlib -nostartfiles -T linker.ld -Map=main.map

all: boot.o main.o main.elf

boot.o: boot.s
	$(ARMGNU)-as --warn --fatal-warnings -mcpu=cortex-m4 -mthumb boot.s -o boot.o	

main.o: main.c
	$(ARMGNU)-gcc $(CFLAGS) main.c -o main.o

main.elf: boot.o main.o
	$(ARMGNU)-ld $(LFLAGS) boot.o main.o -o main.elf
	$(ARMGNU)-objcopy main.elf main.bin -O binary

load:
	openocd -f board/stm32l4discovery.cfg

clean:
	rm -f *.o *.elf *.bin *.map
