module m
  implicit none

  type :: t
  end type t

  type :: t2
    integer :: value = 0
  contains
    final :: fini
  end type t2

contains
  subroutine fini(var)
    type(t2), intent(inout) :: var
    print *, "t2::fini() called, value:", var%value
  end subroutine fini

  subroutine foo(x, y, aa, bb)
    type(t), intent(out) :: x(:), y
    type(t2), intent(out) :: aa(:), bb
    bb%value = 42
  end subroutine foo

end module m

program testProgram
  use m
  implicit none
  type(t) :: y
  type(t2) :: bb
  type(t), allocatable :: x(:)
  type(t2), allocatable :: aa(:)

  allocate(x(1))
  allocate(aa(1))

  call foo(x, y, aa, bb)

  print *, "Test complete. Implement specific checks as needed."
end program testProgram