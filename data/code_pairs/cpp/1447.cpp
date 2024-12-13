#include <iostream>

extern "C" {
    void print_string(const char* str);
}

int main() {
    char arg[256] = "Hello from C++";
    
    print_string(arg); // Directly passing the char array as it is compatible with C

    return 0;
}