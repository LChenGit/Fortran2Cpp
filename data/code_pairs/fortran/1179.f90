program test
  implicit none
  complex :: cresult, cexpected
  real :: re, im
  
  ! Example calculation for complex power
  re = 2.0
  im = -4.3
  cexpected = cmplx(re, im)**2
  cresult = cmplx(-14.49, -17.2) ! Assuming this is the expected calculation result
  
  if (abs(cresult - cexpected) < 1.0E-5) then
    print *, "Test passed for complex power."
  else
    print *, "Test failed for complex power."
  endif

end program test