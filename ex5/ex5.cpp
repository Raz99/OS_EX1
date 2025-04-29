#include <iostream>
#include <cstdlib>   // בשביל srand, rand
using namespace std;


int main() {
    for (int i=0; i < 3; i++) {
        srand(42);
        for (int j = 0; j < 20; j++) {
            int x = rand() % 100 - 25;
            cout << x << " ";
        }
        cout << endl;  
    }

    return 0;
}