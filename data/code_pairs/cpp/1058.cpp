#include <vector>
#include <iostream>
#include <cassert>

void USQUSH(std::vector<double>& V, int ISIZE) {
    V.resize(ISIZE + 6); // Ensure the vector can hold ISIZE + 6 elements.

    for (int I = ISIZE - 1; I >= 3; --I) {
        V[I + 6] = V[I];
    }

    V[7] = V[2];
    V[6] = V[1];
    V[3] = V[0];
    V[8] = 0.0;
    V[5] = 0.0;
    V[4] = 0.0;

    for (int I = 0; I < 3; ++I) {
        V[I] = 0.0;
    }
}

int main() {
    std::vector<double> V(10);

    // Initialize the vector
    for (size_t i = 0; i < V.size(); ++i) {
        V[i] = i + 1; // Fill with values 1 to 10
    }

    // Call USQUSH
    USQUSH(V, 4);

    // Assertions to verify the correctness of the USQUSH function
    assert(V[0] == 0.0);
    assert(V[1] == 0.0);
    assert(V[2] == 0.0);
    assert(V[3] == 1.0);
    assert(V[4] == 0.0);
    assert(V[5] == 0.0);
    assert(V[6] == 2.0);
    assert(V[7] == 3.0);
    assert(V[8] == 0.0);
    assert(V[9] == 4.0); // Corrected as per Fortran output

    std::cout << "All assertions passed!\n";

    return 0;
}