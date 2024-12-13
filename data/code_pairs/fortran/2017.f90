SUBROUTINE MDIAN2(X, N, XMED)
  REAL, DIMENSION(:), INTENT(IN) :: X
  INTEGER, INTENT(IN) :: N
  REAL, INTENT(OUT) :: XMED
  REAL, DIMENSION(1000) :: XCOPY
  REAL :: BIG = 1.E30
  REAL :: AFAC = 1.5
  REAL :: AMP = 1.5
  REAL :: A, EPS, AP, AM, SUM, SUMX, XP, XM, XX, AA, DUM
  INTEGER :: J, NP, NM

  XCOPY(1:N) = X
  A = 0.5 * (XCOPY(1) + XCOPY(N))
  EPS = ABS(XCOPY(N) - XCOPY(1))
  AP = BIG
  AM = -BIG

  DO
    SUM = 0.
    SUMX = 0.
    NP = 0
    NM = 0
    XP = BIG
    XM = -BIG
    DO J = 1, N
      XX = XCOPY(J)
      IF (XX /= A) THEN
        IF (XX > A) THEN
          NP = NP + 1
          IF (XX < XP) XP = XX
        ELSE IF (XX < A) THEN
          NM = NM + 1
          IF (XX > XM) XM = XX
        END IF
        DUM = 1. / (EPS + ABS(XX - A))
        SUM = SUM + DUM
        SUMX = SUMX + XX * DUM
      END IF
    END DO
    IF (NP - NM >= 2) THEN
      AM = A
      AA = XP + MAX(0., SUMX / SUM - A) * AMP
      IF (AA > AP) AA = 0.5 * (A + AP)
      EPS = AFAC * ABS(AA - A)
      A = AA
    ELSE IF (NM - NP >= 2) THEN
      AP = A
      AA = XM + MIN(0., SUMX / SUM - A) * AMP
      IF (AA < AM) AA = 0.5 * (A + AM)
      EPS = AFAC * ABS(AA - A)
      A = AA
    ELSE
      EXIT
    END IF
  END DO

  IF (MOD(N, 2) == 0) THEN
    IF (NP == NM) THEN
      XMED = 0.5 * (XP + XM)
    ELSE IF (NP > NM) THEN
      XMED = 0.5 * (A + XP)
    ELSE
      XMED = 0.5 * (XM + A)
    END IF
  ELSE
    IF (NP == NM) THEN
      XMED = A
    ELSE IF (NP > NM) THEN
      XMED = XP
    ELSE
      XMED = XM
    END IF
  END IF
END SUBROUTINE MDIAN2