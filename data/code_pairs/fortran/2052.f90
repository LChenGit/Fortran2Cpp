MODULE JULIAN_DAY__genmod
  IMPLICIT NONE
CONTAINS
  FUNCTION JULIAN_DAY(YR, MO, DA)
    INTEGER, INTENT(IN) :: YR, MO, DA
    INTEGER :: JULIAN_DAY

    INTEGER :: A, Y, M
    A = (14 - MO) / 12
    Y = YR + 4800 - A
    M = MO + 12 * A - 3
    JULIAN_DAY = DA + (153 * M + 2) / 5 + 365 * Y + Y / 4 - Y / 100 + Y / 400 - 32045
  END FUNCTION JULIAN_DAY
END MODULE JULIAN_DAY__genmod

PROGRAM test_julian_day
  USE JULIAN_DAY__genmod
  IMPLICIT NONE
  
  INTEGER :: JD, YEAR, MONTH, DAY
  
  YEAR = 2000; MONTH = 1; DAY = 1
  JD = JULIAN_DAY(YEAR, MONTH, DAY)
  PRINT *, "Julian Day for ", YEAR, "/", MONTH, "/", DAY, " is ", JD
  
  ! Ensure to add more test cases as necessary for comprehensive validation
END PROGRAM test_julian_day