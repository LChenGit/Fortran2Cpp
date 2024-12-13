// hplusf.h
#ifndef HPLUSF_H
#define HPLUSF_H

#include <vector>

class Hplusf {
public:
    static void hplusf(std::vector<std::vector<double>>& F, const std::vector<std::vector<double>>& H, int NORBS) {
        for (int i = 0; i < NORBS; ++i) {
            for (int j = 0; j < NORBS; ++j) {
                F[i][j] += H[i][j];
            }
        }
    }
};

#endif // HPLUSF_H