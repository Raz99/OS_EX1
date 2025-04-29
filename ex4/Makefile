CC = gcc
CFLAGS = -g -Wall -fprofile-arcs -ftest-coverage
TARGET = dijkstra

.PHONY: all clean coverage run

all: $(TARGET)

$(TARGET): dijkstra.o
	$(CC) $(CFLAGS) -o $@ $<

dijkstra.o: dijkstra.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

coverage: run
	gcov dijkstra.c
	
clean:
	rm -f $(TARGET) *.o *.gcda *.gcno *.gcov