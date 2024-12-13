#include <iostream>
#include <cstring>

int main() {
    // Variables
    int i;
    bool b;

    // Test transferring int to bool
    i = 0;
    std::memcpy(&b, &i, sizeof(b));
    std::cout << "Transfer int 0 to bool: " << std::boolalpha << b << std::endl;

    // Test transferring nonzero int to bool
    i = -1;
    std::memcpy(&b, &i, sizeof(b));
    std::cout << "Transfer int -1 to bool: " << std::boolalpha << b << std::endl;

    return 0;
}