MODULE ppm_module_data_loadbal
    IMPLICIT NONE

    INTEGER, PARAMETER :: ppm_kind_double = SELECTED_REAL_KIND(p=15, r=307)
    REAL(ppm_kind_double) :: ppm_loadbal_decomp_cost = 0.0_ppm_kind_double
    INTEGER               :: ppm_loadbal_dcn = 0
    REAL(ppm_kind_double) :: ppm_loadbal_runsum = 0.0_ppm_kind_double
    REAL(ppm_kind_double) :: ppm_loadbal_old_sar = -1.0_ppm_kind_double

END MODULE ppm_module_data_loadbal