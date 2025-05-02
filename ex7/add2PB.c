#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"Name,Phone\"\n", argv[0]);
        return 1;
    }

    FILE *file = fopen("phonebook.txt", "a"); // Open the file in append mode

    // Check if the file was opened successfully
    if (!file) {
        perror("fopen");
        return 1;
    }

    fprintf(file, "%s\n", argv[1]); // Write the new entry to the file
    fclose(file);

    return 0;
}