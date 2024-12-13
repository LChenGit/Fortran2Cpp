#include <array>
#include <iostream>

class cnvg_I {
public:
    static void cnvg(std::array<double, 1234>& PNEW, const std::array<double, 1234>& P, const std::array<double, 1234>& P1, int NITER, double& PL) {
        PL = 0.0;
        for (int i = 0; i < NITER; ++i) {
            PNEW[i] = (P[i] + P1[i]) / 2.0;
            PL += PNEW[i];
        }
    }
};

int main() {
    std::array<double, 1234> PNEW;
    std::array<double, 1234> P;
    std::array<double, 1234> P1;
    double PL = 0.0;
    int NITER = 1234;

    // Initialize arrays
    P.fill(1.0);
    P1.fill(2.0);

    // Call the function
    cnvg_I::cnvg(PNEW, P, P1, NITER, PL);

    std::cout << "PL: " << PL << std::endl;
    std::cout << "First element of PNEW: " << PNEW[0] << std::endl;

    return 0;
}