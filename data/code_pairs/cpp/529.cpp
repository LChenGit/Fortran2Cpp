#include <iostream>
#include <vector>

void hp_R_points(std::vector<std::vector<double>>& Rvect, const std::vector<std::vector<double>>& at, int nq1, int nq2, int nq3, int nqsh) {
    Rvect.resize(3, std::vector<double>(nqsh));

    if (nqsh == 1) {
        for (int i = 0; i < 3; ++i) {
            Rvect[i][0] = 0.0;
        }
    } else {
        int icell = 0;
        for (int i = 1; i <= nq1; ++i) {
            for (int j = 1; j <= nq2; ++j) {
                for (int k = 1; k <= nq3; ++k) {
                    for (int dim = 0; dim < 3; ++dim) {
                        Rvect[dim][icell] = ((double)(i - 1)) * at[dim][0] +
                                            ((double)(j - 1)) * at[dim][1] +
                                            ((double)(k - 1)) * at[dim][2];
                    }
                    icell++;
                }
            }
        }
    }
}

int main() {
    int nq1 = 3, nq2 = 3, nq3 = 3, nqsh = 27;
    std::vector<std::vector<double>> at = {{1.0, 0.0, 0.0},
                                           {0.0, 1.0, 0.0},
                                           {0.0, 0.0, 1.0}};
    std::vector<std::vector<double>> Rvect;
    hp_R_points(Rvect, at, nq1, nq2, nq3, nqsh);

    std::cout << "Testing hp_R_points..." << std::endl;
    if (Rvect[0][0] == 0.0 && Rvect[2][nqsh-1] == 2.0) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    std::cout << "Rvect Array:" << std::endl;
    for (size_t icell = 0; icell < Rvect[0].size(); ++icell) {
        std::cout << "Column " << icell + 1 << ": ";
        for (int dim = 0; dim < 3; ++dim) {
            std::cout << Rvect[dim][icell] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}