#include <fstream>
#include <iostream>

int main() {
    std::string filename = "tmpfile";
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    file << "This is a test." << std::endl;

    file.close();

    // Optionally delete the file here if necessary
    // std::remove(filename.c_str());

    return 0;
}