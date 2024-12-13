#include <iostream>
#include <vector>
#include <cassert>

// Function to add elements of an integer array
int intAdd(int lenLst, const std::vector<int>& intLst) {
    int intAdd = 0;
    for (int i = 0; i < lenLst; ++i) {
        intAdd += intLst[i];
    }
    return intAdd;
}

int main() {
    // Example usage
    std::vector<int> intLst = {1, 2, 3, 4, 5};
    int lenLst = intLst.size();
    
    int result = intAdd(lenLst, intLst);
    std::cout << "The sum of the elements is: " << result << std::endl;

    // Unit test
    assert(result == 15);
    std::cout << "Test passed." << std::endl;

    return 0;
}