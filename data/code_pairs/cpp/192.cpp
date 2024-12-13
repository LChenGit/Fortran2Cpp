#include <iostream>
#include <vector>

using precision_t = double; // Assuming precision p corresponds to double

namespace base_types {

struct alloc_int1d {
    std::vector<int> v;
};

struct alloc_rp1d {
    std::vector<precision_t> v;
};

struct alloc_int2d {
    std::vector<std::vector<int>> v;
};

struct alloc_rp2d {
    std::vector<std::vector<precision_t>> v;
};

} // namespace base_types

int main() {
    // Test alloc_int1d
    base_types::alloc_int1d int1d;
    int1d.v = {1, 2, 3, 4, 5};
    std::cout << "alloc_int1d: ";
    for (auto item : int1d.v) std::cout << item << " ";
    std::cout << std::endl;

    // Test alloc_rp1d
    base_types::alloc_rp1d rp1d;
    rp1d.v = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::cout << "alloc_rp1d: ";
    for (auto item : rp1d.v) std::cout << item << " ";
    std::cout << std::endl;

    // Test alloc_int2d
    base_types::alloc_int2d int2d;
    int2d.v = {{1, 2, 3}, {4, 5, 6}};
    std::cout << "alloc_int2d:" << std::endl;
    for (const auto& row : int2d.v) {
        for (auto item : row) std::cout << item << " ";
        std::cout << std::endl;
    }

    // Test alloc_rp2d
    base_types::alloc_rp2d rp2d;
    rp2d.v = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    std::cout << "alloc_rp2d:" << std::endl;
    for (const auto& row : rp2d.v) {
        for (auto item : row) std::cout << item << " ";
        std::cout << std::endl;
    }

    return 0;
}