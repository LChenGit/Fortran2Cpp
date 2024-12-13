MODULE constants
  USE iso_fortran_env, ONLY: REAL64
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp = SELECTED_REAL_KIND(15, 307)
  REAL(KIND=dp), PARAMETER :: pi = 3.141592653589793238462643383279502884197_dp, &
                              eps0 = 8.8541878176E-12_dp, &
                              mu0 = 4.0_dp * pi * 1E-7_dp, &
                              c0 = 2.997924580003E8_dp, &
                              eta0 = 3.767303134622E2_dp, &
                              radtodeg = 180.0_dp / pi, &
                              degtorad = pi / 180.0_dp
  INTEGER, PARAMETER :: prd_none = 1, prd_2d = 2
END MODULE constants