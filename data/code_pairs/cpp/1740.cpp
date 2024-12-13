#include <vector>
#include <complex>

namespace constants {
    const double bohr_r = 0.05291772108;
    const double hbarc = 197.326968;
    const double pi = 3.141592741012573;
    const double pi_2 = pi / 2.0;
    const double pi_4 = pi / 4.0;
}

namespace system_ns {
    using namespace constants;

    class SpQuantumNumbers {
    public:
        int TotalOrbits;
        std::vector<int> n, s, ms, parity;
        std::vector<double> masses, energy;
    };

    class TwoDim : public SpQuantumNumbers {
    public:
        std::vector<int> ml;
    };

    class ThreeDim : public TwoDim {
    public:
        std::vector<int> l, j, mj;
    };

    class nucleons : public ThreeDim {
    public:
        std::vector<int> t, tz;
    };

    class hyperons : public nucleons {
    public:
        std::vector<int> strange;
    };
}