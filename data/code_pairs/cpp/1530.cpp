#include <cmath> // For log10

float db(float x) {
    float result = -99.0f;
    if (x > 1.259e-10f) {
        result = 10.0f * log10(x);
    }
    return result;
}