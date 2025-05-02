#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check if the user provided a name as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"Name\"\n", argv[0]);
        exit(1);
    }

    int pipe1_fd[2], pipe2_fd[2], pipe3_fd[2]; // File descriptors for pipes
    
    // Create pipes
    pipe(pipe1_fd);
    pipe(pipe2_fd);
    pipe(pipe3_fd);

    // Step 1: grep "Name" phonebook.txt
    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pipe1_fd[1], STDOUT_FILENO); // Write to pipe1
        close(pipe1_fd[0]); // Close the read end of pipe1
        close(pipe1_fd[1]); // Close the write end of pipe1 after dup2
        char *cmd[] = {"grep", argv[1], "phonebook.txt", NULL};
        execvp(cmd[0], cmd); // Execute grep command
        perror("exec grep"); // If execvp fails, the child process continues executing
        exit(1);
    }

    close(pipe1_fd[1]); // Close the write end of pipe1 after dup2

    // Step 2: sed 's/ /#/g'
    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(pipe1_fd[0], STDIN_FILENO);  // Read from pipe1
        dup2(pipe2_fd[1], STDOUT_FILENO); // Write to pipe2
        close(pipe1_fd[0]); // Close the read end of pipe1
        close(pipe2_fd[0]); // Close the read end of pipe2
        close(pipe2_fd[1]); // Close the write end of pipe2 after dup2
        char *cmd[] = {"sed", "s/ /#/g", NULL}; // sed replaces all spaces with #
        execvp(cmd[0], cmd); // Execute sed command
        perror("exec sed1"); // If execvp fails, the child process continues executing
        exit(1);
    }

    close(pipe1_fd[0]); // Close the read end of pipe1
    close(pipe2_fd[1]); // Close the write end of pipe2 after dup2

    // Step 3: sed 's/,/ /'
    pid_t pid3 = fork();
    if (pid3 == 0) {
        dup2(pipe2_fd[0], STDIN_FILENO);  // Read from pipe2
        dup2(pipe3_fd[1], STDOUT_FILENO); // Write to pipe3
        close(pipe2_fd[0]); // Close the read end of pipe2
        close(pipe3_fd[0]); // Close the read end of pipe3
        close(pipe3_fd[1]); // Close the write end of pipe3 after dup2
        char *cmd[] = {"sed", "s/,/ /", NULL}; // sed replaces the first comma with a space
        execvp(cmd[0], cmd); // Execute sed command
        perror("exec sed2"); // If execvp fails, the child process continues executing
        exit(1);
    }

    close(pipe2_fd[0]); // Close the read end of pipe2
    close(pipe3_fd[1]); // Close the write end of pipe3 after dup2

    // Step 4: awk '{print $2}'
    pid_t pid4 = fork();
    if (pid4 == 0) {
        dup2(pipe3_fd[0], STDIN_FILENO); // Read from pipe3
        close(pipe3_fd[0]); // Close the read end of pipe3
        char *cmd[] = {"awk", "{print $2}", NULL}; // awk prints the second field
        execvp(cmd[0], cmd); // Execute awk command
        perror("exec awk"); // If execvp fails, the child process continues executing
        exit(1);
    }

    close(pipe3_fd[0]); // Close the read end of pipe3

    // Wait for all child processes to finish
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }
    
    return 0;
}