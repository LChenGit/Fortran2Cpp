MODULE coe_I
    IMPLICIT NONE
    CONTAINS
    SUBROUTINE coe(X2, Y2, Z2, NORBI, NORBJ, C, R) 
        IMPLICIT NONE
        DOUBLE PRECISION, INTENT(IN) :: X2, Y2, Z2
        INTEGER, INTENT(IN) :: NORBI, NORBJ
        DOUBLE PRECISION, DIMENSION(75), INTENT(OUT) :: C
        DOUBLE PRECISION, INTENT(OUT) :: R
        INTEGER :: i

        R = X2 + Y2 + Z2
        DO i = 1, 75, 2
            C(i) = NORBI
            IF (i + 1 <= 75) THEN
                C(i + 1) = NORBJ
            END IF
        END DO
    END SUBROUTINE coe
END MODULE coe_I