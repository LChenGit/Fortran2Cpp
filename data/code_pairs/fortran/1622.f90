! Main Program
program main
implicit none
integer, target :: x(0:12)
integer, pointer :: z(:)
integer i

do i = 0,12
  x(i) = i
enddo

z => x

do i = 0,12
  if (x(i) /= i .or. z(i) /= i) then
    call abort
  endif
enddo

end program main

! The Fortran unit test is conceptual and provided separately as a demonstration.