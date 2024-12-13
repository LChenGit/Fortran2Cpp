#ifndef PRECISION_H
#define PRECISION_H

class Precision {
public:
    struct FitLookupTable {
        int fittype;
        int fitparm;
    };

    static constexpr double Yr = 31557600.0;
    static constexpr double Rsun = 696265000.0;
    static constexpr double Mearth = 5.97219e24;
    static constexpr double day = 86400.0;
    static constexpr double PI = 3.141592653589793;
    static constexpr double Gr = 6.6719842229637e-11;
    static constexpr double K2 = 2.959122082855911e-04;
    static constexpr double Msun = 1.9891e30;
    static constexpr double AU = 1.4959787e11;
    static constexpr double MU = Msun;
    static constexpr double TU = day;
    static constexpr double LU = AU;
};

#endif // PRECISION_H