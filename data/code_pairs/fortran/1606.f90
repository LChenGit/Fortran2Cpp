! CorrectFortranProgram.f90
PROGRAM TestFortranProgram
  IMPLICIT NONE
  INTEGER :: A(200, 100, 19)

  A = 0
  CALL FOO(A, 200, 100)

  IF (ALL(A == 1)) THEN
     PRINT *, "Fortran Test Passed: All elements are set to 1."
  ELSE
     PRINT *, "Fortran Test Failed: Not all elements are set to 1."
  END IF
END PROGRAM TestFortranProgram

SUBROUTINE FOO(S, L1, L2)
  INTEGER, INTENT(IN) :: L1, L2
  INTEGER, INTENT(INOUT) :: S(L1, L2, 19)

  !$OMP PARALLEL DO COLLAPSE(3)
  DO I = 1, L1
     DO J = 1, L2
        DO K = 1, 19
           S(I, J, K) = 1
        END DO
     END DO
  END DO
  !$OMP END PARALLEL DO
END SUBROUTINE FOO