PROGRAM testDQWGTC
  IMPLICIT NONE
  DOUBLE PRECISION C, P2, P3, P4, X, result
  INTEGER KP

  INTERFACE
    DOUBLE PRECISION FUNCTION DQWGTC(X, C, P2, P3, P4, KP)
      DOUBLE PRECISION, INTENT(IN) :: X, C, P2, P3, P4
      INTEGER, INTENT(IN) :: KP
    END FUNCTION DQWGTC
  END INTERFACE

  C = 2.0d0
  P2 = 0.0d0
  P3 = 0.0d0
  P4 = 0.0d0
  KP = 0
  X = 3.0d0

  result = DQWGTC(X, C, P2, P3, P4, KP)
  PRINT *, 'DQWGTC(3.0, 2.0, 0, 0, 0, 0) = ', result

END PROGRAM testDQWGTC

DOUBLE PRECISION FUNCTION DQWGTC (X, C, P2, P3, P4, KP)
  DOUBLE PRECISION C, P2, P3, P4, X
  INTEGER KP
  DQWGTC = 1.0d0 / (X - C)
  RETURN
END FUNCTION DQWGTC