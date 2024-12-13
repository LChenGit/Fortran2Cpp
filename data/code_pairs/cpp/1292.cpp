#include <iostream>
#include <fstream>
#include <cstdio> // For std::remove

bool fileExists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

int main() {
    std::string fileName = "99";

    // Create and write to the file
    std::ofstream fileUnit(fileName);
    fileUnit << "Testing file creation.";
    fileUnit.close();

    // Check if the file exists
    if (fileExists(fileName)) {
        std::cout << "File '99' exists after creation." << std::endl;
    } else {
        std::cout << "File '99' does not exist." << std::endl;
    }

    // Delete the file
    std::remove(fileName.c_str());

    // Check again if the file exists
    if (fileExists(fileName)) {
        std::cout << "File '99' exists after deletion." << std::endl;
    } else {
        std::cout << "File '99' does not exist after deletion." << std::endl;
    }

    return 0;
}