MODULE BCAST_ALL_CH_ARRAY__genmod
  IMPLICIT NONE
  INTERFACE 
    SUBROUTINE BCAST_ALL_CH_ARRAY(BUFFER, NDIM, COUNTVAL, MESSAGE)
      INTEGER, INTENT(IN) :: NDIM, COUNTVAL
      CHARACTER(LEN=COUNTVAL), INTENT(OUT) :: BUFFER(NDIM)
      CHARACTER(LEN=*), INTENT(IN) :: MESSAGE
    END SUBROUTINE BCAST_ALL_CH_ARRAY
  END INTERFACE 
END MODULE BCAST_ALL_CH_ARRAY__genmod

SUBROUTINE BCAST_ALL_CH_ARRAY(BUFFER, NDIM, COUNTVAL, MESSAGE)
  INTEGER, INTENT(IN) :: NDIM, COUNTVAL
  CHARACTER(LEN=COUNTVAL), INTENT(OUT) :: BUFFER(NDIM)
  CHARACTER(LEN=*), INTENT(IN) :: MESSAGE
  INTEGER :: i
  DO i = 1, NDIM
    BUFFER(i) = MESSAGE
  END DO
END SUBROUTINE BCAST_ALL_CH_ARRAY

PROGRAM test
  USE BCAST_ALL_CH_ARRAY__genmod
  CHARACTER(LEN=20) :: buffer(5)
  CALL BCAST_ALL_CH_ARRAY(buffer, 5, 20, 'Hello, World!')
  PRINT *, buffer
END PROGRAM test