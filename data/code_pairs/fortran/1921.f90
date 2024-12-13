subroutine fcrit(time,t,a,b,ze,d,dd,h1,h2,h3,h4,func,funcp)
  implicit none
  real*8 time,t,a,b,ze,d,dd,h1,h2,h3,h4,fexp,func,funcp

  fexp = dexp(-h1*t)
  func = ((a+b*time)*(-t*h2-h3)-b*(-t*t*h2-2.d0*t*h3-2.d0*h4))*fexp
  funcp = ((a+b*time)*t-b*(h3+t*h2+t*t))*fexp

  return
end subroutine fcrit