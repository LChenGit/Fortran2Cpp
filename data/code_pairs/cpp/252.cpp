#ifndef INIT_CONDS_H
#define INIT_CONDS_H

void init_conds(double x, double y, double z, double& rho, double& ux, double& uy, double& uz, double& p) {
    uz = 0.0;

    if (x >= 0.25 && x <= 0.75 && y >= 0.25 && y <= 0.75) {
        p = 2.5;
        rho = 4.0;
    } else {
        p = 2.5;
        rho = 1.0;
    }

    ux = 0.5;
    uy = 0.5;
}

#endif // INIT_CONDS_H