#include <vector>
#include <iostream>

void ZMESS(int& NUMESS, int& LESSEL, int& LESSDL, 
           std::vector<int>& IDESS, std::vector<int>& NEESS, std::vector<int>& NEDSS, 
           std::vector<int>& IXEESS, std::vector<int>& IXEDSS, std::vector<int>& LTEESS, 
           std::vector<int>& LTSSS, std::vector<int>& LTSNC, std::vector<float>& FAC, 
           bool USESDF) {

    if (NUMESS <= 0) return;

    int JESS = 0;
    int JNE = 0;
    int JDF = 0;
    int IDFE = 0;
    for (int IESS = 0; IESS < NUMESS; ++IESS) {
        int JNELST = JNE;
        int JDFLST = JDF;
        int nd1 = IXEDSS[IESS];
        int IDFB = nd1;
        for (int N = 0; N < NEESS[IESS]; ++N) {
            int NE = N + IXEESS[IESS];
            int ICNT = LTSNC[NE];
            IDFE = IDFB + ICNT - 1;
            if (LTEESS[NE] > 0) {
                LTEESS[JNE] = LTEESS[NE];
                LTSSS[JNE]  = LTSSS[NE];
                LTSNC[JNE]  = LTSNC[NE];
                ++JNE;
                if (USESDF) {
                    for (int nd = IDFB; nd <= IDFE; ++nd) {
                        FAC[JDF] = FAC[nd - 1];  // Adjust index for zero-based
                        ++JDF;
                    }
                }
            }
            IDFB = IDFE + 1;
        }
        int N = JNE - JNELST;
        if (N > 0) {
            IDESS[JESS] = IDESS[IESS];
            NEESS[JESS] = N;
            IXEESS[JESS] = JNELST + 1;
            ++JESS;
            if (USESDF) {
                NEDSS[JESS - 1] = JDF - JDFLST;  // -1 since JESS was incremented
                IXEDSS[JESS - 1] = JDFLST + 1;
            }
        }
    }
    NUMESS = JESS;
    LESSEL = JNE;
    if (USESDF) {
        if (IDFE != LESSDL) {  // No -1 adjustment needed here since it's a direct check
            std::cerr << "ZMESS: Internal error" << std::endl;
            std::exit(1);
        }
        LESSDL = JDF;
    }
}

int main() {
    // Example usage of ZMESS function in C++
    // Define and initialize variables as needed.
    // Call ZMESS function.
    // Check results.

    return 0;
}