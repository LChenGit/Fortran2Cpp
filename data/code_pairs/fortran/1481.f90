MODULE valout_mod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE VALOUT(STRING, IBEFOR, WIDTH, VALUE)
    CHARACTER(LEN=*), INTENT(INOUT) :: STRING
    INTEGER, INTENT(INOUT) :: IBEFOR
    INTEGER, INTENT(IN) :: WIDTH
    INTEGER, INTENT(IN) :: VALUE
    CHARACTER(LEN=:), ALLOCATABLE :: formattedStr
    INTEGER :: neededLength

    WRITE(formattedStr, '(I0)') VALUE
    STRING = TRIM(ADJUSTL(formattedStr))
    IBEFOR = LEN_TRIM(formattedStr)
  END SUBROUTINE VALOUT
END MODULE valout_mod

PROGRAM test_valout
  USE valout_mod
  IMPLICIT NONE
  CHARACTER(LEN=100) :: testString
  INTEGER :: testIbefor, width, value

  ! Test 1
  testString = ""
  testIbefor = 0
  width = 5
  value = 123
  CALL VALOUT(testString, testIbefor, width, value)
  PRINT *, "Test 1: ", testString, testIbefor

  ! Test 2
  testString = ""
  testIbefor = 0
  width = 5
  value = -45
  CALL VALOUT(testString, testIbefor, width, value)
  PRINT *, "Test 2: ", testString, testIbefor
END PROGRAM test_valout