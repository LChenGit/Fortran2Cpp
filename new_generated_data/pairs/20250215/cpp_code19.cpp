#include <vector>
#include <cmath>
#include <algorithm> // For std::min
#include <iostream>

using namespace std;

void binint(const vector<vector<short>>& ia, int npix, int nlines, 
            int inval, int idx, int idy, double* x, double* y, double* z, 
            double* w, int& nbin) {
    nbin = 0;
    for (int jmin = 1; jmin <= nlines; jmin += idy) {
        int jmax = std::min(jmin + idy - 1, nlines);
        for (int imin = 1; imin <= npix; imin += idx) {
            int imax = std::min(imin + idx - 1, npix);
            double sum = 0.0;
            int npt = 0;
            int ix = 0;
            int iy = 0;
            for (int j = jmin; j <= jmax; ++j) {
                for (int i = imin; i <= imax; ++i) {
                    if (ia[j - 1][i - 1] != inval) {
                        sum += ia[j - 1][i - 1];
                        npt++;
                        ix += i;
                        iy += j;
                    }
                }
            }
            if (npt >= 1) {
                x[nbin] = static_cast<double>(ix) / npt;
                y[nbin] = static_cast<double>(iy) / npt;
                z[nbin] = sum / npt;
                w[nbin] = std::sqrt(static_cast<double>(npt));
                nbin++;
            }
        }
    }
}

int main() {
    // Test case:
    const int NPIX = 2;
    const int NLINES = 2;
    const int INVAL = -1;
    const int IDX = 1;
    const int IDY = 1;

    vector<vector<short>> IA = {
        {1, -1},
        {3, 4}
    };

    const int NBIN_EXPECTED = 3;
    double expected_x[] = {1.0, 1.0, 2.0};
    double expected_y[] = {1.0, 2.0, 2.0};
    double expected_z[] = {1.0, 3.0, 4.0};
    double expected_w[] = {1.0, 1.0, 1.0};

    int NBIN = 0;
    double* X = new double[NBIN_EXPECTED];
    double* Y = new double[NBIN_EXPECTED];
    double* Z = new double[NBIN_EXPECTED];
    double* W = new double[NBIN_EXPECTED];

    binint(IA, NPIX, NLINES, INVAL, IDX, IDY, X, Y, Z, W, NBIN);

    if (NBIN != NBIN_EXPECTED) {
        delete[] X;
        delete[] Y;
        delete[] Z;
        delete[] W;
        cout << "Test failed: Number of bins mismatch!" << endl;
        return 1;
    }

    const double TOLERANCE = 1e-9;
    for (int i = 0; i < NBIN; ++i) {
        if (fabs(X[i] - expected_x[i]) > TOLERANCE) {
            delete[] X;
            delete[] Y;
            delete[] Z;
            delete[] W;
            cout << "Test failed: X[" << i << "] mismatch!" << endl;
            return 1;
        }
        if (fabs(Y[i] - expected_y[i]) > TOLERANCE) {
            delete[] X;
            delete[] Y;
            delete[] Z;
            delete[] W;
            cout << "Test failed: Y[" << i << "] mismatch!" << endl;
            return 1;
        }
        if (fabs(Z[i] - expected_z[i]) > TOLERANCE) {
            delete[] X;
            delete[] Y;
            delete[] Z;
            delete[] W;
            cout << "Test failed: Z[" << i << "] mismatch!" << endl;
            return 1;
        }
        if (fabs(W[i] - expected_w[i]) > TOLERANCE) {
            delete[] X;
            delete[] Y;
            delete[] Z;
            delete[] W;
            cout << "Test failed: W[" << i << "] mismatch!" << endl;
            return 1;
        }
    }

    delete[] X;
    delete[] Y;
    delete[] Z;
    delete[] W;

    cout << "All tests passed!" << endl;
    return 0;
}