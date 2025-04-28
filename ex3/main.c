#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "mandelbrot.h"

#define DEFAULT_N 1000 // Default number for N

int main() {
    int N = DEFAULT_N;
    double real, imag;

    printf("Enter a complex number (real and imaginary parts): ");
    if (scanf("%lf %lf", &real, &imag) != 2) {
        fprintf(stderr, "Invalid input. Please enter two numbers.\n");
        return 1;
    }

    while(real != 0 && imag != 0) {
        complex double c = real + imag * I;

        if (is_in_mandelbrot(c, N)) {
            printf("%f + %fi is in the Mandelbrot set\n", real, imag);
        }
        
        else {
            printf("%f + %fi is not in the Mandelbrot set\n", real, imag);
        }

        printf("Enter a complex number (real and imaginary parts): ");
        if (scanf("%lf %lf", &real, &imag) != 2) {
            fprintf(stderr, "Invalid input. Please enter two numbers.\n");
            return 1;
        }
    }

    return 0;
}