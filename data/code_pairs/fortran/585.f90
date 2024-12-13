module angleModelClass
  use, intrinsic :: iso_c_binding, only: c_double
  implicit none

  ! Define the kind for real numbers
  integer, parameter :: rb = kind(1.0d0)

  ! Parameter for zero value
  real(rb), parameter :: zero = 0.0_rb

  type, abstract :: cModel
    character(len=20) :: name
  end type cModel

  type, abstract, extends(cModel) :: cAngleModel
    contains
      procedure(cAngleModel_compute), deferred, pass :: compute
  end type cAngleModel

  abstract interface
    subroutine cAngleModel_compute(self, Ea, Fa, theta)
      import :: cAngleModel, rb
      class(cAngleModel), intent(in) :: self
      real(rb), intent(out) :: Ea, Fa
      real(rb), intent(in) :: theta
    end subroutine cAngleModel_compute
  end interface

  type, extends(cAngleModel) :: angle_none
    contains
      procedure, pass :: setup => angle_none_setup
      procedure, pass :: compute => angle_none_compute
  end type angle_none

contains

  subroutine angle_none_setup(self)
    class(angle_none), intent(inout) :: self
    self%name = "none"
  end subroutine angle_none_setup

  subroutine angle_none_compute(self, Ea, Fa, theta)
    class(angle_none), intent(in) :: self
    real(rb), intent(out) :: Ea, Fa
    real(rb), intent(in) :: theta
    Ea = zero
    Fa = zero
  end subroutine angle_none_compute

end module angleModelClass