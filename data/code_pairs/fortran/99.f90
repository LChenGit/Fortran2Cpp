module templateModule
  implicit none
  
  private
  public :: Sub1, Fun1

contains

  subroutine Sub1(par1, par2, par3)
    integer, intent(in) :: par1
    real, intent(inout) :: par2
    integer, intent(out) :: par3
    ! Example implementation
    par2 = par2 + 1.0
    par3 = 2
  end subroutine Sub1

  real function Fun1()
    Fun1 = 10.0
  end function Fun1

end module templateModule