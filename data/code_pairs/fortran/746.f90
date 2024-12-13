MODULE SquareMod
    IMPLICIT NONE
CONTAINS
    ! This function returns the square of a number
    FUNCTION square(x) RESULT(res)
        INTEGER, INTENT(IN) :: x
        INTEGER :: res
        res = x * x
    END FUNCTION square
END MODULE SquareMod