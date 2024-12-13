#include <iostream>

const int IPARMS_SIZE = 100;
static int iparms[IPARMS_SIZE] = {0};

void xlaenv(int ispec, int nvalue) {
    if (ispec >= 1 && ispec <= 16) {
        // Adjusting index to 0-based for C++
        iparms[ispec - 1] = nvalue;
    }
}

// Main function for demonstration purposes, can be replaced with unit tests
int main() {
    // Example usage
    xlaenv(1, 10); // Sets the first element of iparms to 10
    std::cout << "iparms[0] = " << iparms[0] << std::endl; // Should output 10

    return 0;
}