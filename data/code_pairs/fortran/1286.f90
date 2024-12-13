! main.f90 - Main program
program main
  implicit none
  integer, parameter :: n = 1024
  integer :: a(n), b(n), c(n)
  integer :: i

  ! Initialize arrays a and b
  call initializeArrays(a, b, n)

  ! Compute array c as the sum of a and b
  call computeC(a, b, c, n)

  ! Verification step
  do i = 1, n
     if (c(i) /= a(i) + b(i)) then
        print *, "Mismatch at index ", i
        stop
     endif
  end do
  print *, "All tests passed successfully."
end program main

subroutine initializeArrays(a, b, n)
  integer, intent(in) :: n
  integer, intent(out) :: a(n), b(n)
  integer :: i
  do i = 1, n
     a(i) = (i-1) * 2
     b(i) = (i-1) * 4
  end do
end subroutine initializeArrays

subroutine computeC(a, b, c, n)
  integer, intent(in) :: n
  integer, intent(in) :: a(n), b(n)
  integer, intent(out) :: c(n)
  integer :: i
  do i = 1, n
     c(i) = a(i) + b(i)
  end do
end subroutine computeC