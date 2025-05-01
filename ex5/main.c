#include <stdio.h>
#include <stdlib.h>

// Function to generate a random array
void generate_random_array(int n, int seed, int* arr) {
    srand(seed);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 25; // Values between -25 and 74
    }
}

// Algorithm 1: O(n^3) - Converted to C
int algorithm1_n3(int* array, int n) {
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            if (sum > best) {
                best = sum;
            }
        }
    }
    return best;
}

// Algorithm 2: O(n^2) - Converted to C
int algorithm2_n2(int* array, int n) {
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            if (sum > best) {
                best = sum;
            }
        }
    }
    return best;
}

// Algorithm 3: O(n) (Kadane's algorithm) - Converted to C
int algorithm3_n(int* array, int n) {
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = (array[k] > sum + array[k]) ? array[k] : sum + array[k];
        best = (best > sum) ? best : sum;
    }
    return best;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int n = atoi(argv[2]);

    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    generate_random_array(n, seed, array);

    printf("%d\n", algorithm1_n3(array, n));
    printf("%d\n", algorithm2_n2(array, n));
    printf("%d\n", algorithm3_n(array, n));

    free(array);
    return 0;
}