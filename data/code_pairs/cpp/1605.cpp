#include <string>

class ModuleGlobal {
public:
    std::string dirIN = std::string(30, ' ');
    std::string dirOUT = std::string(30, ' ');
    std::string dirTMP = std::string(30, ' ');
    std::string simname = std::string(30, ' ');
    std::string filesim = std::string(30, ' ');
    std::string filexy = std::string(30, ' ');
    std::string filename = std::string(100, ' ');

    int flagbed = 0;
    double beta = 0.0;
    double beta0 = 0.0;
    double betaold = 0.0;
    double theta = 0.0;
    double theta0 = 0.0;
    double thetaold = 0.0;
    double ds = 0.0;
    double ds0 = 0.0;
    double dsold = 0.0;
    double Rp = 0.0;
    double rpic = 0.0;
    double rpic0 = 0.0;
    int jmodel = 0;
    double Cf = 0.0;
    double Cf0 = 0.0;
    double Cfold = 0.0;
    double CD = 0.0;
    double CT = 0.0;
    double phi = 0.0;
    double phiD = 0.0;
    double phiT = 0.0;
    double F0 = 0.0;

    double Ef = 0.0;
    double Eb = 0.0;
    double Eo = 0.0;
    double Ebound = 0.0;
    double Lhalfvalley = 0.0;
    double Ltransvalley = 0.0;
    int jbound = 0;

    int flagxy0 = 0;
    int flag_ox = 0;
    int N = 0;
    int Nold = 0;
    int N0 = 0;
    int Nrand = 0;
    int jre = 0;
    int jnco = 0;
    int ksavgol = 0;
    double deltas = 0.0;
    double deltas0 = 0.0;
    double dsmin = 0.0;
    double dsmax = 0.0;
    double tollc = 0.0;
    double stdv = 0.0;

    int flag_time = 0;
    int flag_dt = 0;
    int ivideo = 0;
    int ifile = 0;
    int nend = 0;
    double TT = 0.0;
    double TTs = 0.0;
    double kTTfco = 0.0;
    double tt0 = 0.0;
    double dt0 = 0.0;
    double cstab = 0.0;
};