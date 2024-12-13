SUBROUTINE floop12_F90(N, y, x, a, b, c, d, u)
  INTEGER, INTENT(IN) :: N
  REAL*4, INTENT(INOUT) :: y(N), x(N)
  REAL*4, INTENT(IN) :: a(N), b(N), c(N), d(N), u
  INTEGER :: i

  DO i = 1, N
     y(i) = u + a(i)
     x(i) = a(i) + b(i) + c(i) + d(i)
  END DO
END SUBROUTINE floop12_F90

SUBROUTINE floop12_F90Overhead(N, y, x, a, b, c, d, u)
  ! This subroutine intentionally left blank
END SUBROUTINE floop12_F90Overhead

PROGRAM TestFloops
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 4
  REAL*4 :: y(N), x(N), a(N), b(N), c(N), d(N), u
  INTEGER :: i

  a = (/1.0, 2.0, 3.0, 4.0/)
  b = (/2.0, 3.0, 4.0, 5.0/)
  c = (/3.0, 4.0, 5.0, 6.0/)
  d = (/4.0, 5.0, 6.0, 7.0/)
  u = 1.5

  CALL floop12_F90(N, y, x, a, b, c, d, u)

  PRINT *, "Results for y:"
  DO i = 1, N
     PRINT *, y(i)
  END DO

  PRINT *, "Results for x:"
  DO i = 1, N
     PRINT *, x(i)
  END DO
END PROGRAM TestFloops