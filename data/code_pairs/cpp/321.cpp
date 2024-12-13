#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void writeVector(const std::vector<double>& ad, int neq, int number) {
    std::string name = "vector_" + std::string(1, char(number + 96)) + ".out";

    std::ofstream outFile(name);
    if (!outFile) {
        std::cerr << "Failed to open file: " << name << std::endl;
        return;
    }

    outFile << "vector number " << number << std::endl;
    for (int i = 0; i < neq; ++i) {
        outFile << "row " << (i+1) << " value " << ad[i] << std::endl;
    }
}

int main() {
    std::vector<std::vector<double>> vectors = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    std::vector<int> nums = {1, 2, 3};

    for(size_t i = 0; i < nums.size(); ++i) {
        writeVector(vectors[i], vectors[i].size(), nums[i]);
    }

    return 0;
}