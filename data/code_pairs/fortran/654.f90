module nrtype
  implicit none
  ! Integer kinds
  integer, parameter :: ikind = selected_int_kind(9)
  integer, parameter :: lkind = selected_int_kind(15)
  ! Floating-point kinds
  integer, parameter :: rkind = selected_real_kind(p=6)
  integer, parameter :: dkind = selected_real_kind(p=15)
  ! Constants
  real(kind=rkind), parameter :: pi = 3.1415927_rkind
  real(kind=dkind), parameter :: dpi = 3.14159265358979323846_dkind
end module nrtype