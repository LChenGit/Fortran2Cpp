#include <vector>
#include <string>

class PARS {
public:
    static const int DP = 8;
    static const int NMAX = 50;
    static const int LMAX = 0;
    static const int GMAX = 150;
    int NUSE, LUSE, GUSEX, GUSEY;
    double BOSC, HBAR2M, HBROMG;
    double KAPPAR, KAPPAS, V0R, V0S;
    std::string QUAD;
};

class GAUSS : public PARS {
public:
    std::vector<double> WX, WY;
    std::vector<double> XMESH, YMESH;

    GAUSS() : WX(GMAX), WY(GMAX), XMESH(GMAX), YMESH(GMAX) {}
};

class LOGS : public PARS {
public:
    std::vector<std::vector<double>> LOGANL;

    LOGS() : LOGANL(NMAX + 1, std::vector<double>(LMAX + 1)) {}
};

class LX1D : public PARS {
public:
    std::vector<double> X1D;
    std::vector<std::vector<std::vector<double>>> L1D;

    LX1D() : X1D(GMAX), L1D(NMAX + 1, std::vector<std::vector<double>>(LMAX + 1, std::vector<double>(GMAX))) {}
};

class HRHOMAT : public PARS {
public:
    std::vector<std::vector<double>> HMAT, RHOS;

    HRHOMAT() : HMAT(NMAX + 1, std::vector<double>(NMAX + 1)), RHOS(NMAX + 1, std::vector<double>(NMAX + 1)) {}
};

class TVUMAT : public PARS {
public:
    std::vector<std::vector<double>> TUMAT, V1MAT;
    std::vector<std::vector<std::vector<std::vector<double>>>> VMAT;

    TVUMAT() : TUMAT(NMAX + 1, std::vector<double>(NMAX + 1)), V1MAT(NMAX + 1, std::vector<double>(NMAX + 1)), VMAT(NMAX + 1, std::vector<std::vector<std::vector<double>>>(NMAX + 1, std::vector<std::vector<double>>(NMAX + 1, std::vector<double>(NMAX + 1)))) {}
};

class EIGENS : public PARS {
public:
    std::vector<double> EIGVAL, EIGVAL_OLD;
    std::vector<std::vector<double>> EIGVEC;
    std::vector<int> EIGORD;

    EIGENS() : EIGVAL(NMAX + 1), EIGVAL_OLD(NMAX + 1), EIGVEC(NMAX + 1, std::vector<double>(NMAX + 1)), EIGORD(NMAX + 1) {}
};