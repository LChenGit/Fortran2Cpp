#include <iostream>

int add(int a, int b) {
    return a + b;
}

#ifndef TESTING
int main() {
    std::cout << "Adding 1 and 2 gives: " << add(1, 2) << std::endl;
}
#endif