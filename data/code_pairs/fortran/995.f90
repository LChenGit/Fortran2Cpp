module olbfgs_module
  use iso_c_binding
  implicit none

  private

  public :: dolbfgs
  public :: solbfgs
  
contains

  ! Double precision version
  function dolbfgs(a, b) result(res)
    real(c_double), intent(in) :: a, b
    real(c_double) :: res
    res = a + b
  end function dolbfgs

  ! Single precision version
  function solbfgs(a, b) result(res)
    real(c_float), intent(in) :: a, b
    real(c_float) :: res
    res = a + b
  end function solbfgs

end module olbfgs_module