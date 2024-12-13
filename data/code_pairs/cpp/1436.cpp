// File: foo.cpp
#include <string>
#include <iostream>
#include <algorithm> // For std::fill

void foo(std::string& a, int n) {
    a.resize(n + 5);
    std::fill(a.begin(), a.end(), 'x'); // Fill with 'x' for demonstration
}

int main() {
    std::string str;
    int n = 10; // Example size

    foo(str, n);
    std::cout << "Test 1, Length: " << str.length() << " Expected: " << n + 5 << " Result: " << str << std::endl;

    return 0;
}