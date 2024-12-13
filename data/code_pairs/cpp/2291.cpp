#include <iostream>
#include <array>

// Function declaration
int f() {
    return 42;
}

int main() {
    std::array<int, 3> a;
    int value = f();
    
    // Fill the array with the value
    a.fill(value);
    
    // Print the array elements
    for(int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}