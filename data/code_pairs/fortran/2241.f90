MODULE vast_kind_param
  INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

MODULE zerom_I
  USE vast_kind_param, ONLY: DOUBLE
  INTERFACE
    SUBROUTINE zerom(X, M)
      INTEGER, INTENT(IN) :: M
      REAL(DOUBLE), DIMENSION(M, M), INTENT(OUT) :: X
    END SUBROUTINE zerom
  END INTERFACE
END MODULE zerom_I

SUBROUTINE zerom(X, M)
  USE vast_kind_param, ONLY: DOUBLE
  INTEGER, INTENT(IN) :: M
  REAL(DOUBLE), DIMENSION(M, M), INTENT(OUT) :: X
  INTEGER :: i, j

  DO i = 1, M
    DO j = 1, M
      X(i, j) = 0.0_DOUBLE
    END DO
  END DO
END SUBROUTINE zerom