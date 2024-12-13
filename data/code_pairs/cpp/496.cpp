#include <vector>

class ModuleGeometry {
public:
    int Nnco, Nnco0, Nncoold;
    int Npf, Npb, Npo;
    int Nsamp, Nsampold;
    double Ls, Ls0, Lsold;   
    double Lx, Lx0, Lxold;   

    std::vector<int> oxrow, oxsum;
    std::vector<int> pbrow, pbsum;
    std::vector<int> whereisnode;

    std::vector<double> x, y, x0, y0;
    std::vector<double> xo, yo;
    std::vector<double> xb, yb;
    std::vector<double> s;
    std::vector<double> th;
    std::vector<double> c;
    std::vector<double> dU;
    std::vector<double> E;

    ModuleGeometry() : Nnco(0), Nnco0(0), Nncoold(0), Npf(0), Npb(0), Npo(0), Nsamp(0), Nsampold(0),
                       Ls(0.0), Ls0(0.0), Lsold(0.0), Lx(0.0), Lx0(0.0), Lxold(0.0) {}
};