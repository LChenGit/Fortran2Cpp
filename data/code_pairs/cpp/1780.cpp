#include <vector>
#include <complex>

class WannierNew {
public:
    static constexpr int ningx = 10;
    static inline bool use_wannier = false;
    static inline bool rkmesh = false;
    static inline bool plot_wannier = false;
    static inline bool use_energy_int = false;
    static inline bool print_wannier_coeff = false;
    static inline int nwan = 0;
    static inline int plot_wan_num = 0;
    static inline int plot_wan_spin = 0;
    static inline std::vector<std::vector<double>> wan_pot;
    static inline std::vector<std::vector<double>> wannier_energy;
    static inline std::vector<std::vector<std::vector<double>>> wannier_occ;
    static inline std::vector<std::vector<std::complex<double>>> pp;
    static inline std::vector<std::vector<std::vector<std::complex<double>>>> coef;

    struct Ingredient {
        int l = 0;
        int m = 0;
        int iatomwfc = 0;
        double c = 0.0;
    };

    struct WannierData {
        int iatom = 0;
        int ning = 0;
        double bands_from = 0.0;
        double bands_to = 0.0;
        std::vector<Ingredient> ing = std::vector<Ingredient>(ningx);
    };

    static inline std::vector<std::vector<WannierData>> wan_in;
};