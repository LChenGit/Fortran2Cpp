#include <vector>
#include <string>

class CharmmMod {
public:
    int chmmntype, chmmbond, chmmang, chmmub, chmmdih, chmmimp, chmmcmap, chmmnonb, chmmnbfix, chmmhbond, charmm_nmax;
    std::vector<std::vector<int>> charmm_btype, charmm_atype, charmm_ubtype, charmm_dtype, charmm_itype, charmm_icmap, charmm_icmap2;
    std::vector<int> charmm_lub, charmm_nprms, charmm_ncmap;
    std::vector<std::vector<int>> charmm_typen, psf_atomtype2;
    std::vector<int> psf_atomtype;
    std::vector<std::vector<int>> psf_charge;

    float viscwat, scldiff; // Assuming real corresponds to float; use double if higher precision is needed.
    std::vector<float> charmm_mass;
    std::vector<std::vector<float>> charmm_bond, charmm_ang, charmm_ub, charmm_dih, charmm_imp, charmm_fcmap, charmm_nonbonded;
    std::vector<float> charmm_cmap;

    std::vector<std::string> charmm_label; // Note: Ensure that the strings do not exceed 7 characters for compatibility.

    bool Qchmmbond, Qchmmang, Qchmmub, Qchmmdih, Qchmmimp, Qchmmcmap, Qchmmnbfix, Qchmmhbond, DCDUnitCell;

    CharmmMod() {}
    ~CharmmMod() {}
};