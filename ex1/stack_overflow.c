#include <stdio.h>

int func() {
    return func();
}

int main() {
    func();
    return 0;
}