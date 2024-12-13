module test
contains
  subroutine oacc1
    implicit none
    integer :: i
    integer, parameter :: a = 1
    !$acc declare device_resident(a)
    !$acc parallel loop private(i)
    do i = 1, 5
      ! This loop is symbolic and doesn't perform any operations
    end do
    !$acc end parallel loop
  end subroutine oacc1
end module test

program main
  use test
  call oacc1()
  print *, "Fortran Stdout: Test Passed."
end program main