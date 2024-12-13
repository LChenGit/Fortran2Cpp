#include <iostream>
#include <vector>
#include <cassert>

// Main C++ Code
void sort_split_nodes(int numfn, int numelv, std::vector<std::vector<int>>& nfault, const std::vector<int>& indxiel) {
    if (numfn == 0) return;

    for (int i = 0; i < numfn; ++i) {
        nfault[0][i] = indxiel[nfault[0][i] - 1]; // Adjusted for 0-based indexing
    }
}

// Unit Test for the main C++ Code
void test_sort_split_nodes() {
    int numfn = 5;
    int numelv = 10;

    std::vector<std::vector<int>> nfault(3, std::vector<int>(numfn));
    std::vector<int> indxiel(numelv);

    // Populate nfault and indxiel with example values
    for (int i = 0; i < numfn; ++i) {
        nfault[0][i] = i + 1; // Adjust for 1-based to 0-based indexing
    }
    for (int i = 0; i < numelv; ++i) {
        indxiel[i] = i + 1;
    }

    // Call the function
    sort_split_nodes(numfn, numelv, nfault, indxiel);

    // Verify the results
    for (int i = 0; i < numfn; ++i) {
        assert(nfault[0][i] == indxiel[i]); // Verification based on 0-based indexing
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_sort_split_nodes();
    return 0;
}