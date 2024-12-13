#include <iostream>
#include <vector>

void lookup_shell(const std::vector<int>& table, int a, int& m) {
    int nshells = table.size();
    m = 0; // Adjusting this to ensure a consistent starting point

    for(int i = 0; i < nshells; ++i) {
        if(table[i] >= a) {
            m = i + 1; // Adjust to 1-based indexing for consistency with Fortran code
            return;
        }
    }

    m = nshells; // Adjust to 1-based indexing for consistency with Fortran code
}

int main() {
    std::vector<int> table;
    int m;

    // Test 1: Empty input table
    lookup_shell(table, 3, m);
    std::cout << "Test 1 (Empty table), Expected: 0, Got: " << m << std::endl;

    // Test 2: Table with elements all smaller than `a`
    table = {1, 2, 3};
    lookup_shell(table, 4, m);
    std::cout << "Test 2 (All smaller), Expected: 3, Got: " << m << std::endl;

    // Test 3: Table with elements all greater than or equal to `a`
    table = {4, 5, 6};
    lookup_shell(table, 2, m);
    std::cout << "Test 3 (All greater or equal), Expected: 1, Got: " << m << std::endl;

    // Test 4: Mixed elements, `a` not present
    table = {1, 3, 5, 7, 9};
    lookup_shell(table, 6, m);
    std::cout << "Test 4 (Mixed, a not present), Expected: 4, Got: " << m << std::endl;

    // Test 5: Mixed elements, `a` present
    table = {1, 3, 5, 7, 9};
    lookup_shell(table, 5, m);
    std::cout << "Test 5 (Mixed, a present), Expected: 3, Got: " << m << std::endl;

    // Test 6: First element >= `a`
    table = {2, 3, 4};
    lookup_shell(table, 2, m);
    std::cout << "Test 6 (First element >= a), Expected: 1, Got: " << m << std::endl;

    // Test 7: Last element is the first >= `a`
    table = {1, 2, 3, 4};
    lookup_shell(table, 4, m);
    std::cout << "Test 7 (Last element first >= a), Expected: 4, Got: " << m << std::endl;

    return 0;
}