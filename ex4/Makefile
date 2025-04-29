CC = gcc
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -g
TARGET = dijkstra

.PHONY: all clean

all: $(TARGET)

$(TARGET): dijkstra.o
	$(CC) $(CFLAGS) -o $@ $<

dijkstra.o: dijkstra.c
	$(CC) $(CFLAGS) -c dijkstra.c -o $@

run:
	./$(TARGET)

coverage: run
	gcov dijkstra.c
	
clean:
	rm -f $(TARGET) *.o *.gcda *.gcno *.gcov