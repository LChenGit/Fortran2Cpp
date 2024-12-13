SUBROUTINE loop22_F77(N, x, a, b, c, d)
    INTEGER, INTENT(IN) :: N
    REAL*8, INTENT(INOUT) :: x(N)
    REAL*8, INTENT(IN) :: a(N), b(N), c(N), d(N)
    INTEGER :: i

    DO i = 1, N
        x(i) = x(i) + a(i)*b(i) + c(i)*d(i)
    END DO
END SUBROUTINE loop22_F77

SUBROUTINE loop22_F77Overhead(N, x, a, b, c, d)
    ! This subroutine intentionally left blank
END SUBROUTINE loop22_F77Overhead