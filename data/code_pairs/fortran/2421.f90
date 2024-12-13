! SLAMRG.f90
SUBROUTINE SLAMRG(N1, N2, A, STRD1, STRD2, INDEX)
    INTEGER :: N1, N2, STRD1, STRD2
    INTEGER, DIMENSION(*) :: INDEX
    REAL, DIMENSION(*) :: A
    INTEGER :: I, IND1, IND2, N1SV, N2SV

    N1SV = N1
    N2SV = N2
    IF (STRD1 > 0) THEN
        IND1 = 1
    ELSE
        IND1 = N1
    END IF
    IF (STRD2 > 0) THEN
        IND2 = 1 + N1
    ELSE
        IND2 = N1 + N2
    END IF
    I = 1
    DO WHILE (N1SV > 0 AND N2SV > 0)
        IF (A(IND1) <= A(IND2)) THEN
            INDEX(I) = IND1
            I = I + 1
            IND1 = IND1 + STRD1
            N1SV = N1SV - 1
        ELSE
            INDEX(I) = IND2
            I = I + 1
            IND2 = IND2 + STRD2
            N2SV = N2SV - 1
        END IF
    END DO
    IF (N1SV == 0) THEN
        DO WHILE (N2SV > 0)
            INDEX(I) = IND2
            I = I + 1
            IND2 = IND2 + STRD2
            N2SV = N2SV - 1
        END DO
    ELSE
        DO WHILE (N1SV > 0)
            INDEX(I) = IND1
            I = I + 1
            IND1 = IND1 + STRD1
            N1SV = N1SV - 1
        END DO
    END IF
END SUBROUTINE SLAMRG

PROGRAM test_slamrg
    IMPLICIT NONE
    INTEGER, PARAMETER :: n1=3, n2=3, strd1=1, strd2=1
    REAL, DIMENSION(n1+n2) :: a = (/ 1.0, 3.0, 5.0, 2.0, 4.0, 6.0 /)
    INTEGER, DIMENSION(n1+n2) :: index
    INTEGER :: i

    CALL SLAMRG(n1, n2, a, strd1, strd2, index)

    PRINT *, 'Index:'
    DO i = 1, n1 + n2
        PRINT *, index(i)
    END DO
END PROGRAM test_slamrg