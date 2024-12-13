#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<float>> a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<float>> b = {
        a[1], // Second row of `a`
        a[0]  // First row of `a`
    };
    
    vector<vector<float>> c = {
        a[2], // Third row of `a`
        a[1]  // Second row of `a`
    };

    // Print matrix `a`
    cout << "Matrix a:" << endl;
    for (const auto &row : a) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Print matrix `b`
    cout << "Matrix b:" << endl;
    for (const auto &row : b) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    // Print matrix `c`
    cout << "Matrix c:" << endl;
    for (const auto &row : c) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}