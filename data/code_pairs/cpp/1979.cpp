#include <iostream>
#include <string>

int main() {
    std::string str = "abcdefg";
    int array[7];

    for (int i = 0; i < 7; ++i) {
        array[i] = i + 1;
    }

    // Print substrings to manually verify
    std::cout << str.substr(1, 3) << std::endl; // bcd
    std::cout << str.substr(0, 3) << std::endl; // abc
    std::cout << str.substr(4) << std::endl;    // efg
    std::cout << str << std::endl;              // abcdefg

    return 0;
}