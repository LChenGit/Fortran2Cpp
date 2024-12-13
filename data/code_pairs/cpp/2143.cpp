#include <iostream>
#include <quadmath.h> // For __float128

// A simple function to print a __int128 integer.
void print_int128(__int128 i) {
    if (i < 0) {
        std::cout << '-';
        i = -i;
    }
    if (i / 10) {
        print_int128(i / 10);
    }
    std::cout << char('0' + i % 10);
}

// A simple function to print a __float128 floating-point number.
void print_float128(__float128 f) {
    char buf[128];
    quadmath_snprintf(buf, sizeof buf, "%.38Qf", f);
    std::cout << buf;
}

int main() {
    __int128 int128_var = 42; // Assigning a value directly to a __int128 variable.
    __float128 float128_var = 3.141592653589793238462643383279502884197Q; // For __float128

    // Basic operations
    int128_var += 10; // Adding 10 to our __int128 variable
    float128_var *= 2.0Q; // Multiplying our __float128 variable by 2

    // Output the results
    std::cout << "Int128 Var: ";
    print_int128(int128_var);
    std::cout << std::endl;
    
    std::cout << "Float128 Var: ";
    print_float128(float128_var);
    std::cout << std::endl;

    return 0;
}