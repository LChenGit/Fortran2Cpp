! main.f90
module x
contains
  subroutine a
    call foo(1.0)  ! Ensure passing a floating-point number directly.
  end subroutine a
end module x

subroutine foo(a)
  real :: a
  print *, a
end subroutine foo

program main
  use x
  call a  ! This should print "1.00000000" or a close representation.

  ! Direct Test
  call foo(1.0)  ! Directly testing foo with the expected value to print.
end program main