#include <vector>
#include <cstdint>

class Mod_MBVariables {
public:
    int32_t incp;

    std::vector<double> Nslv, dNslvdxi, dNslv2dxi2;
    std::vector<double> Mslv, dMslvdeta, dMslv2deta2;
    std::vector<double> R1;
    std::vector<std::vector<double>> dR1, ddR1;
    std::vector<double> Rslv, gap;
    std::vector<std::vector<double>> dRslv, ddRslv;
    std::vector<double> Rmst;
    std::vector<std::vector<double>> dRmst, ddRmst;
    std::vector<int32_t> PTS_Active;

    std::vector<std::vector<double>> N, Na, Nb, Ta, tb;
    std::vector<std::vector<double>> Nhat, That, D, Nbar;
    std::vector<std::vector<double>> Kgeo, KG1, KG2, KG3, KG4;

    std::vector<std::vector<double>> KLM, FLM, GLM;
    std::vector<int32_t> disptempLM;
    std::vector<std::vector<double>> KeqLM, FeqLM, DispeqLM;

    std::vector<int32_t> PTS_conn;
};