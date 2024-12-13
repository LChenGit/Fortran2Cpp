#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

namespace foo {
    void bar(const std::vector<std::vector<float>>& a, float& x) {
        x = 0.0;
        for(size_t j = 0; j < a[0].size(); ++j) {
            for(size_t i = 0; i < a.size(); ++i) {
                x += std::pow(a[i][j], 2);
            }
        }
    }
}

void test_bar() {
    std::vector<std::vector<float>> a = {
        {1.0, 2.0, 3.0},
        {-1.0, -2.0, -3.0}
    };
    float x = 0;
    float expected = 28.0;
    
    foo::bar(a, x);
    if (std::abs(x - expected) < 0.0001) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected: " << expected << " Got: " << x << std::endl;
    }
}

int main() {
    test_bar();
    return 0;
}