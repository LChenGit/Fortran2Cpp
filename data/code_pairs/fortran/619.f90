! asyncwait.f90
program asyncwait
  implicit none
  integer, parameter :: N = 64
  real, allocatable :: a(:), b(:)
  integer :: i

  allocate (a(N))
  allocate (b(N))

  a(:) = 3.0
  b(:) = 0.0

  ! Assuming an operation to test here; 
  ! since none exists, we're just initializing arrays.
  !$acc parallel loop
  do i = 1, N
     b(i) = a(i) * 2.0
  end do

  !$acc wait async(N)

  ! Deallocate to clean up
  deallocate(a)
  deallocate(b)

end program asyncwait