#include <iostream>
#include <array>
#include <string>

// Since C++ doesn't use BLOCK DATA, we initialize directly in the global/static variable.
std::array<std::string, 3> FITSHDR_ERRMSG = {
    "Success",
    "Null fitskey pointer-pointer passed",
    "Memory allocation failed"
};

void testFITSHDR() {
    for (size_t i = 0; i < FITSHDR_ERRMSG.size(); ++i) {
        std::cout << "Error " << i << ": " << FITSHDR_ERRMSG[i] << std::endl;
    }
}

int main() {
    testFITSHDR();
    return 0;
}