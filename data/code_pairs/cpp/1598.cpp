#include <iostream>

namespace COMMONNAME {
    int A = 0; // Initialize A to 0
    void IncrementA(int value) {
        A += value;
    }
}

int main() {
    using namespace COMMONNAME;
    IncrementA(10);
    std::cout << "Test IncrementA with start value 0 and increment 10: " << A << std::endl;
    IncrementA(-5);
    std::cout << "Test IncrementA with current value 10 and decrement 5: " << A << std::endl;
    return 0;
}