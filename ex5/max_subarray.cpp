#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // בשביל max

using namespace std;

// פונקציה ליצירת מערך רנדומלי
vector<int> generate_random_array(int size, int seed) {
    srand(seed); // הגדרת seed
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 - 25; // תחום המספרים [-25, 74]
    }
    return array;
}

// אלגוריתם 1 - O(n^3)
int algorithm1(const vector<int>& array) {
    int n = array.size();
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            best = max(best, sum);
        }
    }
    return best;
}

// אלגוריתם 2 - O(n^2)
int algorithm2(const vector<int>& array) {
    int n = array.size();
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = max(best, sum);
        }
    }
    return best;
}

// אלגוריתם 3 - O(n) - אלגוריתם קדאן
int algorithm3(const vector<int>& array) {
    int best = 0, sum = 0;
    for (int k = 0; k < array.size(); k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    return best;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <seed> <size>" << endl;
        return 1;
    }

    unsigned int seed = stoi(argv[1]);
    int n = stoi(argv[2]);
    
    cout << "Running for array size: " << n << endl;

    // יצירת מערך רנדומלי
    vector<int> array = generate_random_array(n, seed);

    // הרצת אלגוריתם 1
    cout << "Algorithm 1 (O(n^3)): " << algorithm1(array) << endl;

    // הרצת אלגוריתם 2
    cout << "Algorithm 2 (O(n^2)): " << algorithm2(array) << endl;

    // הרצת אלגוריתם 3
    cout << "Algorithm 3 (O(n)): " << algorithm3(array) << endl;

    return 0;
}