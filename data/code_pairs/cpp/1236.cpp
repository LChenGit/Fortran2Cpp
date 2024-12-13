#ifndef NEUTRINO_DEF_H
#define NEUTRINO_DEF_H

namespace neutrino_def {

enum icore_nu {
    icore_nu_brem = 1,
    icore_nu_mUrca,
    icore_nu_dUrca,
    icore_nu_PBF,
    num_core_nu_channels = 4
};

constexpr bool core_nu_minimal_cooling[num_core_nu_channels] = {true, true, false, true};

constexpr bool core_nu_enhanced_cooling[num_core_nu_channels] = {true, true, true, true};

struct core_neutrino_emissivity_channels {
    double total;
    double brem;
    double brem_np;
    double brem_pp;
    double brem_nn;
    double mUrca;
    double mUrca_p;
    double mUrca_n;
    double dUrca;
    double PBF;
    double PBF_n;
    double PBF_p;
};

enum icrust_nu {
    icrust_nu_pair = 1,
    icrust_nu_photo,
    icrust_nu_plasma,
    icrust_nu_brems,
    icrust_nu_pbf,
    num_crust_nu_channels = 5
};

constexpr bool crust_nu_full_cooling[num_crust_nu_channels] = {true, true, true, true, true};

struct crust_neutrino_emissivity_channels {
    double total;
    double pair;
    double photo;
    double plasma;
    double brems;
    double pbf;
};

} // namespace neutrino_def

#endif // NEUTRINO_DEF_H