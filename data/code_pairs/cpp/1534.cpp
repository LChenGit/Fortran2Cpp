#include <vector>

void ADDJUT(int MXND, std::vector<double>& XN, std::vector<double>& YN,
            std::vector<std::vector<int>>& LXK, std::vector<std::vector<int>>& KXL,
            std::vector<std::vector<int>>& NXL, std::vector<std::vector<int>>& LXN,
            std::vector<double>& ANGLE, std::vector<std::vector<int>>& LNODES,
            double XNEW, double YNEW, int& NNN, int& LLL,
            int NOLD, int& NLOOP, bool& JUTTED) {
    
    NNN += 1;
    XN[NNN-1] = XNEW;  // Adjusted index for 0-based arrays
    YN[NNN-1] = YNEW;

    LLL += 1;
    NXL[0][LLL-1] = NNN;  // Adjusted index for 0-based arrays
    NXL[1][LLL-1] = NOLD;

    for (int i = 0; i < 4; ++i) {
        LXN[i][NNN-1] = 0;  // Adjusted index for 0-based arrays
    }

    KXL[0][LLL-1] = 0;
    KXL[1][LLL-1] = 0;

    LNODES[0][NNN-1] = 0;
    LNODES[1][NNN-1] = NOLD;
    LNODES[2][NNN-1] = NOLD;
    LNODES[3][NNN-1] = -1;
    LNODES[4][NNN-1] = LLL;

    LNODES[0][NOLD-1] = 0;  // Adjusted index for 0-based arrays
    LNODES[2][NOLD-1] = NNN;
    LNODES[4][NOLD-1] = LLL;

    NLOOP += 2;
    JUTTED = true;
}