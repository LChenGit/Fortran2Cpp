#include <iostream>
#include <fstream>
#include <string>

void createTempFile(int i) {
    std::ofstream tempFile("tempfile_" + std::to_string(100+i));
    if (tempFile.is_open()) {
        tempFile << "Temporary data for i = " << i << std::endl;
        tempFile.close();
    } else {
        std::cerr << "Failed to create a temporary file for i = " << i << std::endl;
    }
}

int main() {
    for (int i = 1; i <= 30; ++i) {
        std::cout << i << std::endl; // Printing the iteration number.
        createTempFile(i); // Function call to create a temp file.
    }
    return 0;
}