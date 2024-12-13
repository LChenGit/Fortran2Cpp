module test_type
  implicit none

  type :: t1
     integer :: i
   contains
     procedure, pass :: assign
     generic :: assignment(=) => assign
  end type t1

contains

  elemental subroutine assign(this, rhs)
    class(t1), intent(inout) :: this
    type(t1), intent(in) :: rhs
    this%i = rhs%i
  end subroutine assign

  function return_t1(arg) result(res)
    type(t1), dimension(:), intent(in) :: arg
    type(t1), dimension(:), allocatable :: res
    allocate(res(size(arg)), source=arg)
  end function return_t1

  function return_t1_p(arg) result(res)
    type(t1), dimension(:), intent(in), target :: arg
    type(t1), dimension(:), pointer :: res
    res => arg
  end function return_t1_p

end module test_type

program test
  use test_type
  implicit none

  type(t1), dimension(3) :: v1, v2
  integer :: i

  ! Test 1: Assignment and return_t1 function
  v1%i = [1,2,3]
  v2 = return_t1(v1)
  do i = 1, 3
    if (v2(i)%i /= v1(i)%i) then
      print *, "Test 1 Failed"
      stop
    endif
  enddo
  print *, "Test 1 Passed"

  ! Test 2: Assignment and return_t1_p function
  v1%i = [4,5,6]
  v2 = return_t1_p(v1)
  do i = 1, 3
    if (v2(i)%i /= v1(i)%i) then
      print *, "Test 2 Failed"
      stop
    endif
  enddo
  print *, "Test 2 Passed"

end program test