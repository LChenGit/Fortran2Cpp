! file: test_array.f90
program test_array
  implicit none
  integer, allocatable :: arr(:)
  integer :: i

  ! Allocate and set values to the array
  allocate(arr(6))
  arr = [(i, i = 1, 6)]

  ! Check values
  do i = 1, size(arr)
      if (arr(i) /= i) then
          print *, 'Mismatch in arr at position', i
          stop 1
      endif
  enddo

  print *, 'Fortran test passed.'
end program test_array