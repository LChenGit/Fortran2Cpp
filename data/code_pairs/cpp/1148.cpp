#include <iostream>
using namespace std;

void TestVariables(double A, int I) {
    if (A == 3.4 && I == 3) {
        cout << "Test Passed" << endl;
    } else {
        cout << "Test Failed" << endl;
    }
}

int main() {
    double A = 3.4;
    int I = 3;
    
    TestVariables(A, I);
    
    return 0;
}