#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 100;
    vector<long long> a(N);
    vector<int> b(N, -99);
    int nerr = 0;
    int me = 1; // Simulate "me"

    // Initialize arrays
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1 + me * 100; // Fortran arrays are 1-indexed
    }

    // Modify b based on condition (simplified)
    if (me == 1) {
        for (int i = 10; i < 44; ++i) { // Adjusting for 0-indexing
            b[i] = a[i];
        }
    }

    // Validation and error checking (simplified)
    nerr = 0;
    for (int i = 0; i < N; ++i) {
        long long nval = i + 1 + me * 100; // Adjusting for 1-indexing
        if (a[i] != nval) {
            cout << "Error in a: " << i + 1 << " " << me << " " << a[i] << " " << nval << endl;
            nerr++;
        }
    }

    if (nerr == 0) {
        cout << "Result OK" << endl;
    } else {
        cout << "Number of errors: " << nerr << endl;
    }

    return 0;
}