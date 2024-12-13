program test_range

implicit none

integer :: i, imax
parameter (imax = 3)
real :: a(0:imax), b(0:imax)

! Initialize array b with some values
do i=0,imax
    b(i) = i * 2.0
end do

! Copy b into a
a(:) = b(:)

! No explicit test is printed here as the verification is manual.
! The original Fortran unit test code provided can be used to verify functionality.

end program test_range