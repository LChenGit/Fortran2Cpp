#include <iostream>
#include <string>

namespace netcdf {
    void openFile(const std::string& filename) {
        std::cout << "Opening file: " << filename << std::endl;
    }

    int getDimension(const std::string& dimName) {
        std::cout << "Getting dimension for: " << dimName << std::endl;
        return 10; // Example dimension
    }
}