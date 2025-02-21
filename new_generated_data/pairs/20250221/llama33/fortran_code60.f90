PROGRAM test_fortran
    IMPLICIT NONE

    INTEGER, PARAMETER :: nx = 100, ny = 100
    REAL, DIMENSION(nx, ny) :: zf1, wrk
    REAL, DIMENSION(6) :: cf
    INTEGER :: i, j

    ! Initialize arrays
    DO i = 1, nx
        DO j = 1, ny
            wrk(i, j) = REAL(i + j)
        END DO
    END DO

    cf(1) = 1.0
    cf(2) = 2.0
    cf(3) = 3.0
    cf(4) = 4.0
    cf(5) = 5.0
    cf(6) = 6.0

    ! Perform calculation
    DO i = 1, nx
        DO j = 1, ny - 5
            zf1(i, j) = wrk(i, j) * cf(1) + &
                         wrk(i, j + 1) * cf(2) + &
                         wrk(i, j + 2) * cf(3) + &
                         wrk(i, j + 3) * cf(4) + &
                         wrk(i, j + 4) * cf(5) + &
                         wrk(i, j + 5) * cf(6)
        END DO
    END DO

    ! Print results
    WRITE (*,*) "Fortran Results:"
    DO i = 1, nx
        DO j = 1, ny - 5
            WRITE (*,*) zf1(i, j)
        END DO
    END DO

END PROGRAM test_fortran