#include <iostream>

bool gt_int(int x, int y) {
    return x > y;
}

void test_case(int x, int y, bool expected) {
    bool result = gt_int(x, y);
    std::cout << x << " > " << y << ": " << std::boolalpha << result;
    if (result == expected) {
        std::cout << " (Pass)" << std::endl;
    } else {
        std::cout << " (Fail)" << std::endl;
    }
}

int main() {
    std::cout << "Testing gt_int function:" << std::endl;
    test_case(5, 3, true);
    test_case(3, 5, false);
    test_case(4, 4, false);
    return 0;
}