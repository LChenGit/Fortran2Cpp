#include <cmath>
#include <algorithm>

void cd_ms_ms(double p1, double p2, double T1, double rad, double d, double xl, double kappa, double r, double reynolds, double u, double& vid, double& cd) {
    double qlim = 10.0;
    double q, c1, c2, c3, fakt, aux, rzd, lkorr, qkorr, rv;

    cd = 0.5885 + 372.0 / reynolds;
    cd = std::min(cd, 1.0);

    rzd = rad / d;
    aux = std::exp(-(3.5 * rzd + 5.5) * rzd);
    fakt = aux + 0.008 * (1.0 - aux);
    cd = 1.0 - fakt * (1.0 - cd);
    cd = std::min(std::max(cd, 0.0), 1.0);

    lkorr = xl - rad;
    q = lkorr / d;
    qkorr = std::min(q, qlim);
    fakt = (1.0 + 1.3 * std::exp(-1.606 * std::pow(qkorr, 2.0))) *
           (0.435 + 0.021 * qkorr) / (2.3 * 0.435);
    cd = 1.0 - fakt * (1.0 - cd);
    cd = std::min(std::max(cd, 0.0), 1.0);

    if(u != 0.0) {
        vid = std::sqrt(2.0 * kappa / (kappa - 1.0) * r * T1 *
              (1.0 - std::pow((p2 / p1), (kappa - 1.0) / kappa)));
        rv = u / vid * std::pow((0.6 / cd), 3);
        c1 = std::exp(-std::pow(rv, 1.2));
        c2 = 0.5 * std::pow(rv, 0.6) * std::sqrt(0.6 / cd);
        c3 = std::exp(-0.5 * std::pow(rv, 0.9));
        cd = cd * (c1 + c2 * c3);
        cd = std::min(std::max(cd, 0.0), 1.0);
    }
}