#include <vector>

void sqzlgv(const std::vector<int>& iptims, const std::vector<bool>& whotim, const std::vector<float>& valin, 
            std::vector<float>& valout) {
    for (size_t i = 0; i < iptims.size(); ++i) {
        if (whotim[iptims[i] - 1]) {
            valout.push_back(valin[i]);
        }
    }
}