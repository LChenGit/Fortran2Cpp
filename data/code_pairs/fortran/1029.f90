! dnrm2.f90
DOUBLE PRECISION FUNCTION DNRM2(N,X,INCX)
    INTEGER INCX,N
    DOUBLE PRECISION X(*)
    DOUBLE PRECISION ONE,ZERO
    PARAMETER (ONE=1.0D+0,ZERO=0.0D+0)
    DOUBLE PRECISION ABSXI,NORM,SCALE,SSQ
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
10      CONTINUE
        NORM = SCALE*SQRT(SSQ)
    END IF
    DNRM2 = NORM
    RETURN
END FUNCTION DNRM2