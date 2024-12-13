#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void writeqnode(int myid, const double* qnode, int qnodesize) {
    std::string filename = std::to_string(1000 + myid) + ".txt";
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    outFile << std::scientific << std::setprecision(8);

    for (int i = 0; i < qnodesize; ++i) {
        outFile << " " << qnode[i] << std::endl;
    }

    outFile.close();
}