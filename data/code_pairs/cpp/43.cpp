#include <iostream>
#include <cassert>

void rswitch(float& x, float& y) {
    float z = x;
    x = y;
    y = z;
}

void dswitch(double& x, double& y) {
    double z = x;
    x = y;
    y = z;
}

void iswitch(int& i, int& j) {
    int k = j;
    j = i;
    i = k;
}

int main() {
    float rf = 1.2f, rf2 = 3.4f;
    double rd = 1.234, rd2 = 5.678;
    int ri = 1, ri2 = 2;

    rswitch(rf, rf2);
    assert(rf == 3.4f && rf2 == 1.2f);  // Confirm values are swapped

    dswitch(rd, rd2);
    assert(rd == 5.678 && rd2 == 1.234);  // Confirm values are swapped

    iswitch(ri, ri2);
    assert(ri == 2 && ri2 == 1);  // Confirm values are swapped

    std::cout << "All tests passed!" << std::endl;

    return 0;
}