PROGRAM TestXYZMOD
    IMPLICIT NONE

    INTEGER, PARAMETER :: NUMNP = 5
    INTEGER, PARAMETER :: NDIM = 3
    REAL :: XOLD(NUMNP), YOLD(NUMNP), ZOLD(NUMNP)
    REAL :: XNEW(NUMNP), YNEW(NUMNP), ZNEW(NUMNP)
    INTEGER :: I

    ! Initialize old coordinates
    DO I = 1, NUMNP
        XOLD(I) = I
        YOLD(I) = I
        ZOLD(I) = I
    END DO

    ! Call the subroutine
    CALL XYZMOD(NUMNP, NDIM, XOLD, YOLD, ZOLD, XNEW, YNEW, ZNEW)

    ! Output the results
    PRINT *, 'XNEW = ', XNEW
    PRINT *, 'YNEW = ', YNEW
    PRINT *, 'ZNEW = ', ZNEW

END PROGRAM TestXYZMOD

SUBROUTINE XYZMOD(NUMNP, NDIM, XOLD, YOLD, ZOLD, XNEW, YNEW, ZNEW)
    INTEGER :: NUMNP, NDIM
    REAL :: XOLD(*), YOLD(*), ZOLD(*)
    REAL :: XNEW(*), YNEW(*), ZNEW(*)
    INTEGER :: I

    DO I = 1, NUMNP
        XNEW(I) = XOLD(I)
        YNEW(I) = YOLD(I)
        IF (NDIM == 3) THEN
            ZNEW(I) = ZOLD(I)
        END IF
    END DO

END SUBROUTINE XYZMOD