PROGRAM TestDLAPMT
  IMPLICIT NONE
  LOGICAL :: FORWRD
  INTEGER :: M, N, LDX
  INTEGER, ALLOCATABLE :: K(:)
  DOUBLE PRECISION, ALLOCATABLE :: X(:,:)
  INTEGER :: I, J

  ! Example parameters and data
  FORWRD = .TRUE.
  M = 2
  N = 3
  LDX = M
  ALLOCATE(K(N), X(LDX, N))

  ! Initialize K and X for testing
  K = (/ 3, 1, 2 /)
  X = RESHAPE((/ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 /), SHAPE(X))

  ! Call the subroutine
  CALL DLAPMT(FORWRD, M, N, X, LDX, K)

  ! Print the results
  PRINT *, "K after DLAPMT:"
  DO I = 1, N
    PRINT *, K(I)
  END DO

  PRINT *, "X after DLAPMT:"
  DO I = 1, M
    DO J = 1, N
      PRINT *, X(I, J)
    END DO
  END DO

END PROGRAM TestDLAPMT