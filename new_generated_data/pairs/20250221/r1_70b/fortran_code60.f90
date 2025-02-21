PROGRAM FILTH2MPPD6_MPI_TEST

    USE ISO_Fortran_env
    IMPLICIT NONE

    INTEGER, PARAMETER :: dp = REAL64
    INTEGER :: kmax, ijmax, nx
    INTEGER :: i, j, k
    REAL(dp), ALLOCATABLE :: cf(:)
    REAL(dp), ALLOCATABLE :: z1(:, :)
    REAL(dp), ALLOCATABLE :: zf1(:, :)
    REAL(dp), ALLOCATABLE :: wrk(:, :)

CONTAINS

    LOGICAL FUNCTION has_close_elements(a, expected, tol, n)
        REAL(dp), INTENT(IN) :: a(:)
        REAL(dp), INTENT(IN) :: expected
        REAL(dp), INTENT(IN) :: tol
        INTEGER, INTENT(IN) :: n
        INTEGER :: i

        has_close_elements = .TRUE.
        DO i = 1, n
            IF (ABS(a(i) - expected) > tol) THEN
                has_close_elements = .FALSE.
                RETURN
            END IF
        END DO
    END FUNCTION has_close_elements

END PROGRAM FILTH2MPPD6_MPI_TEST