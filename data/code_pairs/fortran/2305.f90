! Define module to encapsulate common block
module common_data
  integer :: a, b
  common /bar/ a, b
end module common_data

! Define subroutine that uses the common block
subroutine foo
  use common_data
  a = 1
  b = 2
end subroutine foo

! Unit test program
program test_foo
  use common_data
  call foo()
  if (a == 1 .and. b == 2) then
    print *, 'Test passed: a = ', a, ' b = ', b
  else
    print *, 'Test failed: a = ', a, ' b = ', b
  end if
end program test_foo