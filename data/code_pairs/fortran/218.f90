program main
  implicit none
  double precision :: x, y, yd, p, t, s, error
  integer :: M, n

  x = 1.9
  M = 7
  y = x - sin(x)
  yd = dble(x) - sin(dble(x))
  p = (x**3/6.)*(1. - (x*x/20.)*(1. - (x*x/42.)*(1. - (x*x/72.))))
  
  print *, 'Testing with x =', x
  print *, 'yd:', yd
  print *, 'First s:', s
  print *, 'First error:', error
  
  t = x**3/6.0
  s = t
  error = abs((s - yd)/yd)
  
  do n=1,M
     t = -t*x*x/real((2.*real(n)+2.)*(2.*real(n)+3.))
     s = s + t
     error = abs((s - yd)/yd)
     print *, 'n:', n, 's:', s, 'error:', error
  end do

end program main