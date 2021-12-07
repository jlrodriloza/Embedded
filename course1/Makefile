#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines

TARGET = jose
#CFLAGS = -Werror -g -O0 -std=c99 -I include/common/ -I include/CMSIS -I include/msp432
# removed from here to be conditional to PLATFORM

#only for ARM
ARMCPPFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -Wall -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16


ifeq ($(PLATFORM),HOST)
	
	CC = gcc
	LD = ld
	DUMP = objdump
	SRCS = $(COMMON_SOURCES)
	INCLUDES = $(COMMON_INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	
	# left empty for HOST (not preprocessor flags needed)
	CPPFLAGS = -D$(PLATFORM) -DCOURSE1
	
	CFLAGS = -Werror -g -O0 -std=c99 -I include/common/
	
else ifeq ($(PLATFORM),MSP432)
	
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	DUMP = arm-none-eabi-objdump
	SRCS = $(COMMON_SOURCES) $(MSP432_SOURCES)
	INCLUDES = $(COMMON_INCLUDES) $(MSP432_INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CPPFLAGS = -D$(PLATFORM) -DCOURSE1 $(ARMCPPFLAGS)

	CFLAGS = -Werror -g -O0 -std=c99 -I include/common/ -I include/CMSIS -I include/msp432

else
	$(error "Unsupported PLATFORM" $(PLATFORM))
	
endif



OBJS = $(SRCS:.c=.o)

PREPS = $(SRCS:.c=.i)

ASMS =  $(SRCS:.c=.asm)


%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) -o $@
	
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@
	
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@
	
$(TARGET).dump:  $(TARGET).out
	$(DUMP) --disassemble $(TARGET).out > $(TARGET).dump

$(TARGET).o: $(OBJS)
	$(CC) -c $(OBJS) $(CFLAGS) $(CPPFLAGS) -o $@
	
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

.PHONY: compile-all
compile-all: $(TARGET).o

.PHONY: build
build: $(TARGET).out

.PHONY: clean
clean:	
	rm -f $(PREPS) $(OBJS) $(ASMS) $(TARGET).out $(TARGET).map
