program bug
  implicit none

  type :: block
    real, allocatable :: fields(:)
  end type

  type :: list
    class(block), allocatable :: B
  end type

  type :: domain
    type(list), dimension(2) :: L
  end type

  type(domain) :: d
  type(block) :: b1

  allocate(b1%fields(1), source=5.)

  allocate(d%L(2)%B, source=b1)

  if (d%L(2)%B%fields(1) /= 5.) STOP 1

  print *, "Test Passed"

end program bug