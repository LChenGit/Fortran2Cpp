! foo.f90
module foo
  implicit none
  real :: a = 0.0
end module foo

program test
  use foo
  real :: z
  pointer :: c_a => null()

  c_a => a
  z = 42.0
  a = z
  if (a /= 42.0) STOP "Error: a is not 42"
  print *, "Test passed: The value of a is 42"
end program test