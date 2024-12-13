#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <omp.h>

void putevalfv(const std::string& fext, int ik, const std::vector<std::vector<double>>& evalfv) {
    std::string filename = "EVALFV" + fext;
    std::fstream file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    #pragma omp critical(u120)
    {
        // Assuming vkl and other data are serialized similarly
        // Directly writing evalfv for simplicity
        for (const auto& row : evalfv) {
            for (const auto val : row) {
                file.write(reinterpret_cast<const char*>(&val), sizeof(double));
            }
        }
    }

    file.close();
}

int main() {
    std::string fext = ".test";
    int ik = 1;
    std::vector<std::vector<double>> evalfv = {{1.1, 1.2}, {2.1, 2.2}};

    putevalfv(fext, ik, evalfv);

    std::cout << "Test executed, check the EVALFV" + fext + " file for output." << std::endl;
    return 0;
}