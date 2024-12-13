#include <iostream>
#include <string>

int FirstNonChar(const std::string& str, char ch) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ch) {
            return i + 1; // Adjust for 1-based indexing to match Fortran behavior
        }
    }
    return 0;
}