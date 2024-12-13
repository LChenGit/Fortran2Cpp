program main
  implicit none
  integer, parameter :: n = 10
  complex, dimension(n,n) :: a, b, c
  real, dimension(n,n) :: r
  integer :: i, j

  ! Generate random numbers for the real and imaginary parts of c
  call random_number(r)
  do i = 1, n
    do j = 1, n
      c(i,j) = cmplx(r(i,j), 0.0)
    end do
  end do
  
  call random_number(r)
  do i = 1, n
    do j = 1, n
      c(i,j) = cmplx(real(c(i,j)), r(i,j))
    end do
  end do

  a = c
  b = c

  ! Subtract 0.5 from real and imaginary parts of a and b
  do i = 1, n
    do j = 1, n
      a(i,j) = cmplx(real(a(i,j)) - 0.5, aimag(a(i,j)) - 0.5)
      b(i,j) = cmplx(real(b(i,j)) - 0.5, aimag(b(i,j)) - 0.5)
    end do
  end do

  ! Ensure matrices a and b are equal
  if (any(a /= b)) stop 1

  ! Assign real parts of a to imaginary parts of b and a
  do i = 1, n
    do j = 1, n
      b(i,j) = cmplx(real(b(i,j)), real(a(i,j)))
      a(i,j) = cmplx(real(a(i,j)), real(a(i,j)))
    end do
  end do

  ! Ensure matrices a and b are equal
  if (any(a /= b)) stop 2

  ! Reset matrices a and b to c
  a = c
  b = c

  ! Shift real parts down by one row
  do i = 2, n
    do j = 1, n
      b(i,j) = cmplx(real(a(i-1,j)), aimag(b(i,j)))
      a(i,j) = cmplx(real(a(i-1,j)), aimag(a(i,j)))
    end do
  end do

  ! Ensure matrices a and b are equal
  if (any(a /= b)) stop 3

  ! Reset matrices a and b to c
  a = c
  b = c

  ! Shift imaginary parts up by one row
  do i = 1, n-1
    do j = 1, n
      b(i,j) = cmplx(real(b(i,j)), aimag(a(i+1,j)))
      a(i,j) = cmplx(real(a(i,j)), aimag(a(i+1,j)))
    end do
  end do

  ! Ensure matrices a and b are equal
  if (any(a /= b)) stop 4

  print *, "All tests passed!"
  
end program main