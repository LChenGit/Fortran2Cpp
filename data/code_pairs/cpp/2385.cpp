#include <vector>
#include <iostream>

// Function to initialize the LINK array
void LTNEW(int MDIM, std::vector<std::vector<int>>& LINK) {
    // Resize the LINK array to have dimensions 2 x MDIM
    LINK.resize(2, std::vector<int>(MDIM, 0));

    // Set the first row of the LINK array to 0
    for (int i = 0; i < MDIM; ++i) {
        LINK[0][i] = 0;
    }
}

int main() {
    int MDIM = 10; // Example dimension size
    std::vector<std::vector<int>> LINK;

    // Call the LTNEW function
    LTNEW(MDIM, LINK);

    // Verify that the first row of the LINK array is initialized to 0
    for (int i = 0; i < MDIM; ++i) {
        if (LINK[0][i] != 0) {
            std::cerr << "Error: LINK[0][" << i << "] = " << LINK[0][i] << std::endl;
        } else {
            std::cout << "LINK[0][" << i << "] = " << LINK[0][i] << std::endl;
        }
    }

    return 0;
}