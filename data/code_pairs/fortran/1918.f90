! mymod.f90
module mymod
  implicit none
  type :: mytyp
    character(len=3) :: a = "XYZ"
  end type mytyp
end module mymod