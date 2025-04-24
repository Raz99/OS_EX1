#include <stdio.h>

int main() {
    int *ptr = (int *)0xdeadbeef;
    *ptr = 10;
    return 0;
}