#include <array>

class M_tenstr_rrlw_kg14 {
public:
    static constexpr int no14 = 16;
    static constexpr int ng14 = 2;

    std::array<double, no14> fracrefao;
    std::array<double, no14> fracrefbo;

    double kao[5][13][no14];
    double kbo[5][47][no14]; // Adjusted to fit the C++ 0-based indexing
    double selfrefo[10][no14];
    double forrefo[4][no14];

    std::array<double, ng14> fracrefa;
    std::array<double, ng14> fracrefb;

    double ka[5][13][ng14];
    double kb[5][47][ng14]; // Adjusted for 0-based indexing
    double selfref[10][ng14];
    double forref[4][ng14];

    // Overlay arrays using reinterpret_cast
    double (&absa)[65][ng14] = reinterpret_cast<double (&)[65][ng14]>(*ka);
    double (&absb)[235][ng14] = reinterpret_cast<double (&)[235][ng14]>(*kb);

    M_tenstr_rrlw_kg14() {
        // Constructor to initialize or manipulate data if necessary
    }
};