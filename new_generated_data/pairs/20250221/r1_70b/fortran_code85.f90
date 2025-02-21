PROGRAM MyMainProgram
    IMPLICIT NONE

    ! Declare variables
    REAL :: x, y, result

    x = 5.0
    y = 3.0

    ! Call an internal subroutine to perform some operation
    CALL AddNumbers(x, y, result)

    ! Print the result with formatted output
    PRINT *, "The sum of ", x, " and ", y, " is: ", result

    ! Simple unit test
    IF (result /= 8.0) THEN
        PRINT *, "Unit test failed: Incorrect sum."
        STOP 1
    END IF

CONTAINS

    SUBROUTINE AddNumbers(a, b, c)
        IMPLICIT NONE

        REAL, INTENT(IN) :: a, b
        REAL, INTENT(OUT) :: c

        c = a + b
    END SUBROUTINE AddNumbers
END PROGRAM MyMainProgram