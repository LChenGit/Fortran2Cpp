#include <cmath>
#include <chrono>

float ABSF(float x) {
    return std::abs(x);
}

float SIGNF(float x, float y) {
    return (y >= 0) ? std::abs(x) : -std::abs(x);
}

float INTF(float x) {
    return std::trunc(x);
}

float SQRTF(float x) {
    return std::sqrt(x);
}

float SINF(float x) {
    return std::sin(x);
}

float COSF(float x) {
    return std::cos(x);
}

float ARCOSF(float x) {
    return std::acos(x);
}

float ARSINF(float x) {
    return std::asin(x);
}

float ATN1F(float x, float y) {
    return std::atan2(x, y);
}

float CLOCKF(float xx) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    // Convert milliseconds to seconds for a more comparable result to Fortran's SYSTEM_CLOCK
    return millis / 1000.0;
}