program prog
  complex :: zero, one_two, three_four
  real, parameter :: three=3.0
  real, parameter :: four=three+1.0
  parameter(zero=(0.0e+0,0.0e+0))
  parameter(one_two=(1.0e+0,2.0e+0), three_four=(three,four))
  
  write(*, *) zero
  write(*, *) one_two
  write(*, *) three_four
end program prog