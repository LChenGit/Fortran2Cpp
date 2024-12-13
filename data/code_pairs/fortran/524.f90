MODULE powell_mod
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp_kind = KIND(1.0D0)
CONTAINS
  SUBROUTINE trsapp(n, d, crvmin)
    INTEGER, INTENT(IN) :: n
    REAL(KIND=dp_kind), INTENT(IN) :: d(n)
    REAL(KIND=dp_kind), INTENT(OUT) :: crvmin
    INTEGER :: i
    crvmin = 0.0_dp_kind
    DO i = 1, n
       crvmin = crvmin + d(i)**2
    END DO
  END SUBROUTINE trsapp
END MODULE powell_mod