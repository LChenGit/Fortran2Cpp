module types_module
  use, intrinsic :: iso_fortran_env, only: int32, real32
  implicit none

  type :: t
    integer(int32) :: i
    real(real32) :: r
  end type t

  type, extends(t) :: t2
    integer(int32) :: j
  end type t2

end module types_module

program main
  use types_module
  implicit none

  type(t) :: a
  type(t), dimension(1:3) :: b
  class(t), allocatable :: cp

  ! Allocate cp as t2 type
  allocate(t2 :: cp)

  ! Run tests
  print *, "Running tests..."
  call test_sizes(a, b, cp)

  ! Clean up
  if (allocated(cp)) deallocate(cp)

contains

  subroutine test_sizes(a, b, cp)
    type(t), intent(in) :: a
    type(t), dimension(1:3), intent(in) :: b
    class(t), allocatable, intent(in) :: cp

    if (sizeof(a) /= 8) call abort()
    if (sizeof(b) /= 24) call abort()
    if (sizeof(cp) /= 12) call abort()

    print *, "All tests passed."
  end subroutine test_sizes

end program main