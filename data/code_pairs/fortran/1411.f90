MODULE GRVT__genmod
  IMPLICIT NONE
  CONTAINS

  SUBROUTINE GRVT(ISHP, NDS, R, GWT, GCONST, GRAVDIR, DENSITY, FINTE)
    INTEGER, INTENT(IN) :: NDS, ISHP
    REAL(KIND=8), INTENT(IN) :: R(ISHP)
    REAL(KIND=8), INTENT(IN) :: GWT, GCONST, DENSITY
    INTEGER, INTENT(IN) :: GRAVDIR
    REAL(KIND=8), INTENT(INOUT) :: FINTE(ISHP*NDS, 1)

    INTEGER :: i, j
    DO i = 1, ISHP
      DO j = 1, NDS
        FINTE((i-1)*NDS+j, 1) = GWT * GCONST * DENSITY * R(i) * GRAVDIR
      END DO
    END DO
  END SUBROUTINE GRVT

END MODULE GRVT__genmod