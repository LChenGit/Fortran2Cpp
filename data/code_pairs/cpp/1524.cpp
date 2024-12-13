#include <vector>

namespace DataShadowingCombinations {

class ShadowingCombinations {
public:
    bool UseThisSurf = false;
    int NumGenSurf = 0;
    std::vector<int> GenSurf;
    int NumBackSurf = 0;
    std::vector<int> BackSurf;
    int NumSubSurf = 0;
    std::vector<int> SubSurf;
};

std::vector<ShadowingCombinations> ShadowComb;

} // namespace DataShadowingCombinations