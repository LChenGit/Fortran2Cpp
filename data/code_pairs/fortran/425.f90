MODULE FloopsMod
    IMPLICIT NONE
CONTAINS
    SUBROUTINE floop23_F90(N, x, a, b, c, d, y)
        INTEGER, INTENT(IN) :: N
        REAL*4, INTENT(INOUT) :: x(N), a(N), b(N), c(N), d(N), y(N)
        INTEGER :: i

        DO i = 1, N
            x(i) = a(i) * b(i) + c(i) * d(i)
            y(i) = b(i) + d(i)
        END DO
    END SUBROUTINE floop23_F90
END MODULE FloopsMod