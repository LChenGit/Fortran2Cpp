program test_F90
  integer :: a
  a = 3
  
  ! Unit test to verify the value of 'a'
  if (a == 3) then
    print *, "Test passed: a is 3"
  else
    print *, "Test failed: a is not 3"
  end if
end program test_F90