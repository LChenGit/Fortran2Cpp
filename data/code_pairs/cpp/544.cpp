#include <vector>
#include <string>

class KPoints {
public:
    int nkpoints;
    std::vector<std::vector<float>> special_k;
    std::vector<std::vector<float>> special_k_orig;
    std::vector<float> weight_k;
    std::vector<float> weight_k_orig;
    std::vector<std::vector<float>> scale_k;

    std::string kptpreference;

    void allocateSpecialK(int dim1, int dim2) {
        special_k.resize(dim1, std::vector<float>(dim2));
    }

    // Optionally, other member functions...
};