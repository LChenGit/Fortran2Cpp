SUBROUTINE SLARRA(N, D, E, E2, SPLTOL, TNRM, NSPLIT, ISPLIT, INFO)
  INTEGER, INTENT(IN) :: N
  REAL, INTENT(IN) :: D(*), E(*), E2(*), SPLTOL, TNRM
  INTEGER, INTENT(OUT) :: NSPLIT, ISPLIT(*), INFO
  REAL :: ZERO = 0.0E0
  INTEGER :: I
  REAL :: EABS, TMP1

  INFO = 0
  IF (N.LE.0) THEN
     RETURN
  END IF

  NSPLIT = 1
  IF (SPLTOL.LT.ZERO) THEN
     TMP1 = ABS(SPLTOL) * TNRM
     DO I = 1, N-1
        EABS = ABS(E(I))
        IF (EABS.LE.TMP1) THEN
           E(I) = ZERO
           E2(I) = ZERO
           ISPLIT(NSPLIT) = I
           NSPLIT = NSPLIT + 1
        END IF
     END DO
  ELSE
     DO I = 1, N-1
        EABS = ABS(E(I))
        IF (EABS.LE.SPLTOL * SQRT(ABS(D(I))) * SQRT(ABS(D(I+1)))) THEN
           E(I) = ZERO
           E2(I) = ZERO
           ISPLIT(NSPLIT) = I
           NSPLIT = NSPLIT + 1
        END IF
     END DO
  END IF
  ISPLIT(NSPLIT) = N
END SUBROUTINE SLARRA