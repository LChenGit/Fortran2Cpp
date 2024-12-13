#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int performFileIO(const std::string& tempFileName) {
    std::ofstream outputFile(tempFileName, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Failed to create or open the temporary file." << std::endl;
        return 1; // Error opening file
    }

    std::string message = "This is a test";
    outputFile.write(message.c_str(), message.size());
    if (!outputFile.good()) {
        std::cerr << "Error occurred during file write." << std::endl;
        outputFile.close();
        return 2; // Error during write
    }

    outputFile.close();
    return 0; // Success
}

int main() {
    std::string tempFileName = "tempfile.tmp";
    int result = performFileIO(tempFileName);
    
    // Cleanup
    std::remove(tempFileName.c_str());
    
    return result;
}