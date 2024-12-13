#ifndef DYNAMIC_INIT_VARIABLES_HPP
#define DYNAMIC_INIT_VARIABLES_HPP

#include <vector>

// Constants (assuming these match the Fortran constants)
const int kbcInitial = 1;

// Example structure definitions (adjust members as needed)
struct hecmwST_local_mesh {
    int n_node;
    int n_dof;
};

struct hecmwST_matrix {
    std::vector<double> B;
};

struct fstr_eigen {
    std::vector<double> mass;
};

struct fstr_solid {
    int VELOCITY_type;
    int ACCELERATION_type;
};

struct fstr_dynamic {
    std::vector<std::vector<double>> ACC;
    std::vector<std::vector<double>> VEL;
    double ray_m;
};

struct fstr_param {
    // Example parameters
};

// Function prototype
void dynamic_init_variables(hecmwST_local_mesh& hecMESH, hecmwST_matrix& hecMAT, fstr_solid& fstrSOLID, fstr_eigen& fstrEIG, fstr_dynamic& fstrDYNAMIC, fstr_param& fstrPARAM);

#endif // DYNAMIC_INIT_VARIABLES_HPP