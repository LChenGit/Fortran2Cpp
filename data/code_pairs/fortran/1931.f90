program main
  implicit none

  integer, parameter :: size = 100
  integer :: array(size), i

  call kernels(array, size)
  do i = 1, size
     if (array(i) /= i) then
        print *, "Kernels Test FAILED."
        stop
     endif
  end do
  print *, "Kernels Test PASSED."
end program main

subroutine kernels(array, n)
  integer, dimension(n) :: array
  integer :: n, i

  do i = 1, n
     array(i) = i
  end do
end subroutine kernels