PROGRAM TEST
    IMPLICIT NONE

    INTEGER :: test1In
    INTEGER :: test1Out

    test1In = 255
    test1Out = BKKCRYPT(test1In)

    IF (test1In == test1Out) THEN
        WRITE (*, *) "TEST PASSED"
    ELSE
        WRITE (*, *) "TEST FAILED"
    END IF

    ! Unit tests
    IF (BKKCRYPT(0) /= 0) THEN
        WRITE (*, *) "Test case 1 failed: assertion failed"
        STOP 1
    END IF

    IF (BKKCRYPT(10) /= 10) THEN
        WRITE (*, *) "Test case 2 failed: assertion failed"
        STOP 1
    END IF

    IF (BKKCRYPT(-5) /= -5) THEN
        WRITE (*, *) "Test case 3 failed: assertion failed"
        STOP 1
    END IF

    IF (BKKCRYPT(255) /= 255) THEN
        WRITE (*, *) "Test case 4 failed: assertion failed"
        STOP 1
    END IF

    IF (BKKCRYPT(-256) /= -256) THEN
        WRITE (*, *) "Test case 5 failed: assertion failed"
        STOP 1
    END IF

    WRITE (*, *) "All unit tests passed."

CONTAINS

    INTEGER FUNCTION BKKCRYPT(x)
        IMPLICIT NONE
        INTEGER :: x
        BKKCRYPT = x
    END FUNCTION BKKCRYPT

END PROGRAM TEST