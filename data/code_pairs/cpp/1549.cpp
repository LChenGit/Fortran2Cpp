#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

void COMPRO(std::vector<double>& PROFILE, const std::vector<double>& EMINT, int NFOBR, double W, int JFIRST, int JLAST) {
    for (int K = 0; K < NFOBR; ++K) {
        if (JFIRST == JLAST) {
            PROFILE[K] = EMINT[K];
        } else {
            PROFILE[K] = PROFILE[K] + W * EMINT[K];
        }
    }
}