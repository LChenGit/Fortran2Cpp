#include <vector>
#include <complex>

template<typename T>
class SymCnstODiag {
public:
    static std::vector<std::vector<T>> sym_cnst_odiag_real_dp(const std::vector<std::vector<T>>& matrix) {
        std::vector<std::vector<T>> result = matrix;
        for (auto& row : result) {
            for (auto& elem : row) {
                elem += 1.0;
            }
        }
        return result;
    }
};