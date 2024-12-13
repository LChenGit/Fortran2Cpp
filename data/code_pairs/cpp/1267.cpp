#include <cmath> // For std::abs

float mySign(float parm1, float parm2) {
    return (parm2 >= 0) ? std::abs(parm1) : -std::abs(parm1);
}