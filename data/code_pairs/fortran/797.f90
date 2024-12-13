! CROSS subroutine definition
SUBROUTINE CROSS (X, XX, Y, YY, YYY, XXX)
    IMPLICIT NONE
    REAL :: X, XX, Y, YY, YYY, XXX

    YYY = Y - YY + XX - X
    XXX = Y * (XX - X) + X * (Y - YY)

    IF (ABS(YYY) >= 1.E-6) THEN
        YYY = XXX / YYY
        XXX = XX - X
        IF (ABS(XXX) >= 1.E-6) THEN
            XXX = (YYY - X) / XXX
        ELSE
            XXX = Y - YY
            IF (ABS(XXX) >= 1.E-6) THEN
                XXX = (Y - YYY) / XXX
            END IF
        END IF
    END IF
END SUBROUTINE CROSS

! Test Program
PROGRAM TestCross
    IMPLICIT NONE
    REAL :: X, XX, Y, YY, YYY, XXX

    ! Test case 1
    X = 1.0
    XX = 2.0
    Y = 3.0
    YY = 4.0
    CALL CROSS(X, XX, Y, YY, YYY, XXX)
    PRINT *, "Test case 1: YYY =", YYY, "XXX =", XXX

END PROGRAM TestCross