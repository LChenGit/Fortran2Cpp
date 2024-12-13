#include <iostream>
#include <array>

// Assuming external functions are appropriately defined elsewhere.
void DARACH1(int size, std::array<double, 2>& arr, int& info) {
    // Mock implementation
}

void UARERR(const char* file, int line, const char* message, int& info, int errorCode) {
    // Mock implementation
}

void DARCG22(double& a, double& b, double& c, double& d, double& nrm, int& info) {
    // Mock implementation
}

void DARFGR(char JOB, std::array<double, 2>& Q1, std::array<double, 2>& Q2, int& INFO) {
    INFO = 0;
    double nrm;

    if (JOB == 'R') {
        nrm = Q1[0] * Q2[0] - Q1[1] * Q2[1];
        Q1[1] = Q1[1] * Q2[0] + Q1[0] * Q2[1];
        Q1[0] = nrm;
    } else if (JOB == 'L') {
        nrm = Q1[0] * Q2[0] - Q1[1] * Q2[1];
        Q2[1] = Q1[1] * Q2[0] + Q1[0] * Q2[1];
        Q2[0] = nrm;
    } else {
        INFO = -1;
    }
}

int main() {
    char JOB = 'R';
    std::array<double, 2> Q1 = {1.0, 2.0};
    std::array<double, 2> Q2 = {3.0, 4.0};
    int INFO = 0;

    std::cout << "Before DARFGR: Q1 = [" << Q1[0] << ", " << Q1[1] << "], Q2 = [" << Q2[0] << ", " << Q2[1] << "]" << std::endl;

    DARFGR(JOB, Q1, Q2, INFO);

    std::cout << "After DARFGR: Q1 = [" << Q1[0] << ", " << Q1[1] << "], Q2 = [" << Q2[0] << ", " << Q2[1] << "]" << std::endl;
    std::cout << "INFO: " << INFO << std::endl;

    return 0;
}