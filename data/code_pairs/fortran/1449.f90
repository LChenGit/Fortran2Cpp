module sizes
  implicit none
  private

  integer, parameter, public :: Ndim=3
  integer, dimension(Ndim), parameter, public :: mesh=(/ 100, 100, 100 /)
  integer, parameter, public :: meshx=mesh(1)
  integer, parameter, public :: meshy=mesh(2)
  integer, parameter, public :: meshz=mesh(3)
end module sizes