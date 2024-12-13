#include <vector>

void FSCAN(int& OPCODE, int& NLC, int& NLI, int& NLD, std::vector<char>& NLCPRM, 
           std::vector<int>& NLIPRM, std::vector<double>& NLDPRM, std::vector<double>& WORLD, 
           std::vector<double>& PIXEL, int& CONTRL, std::vector<double>& CONTXT, int& IERR) {
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