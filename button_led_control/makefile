CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS=-c -mcpu=$(MACH) -mthumb -Wall -std=gnu11
LDFLAGS=-nostdlib -T linker.ld -Wl,-Map=final.map

all: main.o start_up.o final.elf final.bin

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

start_up.o: start_up.c
	$(CC) $(CFLAGS) start_up.c -o start_up.o

final.elf: main.o start_up.o
	$(CC) $(LDFLAGS) main.o start_up.o -o final.elf

final.bin: final.elf
	arm-none-eabi-objcopy final.elf final.bin -O binary

load:
	openocd -f board/stm32l4discovery.cfg
	

clean:
	rm -f *.o
	rm -f *.s
	rm -f *elf
	rm -f *.bin
	rm -f *.map
