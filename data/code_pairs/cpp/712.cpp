#include <array>

using rb = float; // Real(kind=rb) equivalent
using im = int;   // Integer(kind=im) equivalent

class rrlw_kg03 {
public:
    static constexpr im no3 = 16;
    static constexpr im ng3 = 16;

    std::array<std::array<rb, 9>, no3> fracrefao;
    std::array<std::array<rb, 5>, no3> fracrefbo;
    std::array<std::array<std::array<std::array<rb, no3>, 13>, 5>, 9> kao;
    std::array<std::array<std::array<std::array<rb, no3>, 47>, 5>, 5> kbo;
    std::array<std::array<std::array<rb, no3>, 19>, 9> kao_mn2o;
    std::array<std::array<std::array<rb, no3>, 19>, 5> kbo_mn2o;
    std::array<std::array<rb, no3>, 10> selfrefo;
    std::array<std::array<rb, no3>, 4> forrefo;

    std::array<std::array<rb, 9>, ng3> fracrefa;
    std::array<std::array<rb, 5>, ng3> fracrefb;
    std::array<std::array<std::array<std::array<rb, ng3>, 13>, 5>, 9> ka;
    std::array<std::array<rb, ng3>, 585> absa; // Flattened representation if needed
    std::array<std::array<std::array<std::array<rb, ng3>, 47>, 5>, 5> kb;
    std::array<std::array<rb, ng3>, 1175> absb; // Flattened representation if needed
    std::array<std::array<std::array<rb, ng3>, 19>, 9> ka_mn2o;
    std::array<std::array<std::array<rb, ng3>, 19>, 5> kb_mn2o;
    std::array<std::array<rb, ng3>, 10> selfref;
    std::array<std::array<rb, ng3>, 4> forref;
};