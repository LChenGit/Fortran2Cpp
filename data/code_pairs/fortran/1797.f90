MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute_column(nz, q, t)
    INTEGER, INTENT(IN) :: nz
    REAL, DIMENSION(nz), INTENT(INOUT) :: q, t
    INTEGER :: i
    DO i = 1, nz
      q(i) = q(i) + 1.0
      t(i) = t(i) + 2.0
    END DO
  END SUBROUTINE compute_column
END MODULE mo_column