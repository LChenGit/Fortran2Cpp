! DefineModelAK135.f90
MODULE DEFINE_MODEL_AK135__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE DEFINE_MODEL_AK135(USE_EXTERNAL_CRUSTAL_MODEL)
    LOGICAL, INTENT(IN) :: USE_EXTERNAL_CRUSTAL_MODEL
    PRINT *, "USE_EXTERNAL_CRUSTAL_MODEL is", USE_EXTERNAL_CRUSTAL_MODEL
  END SUBROUTINE DEFINE_MODEL_AK135
END MODULE DEFINE_MODEL_AK135__genmod

PROGRAM test_ak135
  USE DEFINE_MODEL_AK135__genmod
  CALL DEFINE_MODEL_AK135(.TRUE.)
  CALL DEFINE_MODEL_AK135(.FALSE.)
END PROGRAM test_ak135