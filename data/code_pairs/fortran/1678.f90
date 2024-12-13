program increment
  implicit none
  integer, dimension(1:10) :: arr
  integer :: i

  ! Initialize the array
  do i = 1, 10
     arr(i) = i
  end do

  ! Use OpenACC to increment each element in parallel
  !$acc data copy(arr)
  !$acc parallel loop
  do i = 1, 10
     arr(i) = arr(i) + 1
  end do
  !$acc end data

  ! Print the results
  do i = 1, 10
     print *, 'arr(', i, ') = ', arr(i)
  end do
end program increment