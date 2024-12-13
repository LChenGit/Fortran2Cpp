! Define the subroutine NEWPR
SUBROUTINE NEWPR (Nz, PzNew, PZOLD, CORR, SCALAR)
    IMPLICIT NONE
    INTEGER Nz
    DOUBLE PRECISION PzNew(Nz), PZOLD(Nz), CORR(Nz), SCALAR
    INTEGER I

    DO I = 1, Nz
        PzNew(I) = PZOLD(I) + SCALAR * CORR(I)
    ENDDO
END SUBROUTINE NEWPR

! Test program for NEWPR
PROGRAM testNEWPR
    INTEGER, PARAMETER :: maxz=5
    DOUBLE PRECISION PzNew(maxz), PZOLD(maxz), CORR(maxz)
    DOUBLE PRECISION SCALAR
    INTEGER i

    ! Define test values
    DATA PZOLD /1.0, 2.0, 3.0, 4.0, 5.0/
    DATA CORR /0.1, 0.2, 0.3, 0.4, 0.5/
    SCALAR = 2.0

    ! Call the subroutine
    CALL NEWPR(maxz, PzNew, PZOLD, CORR, SCALAR)

    ! Check the results
    PRINT *, 'PzNew:'
    DO i = 1, maxz
        PRINT *, PzNew(i)
    ENDDO
END PROGRAM testNEWPR