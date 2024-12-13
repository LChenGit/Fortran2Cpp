#include <fstream>
#include <cstdio>

int main() {
    std::string filename = "tmpfile";
    std::ofstream file(filename, std::ios::out);
    if (!file.is_open()) {
        return 1; // Error handling
    }
    file << "Test";
    file.close();
    
    if (std::remove(filename.c_str()) != 0) {
        return 1; // Error handling
    }
    return 0;
}