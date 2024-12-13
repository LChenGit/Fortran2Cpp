#include <vector>
#include <algorithm> // For std::max

void pbm_cut(std::vector<std::vector<int>>& ks, int kstart, int kend, int nthds) {
    int kend0 = kend;
    int kstart0 = kstart;
    int ithds = 0;

    while (ithds < nthds - 1) {
        int nn = kend0 - kstart0 + 1;
        int nblk = nn / (nthds - ithds);
        nblk = std::max(nblk, 0); // Ensure nblk is not negative

        if (nblk % 2 == 1) {
            nblk += 1;
        }

        ks[0][ithds] = kstart0;
        ks[1][ithds] = kstart0 + nblk - 1;
        kstart0 += nblk;
        ithds++;
    }

    int nn = kend0 - kstart0 + 1;
    int nblk = nn;
    nblk = std::max(nblk, 0);

    ks[0][ithds] = kstart0;
    ks[1][ithds] = kstart0 + nblk - 1;
}