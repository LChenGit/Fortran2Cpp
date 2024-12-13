#include <iostream>
#include <vector>
#include <iomanip>

void LUBKSB(std::vector<std::vector<double>>& A, int N, std::vector<int>& INDX, std::vector<double>& B) {
    int II = 0;
    
    for (int I = 0; I < N; ++I) {
        int LL = INDX[I];
        double SUM = B[LL];
        B[LL] = B[I];
        
        if (II != 0) {
            for (int J = II - 1; J < I; ++J) {
                SUM -= A[I][J] * B[J];
            }
        } else if (SUM != 0.0) {
            II = I + 1;
        }
        
        B[I] = SUM;
    }
    
    for (int I = N - 1; I >= 0; --I) {
        double SUM = B[I];
        if (I < N - 1) {
            for (int J = I + 1; J < N; ++J) {
                SUM -= A[I][J] * B[J];
            }
        }
        B[I] = SUM / A[I][I];
    }
}

int main() {
    // Example usage
    int N = 3;
    std::vector<std::vector<double>> A = {{2.0, -1.0, 0.0},
                                          {-1.0, 2.0, -1.0},
                                          {0.0, -1.0, 2.0}};
    std::vector<int> INDX = {0, 1, 2}; // Note: C++ uses 0-based indexing, adjust as needed
    std::vector<double> B = {1.0, 2.0, 3.0};

    LUBKSB(A, N, INDX, B);

    // Print solution
    std::cout << "Solution:" << std::endl;
    for (double x : B) {
        std::cout << std::fixed << std::setprecision(6) << x << " ";
    }
    std::cout << std::endl;

    return 0;
}