#include <iostream>
#include <vector>

int main() {
    int me = 1; // Assuming a single process for a standalone example
    std::vector<int> aa(10);
    int nerr = 0;

    for (int i = 0; i < 10; i++) {
        if (me == 3) {
            aa[i] = 10 - (i + 1);  // Adjust for 0-based indexing
        } else {
            aa[i] = -(i + 1) * 100;  // Adjust for 0-based indexing
        }
    }

    // Intended mismatches for testing purposes
    if (me == 1) {
        aa[2] = 555;  // Adjust for 0-based indexing
        aa[3] = 666;  // Adjust for 0-based indexing
    }

    for (int i = 0; i < 10; i++) {
        int ival;
        if (me == 1 && i == 2) {
            ival = 555;
        } else if (me == 1 && i == 3) {
            ival = 666;
        } else if (me == 3) {
            ival = 10 - (i + 1); // Adjust for 0-based indexing
        } else {
            ival = -(i + 1) * 100; // Adjust for 0-based indexing
        }
        
        if (aa[i] != ival) {
            std::cout << "Mismatch at i=" << (i + 1) << " with aa[i]=" << aa[i] << " and ival=" << ival << std::endl;
            nerr++;
        }
    }

    if (nerr == 0) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "number of NGs: " << nerr << std::endl;
    }

    return 0;
}