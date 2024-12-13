#include <iostream>
#include <iomanip>

void selci_mxma(const double* a, int iac, int iar, 
                const double* b, int ibc, int ibr, 
                double* c, int icc, int icr,
                int nar, int nac, int nbc) {
    const double zero = 0.0;
    double bkj;
    int i1j = 0;
    for (int j = 0; j < nbc; ++j) {
        int ij = i1j;
        for (int i = 0; i < nar; ++i) {
            c[ij] = zero;
            ij += icc;
        }
        i1j += icr;
    }

    i1j = 0;
    int k1j = 0;
    for (int j = 0; j < nbc; ++j) {
        int i1k = 0;
        int kj = k1j;
        for (int k = 0; k < nac; ++k) {
            bkj = b[kj];
            if (bkj != zero) {
                int ij = i1j;
                int ik = i1k;
                for (int i = 0; i < nar; ++i) {
                    c[ij] += a[ik] * bkj;
                    ij += icc;
                    ik += iac;
                }
            }
            kj += ibc;
            i1k += iar;
        }
        i1j += icr;
        k1j += ibr;
    }
}

int main() {
    double a[] = {1.0, 2.0, 3.0, 4.0};
    double b[] = {5.0, 6.0, 7.0, 8.0};
    double c[4];
    
    int iac = 1, iar = 2, ibc = 1, ibr = 2;
    int icc = 1, icr = 2;
    int nar = 2, nac = 2, nbc = 2;

    selci_mxma(a, iac, iar, b, ibc, ibr, c, icc, icr, nar, nac, nbc);

    std::cout << "Resulting matrix C:" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << c[0] << " " << c[1] << std::endl;
    std::cout << c[2] << " " << c[3] << std::endl;

    return 0;
}