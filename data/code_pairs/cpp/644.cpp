#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> a = {1, 2};
    std::vector<bool> lo = {true, true}; // Equivalent to Fortran's lo
    std::vector<bool> lo2 = {true, true, false}; // Equivalent to Fortran's lo2

    auto apply_mask_and_reduce = [](const std::vector<int>& v, const std::vector<bool>& mask, auto op, int init) {
        int result = init;
        for (size_t i = 0; i < v.size(); ++i) {
            if (mask[i]) {
                result = op(result, v[i]);
            }
        }
        return result;
    };

    // Test sum and product with mask lo
    int sum = apply_mask_and_reduce(a, lo, std::plus<int>(), 0);
    int product = apply_mask_and_reduce(a, lo, std::multiplies<int>(), 1);
    std::cout << "Testing sum with mask lo: " << sum << std::endl;
    std::cout << "Expected: 3" << std::endl;
    std::cout << "Testing product with mask lo: " << product << std::endl;
    std::cout << "Expected: 2" << std::endl;

    // Test sum and product with mask lo2
    sum = apply_mask_and_reduce(a, lo2, std::plus<int>(), 0);
    product = apply_mask_and_reduce(a, lo2, std::multiplies<int>(), 1);
    std::cout << "Testing sum with mask lo2: " << sum << std::endl;
    std::cout << "Expected: 3" << std::endl;
    std::cout << "Testing product with mask lo2: " << product << std::endl;
    std::cout << "Expected: 2" << std::endl;

    return 0;
}