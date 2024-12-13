#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<int> j(5);
    std::string x = "ab";
    std::string y = "cd";
    std::vector<std::string> z(2);
    
    z[0] = y.substr(0, y.find_last_not_of(" ") + 1) + x.substr(0, x.find_last_not_of(" ") + 1);
    z[1] = x.substr(0, x.find_last_not_of(" ") + 1) + y.substr(0, y.find_last_not_of(" ") + 1);
    
    for (size_t i = 0; i < 5; ++i) {
        j[i] = (i < z[0].size()) ? static_cast<int>(z[0][i]) : 32; // Fill with ASCII of space if out of bounds
    }
    if (j != std::vector<int>{99, 100, 32, 32, 32}) {
        std::cerr << "Error 1" << std::endl;
        return 1; // Stop the program with an error
    }
    
    for (size_t i = 0; i < 5; ++i) {
        j[i] = (i < z[1].size()) ? static_cast<int>(z[1][i]) : 32; // Fill with ASCII of space if out of bounds
    }
    if (j != std::vector<int>{97, 98, 32, 32, 32}) {
        std::cerr << "Error 2" << std::endl;
        return 2; // Stop the program with an error
    }
    
    x = "a ";
    z[0] = y.substr(0, y.find_last_not_of(" ") + 1) + x.substr(0, x.find_last_not_of(" ") + 1);
    z[1] = x.substr(0, x.find_last_not_of(" ") + 1) + y.substr(0, y.find_last_not_of(" ") + 1);
    
    std::cout << "C++ code executed successfully." << std::endl;
    
    return 0; // Program completed successfully
}