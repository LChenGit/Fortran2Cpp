subroutine foo(i)
  implicit none
  integer, intent(in) :: i
  character(len=i) :: s
  
  s = 'Hello'  ! Assuming the input i is at least 5
  print *, 'Testing with i = ', i
  print *, 'Expected length of s: 5'
  print *, 'Actual length of s: ', len(s)
  print *, 'Contents of s: ', s
end subroutine

program test_foo_program
  implicit none
  call foo(10) ! Example call with i=10
end program test_foo_program