MODULE CONVCHECK__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE CONVCHECK(INC, ABSRES, ABSDISP)
    INTEGER, INTENT(IN) :: INC
    REAL(KIND=8), INTENT(OUT) :: ABSRES, ABSDISP

    ABSRES = INC * 2.0
    ABSDISP = INC + 10.0
  END SUBROUTINE CONVCHECK
END MODULE CONVCHECK__genmod