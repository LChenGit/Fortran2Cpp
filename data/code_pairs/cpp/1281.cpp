#include <iostream>
#include <vector>
#include <algorithm>

// Function 'f' translated from Fortran
int f(int x) {
    return 2*x + 1;
}

// Class 'Test1' translated from Fortran module
class Test1 {
public:
    // Method 'test2' translated from Fortran function
    static std::vector<char> test2(int x) {
        int len_r = f(x); // Using function 'f' to determine the size
        std::vector<char> r(len_r);
        for(int i = 0; i < len_r; ++i) {
            r[i] = static_cast<char>((i % 32) + '@' + 1);
        }
        return r;
    }
};

int main() {
    std::vector<char> chr = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
    auto test2_result = Test1::test2(10);

    if(test2_result.size() != chr.size()) {
        std::cerr << "STOP 1: Length check failed" << std::endl;
        return 1;
    }

    if (!std::equal(test2_result.begin(), test2_result.end(), chr.begin())) {
        std::cerr << "STOP 2: Content check failed" << std::endl;
        return 2;
    }

    std::cout << "C++ tests passed successfully." << std::endl;
    return 0;
}