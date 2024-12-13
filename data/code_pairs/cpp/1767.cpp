#include <iostream>
#include <string>

void chr_ltoc(bool lvalue, std::string& str, int& nchar) {
    if (lvalue) {
        str = "TRUE";
        nchar = 4;
    } else {
        str = "FALSE";
        nchar = 5;
    }
}

int main() {
    std::string testStr;
    int testNchar;

    // Test with lvalue = true
    chr_ltoc(true, testStr, testNchar);
    std::cout << "Test 1 (lvalue = true):" << std::endl;
    std::cout << "STRING = " << testStr << std::endl;
    std::cout << "NCHAR = " << testNchar << std::endl;

    // Test with lvalue = false
    chr_ltoc(false, testStr, testNchar);
    std::cout << "Test 2 (lvalue = false):" << std::endl;
    std::cout << "STRING = " << testStr << std::endl;
    std::cout << "NCHAR = " << testNchar << std::endl;

    return 0;
}