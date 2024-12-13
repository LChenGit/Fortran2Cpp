MODULE NumberStringUtils
  IMPLICIT NONE
CONTAINS
  FUNCTION makenumberstring(x) RESULT(res)
    REAL, INTENT(IN) :: x
    CHARACTER(len=20) :: res
    INTEGER :: xx
    
    xx = NINT(x**2)  ! Square x and convert to nearest integer
    WRITE(res, '(I20)') xx  ! Convert integer to string
  END FUNCTION makenumberstring
END MODULE NumberStringUtils

PROGRAM TestMakeNumberString
  USE NumberStringUtils
  IMPLICIT NONE
  REAL :: inputNumber
  CHARACTER(len=20) :: outputString

  ! Test the makenumberstring function
  inputNumber = 4.0
  outputString = makenumberstring(inputNumber)
  PRINT *, 'The square of ', inputNumber, ' as a string is: ', TRIM(outputString)

END PROGRAM TestMakeNumberString