SUBROUTINE ZDSCAL(N, DA, ZX, INCX)
    DOUBLE PRECISION DA
    INTEGER INCX, N
    COMPLEX*16 ZX(*)
    
    INTEGER I, NINCX
    INTRINSIC DCMPLX
    
    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    IF (INCX.EQ.1) THEN
        DO I = 1, N
            ZX(I) = DCMPLX(DA, 0.0D0) * ZX(I)
        END DO
    ELSE
        NINCX = N*INCX
        DO I = 1, NINCX, INCX
            ZX(I) = DCMPLX(DA, 0.0D0) * ZX(I)
        END DO
    END IF
    RETURN
END SUBROUTINE ZDSCAL

PROGRAM test_zdscal
    IMPLICIT NONE
    COMPLEX*16, ALLOCATABLE :: ZX(:)
    INTEGER :: I
    DOUBLE PRECISION :: DA
    INTEGER :: N, INCX
    
    ! Example test case
    N = 5
    ALLOCATE(ZX(N))
    DA = 2.0D0
    INCX = 1
    
    ! Initialize ZX with some values
    DO I = 1, N
        ZX(I) = CMPLX(DBLE(I), DBLE(I))
    END DO
    
    ! Call ZDSCAL
    CALL ZDSCAL(N, DA, ZX, INCX)
    
    ! Output the result
    PRINT *, 'Result:'
    DO I = 1, N
        PRINT *, 'ZX(', I, ') = ', ZX(I)
    END DO
    
    DEALLOCATE(ZX)
END PROGRAM test_zdscal