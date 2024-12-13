#include <vector>

class MOD_Lifting_Vars {
public:
    std::vector<std::vector<std::vector<std::vector<float>>>> gradPx_slave;
    std::vector<std::vector<std::vector<std::vector<float>>>> gradPy_slave;
    std::vector<std::vector<std::vector<std::vector<float>>>> gradPz_slave;
    std::vector<std::vector<std::vector<std::vector<float>>>> gradPx_master;
    std::vector<std::vector<std::vector<std::vector<float>>>> gradPy_master;
    std::vector<std::vector<std::vector<std::vector<float>>>> gradPz_master;
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> gradPx;
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> gradPy;
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> gradPz;
    std::vector<std::vector<std::vector<std::vector<float>>>> FluxX;
    std::vector<std::vector<std::vector<std::vector<float>>>> FluxY;
    std::vector<std::vector<std::vector<std::vector<float>>>> FluxZ;
    bool LiftingInitIsDone = false;
};