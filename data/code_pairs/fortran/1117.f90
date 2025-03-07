MODULE ZSwapModule
    IMPLICIT NONE
CONTAINS
    SUBROUTINE ZSWAP(N,ZX,INCX,ZY,INCY)
        INTEGER INCX,INCY,N
        COMPLEX*16 ZX(*),ZY(*)
        COMPLEX*16 ZTEMP
        INTEGER I,IX,IY
        IF (N.LE.0) RETURN
        IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
            DO I = 1,N
                ZTEMP = ZX(I)
                ZX(I) = ZY(I)
                ZY(I) = ZTEMP
            END DO
        ELSE
            IX = 1
            IY = 1
            IF (INCX.LT.0) IX = (-N+1)*INCX + 1
            IF (INCY.LT.0) IY = (-N+1)*INCY + 1
            DO I = 1,N
                ZTEMP = ZX(IX)
                ZX(IX) = ZY(IY)
                ZY(IY) = ZTEMP
                IX = IX + INCX
                IY = IY + INCY
            END DO
        END IF
    END SUBROUTINE ZSWAP
END MODULE ZSwapModule