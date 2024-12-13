#include <cmath>
#include <cstdio>

void sctovec(const double tp[2], double v[3]) {
    double t1 = std::sin(tp[0]);
    v[0] = t1 * std::cos(tp[1]);
    v[1] = t1 * std::sin(tp[1]);
    v[2] = std::cos(tp[0]);
}

int main() {
    double tp[2] = { 1.0, 0.5 }; // Example input
    double v[3]; // Output vector

    sctovec(tp, v);

    // Print the result
    printf("v = [%f, %f, %f]\n", v[0], v[1], v[2]);

    return 0;
}