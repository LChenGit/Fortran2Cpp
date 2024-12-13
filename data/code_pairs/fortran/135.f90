module MFAnimal
  implicit none
  private
  public :: TFAnimal

  type, abstract :: TFAnimal
  contains
    procedure(say_interface), deferred :: say
  end type TFAnimal

  abstract interface
    function say_interface(self)
      import :: TFAnimal
      class(TFAnimal), intent(in) :: self
      character(len=80) :: say_interface
    end function say_interface
  end interface
end module MFAnimal