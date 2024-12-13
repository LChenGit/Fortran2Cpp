#include <iostream>
#include <vector>

// Declaration of the NWHSEL function
int NWHSEL(int NPTIMS, const std::vector<int>& IPTIMS, const std::vector<bool>& WHOTIM);

// Main function to run tests
int main() {
    std::vector<int> IPTIMS = {1, 2, 3, 4, 5};
    std::vector<bool> WHOTIM = {true, false, true, false, true};

    std::cout << "Test 1: Expected 3, Got " << NWHSEL(IPTIMS.size(), IPTIMS, WHOTIM) << std::endl;

    WHOTIM = {false, false, false, false, false};
    std::cout << "Test 2: Expected 0, Got " << NWHSEL(IPTIMS.size(), IPTIMS, WHOTIM) << std::endl;

    WHOTIM = {true, true, true, true, true};
    std::cout << "Test 3: Expected 5, Got " << NWHSEL(IPTIMS.size(), IPTIMS, WHOTIM) << std::endl;

    return 0;
}

// Definition of the NWHSEL function
int NWHSEL(int NPTIMS, const std::vector<int>& IPTIMS, const std::vector<bool>& WHOTIM) {
    int result = 0;
    for(int i = 0; i < NPTIMS; ++i) {
        // Adjusting for 0-based indexing in C++
        if (WHOTIM[IPTIMS[i] - 1]) {
            result += 1;
        }
    }
    return result;
}