#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

void write_portion_to_file(const std::string& filename, int m, int n, int i, int nrow, const std::vector<std::vector<double>>& array);

int main() {
    const int m = 10, n = 5, i = 3, nrow = 4;
    std::vector<std::vector<double>> array(m, std::vector<double>(n));

    // Initialize the array with some data for demonstration
    for(int j = 0; j < m; ++j) {
        for(int k = 0; k < n; ++k) {
            array[j][k] = std::sin(static_cast<double>(j+1) * static_cast<double>(k+1));
        }
    }

    // Write a portion of the array to a file
    write_portion_to_file("output.txt", m, n, i, nrow, array);

    return 0;
}

void write_portion_to_file(const std::string& filename, int m, int n, int i, int nrow, const std::vector<std::vector<double>>& array) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    // Write the specified portion of the array to the file
    for(int j = i-1; j < std::min(i-1 + nrow, m); ++j) {
        for(int k = 0; k < n; ++k) {
            file << std::fixed << std::showpoint << std::setprecision(5) << array[j][k] << " ";
        }
        file << std::endl;
    }
}