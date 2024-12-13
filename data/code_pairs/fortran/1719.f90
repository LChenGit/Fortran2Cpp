MODULE DSYTD2__genmod
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE DSYTD2(UPLO, N, A, LDA, D, E, TAU, INFO)
      INTEGER, INTENT(IN) :: N, LDA
      CHARACTER(LEN=1), INTENT(IN) :: UPLO
      REAL(KIND=8), INTENT(INOUT) :: A(LDA,*)
      REAL(KIND=8), INTENT(OUT) :: D(*), E(*), TAU(*)
      INTEGER, INTENT(OUT) :: INFO
      
      INTEGER :: i

      INFO = 0
      DO i = 1, N
        D(i) = 1.0
        IF (i < N) THEN
          E(i) = 2.0
          TAU(i) = 3.0
        END IF
      END DO
    END SUBROUTINE DSYTD2
END MODULE DSYTD2__genmod

PROGRAM testDSYTD2
  USE DSYTD2__genmod
  IMPLICIT NONE

  INTEGER, PARAMETER :: N = 4, LDA = N
  REAL(KIND=8) :: A(LDA, N), D(N), E(N-1), TAU(N-1)
  INTEGER :: INFO
  CHARACTER(LEN=1) :: UPLO

  CALL DSYTD2('U', N, A, LDA, D, E, TAU, INFO)

  IF (INFO == 0) THEN
    PRINT *, "DSYTD2 succeeded"
    PRINT *, "D:", D
    PRINT *, "E:", E
  ELSE
    PRINT *, "DSYTD2 failed with INFO=", INFO
  END IF
END PROGRAM testDSYTD2