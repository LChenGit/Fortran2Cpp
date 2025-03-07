PROGRAM testSNRM2
      IMPLICIT NONE
      REAL :: result
      INTEGER, PARAMETER :: N = 3
      REAL, DIMENSION(1:N) :: X = (/3.0, 4.0, 0.0/)
      INTEGER :: INCX

      INCX = 1
      result = SNRM2(N, X, INCX)
      PRINT *, "The 2-norm of the vector is: ", result

      CONTAINS

      REAL FUNCTION SNRM2(N,X,INCX)
          INTEGER INCX,N
          REAL X(*)

          REAL ONE,ZERO
          PARAMETER (ONE=1.0E+0,ZERO=0.0E+0)
          REAL ABSXI,NORM,SCALE,SSQ
          INTEGER IX
          INTRINSIC ABS,SQRT

          IF (N.LT.1 .OR. INCX.LT.1) THEN
              NORM = ZERO
          ELSE IF (N.EQ.1) THEN
              NORM = ABS(X(1))
          ELSE
              SCALE = ZERO
              SSQ = ONE

              DO 10 IX = 1,1 + (N-1)*INCX,INCX
                  IF (X(IX).NE.ZERO) THEN
                      ABSXI = ABS(X(IX))
                      IF (SCALE.LT.ABSXI) THEN
                          SSQ = ONE + SSQ* (SCALE/ABSXI)**2
                          SCALE = ABSXI
                      ELSE
                          SSQ = SSQ + (ABSXI/SCALE)**2
                      END IF
                  END IF
     10         CONTINUE
              NORM = SCALE*SQRT(SSQ)
          END IF

          SNRM2 = NORM
          RETURN

      END FUNCTION SNRM2

END PROGRAM testSNRM2