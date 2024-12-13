MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute_column(nz, q, t)
    IMPLICIT NONE
    INTEGER, INTENT(IN)   :: nz
    REAL, INTENT(INOUT)   :: t(:)
    REAL, INTENT(INOUT)   :: q(:)
    INTEGER :: k
    REAL :: c
    
    c = 5.345
    c = c * c
    DO k = 2, nz
      t(k) = c * k
      q(k) = q(k - 1) + t(k) * c
    END DO
    
    IF (q(nz) > 0.0) THEN
      q(nz) = q(nz) * c
    END IF
  END SUBROUTINE compute_column
END MODULE mo_column