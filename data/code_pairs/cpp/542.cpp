#include <array>

const int ng25 = 20; // Adjust as needed

class rrsw_kg25 {
public:
    static const int no25 = 16;

    std::array<std::array<std::array<double, no25>, 13>, 5> kao{};
    std::array<double, no25> sfluxrefo{};
    std::array<double, no25> abso3ao{}, abso3bo{};
    std::array<double, no25> raylo{};

    std::array<std::array<std::array<double, ng25>, 13>, 5> ka{};
    std::array<std::array<double, ng25>, 65> absa{};
    std::array<double, ng25> sfluxref{};
    std::array<double, ng25> abso3a{}, abso3b{};
    std::array<double, ng25> rayl{};
};