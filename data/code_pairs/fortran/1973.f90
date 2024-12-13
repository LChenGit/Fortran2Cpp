module m
  integer :: a, b
end module m

subroutine f1(c, d)
  use m
  implicit none
  integer, intent(in) :: c(*)
  integer, intent(out) :: d(*)
  integer :: i
  do i = 1, 64
    d(i) = a
    a = a + c(i)
  end do
end subroutine

program test
  use m
  implicit none
  integer :: c(64), d(64)
  integer :: i

  a = 0
  do i = 1, 64
    c(i) = 1
  end do

  call f1(c, d)

  do i = 1, 64
    print *, 'd(', i, ') = ', d(i)
  end do
  print *, 'Final value of a:', a
end program test