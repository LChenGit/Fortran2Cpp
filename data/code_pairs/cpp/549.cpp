// fclaw2d_clawpatch5_fort_timeinterp.cpp
#include <vector>
#include <iostream>

void fclaw2d_clawpatch5_fort_timeinterp(int mx, int my, int mbc, int meqn, int psize, 
                                        const std::vector<std::vector<std::vector<double>>>& qcurr,
                                        const std::vector<std::vector<std::vector<double>>>& qlast,
                                        std::vector<std::vector<std::vector<double>>>& qinterp,
                                        double alpha, int& ierror) {
    ierror = 0;

    for (int m = 0; m < meqn; ++m) {
        for (int j = 0; j < my; ++j) {
            for (int i = 0; i < mx; ++i) {
                qinterp[m][i + mbc][j + mbc] = qlast[m][i + mbc][j + mbc] + alpha * (qcurr[m][i + mbc][j + mbc] - qlast[m][i + mbc][j + mbc]);
            }
        }
    }
}

int main() {
    int mx = 10, my = 10, mbc = 2, meqn = 1, psize = 100;
    double alpha = 0.5;
    int ierror;

    std::vector<std::vector<std::vector<double>>> qcurr(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 1.0)));
    std::vector<std::vector<std::vector<double>>> qlast(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 0.5)));
    std::vector<std::vector<std::vector<double>>> qinterp(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc)));

    fclaw2d_clawpatch5_fort_timeinterp(mx, my, mbc, meqn, psize, qcurr, qlast, qinterp, alpha, ierror);

    for (const auto& eqn : qinterp) {
        for (const auto& row : eqn) {
            for (const auto& val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "------" << std::endl;
    }

    return 0;
}