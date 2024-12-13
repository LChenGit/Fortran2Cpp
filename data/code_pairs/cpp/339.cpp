// stream_test.cpp
#include <fstream>
#include <cstdio>
#include <iostream>

void writeToTempFile() {
    char tempFilename[L_tmpnam];
    std::tmpnam(tempFilename); // Note: std::tmpnam has been considered dangerous; consider using std::filesystem in C++17 and beyond.
    
    std::ofstream fileStream(tempFilename, std::ios::binary);
    if (fileStream) {
        fileStream << "This is a test";
        fileStream.close();
        std::cout << "File write successful." << std::endl;
    } else {
        std::cerr << "Error occurred during file write." << std::endl;
    }
    std::remove(tempFilename); // Delete the temporary file
}

int main() {
    writeToTempFile();
    return 0;
}