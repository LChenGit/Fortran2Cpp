#include <iostream>
#include <vector>

void checkRange(const std::vector<int>& iArray, int nItems, int maxVal, int& nZero, int& nErr);

int main() {
    std::vector<int> iArray = {0, 2, 5, 10, 15};
    int nItems = iArray.size();
    int maxVal = 10;
    int nZero = 0;
    int nErr = 0;

    checkRange(iArray, nItems, maxVal, nZero, nErr);

    std::cout << "NZERO = " << nZero << std::endl;
    std::cout << "NERR = " << nErr << std::endl;

    return 0;
}

void checkRange(const std::vector<int>& iArray, int nItems, int maxVal, int& nZero, int& nErr) {
    nZero = 0;
    nErr = 0;

    for (int i = 0; i < nItems; i++) {
        int n = iArray[i];
        if (n < 1) {
            nZero++;
        }
        if (n > maxVal) {
            nErr++;
        }
    }
}