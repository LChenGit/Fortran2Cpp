#include <iostream>

namespace m {
    int i = 3;
    // Note: `j` is not needed globally in this translation; it's defined locally in main and the test.
}

int main() {
    using namespace m;
    int j = 77;

    std::cout << i << " " << j << std::endl;

    return 0;
}