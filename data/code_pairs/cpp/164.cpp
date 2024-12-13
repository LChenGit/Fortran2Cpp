#include <cstdint>

extern "C" { // Ensure C linkage for compatibility with C and Fortran

struct info_t {
    std::int32_t type; // Use std::int32_t to match INTEGER(c_int) from Fortran
};

// Declare the liter_cb function with C linkage
std::int32_t liter_cb(info_t link_info);

}