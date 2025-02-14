#include <cmath>
#include <cassert>

namespace funcs {
    void FUNC(int NDIM, double* U, int* ICP, double* PAR, int IJAC, double* F, double* DFDU, double* DFDP) {
        double u1 = U[0];
        double u2 = U[1];
        double e = exp(u2);

        F[0] = -u1 + PAR[0] * (1.0 - u1) * e;
        F[1] = -u2 + PAR[0] * PAR[1] * (1.0 - u1) * e - PAR[2] * u2;
    }

    void STPNT(int NDIM, double* U, double* PAR, double T) {
        PAR[0] = 0.0;
        PAR[1] = 8.0;
        PAR[2] = 3.0;

        U[0] = 0.0;
        U[1] = 0.0;
    }

    void BCND() {}
    void ICND() {}
    void FOPT() {}
    void PVLS() {}
}

int main() {
    const int NDIM = 2;
    double U[NDIM] = {0.0, 0.0};
    double PAR[3];
    int ICP[3]; // Placeholder for ICP
    double F[NDIM];
    double DFDU[2];
    double DFDP[3];
    int IJAC = 0; // Placeholder

    funcs::STPNT(NDIM, U, PAR, 0.0);

    assert(PAR[0] == 0.0);
    assert(PAR[1] == 8.0);
    assert(PAR[2] == 3.0);

    assert(U[0] == 0.0);
    assert(U[1] == 0.0);

    funcs::FUNC(NDIM, U, ICP, PAR, IJAC, F, DFDU, DFDP);

    assert(F[0] == 0.0);
    assert(F[1] == 0.0);

    funcs::BCND();
    funcs::ICND();
    funcs::FOPT();
    funcs::PVLS();

    return 0;
}