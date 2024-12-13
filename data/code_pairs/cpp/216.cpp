#include <iostream>
#include <cstdint>
#include <functional>

class t {
public:
    std::function<int64_t(const t&, const t&)> add1;
    static std::function<int64_t(const t&, const t&)> add2;
    std::function<int64_t(const t&, double)> add_real;

    t() {
        add1 = [](const t& x, const t& y) -> int64_t {
            return 1;  // Placeholder logic for add
        };
        add_real = [](const t& x, double y) -> int64_t {
            return 2;  // Placeholder logic for add_real
        };
    }

    static int64_t add(const t& x, const t& y) {
        return 3;  // Static function logic
    }
};

// Static member initialization
std::function<int64_t(const t&, const t&)> t::add2 = &t::add;

int main() {
    t x, y;
    double z = 0.0;
    int64_t result;

    // Test add function (via add1)
    result = x.add1(x, y);
    std::cout << "Result of add1: " << result << std::endl;

    // Test add function (via add2)
    result = t::add2(x, y);
    std::cout << "Result of add2: " << result << std::endl;

    // Test add_real function
    result = x.add_real(x, z);
    std::cout << "Result of add_real: " << result << std::endl;

    return 0;
}