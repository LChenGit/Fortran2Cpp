#include <vector>
#include <cstdint>

class GsbpMod {
public:
    int nclx1, ncly1;
    std::vector<int> lstpl, lstpm;

    GsbpMod(int x1, int y1) : nclx1(x1), ncly1(y1) {
        lstpl.resize(nclx1, 1);
        lstpm.resize(ncly1, 2);
    }

    void incrementArrays() {
        for (auto& el : lstpl) el += 1;
        for (auto& el : lstpm) el += 1;
    }
};