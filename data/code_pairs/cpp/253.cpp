// Save as darnan.cpp
#include <cmath> // for std::isnan()

void DARNAN(double NUM, int& INFO) {
    INFO = 0;
    
    if (std::isnan(NUM)) {
        INFO = 1;
    }
}