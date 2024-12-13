! NORM_ROT__genmod.f90
MODULE NORM_ROT__genmod
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE NORM_ROT(THN, PHN, TH, PH, TH_NEW, PH_NEW)
      REAL(KIND=8), INTENT(IN) :: THN, PHN, TH, PH
      REAL(KIND=8), INTENT(OUT) :: TH_NEW, PH_NEW

      ! For demonstration, simply copy inputs to outputs.
      TH_NEW = TH
      PH_NEW = PH
    END SUBROUTINE NORM_ROT
END MODULE NORM_ROT__genmod

! Test program
PROGRAM test_norm_rot
  USE NORM_ROT__genmod
  REAL(KIND=8) :: THN, PHN, TH, PH, TH_NEW, PH_NEW

  THN = 1.0
  PHN = 2.0
  TH = 3.0
  PH = 4.0

  CALL NORM_ROT(THN, PHN, TH, PH, TH_NEW, PH_NEW)

  IF (TH_NEW == TH .AND. PH_NEW == PH) THEN
    PRINT *, "Test Passed."
  ELSE
    PRINT *, "Test Failed."
  END IF
END PROGRAM test_norm_rot