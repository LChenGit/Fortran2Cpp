#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

// Helper function to flatten a 2D vector into a 1D vector
vector<int> flatten(const vector<vector<int>>& vec) {
    vector<int> result;
    for (const auto& row : vec) {
        result.insert(result.end(), row.begin(), row.end());
    }
    return result;
}

// Function equivalent to Function_Test in Fortran
vector<int> functionTest(const vector<int>& input) {
    vector<int> result(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        result[i] = input[i] + 10;
    }
    return result;
}

int main() {
    // Initialize Array with the given values
    vector<vector<int>> array = {
        {1, 4, 2},
        {5, 3, 6}
    };

    // Initialize Brray with zeros
    vector<vector<int>> brray(2, vector<int>(3, 0));

    // Apply functionTest to the first row of array and assign to brray's first row
    brray[0] = functionTest(array[0]);

    // Expected values for Brray after first function call
    vector<int> expectedBrray = {11, 14, 12, 0, 0, 0};
    vector<int> actualBrray = flatten(brray);

    // Check if Brray matches expected values
    assert(actualBrray == expectedBrray);

    // Apply functionTest again to update the first row of array
    array[0] = functionTest(array[0]);

    // Expected values for Array after update
    vector<int> expectedArray = {11, 14, 12, 5, 3, 6};
    vector<int> actualArray = flatten(array);

    // Check if Array matches expected values
    assert(actualArray == expectedArray);

    cout << "All tests passed successfully." << endl;
    return 0;
}