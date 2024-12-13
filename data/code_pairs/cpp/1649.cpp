#include <utility> // For std::swap
#include <cstdint>

namespace NumericKinds {
    
    using R_SP = float;
    using R_DP = double;
    using R_QP = long double;
    
    using RK = R_DP;

    using I1B = int8_t;
    using I2B = int16_t;
    using I3B = int32_t;
    using I4B = int64_t;

    using IK = I3B;
    
    template<typename T>
    void swap(T& a, T& b) {
        std::swap(a, b);
    }

    // Explicit template instantiation declarations
    template void swap<RK>(RK&, RK&);
    template void swap<IK>(IK&, IK&);
}