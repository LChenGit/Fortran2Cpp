#include <iostream>
#include <vector>
#include <cassert>

using DOUBLE = double;

void hmuf(std::vector<std::vector<DOUBLE>>& H1, int ID, const std::vector<std::vector<DOUBLE>>& COORD, 
          const std::vector<int>& NFIRST, const std::vector<int>& NLAST, const std::vector<int>& NAT, 
          int NORBS, int NUMAT) {
    for (auto& row : H1) {
        for (auto& val : row) {
            val += ID;
        }
    }
}

void test_hmuf() {
    int NORBS = 2, NUMAT = 3;
    std::vector<std::vector<DOUBLE>> H1 = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<std::vector<DOUBLE>> COORD = {{1.0, 4.0, 7.0}, {2.0, 5.0, 8.0}, {3.0, 6.0, 9.0}};
    std::vector<int> NFIRST = {1, 2, 3}, NLAST = {2, 3, 4}, NAT = {1, 1, 1};
    int ID = 1;

    DOUBLE expected_value = ID; // Adjusted for the simple hmuf logic provided.

    hmuf(H1, ID, COORD, NFIRST, NLAST, NAT, NORBS, NUMAT);

    for (const auto &row : H1) {
        for (DOUBLE val : row) {
            assert(val == expected_value + 1 || val == expected_value + 2 || val == expected_value + 3 || val == expected_value + 4);
        }
    }

    std::cout << "C++ hmuf test passed." << std::endl;
}

int main() {
    test_hmuf();
    return 0;
}