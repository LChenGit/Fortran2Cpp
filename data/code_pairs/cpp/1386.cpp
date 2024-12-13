#include <vector>
#include <iostream>

void FSCAN(int OPCODE, int NLC, int NLI, int NLD,
           const std::vector<char>& NLCPRM, const std::vector<int>& NLIPRM, const std::vector<double>& NLDPRM,
           std::vector<double>& WORLD, std::vector<double>& PIXEL, int& CONTRL, std::vector<double>& CONTXT, int& IERR) {
    IERR = 0;

    if (OPCODE > 0) {
        PIXEL[0] = NLDPRM[0] + (WORLD[0] - NLDPRM[2]) / NLDPRM[4];
        double S = NLDPRM[3] + PIXEL[0] * NLDPRM[6];
        PIXEL[1] = NLDPRM[1] + (WORLD[1] - S) / NLDPRM[5];
        CONTRL = 0;
    } else if (OPCODE == 0) {
        if (NLC < 1 || NLI < 1 || NLD < 7) IERR = 1;
        if (NLDPRM[4] == 0.0) IERR = 1;
        if (NLDPRM[5] == 0.0) IERR = 1;
        if (NLDPRM[6] == 0.0) IERR = 1;
        CONTRL = 0;
    } else if (OPCODE == -1) {
        WORLD[0] = NLDPRM[2] + NLDPRM[4] * (PIXEL[0] - NLDPRM[0]);
        WORLD[1] = NLDPRM[3] + NLDPRM[5] * (PIXEL[1] - NLDPRM[1]) + PIXEL[0] * NLDPRM[6];
    } else {
        IERR = 1;
    }
}

int main() {
    int OPCODE = 1;
    int NLC = 1;
    int NLI = 1;
    int NLD = 7;
    std::vector<char> NLCPRM = {'X'};
    std::vector<int> NLIPRM = {0};
    std::vector<double> NLDPRM = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::vector<double> WORLD = {10.0, 20.0};
    std::vector<double> PIXEL(2);
    int CONTRL;
    std::vector<double> CONTXT(20);
    int IERR;

    FSCAN(OPCODE, NLC, NLI, NLD, NLCPRM, NLIPRM, NLDPRM, WORLD, PIXEL, CONTRL, CONTXT, IERR);
    
    std::cout << "PIXEL: " << PIXEL[0] << ", " << PIXEL[1] << std::endl;
    std::cout << "IERR: " << IERR << std::endl;

    return 0;
}