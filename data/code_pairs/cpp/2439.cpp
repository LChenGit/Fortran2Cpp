#include <array>
#include <cstddef>

namespace rrsw_kg16 {

    constexpr std::size_t no16 = 16;
    using rb = double;

    rb rayl;
    std::array<std::array<rb, no16>, 585> absa;
    std::array<std::array<rb, no16>, 235> absb;

    void initialize() {
        rayl = 1.0;
        for (std::size_t i = 0; i < 585; ++i) {
            absa[i][0] = static_cast<rb>(i + 1);
        }
        for (std::size_t i = 0; i < 235; ++i) {
            absb[i][0] = static_cast<rb>(i + 1001);
        }
    }
}