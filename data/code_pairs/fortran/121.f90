SUBROUTINE ST_ALNM(chrstr, ityp, iret)
    CHARACTER*(*) chrstr
    INTEGER ityp, iret
    iret = 0
    ityp = 0
    IF ((chrstr .GE. '0') .AND. (chrstr .LE. '9')) ityp = 1
    IF ((chrstr .GE. 'a') .AND. (chrstr .LE. 'z')) ityp = 2
    IF ((chrstr .GE. 'A') .AND. (chrstr .LE. 'Z')) ityp = 2
    RETURN
END SUBROUTINE ST_ALNM

PROGRAM testST_ALNM
    IMPLICIT NONE
    CHARACTER*1 testChar
    INTEGER ityp, iret

    testChar = '5'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 1) PRINT *, 'Test 1 passed.'

    testChar = 'a'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 2) PRINT *, 'Test 2 passed.'

    testChar = 'Z'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 2) PRINT *, 'Test 3 passed.'

    testChar = '@'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 0) PRINT *, 'Test 4 passed.'
END PROGRAM testST_ALNM