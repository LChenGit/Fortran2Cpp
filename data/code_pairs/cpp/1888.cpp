#include <iostream>
#include <vector>

void DLAMRG(int N1, int N2, const std::vector<double>& A, int DTRD1, int DTRD2, std::vector<int>& INDEX) {
    int IND1, IND2, N1SV, N2SV, I;

    N1SV = N1;
    N2SV = N2;
    IND1 = (DTRD1 > 0) ? 0 : N1 - 1;
    IND2 = (DTRD2 > 0) ? N1 : N1 + N2 - 1;
    I = 0;
    
    while (N1SV > 0 && N2SV > 0) {
        if (A[IND1] <= A[IND2]) {
            INDEX[I] = IND1 + 1; // Convert to 1-based indexing
            ++I;
            IND1 += DTRD1;
            --N1SV;
        } else {
            INDEX[I] = IND2 + 1; // Convert to 1-based indexing
            ++I;
            IND2 += DTRD2;
            --N2SV;
        }
    }

    while (N1SV > 0) {
        INDEX[I] = IND1 + 1; // Convert to 1-based indexing
        ++I;
        IND1 += DTRD1;
        --N1SV;
    }

    while (N2SV > 0) {
        INDEX[I] = IND2 + 1; // Convert to 1-based indexing
        ++I;
        IND2 += DTRD2;
        --N2SV;
    }
}

void testDLAMRG() {
    int N1 = 5, N2 = 5;
    std::vector<double> A = {1.0, 6.0, 3.0, 7.0, 5.0, 2.0, 8.0, 4.0, 9.0, 10.0};
    std::vector<int> INDEX(N1 + N2);
    DLAMRG(N1, N2, A, 1, 1, INDEX);

    std::cout << "INDEX:" << std::endl;
    for (int i = 0; i < N1 + N2; ++i) {
        std::cout << INDEX[i] << std::endl;
    }
}

int main() {
    testDLAMRG();
    return 0;
}