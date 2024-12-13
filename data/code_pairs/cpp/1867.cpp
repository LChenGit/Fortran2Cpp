#include <vector>
#include <cstddef> // For size_t

using rb = double; // Assuming real64 maps to double

struct m_tenstr_rrlw_cld {
    static inline rb abscld1;
    static inline std::vector<rb> absice0{2};
    static inline std::vector<std::vector<rb>> absice1{2, std::vector<rb>(5)};
    static inline std::vector<std::vector<rb>> absice2{43, std::vector<rb>(16)};
    static inline std::vector<std::vector<rb>> absice3{46, std::vector<rb>(16)};
    static inline rb absliq0;
    static inline std::vector<std::vector<rb>> absliq1{58, std::vector<rb>(16)};
};