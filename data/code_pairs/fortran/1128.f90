MODULE ppm_module_fmm_pretraverse

CONTAINS

  SUBROUTINE ppm_fmm_pretraverse_s()
    PRINT *, 'Single precision calculation'
  END SUBROUTINE ppm_fmm_pretraverse_s

  SUBROUTINE ppm_fmm_pretraverse_d()
    PRINT *, 'Double precision calculation'
  END SUBROUTINE ppm_fmm_pretraverse_d

END MODULE ppm_module_fmm_pretraverse

PROGRAM test_ppm_module_fmm_pretraverse
  USE ppm_module_fmm_pretraverse
  IMPLICIT NONE

  CALL ppm_fmm_pretraverse_s()
  CALL ppm_fmm_pretraverse_d()

END PROGRAM test_ppm_module_fmm_pretraverse