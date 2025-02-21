PROGRAM TEST_RV_INITIALISE
    ! Declare variables
    INTEGER :: I
    CHARACTER(LEN=1) :: EXPECTED_CHAR
    COMMON /CHARBLOCK/ CHARVAL
    CHARACTER(LEN=1), DIMENSION(26) :: CHARVAL

    CALL RV_INITIALIZE()

    DO I = 1, 26
        ! Calculate the expected character using ACHAR with proper index
        EXPECTED_CHAR = ACHAR(I + 64)
        IF (CHARVAL(I) .NE. EXPECTED_CHAR) THEN
            WRITE (*,*) "Test failed at index ", I
            WRITE (*,*) "Expected: '", EXPECTED_CHAR, "'"
            WRITE (*,*) "Received: '", CHARVAL(I), "'"
            STOP 1
        ENDIF
    ENDDO

    WRITE (*,*) "All test cases passed."

END PROGRAM TEST_RV_INITIALISE

SUBROUTINE RV_INITIALIZE()
    INTEGER :: I
    COMMON /CHARBLOCK/ CHARVAL
    CHARACTER(LEN=1), DIMENSION(26) :: CHARVAL

    DO I = 1, 26
        CHARVAL(I) = ACHAR(I + 64)
    ENDDO

END SUBROUTINE RV_INITIALIZE