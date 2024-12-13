// JACG__genmod.h
#include <vector>
#include <cstdint>

class JACG__genmod {
public:
    static void JACG(std::vector<double>& XJAC, int32_t NP, double ALPHA, double BETA) {
        for (int i = 0; i < NP; ++i) {
            XJAC[i] = ALPHA * XJAC[i] + BETA;
        }
    }
};