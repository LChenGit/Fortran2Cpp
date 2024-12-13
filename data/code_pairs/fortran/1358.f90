SUBROUTINE CSCAL(N, CA, CX, INCX)
    COMPLEX CA
    INTEGER INCX, N
    COMPLEX CX(*)
    INTEGER I, NINCX
    
    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    
    IF (INCX.EQ.1) THEN
        DO I = 1, N
            CX(I) = CA * CX(I)
        END DO
    ELSE
        NINCX = N * INCX
        DO I = 1, NINCX, INCX
            CX(I) = CA * CX(I)
        END DO
    END IF
END SUBROUTINE CSCAL

PROGRAM testCSCAL
    IMPLICIT NONE
    COMPLEX, ALLOCATABLE :: CX(:)
    COMPLEX :: CA
    INTEGER :: N, INCX, I

    ! Test 1
    PRINT *, "Test 1 Results:"
    N = 5
    INCX = 1
    CA = (2.0, 3.0)
    ALLOCATE(CX(N))
    CX = [(COMPLEX(1.0, 1.0), I = 1, N)]
    CALL CSCAL(N, CA, CX, INCX)
    DO I = 1, N
        PRINT *, CX(I)
    END DO
    DEALLOCATE(CX)

    ! Test 2
    PRINT *, "Test 2 Results:"
    N = 4
    INCX = 2
    CA = (0.5, 0.5)
    ALLOCATE(CX(N))
    CX = [(COMPLEX(2.0, 2.0), I = 1, N)]
    CALL CSCAL(N, CA, CX, INCX)
    DO I = 1, N, INCX
        PRINT *, CX(I)
    END DO
    DEALLOCATE(CX)
END PROGRAM testCSCAL