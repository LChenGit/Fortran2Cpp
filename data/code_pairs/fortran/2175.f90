module common_blocks
  implicit none
  character(len=15) :: c
  integer :: d, e
  real :: f
end module common_blocks

subroutine test()
  use common_blocks
  if ((d .ne. 42) .or. (e .ne. 43) .or. (f .ne. 2.0)) then
    print *, "Test failed due to incorrect values in /block/"
    stop
  endif
  if (c .ne. "Hello World    ") then
    print *, "Test failed due to incorrect value in /block2/"
    stop
  endif
  print *, "All tests passed."
end subroutine test

program main
  use common_blocks
  d = 42
  e = 43
  f = 2.0
  c = "Hello World    "
  call test()
end program main