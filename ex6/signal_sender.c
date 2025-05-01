#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int msg;

    printf("Enter receiver PID: ");
    scanf("%d", &pid);

    printf("Enter message: ");
    scanf("%d", &msg);

    // Send bits to receiver
    for (int i = 7; i >= 0; i--) {
        int bit = (msg >> i) & 1; // Mask
        if (bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1000); // Sleep 1ms to give time between signals
    }

    return 0;
}