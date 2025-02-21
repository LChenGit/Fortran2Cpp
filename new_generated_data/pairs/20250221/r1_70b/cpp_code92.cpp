#include <fstream>
#include <iostream>

int main() {
    std::ofstream outfile("output.txt");
    
    if (outfile.is_open()) {
        outfile << "Hello, World!" << std::endl;
        outfile.close();
        std::cout << "Successfully wrote to output.txt" << std::endl;
    } else {
        std::cerr << "Unable to open output file";
        return 1; // Return with an error code
    }
    
    return 0;
}