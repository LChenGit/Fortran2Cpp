#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("data.bin", std::ios::binary);

    // Check if the file was successfully opened
    if (!file) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1; // Indicate an error
    }

    float num;

    // Attempt to read a floating-point number from the file
    if (!file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        std::cerr << "Read error!" << std::endl;
        return 1; // Indicate an error
    }

    // Print the number if read was successful
    std::cout << "Read number: " << num << std::endl;
    
    return 0; // Indicate success
}