MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute_column(nz, q, t, nproma)
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(nz, nproma)
    REAL, INTENT(INOUT) :: q(nz, nproma)
    INTEGER :: i, j

    DO i = 1, nz
       DO j = 1, nproma
          t(i, j) = t(i, j) + 1.0
          q(i, j) = q(i, j) + 1.0
       END DO
    END DO
  END SUBROUTINE compute_column
END MODULE mo_column