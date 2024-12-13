#include <string>
#include <iostream>
#include <cassert>

int MDILNB(const std::string& chrs) {
    for (int i = chrs.length() - 1; i >= 0; --i) {
        if (chrs[i] != ' ') {
            return i + 1; // 1-based indexing to match Fortran behavior
        }
    }
    return 1;
}