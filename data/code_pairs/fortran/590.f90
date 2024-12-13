module mod_operations
  implicit none
  type :: t
    integer :: x
  end type t
contains
  subroutine increment(x)
    type(t), intent(inout) :: x
    integer :: i
    do i = 1, 1000
      x%x = x%x + 1
    end do
  end subroutine increment
end module mod_operations

program main
  use mod_operations
  type(t) :: x
  x%x = 0
  call increment(x)
  if (x%x == 1000) then
    print *, 'Test passed.'
  else
    print *, 'Test failed.'
  endif
end program main