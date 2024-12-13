#include <iostream>
#include <vector>

bool testSubmatrixAssignment(std::vector<std::vector<int>>& A, int n);

int main() {
    const int n = 5;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));

    if (testSubmatrixAssignment(A, n)) {
        std::cout << "Main logic passed." << std::endl;
    } else {
        std::cerr << "Main logic failed." << std::endl;
        return 1;
    }

    return 0;
}

bool testSubmatrixAssignment(std::vector<std::vector<int>>& A, int n) {
    int startRow = 2, endRow = 4;
    int startCol = 2, endCol = 4;

    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            A[i-1][j-1] = 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (2 <= i && i <= 4 && 2 <= j && j <= 4) {
                if (A[i-1][j-1] != 2) {
                    return false;
                }
            } else {
                if (A[i-1][j-1] != 1) {
                    return false;
                }
            }
        }
    }
    return true;
}