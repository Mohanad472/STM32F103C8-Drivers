#copywrite : Mohanad
CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=Pressure_Detection

all: $(Project_name).bin
	@echo "=====build is done====="

#startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $<  -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all: 
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin