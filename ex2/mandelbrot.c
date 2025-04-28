#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define M 2.0 // קבוע M
#define DEFAULT_N 1000 // מספר מקסימלי של איטרציות

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <real> <imaginary> [<N>]\n", argv[0]);
        return 1;
    }

    // קבלת ארגומנטים
    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    int N = (argc == 4) ? atoi(argv[3]) : DEFAULT_N; // ברירת מחדל: 50 איטרציות

    double complex c = real + imag * I; // מספר מרוכב
    double complex z = 0 + 0 * I; // a_0 = 0

    for (int i = 0; i < N; i++) {
        z = z * z + c; // a_{n+1} = a_n^2 + c
        if (cabs(z) > M) { // |z| > M (M=2)
            printf("%f + %fi is not in the Mandelbrot set\n", real, imag);
            return 0;
        }
    }

    printf("%f + %fi is in the Mandelbrot set\n", real, imag);
    return 0;
}