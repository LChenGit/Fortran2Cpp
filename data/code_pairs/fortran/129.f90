SUBROUTINE loop12_F77(N, y, a, x, b, c, d, u)
    INTEGER, INTENT(IN) :: N
    REAL(8), INTENT(INOUT) :: y(N), x(N)
    REAL(8), INTENT(IN) :: a(N), b(N), c(N), d(N), u
    INTEGER :: i

    DO i = 1, N
        y(i) = u + a(i)
        x(i) = a(i) + b(i) + c(i) + d(i)
    END DO
END SUBROUTINE loop12_F77

SUBROUTINE loop12_F77Overhead(N, y, a, x, b, c, d, u)
    INTEGER, INTENT(IN) :: N
    REAL(8), INTENT(INOUT) :: y(N), x(N)
    REAL(8), INTENT(IN) :: a(N), b(N), c(N), d(N), u
    ! This subroutine is intentionally left empty to match the original example
END SUBROUTINE loop12_F77Overhead