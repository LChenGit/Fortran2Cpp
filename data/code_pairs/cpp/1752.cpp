#include <iostream>
#include <vector>

// Assuming extern definitions and allocate_pert/deallocate_pert functions are defined here
int nat = 10; // Example: global variable definition
int npertx = 5;

std::vector<std::vector<std::vector<std::vector<double>>>> t;
std::vector<std::vector<std::vector<double>>> tmq;

void allocate_pert() {
    t.resize(npertx);
    for (int i = 0; i < npertx; ++i) {
        t[i].resize(npertx);
        for (int j = 0; j < npertx; ++j) {
            t[i][j].resize(48);
            for (int k = 0; k < 48; ++k) {
                t[i][j][k].resize(3 * nat);
            }
        }
    }

    tmq.resize(npertx);
    for (int i = 0; i < npertx; ++i) {
        tmq[i].resize(npertx);
        for (int j = 0; j < npertx; ++j) {
            tmq[i][j].resize(3 * nat);
        }
    }
}

void deallocate_pert() {
    t.clear();
    tmq.clear();
    // Optionally, to ensure memory is freed immediately, you can use the swap trick
    std::vector<std::vector<std::vector<std::vector<double>>>>().swap(t);
    std::vector<std::vector<std::vector<double>>>().swap(tmq);
}

int main() {
    allocate_pert();
    std::cout << "C++ Stdout: Allocation successful." << std::endl;
    deallocate_pert();
    std::cout << "C++ Stdout: Deallocation successful." << std::endl;

    return 0;
}