CC = gcc
CFLAGS = -Wall # Add/Remove -g if you don't want debug info
T_STACK_OVERFLOW = prog1
T_DIVIDE_BY_ZERO = prog2
T_INVALID_MEMORY = prog3

.PHONY: all clean

all: prog1 prog2 prog3

$(T_STACK_OVERFLOW): stack_overflow.o
	$(CC) $(CFLAGS) -o $@ $<

$(T_DIVIDE_BY_ZERO): divide_by_zero.o
	$(CC) $(CFLAGS) -o $@ $<

$(T_INVALID_MEMORY): invalid_memory.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(T_STACK_OVERFLOW) $(T_DIVIDE_BY_ZERO) $(T_INVALID_MEMORY) *.o