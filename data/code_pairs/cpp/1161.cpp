#include <iostream>
#include <vector>

class Mod {
public:
    int i = 0;
    std::vector<int> x = std::vector<int>(4, 0);
    std::vector<std::vector<float>> a = std::vector<std::vector<float>>(2, std::vector<float>(3, 0.0f));

    void foo() {
        std::cout << "i=" << i << std::endl;
        std::cout << "x=[";
        for (size_t j = 0; j < x.size(); ++j) {
            std::cout << x[j];
            if (j < x.size() - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
        
        std::cout << "a=[" << std::endl;
        for (const auto& row : a) {
            std::cout << "[";
            for (size_t k = 0; k < row.size(); ++k) {
                std::cout << row[k];
                if (k < row.size() - 1) std::cout << ",";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "]" << std::endl;
        
        std::cout << "Setting a[0][1]=a[0][1]+3" << std::endl;
        a[0][1] += 3;
    }

    float getAValue(int row, int col) const {
        return a[row][col];
    }
};

// Test function
void testFoo() {
    Mod mod;
    // Setup initial value
    mod.a[0][1] = 2.0f;
    mod.foo();
    
    // Check if the value is as expected after foo() is called
    if (mod.getAValue(0, 1) == 5.0f) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    testFoo();
    return 0;
}