program test
  implicit none
  integer :: i
  integer, dimension(10) :: d

  d = 0 ! Initialize all elements to 0
  do concurrent (i=1:5)
     d(i) = i ! Set the first five elements to their 1-based index
  end do

  ! Print the array elements
  do i=1,10
     print *, d(i)
  end do
end program test