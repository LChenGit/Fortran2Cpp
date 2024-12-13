MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute_column(nz, q, t, nproma)
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(nproma, nz), q(nproma, nz)
    INTEGER :: k, proma

    DO k = 1, nz
      DO proma = 1, nproma
        IF (t(proma, k) > 0.0) THEN
          q(proma, k) = q(proma, k) / t(proma, k)
        END IF
      END DO
    END DO
  END SUBROUTINE compute_column
END MODULE mo_column