#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

// Function Declarations
void warn(const std::string& msg);
void tnoua(const std::string& ia, int nc);
void dasign(int lu, int mode, const std::string& ia, int len);
void vexit(int ierr);

int main() {
    warn("Test warn message");
    tnoua("TestTnoua", 8);
    dasign(1, -1, "example.txt", 100);
    // vexit(0); // This will terminate the program; uncomment to test

    return 0;
}

// Function Implementations
void warn(const std::string& msg) {
    std::cout << " " << msg << std::endl;
}

void tnoua(const std::string& ia, int nc) {
    std::cout << ia.substr(0, nc) << std::flush; // Using std::flush to avoid adding a newline
}

void dasign(int lu, int mode, const std::string& ia, int len) {
    // Simplified implementation example for demonstrating file operations
    std::fstream file;
    std::string filename = ia; // Assuming ia is the filename
    // Open file based on mode (This example doesn't fully replicate the Fortran logic)
    if (mode > 0) {
        file.open(filename, std::ios::out); // Simplified example
    } else {
        file.open(filename, std::ios::in); // Simplified example
    }
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    // Perform operations with the file here
    file.close();
}

void vexit(int ierr) {
    if (ierr != 0) {
        std::cout << "exit called with error code " << ierr << std::endl;
    }
    std::exit(ierr);
}