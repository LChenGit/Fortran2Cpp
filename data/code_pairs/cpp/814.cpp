#include <fstream>
#include <iostream>

int main() {
    std::ofstream out("output_cpp.txt");
    if (!out) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }
    for(int i = 1; i <= 3; ++i) {
        out << 0 << std::endl;
        out << 1 << std::endl;
    }
    out << 2 << std::endl;
    
    out.close();
    
    return 0;
}