#include <iostream>
#include <string>
#include <cassert>

namespace test1 {
    std::string test2(int x) {
        std::string r(2*x + 1, ' ');
        for (size_t i = 0; i < r.size(); ++i) {
            r[i] = static_cast<char>('A' + (i % 26)); // Looping from 'A' to 'Z'
        }
        return r;
    }
}

void test_test2() {
    assert(test1::test2(10).size() == 21);
    std::cout << "test2 passed" << std::endl;
}

int main() {
    test_test2();
    std::cout << "All tests passed." << std::endl;
    return 0;
}