#include <array>
#include <cmath>

// Constants
constexpr int gtype = 0;
constexpr int ndim = 2;
constexpr int nfael = 3;
constexpr int nnofa = 2;
constexpr int nelem_max = 1000;
constexpr int nface_max = 1000;
constexpr int npoin_max = 10000;
constexpr double pi = std::atan(1.0) * 4.0;
constexpr double tol = 1.0E-12;
constexpr double leps = 1.0E-6;
constexpr double sin60 = std::sin(pi / 3.0);
constexpr double tan60 = std::tan(pi / 3.0);

// Variables
double he;
double he2;

// Face structure
struct Face {
    int fid;
    int eleid;
    int state;
    double flen;
    std::array<int, nnofa> fnode;
    std::array<double, ndim> nhat;
};