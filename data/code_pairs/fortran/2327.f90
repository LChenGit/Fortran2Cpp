subroutine vpot(r,v,vp,vpp)
      implicit none
      double precision, intent(in) :: r
      double precision, intent(out) :: v, vp, vpp
      double precision :: a, alp, d, c6, c8, c10, sigma, rm, eps
      double precision :: units, y, v1, v1p, v1pp, x2, f, fp, dy, v2, v2p, v2pp
      double precision, parameter :: expmax=666.d0

      ! Constants
      data a,alp,d,c6,c8,c10,sigma,rm,eps /544850.4d0, 13.353384d0, 1.241314d0,
     + 1.3732412d0, .4253785d0, .1781d0, 2.556d0, 2.9673d0, 10.8d0/

      units=sigma/rm
      y=rm/(sigma*r)

      v1=a*eps*exp(-alp/y)
      v1p=-alp*units*v1
      v1pp=-alp*units*v1p
      x2=y*y

      f=eps
      fp=0.d0
      dy=d*y

      v2=(c6+(c8+c10*x2)*x2)*x2**3
      v2p=-(6.d0*c6+(8.d0*c8+10.d0*c10*x2)*x2)*x2**3/r
      v2pp=(6.d0*7.d0*c6+(8.d0*9.d0*c8+10.d0*11.d0*c10*x2)*x2)*x2**3/(r**2)

      if (dy > 1.d0) then
         f=f*exp(-min(expmax,(dy-1.d0)**2))
         fp=2.d0*(dy-1.d0)*dy*f/r
      endif

      v=v1-f*v2
      vp=v1p-f*v2p-fp*v2
      vpp=v1pp-f*v2pp-2.d0*fp*v2p

      return
end