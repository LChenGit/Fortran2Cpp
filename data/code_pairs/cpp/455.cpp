#include <cstdlib> // For std::abort
#include <iostream>

int main() {
    long long foo, bar;
    double r = 4e10;
    
    foo = static_cast<long long>(4e10);
    bar = static_cast<long long>(r);
    
    if (foo != bar) {
        std::cerr << "Test failed." << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed." << std::endl;
    }
    
    return 0;
}