SUBROUTINE spline(x,y,n,yp1,ypn,y2,u)
      INTEGER n
      REAL yp1,ypn,x(n),y(n),y2(n),u(n)
      INTEGER i,k
      REAL p,qn,sig,un
      if (yp1 .gt. .99e30) then
        y2(1)=0.
        u(1)=0.
      else
        y2(1)=-0.5
        u(1)=(3./(x(2)-x(1)))*((y(2)-y(1))/(x(2)-x(1))-yp1)
      endif
      do 11 i=2,n-1
        sig=(x(i)-x(i-1))/(x(i+1)-x(i-1))
        p=sig*y2(i-1)+2.
        y2(i)=(sig-1.)/p
        u(i)=(6.*((y(i+1)-y(i))/(x(i+1)-x(i))-(y(i)-y(i-1))/(x(i)-x(i-1)))/(x(i+1)-x(i-1))-sig*u(i-1))/p
11    continue
      if (ypn.gt..99e30) then
        qn=0.
        un=0.
      else
        qn=0.5
        un=(3./(x(n)-x(n-1)))*(ypn-(y(n)-y(n-1))/(x(n)-x(n-1)))
      endif
      y2(n)=(un-qn*u(n-1))/(qn*y2(n-1)+1.)
      do 12 k=n-1,1,-1
        y2(k)=y2(k)*y2(k+1)+u(k)
12    continue
      return
      END

      PROGRAM TestSpline
      IMPLICIT NONE
      INTEGER, PARAMETER :: MAXPTS=5
      REAL :: x(MAXPTS) = (/0.0, 1.0, 2.0, 3.0, 4.0/)
      REAL :: y(MAXPTS) = (/0.0, 0.8415, 0.9093, 0.1411, -0.7568/)
      REAL :: yp1, ypn, y2(MAXPTS), u(MAXPTS)
      INTEGER :: i, n

      n = 5
      yp1 = 1.0
      ypn = -1.0

      CALL spline(x, y, n, yp1, ypn, y2, u)

      PRINT *, 'y2 = '
      DO i = 1, n
          PRINT *, y2(i)
      END DO
      END PROGRAM TestSpline