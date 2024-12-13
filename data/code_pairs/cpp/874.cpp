#include <vector>

class MOD_DG_Vars {
public:
    std::vector<std::vector<double>> D;
    std::vector<std::vector<double>> D_T;
    std::vector<std::vector<double>> D_Hat;
    std::vector<std::vector<double>> D_Hat_T;
    std::vector<double> L_HatMinus;
    std::vector<double> L_HatPlus;
    std::vector<std::vector<double>> DVolSurf;
    std::vector<std::vector<std::vector<std::vector<double>>>> U;
    std::vector<std::vector<std::vector<std::vector<double>>>> Ut;
    int nTotalU;                
    int nDOFFace;               
    int nDOFElem;               
    std::vector<std::vector<std::vector<std::vector<double>>>> U_master;
    std::vector<std::vector<std::vector<std::vector<double>>>> U_slave;
    std::vector<std::vector<std::vector<std::vector<double>>>> Flux_master;
    std::vector<std::vector<std::vector<std::vector<double>>>> Flux_slave;
    std::vector<std::vector<std::vector<std::vector<double>>>> UPrim;
    std::vector<std::vector<std::vector<std::vector<double>>>> UPrim_master;
    std::vector<std::vector<std::vector<std::vector<double>>>> UPrim_slave;
    int SplitDG;
    std::vector<std::vector<std::vector<double>>> UPrim_Boundary;
    bool DGInitIsDone = false;
};