#pragma once

namespace olbfgs_module {

// Implementation for double precision
double dolbfgs(double a, double b) {
    return a + b;
}

// Implementation for single precision
float solbfgs(float a, float b) {
    return a + b;
}

} // namespace olbfgs_module