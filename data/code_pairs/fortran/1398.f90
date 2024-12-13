! main.f90
program main
  implicit none
  integer, parameter :: N = 7
  real :: a(N,N), b(N,N)
  real :: threshold = 0.5
  integer :: i, j

  call random_seed()
  call random_number(a)

  where (a > threshold) b = a
  where (a <= threshold) b = 0.0

  print *, "Matrix a:"
  do i = 1, N
     print '(7F8.2)', (a(i,j), j=1,N)
  end do

  print *, "Matrix b after applying threshold:"
  do i = 1, N
     print '(7F8.2)', (b(i,j), j=1,N)
  end do

end program main