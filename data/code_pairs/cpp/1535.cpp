#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

class m_Useful {
private:
    static constexpr int k_pr = std::numeric_limits<double>::digits;
    static constexpr int k_mw = 40;
    static constexpr int k_ml = 255;

    struct frameType {
        std::string frameLabel;
        double timestamp;
        double bondCurrent;

        frameType() : timestamp(0), bondCurrent(0) {}
    };

public:
    struct cxzType {
        int natoms = 0;
        int nframes = 0;
        std::vector<frameType> frames;
        int atom1, atom2;
        double x1, y1, z1, x2, y2, z2;
        std::string element1, element2;

        cxzType() : atom1(0), atom2(0), x1(0), y1(0), z1(0), x2(0), y2(0), z2(0), element1(2, ' '), element2(2, ' ') {}
    };

    static void error(const std::string& message, const std::string& routine, bool critical, std::ostream& uout = std::cerr) {
        if (critical) {
            uout << "Critical error in subroutine: " << routine << std::endl;
        } else {
            uout << "Error message from subroutine: " << routine << std::endl;
        }

        uout << routine << ": " << message << std::endl;

        if (critical) {
            uout << routine << ": User stop." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    static int GetUnit() {
        static int ustart = 9;
        ustart += 1;
        return ustart;
    }
};