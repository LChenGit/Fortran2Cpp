#include <iostream>
#include <fstream>
#include <vector>

struct MFE010 {
    static int nnod, ntri;
};

struct MFE070 {
    static double hlast;
    static float cpusec;
    static int stats[8];
};

// Initialize static members
int MFE010::nnod = 0, MFE010::ntri = 0;
double MFE070::hlast = 0.0;
float MFE070::cpusec = 0.0;
int MFE070::stats[8] = {0};

void wrsoln(double t, const std::vector<std::vector<double>>& y) {
    std::ofstream outFile("output.txt");

    outFile << t << std::endl;
    for (size_t j = 0; j < static_cast<size_t>(MFE010::nnod); ++j) {
        outFile << y[1][j] << " " << y[2][j] << " " << y[0][j] << std::endl;
    }

    outFile << MFE070::hlast << " " << MFE070::cpusec;
    for (int stat : MFE070::stats) {
        outFile << " " << stat;
    }
    outFile << std::endl;

    outFile.close();
}

int main() {
    // Example usage
    double t = 2.0;
    std::vector<std::vector<double>> y = {{1.0, 2.0, 3.0}, {2.0, 3.0, 4.0}, {3.0, 4.0, 5.0}};
    MFE010::nnod = 3;
    MFE010::ntri = 1;
    MFE070::hlast = 0.5;
    MFE070::cpusec = 1.2;
    for (int i = 0; i < 8; ++i) {
        MFE070::stats[i] = i + 1;
    }

    wrsoln(t, y);

    return 0;
}