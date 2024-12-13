program loop
  implicit none
  integer, parameter :: n=8
  integer :: a(n)
  call loop_program(a)
  write(*,*) "PASS"
end program loop

subroutine loop_program(a)
  integer, dimension(:), intent(out) :: a
  integer :: i

  do i = 1, size(a)
    a(i) = i
  end do
end subroutine loop_program