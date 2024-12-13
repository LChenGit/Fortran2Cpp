#include <vector>
#include <cassert>
#include <iostream>

const int nelemg = 100;

class Vect91 {
public:
    std::vector<double> xargat;
    Vect91() : xargat(nelemg, 0.0) {}
};

void xghis1(Vect91& vect91, const std::vector<std::vector<double>>& a, int ln, int nft, int nlt) {
    for (int i = nft; i <= nlt; ++i) {
        vect91.xargat[i-1] = a[0][i-1];
    }
}