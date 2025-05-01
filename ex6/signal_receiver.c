#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

unsigned char received = 0;
int bits_received = 0;

void handle_bit(int bit) {
    received = (received << 1) | bit; // Add bit as LSB
    bits_received++;

    if (bits_received == 8) {
        printf("Received %d\n", received);
        exit(0);
    }
}

void sigusr1_handler(int sig) {
    handle_bit(0);
}

void sigusr2_handler(int sig) {
    handle_bit(1);
}

int main() {
    printf("My PID is %d\n", getpid());

    struct sigaction sa1, sa2;

    sa1.sa_handler = sigusr1_handler;
    sigemptyset(&sa1.sa_mask); // Start with an empty mask
    sigaddset(&sa1.sa_mask, SIGUSR2); // Block SIGUSR2 while handling SIGUSR1
    sa1.sa_flags = 0;
    sigaction(SIGUSR1, &sa1, NULL); // Register the handler for SIGUSR1

    sa2.sa_handler = sigusr2_handler;
    sigemptyset(&sa2.sa_mask); // Start with an empty mask
    sigaddset(&sa2.sa_mask, SIGUSR1); // Block SIGUSR1 while handling SIGUSR2
    sa2.sa_flags = 0;
    sigaction(SIGUSR2, &sa2, NULL); // Register the handler for SIGUSR2

    // Keep the process running
    while (1) {
        sleep(1); // Wait for a signal
    }

    return 0;
}