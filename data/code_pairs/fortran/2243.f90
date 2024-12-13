module mod_subpr
  implicit none

  type :: foo
    integer :: i = 2
  end type

  type, extends(foo) :: foo_1
    real :: r(2)
  end type

contains

  subroutine subpr (x)
    class(foo), intent(inout) :: x
    x%i = 3
  end subroutine

  elemental subroutine subpr_elem (x)
    class(foo), intent(inout) :: x
    x%i = 3
  end subroutine

  subroutine subpr_array (x)
    class(foo), intent(inout) :: x(:)
    x(:)%i = 3
  end subroutine

  subroutine subpr2 (x)
    class(foo), intent(in) :: x
    if (x%i /= 55) call abort ()
  end subroutine

  subroutine subpr2_array (x)
    class(foo), intent(in) :: x(:)
    if (any(x(:)%i /= 55)) call abort ()
  end subroutine

  function f () result(res)
    class(foo), allocatable :: res
    allocate (foo :: res)
    res%i = 55
  end function f

  function g () result(res)
    class(foo), allocatable :: res(:)
    allocate (foo :: res(3))
    res(:)%i = 55
  end function g
end module