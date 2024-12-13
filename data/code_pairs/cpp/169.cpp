#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::vector<int64_t> foo(2); // Equivalent to the Fortran array size
    std::vector<int64_t> bar(2, 42); // Initialize bar with 42
    int64_t lb = 4294967296;
    int64_t ub = 4294967297;

    // Copy values from bar to foo
    foo = bar;

    // Print bounds of foo
    std::cout << "bounds of foo - " << lb << ":" << ub << std::endl;

    return 0;
}