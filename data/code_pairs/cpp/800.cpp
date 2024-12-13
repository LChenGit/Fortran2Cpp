#include <iostream>
#include <vector>
#include <cassert>

void testArrayCopy() {
    const int n = 100;
    std::vector<float> a(n);
    std::vector<float> temp(n);

    // Fill 'a' with test data.
    for (int i = 0; i < n; ++i) {
        a[i] = i; // Example: fill 'a' with sequential values.
    }

    // Copying the content of 'a' to 'temp'
    temp = a;

    // Test
    for (int i = 0; i < n; ++i) {
        assert(a[i] == temp[i]);
    }

    std::cout << "Test passed." << std::endl;
}

int main() {
    testArrayCopy();
    return 0;
}