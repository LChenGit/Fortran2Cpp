program prog
  implicit none
  integer :: nums(2)
  integer :: i

  do i = 1, 2
    nums(i) = i + 47
  end do
  write(*,*) nums
end program prog