SUBROUTINE DLAPMT(FORWRD, M, N, X, LDX, K)
  LOGICAL, INTENT(IN) :: FORWRD
  INTEGER, INTENT(IN) :: LDX, M, N
  INTEGER, INTENT(INOUT) :: K(LDX)
  DOUBLE PRECISION, INTENT(INOUT) :: X(LDX, *)

  INTEGER :: I, II, IN, J
  DOUBLE PRECISION :: TEMP

  IF (N.LE.1) RETURN

  DO I = 1, N
     K(I) = -K(I)
  END DO

  IF (FORWRD) THEN
     DO I = 1, N
        IF (K(I) .GT. 0) CYCLE

        J = I
        K(J) = -K(J)
        IN = K(J)

        DO
           IF (K(IN) .GT. 0) EXIT

           DO II = 1, M
              TEMP = X(II, J)
              X(II, J) = X(II, IN)
              X(II, IN) = TEMP
           END DO

           K(IN) = -K(IN)
           J = IN
           IN = K(IN)
        END DO
     END DO
  ELSE
     DO I = 1, N
        IF (K(I) .GT. 0) CYCLE

        K(I) = -K(I)
        J = K(I)

        DO
           IF (J .EQ. I) EXIT

           DO II = 1, M
              TEMP = X(II, I)
              X(II, I) = X(II, J)
              X(II, J) = TEMP
           END DO

           K(J) = -K(J)
           J = K(J)
        END DO
     END DO
  END IF
END SUBROUTINE DLAPMT