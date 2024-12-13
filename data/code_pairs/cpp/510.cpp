#include <iostream>
#include <cassert>

int iranfeven(int N) {
    return (N % 2 == 0) ? 1 : 0;
}

int main() {
    // Test cases
    assert(iranfeven(-2) == 1);
    assert(iranfeven(-1) == 0);
    assert(iranfeven(0) == 1);
    assert(iranfeven(1) == 0);
    assert(iranfeven(2) == 1);
    assert(iranfeven(3) == 0);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}