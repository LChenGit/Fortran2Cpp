#include <iostream>
#include <iomanip>
#include <string>

void xersor(const std::string &srname, int info) {
    std::string outputSrName = srname.substr(0, 7);
    std::cout << " ** On entry to " << std::left << std::setw(7) << outputSrName
              << " parameter number " << std::setw(2) << info 
              << " had an illegal value" << std::endl;
}

int main() {
    xersor("ABC1234", 1); // Valid input
    xersor("ABCDEFG", -1); // Invalid input
    return 0;
}