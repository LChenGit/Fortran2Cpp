#include <cstdint> // For std::int32_t

class ppm_module_data_loadbal {
public:
    using ppm_kind_double = double; // Assuming equivalent to Fortran's selected real kind

    ppm_module_data_loadbal() : ppm_loadbal_decomp_cost(0.0),
                                ppm_loadbal_dcn(0),
                                ppm_loadbal_runsum(0.0),
                                ppm_loadbal_old_sar(-1.0) {}

    // Getters
    ppm_kind_double get_decomp_cost() const { return ppm_loadbal_decomp_cost; }
    int get_dcn() const { return ppm_loadbal_dcn; }
    ppm_kind_double get_runsum() const { return ppm_loadbal_runsum; }
    ppm_kind_double get_old_sar() const { return ppm_loadbal_old_sar; }

    // Setters
    void set_decomp_cost(ppm_kind_double value) { ppm_loadbal_decomp_cost = value; }
    void set_dcn(int value) { ppm_loadbal_dcn = value; }
    void set_runsum(ppm_kind_double value) { ppm_loadbal_runsum = value; }
    void set_old_sar(ppm_kind_double value) { ppm_loadbal_old_sar = value; }

private:
    ppm_kind_double ppm_loadbal_decomp_cost;
    std::int32_t ppm_loadbal_dcn;
    ppm_kind_double ppm_loadbal_runsum;
    ppm_kind_double ppm_loadbal_old_sar;
};