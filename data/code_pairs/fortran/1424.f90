program literalnonzero
  real :: a, b
  a = 2.0
  b = f(a)
  print *, 'b = ', b

contains
  real function f(x)
    real, intent(in) :: x
    f = 1.0
  end function f
end program literalnonzero