#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <limits>

namespace config {
    using sp = float; // Single precision
    using dp = double; // Double precision
    using ep = long double; // Extended precision
    using wp = sp; // wp is chosen to be the same as sp for this example

    void disp_wp() {
        std::cout << "Precision digits10: " << std::numeric_limits<wp>::digits10 << std::endl;
    }
}

#endif // CONFIG_HPP