#ifndef M_TENSTR_RRLW_KG03_H
#define M_TENSTR_RRLW_KG03_H

#include <array>

class m_tenstr_rrlw_kg03 {
public:
    static constexpr int no3 = 16;
    std::array<std::array<double, 9>, no3> fracrefao; // Using 'double' for kind_rb equivalent

    m_tenstr_rrlw_kg03() {
        // Initialization or any necessary setup can go here
    }
};

#endif // M_TENSTR_RRLW_KG03_H