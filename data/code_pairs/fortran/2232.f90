SUBROUTINE iau_PAS(AL, AP, BL, BP, THETA)
    IMPLICIT NONE
    DOUBLE PRECISION, INTENT(IN) :: AL, AP, BL, BP
    DOUBLE PRECISION, INTENT(OUT) :: THETA
    DOUBLE PRECISION :: DL, X, Y

    DL = BL - AL
    Y = SIN(DL) * COS(BP)
    X = SIN(BP) * COS(AP) - COS(BP) * SIN(AP) * COS(DL)

    IF (X /= 0D0 .OR. Y /= 0D0) THEN
        THETA = ATAN2(Y, X)
    ELSE
        THETA = 0D0
    END IF
END SUBROUTINE iau_PAS