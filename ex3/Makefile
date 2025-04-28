CC = gcc
CFLAGS = -g -Wall
TARGET = prog1
LIB = libmandelbrot.so

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -lm -L. -Wl,-rpath=. -lmandelbrot

$(LIB): mandelbrot.o
	$(CC) -shared $(CFLAGS) -o $@ $< -lm

mandelbrot.o: mandelbrot.c mandelbrot.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

main.o: main.c mandelbrot.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f $(TARGET) $(LIB) *.o