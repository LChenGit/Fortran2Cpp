SUBROUTINE floop19_F77(N, y, x, a, b, u, v)
    INTEGER, INTENT(IN) :: N
    REAL*4, INTENT(INOUT) :: y(N), x(N)
    REAL*4, INTENT(IN) :: a(N), b(N), u, v
    INTEGER :: i

    DO i = 1, N
        x(i) = u * a(i)
        y(i) = v * b(i)
    END DO
END SUBROUTINE floop19_F77

SUBROUTINE floop19_F77Overhead(N, y, x, a, b, u, v)
    ! This subroutine intentionally left blank
END SUBROUTINE floop19_F77Overhead