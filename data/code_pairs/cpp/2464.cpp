#include <array>
#include <iostream>

void iau_PXP(const std::array<double, 3>& A, const std::array<double, 3>& B, std::array<double, 3>& AXB) {
    double XA = A[0];
    double YA = A[1];
    double ZA = A[2];
    double XB = B[0];
    double YB = B[1];
    double ZB = B[2];
    
    AXB[0] = YA * ZB - ZA * YB;
    AXB[1] = ZA * XB - XA * ZB;
    AXB[2] = XA * YB - YA * XB;
}

int main() {
    std::array<double, 3> A = {1.0, 2.0, 3.0};
    std::array<double, 3> B = {4.0, 5.0, 6.0};
    std::array<double, 3> AXB;
    
    iau_PXP(A, B, AXB);
    
    std::cout << "AXB = ";
    for (const auto& value : AXB) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}