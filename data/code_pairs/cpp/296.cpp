#include <iostream>
#include <vector>
#include <memory>

namespace internal_types {
    constexpr int Simplex = 1;
    constexpr int Hyperrectangle = 2;
    constexpr int EPSTABLENGHT = 52;
    using stnd = double; // Assuming double precision

    class integrator_info {
    public:
        int key, nrsub;
        stnd tune;
        bool uniform_subdiv;
        integrator_info() : key(0), nrsub(0), tune(0.0), uniform_subdiv(false) {}
    };

    class collection_info {
    public:
        int dimens, nrvert, niinfo, nrinfo;
        collection_info() : dimens(0), nrvert(0), niinfo(0), nrinfo(0) {}
    };

    class user_info {
    public:
        int numfun, numrgn, minpts, maxpts;
        stnd epsabs, epsrel;
        bool restart;
        int neval, ifail;
        user_info() : numfun(0), numrgn(0), minpts(0), maxpts(0),
                      epsabs(0.0), epsrel(0.0), restart(false), neval(0), ifail(0) {}
    };

    class epsalg_mem {
    public:
        bool HEURISTIC_USED;
        int DIVLEVEL;
        std::unique_ptr<std::vector<int>> NRRCOPY;
        stnd ERRORMAXPOOL, EPSABS, EPSREL;
        std::unique_ptr<std::vector<stnd>> ERLARG, RESULT1, ABSERR1;
        std::unique_ptr<std::vector<std::vector<stnd>>> RCOPY, RESLA;
        epsalg_mem() : HEURISTIC_USED(false), DIVLEVEL(0), ERRORMAXPOOL(0.0), EPSABS(0.0), EPSREL(0.0) {}
    };
}

int main() {
    using namespace internal_types;

    integrator_info exampleIntegrator;
    exampleIntegrator.key = 10; // Adjusted to match Fortran test output
    std::cout << "Example integrator_info object:" << std::endl;
    std::cout << "Key: " << exampleIntegrator.key << std::endl;

    return 0;
}