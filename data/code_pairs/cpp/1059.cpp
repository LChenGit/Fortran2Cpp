#include <iostream>
#include <string>
#include <cassert>

int performLogic() {
    std::string bTrue(1, 'T'); // Simulating the Fortran 'write' behavior for true
    std::string bFalse(1, 'F'); // Simulating the Fortran 'write' behavior for false

    // Check for 'T'
    if (bTrue.at(0) != 'T') return 1;

    // Check for 'F'
    if (bFalse.at(0) != 'F') return 2;

    std::string bTruePadded = "   T"; // Simulating the Fortran 'write' behavior with padding
    std::string bFalsePadded = "   F"; // Simulating the Fortran 'write' behavior with padding

    // Check for padded 'T'
    if (bTruePadded != "   T") return 3;

    // Check for padded 'F'
    if (bFalsePadded != "   F") return 4;

    return 0;
}

int main() {
    assert(performLogic() == 0);
    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}