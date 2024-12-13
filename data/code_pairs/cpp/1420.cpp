#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string c = "     ";
    std::ofstream outFile("output.txt");
    outFile << c;
    outFile.close();
    return 0;
}