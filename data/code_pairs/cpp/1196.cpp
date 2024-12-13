#include <iostream>
using namespace std;

float asum(float* a, int n, float a0) {
    float result = a0;
    for(int i = 0; i < n; i++) {
        result += a[i];
    }
    return result;
}

void testAsum() {
    float a[8];
    for(int i = 0; i < 8; i++) {
        a[i] = i + 1; // Fill the array
    }

    float result = asum(a, 8, 0.0f);
    if(result == 36.0f) {
        cout << "Test PASS" << endl;
    } else {
        cout << "Test FAIL: Expected 36.0, got " << result << endl;
    }
}

int main() {
    testAsum();
    return 0;
}