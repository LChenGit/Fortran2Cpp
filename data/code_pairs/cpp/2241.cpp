#include <iostream>
#include <vector>

class ZeroMatrix {
public:
    void zerom(int M, std::vector<std::vector<double>>& X) {
        X.resize(M);
        for (int i = 0; i < M; ++i) {
            X[i].resize(M, 0.0); // Initialize with 0.0 during resize
        }
    }
};

bool test_zerom() {
    int M = 5;
    std::vector<std::vector<double>> X;

    ZeroMatrix zm;
    zm.zerom(M, X);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (X[i][j] != 0.0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (test_zerom()) {
        std::cout << "C++ test passed." << std::endl;
    } else {
        std::cout << "C++ test failed." << std::endl;
    }
    return 0;
}