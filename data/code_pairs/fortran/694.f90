MODULE initialdata_mod
    IMPLICIT NONE
CONTAINS
    SUBROUTINE initialdata(Nx, Ny, x, y, u, uold)
        INTEGER, INTENT(IN) :: Nx, Ny
        REAL(KIND=8), DIMENSION(Nx), INTENT(IN) :: x
        REAL(KIND=8), DIMENSION(Ny), INTENT(IN) :: y
        COMPLEX(KIND=8), DIMENSION(Nx, Ny), INTENT(OUT) :: u, uold
        INTEGER :: i, j

        DO j = 1, Ny
            DO i = 1, Nx
                u(i,j) = 0.5d0 * EXP(-1.0d0 * (x(i)**2 + y(j)**2)) * SIN(10.0d0 * x(i) + 12.0d0 * y(j))
                uold(i,j) = u(i,j)
            END DO
        END DO
    END SUBROUTINE initialdata
END MODULE initialdata_mod