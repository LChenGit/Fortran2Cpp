#include <vector>

class GRVT_genmod {
public:
    static void GRVT(int ISHP, int NDS, const std::vector<double>& R, double GWT,
                     double GCONST, int GRAVDIR, double DENSITY, std::vector<double>& FINTE) {
        for (int i = 0; i < ISHP; ++i) {
            for (int j = 0; j < NDS; ++j) {
                FINTE[i * NDS + j] = GWT * GCONST * DENSITY * R[i] * GRAVDIR;
            }
        }
    }
};