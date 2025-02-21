#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

void binint(const vector<int16_t>& ia, int npix, int nlines, int inval, int idx, int idy,
            vector<double>& x, vector<double>& y, vector<double>& z, 
            vector<double>& w, int& nbin) {
    nbin = 0;
    for (int jmin = 0; jmin < nlines; jmin += idy) {
        int jmax = min(jmin + idy, nlines);
        for (int imin = 0; imin < npix; imin += idx) {
            int imax = min(imin + idx, npix);
            double sum = 0.0;
            int npt = 0;
            int ix = 0;
            int iy = 0;
            for (int j = jmin; j < jmax; ++j) {
                for (int i = imin; i < imax; ++i) {
                    int index = j * npix + i;
                    if (ia[index] != inval) {
                        sum += ia[index];
                        npt++;
                        ix += (i + 1); // Adjusting for 1-based in Fortran
                        iy += (j + 1);
                    }
                }
            }
            if (npt >= 1) {
                nbin++;
                if (nbin > x.size()) {
                    x.resize(nbin);
                    y.resize(nbin);
                    z.resize(nbin);
                    w.resize(nbin);
                }
                x[nbin - 1] = static_cast<double>(ix) / npt;
                y[nbin - 1] = static_cast<double>(iy) / npt;
                z[nbin - 1] = sum / npt;
                w[nbin - 1] = sqrt(static_cast<double>(npt));
            }
        }
    }
}

bool has_close_elements(const vector<double>& a, const vector<double>& b, double tolerance) {
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > tolerance) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test case setup
    const int npix = 4;
    const int nlines = 4;
    const int inval = -999;
    const int idx = 2;
    const int idy = 2;
    const int nbin_expected = 4;

    // Initialize input array
    vector<int16_t> ia(npix * nlines);
    for (int j = 0; j < nlines; ++j) {
        for (int i = 0; i < npix; ++i) {
            ia[j * npix + i] = j * npix + i + 1; // Fill with 1, 2, ..., 16
        }
    }

    // Expected results
    vector<double> x_expected = {1.5, 3.5, 1.5, 3.5};
    vector<double> y_expected = {1.5, 1.5, 3.5, 3.5};
    vector<double> z_expected = {3.5, 5.5, 11.5, 13.5};
    vector<double> w_expected = {2.0, 2.0, 2.0, 2.0};

    // C++ arrays
    vector<double> x_cpp(nbin_expected);
    vector<double> y_cpp(nbin_expected);
    vector<double> z_cpp(nbin_expected);
    vector<double> w_cpp(nbin_expected);
    int nbin_cpp = 0;

    // Run C++ code
    binint(ia, npix, nlines, inval, idx, idy, x_cpp, y_cpp, z_cpp, w_cpp, nbin_cpp);

    // Compare results
    assert(nbin_cpp == nbin_expected);
    assert(has_close_elements(x_cpp, x_expected, 1e-6));
    assert(has_close_elements(y_cpp, y_expected, 1e-6));
    assert(has_close_elements(z_cpp, z_expected, 1e-6));
    assert(has_close_elements(w_cpp, w_expected, 1e-6));

    // If all tests pass
    cout << "All tests passed!" << endl;
    return 0;
}