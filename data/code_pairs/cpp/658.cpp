#include <vector>
#include <memory>

class fittingmod {
public:
    std::unique_ptr<int> np2;
    std::vector<double> xp2;
    std::vector<double> yp2;
    std::vector<double> ep2;
    std::vector<double> th2;
    std::vector<double> xpos2;
    std::vector<double> ypos2;

    fittingmod() = default;
    ~fittingmod() = default;

    fittingmod(const fittingmod&) = delete;
    fittingmod(fittingmod&&) = delete;
    fittingmod& operator=(const fittingmod&) = delete;
    fittingmod& operator=(fittingmod&&) = delete;
};