SUBROUTINE avevar(data, n, ave, var)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: n
    REAL*8, INTENT(IN) :: data(n)
    REAL*8, INTENT(OUT) :: ave, var
    INTEGER :: j
    REAL*8 :: s, ep
    ave = 0.0
    DO j = 1, n
        ave = ave + data(j)
    END DO
    ave = ave / n
    var = 0.0
    ep = 0.0
    DO j = 1, n
        s = data(j) - ave
        ep = ep + s
        var = var + s * s
    END DO
    var = (var - ep ** 2 / n) / (n - 1)
END SUBROUTINE avevar

SUBROUTINE avevar2(data, data2, n, ave, var)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: n
    REAL*8, INTENT(IN) :: data(n)
    REAL*8, INTENT(OUT) :: data2(n), ave, var
    INTEGER :: j, n2
    REAL*8 :: s, ep, std
    ave = SUM(data) / n
    var = 0.0
    ep = 0.0
    DO j = 1, n
        s = data(j) - ave
        ep = ep + s
        var = var + s * s
    END DO
    var = (var - ep ** 2 / n) / (n - 1)
    std = SQRT(var)
    n2 = 0
    DO j = 1, n
        IF (ABS(data(j) - ave) < 3.0 * std) THEN
            n2 = n2 + 1
            data2(n2) = data(j)
        END IF
    END DO
    IF (n2 > 0) THEN
       ave = SUM(data2(1:n2)) / n2
       var = 0.0
       ep = 0.0
       DO j = 1, n2
           s = data2(j) - ave
           ep = ep + s
           var = var + s * s
       END DO
       var = (var - ep ** 2 / n2) / (n2 - 1)
    END IF
END SUBROUTINE avevar2