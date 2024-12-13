! main.f90
module mod_types
  implicit none

  type :: t
    integer :: i
  end type t

  type, extends(t) :: t2
    integer :: j
  end type t2
end module mod_types

program main
  use mod_types
  implicit none

  class(t), allocatable :: a

  allocate(a, source=t2(1,2))
  print *, "Fortran Stdout: Test i=1 passed"
  if (a%i /= 1) stop 1

  select type (a)
    type is (t2)
      print *, "Fortran Stdout: Test j=2 passed"
      if (a%j /= 2) stop 2
  end select
end program main