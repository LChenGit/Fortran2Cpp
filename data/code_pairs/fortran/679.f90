! ILASLR.f90
FUNCTION ILASLR( M, N, A, LDA ) RESULT(res)
  INTEGER, INTENT(IN) :: M, N, LDA
  REAL, INTENT(IN) :: A(LDA, *)
  INTEGER :: res
  REAL :: ZERO
  PARAMETER ( ZERO = 0.0E+0 )
  INTEGER :: I, J
  
  IF(M.EQ.0)THEN
     res = M
  ELSEIF( A(M, 1).NE.ZERO .OR. A(M, N).NE.ZERO )THEN
     res = M
  ELSE
     res = 0
     DO J = 1, N
        I = M
        DO WHILE ((A(I,J).NE.ZERO).AND.(I.GE.1))
          I = I-1
          IF (I.EQ.0) THEN
             EXIT
          END IF
        END DO
        res = MAX( res, I )
     END DO
  END IF
END FUNCTION ILASLR

PROGRAM testILASLR
  IMPLICIT NONE
  INTEGER :: M, N, LDA, result
  REAL, ALLOCATABLE :: A(:,:)

  ! Test 1: All zeros matrix
  M = 3
  N = 3
  LDA = 3
  ALLOCATE(A(LDA,N))
  A = 0.0
  result = ILASLR(M, N, A, LDA)
  IF (result == 3) THEN
     PRINT *, "Test 1 Passed."
  ELSE
     PRINT *, "Test 1 Failed."
  END IF
  DEALLOCATE(A)

  ! Test 2: Last row has a non-zero element at the start
  ALLOCATE(A(LDA,N))
  A = 0.0
  A(3, 1) = 1.0
  result = ILASLR(M, N, A, LDA)
  IF (result == 3) THEN
     PRINT *, "Test 2 Passed."
  ELSE
     PRINT *, "Test 2 Failed."
  END IF
  DEALLOCATE(A)
END PROGRAM testILASLR