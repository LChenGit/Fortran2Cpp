// TestInquire.cpp
#include <fstream>
#include <iostream>
#include <cstdio>  // For std::remove

int main() {
    // The file to write to
    std::string filename = "output.txt";

    // Open a file stream in binary mode to mimic stream access
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Write the text to the file
    file << "TEXT";

    // Check if the write was successful
    if (!file) {
        std::cerr << "Write operation failed." << std::endl;
        file.close();
        return 1;
    }

    // Retrieve the current position in the file
    auto position = file.tellp();

    // Close the file
    file.close();

    // Delete the file by removing it
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting the file." << std::endl;
        return 1;
    }

    // Note: In C++, writing "TEXT" to a file typically sets the file position to 4,
    // because it directly corresponds to the number of bytes written.
    // Here, we adjust the Fortran code or the check to ensure consistency.
    if (position != 4) { // Adjusted to match the actual file position after writing "TEXT"
        std::cerr << "C++: File position is not as expected. Position: " << position << std::endl;
        return 1;
    }

    std::cout << "C++: Test PASSED, position is " << position << std::endl;

    return 0; // Success
}