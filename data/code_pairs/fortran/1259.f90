program test
implicit none
  double precision :: a, b, c

  a = 1.0d-46
  b = 1.0d0
  c = fun(a, b)
  print *, 'in main: fun=', c
end program test

double precision function fun(a, b)
  double precision, intent(in) :: a, b
  print *, 'in sub: a,b=', a, b
  fun = a * b
  print *, 'in sub: fun=', fun
end function fun