// tf.cpp
#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<double>>;

void tf(const Matrix& UA, const Matrix& GA, const Matrix& UB, const Matrix& GB, Matrix& T, int NORBS) {
    for (int i = 0; i < NORBS; ++i) {
        for (int j = 0; j < NORBS; ++j) {
            T[i][j] = UA[i][j] + GA[i][j] - UB[i][j] - GB[i][j];
        }
    }
}

int main() {
    int NORBS = 2;
    Matrix UA = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix GA = {{0.5, 0.5}, {0.5, 0.5}};
    Matrix UB = {{1.0, 1.0}, {1.0, 1.0}};
    Matrix GB = {{0.2, 0.2}, {0.2, 0.2}};
    Matrix T(NORBS, vector<double>(NORBS, 0.0));

    tf(UA, GA, UB, GB, T, NORBS);

    cout << "T Matrix:" << endl;
    for (const auto& row : T) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}