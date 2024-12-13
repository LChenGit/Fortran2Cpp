module types_and_subs
  implicit none

  integer :: sum = 0

  type :: t
    integer :: i
    procedure(), pointer, nopass :: ppc => null()
    procedure(), pointer, nopass :: proc => null()
  end type t

  type, extends(t) :: t2
    procedure(), pointer, nopass :: proc2 => null()
  end type t2

contains

  subroutine sub(y)
    integer, intent(in) :: y
    sum = sum + y
  end subroutine sub

  subroutine sub2(arg)
    class(t), intent(inout) :: arg
    arg%i = arg%i + sum
  end subroutine sub2

end module types_and_subs

program test_program
  use types_and_subs
  implicit none

  type(t) :: x
  type(t2) :: x2

  call test()

contains

  subroutine test()
    type(t) :: test_x
    type(t2) :: test_x2

    sum = 0

    test_x%i = 10
    test_x%ppc => sub
    call test_x%ppc(5)
    if (sum /= 5) then
        write(*,*) 'Test failed: sum after sub(5)'
        stop
    end if

    test_x2%proc2 => sub
    call test_x2%proc2(5)
    if (sum /= 10) then
        write(*,*) 'Test failed: sum after test_x2%proc2(5)'
        stop
    end if

    test_x%proc => sub2
    call test_x%proc(test_x)
    if (test_x%i /= 20) then
        write(*,*) 'Test failed: i after sub2()'
        stop
    end if

    write(*,*) 'All Fortran tests passed.'
  end subroutine test

end program test_program