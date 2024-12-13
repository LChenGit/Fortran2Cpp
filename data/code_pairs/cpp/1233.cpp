#include <iostream>
#include <string>

void S(const std::string& c) {
    std::cout << c << std::endl;
}

int main() {
    // Test with a string shorter than 10 characters
    S("Short");
    
    // Test with a string exactly 10 characters long
    S("ExactTenLen");
    
    // Test with a string longer than 10 characters
    S("ThisStringIsLongerThanTen");
    
    return 0;
}