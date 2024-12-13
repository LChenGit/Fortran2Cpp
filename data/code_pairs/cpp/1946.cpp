#include <iostream>
#include <vector>

void btn(int& n, const std::vector<bool>& b) {
    n = 0;
    for (int i = static_cast<int>(b.size()) - 1; i >= 0; --i) {
        n = n * 2;
        if (b[i]) {
            n += 1;
        }
    }
}

int main() {
    std::vector<bool> test_case1 = {true, true, true};
    std::vector<bool> test_case2 = {true, false, true, true};
    int result = 0;

    btn(result, test_case1);
    std::cout << "Result for test case 1 (should be 7): " << result << std::endl;

    btn(result, test_case2);
    std::cout << "Result for test case 2 (should be 13): " << result << std::endl;

    return 0;
}