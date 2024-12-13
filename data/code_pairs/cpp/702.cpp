#include <iostream>

void test(int n) {
    if (n == 1) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}

int main() {
    test(1); // Should print "yes"
    test(0); // Should print "no"
    return 0;
}