module tomography_par
  implicit none
  integer, parameter :: CUSTOM_REAL = selected_real_kind(15, 307)
  integer :: NSPEC, NGLOB
  real(kind=CUSTOM_REAL), dimension(:), allocatable :: x, y, z
contains
  subroutine initialize(ns, ng)
    integer, intent(in) :: ns, ng
    NSPEC = ns
    NGLOB = ng
    allocate(x(NGLOB), y(NGLOB), z(NGLOB))
    x = 1.0_CUSTOM_REAL
    y = 2.0_CUSTOM_REAL
    z = 3.0_CUSTOM_REAL
  end subroutine initialize
end module tomography_par