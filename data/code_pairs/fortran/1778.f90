SUBROUTINE CCOPY(N,CX,INCX,CY,INCY)
  INTEGER INCX,INCY,N
  COMPLEX CX(*),CY(*)
  INTEGER I,IX,IY
  IF (N.LE.0) RETURN
  IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
     DO I = 1,N
        CY(I) = CX(I)
     END DO
  ELSE
     IX = 1
     IY = 1
     IF (INCX.LT.0) IX = (-N+1)*INCX + 1
     IF (INCY.LT.0) IY = (-N+1)*INCY + 1
     DO I = 1,N
        CY(IY) = CX(IX)
        IX = IX + INCX
        IY = IY + INCY
     END DO
  END IF
  RETURN
END SUBROUTINE CCOPY

PROGRAM TestCCOPY
  IMPLICIT NONE
  INTEGER :: n, incx, incy
  COMPLEX, ALLOCATABLE :: cx(:), cy(:)
  INTEGER :: i

  ! Test 1: Basic functionality
  n = 5
  incx = 1
  incy = 1
  ALLOCATE(cx(n), cy(n))
  DO i = 1, n
    cx(i) = CMPLX(i, -i)
    cy(i) = CMPLX(0.0, 0.0)
  END DO
  CALL CCOPY(n, cx, incx, cy, incy)
  PRINT *, "Test 1: Basic functionality"
  DO i = 1, n
    PRINT *, "cy(", i, ") = cx(", i, ") =", cy(i)
  END DO
  
  DEALLOCATE(cx, cy)
END PROGRAM TestCCOPY