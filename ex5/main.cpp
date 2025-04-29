#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> generate_random_array(int n, unsigned int seed) {
    srand(seed);
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100 - 25; // values between -25 and 74
    }
    return array;
}

// Algorithm 1: O(n^3)
int algorithm1(const vector<int>& array) {
    int best = 0;
    for (int a = 0; a < array.size(); a++) {
        for (int b = a; b < array.size(); b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            best = max(best,sum);
        }
    }
    return best;
}

// Algorithm 2: O(n^2)
int algorithm2(const vector<int>& array) {
    int best = 0;
    for (int a = 0; a < array.size(); a++) {
        int sum = 0;
        for (int b = a; b < array.size(); b++) {
            sum += array[b];
            best = max(best,sum);
        }
    }
    return best;
}

// Algorithm 3: O(n) (Kadane's algorithm)
int algorithm3(const vector<int>& array) {
    int best = 0, sum = 0;
    for (int k = 0; k < array.size(); k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    return best;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <seed> <size>" << endl;
        return 1;
    }

    unsigned int seed = stoi(argv[1]);
    int n = stoi(argv[2]);

    vector<int> array = generate_random_array(n, seed);

    cout << algorithm1(array) << "\n";
    cout << algorithm2(array) << "\n";
    cout << algorithm3(array) << "\n";

    return 0;
}