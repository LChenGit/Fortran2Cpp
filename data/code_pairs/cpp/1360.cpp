#include <iostream>
#include <vector>
#include <complex>
#include <string>

void decodems(const std::vector<std::complex<float>>& cdat, int npts, const std::vector<std::vector<std::complex<float>>>& cw, int i1, int nchar, std::vector<std::vector<float>>& s2, std::string& msg) {
    const std::string cc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ./?-                 _     @";
    msg.clear();
    for (int j = 0; j < nchar; ++j) {
        int ia = i1 + j * 56 - 1; // Adjusted for 1-based indexing in Fortran
        float smax = 0.0f;
        int kpk = 0;
        for (int k = 0; k <= 40; ++k) {
            int kk = (k == 40) ? 57 : k;
            std::complex<float> z(0.0f, 0.0f);
            for (int i = 0; i < 56; ++i) {
                z += cdat[ia + i] * std::conj(cw[i][kk]);
            }
            float ss = std::abs(z);
            s2[k][j] = ss;
            if (ss > smax) {
                smax = ss;
                kpk = kk;
            }
        }
        msg += cc[kpk];
    }
}

int main() {
    int npts = 224;
    int nchar = 4;
    int i1 = 1; // Fortran 1-based indexing
    std::vector<std::complex<float>> cdat(npts);
    std::vector<std::vector<std::complex<float>>> cw(56, std::vector<std::complex<float>>(64));
    std::vector<std::vector<float>> s2(64, std::vector<float>(nchar, 0.0f));
    std::string msg;

    // Initialize test data
    for (int i = 0; i < npts; ++i) {
        cdat[i] = std::complex<float>(i + 1, i + 1);
    }
    for (int i = 0; i < 56; ++i) {
        for (int j = 0; j < 64; ++j) {
            cw[i][j] = std::complex<float>(i + j + 1, i - j); // Adjusted for 1-based indexing
        }
    }

    decodems(cdat, npts, cw, i1, nchar, s2, msg);

    std::cout << "Message: " << msg << std::endl;

    return 0;
}