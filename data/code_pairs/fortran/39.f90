SUBROUTINE DSCAL(N, DA, DX, INCX)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: N, INCX
    DOUBLE PRECISION, INTENT(IN) :: DA
    DOUBLE PRECISION, INTENT(INOUT) :: DX(*)
    
    INTEGER :: I, M, MP1, NINCX

    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    IF (INCX.EQ.1) THEN
        M = MOD(N, 5)
        IF (M.NE.0) THEN
            DO I = 1, M
                DX(I) = DA * DX(I)
            END DO
            IF (N.LT.5) RETURN
        END IF
        MP1 = M + 1
        DO I = MP1, N, 5
            DX(I) = DA * DX(I)
            DX(I+1) = DA * DX(I+1)
            DX(I+2) = DA * DX(I+2)
            DX(I+3) = DA * DX(I+3)
            DX(I+4) = DA * DX(I+4)
        END DO
    ELSE
        NINCX = N * INCX
        DO I = 1, NINCX, INCX
            DX(I) = DA * DX(I)
        END DO
    END IF
END SUBROUTINE DSCAL