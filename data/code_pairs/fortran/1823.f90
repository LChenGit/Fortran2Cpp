! main.f90
module types
  implicit none

  type :: concrete_type
     procedure(alloc_integer), pointer, nopass :: alloc
  end type concrete_type

contains

  function alloc_integer() result(res)
     integer, allocatable :: res
     allocate(res, source=13)
  end function alloc_integer

end module types

program test
  use types
  implicit none

  type(concrete_type) :: concrete
  procedure(alloc_integer), pointer :: pp => null()

  ! Direct call
  print *, alloc_integer()

  ! Function pointer call
  pp => alloc_integer
  print *, pp()

  ! Concrete type function pointer call
  concrete % alloc => alloc_integer
  print *, concrete % alloc()

end program test