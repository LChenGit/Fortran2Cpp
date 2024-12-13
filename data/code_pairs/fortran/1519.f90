program bug
  implicit none
  integer :: i
  real, dimension(2) :: a, b
  real :: x
  a = [-3.5, 4.5] ! Assuming initialization for the sake of completeness in testing
  do i = 1, 2
    x = abs(a(i))
    b(i) = x
  end do
  ! Including a simple print statement for demonstration purposes
  print *, "Array b:", b
end program bug