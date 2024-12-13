// test.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <cstdio> // For std::remove

void asyncWrite(const std::string& filename, const std::vector<float>& data) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::out);
    if (!outFile) {
        throw std::runtime_error("Failed to open file for writing.");
    }
    outFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(float));
    outFile.close();
}

bool fileExists(const std::string& filename) {
    std::ifstream infile(filename);
    return infile.good();
}

int main() {
    std::string filename = "test_async.dat";
    std::vector<float> data(10000, 1.0f);

    // Clean up before test
    std::remove(filename.c_str());

    // Execute the asyncWrite function in a thread to simulate asynchronous behavior
    std::thread writeThread(asyncWrite, filename, std::ref(data));
    writeThread.join(); // Wait for the async operation to finish

    // Test if file exists after writing
    if (!fileExists(filename)) {
        std::cerr << "Test Failed: File does not exist after writing." << std::endl;
        return 1;
    }

    // Delete the file and check if it has been deleted
    std::remove(filename.c_str());
    if (fileExists(filename)) {
        std::cerr << "Test Failed: File exists after deletion." << std::endl;
        return 1;
    }

    std::cout << "Test Passed: File written and deleted successfully." << std::endl;
    return 0;
}