CC = gcc
CFLAGS = -g -Wall
TARGET = mandelbrot

all: $(TARGET)

$(TARGET): mandelbrot.o
	$(CC) $(CFLAGS) -o mandelbrot $< -lm

mandelbrot.o: mandelbrot.c
	$(CC) $(CFLAGS) -c mandelbrot.c -o $@

clean:
	rm -f $(TARGET) *.o