MODULE SLCTSXMod
  IMPLICIT NONE
CONTAINS
  LOGICAL FUNCTION SLCTSX(AR, AI, BETA)
    REAL, INTENT(IN) :: AR, AI, BETA
    INTEGER :: M, N, MPLUSN, I
    LOGICAL :: FS
    COMMON /MN/ M, N, MPLUSN, I, FS

    IF (FS) THEN
      I = I + 1
      IF (I <= M) THEN
        SLCTSX = .FALSE.
      ELSE
        SLCTSX = .TRUE.
      END IF
      IF (I == MPLUSN) THEN
        FS = .FALSE.
        I = 0
      END IF
    ELSE
      I = I + 1
      IF (I <= N) THEN
        SLCTSX = .TRUE.
      ELSE
        SLCTSX = .FALSE.
      END IF
      IF (I == MPLUSN) THEN
        FS = .TRUE.
        I = 0
      END IF
    END IF
  END FUNCTION SLCTSX
END MODULE SLCTSXMod