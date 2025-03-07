PROGRAM testMA01BZ
  IMPLICIT NONE
  COMPLEX*16, ALLOCATABLE :: A(:)
  INTEGER, ALLOCATABLE :: S(:)
  INTEGER :: K, INCA, SCAL
  DOUBLE PRECISION :: BASE
  COMPLEX*16 :: ALPHA, BETA

  ! Initialize test data
  K = 2
  INCA = 1
  BASE = 2.0D0
  ALLOCATE(A(K))
  ALLOCATE(S(K))
  A(1) = (1.0D0, 2.0D0)
  A(2) = (3.0D0, 4.0D0)
  S(1) = 1
  S(2) = 0

  ! Call the subroutine
  CALL MA01BZ(BASE, K, S, A, INCA, ALPHA, BETA, SCAL)

  ! Output results
  PRINT *, 'ALPHA:', ALPHA
  PRINT *, 'BETA:', BETA
  PRINT *, 'SCAL:', SCAL

END PROGRAM testMA01BZ

SUBROUTINE MA01BZ(BASE, K, S, A, INCA, ALPHA, BETA, SCAL)
  DOUBLE PRECISION ONE, ZERO
  PARAMETER (ONE = 1.0D0, ZERO = 0.0D0)
  COMPLEX*16 CONE, CZERO
  PARAMETER (CONE = (1.0D0, 0.0D0), CZERO = (0.0D0, 0.0D0))
  INTEGER INCA, K, SCAL
  DOUBLE PRECISION BASE
  COMPLEX*16 ALPHA, BETA
  INTEGER S(*)
  COMPLEX*16 A(*)
  INTEGER I, INDA
  COMPLEX*16 CBASE

  CBASE = CMPLX(BASE, ZERO)
  ALPHA = CONE
  BETA = CONE
  SCAL = 0
  INDA = 1

  DO I = 1, K
    IF (S(I) .EQ. 1) THEN
      ALPHA = ALPHA * A(INDA)
    ELSE
      IF (A(INDA) .EQ. CZERO) THEN
        BETA = CZERO
      ELSE
        ALPHA = ALPHA / A(INDA)
      END IF
    END IF
    IF (ABS(ALPHA) .EQ. ZERO) THEN
      ALPHA = CZERO
      SCAL = 0
      IF (ABS(BETA) .EQ. ZERO) THEN
        RETURN
      END IF
    ELSE
      DO WHILE (ABS(ALPHA) .LT. ONE)
        ALPHA = ALPHA * CBASE
        SCAL = SCAL - 1
      END DO
      DO WHILE (ABS(ALPHA) .GE. BASE)
        ALPHA = ALPHA / CBASE
        SCAL = SCAL + 1
      END DO
    END IF
    INDA = INDA + INCA
  END DO
END SUBROUTINE MA01BZ