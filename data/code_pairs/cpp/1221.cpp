#include <iostream>
#include <vector>
#include <cassert>

void FRPLOT(int& N, std::vector<double>& S, std::vector<double>& X,
            std::vector<double>& HK, std::vector<double>& TH,
            std::vector<double>& UE, std::vector<double>& VE,
            double& XTR, double& FREF, double& XOFF, double& XSF,
            double& YOFF, double& YSF, char& CHF) {
    N = 0;
}

void testFRPLOT() {
    int N = 10;
    std::vector<double> S(N), X(N), HK(N), TH(N), UE(N), VE(N);
    double XTR, FREF, XOFF, XSF, YOFF, YSF;
    char CHF = 'A';

    FRPLOT(N, S, X, HK, TH, UE, VE, XTR, FREF, XOFF, XSF, YOFF, YSF, CHF);

    assert(N == 0);
    std::cout << "Test passed: N is set to 0." << std::endl;
}

int main() {
    testFRPLOT();
    return 0;
}