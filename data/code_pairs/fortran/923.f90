module m
  use, intrinsic :: iso_c_binding
  implicit none

  type, bind(c) :: bindc_t
    integer(c_int) :: x
  end type bindc_t

  type :: sequence_t
    sequence
    integer :: x
  end type sequence_t

  type, abstract :: abst_t
    integer :: x = 0
  end type abst_t

  type, extends(abst_t) :: concrete_t
    integer :: y = 1
  end type concrete_t

  type :: myt
    class(abst_t), allocatable :: comp
  end type myt

  type, abstract, extends(concrete_t) :: again_abst_t
    integer :: z = 2
  end type again_abst_t

contains

  subroutine sub(arg)
    class(again_abst_t), intent(inout) :: arg
    ! The implementation of this subroutine would depend on the specific use case.
  end subroutine sub

end module m

program test
  use m
  implicit none

  ! Example usage of the module
  type(concrete_t) :: concObj
  print *, concObj%x, concObj%y

end program test