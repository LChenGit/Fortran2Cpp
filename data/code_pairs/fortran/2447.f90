module mytype_mod
  implicit none
  type :: mytype
    integer, allocatable :: indices(:)
  end type mytype
end module mytype_mod

program main
  use mytype_mod
  implicit none

  type(mytype) :: object
  integer :: i, me

  ! For a standalone example, simulate 'this_image()' with a fixed value
  me = 1

  ! Allocate and set indices array
  allocate(object%indices(me))
  object%indices = [(i, i = 1, me)]

  ! Perform checks
  if (size(object%indices) /= 1) then
    call abort()
  endif
  if (object%indices(1) /= 1) then
    call abort()
  endif

  print *, "Fortran Unit Test Passed Successfully."
end program main