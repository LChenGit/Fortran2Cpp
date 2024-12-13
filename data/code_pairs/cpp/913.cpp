#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio> // For std::remove

bool write_and_delete_file(const std::string& filename, const std::vector<float>& array) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open()) {
        return false;
    }
    outFile.write(reinterpret_cast<const char*>(array.data()), array.size() * sizeof(float));
    if (!outFile.good()) {
        outFile.close();
        return false;
    }
    outFile.close();

    if (std::remove(filename.c_str()) != 0) {
        return false;
    }
    return true;
}

int main() {
    std::vector<float> array = {5.4321f, 5.4321f, 5.4321f, 5.4321f, 5.4321f};
    std::string filename = "data.bin";

    if (!write_and_delete_file(filename, array)) {
        return 1; // Indicate error
    }
    return 0; // Indicate success
}