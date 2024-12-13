#include <iostream>
#include <vector>

void allocate_memory(int Nx, int nvars, std::vector<double>& x, std::vector<std::vector<double>>& u,
                     std::vector<std::vector<double>>& u_p, std::vector<std::vector<double>>& rhs_u,
                     std::vector<std::vector<double>>& du, std::vector<double>& Mom) {
    x.resize(Nx + 1);
    u.resize(nvars, std::vector<double>(Nx + 1));
    u_p.resize(nvars, std::vector<double>(Nx + 1));
    rhs_u.resize(nvars, std::vector<double>(Nx + 1));
    du.resize(nvars, std::vector<double>(Nx + 1));
    Mom.resize(Nx + 1);
}

int main() {
    int Nx = 10;
    int nvars = 5;
    std::vector<double> x, Mom;
    std::vector<std::vector<double>> u, u_p, rhs_u, du;

    allocate_memory(Nx, nvars, x, u, u_p, rhs_u, du, Mom);

    std::cout << "C++ test passed." << std::endl;
    return 0;
}