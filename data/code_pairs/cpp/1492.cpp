#include <iostream>
#include <iomanip>

namespace aot_extdouble_top {
    using xdble_k = long double;
}

int main() {
    aot_extdouble_top::xdble_k myVar = 12345.6789012345678901L;
    
    std::cout << "Precision test for xdble_k:" << std::endl;
    std::cout << "Assigned value: 12345.6789012345678901" << std::endl;
    std::cout << "Stored value: " << std::setprecision(21) << myVar << std::endl;
    
    return 0;
}