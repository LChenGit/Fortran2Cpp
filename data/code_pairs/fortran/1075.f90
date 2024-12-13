PROGRAM test_abstraction1
  IMPLICIT NONE
  REAL :: q(1:20, 1:60)
  REAL :: t(1:20, 1:60)
  INTEGER :: nproma, nz, p

  nproma = 20
  nz = 60
  DO p = 1, nproma
    q(p, 1) = 0.0
    t(p, 1) = 0.0
  END DO

  CALL compute_column(4, nz, q, t, nproma)

  PRINT *, 'Sum of q:', SUM(q)
  PRINT *, 'Sum of t:', SUM(t)
END PROGRAM test_abstraction1

SUBROUTINE compute_column(arg1, nz, q, t, nproma)
  INTEGER, INTENT(IN) :: arg1, nz, nproma
  REAL, INTENT(INOUT) :: q(nz, nproma), t(nz, nproma)
  INTEGER :: i, j
  
  DO i = 1, nproma
    DO j = 1, nz
      q(j, i) = 1.0
      t(j, i) = 2.0
    END DO
  END DO
END SUBROUTINE compute_column