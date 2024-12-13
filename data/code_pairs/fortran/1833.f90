MODULE loop10Module
  IMPLICIT NONE
CONTAINS
  SUBROUTINE loop10_F90(N, x, a, b, c, u)
    INTEGER, INTENT(IN) :: N
    REAL(KIND=8), INTENT(INOUT) :: x(N)
    REAL(KIND=8), INTENT(IN) :: a(N), b(N), c(N), u
    INTEGER :: i

    DO i = 1, N
      x(i) = u + a(i) + b(i) + c(i)
    END DO
  END SUBROUTINE loop10_F90

  SUBROUTINE loop10_F90Overhead(N, x, a, b, c, u)
    INTEGER, INTENT(IN) :: N
    REAL(KIND=8), INTENT(INOUT) :: x(N)
    REAL(KIND=8), INTENT(IN) :: a(N), b(N), c(N), u
    ! This subroutine intentionally left blank
  END SUBROUTINE loop10_F90Overhead
END MODULE loop10Module