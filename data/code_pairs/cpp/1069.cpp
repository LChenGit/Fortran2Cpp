#include <vector>

class FittingMod {
public:
    int* ntrace2 = nullptr;
    int* nfit2 = nullptr;
    int* ilinkpsf2 = nullptr;
    int* nline2 = nullptr;
    std::vector<int> isol2;
    std::vector<double> line2;
    std::vector<double> sol2;

    FittingMod() = default;

    ~FittingMod() {
        delete ntrace2;
        delete nfit2;
        delete ilinkpsf2;
        delete nline2;
    }
};