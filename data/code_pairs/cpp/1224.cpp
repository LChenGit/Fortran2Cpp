#include <iostream>
#include <vector>
#include <algorithm>

int checkConditions(const std::vector<int>& K, const std::vector<int>& J) {
    // Condition 1: Using MAXLOC equivalent logic in C++
    bool condition1Met = false;
    for (size_t i = 0; i < K.size(); ++i) {
        if (J[i] < 3) {
            auto maxPos = std::distance(K.begin(), std::max_element(K.begin(), K.end()));
            if (maxPos != 0) { // Adjusted for 0-based indexing in C++
                condition1Met = true;
                break;
            }
        }
    }

    if (condition1Met) {
        return 1;
    }

    // Condition 2: Checking if any element in J is not equal to 2
    if (std::any_of(J.begin(), J.end(), [](int val) { return val != 2; })) {
        return 2;
    }

    return 0; // No conditions met
}

int main() {
    std::vector<int> K = {1, 1, 1}; // Equivalent to INTEGER :: K(3) = 1 in Fortran
    std::vector<int> J = {2, 2, 2}; // Equivalent to INTEGER, PARAMETER :: J(3) = 2 in Fortran
    
    int result = checkConditions(K, J);
    std::cout << "Result: " << result << std::endl;

    return 0;
}