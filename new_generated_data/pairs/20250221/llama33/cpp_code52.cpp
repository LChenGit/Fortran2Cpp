#include <iostream>
using namespace std;

const int nsin = 10;
const int ndet = 5;

void init_input(short in[nsin][ndet]) {
    for (int i = 0; i < nsin; i++) {
        for (int j = 0; j < ndet; j++) {
            in[i][j] = (i + 1) * (j + 1);
        }
    }
}

bool has_close_elements(double out[nsin][ndet], int n, int m, double threshold) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (out[i][j] > threshold) {
                return false;
            }
        }
    }
    return true;
}

bool has_match_elements(short in[nsin][ndet], double out[nsin][ndet], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((double)out[i][j] != (double)in[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void convw(short in[nsin][ndet], int ns, int nd, int sbegin, int send, double out[nsin][ndet]) {
    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < nd; j++) {
            out[i][j] = (double)in[i][j];
        }
    }
}

int main() {
    short in[nsin][ndet];
    double out[nsin][ndet];

    init_input(in);

    convw(in, nsin, ndet, 1, 5, out);

    if (!has_close_elements(out, nsin, ndet, 100.0)) {
        cout << "Test case 2 failed: assertion failed" << endl;
        return 1;
    }

    if (!has_match_elements(in, out, nsin, ndet)) {
        cout << "Test case 3 failed: output does not match input" << endl;
        return 1;
    }

    cout << "All unit tests passed." << endl;

    return 0;
}