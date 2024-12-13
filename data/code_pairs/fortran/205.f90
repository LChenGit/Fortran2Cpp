module myTypes
  type :: t
    integer :: dummy
  end type t
end module myTypes

subroutine s()
  use myTypes
  type(t) :: myVar
  myVar%dummy = 10
  print *, 'Test passed. Value of dummy: ', myVar%dummy
end subroutine s