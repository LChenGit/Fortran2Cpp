#ifndef MOD_VISCOSITY_H
#define MOD_VISCOSITY_H

namespace MOD_EOS_Vars {
    const double mu0 = 1.0;
    const double Tref = 1.0;
    const double Ts = 2.0;
    const double ExpoSuth = 0.5;
    const double cSuth = 0.5;
}

class MOD_Viscosity {
public:
    static double muSuth(double T) {
        using namespace MOD_EOS_Vars;
        double TnoDim = T * Tref;
        if (TnoDim >= Ts) {
            return mu0 * std::pow(TnoDim, ExpoSuth) * (1 + Ts) / (TnoDim + Ts);
        } else {
            return mu0 * TnoDim * cSuth;
        }
    }
};

#endif // MOD_VISCOSITY_H