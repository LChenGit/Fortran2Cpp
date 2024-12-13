MODULE MathOperations
    IMPLICIT NONE
CONTAINS
    FUNCTION add(a, b) RESULT(res)
        INTEGER, INTENT(IN) :: a, b
        INTEGER :: res
        res = a + b
    END FUNCTION add
END MODULE MathOperations

PROGRAM TestAdd
    USE MathOperations
    IMPLICIT NONE
    INTEGER :: result

    ! Test 1: Positive Numbers
    result = add(1, 2)
    IF (result == 3) THEN
        PRINT *, "Test 1 Passed: add(1, 2) = 3"
    ELSE
        PRINT *, "Test 1 Failed: add(1, 2) /= 3"
    END IF

    ! Test 2: Negative Numbers
    result = add(-1, -2)
    IF (result == -3) THEN
        PRINT *, "Test 2 Passed: add(-1, -2) = -3"
    ELSE
        PRINT *, "Test 2 Failed: add(-1, -2) /= -3"
    END IF
END PROGRAM TestAdd