MODULE BOOLARRAY
  IMPLICIT NONE 
  PRIVATE
  PUBLIC :: SUBR_BOOLARRAY_IN
CONTAINS
  SUBROUTINE SUBR_BOOLARRAY_IN(ARRAY_IN, N_IN)
    INTEGER, INTENT(IN) :: N_IN
    LOGICAL, INTENT(IN) :: ARRAY_IN(:)
    INTEGER :: I
    PRINT *, 'SUBR_BOOLARRAY_IN'
    DO I = 1, N_IN
      PRINT *, I, ARRAY_IN(I)
    END DO
  END SUBROUTINE SUBR_BOOLARRAY_IN
END MODULE BOOLARRAY