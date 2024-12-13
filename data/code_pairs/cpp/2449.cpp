#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<double>> Array2D;

void clawpack5_rpt2adv_manifold(int ixy, int imp, int maxm, int meqn, 
                                int mwaves, int maux, int mbc, int mx, 
                                const Array2D& ql, const Array2D& qr, 
                                const Array2D& aux1, const Array2D& aux2, 
                                const Array2D& aux3, const Array2D& asdq, 
                                Array2D& bmasdq, Array2D& bpasdq) {
    int iface = 3 - ixy;
    for (int i = 2 - mbc; i <= mx + mbc; ++i) {
        int i1 = i - 2 + imp;
        for (int m = 0; m < meqn; ++m) {
            bmasdq[m][i + mbc - 1] = std::min(aux2[1 + iface - 1][i1 + mbc - 1], 0.0) * asdq[m][i + mbc - 1];
            bpasdq[m][i + mbc - 1] = std::max(aux3[1 + iface - 1][i1 + mbc - 1], 0.0) * asdq[m][i + mbc - 1];
        }
    }
}

int main() {
    int meqn = 2;
    int maux = 3;
    int mbc = 2;
    int maxm = 10;
    int mx = 10;
    int ixy = 1, imp = 1;

    Array2D ql(meqn, std::vector<double>(maxm + 2 * mbc, 1.0));
    Array2D qr(meqn, std::vector<double>(maxm + 2 * mbc, 2.0));
    Array2D asdq(meqn, std::vector<double>(maxm + 2 * mbc, 1.0));
    Array2D bmasdq(meqn, std::vector<double>(maxm + 2 * mbc, 0.0));
    Array2D bpasdq(meqn, std::vector<double>(maxm + 2 * mbc, 0.0));
    Array2D aux1(maux, std::vector<double>(maxm + 2 * mbc, 0.0));
    Array2D aux2(maux, std::vector<double>(maxm + 2 * mbc, 1.0));
    Array2D aux3(maux, std::vector<double>(maxm + 2 * mbc, 2.0));

    clawpack5_rpt2adv_manifold(ixy, imp, maxm, meqn, 0, maux, mbc, mx, ql, qr, aux1, aux2, aux3, asdq, bmasdq, bpasdq);

    // Print some results to verify
    std::cout << "bmasdq:" << std::endl;
    for (int j = 0; j < meqn; ++j) {
        for (int i = 0; i < maxm + 2 * mbc; ++i) {
            std::cout << bmasdq[j][i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "bpasdq:" << std::endl;
    for (int j = 0; j < meqn; ++j) {
        for (int i = 0; i < maxm + 2 * mbc; ++i) {
            std::cout << bpasdq[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}