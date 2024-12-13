module my_module
  implicit none
  type :: t
  end type t

  type, extends(t) :: t2
  end type t2
contains
  function same_type_as(a, b) result(res)
    class(t), intent(in) :: a, b
    logical :: res
    res = .false.
    select type(a => a)
    type is (t)
      select type(b => b)
      type is (t)
        res = .true.
      class default
      end select
    class default
    end select
  end function same_type_as
end module my_module

program test_my_module
  use my_module
  implicit none
  class(t), allocatable :: a, b, c
  class(t), allocatable :: a2(:), b2(:), c2(:)
  logical :: testPassed

  allocate (t2 :: a)
  allocate (t2 :: a2(5))
  call move_alloc (from=a, to=b)
  call move_alloc (from=a2, to=b2)

  testPassed = .true.
  testPassed = testPassed .and. allocated(b)
  testPassed = testPassed .and. allocated(b2)
  testPassed = testPassed .and. size(b2) == 5

  if (.not. same_type_as(a, c) .or. same_type_as(a, b)) testPassed = .false.
  if (.not. same_type_as(a2(1), c2(1)) .or. same_type_as(a2(1), b2(1))) testPassed = .false.

  if (testPassed) then
    print *, "All tests passed successfully."
  else
    print *, "Some tests failed."
  end if
end program test_my_module