#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // For std::remove

int main() {
    std::string filename = "cpp_testfile";
    std::ofstream outFile(filename);

    // Check if file is open
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;
    }

    // Write to the file
    outFile << "Test" << std::endl;
    // Close the file
    outFile.close();

    // Open the file for reading
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open the file for reading." << std::endl;
        return 1;
    }

    // Read from the file
    std::string line;
    std::getline(inFile, line);
    // Print the line read from the file
    std::cout << "Read from file: " << line << std::endl;
    // Close the file
    inFile.close();

    // Delete the file
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting the file." << std::endl;
    }

    return 0;
}