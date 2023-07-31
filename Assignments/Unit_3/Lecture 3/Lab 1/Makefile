#Copywrite Mohanad

CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s 
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=learn-in-depth

all: $(Project_name).bin
	@echo "==========Build is done=========="

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=Map_file.map

$(Project_name).bin:	$(Project_name).elf
	$(CC)objcopy -O binary $< $@

clean_all: 
	rm *.o *.elf *bin

clean:
	rm *.elf *.bin