#ifndef ARG_NUT_H
#define ARG_NUT_H

#include <cmath>

namespace arg_nut {

    const double pi = 4.0 * atan(1.0);

    const double t2000 = 51544.5;
    const double Nbr_days_in_Century = 36525;

    const double phil = 134.96340251 * pi / 180.0;
    const double phils = 357.52910918 * pi / 180.0;
    const double phiF = 93.27209062 * pi / 180.0;
    const double phiD = 297.85019547 * pi / 180.0;
    const double phiomega = 125.04455501 * pi / 180.0;

    const double sigmal = 1717915923.2178 / 3600.0 * pi / 180.0;
    const double sigmals = 129596581.0481 / 3600.0 * pi / 180.0;
    const double sigmaF = 1739527262.8478 / 3600.0 * pi / 180.0;
    const double sigmaD = 1602961601.2090 / 3600.0 * pi / 180.0;
    const double sigmaomega = -6962890.5431 / 3600.0 * pi / 180.0;

} // namespace arg_nut

#endif // ARG_NUT_H