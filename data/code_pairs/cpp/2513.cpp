#ifndef NETCDF_H
#define NETCDF_H

#include <iostream>
#include <string>

namespace netcdf {
    void openFile(const std::string& filename) {
        std::cout << "Opening file: " << filename << std::endl;
    }

    void closeFile() {
        std::cout << "Closing file." << std::endl;
    }
}

#endif // NETCDF_H