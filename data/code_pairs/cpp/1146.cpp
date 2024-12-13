#include <vector>
#include <array>
#include <cstdint>

class ComputeCouplingFluidCmb {
public:
    static void computeCouplingFluidCmb(
        std::vector<std::array<float, 3>>& DISPL_CRUST_MANTLE,
        std::int32_t NGLOB_CM
    ) {
        for (std::int32_t i = 0; i < NGLOB_CM; ++i) {
            for (int j = 0; j < 3; ++j) {
                DISPL_CRUST_MANTLE[i][j] += 1.0f; // Increment each element by 1.0
            }
        }
    }
};