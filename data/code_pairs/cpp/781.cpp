#include <fstream>
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main() {
    std::ofstream fileStream("foo_open_negative_unit_1.txt");
    if (!fileStream) {
        std::cerr << "Error opening file foo_open_negative_unit_1.txt\n";
        std::abort();
    }
    fileStream.close();

    if (!fs::remove("foo_open_negative_unit_1.txt")) {
        std::cerr << "Error deleting file foo_open_negative_unit_1.txt\n";
        std::abort();
    }

    if (fs::exists("foo_open_negative_unit_1.txt")) {
        std::cerr << "File foo_open_negative_unit_1.txt should have been deleted.\n";
        std::abort();
    }

    std::cout << "C++ program operations completed.\n";

    return 0;
}