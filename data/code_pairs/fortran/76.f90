module bar
  implicit none
  public :: bar_type

  type, abstract :: bar_type
  contains
    procedure(bar_test_interface), deferred, pass :: test_method
  end type bar_type

  abstract interface
    subroutine bar_test_interface(self)
      import :: bar_type
      class(bar_type), intent(in) :: self
    end subroutine bar_test_interface
  end interface

end module bar