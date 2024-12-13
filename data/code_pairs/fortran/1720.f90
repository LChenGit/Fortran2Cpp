PROGRAM TestGDMPGD
  IMPLICIT NONE
  REAL, ALLOCATABLE :: R(:,:), A(:,:), B(:,:)
  INTEGER :: NI, NJ, NB, I, J
  REAL :: CON
  
  NI = 4
  NJ = 4
  NB = 1234
  CON = 1.5
  ALLOCATE(R(NI,NJ), A(NI,NJ), B(NI,NJ))
  
  CALL RANDOM_NUMBER(A)
  CALL RANDOM_NUMBER(B)

  CALL GDMPGD(R, A, B, CON, NI, NJ, NB)
  
  PRINT *, 'Result R:'
  DO I = 1, NI
    PRINT *, (R(I, J), J=1, NJ)
  END DO
  
  DEALLOCATE(R, A, B)
END PROGRAM TestGDMPGD

SUBROUTINE GDMPGD (R,A,B,CON,NI,NJ,NB)
  REAL R(NI,NJ), A(NI,NJ), B(NI,NJ)
  INTEGER NI, NJ, NB, I, J, IL, JB, IR, JT
  REAL CON

  IL = 1 + NB / 1000
  JB = 1 + MOD(NB,1000) / 100
  IR = NI - MOD(NB,100) / 10
  JT = NJ - MOD(NB,10)
  IF (NB == 0) THEN
    JT = 1
    IR = NI*NJ
  END IF

  DO J=JB,JT
    DO I=IL,IR
      R(I,J) = CON * A(I,J) + B(I,J)  ! Simplified operation for demonstration
    END DO
  END DO
END SUBROUTINE GDMPGD