#include <vector>
#include <cassert>
#include <iostream>

void permuteElementsLogical1D(std::vector<bool>& arrayToPermute, std::vector<bool>& tempArray, const std::vector<int>& perm, int nSpec) {
    tempArray.resize(arrayToPermute.size());
    for (int i = 0; i < nSpec; ++i) {
        tempArray[i] = arrayToPermute[perm[i] - 1];
    }
    arrayToPermute = tempArray;
}

int main() {
    // Test 1: Reverse permutation
    std::vector<bool> arrayToPermute = {true, false, true, false};
    std::vector<bool> tempArray;
    std::vector<int> perm = {4, 3, 2, 1};
    permuteElementsLogical1D(arrayToPermute, tempArray, perm, arrayToPermute.size());
    assert(arrayToPermute == std::vector<bool>({false, true, false, true}));

    // Test 2: Custom permutation
    perm = {2, 1, 4, 3};
    permuteElementsLogical1D(arrayToPermute, tempArray, perm, arrayToPermute.size());
    assert(arrayToPermute == std::vector<bool>({true, false, true, false}));

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}