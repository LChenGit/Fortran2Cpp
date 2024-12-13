module Members
  implicit none

  type :: HasMembers
    integer :: kind_member
    integer :: len_member
    integer :: member
  contains
    procedure :: MyMethod
  end type HasMembers

contains

  subroutine MySubroutine(arg)
    integer :: arg
    print *, 'MySubroutine called with arg =', arg
  end subroutine MySubroutine
  
  subroutine MyMethod(this)
    class(HasMembers), intent(in) :: this
    print *, 'Member value:', this%member
  end subroutine MyMethod

end module Members

program test
  use Members
  implicit none
  
  type(HasMembers) :: obj
  
  obj%kind_member = 1
  obj%len_member = 10
  obj%member = 5
  
  call obj%MyMethod()
  
  call MySubroutine(10)
  
end program test