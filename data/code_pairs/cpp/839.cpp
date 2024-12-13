#include <iostream>

char foo(int i) {
    char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                          '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char c = hex_chars[i];
    return c == '3' ? 'T' : 'F'; // Return 'T' (True) if matches '3', else 'F' (False)
}

int main() {
    std::cout << "C++ Unit Tests" << std::endl;
    for(int i = 0; i <= 15; ++i) {
        char result = foo(i);
        if (result == 'T') {
            std::cout << "Test with i=" << i << " Passed." << std::endl;
        } else {
            std::cout << "Test with i=" << i << " Failed." << std::endl;
        }
    }
    return 0;
}