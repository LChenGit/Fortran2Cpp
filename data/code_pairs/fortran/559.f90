SUBROUTINE loop4_F77(niters, N, x, a, b)
  INTEGER, INTENT(IN) :: niters, N
  REAL*8, INTENT(INOUT) :: x(N)
  REAL*8, INTENT(IN) :: a(N), b(N)
  INTEGER :: i, iter

  DO iter = 1, niters
    DO i = 1, N
      x(i) = a(i) + b(i)
    END DO
  END DO
END SUBROUTINE loop4_F77