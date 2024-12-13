MODULE COMPUTE_STACEY_CM_BACKWARD__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE COMPUTE_STACEY_CM_BACKWARD(inputArray, outputArray, size)
    INTEGER, INTENT(IN) :: size
    REAL, DIMENSION(size), INTENT(IN) :: inputArray
    REAL, DIMENSION(size-1), INTENT(OUT) :: outputArray
    INTEGER :: i
    DO i = 2, size
      outputArray(i-1) = inputArray(i) - inputArray(i-1)
    END DO
  END SUBROUTINE COMPUTE_STACEY_CM_BACKWARD
END MODULE COMPUTE_STACEY_CM_BACKWARD__genmod