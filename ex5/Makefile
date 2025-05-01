CC = gcc
CFLAGS = -O0 -pg -g -Wall
TARGET = max_subarray

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) *.o *.out