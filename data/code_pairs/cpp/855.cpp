#include <iostream>
#include <cmath>

void ts_calc(double xflow, double Tt, double Pt, double kappa, double r, double a, int icase, double& Ts) {
    const double expon = -0.5 * (kappa + 1.0) / (kappa - 1.0);
    const double C = std::sqrt(2.0 / r * kappa / (kappa - 1.0));
    double Ts_old = Tt;
    
    if (std::abs(xflow) <= 1e-9) {
        Ts = Tt;
        return;
    }
    
    double Qred = std::abs(xflow) * std::sqrt(Tt) / (a * Pt);
    Ts = Tt / (1 + std::pow(Qred / C, 2));
    
    double TtzTs_crit = (icase == 0) ? (kappa + 1.0) / 2.0 : 1.0 + (kappa - 1.0) / (2.0 * kappa);
    double Qred_crit = C * std::pow(TtzTs_crit, expon) * std::sqrt(TtzTs_crit - 1.0);
    
    if (Qred >= Qred_crit) {
        Ts = Tt / TtzTs_crit;
        return;
    }
    
    int i = 0;
    do {
        ++i;
        double TtzTs = Tt / Ts;
        double h1 = TtzTs - 1.0;
        double h2 = std::sqrt(h1);
        double h3 = std::pow(TtzTs, expon);
        double f = C * h2 * h3;
        double df = f * (expon + 0.5 * TtzTs / h1) / Ts;
        f = Qred - f;
        double deltaTs = -f / df;
        Ts += deltaTs;
        
        if (std::abs(Ts - Ts_old) / Ts_old <= 1e-8 || std::abs(Ts - Ts_old) <= 1e-10) break;
        if (i > 20) {
            Ts = 0.9 * Tt;
            break;
        }
        Ts_old = Ts;
    } while (true);
}

int main() {
    double Ts;
    ts_calc(0.5, 300.0, 101325.0, 1.4, 287.0, 340.0, 0, Ts);
    std::cout << "Calculated Ts: " << Ts << std::endl;
    return 0;
}