module m
  implicit none
  type t
    integer :: ii = 55
  end type t
contains
  function f1() result(res)
    type(t), pointer :: res
    allocate (res)
    res%ii = 123
  end function f1

  function f2() result(res)
    type(t), pointer :: res(:)
    allocate (res(3))
    res(:)%ii = [-11,-22,-33]
  end function f2
end module m

program test
  use m
  implicit none
  type(t), pointer :: p1, p2(:), p3(:,:)
  p1 => f1()
  if (p1%ii /= 123) stop "Test f1 failed"
  p2 => f2()
  if (any (p2%ii /= [-11,-22,-33])) stop "Test f2 failed"
  allocate (p3(2:2,1:3))
  p3(2:2,1:3) => f2()
  if (any (p3(2,:)%ii /= [-11,-22,-33])) stop "Test f2 in 2D failed"
  print *, "All tests passed."
end program test