#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define M 2.0 // Constant
#define DEFAULT_N 1000 // Default number for N

int main(int argc, char *argv[]) {
    // Check for the correct arguments
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <real> <imaginary> [<N>]\n", argv[0]);
        return 1;
    }

    // Validate and parse arguments
    char *endptr;
    double real = strtod(argv[1], &endptr);
    if (*endptr != '\0') {
        fprintf(stderr, "Error: '%s' is not a valid number.\n", argv[1]);
        return 1;
    }

    double imag = strtod(argv[2], &endptr);
    if (*endptr != '\0') {
        fprintf(stderr, "Error: '%s' is not a valid number.\n", argv[2]);
        return 1;
    }

    int N = DEFAULT_N;
    if (argc == 4) {
        N = strtol(argv[3], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: '%s' is not a valid integer.\n", argv[3]);
            return 1;
        }
    }

    double complex c = real + imag * I; // Complex number
    double complex z = 0 + 0 * I; // a_0 = 0

    for (int i = 0; i < N; i++) {
        z = z * z + c; // a_{n+1} = a_n^2 + c (Wikipedia)
        if (cabs(z) > M) { // |z| > M
            printf("%f + %fi is not in the Mandelbrot set\n", real, imag);
            return 0;
        }
    }

    printf("%f + %fi is in the Mandelbrot set\n", real, imag);
    return 0;
}