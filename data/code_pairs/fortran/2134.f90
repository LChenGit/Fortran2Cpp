SUBROUTINE ZLACGV(N, X, INCX)
      INTEGER            INCX, N
      COMPLEX*16         X(*)
      INTEGER            I, IOFF
      INTRINSIC          DCONJG

      IF (INCX.EQ.1) THEN
         DO I = 1, N
            X(I) = DCONJG(X(I))
         END DO
      ELSE
         IOFF = 1
         IF (INCX.LT.0) THEN
            IOFF = 1 - (N - 1) * INCX
         END IF
         DO I = 1, N
            X(IOFF) = DCONJG(X(IOFF))
            IOFF = IOFF + INCX
         END DO
      END IF
      RETURN
END SUBROUTINE ZLACGV