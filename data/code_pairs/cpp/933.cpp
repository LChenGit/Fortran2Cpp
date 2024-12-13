#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("test.dat", std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Failed to open test.dat" << std::endl;
        return 1; 
    }

    file << "Hello world!" << std::endl;
    file.close();

    return 0;
}