! File: great_ne.f90
subroutine great_ne(a, b)
  implicit none
  integer, intent(in) :: a, b
  ! This subroutine does nothing.
end subroutine great_ne

program test_great_ne
  implicit none
  
  call great_ne(1, 2)
  
  print *, "Test passed."
end program test_great_ne