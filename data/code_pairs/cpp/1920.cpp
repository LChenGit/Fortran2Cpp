#ifndef CKM_H
#define CKM_H

#include <string>

class CKM {
public:
    double V_ud, V_us, V_ub, V_cd, V_cs, V_cb, V_td, V_ts, V_tb;
    double V_ud2, V_us2, V_ub2, V_cd2, V_cs2, V_cb2, V_td2, V_ts2, V_tb2;
    std::string InCKM;

    void SetCKM(double Vud, double Vus, double Vub, double Vcd, double Vcs, double Vcb, double Vtd, double Vts, double Vtb);
};

#endif // CKM_H