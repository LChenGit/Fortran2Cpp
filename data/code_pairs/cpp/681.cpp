#include <cmath>
#include <vector>
#include <iostream>

void SLASDT(int N, int& LVL, int& ND, std::vector<int>& INODE, std::vector<int>& NDIML, std::vector<int>& NDIMR, int MSUB) {
    const float TWO = 2.0;

    int MAXN = (N > 1) ? N : 1;
    float TEMP = std::log(static_cast<float>(MAXN) / static_cast<float>(MSUB + 1)) / std::log(TWO);
    LVL = static_cast<int>(TEMP) + 1;

    int I = N / 2;
    INODE[0] = I + 1;
    NDIML[0] = I;
    NDIMR[0] = N - I - 1;
    int IL = -1;
    int IR = 0;
    int LLST = 1;

    for (int NLVL = 1; NLVL <= LVL - 1; ++NLVL) {
        for (I = 0; I < LLST; ++I) {
            IL += 2;
            IR += 2;
            int NCRNT = LLST + I - 1;
            NDIML[IL] = NDIML[NCRNT] / 2;
            NDIMR[IL] = NDIML[NCRNT] - NDIML[IL] - 1;
            INODE[IL] = INODE[NCRNT] - NDIMR[IL] - 1;
            NDIML[IR] = NDIMR[NCRNT] / 2;
            NDIMR[IR] = NDIMR[NCRNT] - NDIML[IR] - 1;
            INODE[IR] = INODE[NCRNT] + NDIML[IR] + 1;
        }
        LLST *= 2;
    }
    ND = LLST * 2 - 1;
}

int main() {
    const int N = 8;
    const int MSUB = 3;
    int LVL = 0;
    int ND = 0;
    std::vector<int> INODE(N), NDIML(N), NDIMR(N);

    SLASDT(N, LVL, ND, INODE, NDIML, NDIMR, MSUB);

    std::cout << "C++ Test Result:" << std::endl;
    std::cout << "LVL: " << LVL << std::endl;
    std::cout << "ND: " << ND << std::endl;
    std::cout << "INODE: ";
    for (int i = 0; i < ND; ++i) {
        std::cout << INODE[i] << " ";
    }
    std::cout << std::endl << "NDIML: ";
    for (int i = 0; i < ND; ++i) {
        std::cout << NDIML[i] << " ";
    }
    std::cout << std::endl << "NDIMR: ";
    for (int i = 0; i < ND; ++i) {
        std::cout << NDIMR[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}