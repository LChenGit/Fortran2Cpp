program test_ddot
    implicit none
    double precision :: result
    integer :: n, incx, incy
    double precision, dimension(5) :: dx, dy

    ! Example data
    dx = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    dy = (/5.0d0, 4.0d0, 3.0d0, 2.0d0, 1.0d0/)
    n = 5
    incx = 1
    incy = 1

    ! Call the DDOT function
    result = ddot(n, dx, incx, dy, incy)

    ! Print the result
    print *, "DDOT result: ", result

contains

    DOUBLE PRECISION FUNCTION DDOT(N,DX,INCX,DY,INCY)
        INTEGER INCX,INCY,N
        DOUBLE PRECISION DX(*),DY(*)
        DOUBLE PRECISION DTEMP
        INTEGER I,IX,IY,M,MP1
        INTRINSIC MOD
        DDOT = 0.0d0
        DTEMP = 0.0d0
        IF (N.LE.0) RETURN
        IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
            M = MOD(N,5)
            IF (M.NE.0) THEN
                DO I = 1,M
                    DTEMP = DTEMP + DX(I)*DY(I)
                END DO
                IF (N.LT.5) THEN
                    DDOT=DTEMP
                    RETURN
                END IF
            END IF
            MP1 = M + 1
            DO I = MP1,N,5
                DTEMP = DTEMP + DX(I)*DY(I) + DX(I+1)*DY(I+1) +
     &                DX(I+2)*DY(I+2) + DX(I+3)*DY(I+3) + DX(I+4)*DY(I+4)
            END DO
        ELSE
            IX = 1
            IY = 1
            IF (INCX.LT.0) IX = (-N+1)*INCX + 1
            IF (INCY.LT.0) IY = (-N+1)*INCY + 1
            DO I = 1,N
                DTEMP = DTEMP + DX(IX)*DY(IY)
                IX = IX + INCX
                IY = IY + INCY
            END DO
        END IF
        DDOT = DTEMP
        RETURN
    END FUNCTION DDOT

end program test_ddot