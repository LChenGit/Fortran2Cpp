#include <array>
#include <cstdint>

namespace rrlw_kg04 {

    constexpr std::int32_t no4 = 16;
    constexpr std::int32_t ng4 = 14;

    struct Module {
        std::array<std::array<double, 9>, no4> fracrefao{};
        std::array<std::array<double, 5>, no4> fracrefbo{};
        std::array<std::array<std::array<std::array<double, no4>, 13>, 5>, 9> kao{};
        std::array<std::array<std::array<std::array<double, no4>, 47>, 5>, 5> kbo{};
        std::array<std::array<double, no4>, 10> selfrefo{};
        std::array<std::array<double, no4>, 4> forrefo{};

        std::array<std::array<double, 9>, ng4> fracrefa{};
        std::array<std::array<double, 5>, ng4> fracrefb{};
        std::array<std::array<double, ng4>, 10> selfref{};
        std::array<std::array<double, ng4>, 4> forref{};

        std::array<std::array<double, 585>, ng4> absa{};
        std::array<std::array<double, 1175>, ng4> absb{};

        // We use separate arrays for ka and kb to avoid complex alignment issues
        std::array<std::array<std::array<std::array<double, ng4>, 13>, 5>, 9> ka{};
        std::array<std::array<std::array<std::array<double, ng4>, 47>, 5>, 5> kb{};
    };
}