! File: test_foo.f90
program test_foo
  call foo
  call foo
end program test_foo

subroutine foo
  integer, save :: i = 0
  print *, 'Value of i before assignment: ', i
  i = 1
  print *, 'Value of i after assignment: ', i
end subroutine