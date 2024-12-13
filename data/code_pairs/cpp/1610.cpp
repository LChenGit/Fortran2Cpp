#include <iostream>
#include <cstdint>
#include <type_traits>

template<int P>
struct selected_int_kind {};

template<>
struct selected_int_kind<8> {
    using type = int32_t;
};

template<>
struct selected_int_kind<10> {
    using type = int64_t;
};

int main() {
    using s4 = selected_int_kind<8>::type;
    using s8 = selected_int_kind<10>::type;
    using k4 = int32_t;
    using k8 = int64_t;
    using r8 = double;
    
    static_assert(std::is_same<s4, int32_t>::value, "invalid s4");
    static_assert(std::is_same<s8, int64_t>::value, "invalid s8");
    static_assert(std::is_same<k4, int32_t>::value, "invalid k4");
    static_assert(std::is_same<k8, int64_t>::value, "invalid k8");
    static_assert(std::is_same<r8, double>::value, "invalid r8");

    std::cout << "All checks passed." << std::endl;

    return 0;
}