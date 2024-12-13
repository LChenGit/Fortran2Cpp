MODULE mo_column
  IMPLICIT NONE
  PUBLIC :: ty_column

  TYPE :: ty_column
  CONTAINS
    PROCEDURE :: compute_column
  END TYPE ty_column

CONTAINS

  SUBROUTINE compute_column(this, nz, q, t, nproma)
    CLASS(ty_column), INTENT(INOUT) :: this
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(:,:), q(:,:)

    INTEGER :: i, j
    DO i = 1, nz
      DO j = 1, nproma
        q(i, j) = q(i, j) * 2.0
        t(i, j) = t(i, j) + 10.0
      END DO
    END DO
  END SUBROUTINE compute_column

END MODULE mo_column