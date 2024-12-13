#include <iostream>
#include <vector>

void foo(const std::vector<int>& x) {
    int sum = 0;
    for (int num : x) {
        sum += num;
    }
    std::cout << "Sum = " << sum << std::endl;
}