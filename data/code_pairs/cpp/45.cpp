#include <cstdint>
#include <string>

struct mod_parameters {
    static const int64_t i64; // Placeholder for demonstration
    static const int buffer_len;
    static const int nhb;
    static constexpr double a = 1.0;
    static double b;
    static std::string geometry;
    static double aratio, q, Pe, x0width, y0, z0, t_warmup, dt, dtmax, Tfinal;
    static int nGates, x0n, nbins;
    static bool save_hist, save_hist2d, use_external_ic, use_oscillatory;
    static std::string ic_file, tstep_type, other_file;
    static int64_t mt_seed;
};

// Initialization of static members
const int64_t mod_parameters::i64 = 0; // Placeholder, actual initialization may vary
const int mod_parameters::buffer_len = 100;
const int mod_parameters::nhb = 400;
double mod_parameters::b = 0.0;
std::string mod_parameters::geometry = "";
// Initialize other variables similarly...