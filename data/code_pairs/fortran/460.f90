program prog
  implicit none
  integer, dimension(2,2) :: nums
  character(len=2), dimension(2,2) :: s2s
  integer :: i, j

  ! Initialize arrays
  nums = reshape([12, 34, 56, 78], shape(nums))
  s2s = reshape([character(len=2) :: 'Xy', 'Za', 'cD', 'eF'], shape(s2s))

  ! Output arrays
  do i = 1, 2
    do j = 1, 2
      write(*, '(i2, x, a)') nums(i,j), s2s(i,j)
    end do
  end do
end program prog