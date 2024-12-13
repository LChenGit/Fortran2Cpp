#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cassert>

class VaryingString {
public:
    std::vector<char> chars;

    VaryingString& operator=(const char* expr) {
        chars.assign(expr, expr + std::strlen(expr));
        return *this;
    }
};

bool notEqual(const std::vector<char>& vec, const char* str, size_t len) {
    return !std::equal(vec.begin(), vec.begin() + len, str);
}

int main() {
    char char_storage[10];
    char* char_arb[2] = {char_storage, char_storage + 5};
    char* char_elm = char_storage;

    std::strcpy(char_arb[0], "Hello");
    std::strcpy(char_arb[1], "World");

    VaryingString str_ara[2];
    str_ara[0] = char_arb[0];
    str_ara[1] = char_arb[1];

    assert(notEqual(str_ara[0].chars, char_elm, 5) == false);
    std::cout << "Test 1 Passed." << std::endl;

    assert(notEqual(str_ara[1].chars, char_elm + 5, 5) == false);
    std::cout << "Test 2 Passed." << std::endl;

    return 0;
}