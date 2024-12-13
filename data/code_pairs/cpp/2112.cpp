#include <cstdint>
#include <iostream>

int main() {
    bool l1;
    bool l2;
    bool l4;
    int8_t i1;
    int16_t i2;
    int32_t i4;

    // Assign true to all logicals
    l1 = true;
    l2 = true;
    l4 = true;

    // Convert logical to integer
    i1 = l1 ? 1 : 0;
    i2 = l2 ? 1 : 0;
    i4 = l4 ? 1 : 0;

    // Output the results
    std::cout << "After assigning true: " << static_cast<int>(i1) << ", " << i2 << ", " << i4 << std::endl;

    // Assign false to all logicals
    l1 = false;
    l2 = false;
    l4 = false;

    // Convert logical to integer
    i1 = l1 ? 1 : 0;
    i2 = l2 ? 1 : 0;
    i4 = l4 ? 1 : 0;

    // Output the results
    std::cout << "After assigning false: " << static_cast<int>(i1) << ", " << i2 << ", " << i4 << std::endl;

    return 0;
}