// h5global.hpp
#ifndef H5GLOBAL_HPP
#define H5GLOBAL_HPP

namespace h5global {
    extern int h5p_default_f;
    extern int h5p_flags;
}

#endif // H5GLOBAL_HPP

// h5global.cpp
#include "h5global.hpp"

namespace h5global {
    // Ensure h5p_flags and h5p_default_f refer to the same memory location
    union {
        int h5p_flags;
        int h5p_default_f;
    } h5p_equiv;

    // Define the global variables to ensure linkage
    int& h5p_default_f = h5p_equiv.h5p_default_f;
    int& h5p_flags = h5p_equiv.h5p_flags;
}