#include <complex.h>
#include <math.h>
#include "mandelbrot.h"

#define M 2.0 // Constant

double complex z = 0 + 0 * I; // a_0 = 0

bool is_in_mandelbrot(complex double c, int N) {
    for (int i = 0; i < N; i++) {
        z = z * z + c; // a_{n+1} = a_n^2 + c (Wikipedia)
        if (cabs(z) > M) { // |z| > M
            return false;
        }
    }

    return true;
}