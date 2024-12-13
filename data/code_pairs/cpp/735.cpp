#ifndef M_BOUNDARY_PARAMS_SPH_MHD_H
#define M_BOUNDARY_PARAMS_SPH_MHD_H

struct sph_boundary_type {
    int dummy; // Placeholder member variable
};

class MBoundaryParamsSphMHD {
public:
    sph_boundary_type sph_bc_U;
    sph_boundary_type sph_bc_B;
    sph_boundary_type sph_bc_T;
    sph_boundary_type sph_bc_C;

    double* vp_ICB_bc = nullptr;
    double* vt_ICB_bc = nullptr;
    double* vp_CMB_bc = nullptr;
    double* vt_CMB_bc = nullptr;

    void allocate_vsp_bc_array(int jmax);
    void deallocate_vsp_bc_array();

    ~MBoundaryParamsSphMHD();
};

#endif // M_BOUNDARY_PARAMS_SPH_MHD_H