! FJAC.f90
SUBROUTINE FJAC(X, V, K)
  IMPLICIT NONE
  DOUBLE PRECISION, INTENT(INOUT) :: X(*)
  DOUBLE PRECISION, INTENT(IN) :: V(*)
  INTEGER, INTENT(IN) :: K
  INTEGER :: i

  DO i = 1, K
     X(i) = X(i) + 1
  END DO
END SUBROUTINE FJAC

! Unit test for FJAC subroutine
PROGRAM TestFJAC
  IMPLICIT NONE
  DOUBLE PRECISION :: X(5) = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  DOUBLE PRECISION :: V(5)
  INTEGER :: K = 5
  INTEGER :: i

  CALL FJAC(X, V, K)

  DO i = 1, K
     PRINT *, "X(", i, ") = ", X(i)
  END DO
END PROGRAM TestFJAC