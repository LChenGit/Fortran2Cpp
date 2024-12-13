program test_kind
  implicit none
  integer, parameter :: dp = selected_real_kind(15, 307)
  real(kind=dp) :: i
  print *, kind(i)
end program test_kind