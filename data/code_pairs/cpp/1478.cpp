#include <iostream>
#include <vector>

std::vector<int> find_divisible_by_five(int n) {
    std::vector<int> divisible;
    for (int i = 1; i <= n; ++i) {
        if (i % 5 == 0) {
            divisible.push_back(i);
        }
    }
    return divisible;
}