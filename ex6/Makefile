CC = gcc
CFLAGS = -g -Wall

.PHONY: all clean

all: signal_sender signal_receiver

signal_sender: signal_sender.o
	$(CC) $(CFLAGS) -o $@ $<

signal_receiver: signal_receiver.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f signal_sender signal_receiver *.o