// Include this function in the x_wc06.cpp file or directly in the test file
#include <cmath>

void x_wc06(double rho, double s, double u, double v, double& ex, double& vx) {
    const double ax = -0.7385587663820224059;
    const double mu = 0.2195149727645171;
    const double kappa = 0.804;
    const double b = 10.0 / 81.0;
    const double c = 0.00793746933516;
    const double thrd = 1.0 / 3.0;
    const double thrd4 = 4.0 / 3.0;
    
    double exu, dmu, s2, s4, es2, x, p0, fxwc;
    double fs, fss, t0, t1, t2, t3;
    
    exu = ax * std::pow(rho, thrd);
    s2 = s * s;
    s4 = s2 * s2;
    es2 = std::exp(-s2);
    t0 = 1.0 + c * s4;
    dmu = mu - b;
    x = b * s2 + dmu * s2 * es2 + std::log(t0);
    p0 = 1.0 + x / kappa;
    fxwc = 1.0 + kappa - kappa / p0;
    ex = exu * fxwc;
    
    t1 = b + dmu * (1.0 - s2) * es2 + 2.0 * c * s2 / t0;
    t2 = dmu * s * (s2 - 2.0) * es2 + 2.0 * c / t0 - 4.0 * (c * c) * s4 / (t0 * t0);
    t3 = 1.0 / (p0 * p0);
    fs = 2.0 * t1 * t3;
    fss = t3 * (4.0 * t2 - 8.0 * s * (t1 * t1) / (kappa * p0));
    vx = exu * (thrd4 * fxwc - (u - thrd4 * s2 * s) * fss - v * fs);
}