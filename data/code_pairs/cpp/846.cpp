#include <vector>

void propage(int ip1, int ip2, int& ier, int iirai,
             int npn, int nsn, int ncn, int nfront, int nd, int nk, int npar,
             std::vector<std::vector<std::vector<float>>>& ys,
             std::vector<std::vector<std::vector<int>>>& iys,
             std::vector<std::vector<std::vector<double>>>& dys,
             std::vector<std::vector<std::vector<int>>>& iseg,
             std::vector<std::vector<std::vector<int>>>& icel,
             std::vector<int>& nrai, std::vector<int>& ncel, std::vector<int>& nseg,
             std::vector<int>& irai, std::vector<int>& iraf, std::vector<int>& irpop,
             std::vector<std::vector<int>>& irais, std::vector<int>& isatr,
             std::vector<int>& isats, std::vector<int>& isatc) {
    ip1 -= 1;
    ip2 -= 1;
    iirai -= 1;

    if (ier != 0) {
        iys[1][iirai][ip1] = -1;
    } else {
        nrai[ip2] += 1;
        int idx = nrai[ip2] - 1; // Adjust for 0-based indexing
        iys[1][idx][ip2] = 0;
        iys[1][iirai][ip1] = nrai[ip2];
        dys[0][idx][ip2] = dys[0][iirai][ip1];
        dys[1][idx][ip2] = dys[1][iirai][ip1];
    }
}

// Test function omitted for brevity