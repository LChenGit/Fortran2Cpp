#include <iostream>
#include <vector>

using namespace std;

int ISRCHFLE(int N, const vector<double>& array, int istep, double value);

void test_ISRCHFLE() {
    vector<double> testArray = {10.0, 20.0, 30.0, 40.0, 50.0};
    int result = ISRCHFLE(testArray.size(), testArray, 1, 25.0);
    
    if (result == 2) {
        cout << "Test passed." << endl;
    } else {
        cout << "Test failed: Expected 2, got " << result << endl;
    }
}

int main() {
    test_ISRCHFLE();
    return 0;
}

int ISRCHFLE(int N, const vector<double>& array, int istep, double value) {
    int i = -1;
    for (int k = N - 1; k >= 0; k -= istep) {
        double arr = array[k];
        if (arr <= value) {
            i = k + 1; // Adjusting for 1-based indexing
            break;
        }
    }
    return i;
}