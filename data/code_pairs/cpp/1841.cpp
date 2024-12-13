#include <array>
constexpr std::size_t ng23 = 10; // Example value, adjust as necessary
constexpr std::size_t no23 = 16;

class m_tenstr_rrsw_kg23 {
public:
    using rb_type = float; // Assuming kind_rb translates to float
    std::array<std::array<std::array<rb_type, no23>, 13>, 5> kao;
    std::array<std::array<rb_type, no23>, 10> selfrefo;
    std::array<std::array<rb_type, no23>, 3> forrefo;
    std::array<rb_type, no23> sfluxrefo;
    std::array<rb_type, no23> raylo;

    // Union for equivalence
    union {
        std::array<std::array<std::array<rb_type, ng23>, 13>, 5> ka;
        std::array<std::array<rb_type, ng23>, 65> absa; // Assuming equivalence works out with dimensions
    };

    std::array<std::array<rb_type, ng23>, 10> selfref;
    std::array<std::array<rb_type, ng23>, 3> forref;
    std::array<rb_type, ng23> sfluxref;
    std::array<rb_type, ng23> rayl;

    m_tenstr_rrsw_kg23() {
        // Constructor to initialize or bind the union/overlapping memory
    }
};