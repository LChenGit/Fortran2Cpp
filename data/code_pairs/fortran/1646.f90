SUBROUTINE GRID2TRIPLE(X,Y,Z,MX,NY,D,LDMAX,LD,ZMSG,IER)
      IMPLICIT NONE
      INTEGER MX,NY,LDMAX
      DOUBLE PRECISION X(MX),Y(NY),Z(MX,NY),ZMSG
      INTEGER LD,IER
      DOUBLE PRECISION D(LDMAX,3)

      INTEGER M,N

      LD = 0
      IER = 0

      DO N = 1,NY
          DO M = 1,MX
              IF (Z(M,N).NE.ZMSG) THEN
                  IF (LD .LT. LDMAX) THEN
                      LD = LD + 1
                      D(LD,1) = X(M)
                      D(LD,2) = Y(N)
                      D(LD,3) = Z(M,N)
                  ELSE
                      IER = -11
                      RETURN
                  END IF
              END IF
          END DO
      END DO

      IF (LD.EQ.0) THEN
          IER = -10
      END IF
      RETURN
END