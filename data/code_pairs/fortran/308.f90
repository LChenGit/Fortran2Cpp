module base_mod
  implicit none

  type, abstract :: base_type
  contains
    procedure(base_clone_iface), deferred, pass :: clone
  end type base_type

  abstract interface
    subroutine base_clone_iface(self, clone)
      import :: base_type
      class(base_type), intent(in) :: self
      class(base_type), allocatable, intent(out) :: clone
    end subroutine base_clone_iface
  end interface

end module base_mod