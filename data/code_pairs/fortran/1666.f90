MODULE CONTROLRET
  IMPLICIT NONE
CONTAINS
  FUNCTION increment(n)
    INTEGER, INTENT(IN) :: n
    INTEGER :: increment
    increment = n + 1
  END FUNCTION increment
END MODULE CONTROLRET