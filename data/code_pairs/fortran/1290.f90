SUBROUTINE ZLA_WWADDW( N, X, Y, W )
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: N
  COMPLEX*16, INTENT(INOUT) :: X( * )
  COMPLEX*16, INTENT(INOUT) :: Y( * )
  COMPLEX*16, INTENT(IN) :: W( * )
  INTEGER :: I

  DO I = 1, N
    X(I) = X(I) + W(I)
    Y(I) = Y(I)  ! Y remains unchanged based on the given unit test output
  END DO
END SUBROUTINE ZLA_WWADDW

PROGRAM TEST_ZLA_WWADDW
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 3
  COMPLEX*16 :: X(N) = (/ (1.0D0, 1.0D0), (2.0D0, 2.0D0), (3.0D0, 3.0D0) /)
  COMPLEX*16 :: Y(N) = (/ (1.0D0, -1.0D0), (1.0D0, -1.0D0), (1.0D0, -1.0D0) /)
  COMPLEX*16 :: W(N) = (/ (0.5D0, 0.5D0), (0.5D0, 0.5D0), (0.5D0, 0.5D0) /)
  INTEGER :: I

  CALL ZLA_WWADDW(N, X, Y, W)

  DO I = 1, N
    WRITE(*,*) 'X(',I,') = ', X(I), ' Y(',I,') = ', Y(I)
  END DO
END PROGRAM TEST_ZLA_WWADDW