#include <array>

std::array<float, 4> x_dot(float kon_1, float koff_1, float kon_2, float koff_2,
                           float f_plus, float g_minus, float g_plus, float Ca,
                           const std::array<float, 4>& x) {
    std::array<float, 4> f;

    f[0] = -kon_1 * Ca * x[0] + koff_1 * x[1] + g_minus * x[3];
    f[1] =  kon_1 * Ca * x[0] - (koff_1 + f_plus) * x[1] + g_plus * x[2];
    f[2] =  f_plus * x[1] - (g_plus + koff_2) * x[2] + kon_2 * Ca * x[3];
    f[3] =  koff_2 * x[2] - (g_minus + kon_2 * Ca) * x[3];

    return f;
}