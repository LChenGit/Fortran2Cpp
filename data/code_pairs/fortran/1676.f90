! Main program to test the SECOND function
PROGRAM testSecond
  IMPLICIT NONE
  REAL :: result

  result = SECOND()
  IF (result == 0.0E+0) THEN
    PRINT *, 'Test Passed!'
  ELSE
    PRINT *, 'Test Failed!'
  END IF
END PROGRAM testSecond

! Function SECOND returns a constant value
REAL FUNCTION SECOND()
    SECOND = 0.0E+0
END FUNCTION SECOND