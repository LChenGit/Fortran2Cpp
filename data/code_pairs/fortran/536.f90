program test_arithmetic_if
  integer :: A, x

  ! Test case setup
  A = -1 ! Example value; change this to test different paths
  x = 0

  ! Arithmetic IF statement to decide the path based on the value of A
  if (A) 100, 200, 300

  100 CONTINUE
  x = x + 1
  goto 400

  200 CONTINUE
  x = x + 2
  goto 400

  300 CONTINUE
  x = x + 3

  400 CONTINUE
  print *, 'Test Case with A = ', A, ' results in x = ', x

end program test_arithmetic_if