CC = gcc
CFLAGS = -g -Wall

.PHONY: all clean

all: add2PB findPhone

add2PB: add2PB.o
	$(CC) $(CFLAGS) -o $@ $<

findPhone: findPhone.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean_phonebook:
	rm -f phonebook.txt

clean:
	rm -f add2PB findPhone *.o