program test_idamax
  implicit none
  integer :: n, incx, result
  double precision, allocatable :: dx(:)
  
  ! Initialize test data
  n = 5
  incx = 1
  allocate(dx(n))
  dx = (/1.0d0, 3.0d0, -5.0d0, 2.0d0, 4.0d0/)
  
  ! Call the IDAMAX function
  result = idamax(n, dx, incx)
  
  ! Print the result
  print *, 'IDAMAX result:', result
  
contains

  INTEGER FUNCTION IDAMAX(N, DX, INCX)
    INTEGER, INTENT(IN) :: N, INCX
    DOUBLE PRECISION, INTENT(IN) :: DX(*)
    DOUBLE PRECISION :: DMAX, XMAG
    INTEGER :: I, IX
    
    IDAMAX = 0
    IF (N.LE.0) RETURN
    IDAMAX = 1
    IF (N.EQ.1) RETURN
    IF (INCX.EQ.1) GOTO 20
    IX = 1
    IF (INCX.LT.0) IX = (-N+1)*INCX + 1
    DMAX = ABS(DX(IX))
    IX = IX + INCX
    DO I = 2,N
      XMAG = ABS(DX(IX))
      IF (XMAG.GT.DMAX) THEN
        IDAMAX = I
        DMAX = XMAG
      END IF
      IX = IX + INCX
    END DO
    RETURN
20  DMAX = ABS(DX(1))
    DO I = 2,N
      XMAG = ABS(DX(I))
      IF (XMAG.GT.DMAX) THEN
        IDAMAX = I
        DMAX = XMAG
      END IF
    END DO
    RETURN
  END FUNCTION IDAMAX

end program test_idamax