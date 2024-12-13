#include <iostream>

void f() {
    {
        int k;
        // The scope of k is limited to this block
    }
    // k is not accessible here
}

int main() {
    f();
    std::cout << "Test passed." << std::endl;
    return 0;
}