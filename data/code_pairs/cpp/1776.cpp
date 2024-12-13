#include <iostream>
using namespace std;

// Function prototype
double PA_FROM_MB(double MB, double BADDATA);

int main() {
    double BADDATA = -999.0;
    double MB = 101.3;
    
    // Test with valid data
    cout << "Test with valid data: " << PA_FROM_MB(MB, BADDATA) << endl;
    // Test with BADDATA
    cout << "Test with BADDATA: " << PA_FROM_MB(BADDATA, BADDATA) << endl;

    return 0;
}

// Function definition
double PA_FROM_MB(double MB, double BADDATA) {
    if (MB != BADDATA) {
        return MB * 100.0;
    } else {
        return BADDATA;
    }
}