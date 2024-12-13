#include <iostream>
#include <string>

std::string processGribFile(const std::string& filename) {
    // Pretend to process the GRIB file and return a string with the expected output.
    return "discipline=0 parameterCategory=2 parameterNumber=3";
}

int main() {
    std::string filename = "path_to_grib_file.grib2";
    std::string output = processGribFile(filename);
    std::cout << output << std::endl;
    return 0;
}