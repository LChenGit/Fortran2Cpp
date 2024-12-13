program test_fortran
  implicit none
  real(kind=16) :: x

  ! Calculation
  x = 1.0_16 + 2.0_16**(-105)
  
  ! Output the value of x for verification
  print *, "Value of x: ", x

end program test_fortran