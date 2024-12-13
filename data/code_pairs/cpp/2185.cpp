#include <iostream>
#include <iomanip>

float f(float x, float t) {
    return -100.0f * x + 100.0f * t + 101.0f;
}

int main() {
    int N;
    float x, h;

    h = 0.01f;
    N = static_cast<int>(1.0f / h);

    x = 1.01f;
    std::cout << std::fixed << std::setprecision(2) << 0.0 << " " << x << std::endl;
    for (int i = 1; i <= N; ++i) {
        x = x + h * f(x, (i - 1) * h);
        std::cout << i * h << " " << x << std::endl;
    }

    return 0;
}