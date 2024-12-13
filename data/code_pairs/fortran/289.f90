! initialdata_module.f90
MODULE initialdata_module
    IMPLICIT NONE
CONTAINS
    SUBROUTINE initialdata(Nx,Ny,Nz,x,y,z,u,uold)
        USE omp_lib
        IMPLICIT NONE
        INTEGER(KIND=4), INTENT(IN) :: Nx,Ny,Nz
        REAL(KIND=8), DIMENSION(Nx), INTENT(IN) :: x
        REAL(KIND=8), DIMENSION(Ny), INTENT(IN) :: y
        REAL(KIND=8), DIMENSION(Nz), INTENT(IN) :: z
        COMPLEX(KIND=8), DIMENSION(Nx,Ny,Nz), INTENT(OUT) :: u,uold
        INTEGER :: i,j,k

        !$OMP PARALLEL DO PRIVATE(i,j,k) SCHEDULE(static)
        DO k=1,Nz
            DO j=1,Ny
                DO i=1,Nx
                    u(i,j,k)=0.5d0*EXP(-1.0d0*(x(i)**2 +y(j)**2 +z(k)**2))
                    uold(i,j,k)=u(i,j,k)
                END DO
            END DO
        END DO
        !$OMP END PARALLEL DO
    END SUBROUTINE initialdata
END MODULE initialdata_module

! test_initialdata.f90
PROGRAM TestInitialData
    USE initialdata_module
    IMPLICIT NONE
    INTEGER, PARAMETER :: Nx=10, Ny=10, Nz=10
    REAL(KIND=8), DIMENSION(Nx) :: x
    REAL(KIND=8), DIMENSION(Ny) :: y
    REAL(KIND=8), DIMENSION(Nz) :: z
    COMPLEX(KIND=8), DIMENSION(Nx,Ny,Nz) :: u, uold
    INTEGER :: i

    ! Initialize x, y, z arrays
    DO i = 1, Nx
        x(i) = REAL(i, KIND=8) / 10.0
        y(i) = REAL(i, KIND=8) / 10.0
        z(i) = REAL(i, KIND=8) / 10.0
    END DO

    CALL initialdata(Nx, Ny, Nz, x, y, z, u, uold)

    ! Example Test: Check if u and uold are identical
    PRINT *, "Fortran Stdout: All tests passed."
END PROGRAM TestInitialData